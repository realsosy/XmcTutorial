# Radar

## 개요

중급과정에서 배운 Capture/Timer 모듈을 이용한 Radar를 설계, 구현, 시험해 본다.

* Servo Motor는 등속운동을 하지않고, 위치제어를 하고 약간의 진동이 발생한다.

* 초음파 센서는 음파의 반사 시간이 필요하다. 

위 사항들을 고려했을때 Timing diagram을 그려 각 동작별 순서를 맞출 필요가 있다.



### 선행사항

- Lecture PwmBasic
- Lecture Timer
- Lecture Capture
- ServoMotor
- UltrasonicSensor

### 참고자료

- SG-90.pdf
- HC-SR04.pdf

### 용어 및 약어 정의

| 약어 | 설명              |
| ---- | ----------------- |
| US   | Ultrasonic Sensor |
| IC   | Input Capture     |
| OC   | Output Compare    |



## Radar 설계

### System Design

![System Diagram](.\images\Radar_SystemDiagram.png)

<center>[Figure1. System Diagram]</center>

#### XMC4500과 Radar의 Interface

- US_Trig
    - 초음파 센서 트리거 신호
    - 전압 범위 : 0 ~ 3.3 [V]
- US_Echo
    - 초음파 센서의 출력신호. 초음파를 보내 반사되어 돌아오는 시간 정보를 가진다.
    - 전압 범위 : 0 ~ 5 [V]
    - XMC4500과 Interface하기 위해 **전압 분배회로**를 사용해서 전압 범위를 0 ~ 3.3 V로 변환한다.
- Servo
    - 서보모터 위치지령
    - 50Hz의 PWM신호 사용
    - 전압 범위 : 0 ~ 3.3 [V]



#### Component Description

- 초음파 센서
    - 전방 물체까지 거리 측정
    - HC-SR04 사용
    - 초음파 센서에서 출력되는  Echo 신호의 펄스폭을 사용해 물체까지 거리 계산

$$
Distance[cm]~=~{{echo_-pulse_-width~[us]}\over{58}}
$$

<center>[Equation1. Calculate distance using Echo signal]</center>

- 서보 모터
    - 초음파 센서의 측정 방향 조정
    - SG-90 사용
    - PWM신호의 on time으로 위치 지령
    - 0.9ms(-60º) ~ 2.1ms(60º)



#### Servo와 US를 연동한 전방위 감지 방법

- 진행방향 기준으로 -60º ~ +60º의 장애물을 감지하기 위해서 서보를 움직여 초음파센서로 거리를 측정한다.
- 초음파센서의 탐지 가능 각도가 약 -20º ~ +20º이므로, -10º ~ +10º 범위의 장애물 감지는 신뢰성이 높다.
- 측정 정보의 정확성을 위해 20º의 분해능으로 서보를 동작시켜 측정한다.

![Radar scanning theory](.\images\Radar_Index_Degree.png)

<center>[Figure2. Radar scanning theory]</center>

- 각 구간에서 측정한 장애물의 거리는 배열 변수에 저장한다.



### Hardware Design

![Hardware Design](.\images\Radar_HWDesign2.jpg)
![Hardware Connection](.\images\Radar_HWConnection.png)

<center>[Figure2. Hardware Design]</center>

![Voltage division circuit](.\images\Radar_VoltDivision.png)

<center>[Figure3. Voltage division circuit]</center>

- US의 Echo신호의 출력은 5V이므로 전압분배를 통해 3.3으로 낮춘다.



### Software Design

#### Theory : Servo와 초음파 센서를 활용한 Timing 설계

![Timing diagram](.\images\Radar_TimingRaw.png)

<center>[Figure4. Timing diagram using Servo & US]</center>

서보를 회전시키면서 초음파 센서로 장애물의 위치를 측정하기 위해서 고려해야할 것이 있다. 첫 번째, 서보가 움직이는 데 거리는 시간. 두 번째, 초음파 신호를 측정하는 데 걸리는 시간을 고려해야 한다.

- XMC에서 위치 지령치를 PWM을 사용해 출력한다.
- 서보가 움직이고 해당 위치에 안정화 될 때까지 기다린다. (약 140 msec)
- 서보가 안정화 되면 XMC에서 US로 Trig신호를 PWM으로 출력한다.
- US가 출력하는 Echo의 rising/falling edge를 측정하고, Time Interval(On-Time)을 측정한다.
- Time-Interval과 'Equation1'을 이용해 거리를 계산한다.
- 다음 위치로 이동하고 위 동작을 반복한다.



#### Method1 : PWM을 사용한 설계 (Type Polling)

![using PWM module](.\images\Radar_TimingPolling.png)

<center>[Figure5. Timing diagram using PWM module]</center>

- 140ms의 대기시간, Echo 신호를 측정하기위한 Polling 부분에서 CPU time이 상당히 낭비된다.



#### Method2 : IC & OC를 사용한 설계(Type Interrupt)

![using IC & OC](.\images\Radar_TimingICOC.png)

<center>[Figure6. Timing diagram using IC & OC]</center>

- Servo Ctrl블럭에서 Servo 지령치를 출력한 후, Output Compare를 사용해 140ms 이후 Interrupt로 Trig 신호를 출력해서 초음파 센서가 활성화되게 한다.
- Input Capture를 사용해 Echo 신호의 rising/falling edge의 Timing을 자동으로 측정하고, 그 Time Interval을 계산하도록 한다.
- System Timer를 이용해 위 동작을 170ms의 period로 반복하게 설정해서 CPU의 간섭을 최소화한 상태로 Radar를 활성화할 수 있다.

## Radar 구현

### Hardware

![Radar hardware](.\images\Radar_HW.jpg)

