---
layout: post
title: DS18B20 temperature module
categories: module
excerpt: "KY-001 - the DS18B20 temperature module"
tags:
  - temperature
  - sensor
  - DS18B20
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-14 11:27'
modified: '2020-02-14 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

The DS18B20 digital thermometer provides 9-bit to 12-bit Celsius temperature measurements and has an alarm function with nonvolatile user-programmable upper and lower trigger points. The DS18B20 communicates over a 1-Wire bus that by definition requires only one data line (and ground) for communication with a central microprocessor. In addition, the DS18B20 can derive power directly from the data line (“parasite power”), eliminating the need for an external power supply. [Datasheet](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf).

### KY-001

I got a [KY-001 Arduino Temperature Module](http://www.mikroblog.net/37-sensor-kit/ky-001-temperature-sensor-module.php) [or here](https://arduinomodules.info/ky-001-temperature-sensor-module/) as part of a [kit with 40 modules](https://rydepier.wordpress.com/2015/06/13/list-of-keyes-boardssensors-for-arduino/). The youtube video [KY-001 Temperature sensor DS18B20 Arduino](https://www.youtube.com/watch?v=sBIXxS4xTao) introduces both the breakout board (from Keyes) and the component. The KY-001 board include a pull-up resistor of 4.7 kOhm that is required for generating the correct data signal.

<figure>
<img src="../../images/module-DS18B20-temperature.png">
<figcaption> The KY-100 module with the DS18B20 analog temperature sensor. </figcaption>
</figure>

### Waterproof and cabled

Several different online shops sell the DS18B20 temperature sensor encased in watertight metal and with a waterproof cable. I got mine form [pchbutik.se](https://pchbutik.se/komponenter/82-2-st-digital-vattentat-temperatur-givare-passar-arduino.html?search_query=temperatur&results=94). Most of these modules do **not** contain the 4.7 kOhm [pull up resistor](https://learn.sparkfun.com/tutorials/pull-up-resistors/all). Thus you must include that in the wiring, explained in the [project page for the DS18B20 sensor](../../projects/project-DS18B20-temperature).

<figure>
<img src="../../images/waterproof-DS18B20-temperature.png">
<figcaption> Waterproof casing and cabling of the DS18B20 analog temperature sensor. </figcaption>
</figure>
