---
title: Timer Input Capture Lab  
author: Wootaik Lee(wootaik@changwon.ac.kr)  
date: 2017-09-01  
---

# Timer Input Capture Lab  



## Objectives

*   Input Capture 를 사용해서 Event의 발생 주기와 On-Time을 측정할 수 있다.




## CAPTURE APP

*   APP Help - Configuration Parameters
*   APP Help - Methods



## To Do

*   신호의 발생 주기를 Tick 단위로 측정할 수 있다.
*   신호의 On-Time을 Tick 단위와 nano sec 단위로 측정할 수 있다.
*   실험을 위해서 PWM APP을 사용하여 10KHz, 50% Duty 의 신호를 발생시키고, 이것을 측정하도록 한다.

## Architecture Design

![LabTimerCapture_SysDiagram](images/LabTimerCapture_SysDiagram.png)



![LabTimerCapture_SwArchitecture](images/LabTimerCapture_SwArchitecture.png)



## [Activity]

*   Debugger 에 다음의 전역변수를 등록하고 중간에 Pause 하여 값을 확인한다.



| PwmFreqHz | DutyCycle | SignalPeriod | CapturedTime | CapturedTimeInNanoSec |
| --------- | --------- | ------------ | ------------ | --------------------- |
| 10000     | 5000      |              |              |                       |
| 10000     | 3000      |              |              |                       |
| 20000     | 3000      |              |              |                       |

*   Input Capture 를 사용할 때, 좀 더 넓은 의미에서 타이머를 사용할 때, 우리가 고려해야 하는 것(설계 인자)은 무엇인가요? 
*   위의 시험에서 3가지 Case 만 확인했습니다.  이것만 하면 충분 한가요? 부족하다면 필요한 시험을 제시해 보세요.