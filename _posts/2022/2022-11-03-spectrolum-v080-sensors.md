---
layout: post
title: Sensors and accessories v0.80
categories: spectrolum
version: v0.80
excerpt: "List of sensors and accessories to consider for version 0.80"
tags:
  - spectrometer
  - stulturum
  - sensors
  - accessories

image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-11-04'
modified: '2022-11-04'
comments: true
share: true
---

### Introduction

On the verge of producing a first series of xSpectre´s spectrometer, which should be version 0.80, this post lists all the sensors and accessories that the model should be able to carry.

### Microcontroller

The microcontroller determines the available ports, power supply and processing capacity. As an outset version 0.80 will use the same microprocessor as version 0.78: the [Adafruit Feather nrF62840 express](../../module/module-feather-nRF52840/).

### Spectral sensors


#### Hamamatsu science grade sensors

The main sensor for xSpectre version 0.80 will be the Hamamatsu near infrared (NIR) miniature sensor [C14384MA-01](sensor/sensor-C14384MA-01-spectrometer/). But alternatively the visible (VIS) to NIR [C12880MA]() sensor should be possible to use as well. They build on the same principles and are similarly operated, but with the C14384MA sensor requiring a higher start pulse voltage.

#### AMS Hyperspectral NIR Sensor

 The [AMS OSRAM AS7421 Hyperspectral NIR Sensor](https://ams.com/as7421) was launched in September 2022. It is announced as made for Apple iPad, but I can not find any iPad with built-in spectrometer advertised.

 [Mouser](https://www.mouser.se/c/?q=AS7421) advertises the AMS 64 band NIR sensor for €16 each when buying 10 or more, increasing to €24 for buying a single sensor. Expected to become available late January 2022.

#### AMS hobby grade sensors

The AMS ...

#### BNC connected Ion Selective Electrodes (ISEs)

[pH](https://www.pasco.com/products/sensors/wireless/ps-3514)

[Nitrate](https://www.pasco.com/products/sensors/wireless/ps-3521)

[ammonium](https://www.pasco.com/products/sensors/wireless/ps-3516)

[calcium](https://www.pasco.com/products/sensors/wireless/ps-3518)

[chloride](https://www.pasco.com/products/sensors/wireless/ps-3519)

[Potassium](https://www.pasco.com/products/sensors/wireless/ps-3520)

[Oxidation Reduction Potential Probe](https://www.pasco.com/products/sensors/wireless/ps-3515)

[Carbon Dioxide](https://www.pasco.com/products/sensors/wireless/ps-3517)

[Shanghai Measuretech Scientific Instrument Co., Ltd](http://www.measureteq.com/electrode-and-sensor/) offers the same, and more.

[Shanghai Rex technologu Co (Alibaba)](https://shrex.en.alibaba.com/minisiteentrance.html?spm=a2700.details.0.0.b2092b79sAS4YE&from=detail&productId=1600229164961) is another supplier.

The ISE from the two latter comes at 1/10 the price of PASCO.

#### GX connections

##### ModBus

SEEED studio [soil moisture, temperature and electric conductivity](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-EC-Sensor-S-Soil-MTEC-02-p-4633.html)

[Soil NPK (ebay)](https://www.ebay.com/itm/274795734471?var=575029255148&norover=1&mkevt=1&mkrid=21572-161791-658771-9&mkcid=2&itemid=575029255148_274795734471&targetid=294505072980&device=c&mktype=pla&googleloc=9062465&poi=&campaignid=18211069817&mkgroupid=149185976548&rlsatarget=pla-294505072980&abcId=&merchantid=605335973&gclid=CjwKCAjw8JKbBhBYEiwAs3sxN2Jf3xFjDz8MbkVNLvjrCtgiA3UAnsX_AHCtg1rw1OMb-2-m4WgEABoCBdgQAvD_BwE)

http://lorawan.lnwshop.com/product/160/7-in-1-npk-ph-ec-temp-humid-soil-sensor

https://www.amazon.com/Taidacent-Detector-Agricultural-Phosphorus-Potassium/dp/B08MXXSP59?dchild=1&keywords=npk%2Bsensor&qid=1615207116&sr=8-1&linkCode=sl1&tag=electron0f21e-20&linkId=f0b29b991e36fecb831aa09a0050bb5d&language=en_US&ref_=as_li_ss_tl&th=1 BUT 12-24 volt

https://how2electronics.com/measure-soil-nutrient-using-arduino-soil-npk-sensor/, also 9-12 volt


[JXCT](http://www.jxct-iot.com) has a series of [rs485/MODBUS stainless steel pinned sensors](http://www.jxct-iot.com/product/product.php?class2=118). On an Indian site, the [NPK sensor](https://roboticsdna.in/product/rs485-soil-npk-ph-sensor-probe-npk-sensors-detector-meter-for-agricultural-soil-nitrogen-tester/) from JXCT is advertised to operate at 5V, but I can not find that one on the JXCT we page. The Indian company also advertises a [7 in 1 Soil Sensor JXBS-3001-TR](https://roboticsdna.in/product/rs-ecthnpkph-tr-n01-soil-7-in-1-sensor/), also from []

https://roboticsdna.in/product/soil-moisture-sensor-detector-module-and-humidity-test-sensor-with-cable/

##### other

CO2 sensor (the one I have) - check if the port can deliver the voltage or if I need to use an external battery and a switch but still receive the signal back?


### To consider compared with v0.78

The start pulse voltage difference dependent on spectral sensor

Is a cheaper version with an [AMS AS7343 14-band sensor]() possible to combine with the Hamamatsu sensors?
