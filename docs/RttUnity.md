---
title: RTT & Unity 
author: 이우택 (wootaik@gmail.com)  
date: Mar 11 2020  
---

# RTT

## 목적

* 마이크로컨트롤러의 RTT(Real-Time Tracing) 개념을 이해하고 Debugger를 사용하여 입출력 할 수 있도록 힌다.

## 참고자료

* [RTT Viewer - SEGGER Wiki]: https://www.segger.com/products/debug-probes/j-link/tools/rtt-viewer/
  
* [Using Segger Real Time Terminal (RTT) with Eclipse - MCU on Eclipse]: https://mcuoneclipse.com/2015/07/07/using-segger-real-time-terminal-rtt-with-eclipse/

      


## RTT 개념

* Semihosting과 유사하게 타겟과 호스트 사이의 양방향 통신이 가능하다.
    * 별도의 통신 채널을 확보할 필요가 없으므로 간단하게 활용 가능
* Semihosting과 SWO와 비교하여 매우 빠르게 통신할 수 있다.



## 설정 및 활용 방법

다음의 단계를 거쳐서 설정한다.

1. SEGGER_RTT 파일들 가져 오기
    * include 경로 추가
2. SEGGER_RTT API
3. J-Link RTT Viewer

### SEGGER_RTT 파일들 가져 오기

* /vendor/SEGGER_RTT 의 파일들을 프로젝트에 추가하고 경로를 포함시켜 준다.

![RttUnity_vendor_SEGGER_RTT](D:\GitRepo\XmcTutorial\docs\images\RttUnity_vendor_SEGGER_RTT.png)



![RttUnity_Include](D:\GitRepo\XmcTutorial\docs\images\RttUnity_Include.png)



### SEGGER_RTT API

**[SEGGER_RTT.h]**

```c
/* 이전 생략 */
int       SEGGER_RTT_GetKey(void);

unsigned  SEGGER_RTT_Write(unsigned BufferIndex, const void* pBuffer, unsigned NumBytes);

unsigned  SEGGER_RTT_WriteString(unsigned BufferIndex, const char* s);

unsigned  SEGGER_RTT_PutChar(unsigned BufferIndex, char c);

int SEGGER_RTT_printf(unsigned BufferIndex, const char * sFormat, ...);

```



```c
#include <DAVE.h>
#include "SEGGER_RTT.h"

int main(void)
{
  DAVE_STATUS_t status;
  status = DAVE_Init();           /* Initialization of DAVE APPs  */
  if(status != DAVE_STATUS_SUCCESS)
  {  }

  SEGGER_RTT_PutChar(0, 'P');
  SEGGER_RTT_PutChar(0, 'u');
  SEGGER_RTT_PutChar(0, 't');
  SEGGER_RTT_PutChar(0, 'C');
  SEGGER_RTT_PutChar(0, 'h');
  SEGGER_RTT_PutChar(0, 'a');
  SEGGER_RTT_PutChar(0, 'r');
  SEGGER_RTT_PutChar(0, ' ');
  SEGGER_RTT_PutChar(0, 'T');
  SEGGER_RTT_PutChar(0, 'e');
  SEGGER_RTT_PutChar(0, 's');
  SEGGER_RTT_PutChar(0, 't');
  SEGGER_RTT_PutChar(0, '\n');

  SEGGER_RTT_Write(0, "Write Test\n", 11);
  SEGGER_RTT_WriteString(0, "Hello World from XMC using SEGGER_RTT!\r\n");

  int my_char;
  while(1U)
  {
	  my_char = SEGGER_RTT_GetKey();
	  if(my_char>=0){
		  SEGGER_RTT_PutChar(0, my_char);
	  }
  }
}

```



### J-Link RTT Viewer

![RttUnity_RTTViewerConfiguration](D:\GitRepo\XmcTutorial\docs\images\RttUnity_RTTViewerConfiguration.png)



![RttUnity_RTTViewer](D:\GitRepo\XmcTutorial\docs\images\RttUnity_RTTViewer.png)



## Summary

* 다양한 입출력 기능을 활용할 수 있다.
* Interrupt 를 사용하지 않고 Debugger의 기능을 사용하여 실시간 성능을 저하시키지 않는다.
* GDB와 RTT Viewer를 동시에 사용할 때 순서에 주의 하여야 한다.
    * RTT Viewer가 Disconnect 되어 있는 상태에서 GDB를 실행하고,
    * GDB가 Target board에서 실행 가능한 상태가 된 후에,
    * RTT Viewer를 Connect 하여야 한다.
    * 반복적으로 작업할 때 매우 번거롭다.

