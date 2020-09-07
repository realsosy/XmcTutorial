<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="COUNTER" URI="http://resources/4.1.10/app/COUNTER/0" description="Counts the occurrences of external events using one timer slice of CCU4 or CCU8 " mode="NOTSHARABLE" version="4.1.10" minDaveVersion="4.3.2" instanceLabel="dhCOUNTER_0" appLabel="" containingProxySignal="true">
  <properties provideInit="true"/>
  <virtualSignals name="global_signal" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_global_signal" hwSignal="global_signal" hwResource="//@hwResources.0"/>
  <virtualSignals name="global_signal" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_global_signal" hwSignal="global_signal" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="counter_output" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_timer_status" hwSignal="st" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="counter_output" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_timer_status" hwSignal="st" hwResource="//@hwResources.1" required="false" visible="true"/>
  <virtualSignals name="event_rollover" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_rollover_event" hwSignal="pmus_omds" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_rollover" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_rollover_event" hwSignal="pmus_omds" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="event_count_match" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_count_match" hwSignal="cmds_cmus" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="event_count_match" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_count_match" hwSignal="cmd1s_cmu1s" hwResource="//@hwResources.1" required="false" visible="true"/>
  <virtualSignals name="event_edge_detection" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_edge_event" hwSignal="e0as" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_edge_detection" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_edge_event" hwSignal="e0as" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="event_gating_level_detection" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_cdir_gate_event" hwSignal="e1as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_gating_level_detection" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_cdir_gate_event" hwSignal="e1as" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="event_gating_level_detection" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_gating_event" hwSignal="e2as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_gating_level_detection" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_gating_event" hwSignal="e2as" hwResource="//@hwResources.1" required="false"/>
  <virtualSignals name="counter_input" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_input_signal" hwSignal="gp0_unsync" hwResource="//@hwResources.0" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../DIGITAL_IO/v4_0_16/DIGITAL_IO_0.app#//@connections.2"/>
  </virtualSignals>
  <virtualSignals name="counter_input" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_input_signal" hwSignal="gp0_unsync" hwResource="//@hwResources.1" required="false" visible="true"/>
  <virtualSignals name="gating_input" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_event2_input" hwSignal="gp2_unsync" hwResource="//@hwResources.0" required="false" visible="true"/>
  <virtualSignals name="gating_input" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_event2_input" hwSignal="gp2_unsync" hwResource="//@hwResources.1" required="false" visible="true"/>
  <virtualSignals name="gating_input" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_event1_input" hwSignal="gp1_unsync" hwResource="//@hwResources.0" required="false" visible="true"/>
  <virtualSignals name="gating_input" URI="http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_event1_input" hwSignal="gp1_unsync" hwResource="//@hwResources.1" required="false" visible="true"/>
  <requiredApps URI="http://resources/4.1.10/app/COUNTER/0/appres_ccu4_global" requiredAppName="GLOBAL_CCU4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_CCU4/v4_1_12/GLOBAL_CCU4_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.1.10/app/COUNTER/0/appres_ccu8_global" requiredAppName="GLOBAL_CCU8" required="false" requiringMode="SHARABLE"/>
  <hwResources name="CCU4 Slice" URI="http://resources/4.1.10/app/COUNTER/0/hwres_ccu4_slice" resourceGroupUri="peripheral/ccu4/*/cc4/*" mResGrpUri="peripheral/ccu4/*/cc4/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CCU41/CCU41_1.dd#//@provided.3"/>
  </hwResources>
  <hwResources name="CCU8 Slice" URI="http://resources/4.1.10/app/COUNTER/0/hwres_ccu8_slice" resourceGroupUri="" required="false" mResGrpUri="peripheral/ccu8/*/cc8/*"/>
  <connections URI="http://resources/4.1.10/app/COUNTER/0/http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_global/http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_global_signal" systemDefined="true" sourceSignal="ccu4_global" targetSignal="global_signal" targetVirtualSignal="//@virtualSignals.0" proxySrcVirtualSignalUri="http://resources/4.1.12/app/GLOBAL_CCU4/0/vs_global_ccu4_globalsignal" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_CCU4/v4_1_12/GLOBAL_CCU4_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../GLOBAL_CCU4/v4_1_12/GLOBAL_CCU4_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.1.10/app/COUNTER/0/http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_global/http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu8_global_signal" systemDefined="true" targetSignal="global_signal" required="false" targetVirtualSignal="//@virtualSignals.1" containingProxySignal="true"/>
  <connections URI="http://resources/4.1.10/app/COUNTER/0/http://resources/4.1.10/app/COUNTER/0/vs_counter_ccu4_count_match/http://resources/4.0.8/app/INTERRUPT/0/vs_nvic_signal_in" sourceSignal="event_count_match" targetSignal="sr_irq" srcVirtualSignal="//@virtualSignals.6">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../INTERRUPT/v4_0_8/INTERRUPT_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../INTERRUPT/v4_0_8/INTERRUPT_0.app#//@virtualSignals.0"/>
  </connections>
</ResourceModel:App>
