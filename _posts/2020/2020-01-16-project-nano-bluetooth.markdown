---
layout: post
title: Bluetooth classic sketch and wiring Arduino Nano
categories: project
excerpt: "Wire and sketch HC-05 or HC-06 Bluetooth module for Arduino Nao"
tags:
  - bluetooth
  - wire
  - sketch
  - HC05
  - HC06
  - Nano
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-15 11:27'
modified: '2020-01-15 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

Setting up a connection between your computer or phone (master) and Arduino project (slave) using Classic Bluetooth is fairly easy and straight forward. The complication is the power supply and voltage for the serial port connection. The communication port with the Bluetooth device requires 3.3 v. To reduce 5.0 v to 3.3 v you need a [voltage divider]( https://en.wikipedia.org/wiki/Voltage_divider).

### Online manuals

There are many manuals and tutorials for how to wire and sketch your Arduino Bluetooth connection. To get an updated manual you should probably consult a search engine. The [How to connect an Arduino Uno to an Android phone via Bluetooth](https://42bots.com/tutorials/how-to-connect-arduino-uno-to-android-phone-via-bluetooth/) by _42 Bots | Hobby Robotics and Electronics Blog_, contains a good summary on the power and voltage issue. Also _How To Meachatronics_ have an OK [Arduino and HC-05 Bluetooth Module Tutorial](https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-05-bluetooth-module-tutorial/).

### Voltage divider

[Resistor Color Code Calculator](https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-resistor-color-code-4-band)

### Wiring

<figure>
<img src="../../images/fritzing-nano-HC05_01.png">
<figcaption> Fritzing app startup GUI.</figcaption>
</figure>
