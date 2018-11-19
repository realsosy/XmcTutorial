# Signal Generator & Monitor Test Report

## Objective

* 이 문서는 Signal Generator & Monitor 기능 검사를 하기 위한 테스트 환경, 테스트 케이스를 설명한다.
* 기능 시험은 다음의 절차에 따라 진행된다.
  * H/W 시험
  * S/W with PC 시험
  * Integration 시험

## H/W 시험

### Test Overview

![Hw](./images/Hw.svg)

* 이 시험은 Signal Interface Shield의 디지털/아날로그 입출력 회로들이 올바르게 동작하는지 시험한다. 만들어진 회로에 입력에 대한 예상된 출력이 나오는지 관찰한다.

### Test Setup

* Power Selector를 사용하여 외부회로 전압 설정
  * 3.3V Mode Test 시, 1, 2번 연결
  * 5V Mode Test 시, 0, 1번 연결
* 5V Mode 테스트 시, 파워서플라이를 CON1_0(5V), CON1\_6(GND) 연결
* 테스트 케이스에 따라 Function Generator를 Stimulus Point와 연결
* 테스트 케이스에 따라 Oscilloscope 를 Test Point와 연결

### Test Result

#### 3.3V Mode Test

| Interface      | Stimulus Point | Value | Test Point | Expected Result | Test Result |
| -------------- | -------------- | ----- | ---------- | --------------- | ----------- |
| Digital Input  | CON1_1         | 0V    | X2 17      | 0V              |             |
|                |                | 3.3V  |            | 3.3V            |             |
|                | CON1_7         | 0V    | X2 16      | 0V              |             |
|                |                | 3.3V  |            | 3.3V            |             |
| Digital Output | X2 19          | 0V    | CON1_2     | 0V              |             |
|                |                | 3.3V  |            | 3.3V            |             |
|                | X2 18          | 0V    | CON1_8     | 0V              |             |
|                |                | 3.3V  |            | 3.3V            |             |
| Analog Output  | X1 10          | 0.3V  | CON1_5     | 0.6V            |             |
|                |                | 0.8V  |            | 1.6V            |             |
|                |                | 1.65V |            | 3.3V            |             |
|                | X1 12          | 0.3V  | CON1_11    | 0.6V            |             |
|                |                | 0.8V  |            | 1.6V            |             |
|                |                | 1.65V |            | 3.3V            |             |
#### 5V Mode Test

| Interface      | Stimulus Point | Value      | Test Point | Expected Result | Test Result |
| -------------- | -------------- | ---------- | ---------- | --------------- | ----------- |
| Digital Input  | CON1_1         | 0V         | X2 17      | 0V              |             |
|                |                | 5V         |            | 5V              |             |
|                | CON1_7         | 0V         | X2 16      | 0V              |             |
|                |                | 5V         |            | 5V              |             |
| Digital Output | X2 19          | 0V         | CON1_2     | 0V              |             |
|                |                | 5V         |            | 5V              |             |
|                | X2 18          | 0V         | CON1_8     | 0V              |             |
|                |                | 5V         |            | 5V              |             |
| Analog Input   | CON1_4         | 0V/0Hz     | X1 14      | 0V/0Hz          |             |
|                |                | 2.5V/0Hz   |            | 1.63V/0Hz       |             |
|                |                | 5V/0kHz    |            | 3.26V/0Hz       |             |
|                |                | 2.5V/5kHz  |            | 1.63V/5kHz      |             |
|                |                | 2.5V/10kHz |            | 1.19V/10kHz     |             |
|                |                | 2.5V/15kHz |            | 0.94V/15kHz     |             |
|                | CON1_10        | 0V/0Hz     | X1 16      | 0V/0Hz          |             |
|                |                | 2.5V/0Hz   |            | 1.63V/0Hz       |             |
|                |                | 5V/0kHz    |            | 3.26V/0Hz       |             |
|                |                | 2.5V/5kHz  |            | 1.63V/5kHz      |             |
|                |                | 2.5V/10kHz |            | 1.19V/10kHz     |             |
|                |                | 2.5V/15kHz |            | 0.94V/15kHz     |             |
| Analog Output  | X1 10          | 0.3V       | CON1_5     | 0.6V            |             |
|                |                | 1.25V      |            | 2.5V            |             |
|                |                | 2.5V       |            | 5V              |             |
|                | X1 12          | 0.3V       | CON1_11    | 0.6V            |             |
|                |                | 1.25V      |            | 2.5V            |             |
|                |                | 2.5V       |            | 5V              |             |
## S/W with PC UI 시험

### Test Description

