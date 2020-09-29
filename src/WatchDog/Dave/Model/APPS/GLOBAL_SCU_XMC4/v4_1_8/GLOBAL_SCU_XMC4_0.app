<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="GLOBAL_SCU_XMC4" URI="http://resources/4.1.8/app/GLOBAL_SCU_XMC4/0" description="GLOBAL_SCU_XMC4 APP allows to register callback functions and to handle the service request Events." version="4.1.8" minDaveVersion="4.0.0" instanceLabel="GLOBAL_SCU_XMC4_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../WATCHDOG/v4_0_14/WATCHDOG_0.app#//@requiredApps.1"/>
  <properties singleton="true" provideInit="true" sharable="true"/>
  <virtualSignals name="sr_irq0" URI="http://resources/4.1.8/app/GLOBAL_SCU_XMC4/0/vs_nvic_signal_in" hwSignal="signal_in" hwResource="//@hwResources.0">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../WATCHDOG/v4_0_14/WATCHDOG_0.app#//@connections.0"/>
  </virtualSignals>
  <requiredApps URI="http://resources/4.1.8/app/GLOBAL_SCU_XMC4/0/appres_cpu" requiredAppName="CPU_CTRL_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CPU_CTRL_XMC4/v4_0_14/CPU_CTRL_XMC4_0.app#/"/>
  </requiredApps>
  <hwResources name="NVIC Node" URI="http://resources/4.1.8/app/GLOBAL_SCU_XMC4/0/hwres_global_scu_xmc4_node" resourceGroupUri="peripheral/cpu/0/nvic/interrupt/sv0" solverVariable="true" mResGrpUri="peripheral/cpu/0/nvic/interrupt/sv0">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CPU/CPU_0.dd#//@provided.7"/>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="0"/>
    </solverVarMap>
    <solverVarMap index="5">
      <value variableName="sv0" solverValue="0"/>
    </solverVarMap>
  </hwResources>
</ResourceModel:App>
