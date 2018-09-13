---
title: Timer  
author: 이우택 (wootaik@gmail.com)  
date: Sep 01 2016  
---

# Timer

## 목적
* Timer 동작을 이해하고 DAVE App 을 살펴보고 이해하자.

## 참고자료

* [TIMER] (DAVE APP on-line help)

## Timer

타이머는 주기적인 클럭 신호를 카운터의 입력으로 활용한 것이다. 중요 활용 용도는 다음과 같다.

* 일정 시간 간격으로 주기적인 이벤트를 발생하는 것이다. (Periodic Timer)
* 일정 시간 간격, 혹은 시간 경과 후에 외부로 신호를 발생할 수 있다. (Output Compare)
* 외부 신호의 발생 시각을 알 수 있는 용도로 활용할 수도 있다. (Input Capture)

### Periodic Timer (Output Compare)

카운터를 사용하여 주기적인 클럭신호를 측정하는 모듈을 타이머라고 한다.  하드웨어적인 클럭신호를 사용함으로 입력신호와 같은 정밀도로 이벤트를 생성시킬 수 있는 장점이 있다. 타이머를 사용하여 신시간운영체계(RTOS: Real-Time Operating System)에서 필요한 틱과 같은 주기적인 이벤트를 생성할 수도 있고, 직렬통신의 전송속도에 필요한 주기적 신호(예를 들어 Baud Rate 신호)등을 만들어 낼 수 있다.  일반적으로 주기적인 이벤트 등을 만들어 내는 경우를 타이머라 부르고,  외부로 신호를 만들어 낼 경우 Output Compare 라 부른다.

일반적으로 타이머는 클럭을 측정하는 **카운터 레지스터(Counter Register)** 가지고 있다.  CPU의 부하를 줄이고 주기, 시간 지연 등을 효과적으로 관리하기 위하여 **초기값을 설정할 수 있는 레지스터(Reload Value Register)**와 **최종값을 설정할 수 있는 레지스터(Terminal Value Register)**를 가지고 있는 경우가 많다.  타이머는 기본적으로 입력 클럭신호의 에지에 따라 그 값이 증가하게 되고, Overflow가 발생될 때 이벤트를 발생시키는 방식으로 동작하게 된다.  그러나 이와같이 사용한다면 카운터 값이 Overflow 가 발생될 때만 감지할 수 있으므로 활용도가 매우 떨어지게 된다.  Reload Value Register 와 Terminal Value Register를 사용하여 이 문제를 해결할 수 있다.

첫번째 방법은 Reload Value Register에 카운터의 초기값을 설정하도록 하는 것이다.  이렇게 하면 0에서 시작하여 카운트 동작을 실행하는 대신 사용자가 설정한 초기값 부터 시작하게 할 수 있게 된다.  다른 방법은 카운터가 Overflow 할 때 이벤트를 발생시키는 대신 카운터의 최종값을 Terminal Value Register에 사용자가 임의로 설정하도록 하는 것이다.  카운터의 값이 이 최종값과 같아지는 순간 이벤트를 발생하도록 하는 것이다. 이 두가지 방법 모두 Overflow 순간 이벤트를 발생시키는 방법과 유사하게 동작하지만 사용자가 그 기간을 임의로 설정할 수 있도록 하는 것이다.


![TimerBasic](./images/Timer_TimerBasic.png)



![ReloadMatch](./images/Timer_ReloadMatch.png)



타이머가 자동으로 초기값을 로딩하고 같은 동작을 반복할 지를 설정할 수 있도록 구성되어 있다. 자동으로 반복되지 않는 카운트와 반복되는 카운트를 각각 one-shot 또는 periodic 모드라고 구분 한다. 일반적으로 타이머의 제어 레지스터를 통하여 이 모드를 제어하게 된다.  one-shot 모드를 사용하여 임의의 시간지연을 만들어 낼 수도 있다.

### Input Capture

* *TimerCapture 참고*



## DAVE APP (TIMER APP)

TIMER APP은 CCU4 또는 CCU8 모듈의 슬라이스 한 개를 사용하여 정확한 하드웨어 타이머를 제공한다. 그리고 다음의 기능을 제공한다.

* 주어진 시간 간격으로 반복적인 이벤트 발생
* 하드웨어 타이머를 사용한 더 정확한 지연(delay) 발생
* 런타임 시 원하는 시간 간격 설정(마이크로초 단위)
* DAVE HW Signal Connections를 사용하여 타이머 이벤트를 다른 주변 장치의 트리거 소스나 인터럽트 발생을 위한 신호로 사용 가능

![Timer_Overview](./images/Timer_Overview.png)

### 아키텍쳐(Architecture)
![Timer_Architecture](./images/Timer_Architecture.png)

위의 그림은 TIMER APP의 내부 소프트웨어 아키텍처를 보여준다. TIMER APP의 각각의 인스턴스는 MCU에서 하나의 CCU 타이머 슬라이스를 사용한다. 이 APP은 GLOBAL_CCUx(x=[4, 8]) APP과 CLOCK 앱이 필요하다. TIMER APP은 또한 주변 장치들 간 연결을 위해 출력 신호를 제공한다.

* Signals

Signal Name         | Input/Output | Availability | Description
--------------------|--------------|--------------|--------------
event_time_interval | Output       | Conditional  | 타이머 이벤트

* APPS Consumed

APP Name    | Consumption            | Description
------------|------------------------|----------------------------------------
GLOBAL_CCU4 | Conditionally consumed | CCU4 프리스케일러(prescaler)를 시작한다
GLOBAL_CCU8 | Conditionally consumed | CCU8 프리스케일러(prescaler)를 시작한다

