<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="SPI_SLAVE" URI="http://resources/4.0.8/app/SPI_SLAVE/0" description="Configures a USIC channel to implement SPI slave functionality" mode="NOTSHARABLE" version="4.0.8" minDaveVersion="4.1.2" instanceLabel="dhSPI_SLAVE" appLabel="" containingProxySignal="true">
  <properties provideInit="true"/>
  <virtualSignals name="dx0_input_stage" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dx0ins" hwSignal="dx0ins" hwResource="//@hwResources.0"/>
  <virtualSignals name="dx1_input_stage" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dx1ins" hwSignal="dx1ins" hwResource="//@hwResources.0"/>
  <virtualSignals name="dx2_input_stage" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dx2ins" hwSignal="dx2ins" hwResource="//@hwResources.0"/>
  <virtualSignals name="dx3_input_stage" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dx3ins" hwSignal="dx3ins" hwResource="//@hwResources.0"/>
  <virtualSignals name="dx4_input_stage" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dx4ins" hwSignal="dx4ins" hwResource="//@hwResources.0"/>
  <virtualSignals name="dx5_input_stage" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dx5ins" hwSignal="dx5ins" hwResource="//@hwResources.0"/>
  <virtualSignals name="dout0_output" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dout0" hwSignal="dout0" hwResource="//@hwResources.0"/>
  <virtualSignals name="dout1_output" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dout1" hwSignal="dout1" hwResource="//@hwResources.0"/>
  <virtualSignals name="dout2_output" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dout2" hwSignal="dout2" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="dout3_output" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dout3" hwSignal="dout3" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="miso_pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_miso_mosi1" hwSignal="pad" hwResource="//@hwResources.2" visible="true"/>
  <virtualSignals name="mosi_pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi0" hwSignal="pad" hwResource="//@hwResources.1" visible="true"/>
  <virtualSignals name="mosi/miso[2]_pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi2" hwSignal="pad" hwResource="//@hwResources.3" required="false"/>
  <virtualSignals name="mosi/miso[3]_pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi3" hwSignal="pad" hwResource="//@hwResources.4" required="false"/>
  <virtualSignals name="sclk_in_pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_sclk" hwSignal="pad" hwResource="//@hwResources.5" visible="true"/>
  <virtualSignals name="slave_select_pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_select" hwSignal="pad" hwResource="//@hwResources.6" visible="true"/>
  <virtualSignals name="mosi_0_hw_o" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi_0_hw_o" hwSignal="hw_o" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="mosi_1_hw_o" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi_1_hw_o" hwSignal="hw_o" hwResource="//@hwResources.2" required="false"/>
  <virtualSignals name="mosi_2_hw_o" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi_2_hw_o" hwSignal="hw_o" hwResource="//@hwResources.3" required="false"/>
  <virtualSignals name="mosi_3_hw_o" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi_3_hw_o" hwSignal="hw_o" hwResource="//@hwResources.4" required="false"/>
  <virtualSignals name="event_transmit_buffer" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_std_tx_int" hwSignal="transmit_buffer_int" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_receive_start" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_rec_start_int" hwSignal="receive_start_int" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_std_receive" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_std_rx_int" hwSignal="standard_receive_int" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_alt_receive" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_alt_rx_int" hwSignal="alternate_receive_int" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_protocol" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_proto_specfic_int" hwSignal="protocol_specific_int" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="event_fifo_transmit" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_fifo_tx_int" hwSignal="standard_transmit_buffer_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_fifo_std_receive" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_fifo_rx_int" hwSignal="standard_receive_buffer_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_fifo_alt_receive" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_fifo_alt_rx_int" hwSignal="alternate_receive_buffer_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="sr_transmit" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_interrupt_spi_sl_tx" hwSignal="signal_in" hwResource="//@hwResources.7" required="false"/>
  <virtualSignals name="sr_receive" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_interrupt_spi_sl_rx" hwSignal="signal_in" hwResource="//@hwResources.8" required="false"/>
  <virtualSignals name="sr_protocol_events" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_interrupt_spi_sl_error" hwSignal="signal_in" hwResource="//@hwResources.9" required="false"/>
  <virtualSignals name="source_trigger" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_src_trigger_dlr_rx_in" hwSignal="in" hwResource="//@hwResources.13"/>
  <virtualSignals name="destination_trigger" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_dst_trigger_dlr_tx_in" hwSignal="in" hwResource="//@hwResources.12"/>
  <virtualSignals name="dlr_out" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_src_trigger_dlr_rx_out" hwSignal="out" hwResource="//@hwResources.13"/>
  <virtualSignals name="dlr_out" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_dst_trigger_dlr_tx_out" hwSignal="out" hwResource="//@hwResources.12"/>
  <virtualSignals name="DMA Transfer complete event" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_dma_interrupt_tx" hwSignal="dma_int" hwResource="//@hwResources.10" visible="true"/>
  <virtualSignals name="DMA Transfer complete event" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_dma_interrupt_rx" hwSignal="dma_int" hwResource="//@hwResources.11" visible="true"/>
  <virtualSignals name="Destination request" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_dma_ch_dst_req_tx" hwSignal="dest_req" hwResource="//@hwResources.10"/>
  <virtualSignals name="Source request" URI="http://resources/4.0.8/app/SPI_SLAVE/0/vs_dma_ch_src_req_rx" hwSignal="src_req" hwResource="//@hwResources.11"/>
  <virtualSignals name="MOSI pin_signal" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_mosi0" hwSignal="pin" hwResource="//@hwResources.14"/>
  <virtualSignals name="MISO pin_signal" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_miso_mosi1" hwSignal="pin" hwResource="//@hwResources.15"/>
  <virtualSignals name="MOSI\MISO_2 pin_signal" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_mosi2" hwSignal="pin" hwResource="//@hwResources.16"/>
  <virtualSignals name="MOSI\MISO_3 pin_signal" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_mosi3" hwSignal="pin" hwResource="//@hwResources.17"/>
  <virtualSignals name="SCLK pin_signal" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_sclk" hwSignal="pin" hwResource="//@hwResources.18"/>
  <virtualSignals name="Slave select pin_signal" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_select" hwSignal="pin" hwResource="//@hwResources.19"/>
  <requiredApps URI="http://resources/4.0.8/app/SPI_SLAVE/0/appres_cpu" requiredAppName="CPU_CTRL_XMC4" required="false" requiringMode="SHARABLE"/>
  <requiredApps URI="http://resources/4.0.8/app/SPI_SLAVE/0/appres_global_dma" requiredAppName="GLOBAL_DMA" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_DMA/v4_0_8/GLOBAL_DMA_0.app#/"/>
  </requiredApps>
  <hwResources name="Channel" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_usic_ch" resourceGroupUri="peripheral/usic/*/channel/*" mResGrpUri="peripheral/usic/*/channel/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/USIC1/USIC1_1.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="MOSI pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_port_pad_spi_mosi_0" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/Port0/Port0_0.dd#//@provided.19"/>
  </hwResources>
  <hwResources name="MISO pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_port_pad_spi_miso_mosi_1" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/Port0/Port0_0.dd#//@provided.29"/>
  </hwResources>
  <hwResources name="MOSI\MISO_2 pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_port_pad_spi_mosi_2" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="MOSI\MISO_3 pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_port_pad_spi_mosi_3" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="SCLK pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_port_pad_spi_sclk" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/Port0/Port0_0.dd#//@provided.6"/>
  </hwResources>
  <hwResources name="Slave select pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_port_pad_spi_sel" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/Port0/Port0_0.dd#//@provided.33"/>
  </hwResources>
  <hwResources name="NVIC Node Tx" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_nvic_node_tx" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/0/nvic/interrupt/*"/>
  <hwResources name="NVIC Node Rx" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_nvic_node_rx" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/0/nvic/interrupt/*"/>
  <hwResources name="NVIC Node Error" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_nvic_node_error" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/0/nvic/interrupt/*"/>
  <hwResources name="DMA channel Tx" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_dma_ch_tx" resourceGroupUri="resources/0.1.28/peripheral/dma8/0/ch/5" solverVariable="true" mResGrpUri="peripheral/sv0/0/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/GPDMA0/GPDMA0_0.dd#//@provided.0"/>
    <solverVarMap index="1">
      <value variableName="sv0" solverValue="dma8"/>
    </solverVarMap>
    <solverVarMap index="1">
      <value variableName="sv0" solverValue="dma8"/>
    </solverVarMap>
    <solverVarMap index="1">
      <value variableName="sv0" solverValue="dma8"/>
    </solverVarMap>
  </hwResources>
  <hwResources name="DMA channel Rx" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_dma_ch_rx" resourceGroupUri="resources/0.1.28/peripheral/dma8/0/ch/5" solverVariable="true" mResGrpUri="peripheral/sv0/0/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/GPDMA0/GPDMA0_0.dd#//@provided.4"/>
    <solverVarMap index="1">
      <value variableName="sv0" solverValue="dma8"/>
    </solverVarMap>
    <solverVarMap index="1">
      <value variableName="sv0" solverValue="dma8"/>
    </solverVarMap>
    <solverVarMap index="1">
      <value variableName="sv0" solverValue="dma8"/>
    </solverVarMap>
  </hwResources>
  <hwResources name="DLR channel Tx" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_dlr_ch_tx" resourceGroupUri="resources/0.1.28/peripheral/dlr/0/ch/5" mResGrpUri="peripheral/dlr/0/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DLR/DLR_0.dd#//@provided.3"/>
  </hwResources>
  <hwResources name="DLR channel Rx" URI="http://resources/4.0.8/app/SPI_SLAVE/0/hwres_dlr_ch_rx" resourceGroupUri="resources/0.1.28/peripheral/dlr/0/ch/2" mResGrpUri="peripheral/dlr/0/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DLR/DLR_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="MOSI pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_hwres_port_pad_spi_mosi_0" resourceGroupUri="devicepackage/0/142" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.17"/>
  </hwResources>
  <hwResources name="MISO pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_hwres_port_pad_spi_miso_mosi_1" resourceGroupUri="devicepackage/0/141" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.19"/>
  </hwResources>
  <hwResources name="MOSI\MISO_2 pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_hwres_port_pad_spi_mosi_2" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="MOSI\MISO_3 pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_hwres_port_pad_spi_mosi_3" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="SCLK pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_hwres_port_pad_spi_sclk" resourceGroupUri="devicepackage/0/139" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.14"/>
  </hwResources>
  <hwResources name="Slave select pin" URI="http://resources/4.0.8/app/SPI_SLAVE/0/__pin_hwres_port_pad_spi_sel" resourceGroupUri="devicepackage/0/140" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.18"/>
  </hwResources>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dout0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi0" systemDefined="true" sourceSignal="dout0_output" targetSignal="mosi_pin" required="false" srcVirtualSignal="//@virtualSignals.6" targetVirtualSignal="//@virtualSignals.11"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dout0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_miso_mosi1" systemDefined="true" sourceSignal="dout0_output" targetSignal="miso_pin" srcVirtualSignal="//@virtualSignals.6" targetVirtualSignal="//@virtualSignals.10"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dx0ins" systemDefined="true" sourceSignal="mosi_pin" targetSignal="dx0_input_stage" srcVirtualSignal="//@virtualSignals.11" targetVirtualSignal="//@virtualSignals.0"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dout0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi_0_hw_o" systemDefined="true" sourceSignal="dout0_output" targetSignal="mosi_0_hw_o" required="false" srcVirtualSignal="//@virtualSignals.6" targetVirtualSignal="//@virtualSignals.16"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dout1/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi_1_hw_o" systemDefined="true" sourceSignal="dout1_output" targetSignal="mosi_1_hw_o" required="false" srcVirtualSignal="//@virtualSignals.7" targetVirtualSignal="//@virtualSignals.17"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dout2/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi_2_hw_o" systemDefined="true" sourceSignal="dout2_output" targetSignal="mosi_2_hw_o" required="false" srcVirtualSignal="//@virtualSignals.8" targetVirtualSignal="//@virtualSignals.18"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dout3/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi_3_hw_o" systemDefined="true" sourceSignal="dout3_output" targetSignal="mosi_3_hw_o" required="false" srcVirtualSignal="//@virtualSignals.9" targetVirtualSignal="//@virtualSignals.19"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_sclk/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dx1ins" systemDefined="true" sourceSignal="sclk_in_pin" targetSignal="dx1_input_stage" srcVirtualSignal="//@virtualSignals.14" targetVirtualSignal="//@virtualSignals.1"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_select/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_dx2ins" systemDefined="true" sourceSignal="slave_select_pin" targetSignal="dx2_input_stage" srcVirtualSignal="//@virtualSignals.15" targetVirtualSignal="//@virtualSignals.2"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_std_tx_int/http://resources/4.0.8/app/SPI_SLAVE/0/vs_interrupt_spi_sl_tx" systemDefined="true" sourceSignal="event_transmit_buffer" targetSignal="sr_transmit" required="false" srcVirtualSignal="//@virtualSignals.20" targetVirtualSignal="//@virtualSignals.28"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_std_rx_int/http://resources/4.0.8/app/SPI_SLAVE/0/vs_interrupt_spi_sl_rx" systemDefined="true" sourceSignal="event_std_receive" targetSignal="sr_receive" required="false" srcVirtualSignal="//@virtualSignals.22" targetVirtualSignal="//@virtualSignals.29"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_alt_rx_int/http://resources/4.0.8/app/SPI_SLAVE/0/vs_interrupt_spi_sl_rx" systemDefined="true" sourceSignal="event_alt_receive" targetSignal="sr_receive" required="false" srcVirtualSignal="//@virtualSignals.23" targetVirtualSignal="//@virtualSignals.29"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_fifo_tx_int/http://resources/4.0.8/app/SPI_SLAVE/0/vs_interrupt_spi_sl_tx" systemDefined="true" sourceSignal="event_fifo_transmit" targetSignal="sr_transmit" required="false" srcVirtualSignal="//@virtualSignals.25" targetVirtualSignal="//@virtualSignals.28"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_fifo_rx_int/http://resources/4.0.8/app/SPI_SLAVE/0/vs_interrupt_spi_sl_rx" systemDefined="true" sourceSignal="event_fifo_std_receive" targetSignal="sr_receive" required="false" srcVirtualSignal="//@virtualSignals.26" targetVirtualSignal="//@virtualSignals.29"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_fifo_alt_rx_int/http://resources/4.0.8/app/SPI_SLAVE/0/vs_interrupt_spi_sl_rx" systemDefined="true" sourceSignal="event_fifo_alt_receive" targetSignal="sr_receive" required="false" srcVirtualSignal="//@virtualSignals.27" targetVirtualSignal="//@virtualSignals.29"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_proto_specfic_int/http://resources/4.0.8/app/SPI_SLAVE/0/vs_interrupt_spi_sl_error" systemDefined="true" sourceSignal="event_protocol" targetSignal="sr_protocol_events" required="false" srcVirtualSignal="//@virtualSignals.24" targetVirtualSignal="//@virtualSignals.30"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_rec_start_int/http://resources/4.0.8/app/SPI_SLAVE/0/vs_dst_trigger_dlr_tx_in" systemDefined="true" sourceSignal="event_receive_start" targetSignal="destination_trigger" srcVirtualSignal="//@virtualSignals.21" targetVirtualSignal="//@virtualSignals.32"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_std_rx_int/http://resources/4.0.8/app/SPI_SLAVE/0/vs_src_trigger_dlr_rx_in" systemDefined="true" sourceSignal="event_std_receive" targetSignal="source_trigger" srcVirtualSignal="//@virtualSignals.22" targetVirtualSignal="//@virtualSignals.31"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_alt_rx_int/http://resources/4.0.8/app/SPI_SLAVE/0/vs_src_trigger_dlr_rx_in" systemDefined="true" sourceSignal="event_alt_receive" targetSignal="source_trigger" srcVirtualSignal="//@virtualSignals.23" targetVirtualSignal="//@virtualSignals.31"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_dma_interrupt_tx/http://resources/4.0.8/app/SPI_SLAVE/0/vsra_gpdma_interrupt" systemDefined="true" sourceSignal="DMA Transfer complete event" targetSignal="Interrupt signal" srcVirtualSignal="//@virtualSignals.35" proxyTargetVirtualSignalUri="http://resources/4.0.8/app/GLOBAL_DMA/0/interrupt_dma" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_DMA/v4_0_8/GLOBAL_DMA_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../GLOBAL_DMA/v4_0_8/GLOBAL_DMA_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_dma_interrupt_rx/http://resources/4.0.8/app/SPI_SLAVE/0/vsra_gpdma_interrupt" systemDefined="true" sourceSignal="DMA Transfer complete event" targetSignal="Interrupt signal" srcVirtualSignal="//@virtualSignals.36" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_DMA/v4_0_8/GLOBAL_DMA_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../GLOBAL_DMA/v4_0_8/GLOBAL_DMA_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_dst_trigger_dlr_tx_out/http://resources/4.0.8/app/SPI_SLAVE/0/vs_dma_ch_dst_req_tx" systemDefined="true" sourceSignal="dlr_out" targetSignal="Destination request" srcVirtualSignal="//@virtualSignals.34" targetVirtualSignal="//@virtualSignals.37"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_src_trigger_dlr_rx_out/http://resources/4.0.8/app/SPI_SLAVE/0/vs_dma_ch_src_req_rx" systemDefined="true" sourceSignal="dlr_out" targetSignal="Source request" srcVirtualSignal="//@virtualSignals.33" targetVirtualSignal="//@virtualSignals.38"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi0/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_mosi0" systemDefined="true" sourceSignal="mosi_pin" targetSignal="MOSI pin_signal" srcVirtualSignal="//@virtualSignals.11" targetVirtualSignal="//@virtualSignals.39"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_mosi0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi0" systemDefined="true" sourceSignal="MOSI pin_signal" targetSignal="mosi_pin" srcVirtualSignal="//@virtualSignals.39" targetVirtualSignal="//@virtualSignals.11"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_miso_mosi1/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_miso_mosi1" systemDefined="true" sourceSignal="miso_pin" targetSignal="MISO pin_signal" srcVirtualSignal="//@virtualSignals.10" targetVirtualSignal="//@virtualSignals.40"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_miso_mosi1/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_miso_mosi1" systemDefined="true" sourceSignal="MISO pin_signal" targetSignal="miso_pin" srcVirtualSignal="//@virtualSignals.40" targetVirtualSignal="//@virtualSignals.10"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi2/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_mosi2" systemDefined="true" sourceSignal="mosi/miso[2]_pin" targetSignal="MOSI\MISO_2 pin_signal" srcVirtualSignal="//@virtualSignals.12" targetVirtualSignal="//@virtualSignals.41"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_mosi2/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi2" systemDefined="true" sourceSignal="MOSI\MISO_2 pin_signal" targetSignal="mosi/miso[2]_pin" srcVirtualSignal="//@virtualSignals.41" targetVirtualSignal="//@virtualSignals.12"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi3/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_mosi3" systemDefined="true" sourceSignal="mosi/miso[3]_pin" targetSignal="MOSI\MISO_3 pin_signal" srcVirtualSignal="//@virtualSignals.13" targetVirtualSignal="//@virtualSignals.42"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_mosi3/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_mosi3" systemDefined="true" sourceSignal="MOSI\MISO_3 pin_signal" targetSignal="mosi/miso[3]_pin" srcVirtualSignal="//@virtualSignals.42" targetVirtualSignal="//@virtualSignals.13"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_sclk/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_sclk" systemDefined="true" sourceSignal="sclk_in_pin" targetSignal="SCLK pin_signal" srcVirtualSignal="//@virtualSignals.14" targetVirtualSignal="//@virtualSignals.43"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_sclk/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_sclk" systemDefined="true" sourceSignal="SCLK pin_signal" targetSignal="sclk_in_pin" srcVirtualSignal="//@virtualSignals.43" targetVirtualSignal="//@virtualSignals.14"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_select/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_select" systemDefined="true" sourceSignal="slave_select_pin" targetSignal="Slave select pin_signal" srcVirtualSignal="//@virtualSignals.15" targetVirtualSignal="//@virtualSignals.44"/>
  <connections URI="http://resources/4.0.8/app/SPI_SLAVE/0/http://resources/4.0.8/app/SPI_SLAVE/0/__pin_vs_spi_sl_select/http://resources/4.0.8/app/SPI_SLAVE/0/vs_spi_sl_select" systemDefined="true" sourceSignal="Slave select pin_signal" targetSignal="slave_select_pin" srcVirtualSignal="//@virtualSignals.44" targetVirtualSignal="//@virtualSignals.15"/>
</ResourceModel:App>
