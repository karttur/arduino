---
layout: post
title: AMD six band spectrometer project
categories: project
excerpt: "Wiring up the AMD as726x spectrometer"
tags:
  - arduino
  - spectrometer
  - wiring
  - sketch
  - I2C
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-10-24 11:27'
modified: '2019-10-24 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

This small "project" post covers how to wire an integrated module with the [AMS AS72Sx 6 channel broad band spectrometer](../../module/module-AS726X-spectrometer/) to an Arduino board.

#### The I2C communication bus

The spectrometer sends data for 6 (12 or 18) spectral bands using the [I2C communication bus]().
The spectrometer communicates with the board (Arduino) using the [I2C protocol as described in a separate post](../arduino-I2C/)

#### Preparing the Arduino IDE

Your Arduino board must have the SCL and SDA ports required for the I2C communication bus. If you are using one of [Arduino's standard boards](https://www.arduino.cc/en/main/boards) they should be included with the latest version of <span class='app'>[Arduino IDE](https://www.arduino.cc/en/main/software)</span>.

If instead you are using a board from a partner, you probably need to configure Arduino IDE for that particular board. As an example, you can look at the manuals for how to [configure Arduino for the Adafruit's Metro Express board](https://learn.adafruit.com/experimenters-guide-for-metro/configure-arduino-for-the-metro-express).

#### Arduino library

Code packages that connects an Arduino board to different devices, including break out boards, sensors, displays, communication and storage devices, are available from different libraries. The <span class='app'>Arduino</span> app has a library manager that you reach from the menu:

<span class='menu'>Sketch -> Include Library -> Manage Libraries</span>

The basics for handling libraries is explained on Ardiuons official page [Installing Additional Arduino Libraries](www.arduino.cc/en/Guide/Libraries).

### Adafruit or sparkfun

Breakout boards with the AMD AS72Sx sensor(s) are offered both by [Adafruit](../../components/components-adafruit/) and [Sparkfun](../../components/components-sparkfun-spectrometer/). Sparkfun is easier to work with if you use their [Qwiic](https://www.sparkfun.com/qwiic) connect system for I2C devices. You can then use the [Qwiic Cable - Breadboard Jumper (4-pin)](https://www.sparkfun.com/products/14425) for connecting the spectrometer to the board. If you use the Adafruit spectrometer you have to solder the breakout board.

### Wiring

The wiring is the same regardless if you use the Adafruit or Sparkfun breakout boards. The Adafruit manual is [here](https://learn.adafruit.com/adafruit-as7262-6-channel-visible-light-sensor?view=all).

### Adafruit additional components


[Adafruit TFT display 1.44 (240 x 135)](https://www.adafruit.com/product/4383), also available from [Elfa](https://www.elfa.se/sv/44-tums-tft-lcd-skaerm-adafruit-2088/p/30129195?channel=b2c&price_gs=176.25&wt_mc=se.cse.gshop.sv.-&source=googleps&ext_cid=shgooaqsesv-na&&gclid=Cj0KCQiA-4nuBRCnARIsAHwyuPo4YAQ16hq3lAwA2j1m6p-NhvISnPZBGCaRi5XegqPpJp5-LjVZA0MaAv2REALw_wcB).

[Adafruit TFT display 0.96 (160 x 80)](https://www.elfa.se/sv/96-tums-160-80-tft-display-delning-adafruit-3533/p/30139159?q=Adafruit+0.96&pos=2&origPos=2&origPageSize=10&track=true).

The board used in the Adafruits manual for [Arduino wiring of these components](https://learn.adafruit.com/adafruit-as7262-6-channel-visible-light-sensor/arduino-wiring-test) is the Adafruit METRO M0 Express, also available from [Elfa](https://www.elfa.se/sv/adafruit-metro-m0-express-adafruit-3505/p/30129229?q=Adafruit+Metro+M0+&pos=1&origPos=1&origPageSize=10&track=true).
