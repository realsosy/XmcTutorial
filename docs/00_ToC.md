---
title: 목차(Toc)  
author: 이우택 (wootaik@gamil.com)  
date: Sep 01 2016  
---


# XMC tutorial

## Objectives & Scopes

* Objectives
    - 마이크로컨트롤러 개발 관련 내용을 전문적으로 배우려는 대학생 및 일반인을 위한 지침서
    - Infineon의 XMC4000-series 를 활용하여 개발하려는 사람을 위한 활용서​

* Scopes
    - 초급: 모듈별 개념 설명 with DAVE
    - 중급: DAVE APP 고급 / XMC lib 활용 중심
    - 고급: XMC의 고급 기능 활용

## 초급
* 개요
    - 대상: 일반 C 프로그래밍 경험을 갖는 초보 emb 개발자
    - 내용: emb 특징, 기본 interface 개론(DIO, ADC, DAC, PWM), Dave App, uC-Probe
    - 프로젝트: Signal generator & monitor

1. Getting Started XMC
    - Follow-up example (DIO, PWM, ADC)  
1. Development Environment
    - How to Set Up the Board & Dev Environment
1. CPU Subsystem
    - CORTEX-M4 특징
1. Digital IOs: LEDs and Buttons
    - 2 Leds & 2 Buttons  
1. PWM Basic
1. ADC Basic
1. DAC Basic
1. Interrupt
1. System Timer & Foreground/Background Scheduler
1. uC-Probe
1. Signal Generator & Monitor

*   [Programing 관련 필요 지식]
    *   Pointer
    *   Structure
    *   Function

## 중급
* [Note]
    - 대상: emb 경험자
    - 내용: 중급 interface(기본 interface 다시, GPDMA, CCU4/8, USIC or USB, FCE), XMC lib
    - 프로젝트: raidar & dc motor speed control

1. DAC LUT
1. Counter, Timer
1. CCU8 Slice Config
1. Real-time Clock
1. Watchdog
1. DMA
1. ERU
1. UART
1. USB(USBD_VCOM)
1. I2C & SPI

*   [Programing 관련 필요 지식]
    *   모듈화
    *   Library

## 고급
*   개요
    *   대상: XMC 성능을 최대한 활용하고자 하는 개발자
    *   내용: 고급 interface(MultiCAN, SDMMC, ETH), FreeRTOS, CMSIS, XMC Toolbox
    *   제외 interface 모듈(HRPWM, POSIF, DSD, EBU, LEDTS)
    *   프로젝트: COMM emulator/analyzer

1. Project Template
1. FreeRTOS
1. CMSIS_DSP
1. Single PWM with dead time output monitoring
1. ADC Advanced
1. Webserver I: Basic Settings (optional)
1. Webserver II: Sending data from the MCU (optional)
1. Basic control using ADC,PWM and NVIC
1. Library for Servo motors(optional)

*   [Programing 관련 필요 지식]
    *   Real-Time OS

## Examples
* Servo with PWM
* DC Motor with PWM
* Sensing Light Intensity with ADC
* Ultra-sonic Sensor with Capture and Compare
* ADXL Sensor with IIC and SPI

