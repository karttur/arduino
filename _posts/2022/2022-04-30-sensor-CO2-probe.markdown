---
layout: post
title: CO2 probe
categories: sensor
excerpt: "CO2 probe for soil respiration"
tags:
  - CO2
  - Sensor
  - probe
  - DFrobot
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-04-30 11:27'
modified: '2022-04-30 T11:27'
comments: true
share: true
---

### Introduction

The post on [CO2 dual thermal sensors](../sensor-CO2dualsensor-comparison) identifies different options for Mid-InfraRed (MIR) spectral sensing of air content of CO2 and CH4. This post instead identifies "plug-and-play" probes that can be used for observing the CO2 content of e.g. soil pores. That is, observing the soil respiration. This might be an alternative for estimating the soil carbon balance, as suggested by [Gyawali et al, 2019, Talking SMAAC: A New Tool to Measure Soil Respiration and Microbial Activity](https://doi.org/10.3389/feart.2019.00138).

### SMAAC

Gyawali et al, 2019 compared the SMAAC with a commercial infrared gas analyzer (IRGA) and found that the SMAAC performed well as an inexpensive yet accurate tool for measuring soil respiration and microbial activity.

The CO2 sensor requires only 4 wires to communicate with the Arduino (+V, RX, TX, and Ground). The sensor uses I2C (Intra Integrated Circuit) serial protocol and determines CO2 concentration using non-dispersive infrared absorbance (NDIR). Example code for integrating this sensor with the Arduino is available at [https://github.com/SandboxElectronics/NDIRZ16](https://github.com/SandboxElectronics/NDIRZ16).


Here is the device at Sandbox |https://sandboxelectronics.com/?product_tag=co2-sensor](https://sandboxelectronics.com/?product_tag=co2-sensor)

Seedstudio offers the [Grove - CO2 Sensor module](https://www.seeedstudio.com/Grove-Carbon-Dioxide-Sensor-MH-Z16.html?queryID=01d2afe2f0e99dd90be981c940e7d48a&objectID=1083&indexName=bazaar_retailer_products), an infrared CO2 sensor high sensitivity and high resolution. Infrared CO2 sensor MH-Z16 Is a general-purpose, small sensors, the use of non-dispersive infrared (NDIR) Present in the principle of the air CO2 Detect, with good selectivity, oxygen-dependent, long life， built-in temperature sensor, temperature compensation

[Seeedstudio](https://www.seeedstudio.com) also offers the [NDIR at 600 SEK](https://www.seeedstudio.com/Grove-CO2-Temperature-Humidity-Sensor-SCD30-p-2911.html?queryID=6ad894478cb9df5ce4aed3e405677da2&objectID=2911&indexName=bazaar_retailer_products). They also have some [interesting applications](https://www.seeedstudio.com/Grove-Carbon-Dioxide-Sensor-MH-Z16.html?queryID=01d2afe2f0e99dd90be981c940e7d48a&objectID=1083&indexName=bazaar_retailer_products).

### Connection

The SMAAC developed by Gyawali et al uses the CO2 probe [NDIRZ16]() from [Sandbox electronics]().
The [Arduino code for the [NDIRZ16 is available on GitHub](https://github.com/SandboxElectronics/NDIRZ16)


### SEEED studio IoT into the wild

In 2022 [seeedstudio](https://www.seeedstudio.com) launches the product line [IoT into the wild](https://www.seeedstudio.com/iot_into_the_wild.html). As part of the product line they offer a [LoRaWAN integrated sensor for CO2, temperature and humidity](https://www.seeedstudio.com/SenseCAP-S2103-LoRaWAN-CO2-Temperature-and-Humidity-Sensor-p-5356.html?queryID=c39b94b6fdd39a01ee87b361d1ce0651&objectID=5356&indexName=bazaar_retailer_products).
