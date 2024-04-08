#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <stdarg.h>
#include <sys/uio.h>

#include <f2fs_fs.h>

#define LOG_PARTITION_SPLASH2   "/splash2/"
#define LOG_PARTITION_LOG       "/log/"
#define LOG_PARTITION_DEV        "/dev/"

#define LOG_MAX_SIZE	0x200000	/* 2MB */
char *LOG_PARTITION = NULL;

#define DMD_BUF_MAX	1024
char dmd_insert_buf[DMD_BUF_MAX] = {0};
int dmd_write_size = 0;

char *log_tag[] = {
	"F2fs-tools",
	"F2fs.fsck",
	"F2fs.dump",
	"F2fs.defrag",
	"F2fs.mkfs",
	"",
};

struct log_info log_i = {
	.type		= LOG_TYP_F2FS_TOOLS,
	.slog_fd	= -1,
	.klog_fd	= -1,
	.dsm_fd		= -1,
	.klog_level	= KLOG_DEFAULT_LEVEL,
	.slog_file	= NULL,
	.slog_file_bak	= NULL,
	.log_dir	= NULL
};

#ifdef BG_FSCK
int bg_fsck_mode = 0;

int cp_bg_fsck_result(){
    int fd;
    ssize_t ret;
    fd = open(BG_FSCK_LOG, O_RDONLY);
    if (fd < 0) {
        KLOGE("%s : open %s failed, %s!\n", __func__, BG_FSCK_LOG, strerror(errno));
        return -1;
    }
    char *buff;
    buff = calloc(1, LOG_BUF_MAX);
    if (!buff) {
        KLOGE("%s : calloc  buff failed\n", __func__);
        ret = -1;
        goto clean_fd;
    }
    while ((ret = read(fd, buff, LOG_BUF_MAX-1)) != 0) {
        if (ret < 0) {
            KLOGE("%s : read %s failed, %s!\n", __func__, BG_FSCK_LOG, strerror(errno));
            break;
        }
        MSG(0, "%s", buff);
        memset(buff, 0, LOG_BUF_MAX);
    }
    free(buff);
clean_fd:
    close(fd);
    return ret;
}

void rm_bg_fsck_result(){
    if(unlink(BG_FSCK_LOG))
        KLOGE("%s : unlink %s failed, %s!\n", __func__, BG_FSCK_LOG, strerror(errno));
}

int is_in_bg_fsck(){
    return bg_fsck_mode;
}

void set_bg_fsck_mode(){
    bg_fsck_mode = 1;
}

int need_fg_fsck(){
    return access(BG_FSCK_LOG, F_OK);
}

#endif

#ifdef HAVE_LOG

/*
 * klog_* are copied from system/core/libcutils/klog.c
 * klog write data to /dev/kmsg, to save message in kernel log
 */

void klog_init(void)
{
    if (log_i.klog_fd >= 0) return; /* Already initialized */

    log_i.klog_fd = open("/dev/kmsg", O_WRONLY | O_CLOEXEC);
    if (log_i.klog_fd >= 0) {
        return;
    }

    static const char* name = "/dev/__kmsg__";
    if (mknod(name, S_IFCHR | 0600, (1 << 8) | 11) == 0) {
        log_i.klog_fd = open(name, O_WRONLY | O_CLOEXEC);
        unlink(name);
    }
}

void klog_writev(int level, const struct iovec* iov, int iov_count)
{
    if (level > log_i.klog_level) return;
    if (log_i.klog_fd < 0) klog_init();
    if (log_i.klog_fd < 0) return;
    TEMP_FAILURE_RETRY(writev(log_i.klog_fd, iov, iov_count));
}

