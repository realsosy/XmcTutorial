---
title: Semihosting 
author: 이우택 (wootaik@gmail.com)  
date: Mar 11 2020  
---

# Semihosting

## 목적

* 마이크로컨트롤러의 이벤트(Event) 개념을 이해하고 EVENT_DETECTOR, EVENT_GENERATOR APP 의 활용방법을 익힌다.

## 참고자료

* [Semihosting - SEGGER Wiki]: https://wiki.segger.com/Semihosting
  
* [Semihosting with GNU ARM Embedded - MCU on Eclipse]: https://mcuoneclipse.com/2014/09/11/semihosting-with-gnu-arm-embedded-launchpad-and-gnu-arm-eclipse-debug-plugins/

* [DAVE TIP of the day: Semihosting in DAVEv4]: https://www.infineonforums.com/threads/3489-DAVE-TIP-of-the-day-Semihosting-in-DAVEv4

    

## Semihosting 개념

* Semihosting이란 현재 활성화 되어 있는 디버거를 통하여 `printf()`를 실행하는 방법
    * 별도의 통신 채널을 확보할 필요가 없으므로 간단하게 활용 가능
    * ARM 계열에서는 이를 위한 특별한 exception 명령을 가지고 있다
    * exception 명령 사용하는 debug agent를 실행하여 기능을 수행한다.
* [주의] `scanf()` 도 활용 가능하다고 설명되어 있으나, DAVE 상에서는 실행이 되지 않는 것으로 판단된다.



## 설정 및 활용 방법

다음의 단계를 거쳐서 설정한다.

1. GNU Linker 의 Option 설정 
2. GDB의 semihosting 관련 기능 활성화
3. Source 코드에서 관련 함수 초기화

### GNU Linker Option 설정

* 다음의 내용을

    *Project > Properties > C/C++ Build > Settings* 에서 설정해 준다.

> ```
> --specs=rdimon.specs
> ```



![Semihosting_LinkerSetting](D:\GitRepo\XmcTutorial\docs\images\Semihosting_LinkerSetting.png)



### GDB Option 설정

![Semihosting_DebuggerSetting1](D:\GitRepo\XmcTutorial\docs\images\Semihosting_DebuggerSetting1.png)



![Semihosting_DebuggerSetting2](D:\GitRepo\XmcTutorial\docs\images\Semihosting_DebuggerSetting2.png)



### Source 코드의 추가 사항

* `XMC_DEBUG()` 함수를 사용할 수 있도록 `XMC_DEBUG_ENABLE`을 정의해 준다.

![Semihosting_Preprocessing](D:\GitRepo\XmcTutorial\docs\images\Semihosting_Preprocessing.png)



* `printf()` 함수를 활성화 하기 위하여 `initialise_monitor_handles(void)`를 호출하여 준다.

![Semihosting_Code](D:\GitRepo\XmcTutorial\docs\images\Semihosting_Code.png)



### 실행 결과 

![Semihosting_Console](D:\GitRepo\XmcTutorial\docs\images\Semihosting_Console.png)



## Summary

* 간단하게 `printf()`를 사용할 수 있다.
* 내부적으로 exception을 사용하여 IO를 처리하므로 real-time performance를 떨어뜨릴 수 있다.
    * 간단한 단위시험이나, idle 실행 시 상태를 모니터링 하는 정도로 활용하는 것이 적합하다고 판단된다.