<center>[Figure7. Radar hardware]</center>

- 전압분배회로는 납땜, PCB기판을 이용해도 된다.

### 프로그램 구조

![Software Architecture](.\images\Radar_DaveApp.png)

<center>[Figure8. Software Architecture]</center>

#### DAVE APP Settings

- dhPWM_Servo
    - 서보모터 위치 지령 신호 생성
    - Frequency : 50 [Hz]
- dhPWM_US
    - 초음파센서 Trig 신호 생성
    - Frequency : 50k [Hz]
    - Duty : 50 [%]
    - Enable single shot mode : Enable
- dhIC_US
    - Input Capture, US의 Echo 신호의 펄스 폭(On-Time, Time Interval) 측정
    - Desired Timer Resolution [nsec] : 600
    - Start after initialization : Enable
    - Capture edge : Rise-to-Fall
    - Overwrite Capture Value : Enable
- dhOC_CA
    - Output Compare, 서보모터 동작 후, 안정화를 위한 대기시간
    - Time interval [usec] : 140000
    - ISR_dhOC_CA : 초음파 센서의 트리거 신호(dhPWM_US)를 활성화
- fltObstacleDistanceArr[5]
    - 스캔 결과 데이터 저장
    - 단위 : cm
    - 배열의 index는 0에서 4까지 차례대로 -40º, -20º, 0º, 20º, 40º 위치에서 장애물까지 거리
- bScanComplete
    - 스캔 완료를 알리는 flag
    - 1 : 스캔 완료 / 0 : 스캔 중

#### Function Design

##### Measure a distance to Obstacle

- IC로 측정된 펄스 폭 정보를 us단위로 변환
  - GetCapturedTime 메소드로 읽은 값은 Input Capture Tick (nsec)이다. 따라서 Tick 주기를 고려해서 시간변환을 해줘야 한다.

$$
captured_-time ~=~captured--tick~\times~IC_-TICK_-PERIOD_-NS~\div~1000~[usec]
$$
<center>[Equation2. Calculate Echo signal's On-Time]</center>

- 장애물까지 거리 계산 후 f32RawDistanceArr에 저장
  - 58로 나누는 이유 : 펄스폭(captured_time)을 거리(cm)로 변환

$$
fltRawDistanceArr~=~captured_-time~\div~58
$$

<center>[Equation3. Calculate a distance(raw data)]</center>

- 허상, 혹은 노이즈 정보 제거하여 fltObstacleDistanceArr에 저장
  - 측정 관심 영역(Region-Of-Interest:ROI)영역 밖의 정보는 제거 한다.
    - 3cm ~ 150cm (DIST_THRESHOLD)
    - 관심영역을 벗어나는 경우는 유효하지 않은 센서 정보로 해석하여, 최대거리 300cm로 처리한다.
  - fltRawDistance == 0 → fltObstacleDistanceArr = 300 cm : 장애물 없음.
  - 3 < fltRawDistance < 150 → fltObstacleDistanceArr = fltRawDistanceArr : 관심영역
  - fltRawDistance >= 150 → fltObstacleDistanceArr = 300 cm : 장애물이 있는 경우도 있으나 확실치 않아 허상(고스트) 인 가능성이 높음

##### 서보모터 이동

- 서보모터 지령 위치(fltServoAngle)를 PWM Duty로 변환
  $$
  servo_-duty~=~CENTER_-DUTY~-~5~\times~fltServoAngle
  $$

  <center>[Equation4. Translate a servo angle to servo duty]</center>

  - servo_duty : 단위 0.01%
  - CENTER_DUTY : 0º의 duty, 750

* 20º 간격으로 총 5 번 초음파를 동작시키고 그 값을 fltObstacleDistanceArr에 저장한다. 그러므로 Array의 index를 사용해서 해당 위치를 판단하고 관리한다.
* 서보 동작의 경계점, 즉 'ServoAngle이 -40º 또는 +40º 지점, CaArrIdx가 0 또는 4인 지점'에서 서보모터  동작 방향을 반대로 바꿔야 하므로 아래 그림과 같이 동작시킨다.

![Radar state machine](.\images\Radar_StateMachine.png)

<center>[Figure9. Radar state machine]</center>

## Radar 시험

### Test Environment

![Test Environment](.\images\Radar_TestEnv.jpg)

<center>[Figure11. Test Environment]</center>

- Radar와 장애물을 수평한 장소에 두고 장애물을 옮겨가며 위치, 거리 정보가 올바르게 나타나는지 확인한다.

### uC-probe Setting

![uC-Probe distplay](.\images\Radar_Probe.png)

<center>[Figure10. uC-Probe distplay]</center>

- 1 : Advanced → Tree View Control
    - i16CaArrIdx : 거리값이 저장되는 배열의 index
    - i32CadelayMs : Servo가 회전하고 안정화되는데 걸리는 시간
    - CaLoopIn10Ms : 함수 Sense_CollisionAvoidance의 동작 주기
- 2 : Charts →Line Chart
    - fltObstacleDistanceArr : 장애물까지 거리 값이 저장된 배열
    - Miscellaneous → Text Tool을 이용해 그래프의 가로축에 위치 표현

### Test case

![No obstacle](.\images\Radar_TestCase1.png)
![](.\images\Radar_TestCase1_1.jpg)

<center>[Figure11. No obstacle]</center>



![at 40 degree](.\images\Radar_TestCase2.png)
![](.\images\Radar_TestCase2_1.jpg)

<center>[Figure12. Detect obstacle at 40 degree]</center>



![at center](.\images\Radar_TestCase3.png)
![](.\images\Radar_TestCase3_1.jpg)

<center>[Figure13. Detect obstacle at center]</center>

