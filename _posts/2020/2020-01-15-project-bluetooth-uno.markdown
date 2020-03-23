---
layout: post
title: Bluetooth sketch and wiring Arduino UNO
categories: project
excerpt: "Wire and sketch Bluetooth module for Arduino UNO"
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
module: module-bluetooth
project: project-bluetooth-nano
---

### Introduction

Setting up a connection between your computer or phone (master) and Arduino project (slave) using Bluetooth is fairly easy and straight forward. The complication is the power supply and voltage for the serial port connection.

### Online manuals

There are many manuals and tutorials for how to wire and sketch your Arduino Bluetooth connection. To get an updated manual you should probably consult a search engine. The [How to connect an Arduino Uno to an Android phone via Bluetooth](https://42bots.com/tutorials/how-to-connect-arduino-uno-to-android-phone-via-bluetooth/) (by _42 Bots Hobby Robotics and Electronics Blog_), contains a good summary on the power and voltage issue. Also _How To Meachatronics_ have an OK [Arduino and HC-05 Bluetooth Module Tutorial](https://howtomechatronics.com/tutorials/arduino/arduino-and-hc-05-bluetooth-module-tutorial/). For a specific post on Bluetooth Low Energy (BLE) see Martyn Currey's blog post on [HM-10 Bluetooth 4 BLE Modules](http://www.martyncurrey.com/hm-10-bluetooth-4ble-modules/).

### Voltage divider

While most Bluetooth modules require 5 v as DCC input, the communication port (RXD) only requires 3.3 v. In many online manuals this is ignored and the RXD port s fed 5 v. The wiring below here reduces the RXD input voltage to 3.3 v using a [voltage divider](https://circuitdigest.com/calculators/voltage-divider-calculator). A voltage divider requires one resistor reducing the voltage over the power supply, and a second resistor connecting the power supply to ground. To reduce from 5 to 3.3 v the resistance relation between these need to be exactly 1:2.  In my examle below I have chosen resistor of approxiamtely 500 Ohm : 1000 Ohm. To get the correct resistor you might need a [Resistor Color Code Calculator](https://www.digikey.com/en/resources/conversion-calculators/conversion-calculator-resistor-color-code-4-band).

### Wiring

The wiring is similar for Bluetooth Classical and BLE with both requiring a voltage divider. The first example only shows the Bluetooth module. The second example includes a LED, and is the wiring used in the post on []().


<figure>
<img src="../../images/uno-bluetooth_HCXX_only_bb.png">
<figcaption> Wiring a HC-05/HC-06 Classic Bluettoh module to an Arduino UNO board using a voltage divider for the HC-05/HC-06 module RX port. The voltage divider use 560 Ohm and 1 kOhm resistors. </figcaption>
</figure>

<figure>
<img src="../../images/fritzing_HM10-UNO_bb.png">
<figcaption> Wiring a HM10 Bluetooth BLE module to an Arduino UNO board using a voltage divider for the HM10 module RX port. The voltage divider use 560 Ohm and 1 kOhm resistors. </figcaption>
</figure>
