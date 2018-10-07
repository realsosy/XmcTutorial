# Welcome to XMC World

Author: Wootaik Lee (wootaik@changwon.ac.kr)  

# XMC tutorial

## Objectives & Scopes

* Objectives

  * 마이크로컨트롤러 개발 관련 내용을 전문적으로 배우려는 대학생 및 일반인을 위한 지침서
  * Infineon의 XMC4000-series 를 활용하여 개발하려는 사람을 위한 활용서​

* Scopes

  * 초급: 모듈별 개념 설명 with DAVE
  * 중급: DAVE APP 고급 / XMC lib 활용
  * 고급: XMC의 고급 기능 활용

* 관련 URL

  * [Google Drive](https://goo.gl/vkcuA1)
  * [Read the Docs](http://xmctutorial.readthedocs.io/ko/latest/)
  * [GitHub](https://github.com/realsosy/XmcTutorial)

  ​

## 초급

* 개요
  * 대상: 일반 C 프로그래밍 경험을 갖는 초보 emb 개발자
  * 내용: emb 특징, 기본 interface 개론(DIO, ADC, DAC, PWM), Dave App, uC-Probe
  * 프로젝트: Signal generator & monitor

1. Getting Started XMC: Follow-up example (DIO, PWM, ADC)  
2. Development Environment
3. CPU Subsystem
4. Digital IOs: LEDs and Buttons
5. PWM Basic
6. ADC Basic
7. DAC Basic
8. Interrupt
9. System Timer & Foreground/Background Scheduler
10. uC-Probe
11. [Mini Project] Signal Generator & Monitor

* [Programing 관련 필요 지식]
  * Pointer
  * Structure
  * Function

## 중급

* 개요
  * 대상: emb 경험자
  * 내용: 중급 interface(Timer CCU4/8, USIC or USB), XMC lib
  * 프로젝트: raidar

1. Counter, Timer
2. CCU8 Slice Config
3. Real-time Clock
4. Watchdog
5. I2C & SPI
6. UART
7. USB(USBD_VCOM)
8. [Example] Radar

* [Programing 관련 필요 지식]
  * 모듈화 & Library
  * State-machine

## 고급(준비중)

* 개요
  * 대상: XMC 성능을 최대한 활용하고자 하는 개발자
  * 내용: 고급 interface(MultiCAN, SDMMC, ETH), FreeRTOS, CMSIS, XMC Toolbox
  * 제외 interface 모듈(HRPWM, POSIF, DSD, EBU, LEDTS)

1. DAC LUT
2. DMA
3. ERU
4. Project Template
5. FreeRTOS
6. CMSIS_DSP
7. Single PWM with dead time output monitoring
8. ADC Advanced
9. Webserver I: Basic Settings (optional)
10. Webserver II: Sending data from the MCU (optional)
11. Library for Servo motors(optional)

* [Programing 관련 필요 지식]
  * Real-Time OS

## Programming 배경 지식

* Functions & Program Design
* Module Design & Multiple files
* System Timer & Scheduler
* Statemachine

## Circuit 배경 지식

* Digital Signal Interfacing 
* Analog Signal Interfacing

## Examples & Mini projects

* Servo with PWM
* DC Motor with PWM
* Sensing Light Intensity with DI or ADC
* Ultra-sonic Sensor
* ADXL Sensor with IIC and SPI

**[Mini Projects]**

* Signal Generator & Monitor
* Radar
* LineRacer
* 수평계 with ADXL345