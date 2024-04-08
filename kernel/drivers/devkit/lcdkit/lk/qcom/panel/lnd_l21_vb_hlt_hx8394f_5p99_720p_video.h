/* Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of The Linux Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*-------------------------------------------------------------------------
 * This file is autogenerated file using gcdb parser. Please do not edit it.
 * Update input XML file to add a new entry or update variable in this file
 * VERSION = 1.1
 *-----------------------------------------------------------------------*/

#ifndef _PANEL_LND_L21_VB_HLT_HX8394F_5P99_720P_VIDEO_H_

#define _PANEL_LND_L21_VB_HLT_HX8394F_5P99_720P_VIDEO_H_
/*-----------------------------------------------------------------------*/
/* HEADER files                                                          */
/*-----------------------------------------------------------------------*/
#include "panel.h"

#include "lcdkit_bias_ic_common.h"

#include "lcd_bl.h"

/*-----------------------------------------------------------------------*/
/* Panel configuration                                                   */
/*-----------------------------------------------------------------------*/
static struct panel_config lnd_l21_vb_hlt_hx8394f_5p99_720p_video_panel_data = {
        "lcdkit_lnd_l21_vb_hlt_hx8394f_5p99_720p_video", "dsi:0:", 
        "hlt-hx8394f-5p99-720p-video", 10, 0, "DISPLAY_1", 0, 428300000, 
        60, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 
};

/*-----------------------------------------------------------------------*/
/* Panel resolution                                                      */
/*-----------------------------------------------------------------------*/
static struct panel_resolution lnd_l21_vb_hlt_hx8394f_5p99_720p_video_panel_res = {
        720, 1440, 40, 36, 20, 0, 10, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 
        0 
};

/*-----------------------------------------------------------------------*/
/* Panel color information                                               */
/*-----------------------------------------------------------------------*/
static struct color_info lnd_l21_vb_hlt_hx8394f_5p99_720p_video_color = {
        24, 0, 0x00, 0, 0, 0 
};

