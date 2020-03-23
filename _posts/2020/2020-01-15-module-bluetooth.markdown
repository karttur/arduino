---
layout: post
title: Bluetooth modules for Arduino
categories: module
excerpt: "Different generations and makes of bluetooth modules for Arduino"
tags:
  - bluetooth
  - BLE
  - HC05
  - HC06
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-15 11:27'
modified: '2020-01-15 T18:17:25.000Z'
comments: true
share: true
project: project-bluetooth-nano
projectuno: project-bluetooth-uno
---

### Introduction

[Bluetooth](https://www.bluetooth.com) uses UHF radio waves for data transfer over short distances. It is one of the alternatives for communicating with your Arduino project. This post lists some common Bluetooth boards to use with your Arduino project.

### Bluetooth generations

The two main generations of Bluetooth are _Classic Bluetooth_ and [_Bluetooth Low Energy_](https://en.wikipedia.org/wiki/Bluetooth_Low_Energy). Both are defined in the Bluetooth Core Specification version 4.0 (Bluetooth Smart). Breakout boards with both versions are available for Arduino.

If your master device (typically computer or mobile phone) does not connect to you Arduino Bluetooth module it might be because you have incompatible generations.

### Classic Bluetooth

The standard Arduino breakout boards for _Classic Bluetooth_ are HC-05 and HC-06. The HC-05 module can either be a master or slave which means that it can initiate connection to another device. The HC-06 module is a slave only and can only accept a connection from another device.

Both HC-05 and HC-06 are produced by different vendors, and sold at almost every shop offering Arduino modules. In Sweden the best price and service might be from [pchbutik.se](https://pchbutik.se).

### Bluetooth Low Energy (BLE)

At time of writing this (January 2020) BLE has not yet taken over from _Classic Bluetooth_, but it is on its way to happen. [pchbutik.se](https://pchbutik.se) also has some alternatives for BLE modules.

As usual it is cheaper to buy directly from China, [Banggood.com](https://www.banggood.com/buy/arduino-bluetooth-module.html) for instance.

### Sketch and wire

The post on [Bluetooth sketch and wiring](../../project/project-bluetooth-uno/) contains instructions for how to wire a Bluetooth module to an Arduino UNO board with links to libraries and codes. How to wire using an Arduino Nano board is outlined in the post [Arduino Nano project - bluetooth](../../project/project-bluetooth-nano/).
