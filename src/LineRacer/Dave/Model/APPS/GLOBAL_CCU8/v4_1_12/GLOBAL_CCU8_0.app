<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="GLOBAL_CCU8" URI="http://resources/4.1.12/app/GLOBAL_CCU8/0" description="Initializes CCU8 Global Register Set." version="4.1.12" minDaveVersion="4.0.0" instanceLabel="GLOBAL_CCU8_0" appLabel="" containingProxySignal="true">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../TIMER/v4_1_10/TIMER_0.app#//@requiredApps.1"/>
  <properties provideInit="true" sharable="true"/>
  <virtualSignals name="ccu8_global" URI="http://resources/4.1.12/app/GLOBAL_CCU8/0/vs_global_ccu8_globalsignal" hwSignal="global_signal" hwResource="//@hwResources.0">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../TIMER/v4_1_10/TIMER_0.app#//@connections.1"/>
  </virtualSignals>
  <virtualSignals name="clock_ccu" URI="http://resources/4.1.12/app/GLOBAL_CCU8/0/vs_global_ccu8_clk" hwSignal="clk" hwResource="//@hwResources.0"/>
  <virtualSignals name="ccu8_global_start" URI="http://resources/4.1.12/app/GLOBAL_CCU8/0/vs_global_ccu8_gsc_enable" hwSignal="gsc_enable" hwResource="//@hwResources.1" visible="true"/>
  <requiredApps URI="http://resources/4.1.12/app/GLOBAL_CCU8/0/appres_clock" requiredAppName="CLOCK_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK_XMC4/v4_0_22/CLOCK_XMC4_0.app#/"/>
  </requiredApps>
  <hwResources name="Global" URI="http://resources/4.1.12/app/GLOBAL_CCU8/0/hwres_peripheral_ccu8_global" resourceGroupUri="peripheral/ccu8/sv0/global" solverVariable="true" mResGrpUri="peripheral/ccu8/sv0/global">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CCU80/CCU80_0.dd#//@provided.12"/>
    <solverVarMap index="2">
      <value variableName="sv0" solverValue="0"/>
    </solverVarMap>
    <solverVarMap index="2">
      <value variableName="sv0" solverValue="0"/>
    </solverVarMap>
  </hwResources>
  <hwResources name="CCU8 sync start" URI="http://resources/4.1.12/app/GLOBAL_CCU8/0/hwres_peripheral_scu_gcu_ccu8_global_enable" resourceGroupUri="peripheral/scu/*/gcu/ccu8_global_enable/sv0" solverVariable="true" mResGrpUri="peripheral/scu/*/gcu/ccu8_global_enable/sv0">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/SCU/SCU_0.dd#//@provided.19"/>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="0"/>
    </solverVarMap>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="0"/>
    </solverVarMap>
  </hwResources>
  <connections URI="http://resources/4.1.12/app/GLOBAL_CCU8/0/http://resources/4.1.12/app/GLOBAL_CCU8/0/vs_clock_fccu/http://resources/4.1.12/app/GLOBAL_CCU8/0/vs_global_ccu8_clk" systemDefined="true" sourceSignal="clk_ccu_output" targetSignal="clock_ccu" targetVirtualSignal="//@virtualSignals.1" proxySrcVirtualSignalUri="http://resources/4.0.22/app/CLOCK_XMC4/0/vs_fccu" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../CLOCK_XMC4/v4_0_22/CLOCK_XMC4_0.app#//@virtualSignals.1"/>
    <srcVirtualSignal href="../../CLOCK_XMC4/v4_0_22/CLOCK_XMC4_0.app#//@virtualSignals.1"/>
  </connections>
</ResourceModel:App>