void klog_write(int level, const char* fmt, ...)
{
    char *buf;
    va_list ap;

    buf = calloc(1, LOG_BUF_MAX);
    if (!buf) {
        KLOGE("calloc klog buf failed\n");
        return;
    }

    va_start(ap, fmt);
    vsnprintf(buf, LOG_BUF_MAX - 1, fmt, ap);
    va_end(ap);

    struct iovec iov[1];
    iov[0].iov_base = buf;
    iov[0].iov_len = strlen(buf);
    klog_writev(level, iov, 1);
    free(buf);
}

/*
 * slog_* is copied from http://rnd-hisi-kirin-origin.huawei.com:8080/#/c/202061/
 * slog write data to specific files in partition /splash2
 */
static int slog_fix_size(int request_size)
{
	struct stat st;
	int mode;

	if (stat(log_i.slog_file, &st) < 0) {
		if (errno == ENOENT)
			return 0;
		KLOGE("cannot stat %s errno %d\n", log_i.slog_file, errno);
		return -1;
	}

	if (!S_ISREG(st.st_mode)) {
		KLOGE("file %s is not a regular file\n", log_i.slog_file);
		return -1;
	}

	if (LOG_MAX_SIZE - st.st_size > request_size)
		return 0;

	/*
	 * LOG_FILE does not have enough size, we rename it to LOG_FILE_BAK,
	 * then unlink LOG_FILE, so that we can write new log to LOG_FILE
	 * again
	 */
	close(log_i.slog_fd);
	if (rename(log_i.slog_file, log_i.slog_file_bak)) {
		KLOGE("rename fail errno %d\n", errno);
		/* force unlink LOG_FILE */
		unlink(log_i.slog_file);
	}

	KLOGI("%s is full, rename it to %s\n", log_i.slog_file,
		log_i.slog_file_bak);
	if (access(log_i.slog_file, 0) != 0) {
		if (errno != ENOENT) {
			KLOGE("cannot unlink %s, errno %d\n", log_i.slog_file,
				errno);
			return -1;
		}
	}

	mode = O_RDWR | O_CLOEXEC | O_CREAT;
	log_i.slog_fd = open(log_i.slog_file, mode, 0664);
	if (log_i.slog_fd < 0) {
		KLOGE("re-open slog file fail errno %d\n", errno);
		return log_i.slog_fd;
	}

	return 0;
}

static int init_log_info(int log_type)
{
	char *name = "";
	unsigned int size;
	struct stat st;
	int log_stat, splash2_stat;
	int ret;

	/* the file and back file are:
	 *   log_i.log_dir/buf
	 *   log_i.log_dir/buf".1"
	 */
	switch (log_type) {
	case LOG_TYP_FSCK:
		name = "fsck.log";
		break;
	case LOG_TYP_DUMP:
		name = "dump.log";
		break;
	case LOG_TYP_DEFRAG:
		name = "defrag.log";
		break;
	case LOG_TYP_MKFS:
		name = "mkfs.log";
		break;
	default:
		KLOGE("unknown log type %d\n", log_type);
		return -1;
	}

    if(is_in_bg_fsck()){
        int dev_stat;
        dev_stat = stat(LOG_PARTITION_DEV, &st);
        if(dev_stat == 0){
            LOG_PARTITION = LOG_PARTITION_DEV;
        } else {
            KLOGE("failed to stat %s errno %d\n", LOG_PARTITION_DEV, errno);
            return -1;
        }
    } else {
	log_stat = stat(LOG_PARTITION_LOG, &st);
	if (log_stat == 0) {
		LOG_PARTITION = LOG_PARTITION_LOG;
	} else {
		KLOGE("failed to stat %s errno %d, may log into /splash2\n",
				LOG_PARTITION_LOG, errno);
		splash2_stat = stat(LOG_PARTITION_SPLASH2, &st);
		if (splash2_stat == 0) {
			LOG_PARTITION = LOG_PARTITION_SPLASH2;
		} else {
			KLOGE("failed to stat %s errno %d\n", LOG_PARTITION_SPLASH2, errno);
			return -1;
		}
	}
    }
	KLOGI("fsck logging to %s\n", LOG_PARTITION);
	if (!S_ISDIR(st.st_mode)) {
		KLOGE("%s is not a directory\n", LOG_PARTITION);
		return -1;
	}

	size = strlen(LOG_PARTITION) + strlen("f2fs-tools/") + 1;
	log_i.log_dir = malloc(size);
	ASSERT(log_i.log_dir);
	snprintf(log_i.log_dir, size, "%s%s", LOG_PARTITION, "f2fs-tools/");

	ret = mkdir(log_i.log_dir, 0775);
	if (ret < 0 && errno != EEXIST) {
		KLOGE("mkdir fail errno %d\n", errno);
		return ret;
	}

	log_i.type = log_type;
	size = strlen(log_i.log_dir) + strlen(name) + 1;
	log_i.slog_file = malloc(size);
	ASSERT(log_i.slog_file);
	snprintf(log_i.slog_file, size, "%s%s", log_i.log_dir, name);
	size += 2;
	log_i.slog_file_bak = malloc(size);
	ASSERT(log_i.slog_file_bak);
	snprintf(log_i.slog_file_bak, size, "%s%s%s", log_i.log_dir, name, ".1");
	return 0;
}

