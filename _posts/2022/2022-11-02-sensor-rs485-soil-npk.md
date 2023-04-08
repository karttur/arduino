---
layout: post
title: RS485 soil NPK
categories: sensor
sensingfeature: NPK
sensormethod: steel-pin
sensorconnect: RS485/MODBUS-RTU
sensingmedia: soil
excerpt: "Industrial Soil Nitrogen (N), Phosphorus (P) and Potassium (K) Sensor MODBUS-RTU RS485"
tags:
- arduino
- soil
- rs485
- MODBUS RTU
- NPK
- nitrogen
- phosphorus
- potassium
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-11-02'
modified: '2022-11-02'
comments: true
share: true
---

### Introduction

With the [SEEED rs485 + ModBus soil moisture and salinity module](../../sensor/sensor-seeed-modbus-soil-moisture/) operating properly I started to look for a 3.3V to 5V operated RS485 MODBUS soil NPK snesor with stainless steel pins. I had seen those passing by when exploring the SEEED soil moisture module.

### Versions

The MODBUS Soil-NPK sensor is not available (January 2023) from any of the usual suspects supplying Arduino compatible sensors. As was the case with the MODBUS Soil-MTEC sensor, the majority of the MODBUS Soil-NPK sensors offered are for 12-24 V power supply. But in late 2022 versions that can be powered from 5-30 V turned up on [Aliexpress](https://www.aliexpress.com). I ordered mine in early December 2022 from [Liyuan electroncis](https://www.aliexpress.com/item/1005002362255438.html?spm=a2g0o.order_list.order_list_main.46.21ef1802QZaDGn) at $43, the price when updating this (late January 2023) is down to $32.

### MODBUS rs485 soil NPK sensor

There is a plethora of sensors with similar robust design including 2 or more stainless steel pins to push into the soil and that operate using the MODBUS rs485 connection solution. The only one available in Sweden, and from one the recognised producers of Arduino accessories is the [Soil Moisture  sensors](sensor-seeed-modbus-soil-moisture). There are, however, lots of producer of MODBUS rs485 sensors for other soil properties, including:

- pH,
- EC,
- Nitrogen, Phosphorus and Potassium (NPK),
- pH + EC,
- pH + NPK,
- pH + NPK + soil moisture,
- etc.

To find out what is available, the easiest is to go to [Alibaba.com](https://www.alibaba.com), and search for "MODBUS rs485 soil". You will get hundreds of results. The problem is that the vast majority will be for 12V to 24V power supply, which is too cumbersome to acheive for xSpectre's spectrometer. For the spectrometer I need a sensor that can be driven by 3.3V to 5V.

### Setup

the wires and wiring of the MODBUS Soil-NPK is identical to that of the MODBUS Soil-MTEC sensor. The best summary I found is from [Faranaux Electronics](https://www.faranux.com/product/soil-npk-sensor/).

### Resources

google search string "modbus function code arduino softwareserial"

[Youtube: Fun and Easy Modbus RTU Protocol - RS485](https://www.youtube.com/watch?v=nhQ_HQC7CRg)

[Arduino: ModBus implementation](https://forum.arduino.cc/t/modbus-implemntation/674118) (Arduino IDE sketch with explanation comments for function call etc, scroll down to see the edited code after comments.)

[GitHub repo: Modbus for Arduino (FOR RS 232)](https://github.com/mcci-catena/Modbus-for-Arduino/blob/master/examples/software_serial_simple_host/software_serial_simple_host.ino) (GitHub repo)

[GitHub: Arduino Library: SerialModbus](https://github.com/legicore/SerialModbus) - too esoteric at the moment.

Lots of MODBUS libraries in a single repo
https://github.com/IndustrialShields/arduino-Tools40

### Appendix
#### List of NPK sensors avalaible November 2022

[lorawan 7 in 1 sensor 5-30V](http://lorawan.lnwshop.com/product/160/7-in-1-npk-ph-ec-temp-humid-soil-sensor)

[Ebay Soil Npk sensor tester environmental fertility detector 4-20ma rs485 0-5v 0-10v)](https://www.ebay.com/itm/274795734471?var=575029255148&norover=1&mkevt=1&mkrid=21572-161791-658771-9&mkcid=2&itemid=575029255148_274795734471&targetid=294505072980&device=c&mktype=pla&googleloc=9062465&poi=&campaignid=18211069817&mkgroupid=149185976548&rlsatarget=pla-294505072980&abcId=&merchantid=605335973&gclid=CjwKCAjw8JKbBhBYEiwAs3sxN2Jf3xFjDz8MbkVNLvjrCtgiA3UAnsX_AHCtg1rw1OMb-2-m4WgEABoCBdgQAvD_BwE)

https://www.amazon.com/Taidacent-Detector-Agricultural-Phosphorus-Potassium/dp/B08MXXSP59?dchild=1&keywords=npk%2Bsensor&qid=1615207116&sr=8-1&linkCode=sl1&tag=electron0f21e-20&linkId=f0b29b991e36fecb831aa09a0050bb5d&language=en_US&ref_=as_li_ss_tl&th=1 BUT 12-24 volt

https://how2electronics.com/measure-soil-nutrient-using-arduino-soil-npk-sensor/, also 9-12 volt


[JXCT](http://www.jxct-iot.com) has a series of [rs485/MODBUS stainless steel pinned sensors](http://www.jxct-iot.com/product/product.php?class2=118). On an Indian site, the

[RoboticsDNA](https://roboticsdna.in) in India advertises an [MODBUS rs485 soil NPK sensor](https://roboticsdna.in/product/rs485-soil-npk-ph-sensor-probe-npk-sensors-detector-meter-for-agricultural-soil-nitrogen-tester/) that is listed as operating from 5V. They also have a  [7 in 1 Soil Sensor](https://roboticsdna.in/product/rs-ecthnpkph-tr-n01-soil-7-in-1-sensor/) that is listed as operating at 5V.

[RoboticsDNA](https://roboticsdna.in) also has a [sturdy soil moisture probe at 3.3 to 5V](https://roboticsdna.in/product/soil-moisture-sensor-detector-module-and-humidity-test-sensor-with-cable/) that could be interesting.

On [Aliexpress](https://www.aliexpress) I, finally, also found a [MODBUS rs485 soil NPK sensor operating at 5V](https://www.aliexpress.com/item/1005004154427983.html?spm=a2g0o.productlist.0.0.58714321rn43us&algo_pvid=8e91cdd4-5b04-41ba-8078-e860c6ee7285&algo_exp_id=8e91cdd4-5b04-41ba-8078-e860c6ee7285-37&pdp_ext_f=%7B%22sku_id%22%3A%2212000028216933438%22%7D&pdp_npi=2%40dis%21USD%2171.12%2168.99%21%21%2112.67%21%21%400b0a050116676363530512193e4168%2112000028216933438%21sea&curPageLogUid=Sg1TYrV47Yq6). You can also try searching [Aliexpress](https://www.aliexpress), again using the string "MODBUS rs485 soil" or "sem225".

The producer [ComWinTop](https://www.aliexpress.com/item/1005001524845572.html?spm=a2g0o.productlist.0.0.1482462cJEn0J4&algo_pvid=7ca7b05e-3824-465e-bf30-de181d079329&aem_p4p_detail=2022110509490238913394387040002125226&algo_exp_id=7ca7b05e-3824-465e-bf30-de181d079329-0&pdp_ext_f=%7B%22sku_id%22%3A%2212000017200416623%22%7D&pdp_npi=2%40dis%21USD%2152.75%2152.75%21%21%217.63%21%21%402100bddb16676669424031853e921f%2112000017200416623%21sea&curPageLogUid=KmdDAT577t8a&ad_pvid=2022110509490238913394387040002125226_1) has a large range of MODBUS rs485 soil sensors on ALiexpress. Some operate on 5-30V. The sensors offered includes an NPK sensor with rs485 interface and operating from 5-30V.

On [Aliexpress I also found a 3.3-30V soil moisture sensor](https://www.aliexpress.com/item/1005004777657199.html?spm=a2g0o.productlist.0.0.1482462cJEn0J4&algo_pvid=7ca7b05e-3824-465e-bf30-de181d079329&aem_p4p_detail=2022110509490238913394387040002125226&algo_exp_id=7ca7b05e-3824-465e-bf30-de181d079329-4&pdp_ext_f=%7B%22sku_id%22%3A%2212000030447040011%22%7D&pdp_npi=2%40dis%21USD%21107.5%2174.17%21%21%21%21%21%402100bddb16676669424031853e921f%2112000030447040011%21sea&curPageLogUid=kgQgRXcLEqyL&ad_pvid=2022110509490238913394387040002125226_5) but has the same price as the one offered by [SEEED technology](../../sensor/sensor-seeed-modbus-soil-moisture).