### 설정(Configuration)

![Timer_GeneralSettings](./images/Timer_GeneralSettings.png)

* Select timer module
    - CCU4: CCU4의 슬라이스 한개를 사용한다.
    - CCU8: CCU8의 슬라이스 한개를 사용한다.
* Timer Settings:Time interval[usec]
    - 이벤트를 발생을 위한 시간 간격을 설정
    - [0.2 to 4294967200]
* Timer Settings:Start after initialization
    - 시작과 함께 자동으로 타이머를 수행시작

![Timer_EventSettings](./images/Timer_EventSettings.png)

* Time interval event
    - 각 시간 간격마다 event_time_interval 이벤트를 출력한다.

### 자료구조
타이머 관련 설정 정보를 관리하기 위하여 TIMER 구조체를 활용하여 TIMER_t 자료형을 사용하고 있다. 이 구조체에는 TIMER Configuration과 관련된 정보들을 담고 있고, 의존성이 있는 CCU4와 CCU8의 연결 정보등을 담고 있다.
```
typedef struct TIMER
{
  uint32_t time_interval_value_us;  /**< Timer interval value for which event is being generated */
  const uint32_t timer_max_value_us;	/**< Maximum timer value in micro seconds for the available clock */
  const uint32_t timer_min_value_us;  /**< Minimum timer value in micro seconds for the available clock */
  /* 중간 생략 */
} TIMER_t;
```
TIMER 관련 동작을 프로그래밍 하기 위한 열거형 자료형들은 다음과 같다.
```
typedef enum TIMER_MODULE
{
  TIMER_MODULE_CCU4 = 0U, /**< CCU4 is selected */
  TIMER_MODULE_CCU8       /**< CCU8 is selected */
} TIMER_MODULE_t;

/**
 * @brief status of the TIMER APP
 */
typedef enum TIMER_STATUS{
  TIMER_STATUS_SUCCESS = 0U, /**< Status success */
  TIMER_STATUS_FAILURE       /**< Status failure */
} TIMER_STATUS_t;
```
### 메쏘드(Method)

* TIMER APP을 초기화하고, 현재의 동작상태를 검사하고, 시작/중지한다.

  `TIMER_STATUS_t  TIMER_Init (TIMER_t *const handle_ptr);`

  `bool  TIMER_GetTimerStatus (TIMER_t *const handle_ptr);`

  `TIMER_STATUS_t  TIMER_Start (TIMER_t *const handle_ptr);`

  `TIMER_STATUS_t  TIMER_Stop (TIMER_t *const handle_ptr);`

* TIMER 값을 읽거나 TIMER 값을 초기화한다.

  `uint32_t  TIMER_GetTime (TIMER_t *const handle_ptr);`

  `TIMER_STATUS_t  TIMER_Clear (TIMER_t *const handle_ptr);`

* 이벤트를 생성을 위한 새로운 시간 간격을 설정한다.

  `TIMER_STATUS_t  TIMER_SetTimeInterval (TIMER_t *const handle_ptr, uint32_t time_interval);`

    - time_interval : 새로운 시간 간격 값이다. 단위는 마이크로초이다.

* 인터럽트 상태를 확인하거나 이벤트를 클리어한다.

  `bool  TIMER_GetInterruptStatus (TIMER_t *const handle_ptr);`

  `void  TIMER_ClearEvent (TIMER_t *const handle_ptr);`


### 사용예

* 초기화
  설정 값의 초기화 사용자는 이와 같이 DAVE APP을 설정하고 사용하면 main.c 함수에서 DAVE_Init() 함수가 호출되어 개별적인 APP을 초기화 하지 않고 사용할 수 있다. 만약 이벤트 설정를 바꾸거나 사용할 하드웨어 모듈을 변경 시는 초기화 함수를 명시적으로 호출하여야 한다.

* 시작과 정지
    - TIMER_GetTimerStatus 함수를 사용하여 현재 타이머 상태를 확인한다.
    - 만약 타이머가 정지 상태라면 TIMER_Start 함수를 사용하여 타이머를 시작한다.
    - 만약 타이머가 동작 상태라면 TIMER_Stop 함수를 사용하여 타이머를 정지시킨다.

```
TIMER_STATUS_t timer_status;
if (TIMER_GetTimerStatus(&dhTIMER_0) == false)
{
  timer_status = TIMER_Start(&dhTIMER_0);
}
else
{
  timer_status = TIMER_Stop(&dhTIMER_0);
}
```

* 타이머 값 읽기
    - TIMER_GetTime 함수를 사용하여 현재 타이머 값을 읽을 수 있다. 단위는 마이크로초이다.
    - TIMER_Clear 함수를 사용하여 현재 타이머 값을 클리어 할 수 있다.

```
uint32_t timer_value;
TIMER_STATUS_t timer_status;
timer_value = TIMER_GetTime(&dhTIMER_0);
timer_status = TIMER_Clear(&dhTIMER_0);
```

* 타이머 시간 간격 설정
    - TIMER_SetTimeInterval 함수를 사용하여 타이머 시간 간격을 다시 설정할 수 있다.
    - 시간 간격 설정 시 타이머는 정지 상태여야 한다.

```
TIMER_STATUS_t timer_status;
TIMER_Stop(&dhTIMER_0);
timer_status = TIMER_SetTimeInterval(&dhTIMER_0, 1000000); // change to 1s
TIMER_Start(&dhTIMER_0);
```


## 실습프로젝트

* Lab Timer

## 요약

