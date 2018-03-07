---
title: 목차(Toc)  
author: 이우택 (wootaik@gamil.com)  
date: Sep 01 2016  
---


# XMC tutorial

## Objectives & Scopes

* Objectives
    - 교재 수준으로 관련 내용 정리 (초급, 중급, 고급)
    - 각 파트별  대표적 예제코드

* Scopes
    - 초급: 모듈별 개념 설명 with DAVE
    - 중급: DAVE APP 고급 / XMC lib 활용 중심
    - 고급: XMC의 고급 기능을 활용한 성능 극대화

## 초급
* [Note]
    - 대상: 일반 C 프로그래밍 경험을 갖는 초보 emb 개발자
    - 내용: emb 특징, 기본 interface 개론(DIO, ADC, DAC, PWM), Dave App, uC-Probe
    - 프로젝트: Signal generator & monitor
    - Capstone 연계 프로젝트: line scanner using DIO & ADC

* 무조건 따라하기 프로젝트: switch, led 정도
* Fundamentals
    - Cortex-M Processor Overview
    - Dave, IDE & App

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
1. Counter
1. Timer
1. Real-time Clock
1. System Timer & Foreground/Background Scheduler
1. uC-Probe
1. Signal Generator & Monitor

## 중급
* [Note]
    - 대상: emb 경험자
    - 내용: 중급 interface(기본 interface 다시, GPDMA, CCU4/8, USIC or USB, FCE), CMSIS, XMC lib,
    - 프로젝트: raidar & dc motor speed control
    - Capstone 연계 프로젝트: 장애물 회피 자동차

1. DAC LUT
1. CCU8 Slice Config
1. Watchdog
1. DMA
1. ERU

1. UART
1. USB(USBD_VCOM)
1. I2C & SPI

## 고급
1. Project Template

1. FreeRTOS
1. CMSIS_DSP
1. Single PWM with dead time output monitoring
1. ADC Advanced

1. Webserver I: Basic Settings (optional)
1. Webserver II: Sending data from the MCU (optional)
1. Basic control using ADC,PWM and NVIC
1. Library for Servo motors(optional)

* [Note]
    - 대상: XMC 성능을 최대한 활용하고자 하는 개발자
    - 내용: 고급 interface(MultiCAN, SDMMC, ETH), FreeRTOS, XMC Toolbox
    - 제외 interface 모듈(HRPWM, POSIF, DSD, EBU, LEDTS)
    - 프로젝트: COMM emulator/analyzer

## Final 프로젝트:
* Virtual Lab (+Logging, Pattern)
* DC motor hils?
