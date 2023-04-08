---
layout: post
title: Wetland watch
categories: module
version: v0.80
excerpt: "List of stuff to use for a Wetland Watch project"
tags:
  - spectrometer
  - xspectrolum
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

### DFRobot

[Gravity: Analog CH4 Gas Sensor (MQ4) For Arduino](https://www.dfrobot.com/product-683.html), and how to hook up [Arduino Project Hub: Gas Analyser Using Arduino](https://create.arduino.cc/projecthub/noneedforit/gas-ananlyser-using-arduino-1d6f95).

### SEEED technology

[Water level sensor](https://www.seeedstudio.com/Liquid-Level-Sensor-p-4619.html?queryID=1cefa6e412cd795b7f6454e040b46dab&objectID=4619&indexName=bazaar_retailer_products) at USD 79.

[SenseCAP S2103 Wireless LoRaWAN® CO2, Temperature, and Humidity Sensor for Outdoor&Indoor Air Quality, CO2 Meter, Carbon Emission](https://www.seeedstudio.com/SenseCAP-S2103-LoRaWAN-CO2-Temperature-and-Humidity-Sensor-p-5356.html?queryID=1d9f00b7f3b498e555a338bb3f3f8ab0&objectID=5356&indexName=bazaar_retailer_products)

[The Grove - SCD30 is a 3-in-1 Arduino sensor that can measure CO2, temperature, and humidity.](https://www.seeedstudio.com/Grove-CO2-Temperature-Humidity-Sensor-SCD30-p-2911.html?queryID=47c58d2b8fb944d24b1b01e3ada323d2&objectID=2911&indexName=bazaar_retailer_products)

[Grove - Carbon Dioxide Sensor(MH-Z16)](https://www.seeedstudio.com/Grove-Carbon-Dioxide-Sensor-MH-Z16.html?queryID=b913f8bd01c90703e74c2ee5b7ded3ce&objectID=1083&indexName=bazaar_retailer_products), including [scientific reported project on soil breathing project](../../sensor/sensor-mh-z16-c02). At [Aliexpress](https://www.aliexpress.com/item/1005004678211790.html?spm=a2g0o.productlist.0.0.685d105dVZn6wH&algo_pvid=c125256c-1627-4826-8d7a-f46ac4d6aa62&algo_exp_id=c125256c-1627-4826-8d7a-f46ac4d6aa62-16&pdp_ext_f=%7B%22sku_id%22%3A%2212000030070843054%22%7D&pdp_npi=2%40dis%21USD%21487.5%21360.75%21%21%21%21%21%402100bddf16676764667453237ec9c4%2112000030070843054%21sea&curPageLogUid=pv3FzfznqwwV) you can get 10 at 360 USD, which is about 1/3 of the price of the SEEEDstudie MH-Z16 sensor in Sweden.

[https://www.seeedstudio.com/Solar-Radiation-Shield-for-Outdoor-Sensor-Protection-A10-p-4601.html?queryID=ee8b018239d583cc6a90db14968400ab&objectID=4601&indexName=bazaar_retailer_products](Solar Radiation Shield for Outdoor Sensor Protection-A10, Louver Box for Temperature, Humidity and Gas Sensors)

##### Building an IoT project

With the [SenseCAP S2110 controller](https://www.seeedstudio.com/SenseCAP-XIAO-LoRaWAN-Controller-p-5474.html) and [S2100 data logger](https://www.seeedstudio.com/SenseCAP-S2100-LoRaWAN-Data-Logger-p-5361.html), you can easily turn the CO2 Grove into a LoRaWAN® sensor. Seeed not only helps you with prototyping but also offers you the possibility to expand your project with the [SenseCAP series of robust industrial sensors](https://www.seeedstudio.com/catalogsearch/result/?q=sensecap&categories=SenseCAP&application=Temperature%2FHumidity~Soil~Gas~Light~Weather~Water~Automation~Positioning~Machine%20Learning~Voice%20Recognition&compatibility=SenseCAP), should be possible to add soil moisture (yes), temperature (yes), methane (maybe) and ground water level (maybe).

The IP66 housing, Bluetooth configuration, compatibility with the global LoRaWAN® network, built-in 19 Ah battery, and powerful support from APP make the SenseCAP S210x the best choice for industrial applications. The series includes sensors for soil moisture, air temperature and humidity, light intensity, CO2, EC, and an 8-in-1 weather station. Try the latest SenseCAP S210x for your next successful industrial project.




IoT into the wild


#### IoT into the Wild Hackster

[Wireless Monitoring System for GHGs emissions in Paddy Field](https://www.hackster.io/james-woods/wireless-monitoring-system-for-ghgs-emissions-in-paddy-field-7d2991), centered around a [Gravity: Analog CH4 Gas Sensor (MQ4) For Arduino](https://www.dfrobot.com/product-683.html).


### Sensoterra

https://www.sensoterra.com

#### Other inspirations

https://blog.quickbird.uk/ec-and-ph-sensors-for-arduino-98bb70c756b9
