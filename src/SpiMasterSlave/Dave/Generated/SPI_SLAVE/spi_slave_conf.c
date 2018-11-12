
/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015-2016, Infineon Technologies AG
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
 * 2015-08-06:
 *     - Initial version for DAVEv4.
 *
 * @endcond
 *
 */
/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "spi_slave.h"

/***********************************************************************************************************************
 * EXTERN DECLARATIONS
 ***********************************************************************************************************************/

extern void SPI_SLAVE_lProtocolHandler(const SPI_SLAVE_t * const handle);


/**********************************************************************************************************************
 * DATA STRUCTURES
 **********************************************************************************************************************/
SPI_SLAVE_STATUS_t dhSPI_SLAVE_init(void);
void dhSPI_SLAVE_dma_tx_handler(XMC_DMA_CH_EVENT_t event);
void dhSPI_SLAVE_dma_rx_handler(XMC_DMA_CH_EVENT_t event);

/*USIC channel configuration*/
const XMC_SPI_CH_CONFIG_t dhSPI_SLAVE_channel_config =
{
  .bus_mode     = XMC_SPI_CH_BUS_MODE_SLAVE,
  .parity_mode   = XMC_USIC_CH_PARITY_MODE_NONE
};
/*MISO pin configuration*/
const XMC_GPIO_CONFIG_t dhSPI_SLAVE_mosi1_pin_config   = 
{ 
#ifdef P0_5_AF_U1C0_DOUT0
  .mode             = (XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT2 | P0_5_AF_U1C0_DOUT0), 
#else
  .mode             = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT2,
#endif
  .output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH,
  .output_strength  = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE
};

/*MISO pin configuration used for initializing*/
const SPI_SLAVE_PIN_CONFIG_t dhSPI_SLAVE_miso_pin = 
{
  .port = (XMC_GPIO_PORT_t *)PORT0_BASE,
  .config = &dhSPI_SLAVE_mosi1_pin_config,
  .hw_control = XMC_GPIO_HWCTRL_DISABLED,
  .pin = 5U
};

/*MOSI pin configuration*/
const XMC_GPIO_CONFIG_t dhSPI_SLAVE_mosi_pin_config   = 
{ 
  .mode             = XMC_GPIO_MODE_INPUT_TRISTATE, 
  .output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH
};

/*MOSI pin configuration used for initializing*/
const SPI_SLAVE_PIN_CONFIG_t dhSPI_SLAVE_mosi_pin = 
{
  .port = (XMC_GPIO_PORT_t *)PORT0_BASE,
  .config = &dhSPI_SLAVE_mosi_pin_config,
  .hw_control = XMC_GPIO_HWCTRL_DISABLED,
  .pin = 4U
};

/*SCLK pin configuration*/
const XMC_GPIO_CONFIG_t dhSPI_SLAVE_sclk_pin_config   = 
{ 
  .mode             = XMC_GPIO_MODE_INPUT_TRISTATE, 
  .output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH,
  .output_strength  = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE
};

/*SELIN pin configuration*/
const XMC_GPIO_CONFIG_t dhSPI_SLAVE_slavesel_pin_config   = 
{ 
  .mode             = XMC_GPIO_MODE_INPUT_TRISTATE, 
  .output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH,
  .output_strength  = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE
};

const XMC_DMA_CH_CONFIG_t dhSPI_SLAVE_tx_dma_ch_config =
{
  .enable_interrupt = true,
  .dst_transfer_width = (uint32_t)XMC_DMA_CH_TRANSFER_WIDTH_8,
  .src_transfer_width = (uint32_t)XMC_DMA_CH_TRANSFER_WIDTH_8,
  .dst_address_count_mode = (uint32_t)XMC_DMA_CH_ADDRESS_COUNT_MODE_NO_CHANGE,
  .src_address_count_mode = (uint32_t)XMC_DMA_CH_ADDRESS_COUNT_MODE_INCREMENT,
  .dst_burst_length = (uint32_t)XMC_DMA_CH_BURST_LENGTH_1,
  .src_burst_length = (uint32_t)XMC_DMA_CH_BURST_LENGTH_8,
  .transfer_flow = (uint32_t)XMC_DMA_CH_TRANSFER_FLOW_M2P_DMA,
  .transfer_type = (uint32_t)XMC_DMA_CH_TRANSFER_TYPE_SINGLE_BLOCK,
  .dst_handshaking = (uint32_t)XMC_DMA_CH_DST_HANDSHAKING_HARDWARE,
  .dst_peripheral_request = DMA_PERIPHERAL_REQUEST(5U, 11U), /*DMA0_PERIPHERAL_REQUEST_USIC1_SR0_5*/
};

const SPI_SLAVE_DMA_CONFIG_t dhSPI_SLAVE_tx_dma_config =
{
  .dma_ch_config = &dhSPI_SLAVE_tx_dma_ch_config,
  .dma_channel   = 5U
};

