---
title: Timer - Input Capture 
author: 이우택 (wootaik@gmail.com)  
date: Sep 01 2016  
---

# Timer - Input Capture

## 목적
* Input Capture 동작을 이해하고 DAVE App 을 살펴보고 이해하자.

## 참고자료

* [Capture] (DAVE APP on-line help)

## Timer

타이머는 주기적인 클럭 신호를 카운터의 입력으로 활용한 것이다. 중요 활용 용도는 다음과 같다.

* 일정 시간 간격으로 주기적인 이벤트를 발생하는 것이다. (Periodic Timer)
* 일정 시간 간격, 혹은 시간 경과 후에 외부로 신호를 발생할 수 있다. (Output Compare)
* 외부 신호의 발생 시각을 알 수 있는 용도로 활용할 수도 있다. (Input Capture)

### Periodic Timer (Output Compare)

* *Timer 참고*

### Input Capture

Input Capture 타이머에는 **카운터 레지스터(Counter Register)**에 연결된 **캡쳐 레지스터(Capture Value Register)**가 있다. 카운터 레지스터의 값은 일정한 클럭 속도 (일반적으로 프로세서 클럭신호)로 지속적으로 증가한다. 외부 신호가 발생하는 순간 타이머의 값이 캡쳐 레지스터로 복사되고 이벤트를 생성한다.  CPU에서는 이 캡쳐 레지스터의 값을 확인하여 외부신호가 발생한 순간을 알수있게 되는 것이다.

Input Capture 타이머의 대표적인 용도는 두 펄스의 엣지 사이의 시간을 측정하는 것이다.  연속적으로 캡쳐된 카운터값을 사용하여 두 펄스 사이에 경과 된 카운터 값의 차이를 알 수 있다.  경우에 따라 타이머의 카운트 레지스터가 값이 래치 된 후 자동으로 재설정 될 수 있다. 입력 캡처 핀은 일반적으로 입력 신호의 상승 또는 하강 에지에서 캡처하도록 소프트웨어적으로 설정할 수 있다.

![InputCapture](./images/Timer_InputCapture.png)

## DAVE APP (Capture APP)

### 

### 아키텍쳐(Architecture)



* Signals

Signal Name         | Input/Output | Availability | Description
--------------------|--------------|--------------|--------------
             |              |              |             

* APPS Consumed

APP Name    | Consumption            | Description
------------|------------------------|----------------------------------------
          |             |             
          |             |             

### 설정(Configuration)

* 

### 자료구조

```
;
```
열거형 자료형들은 다음과 같다.
```

```
### 메쏘드(Method)

* APP을 초기화하고, 현재의 동작상태를 검사하고, 시작/중지한다.



### 사용예

* 실습프로젝트


* Lab TimerCapture

## 요약