![Sw_Pc](./images/Sw_Pc.svg)

* 이 시험은 Signal Generator & Monitor의 S/W와 UI를 시험하기 위한 것이다.
* XMC4500 보드에서 디지털 입력과 출력을 서로 연결하고, 아날로그 입력과 출력을 서로 연결한다. 그리고 PC UI 환경에서 디지털/아날로그 출력에 따라 디지털/아날로그 입력의 변화를 관찰한다.
* 아날로그 입출력 테스트 시, 결과 값은 아날로그 입출력 회로 이득이 보상된 결과가 출력된다.

### Test Setup

* 시험을 위해 점프선을 사용하여 위의 그림과 같이 연결한다.
  * X2 17 - X2 19
  * X2 16 - X2 18
  * X1 10 - X1 14
  * X1 12 - X1 16

### Test Result

| Interface    | Stimulus Point  | Value | Test Point     | Expected Result | Test Result |
| ------------ | --------------- | ----- | -------------- | --------------- | ----------- |
| Digital In   | Digital Out Ch0 | OFF   | Digital In Ch0 | OFF             |             |
| /Digital Out |                 | ON    |                | ON              |             |
|              | Digital Out Ch1 | OFF   | Digital In Ch1 | OFF             |             |
|              |                 | ON    |                | ON              |             |
| Analog In    | Analog Out Ch0  | 0.6V  | Analog In Ch0  | 0.46V           |             |
| /Analog Out  |                 | 1.65V |                | 1.23V           |             |
|              |                 | 3.3V  |                | 2.53V           |             |
|              | Analog Out Ch1  | 0V    | Analog In Ch1  | 0.46V           |             |
|              |                 | 1.65V |                | 1.23V           |             |
|              |                 | 3.3V  |                | 2.53V           |             |



## Integration Test

### Test Description

![Integration](./images/Integration.svg)

* XMC4500, Signal Interface Shield, S/W, UI를 통합한 시스템이 올바르게 동작하는지 시험한다.
* 디지털 입력과 출력을 서로 연결하고, 아날로그 입력과 출력을 서로 연결한다. 그리고 PC UI 환경에서 디지털/아날로그 출력에 따라 디지털/아날로그 입력의 변화를 관찰한다.

### Test Setup

* Power Selector를 사용하여 운용 전압을 설정
  * 3.3V Mode Test 시, 1, 2번 연결
  * 5V Mode Test 시, 0, 1번 연결
* 위의 그림과 같이 점퍼선을 사용하여 연결한다.
  * CON1_1 - CON1\_2
  * CON1_7 - CON1\_8
  * CON1_4 - CON1\_5
  * CON1_10 - CON1\_11

### Test Result

#### 3.3V Mode Test

| Interface    | Stimulus Point  | Value | Test Point     | Expected Result | Test Result |
| ------------ | --------------- | ----- | -------------- | --------------- | ----------- |
| Digital In   | Digital Out Ch0 | OFF   | Digital In Ch0 | OFF             |             |
| /Digital Out |                 | ON    |                | ON              |             |
|              | Digital Out Ch1 | OFF   | Digital In Ch1 | OFF             |             |
|              |                 | ON    |                | ON              |             |
| Analog In    | Analog Out Ch0  | 0V    | Analog In Ch0  | 0V              |             |
| /Analog Out  |                 | 1.25V |                | 1.25V           |             |
|              |                 | 2.5V  |                | 2.5V            |             |
|              | Analog Out Ch1  | 0V    | Analog In Ch1  | 0V              |             |
|              |                 | 1.25V |                | 1.25V           |             |
|              |                 | 2.5V  |                | 2.5V            |             |



#### 5V Mode Test
| Interface    | Stimulus Point  | Value | Test Point     | Expected Result | Test Result |
| ------------ | --------------- | ----- | -------------- | --------------- | ----------- |
| Digital In   | Digital Out Ch0 | OFF   | Digital In Ch0 | OFF             |             |
| /Digital Out |                 | ON    |                | ON              |             |
|              | Digital Out Ch1 | OFF   | Digital In Ch1 | OFF             |             |
|              |                 | ON    |                | ON              |             |
| Analog In    | Analog Out Ch0  | 0V    | Analog In Ch0  | 0V              |             |
| /Analog Out  |                 | 2.5V  |                | 2.5V            |             |
|              |                 | 5V    |                | 5V              |             |
|              | Analog Out Ch1  | 0V    | Analog In Ch1  | 0V              |             |
|              |                 | 2.5V  |                | 2.5V            |             |
|              |                 | 5V    |                | 5V              |             |