/*-----------------------------------------------------------------------*/
/* Panel on/off command                                                  */
/*-----------------------------------------------------------------------*/
static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd0[] = {
    0x04, 0x00, 0x39, 0xC0,
    0xB9, 0xFF, 0x83, 0x94,
   };


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd1[] = {
    0x07, 0x00, 0x39, 0xC0,
    0xBA, 0x63, 0x03, 0x68,
    0x6B, 0xB2, 0xC0, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd2[] = {
    0x0B, 0x00, 0x39, 0xC0,
    0xB1, 0x48, 0x07, 0x67,
    0x09, 0x31, 0x54, 0x71,
    0x31, 0x50, 0x34, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd3[] = {
    0x07, 0x00, 0x39, 0xC0,
    0xB2, 0x00, 0x80, 0x78,
    0x06, 0x08, 0x22, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd4[] = {
    0x15, 0x00, 0x39, 0xC0,
    0xB4, 0x71, 0x72, 0x29,
    0x72, 0x29, 0x72, 0x01,
    0x0C, 0x7C, 0x33, 0x00,
    0x3F, 0x71, 0x72, 0x29,
    0x72, 0x29, 0x72, 0x01,
    0x0C, 0xFF, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd5[] = {
    0x3B, 0x00, 0x39, 0xC0,
    0xE0, 0x1a, 0x1A, 0x20,
    0x25, 0x25, 0x28, 0x2B,
    0x28, 0x52, 0x63, 0x72,
    0x70, 0x77, 0x8A, 0x90,
    0x93, 0xA1, 0xA5, 0xA0,
    0xB0, 0xC1, 0x61, 0x5F,
    0x64, 0x69, 0x6C, 0x72,
    0x7A, 0x7C, 0x1a, 0x1A,
    0x20, 0x24, 0x25, 0x28,
    0x2A, 0x28, 0x53, 0x63,
    0x71, 0x6F, 0x77, 0x8A,
    0x8F, 0x94, 0xA0, 0xA4,
    0xA0, 0xAF, 0xC1, 0x60,
    0x5F, 0x63, 0x68, 0x6C,
    0x73, 0x7A, 0x7C, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd6[] = {
    0x22, 0x00, 0x39, 0xC0,
    0xD3, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0F,
    0x0F, 0x32, 0x10, 0x01,
    0x00, 0x01, 0x52, 0x15,
    0xA8, 0x05, 0xA8, 0x32,
    0x10, 0x00, 0x00, 0x00,
    0x67, 0x43, 0x05, 0x05,
    0x37, 0x0E, 0x0E, 0x27,
    0x06, 0x40, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd7[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xBD, 0x02, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd8[] = {
    0x05, 0x00, 0x39, 0xC0,
    0xD3, 0x01, 0x04, 0x00,
    0x01, 0xFF, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd9[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xBD, 0x00, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd10[] = {
    0x2D, 0x00, 0x39, 0xC0,
    0xD5, 0x19, 0x19, 0x18,
    0x18, 0x24, 0x25, 0x06,
    0x07, 0x04, 0x05, 0x02,
    0x03, 0x00, 0x01, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x20,
    0x21, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0xFF, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd11[] = {
    0x2D, 0x00, 0x39, 0xC0,
    0xD6, 0x18, 0x18, 0x19,
    0x19, 0x21, 0x20, 0x01,
    0x00, 0x03, 0x02, 0x05,
    0x04, 0x07, 0x06, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x25,
    0x24, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18,
    0x18, 0xFF, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd12[] = {
    0x03, 0x00, 0x39, 0xC0,
    0xB6, 0x1B, 0x0F, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd13[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xCC, 0x0B, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd14[] = {
    0x03, 0x00, 0x39, 0xC0,
    0xC0, 0x1F, 0x31, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd15[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xD4, 0x02, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd16[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xBD, 0x01, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd17[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xB1, 0x00, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd18[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xBD, 0x00, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd19[] = {
    0x02, 0x00, 0x39, 0xC0,
    0xC6, 0xED, 0xFF, 0xFF};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd20[] = {
    0x11, 0x00, 0x05, 0x80};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd21[] = {
    0x29, 0x00, 0x05, 0x80};




static struct mipi_dsi_cmd lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_command[] = {
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd0, 0x00},
{0xc, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd1, 0x00},
{0x10, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd2, 0x00},
{0xc, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd3, 0x00},
{0x1c, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd4, 0x00},
{0x40, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd5, 0x00},
{0x28, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd6, 0x00},
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd7, 0x00},
{0xc, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd8, 0x00},
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd9, 0x00},
{0x34, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd10, 0x00},
{0x34, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd11, 0x00},
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd12, 0x00},
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd13, 0x00},
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd14, 0x00},
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd15, 0x00},
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd16, 0x00},
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd17, 0x00},
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd18, 0x00},
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd19, 0x00},
{0x4, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd20, 0x96},
{0x4, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_on_cmd21, 0x14}
};
#define LND_L21_VB_HLT_HX8394F_5P99_720P_VIDEO_ON_COMMAND 22


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_off_cmd0[] = {
    0x28, 0x00, 0x05, 0x80};


static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_off_cmd1[] = {
    0x10, 0x00, 0x05, 0x80};




static struct mipi_dsi_cmd lnd_l21_vb_hlt_hx8394f_5p99_720p_video_off_command[] = {
{0x4, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_off_cmd0, 0x14},
{0x4, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_off_cmd1, 0x96}
};
#define LND_L21_VB_HLT_HX8394F_5P99_720P_VIDEO_OFF_COMMAND 2


static struct command_state lnd_l21_vb_hlt_hx8394f_5p99_720p_video_state = {
        0, 1 
};

/*-----------------------------------------------------------------------*/
/* Command mode panel                                                    */
/*-----------------------------------------------------------------------*/
static struct commandpanel_info lnd_l21_vb_hlt_hx8394f_5p99_720p_video_command_panel = {
        0, 1, 1, 0, 0, 0x2c, 0, 0, 0, 1, 0, 0 
};

/*-----------------------------------------------------------------------*/
/* Video mode panel                                                      */
/*-----------------------------------------------------------------------*/
static struct videopanel_info lnd_l21_vb_hlt_hx8394f_5p99_720p_video_video_panel = {
        1, 0, 0, 0, 1, 1, 2, 0, 0x9 
};

/*-----------------------------------------------------------------------*/
/* Lane configuration                                                    */
/*-----------------------------------------------------------------------*/
static struct lane_configuration lnd_l21_vb_hlt_hx8394f_5p99_720p_video_lane_config = {
        4, 0, 1, 1, 1, 1, 0 
};

/*-----------------------------------------------------------------------*/
/* Panel timing                                                          */
/*-----------------------------------------------------------------------*/
static const uint32_t lnd_l21_vb_hlt_hx8394f_5p99_720p_video_timings[]= {
        0x7A, 0x1A, 0x12, 0x00, 0x3E, 0x42, 0x16, 0x1E, 0x14, 0x03, 0x04, 0x00 
};

static struct panel_timing lnd_l21_vb_hlt_hx8394f_5p99_720p_video_timing_info = {
        0, 4, 0x04, 0x26 
};

/*-----------------------------------------------------------------------*/
/* Panel reset sequence                                                  */
/*-----------------------------------------------------------------------*/
static struct panel_reset_sequence lnd_l21_vb_hlt_hx8394f_5p99_720p_video_reset_seq = {
    { 1, 0, 1, }, { 5, 5, 50, }, 2
};

/*-----------------------------------------------------------------------*/
/* Backlight setting                                                     */
/*-----------------------------------------------------------------------*/
static struct backlight lnd_l21_vb_hlt_hx8394f_5p99_720p_video_backlight = {
        1, 24, 4095, 1, 1, 0 
};

/*-----------------------------------------------------------------------*/
/* Labibb setting                                                        */
/*-----------------------------------------------------------------------*/
static struct labibb_desc lnd_l21_vb_hlt_hx8394f_5p99_720p_video_labibb = {
        0, 1, 5500000, 5500000, 5500000, 5500000, 3, 3, 1, 0 
};

/*-----------------------------------------------------------------------*/
/* turn on backlight delay                                               */
/*-----------------------------------------------------------------------*/
int lnd_l21_vb_hlt_hx8394f_5p99_720p_video_mdp_pipe_type  = MDSS_MDP_PIPE_TYPE_RGB;

int lnd_l21_vb_hlt_hx8394f_5p99_720p_video_dsi_pll_type  = DSI_PLL_TYPE_28NM;

int lnd_l21_vb_hlt_hx8394f_5p99_720p_video_mipi_signature  = 0xffff;

static const uint32_t lnd_l21_vb_hlt_hx8394f_5p99_720p_video_regulator_setting[]= {
        0x03, 0x08, 0x07, 0x00, 0x20, 0x07, 0x01 
};

/*-----------------------------------------------------------------------*/
/* platform Config                                                       */
/*-----------------------------------------------------------------------*/
static struct lcdkit_platform_config lnd_l21_vb_hlt_hx8394f_5p99_720p_video_panel_platform_config = {
        0, 0, 0, 0, 0x10002, 0x10000, 0x200, 0x20, 0, 0, 0, 60, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 5500000, 5500000, 0, 0, 0, 0, 0, 0, 
        0, 0, 0 
};

/*-----------------------------------------------------------------------*/
/* misc Information                                                      */
/*-----------------------------------------------------------------------*/
static struct lcdkit_misc_info lnd_l21_vb_hlt_hx8394f_5p99_720p_video_panel_misc_info = {
        0, 0, 0, 0x01, 0x01, 0x01, 0x01, 1, 0, 1 
};

/*-----------------------------------------------------------------------*/
/* delay ctrl                                                            */
/*-----------------------------------------------------------------------*/
static struct lcdkit_delay_ctrl lnd_l21_vb_hlt_hx8394f_5p99_720p_video_panel_delay_ctrl = {
        0, 0, 0, 3, 3, 3, 5, 0, 0, 0, 0, 20, 0, 50 
};

static char lnd_l21_vb_hlt_hx8394f_5p99_720p_video_backlight_cmd0[] = {
    0x02, 0x00, 0x39, 0xC0,
    0x51, 0x00, 0xFF, 0xFF};




static struct mipi_dsi_cmd lnd_l21_vb_hlt_hx8394f_5p99_720p_video_backlight_command[] = {
{0x8, lnd_l21_vb_hlt_hx8394f_5p99_720p_video_backlight_cmd0, 0x00}
};
#define LND_L21_VB_HLT_HX8394F_5P99_720P_VIDEO_BACKLIGHT_COMMAND 1



static struct lcd_bias_voltage_info * lnd_l21_vb_hlt_hx8394f_5p99_720p_video_bias_ic_array[0];
 
#define LND_L21_VB_HLT_HX8394F_5P99_720P_VIDEO_BIAS_IC_ARRAY 0


static struct backlight_ic_info * lnd_l21_vb_hlt_hx8394f_5p99_720p_video_backlight_ic_array[0];
 
#define LND_L21_VB_HLT_HX8394F_5P99_720P_VIDEO_BACKLIGHT_IC_ARRAY 0


#endif /*_PANEL_LND_L21_VB_HLT_HX8394F_5P99_720P_VIDEO_H_*/