int slog_init(int log_type)
{
	time_t t;
	struct tm *tm;
	char *buf;
	int mode;
	int ret;

	if (init_log_info(log_type))
		return -1;

	mode = O_RDWR | O_CLOEXEC | O_CREAT | O_APPEND;
	log_i.slog_fd = open(log_i.slog_file, mode, 0664);
	if (log_i.slog_fd < 0) {
		KLOGE("open slog file fail errno %d\n", errno);
		return log_i.slog_fd;
	}

	KLOGI("Starting logging to %s\n", log_i.slog_file);

    if(is_in_bg_fsck()){
        const char* flag = "BG FSCK \n";
        ret = write(log_i.slog_fd, flag, strlen(flag));
        if (ret < 0)
            KLOGE("write BG FSCK flag fail errno %d\n", errno);
        return 0;
    }

	/* get current date
	 * the string looks like "=== 2016/03/16 14:01:01 ===", its max
	 * length is 32.
	 */
	buf = calloc(1, 64);
	if (!buf)
		return -1;

	t = time(NULL);
	tm = localtime(&t);
	snprintf(buf, 63, "=== %d/%02d/%02d %02d:%02d:%02d ===\n",
		1900 + tm->tm_year, 1 + tm->tm_mon, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec);
	ret = write(log_i.slog_fd, buf, strlen(buf));
	if (ret < 0)
		KLOGE("write time stamp %s fail errno %d\n", buf, errno);
	free(buf);
	return ret;
}

void slog_exit(void)
{
	if (log_i.slog_fd < 0)
		return;

    if (fsync(log_i.slog_fd) < 0)
        KLOGE("fsync slog fail\n");

	if (log_i.log_dir)
		free(log_i.log_dir);
	if (log_i.slog_file)
		free(log_i.slog_file);
	if (log_i.slog_file_bak)
		free(log_i.slog_file_bak);
	if (log_i.slog_fd)
		close(log_i.slog_fd);

	KLOGI("Logging done\n");
}

int slog_write(const char *fmt, ...)
{
	va_list args;
	char *buf;
	int size = 64;
	int ret;

	if (log_i.slog_fd < 0)
		return 0;

	buf = malloc(size);
	if (!buf)
		return -1;

	while (1) {
		memset(buf, 0, size);
		va_start(args, fmt);
		ret = vsnprintf(buf, size - 1, fmt, args);
		va_end(args);

		if (ret < 0) {
			free(buf);
			return -1;
		}

		if (ret < size - 1) {
			/* we get the whole fmt... */
			size = ret;
			break;
		}

		size += size;
		free(buf);
		buf = malloc(size);
		if (!buf)
			return -1;
	}

	ret = slog_fix_size(size);
	if (ret < 0) {
		KLOGE("slog_fix_size fail\n");
		free(buf);
		return ret;
	}

	ret = write(log_i.slog_fd, buf, size);
	if (ret < 0)
		KLOGE("write to slog file fail errno %d\n", errno);

	free(buf);
	return ret;
}

