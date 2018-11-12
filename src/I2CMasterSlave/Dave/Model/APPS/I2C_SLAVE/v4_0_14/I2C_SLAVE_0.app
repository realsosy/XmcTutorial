<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="I2C_SLAVE" URI="http://resources/4.0.14/app/I2C_SLAVE/0" description="Configures a USIC channel to implement I2C slave functionality." mode="NOTSHARABLE" version="4.0.14" minDaveVersion="4.1.2" instanceLabel="dhI2C_SLAVE" appLabel="" containingProxySignal="true">
  <properties provideInit="true"/>
  <virtualSignals name="DMA Transfer complete event" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_dma_interrupt_tx" hwSignal="dma_int" hwResource="//@hwResources.6"/>
  <virtualSignals name="DMA Transfer complete event" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_dma_interrupt_rx" hwSignal="dma_int" hwResource="//@hwResources.7"/>
  <virtualSignals name="source_trigger" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_src_trigger_dlr_rx_in" hwSignal="in" hwResource="//@hwResources.9"/>
  <virtualSignals name="destination_trigger" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_dst_trigger_dlr_tx_in" hwSignal="in" hwResource="//@hwResources.8"/>
  <virtualSignals name="dlr_out" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_src_trigger_dlr_rx_out" hwSignal="out" hwResource="//@hwResources.9"/>
  <virtualSignals name="dlr_out" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_dst_trigger_dlr_tx_out" hwSignal="out" hwResource="//@hwResources.8"/>
  <virtualSignals name="Destination request" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_dma_ch_dst_req_tx" hwSignal="dest_req" hwResource="//@hwResources.6"/>
  <virtualSignals name="Source request" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_dma_ch_src_req_rx" hwSignal="src_req" hwResource="//@hwResources.7"/>
  <virtualSignals name="sda_pin" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sdapad" hwSignal="pad" hwResource="//@hwResources.4" visible="true"/>
  <virtualSignals name="scl_pin" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sclpad" hwSignal="pad" hwResource="//@hwResources.5" visible="true"/>
  <virtualSignals name="tx pin" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_dout0" hwSignal="dout0" hwResource="//@hwResources.0"/>
  <virtualSignals name="rx pin" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_dx0ins" hwSignal="dx0ins" hwResource="//@hwResources.0"/>
  <virtualSignals name="sclk pin" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sclk" hwSignal="sclkout" hwResource="//@hwResources.0"/>
  <virtualSignals name="clockin" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_dx1ins" hwSignal="dx1ins" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_transmit_buffer" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_std_tx_int" hwSignal="transmit_buffer_int" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_std_receive" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_std_rx_int" hwSignal="standard_receive_int" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_alt_receive" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_alt_rx_int" hwSignal="alternate_receive_int" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_fifo_transmit" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_fifo_tx_int" hwSignal="standard_transmit_buffer_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_fifo_std_receive" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_fifo_rx_int" hwSignal="standard_receive_buffer_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_fifo_alt_receive" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_fifo_alt_rx_int" hwSignal="alternate_receive_buffer_int" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_protocol" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_proto_specfic_int" hwSignal="protocol_specific_int" hwResource="//@hwResources.0"/>
  <virtualSignals name="sr_transmit" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_tx_int" hwSignal="signal_in" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="sr_receive" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_rx_int" hwSignal="signal_in" hwResource="//@hwResources.2" required="false"/>
  <virtualSignals name="sr_protocol_events" URI="http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_error_int" hwSignal="signal_in" hwResource="//@hwResources.3"/>
  <virtualSignals name="SDA_signal" URI="http://resources/4.0.14/app/I2C_SLAVE/0/__pin_vs_i2c_sdapad" hwSignal="pin" hwResource="//@hwResources.10"/>
  <virtualSignals name="SCL_signal" URI="http://resources/4.0.14/app/I2C_SLAVE/0/__pin_vs_i2c_sclpad" hwSignal="pin" hwResource="//@hwResources.11"/>
  <requiredApps URI="http://resources/4.0.14/app/I2C_SLAVE/0/appres_clock" requiredAppName="CLOCK_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK_XMC4/v4_0_22/CLOCK_XMC4_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.14/app/I2C_SLAVE/0/appres_cpu" requiredAppName="CPU_CTRL_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CPU_CTRL_XMC4/v4_0_12/CPU_CTRL_XMC4_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.14/app/I2C_SLAVE/0/appres_global_dma" requiredAppName="GLOBAL_DMA" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_DMA/v4_0_8/GLOBAL_DMA_0.app#/"/>
  </requiredApps>
  <hwResources name="Channel" URI="http://resources/4.0.14/app/I2C_SLAVE/0/hwres_usic_channel" resourceGroupUri="peripheral/usic/*/channel/*" mResGrpUri="peripheral/usic/*/channel/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/USIC1/USIC1_1.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="NVIC Node Tx" URI="http://resources/4.0.14/app/I2C_SLAVE/0/hwres_nvic_node_i2c_tx" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/0/nvic/interrupt/*"/>
  <hwResources name="NVIC Node Rx" URI="http://resources/4.0.14/app/I2C_SLAVE/0/hwres_nvic_node_i2c_rx" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/0/nvic/interrupt/*"/>
  <hwResources name="NVIC Node Error" URI="http://resources/4.0.14/app/I2C_SLAVE/0/hwres_nvic_node_i2c_error" resourceGroupUri="peripheral/cpu/0/nvic/interrupt/*" mResGrpUri="peripheral/cpu/0/nvic/interrupt/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CPU/CPU_0.dd#//@provided.30"/>
  </hwResources>
  <hwResources name="SDA" URI="http://resources/4.0.14/app/I2C_SLAVE/0/hwres_i2c_sda" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/Port0/Port0_0.dd#//@provided.6"/>
  </hwResources>
  <hwResources name="SCL" URI="http://resources/4.0.14/app/I2C_SLAVE/0/hwres_i2c_scl" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/Port0/Port0_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="DMA channel Tx" URI="http://resources/4.0.14/app/I2C_SLAVE/0/hwres_tx_dma_channel" resourceGroupUri="resources/0.1.28/peripheral/dma8/0/ch/5" solverVariable="true" mResGrpUri="peripheral/sv0/0/ch/*">
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
  <hwResources name="DMA channel Rx" URI="http://resources/4.0.14/app/I2C_SLAVE/0/hwres_rx_dma_channel" resourceGroupUri="resources/0.1.28/peripheral/dma8/0/ch/5" solverVariable="true" mResGrpUri="peripheral/sv0/0/ch/*">
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
  <hwResources name="DLR channel Tx" URI="http://resources/4.0.14/app/I2C_SLAVE/0/hwres_tx_dma_dlr" resourceGroupUri="resources/0.1.28/peripheral/dlr/0/ch/2" mResGrpUri="peripheral/dlr/0/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DLR/DLR_0.dd#//@provided.3"/>
  </hwResources>
  <hwResources name="DLR channel Rx" URI="http://resources/4.0.14/app/I2C_SLAVE/0/hwres_rx_dma_dlr" resourceGroupUri="resources/0.1.28/peripheral/dlr/0/ch/2" mResGrpUri="peripheral/dlr/0/ch/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DLR/DLR_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="SDA" URI="http://resources/4.0.14/app/I2C_SLAVE/0/__pin_hwres_i2c_sda" resourceGroupUri="devicepackage/0/97" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.8"/>
  </hwResources>
  <hwResources name="SCL" URI="http://resources/4.0.14/app/I2C_SLAVE/0/__pin_hwres_i2c_scl" resourceGroupUri="devicepackage/0/95" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.2"/>
  </hwResources>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_dout0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sdapad" systemDefined="true" sourceSignal="tx pin" targetSignal="sda_pin" srcVirtualSignal="//@virtualSignals.10" targetVirtualSignal="//@virtualSignals.8"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sdapad/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_dx0ins" systemDefined="true" sourceSignal="sda_pin" targetSignal="rx pin" srcVirtualSignal="//@virtualSignals.8" targetVirtualSignal="//@virtualSignals.11"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sclk/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sclpad" systemDefined="true" sourceSignal="sclk pin" targetSignal="scl_pin" srcVirtualSignal="//@virtualSignals.12" targetVirtualSignal="//@virtualSignals.9"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sclpad/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_dx1ins" systemDefined="true" sourceSignal="scl_pin" targetSignal="clockin" srcVirtualSignal="//@virtualSignals.9" targetVirtualSignal="//@virtualSignals.13"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_std_tx_int/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_tx_int" systemDefined="true" sourceSignal="event_transmit_buffer" targetSignal="sr_transmit" required="false" srcVirtualSignal="//@virtualSignals.14" targetVirtualSignal="//@virtualSignals.21"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_std_rx_int/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_rx_int" systemDefined="true" sourceSignal="event_std_receive" targetSignal="sr_receive" required="false" srcVirtualSignal="//@virtualSignals.15" targetVirtualSignal="//@virtualSignals.22"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_alt_rx_int/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_rx_int" systemDefined="true" sourceSignal="event_alt_receive" targetSignal="sr_receive" required="false" srcVirtualSignal="//@virtualSignals.16" targetVirtualSignal="//@virtualSignals.22"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_fifo_tx_int/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_tx_int" systemDefined="true" sourceSignal="event_fifo_transmit" targetSignal="sr_transmit" required="false" srcVirtualSignal="//@virtualSignals.17" targetVirtualSignal="//@virtualSignals.21"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_fifo_rx_int/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_rx_int" systemDefined="true" sourceSignal="event_fifo_std_receive" targetSignal="sr_receive" required="false" srcVirtualSignal="//@virtualSignals.18" targetVirtualSignal="//@virtualSignals.22"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_fifo_alt_rx_int/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_rx_int" systemDefined="true" sourceSignal="event_fifo_alt_receive" targetSignal="sr_receive" required="false" srcVirtualSignal="//@virtualSignals.19" targetVirtualSignal="//@virtualSignals.22"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_proto_specfic_int/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_error_int" systemDefined="true" sourceSignal="event_protocol" targetSignal="sr_protocol_events" srcVirtualSignal="//@virtualSignals.20" targetVirtualSignal="//@virtualSignals.23"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_std_tx_int/http://resources/4.0.14/app/I2C_SLAVE/0/vs_dst_trigger_dlr_tx_in" systemDefined="true" sourceSignal="event_transmit_buffer" targetSignal="destination_trigger" srcVirtualSignal="//@virtualSignals.14" targetVirtualSignal="//@virtualSignals.3"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_dma_interrupt_tx/http://resources/4.0.14/app/I2C_SLAVE/0/vsra_gpdma_interrupt" systemDefined="true" sourceSignal="DMA Transfer complete event" targetSignal="Interrupt signal" srcVirtualSignal="//@virtualSignals.0" proxyTargetVirtualSignalUri="http://resources/4.0.8/app/GLOBAL_DMA/0/interrupt_dma" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_DMA/v4_0_8/GLOBAL_DMA_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../GLOBAL_DMA/v4_0_8/GLOBAL_DMA_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_dma_interrupt_rx/http://resources/4.0.14/app/I2C_SLAVE/0/vsra_gpdma_interrupt" systemDefined="true" sourceSignal="DMA Transfer complete event" targetSignal="Interrupt signal" srcVirtualSignal="//@virtualSignals.1" proxyTargetVirtualSignalUri="http://resources/4.0.8/app/GLOBAL_DMA/0/interrupt_dma" containingProxySignal="true">
    <targetVirtualSignal href="../../GLOBAL_DMA/v4_0_8/GLOBAL_DMA_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_dst_trigger_dlr_tx_out/http://resources/4.0.14/app/I2C_SLAVE/0/vs_dma_ch_dst_req_tx" systemDefined="true" sourceSignal="dlr_out" targetSignal="Destination request" srcVirtualSignal="//@virtualSignals.5" targetVirtualSignal="//@virtualSignals.6"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_std_rx_int/http://resources/4.0.14/app/I2C_SLAVE/0/vs_src_trigger_dlr_rx_in" systemDefined="true" sourceSignal="event_std_receive" targetSignal="source_trigger" srcVirtualSignal="//@virtualSignals.15" targetVirtualSignal="//@virtualSignals.2"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_alt_rx_int/http://resources/4.0.14/app/I2C_SLAVE/0/vs_src_trigger_dlr_rx_in" systemDefined="true" sourceSignal="event_alt_receive" targetSignal="source_trigger" srcVirtualSignal="//@virtualSignals.16" targetVirtualSignal="//@virtualSignals.2"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_src_trigger_dlr_rx_out/http://resources/4.0.14/app/I2C_SLAVE/0/vs_dma_ch_src_req_rx" systemDefined="true" sourceSignal="dlr_out" targetSignal="Source request" srcVirtualSignal="//@virtualSignals.4" targetVirtualSignal="//@virtualSignals.7"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sdapad/http://resources/4.0.14/app/I2C_SLAVE/0/__pin_vs_i2c_sdapad" systemDefined="true" sourceSignal="sda_pin" targetSignal="SDA_signal" srcVirtualSignal="//@virtualSignals.8" targetVirtualSignal="//@virtualSignals.24"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/__pin_vs_i2c_sdapad/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sdapad" systemDefined="true" sourceSignal="SDA_signal" targetSignal="sda_pin" srcVirtualSignal="//@virtualSignals.24" targetVirtualSignal="//@virtualSignals.8"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sclpad/http://resources/4.0.14/app/I2C_SLAVE/0/__pin_vs_i2c_sclpad" systemDefined="true" sourceSignal="scl_pin" targetSignal="SCL_signal" srcVirtualSignal="//@virtualSignals.9" targetVirtualSignal="//@virtualSignals.25"/>
  <connections URI="http://resources/4.0.14/app/I2C_SLAVE/0/http://resources/4.0.14/app/I2C_SLAVE/0/__pin_vs_i2c_sclpad/http://resources/4.0.14/app/I2C_SLAVE/0/vs_i2c_sclpad" systemDefined="true" sourceSignal="SCL_signal" targetSignal="scl_pin" srcVirtualSignal="//@virtualSignals.25" targetVirtualSignal="//@virtualSignals.9"/>
</ResourceModel:App>
