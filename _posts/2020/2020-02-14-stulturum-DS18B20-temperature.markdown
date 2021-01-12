---
layout: post
title: DS18B20 temperature module
categories: stulturum
stulturum: True
startversion: 0.017
endversion: 0.021
excerpt: "DS18B20 temperature component integrated as an externally wired thermometer"
tags:
  - temperature
  - sensor
  - DS18B20
  - thermometer
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-14 11:27'
modified: '2020-03-25 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

The DS18B20 digital thermometer provides 9-bit to 12-bit Celsius temperature measurements and has an alarm function with nonvolatile user-programmable upper and lower trigger points. The DS18B20 communicates over a 1-Wire bus that by definition requires only one data line (and ground) for communication with a central microprocessor. In addition, the DS18B20 can derive power directly from the data line (“parasite power”), eliminating the need for an external power supply. [Datasheet](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf).

Several different online shops sell the DS18B20 temperature sensor encased in watertight metal and with a waterproof cable. The one used in Stulturum´s early spectrometers are from [pchbutik.se](https://pchbutik.se/komponenter/82-2-st-digital-vattentat-temperatur-givare-passar-arduino.html?search_query=temperatur&results=94). This version do **not** contain the 4.7 kOhm [pull up resistor](https://learn.sparkfun.com/tutorials/pull-up-resistors/all). Thus you must include that in the wiring, explained in the [project page for the DS18B20 sensor](../../project/project-DS18B20-temperature).

<figure>
<img src="../../images/waterproof-DS18B20-temperature.png">
<figcaption> Waterproof casing and cabling of the DS18B20 analog temperature sensor. </figcaption>
</figure>
