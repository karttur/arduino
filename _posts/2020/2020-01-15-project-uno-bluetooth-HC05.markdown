---
layout: post
title: Bluetooth classic sketch and wiring Arduino UNO
categories: project
excerpt: "Wire and sketch HC-05 or HC-06 Bluetooth module for  Arduino UNO"
tags:
  - bluetooth
  - wire
  - sketch
  - HC05
  - HC06
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-15 11:27'
modified: '2020-01-15 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

Setting up a connection between your computer or phone (master) and Arduino project (slave) using Bluetooth is fairly easy and straight forward. The complication is the power supply and voltage for the serial port connection.

### Online manuals

There are many manuals and tutorials for how to wire and sketch your Arduino Bluetooth connection. To get an updated manual you should probably consult a search engine. The [How to connect an Arduino Uno to an Android phone via Bluetooth](https://42bots.com/tutorials/how-to-connect-arduino-uno-to-android-phone-via-bluetooth/) by _42 Bots | Hobby Robotics and Electronics Blog_, contains a good summary on the power and voltage issue. Also _How To Meachatronics_ have an OK [Arduino and HC-05 Bluetooth Module Tutorial](https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-05-bluetooth-module-tutorial/).

### Wiring

<figure>
<img src="../../images/fritzing_HM10-UNO_bb.png">
<figcaption> Wiring a HM10 Bluetooth BLE module to an Arduino UNO board using a voltage divider for the HM10 module RX port. The voltage divider use 560 Ohm and 1 kOhm resistors. </figcaption>
</figure>
