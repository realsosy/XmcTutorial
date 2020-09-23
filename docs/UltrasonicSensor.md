---
title : UltrasonicSensor
author : 이우택 (wootaik@gmail.com)
date : Sep 13 2018
---

# Ultrasonic Sensor

## 개요

Timer/count기능을 사용하여 Ultrasonic Sensor를 동작시킨다.

* 초음파센서의 물체와의 거리 측정 성능
* 초음파센서 측정각도

## References
* Ultrasonic.zip




# Ultrasonic 기초 지식

## 초음파란?

* 사람이 들을 수 있는 가청주파수 영역(20~20kHz)보다 높은 음파를 초음파라고 한다.
* 음파의 속도는 약 340m/s이고 액체와 고체의 경게면에서 반사, 굴절, 회절의 성질을 가진다.



## 초음파센서의 원리

![image alt text](.\images\UltrasonicSensorPrinciple.png)

* 음파를 쏘고 음파가 물체에 부딪혀 되돌아 올 때까지의 시간을 측정하여 거리 측정

$$
L = {1\over2} \times t \times v
$$

$$
L: Distance[m]\\
t:time[s]\\
v:the~speed~of~soundwave(340m/s)
$$



## HC-SR04 신호 모듈레이션 방법

![image alt text](.\images\UltrasonicSensorModule.png)

* 다음의 순서로 동작

    * Trig 핀에 10us이상의 펄스 신호를 입력

    * 주파수 40kHz의 초음파를 발사한다. 발사된 초음파는 물체의 표면에 부딪히고 반사된다. 반사된 일부 초음파는 초음파센서로 다시 돌아온다.

    * Echo 핀을 통해 물체와의 거리에 비례한 펄스폭을 가진 펄스신호 출력

* Echo핀을 통해 출력되는 펄스신호의 펄스폭으로 거리계산

    * 펄스폭은 초음파를 쏘고 물체에 부딪혀 되돌아올 때까지의 시간
    * 따라서, 초음파 원리를 바탕으로 식을 유도하면 다음과 같다.

    $$
    Distance~=~{1\over2}\times~340m/s~\times~echo_-pulse_-width[us]
    $$

    * 위 식을 정리하고, 단위를 정리하면 다음 식과 같다.

$$
Distance[cm]~=~echo_-pulse_-width[us]~\div~58
$$

* 측정 사이클은 60ms 이상




# 실험환경

## H/W Setup

![image alt text](.\images\UltrasonicSensorFigCircuit.png)



![Circuit](.\images\UltrasonicSensorCircuit.png)



* 외부의 5V 전원을 사용하여 초음파 센서 전원 공급
* Tirg: 5V TTL 입력 신호 이므로 XMC 출력과 직접 연결
* Echo: 5V 신호 이므로 전압 분배 회로로 3.3V 로 변환하여 XMC 입력으로 연결
* 대상물체의 크기 : 15cm x 15cm
* Oscilloscope로 Echo신호 펄스폭 모니터링

    * PC를 통해 MCU에서 측정한 Echo신호 펄스폭과 비교
* PC를 사용하여 Echo신호 펄스폭 및 거리 모니터링


## S/W Setup

![image alt text](.\images\UltrasonicSensorSWSetup.png)

### dhPWM_0

* 초음파센서 트리거 신호 생성

* Frequency : 16 [Hz]

    * 초음파센서 측정사이클 : 62.5 [ms]

* Duty cycle : 0.02 [%]

    * Trig 신호 펄스 길이 : 12.5 [us]

### dhCAPTURE

* 초음파센서 Echo신호 펄스폭 측정

* Desired Timer Resolution : 174

    * 초음파센서 거리 Resolution : 0.3cm

* Capture edge : Rise-to-Fall

* Overwrite Capture Value : Enable

### CB_dhSYSTIMER_0_u32SwTimer_60ms

* Echo 펄스폭 길이를 읽고 초음파센서가 측정한 물체와의 거리 계산

* 변환식 Basic Theory 참조




# 실험방법

## 거리측정실험

1. 물체의 위치(L)를 10, 20, 30, 40, 50, 60cm에 위치시킨다

2. Oscilloscope 로 echo_pulse_width 를 측정한다.

3. uC/Probe 에서 echo_pulse_width 계산값과 거리 계산값을 측정한다.

## 측정각도 실험

1. 대상물체를 초음파센서 정면 30cm, 평행위치(D) 에 위치시킨다.

2. uC/Probe 에서 echo_pulse_width 계산값과 거리 계산값을 측정한다.




# 실험 결과

## 거리측정실험

![Distance](.\images\UltrasonicSensorDistance.png)

Echo의 Pulse width와 그에 따른 거리를 uC/Probe로 관찰 할 수 있다.

* 목표물을 중심에 놓고, 즉 D=0cm, 다음의 실험 조건에서 거리 측정 실험을 실시한다.

| L[cm]     | 10   | 20   | 30   | 40   | 50   | 60   |
| --------- | ---- | ---- | ---- | ---- | ---- | ---- |
| Cap. Time |      |      |      |      |      |      |
| Distance  |      |      |      |      |      |      |





## 측정각도실험

![Angle](.\images\UltrasonicSensorAngle.png)

대상 물체를 이동하여 D의 거리에 변화를 주면 그림과 같이 모니터링 가능하다.

* L = 30cm로 고정하고 다음의 실험 조건에서 거리 측정 실험을 실시한다.

| D[cm]    | -45 | -30 | -15 | 0 | +15 | +30 |+45   |
| --------- | ---- | ---- | ---- | ---- | ---- | ---- |---- |
| Cap. Time |      |      |      |      |      |      ||
| Distance  |      |      |      |      |      |      ||