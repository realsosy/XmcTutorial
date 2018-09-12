<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="CAPTURE" URI="http://resources/4.0.2/app/CAPTURE/1" description="Perform signal analysis to find out the duty cycle and the period of an unknown input signal." mode="NOTSHARABLE" version="4.0.2" minDaveVersion="4.2.4" instanceLabel="dhCAPTURE_PERIOD" appLabel="" containingProxySignal="true">
  <properties provideInit="true"/>
  <virtualSignals name="global_enable" URI="http://resources/4.0.2/app/CAPTURE/1/vs_capture_ccu4_global_enable" hwSignal="global_signal" hwResource="//@hwResources.0"/>
  <virtualSignals name="global_enable" URI="http://resources/4.0.2/app/CAPTURE/1/vs_capture_ccu8_global_enable" hwSignal="global_signal" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="capture_pad" URI="http://resources/4.0.2/app/CAPTURE/1/vs_capture_input" hwSignal="pad" hwResource="//@hwResources.2" visible="true"/>
  <virtualSignals name="capture_input" URI="http://resources/4.0.2/app/CAPTURE/1/vs_ccu4_cc4_gp0_unsync" hwSignal="gp0_unsync" hwResource="//@hwResources.0"/>
  <virtualSignals name="capture_input" URI="http://resources/4.0.2/app/CAPTURE/1/vs_ccu8_cc8_gp0_unsync" hwSignal="gp0_unsync" hwResource="//@hwResources.1"/>
  <virtualSignals name="capture event" URI="http://resources/4.0.2/app/CAPTURE/1/vs_ccu4_cc4_event0" hwSignal="e0as" hwResource="//@hwResources.0"/>
  <virtualSignals name="capture event" URI="http://resources/4.0.2/app/CAPTURE/1/vs_ccu8_cc8_event0" hwSignal="e0as" hwResource="//@hwResources.1"/>
  <virtualSignals name="capture_interrupt" URI="http://resources/4.0.2/app/CAPTURE/1/vs_interrupt_capture" hwSignal="signal_in" hwResource="//@hwResources.3"/>
  <virtualSignals name="Capture Input Pin_signal" URI="http://resources/4.0.2/app/CAPTURE/1/__pin_vs_capture_input" hwSignal="pin" hwResource="//@hwResources.4"/>
  <requiredApps URI="http://resources/4.0.2/app/CAPTURE/1/app_global_ccu4" requiredAppName="GLOBAL_CCU4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_CCU4/v4_1_12/GLOBAL_CCU4_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.2/app/CAPTURE/1/app_global_ccu8" requiredAppName="GLOBAL_CCU8" required="false" requiringMode="SHARABLE"/>
  <requiredApps URI="http://resources/4.0.2/app/CAPTURE/1/appres_cpu_ctrl" requiredAppName="CPU_CTRL_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CPU_CTRL_XMC4/v4_0_14/CPU_CTRL_XMC4_0.app#/"/>
  </requiredApps>
  <hwResources name="CC4 Timer" URI="http://resources/4.0.2/app/CAPTURE/1/hwres_ccu4_cc4" resourceGroupUri="peripheral/ccu4/*/cc4/*" mResGrpUri="peripheral/ccu4/*/cc4/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CCU40/CCU40_0.dd#//@provided.16"/>
  </hwResources>
  <hwResources name="CC8 Timer" URI="http://resources/4.0.2/app/CAPTURE/1/hwres_ccu8_cc8" resourceGroupUri="" required="false" mResGrpUri="peripheral/ccu8/*/cc8/*"/>
  <hwResources name="Capture Input Pin" URI="http://resources/4.0.2/app/CAPTURE/1/hwres_port_pad_capture_in" resourceGroupUri="resources/0.1.40/port/p/1/pad/5" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/Port1/Port1_1.dd#//@provided.25"/>
  </hwResources>
  <hwResources name="Capture Event Node" URI="http://resources/4.0.2/app/CAPTURE/1/hwres_cpu_nvic_interrupt_event_0" resourceGroupUri="peripheral/cpu/0/nvic/interrupt/*" mResGrpUri="peripheral/cpu/0/nvic/interrupt/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CPU/CPU_0.dd#//@provided.16"/>
  </hwResources>
  <hwResources name="Capture Input Pin" URI="http://resources/4.0.2/app/CAPTURE/1/__pin_hwres_port_pad_capture_in" resourceGroupUri="devicepackage/0/78" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.14"/>
  </hwResources>
  <connections URI="http://resources/4.0.2/app/CAPTURE/1/http://resources/4.0.2/app/CAPTURE/1/vs_global_ccu4_enable/http://resources/4.0.2/app/CAPTURE/1/vs_capture_ccu4_global_enable" systemDefined="true" sourceSignal="ccu4_global" targetSignal="global_enable" targetVirtualSignal="//@virtualSignals.0" proxySrcVirtualSignalUri="http://resources/4.1.12/app/GLOBAL_CCU4/0/vs_global_ccu4_globalsignal" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_CCU4/v4_1_12/GLOBAL_CCU4_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../GLOBAL_CCU4/v4_1_12/GLOBAL_CCU4_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.2/app/CAPTURE/1/http://resources/4.0.2/app/CAPTURE/1/vs_global_ccu8_enable/http://resources/4.0.2/app/CAPTURE/1/vs_capture_ccu8_global_enable" systemDefined="true" targetSignal="global_enable" required="false" targetVirtualSignal="//@virtualSignals.1" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.2/app/CAPTURE/1/http://resources/4.0.2/app/CAPTURE/1/vs_capture_input/http://resources/4.0.2/app/CAPTURE/1/vs_ccu4_cc4_gp0_unsync" systemDefined="true" sourceSignal="capture_pad" targetSignal="capture_input" srcVirtualSignal="//@virtualSignals.2" targetVirtualSignal="//@virtualSignals.3"/>
  <connections URI="http://resources/4.0.2/app/CAPTURE/1/http://resources/4.0.2/app/CAPTURE/1/vs_capture_input/http://resources/4.0.2/app/CAPTURE/1/vs_ccu8_cc8_gp0_unsync" systemDefined="true" sourceSignal="capture_pad" targetSignal="capture_input" required="false" srcVirtualSignal="//@virtualSignals.2" targetVirtualSignal="//@virtualSignals.4"/>
  <connections URI="http://resources/4.0.2/app/CAPTURE/1/http://resources/4.0.2/app/CAPTURE/1/vs_ccu4_cc4_event0/http://resources/4.0.2/app/CAPTURE/1/vs_interrupt_capture" systemDefined="true" sourceSignal="capture event" targetSignal="capture_interrupt" srcVirtualSignal="//@virtualSignals.5" targetVirtualSignal="//@virtualSignals.7"/>
  <connections URI="http://resources/4.0.2/app/CAPTURE/1/http://resources/4.0.2/app/CAPTURE/1/vs_ccu8_cc8_event0/http://resources/4.0.2/app/CAPTURE/1/vs_interrupt_capture" systemDefined="true" sourceSignal="capture event" targetSignal="capture_interrupt" required="false" srcVirtualSignal="//@virtualSignals.6" targetVirtualSignal="//@virtualSignals.7"/>
  <connections URI="http://resources/4.0.2/app/CAPTURE/1/http://resources/4.0.2/app/CAPTURE/1/vs_capture_input/http://resources/4.0.2/app/CAPTURE/1/__pin_vs_capture_input" systemDefined="true" sourceSignal="capture_pad" targetSignal="Capture Input Pin_signal" srcVirtualSignal="//@virtualSignals.2" targetVirtualSignal="//@virtualSignals.8"/>
  <connections URI="http://resources/4.0.2/app/CAPTURE/1/http://resources/4.0.2/app/CAPTURE/1/__pin_vs_capture_input/http://resources/4.0.2/app/CAPTURE/1/vs_capture_input" systemDefined="true" sourceSignal="Capture Input Pin_signal" targetSignal="capture_pad" srcVirtualSignal="//@virtualSignals.8" targetVirtualSignal="//@virtualSignals.2"/>
</ResourceModel:App>
