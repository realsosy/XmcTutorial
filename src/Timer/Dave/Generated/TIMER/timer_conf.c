/*********************************************************************************************************************
* DAVE APP Name : TIMER       APP Version: 4.1.10
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-16:
 *     - Initial version<br>
 *
 * 2015-05-08:
 *     - Added Shadow transfer mask generation<br>
 *
 * 2015-08-31:
 *     - invert_out parameters are removed in CCU8 config structure, to remove the device dependency<br>
 *
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
/* Included to access TIMER app data structure, functions & enumerations */
#include "timer.h"

/***********************************************************************************************************************
* DATA STRUCTURES
***********************************************************************************************************************/

/**
 * @brief Contents entered via GUI
 */

XMC_CCU4_SLICE_COMPARE_CONFIG_t dhTIMER_0_config =
{
  .timer_mode          = XMC_CCU4_SLICE_TIMER_COUNT_MODE_EA,
  .monoshot            = XMC_CCU4_SLICE_TIMER_REPEAT_MODE_REPEAT,
  .shadow_xfer_clear   = false,
  .dither_timer_period = false,
  .dither_duty_cycle   = false,
  .prescaler_mode      = XMC_CCU4_SLICE_PRESCALER_MODE_NORMAL,
  .mcm_enable          = false,
  .prescaler_initval   = 11U,
  .float_limit         = 0U,
  .dither_limit        = 0U,
  .passive_level       = XMC_CCU4_SLICE_OUTPUT_PASSIVE_LEVEL_LOW, 
  .timer_concatenation = false
};

TIMER_t dhTIMER_0 = 
{
  .ccu4_slice_ptr         = (XMC_CCU4_SLICE_t*) CCU43_CC43,
  .ccu4_slice_number      = 3U,
  .time_interval_value_us = 100000000U,
  .timer_max_value_us     = 1789542400U,
  .timer_min_value_us     = 10U,
  .global_ccu4_handler    = (GLOBAL_CCU4_t*)&GLOBAL_CCU4_0, 
  .ccu4_slice_config_ptr  = (XMC_CCU4_SLICE_COMPARE_CONFIG_t*)&dhTIMER_0_config,
  .shadow_mask            = (uint32_t)((uint32_t)XMC_CCU4_SHADOW_TRANSFER_SLICE_3 | 
                                       (uint32_t)XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_3),
  .ccu4_period_match_node = XMC_CCU4_SLICE_SR_ID_1,
  .timer_module           = TIMER_MODULE_CCU4,
  .period_value           = 58592U,
  .start_control          = true,
  .period_match_enable    = true,
  .initialized            = false
};

                      
