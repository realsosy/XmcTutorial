---
title: SWO & Unity 
author: 이우택 (wootaik@gmail.com)  
date: Mar 11 2020  
---

# SWO

## 목적

* 마이크로컨트롤러의 SWO(Single Wire Output) 개념을 이해하고 Debugger를 사용하여 출력 할 수 있도록 힌다.

## 참고자료

* [J-Link SWO Viewer]: https://www.segger.com/products/debug-probes/j-link/tools/j-link-swo-viewer/
  
* [Tutorial: Using Single Wire Output SWO with ARM Cortex-M and Eclipse - MCU on Eclipse]: https://mcuoneclipse.com/2016/10/17/tutorial-using-single-wire-output-swo-with-arm-cortex-m-and-eclipse/

      


## SWO 개념

* SWO 란 ARM의 Cortex-M Debug 인터페이스의 전용 기능
    * 별도의 핀을 사용하여 출력 정보를 실시간으로 전달
    * 아주 적은 부하를 사용하므로 CPU의 Real-Time 성능을 떨어뜨리지 않는다.



## 설정 및 활용 방법

다음의 단계를 거쳐서 설정한다.

* SWO 관련 서비스
    * ` uint32_t ITM_SendChar(uint32_t ch)` in /Libraries/CMSIS/Include/core_cm4.h

2. SWO 서비스 호출하기
2. Debugger 관련 설정
3. J-Link SWO Viewer & Console in GDB
4. SWO Service module 사용

### SWO 관련 서비스

* SWO 서비스와 관련된 CMSIS 라이브러리 기능
    * /Libraries/CMSIS/Include/core_cm4.h
    * `uint32_t ITM_SendChar(uint32_t ch)`

![SwoUnity_CMSIS](D:\GitRepo\XmcTutorial\docs\images\SwoUnity_CMSIS.png)



### SWO 서비스 호출하기

* `xmc_common.h` 혹은 `Dave.h` 를 include 하면 사용할 수 있다.
* 사용방법은 매우 간단하다.
    * `ITM_SendChar()`함수를 호출하기만 하면 된다.

```c
  ITM_SendChar('I');
```



### Debugger 관련 설정

* Debug Configurations 에서 
    * Enable SWO 를 Check 해 주고
    * CPU의 속도를 맞춰 주면된다.
* GDB 실행 시 Console 창에서 아래와 같이 출력되는 문자들을 확인할 수 있다.

![SwoUnity_Debug](D:\GitRepo\XmcTutorial\docs\images\SwoUnity_Debug.png)



![SwoUnity_GdbConsole](D:\GitRepo\XmcTutorial\docs\images\SwoUnity_GdbConsole.png)

### J-Link SWO Viewer 

* CPU의 속도를 알 수 없을 때는 SEGGER J-Link SWO Viewer를 사용하여 아래와 같이 확인할 수 있다.
    * 이때 Device의 종류를 정확히 설정해 주고
    * Board가 연결되어 있어야 한다.
* GDB를 활용하여 프로그램을 실행하면 SWO Viewer를 사용하여 출력 결과를 확인할 수 있다.

![SwoUnity_JLinkSwoConfig](D:\GitRepo\XmcTutorial\docs\images\SwoUnity_JLinkSwoConfig.png)



![SwoUnity_JLinkSwoViewer](D:\GitRepo\XmcTutorial\docs\images\SwoUnity_JLinkSwoViewer.png)



### SWO Service module 사용

* 한글자씩 전송하는 것이 번거로울 수 있다.
* 문자열을 전송하는 모듈을 만들어 사용하면 편의성을 향상할 수 있다.

**[SWO.h]**

```c
#include "xmc_common.h"

#define SWO_PrintChar(c) ITM_SendChar(c)
//void SWO_PrintChar  (char c);

void SWO_PrintString(const char *s);
```



**[SWO.c]**

```c
#include "SWO.h"

void SWO_PrintString(const char *s) {
  //
  // Print out character per character
  //
  while (*s) {
    SWO_PrintChar(*s++);
  }
}
```





## Summary

* ARM SWO trace pin을 사용하여 다양한 정보를 호스트로 전송할 수 있다.

* [장점]
    * 전용핀을 사용하여 매우 짧은 코드와 빠르게 실행할 수 있다.
* [단점]
    * Cortex-M의 상위 버젼에서만 지원된다. (Cortex-M0는 지원하지 않는 경우가 있다.)
    * 출력 기능만 사용 가능하다.

