---
title : UnitTest-ServoMotor
author : Minkyu Kim (kimmin7894@gmail.com)
date : Sep 18 2019
---
# ServoMotor

## Purpose and Scope

PWM App을 이용하여 SG-90 제품의 데이터시트에 기술된 대로 올바르게 동작하는지 실험하고 기록한다. 이 실험을 통하여 다음의 성능을 중심적으로 실험한다.

* SG-90의 위치제어 성능

## References

1. SG-90.pdf



## ServoMotor 기초 지식

### 서보모터란?

* 서보모터란 각도 또는 위치, 속도, 가속도를 정확하게 제어할 수 있는 원형 또는 선형 엑츄에이터를 말한다. 서보모터는 모터와 위치 피드백을 위한 센서, 컨트롤러를 포함하고 있다.

### 서보모터(MG-996R) 신호 모듈레이션 방법

<img src=".\images\ServoMotor_SignalModulation.png">

* SG-90는 일정한 주기의 PWM 신호로 제어되며, 신호의 on time 시간에 따라 로터의 위치가 결정된다.

* SG-90제어를 위한 PWM 신호는 다음의 특징을 지닌다.

    * 주기 : 20ms(50 Hz)

    * on time시간 : 0.9ms(60도) ~ 2.1ms(-60도)

![ServoArm](.\images\ServoMotor_ServoArm.png)



## 실험 환경

### H/W Setup

![Circiut](.\images\ServoMotor_Environment.png)

* PWM 연결: 3.3V -> 5V (TTL 범위의 입력 신호로 정상 동작 확인)
* SG-90전원 공급: 

    * 서보 동작시 급격한 전력이 소모되므로, Battery 에서 직접 연결하여 사용

    * 동작 전압 4.8~ 7.2 V 이나, Battery 의 공급 전압이 7.4 V (2.7 X 2) 이므로 다이오드를 2개 직렬로 연결하여 전압 강하시켜 사용
* PC를 사용하여 서보모터에 입력되는 PWM 신호 Duty 변경
* 각도 측정을 쉽게 하기 위해서 서보모터 샤프트에 다음과 같이 각도기를 인쇄하여 붙이면 각도 측정을 쉽게 할 수 있을 것이다.

![Protractor](.\images\ServoMotor_Protractor.jpg)



### S/W Setup



![SWDesign](.\images\ServoMotor_SWDesign.png)

* dhPWM_0

    * Frequency : 50 [Hz]

    * Start after initialization : Enable

* main 함수에서 서보모터의 위치를 dhPWM_0에 입력해야 할 Duty로 변환
    $$
    OnTime~=~{0.9msec~-~2.1msec \over 60deg~-~(-60deg)}~\times~ServoAngle~+~1.5msec
    $$

    $$
    ServoDuty~=~{OnTime\over PwmPeriod}~\times~10,000~[단위 : 0.01\%]
    $$


이를 축약된 간단한 식으로 정리하면
$$
ServoDuty~=~750~-~5~\times~ServoAngle
$$



## 실험 방법 

1. 아래와 같이 회로도를 구성하고 S/W를 제작한다.

<img src=".\images\ServoMotor_Circuit.jpg" width="50%">

2. uC-probe로 Servo Angle을 변경하며 서보모터의 성능을 관찰한다.

<img src=".\images\ServoMotor_Test.png">



# 실험 결과

| Reference Position<br />[degree] | OnTime<br />예상치[us] | OnTime<br />측정치[us] | Real Position<br />측정치[degree] |
| -------------------------------- | ---------------------- | ---------------------- | --------------------------------- |
| -60                              | 2100                   |                        |                                   |
| -45                              | 1950                   |                        |                                   |
| -30                              | 1800                   |                        |                                   |
| -15                              | 1650                   |                        |                                   |
| 0                                | 1500                   |                        |                                   |
| 15                               | 1350                   |                        |                                   |
| 30                               | 1200                   |                        |                                   |
| 45                               | 1050                   |                        |                                   |
| 60                               | 900                    |                        |                                   |

