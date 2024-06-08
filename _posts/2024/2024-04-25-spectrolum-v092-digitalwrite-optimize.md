---
layout: post
title: Digital write
categories: spectrolum
version: v0.92
excerpt: "Synopsis of low cost optical spectral sensors available for the xspectrolum spectrometer"
tags:
  - spectrometer
  - xspectrolum
  - sensors
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2024-03-03'
modified: '2024-03-03'
comments: true
share: true
---

## Introduction

the Arduino command Digital write is comparatively slow and cause variations in the spectral scans by e.g. the Hamamatsu sensor. Nay read or write command are also affected by _interrupts_ - code that has precedence over the sequential code execution.

## Handling interrupts

To prevent any interrupts during the scanning and reading data for any spectral sensor, add the command
```
noInterrupts();

// critical, time-sensitive sensor operations here

interrupts();
```

## Optimizing digitalWrite

the Arduino command _digitalWrite_ performs a range of tasks before actually changing the state of an I/O pin:

1. Check if the pin exist, and if not, return.
2. Check if there is a PWM running for this pin. If yes, it will stop the PWM.
3. Find the bit mask for the pin.
4. Find the port associated to the pin number.
5. Check the current pin’s state, and change the state accordingly.

This causes the process of switching state for an I/O pin to take several micro-seconds. A code for testing the speed of _ditialWrite_ is published by [The Robotics Back-End](https://roboticsbackend.com/arduino-fast-digitalwrite/).

The ideal solution to speed up the switching of states is to find the microprocessor machine code for that and tweak your script to use a single call to the machine for switching.

Alternatively the Arduino code can be changed and other libraries used for swithing. Again see the article by [The Robotics Back-End](https://roboticsbackend.com/arduino-fast-digitalwrite/). For AVR boards you can use the library [digitalwritefast](https://www.arduino.cc/reference/en/libraries/digitalwritefast/).

https://forum.seeedstudio.com/t/fast-digital-write-on-xiao-nrf52840/265945
