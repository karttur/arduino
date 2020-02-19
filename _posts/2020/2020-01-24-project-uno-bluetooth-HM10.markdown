---
layout: post
title: Bluetooth BLE sketch and wiring Arduino UNO
categories: projects
excerpt: "Wire and sketch HM-10 Bluetooth module for  Arduino UNO"
tags:
  - bluetooth
  - wire
  - sketch
  - HM10
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-15 11:27'
modified: '2020-01-15 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

Setting up a connection between your computer or phone (master) and Arduino project (slave) using Bluetooth BLE HM10.

### Online manuals

Martyn Currey's blog post on [HM-10 Bluetooth 4 BLE Modules](http://www.martyncurrey.com/hm-10-bluetooth-4ble-modules/).

### Wiring

<figure>
<img src="../../images/fritzing-uno-HC05_01.png">
<figcaption> Wiring a HC-05/HC-06 Classic Bluettoh module to an Arduino UNO board using a voltage divider for the HC-05/HC-06 module RX port. The voltage divider use 560 Ohm and 1 kOhm resistors. </figcaption>
</figure>