const XMC_DMA_CH_CONFIG_t dhSPI_SLAVE_rx_dma_ch_config =
{
  .enable_interrupt = true,
  .dst_transfer_width = (uint32_t)XMC_DMA_CH_TRANSFER_WIDTH_8,
  .src_transfer_width = (uint32_t)XMC_DMA_CH_TRANSFER_WIDTH_8,
  .dst_address_count_mode = (uint32_t)XMC_DMA_CH_ADDRESS_COUNT_MODE_INCREMENT,
  .src_address_count_mode = (uint32_t)XMC_DMA_CH_ADDRESS_COUNT_MODE_NO_CHANGE,
  .dst_burst_length = (uint32_t)XMC_DMA_CH_BURST_LENGTH_8,
  .src_burst_length = (uint32_t)XMC_DMA_CH_BURST_LENGTH_1,
  .transfer_flow = (uint32_t)XMC_DMA_CH_TRANSFER_FLOW_P2M_DMA,
  .transfer_type = (uint32_t)XMC_DMA_CH_TRANSFER_TYPE_SINGLE_BLOCK,
  .src_handshaking = (uint32_t)XMC_DMA_CH_SRC_HANDSHAKING_HARDWARE,
  .src_peripheral_request = DMA_PERIPHERAL_REQUEST(2U, 12U), /*DMA0_PERIPHERAL_REQUEST_USIC1_SR1_2*/
};

const SPI_SLAVE_DMA_CONFIG_t dhSPI_SLAVE_rx_dma_config =
{
  .dma_ch_config = &dhSPI_SLAVE_rx_dma_ch_config,
  .dma_channel   = 4U
};

const SPI_SLAVE_CONFIG_t dhSPI_SLAVE_conf =
{
  .channel_config = &dhSPI_SLAVE_channel_config,
  .global_dma    = &GLOBAL_DMA_0,
  .transmit_dma_config = &dhSPI_SLAVE_tx_dma_config,
  .receive_dma_config = &dhSPI_SLAVE_rx_dma_config,
  .mosi1_pin_config = &dhSPI_SLAVE_miso_pin,
  .mosi0_pin_config = &dhSPI_SLAVE_mosi_pin,
  .fptr_spi_slave_config = dhSPI_SLAVE_init,
  .tx_cbhandler = NULL,
  .rx_cbhandler = ISR_SpiSlaveRx,
  .parity_error_cbhandler = NULL,
  .slave_select_cbhandler = NULL,
  .transmit_mode = SPI_SLAVE_TRANSFER_MODE_DMA,
  .receive_mode = SPI_SLAVE_TRANSFER_MODE_DMA,
  .tx_fifo_size = XMC_USIC_CH_FIFO_DISABLED,
  .rx_fifo_size = XMC_USIC_CH_FIFO_DISABLED,
  .spi_configured_mode = XMC_SPI_CH_MODE_STANDARD,
  .tx_sr = 0U,
#ifdef USIC1_C0_DX0_P0_4
  .dx0_source = (SPI_SLAVE_INPUT_t)USIC1_C0_DX0_P0_4,
#else
  .dx0_source = SPI_SLAVE_INPUT_INVALID,
#endif
  .tx_dlr_line = 5U,
};

SPI_SLAVE_RUNTIME_t dhSPI_SLAVE_runtime =
{
  .spi_current_mode = XMC_SPI_CH_MODE_STANDARD,
  .data_size = SPI_SLAVE_DATA_SIZE_8BITS,
  .tx_busy = false,
  .rx_busy = false
};

SPI_SLAVE_t dhSPI_SLAVE =
{
  .channel = XMC_SPI1_CH0,
  .config = &dhSPI_SLAVE_conf,
  .runtime = &dhSPI_SLAVE_runtime
};

