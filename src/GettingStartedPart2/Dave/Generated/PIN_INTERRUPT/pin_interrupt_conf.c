/*********************************************************************************************************************
* DAVE APP Name : PIN_INTERRUPT       APP Version: 4.0.2
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2016, Infineon Technologies AG
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
 * 2016-03-02:
 *     - Initial version for DAVEv4. <BR>
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "pin_interrupt.h"

/**********************************************************************************************************************
 * DATA STRUCTURES
 **********************************************************************************************************************/
/**
* @brief Contents entered via GUI
*/
const PIN_INTERRUPT_t dhPIN_INTERRUPT_0 =
{
  .eru = XMC_ERU1,  /* ERU module 1 Mapped */
  .port = XMC_GPIO_PORT1,  /* PORT 1 Mapped */
  .gpio_config =
   {
     .mode = XMC_GPIO_MODE_INPUT_TRISTATE  /* Pin Characteristics */
   },
  .etl_config = 
  {
    .input_a = (uint32_t)XMC_ERU_ETL_INPUT_A0, /* Event input selection for A(0-3) */
    .input_b = (uint32_t)XMC_ERU_ETL_INPUT_B0, /* Event input selection for B(0-3) */
    .enable_output_trigger = (uint32_t)1,
    .edge_detection = (XMC_ERU_ETL_EDGE_DETECTION_t)PIN_INTERRUPT_EDGE_FALLING, /* Select the edge to convert as event */
    .output_trigger_channel = XMC_ERU_ETL_OUTPUT_TRIGGER_CHANNEL0, /* Select the source for event */
    .source = XMC_ERU_ETL_SOURCE_A
  },
  .IRQn = (IRQn_Type)5,  /* Mapped Interrupt Request Number */
  .irq_priority = 63, /* Priority of the Interrupt */
#if(UC_FAMILY == XMC4)
  .irq_subpriority = 0,  /* Subpriority of the Interrupt */
#endif
  .etl = 1U,  /* ERU ETL channel number */
  .ogu = 0U,  /* ERU OGU channel number */
  .pin = 15U, /* Mapped pin number */ 
  .enable_at_init = true /* Enable Interrupt during initialization */ 
  };