static int dmd_report_init(void)
{
	struct stat st;
	int ret;

	/* check if /dev/dsm exists */
	ret = stat("/dev/dsm", &st);
	if (ret < 0) {
		if (errno == ENOENT) {
			KLOGE("/dev/dsm no exist\n");
			return ret;
		}
		KLOGE("failed to stat /dev/dsm errno %d\n", errno);
		return ret;
	}

	if (!S_ISCHR(st.st_mode)) {
		KLOGE("/dev/dsm is not a character device file.\n");
		return ret;
	}

	log_i.dsm_fd = open("/dev/dsm", O_WRONLY);
	if (log_i.dsm_fd < 0) {
		KLOGE("open /dev/dsm file fail errno %d\n", errno);
		return log_i.dsm_fd;
	}

	KLOGI("Starting dmd report\n");
	return ret;
}

/*
 * @client: dmd client name
 * @dmd_err: dmd error number of client
 */
static int dmd_report_write(const char *client, int dmd_err)
{
	char *dmd_buf, *dmd_buf_ptr;
	int size = 0, left;
	int ret;

	if (log_i.dsm_fd < 0)
		return 0;

    dmd_buf = calloc(1, 1024);
    if (!dmd_buf) {
        KLOGE("calloc dmd buf failed\n");
        return -ENOMEM;
    }

	left = 1024-1;
	size = snprintf(dmd_buf, left, "%s,%d,", client, dmd_err);
	dmd_buf_ptr = dmd_buf + size;
	left -= size;
	if (left > dmd_write_size)
		left = dmd_write_size;
	strncpy(dmd_buf_ptr, dmd_insert_buf, left);
	left += size;

	ret = write(log_i.dsm_fd, dmd_buf, left);
	if (ret < 0)
		KLOGE("dmd report failed to write %s errno %d\n",
			dmd_buf, errno);

    free(dmd_buf);
	return ret;
}

static void dmd_report_exit(void)
{
	if (log_i.dsm_fd < 0)
		return;

	if (log_i.dsm_fd)
		close(log_i.dsm_fd);

	KLOGI("dmd report done\n");
}

/*
 * @client: dmd client name
 * @dmd_err: dmd error number for the client
 */
int dmd_report(const char *client, int dmd_err)
{
	int ret;

    if(is_in_bg_fsck())
        return 0;

    if (*dmd_insert_buf == 0)
        return 0;

	ret = dmd_report_init();
	if (ret < 0) {
		KLOGE("Init dmd report failed\n");
		return ret;
	}

	ret = dmd_report_write(client, dmd_err);
	if (ret < 0)
		KLOGE("Write message to DMD failed\n");

	dmd_report_exit();
	return ret;
}

void dmd_insert_error(int type, int err, const char *func, int line)
{
	int dmd_insert_size = 0;
	char *dmd_insert_buf_ptr = dmd_insert_buf;
	int remain_len = DMD_BUF_MAX - dmd_write_size;

	if (type < LOG_TYP_FSCK || type >= LOG_TYP_MAX) {
		KLOGE("Unknown log type %d\n", type);
		return;
	}

	if (remain_len > 0) {
		dmd_insert_buf_ptr = dmd_insert_buf + dmd_write_size;
		dmd_insert_size = snprintf(dmd_insert_buf_ptr, remain_len, "%s:%d %x;",
				func, line, err);
		if (dmd_insert_size > remain_len)
			dmd_insert_size = remain_len;
		dmd_write_size += dmd_insert_size;
	}
}
#endif