/**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/
/*Channel initialization function*/
SPI_SLAVE_STATUS_t dhSPI_SLAVE_init()
{
  SPI_SLAVE_STATUS_t status = SPI_SLAVE_STATUS_SUCCESS;
  /*Reset the runtime state variables*/
  dhSPI_SLAVE.runtime->tx_busy = false;
  dhSPI_SLAVE.runtime->rx_busy = false;

  /*Configure SCLK pin*/
  XMC_GPIO_Init((XMC_GPIO_PORT_t *)PORT0_BASE, 11U, &dhSPI_SLAVE_sclk_pin_config);
  /*Configure slave select pin*/
  XMC_GPIO_Init((XMC_GPIO_PORT_t *)PORT0_BASE, 6U, &dhSPI_SLAVE_slavesel_pin_config);
  status = (SPI_SLAVE_STATUS_t)GLOBAL_DMA_Init(&GLOBAL_DMA_0);
  XMC_DMA_CH_Init(XMC_DMA0, 5U, &dhSPI_SLAVE_tx_dma_ch_config);
  XMC_DMA_CH_EnableEvent(XMC_DMA0,  5U, XMC_DMA_CH_EVENT_TRANSFER_COMPLETE);

  XMC_DMA_CH_Init(XMC_DMA0, 4U, &dhSPI_SLAVE_rx_dma_ch_config);
  XMC_DMA_CH_EnableEvent(XMC_DMA0,  4U, XMC_DMA_CH_EVENT_TRANSFER_COMPLETE);

  /*Configure MOSI pin*/
  XMC_GPIO_Init((XMC_GPIO_PORT_t *)PORT0_BASE, 4U, &dhSPI_SLAVE_mosi_pin_config);
  /* Initialize USIC channel in SPI slave mode*/
  XMC_SPI_CH_Init(XMC_SPI1_CH0, &dhSPI_SLAVE_channel_config);
  XMC_SPI_CH_SetBitOrderMsbFirst(XMC_SPI1_CH0);

  XMC_SPI_CH_SetWordLength(XMC_SPI1_CH0, (uint8_t)8U);
  XMC_SPI_CH_SetFrameLength(XMC_SPI1_CH0, (uint8_t)16U);

  /*Set input source path*/
  XMC_SPI_CH_SetInputSource(XMC_SPI1_CH0, (XMC_SPI_CH_INPUT_t)XMC_USIC_CH_INPUT_DX0, 0U);
  XMC_SPI_CH_SetInputSource(XMC_SPI1_CH0, (XMC_SPI_CH_INPUT_t)XMC_USIC_CH_INPUT_DX1, 0U);
  XMC_SPI_CH_SetInputSource(XMC_SPI1_CH0, (XMC_SPI_CH_INPUT_t)XMC_USIC_CH_INPUT_DX2, 0U);
  XMC_SPI_CH_EnableInputInversion(XMC_SPI1_CH0, XMC_SPI_CH_INPUT_SLAVE_SELIN);
  XMC_SPI_CH_EnableInputInversion(XMC_SPI1_CH0, XMC_USIC_CH_INPUT_DX1);
  /*Set service request for transmit interrupt*/
  XMC_USIC_CH_SetInterruptNodePointer(XMC_SPI1_CH0, XMC_USIC_CH_INTERRUPT_NODE_POINTER_TRANSMIT_BUFFER,
     0U);
  /*Set service request for receive interrupt*/
  XMC_USIC_CH_SetInterruptNodePointer(XMC_SPI1_CH0, XMC_USIC_CH_INTERRUPT_NODE_POINTER_RECEIVE,
     1U);
  XMC_USIC_CH_SetInterruptNodePointer(XMC_SPI1_CH0, XMC_USIC_CH_INTERRUPT_NODE_POINTER_ALTERNATE_RECEIVE,
     1U);
  /*Set service request for SPI protocol events*/
  XMC_USIC_CH_SetInterruptNodePointer(XMC_SPI1_CH0, XMC_USIC_CH_INTERRUPT_NODE_POINTER_PROTOCOL,
     2U);
  /*Register transfer complete event handler*/
  XMC_DMA_CH_SetEventHandler(XMC_DMA0, 4U, dhSPI_SLAVE_dma_rx_handler);
  /*Register transfer complete event handler*/
  XMC_DMA_CH_SetEventHandler(XMC_DMA0, 5U, dhSPI_SLAVE_dma_tx_handler);
  /* Start SPI */
  XMC_SPI_CH_Start(XMC_SPI1_CH0);

  /* Initialize SPI Slave MISO pin */
  XMC_GPIO_Init((XMC_GPIO_PORT_t *)PORT0_BASE, 5U, &dhSPI_SLAVE_mosi1_pin_config);
  XMC_GPIO_SetHardwareControl((XMC_GPIO_PORT_t *)PORT0_BASE, 5U, XMC_GPIO_HWCTRL_DISABLED);

  return status;
}

void dhSPI_SLAVE_dma_tx_handler(XMC_DMA_CH_EVENT_t event)
{
  if(event == XMC_DMA_CH_EVENT_TRANSFER_COMPLETE)
  {
    dhSPI_SLAVE.runtime->tx_busy = false;
  }
}


void dhSPI_SLAVE_dma_rx_handler(XMC_DMA_CH_EVENT_t event)
{
  if(event == XMC_DMA_CH_EVENT_TRANSFER_COMPLETE)
  {
    dhSPI_SLAVE.runtime->rx_busy = false;
    XMC_SPI_CH_DisableEvent(XMC_SPI1_CH0, ((uint32_t)XMC_SPI_CH_EVENT_STANDARD_RECEIVE | (uint32_t)XMC_SPI_CH_EVENT_ALTERNATIVE_RECEIVE));
    ISR_SpiSlaveRx();

  }
}

