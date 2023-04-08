---
layout: post
title: RS485 steel-pin soil field sensors
categories: sensor
sensingfeature: temperature+soil-moisture+electric-conductivity+salinity+tds+epsilon+ph+nitroge+phosphorus+potassium
sensormethod: steel-pin
sensorconnect: RS485/MODBUS-RTU
sensingmedia: soil
excerpt: "Umbrella post for all RS485/MODBUS-RTU steel-pin soil field sensors."
tags:
- soil fiels sensor
- stainless steel
- RS485
- MODBUS RTU
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2023-03-05 11:27'
modified: '2023-03-05 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

The series of stainless steel-pin soil probes for direct field sensing, include the following basic versions:

- temperature & soil-moisture [temp-sm],
- temp, sm & electric conductivity (ec), salinity, total dissolved solids & epsilon [temp-sm-ec],
- Nitrogen (N), Phosphorus (P) & Potasium (K) [NPK], and
- pH [pH]

The four basic versions are available as separate units and as various combinations. The latter also include a 5-pin unit with the capacity to sense all the listed soil properties (except epsilon). The figure below shows the xSpectrolum<b>+</b> v080 spectroemter with three of the four basic version and the 5-pin version combining all at the bottom.

<figure>
<img src="../../images/xspectrev080-steel-pin-field-probes.png">
<figcaption> Field probes for soil properties that can be operated with xSpectrolum<b>+</b>. The frontmost probe can sense all the parameters of the other three combined (NPK, pH, temperature, soil moisture, electric conductivity and salinity)</figcaption>
</figure>

### RS485 MODUS-RTU

To simplify, the ANSI EIA/TIA-485, or RS485, is a hardware standard multi-point (characteristics of drivers and receivers) communications systems. MODBUS is a software protocol that uses the RS485 connection for serial communication. Some modules and sensors that operate using RS485 + Modbus are possible to use with Arduino. Among these are the [SEEED technology Soil Moisture & Temperature & EC Sensor MODBUS-RTU RS485 (S-Soil MTEC-02A)](../../sensor/sensor-seeed-modbus-soil-moisture). I got the SEEED technology MODBUS RS485 sensor to operate using xSpectre's [version 0.78 spectrometer](../../spectrolum/spectrolum-v078-summary). Once that worked, I just needed to get the MODBUS-RTU communication parameters correct for also operate all other versions of the steel-pin soil field sensors.

### temp-sm and temp-sm-ec

The most common os the soil steel-pin probes are the [temperature and soil-moisture (temp-sm) and temperature, soil-moisture, electric conductivity, salinity, total dissolved solids and epsilon (temp-sm-ec) probes](../sensor-seeed-modbus-soil-moisture). These sensors were introduced as [5 volt models by SEEED studios](../sensor-seeed-modbus-soil-moisture/).

Today, identical steel-pin sensors to the SEED studio version are offered on [AliExpress](https://aliexpress.com).

<figure>
<img src="../../images/rs485-modbus-rtu_temp-sm-ec_probe.png">
<figcaption> RS485 MODBUS-RTU steel-pin field sensor for temperature, soil moisture and electric conductivity.</figcaption>
</figure>

### NPK

Searching for 5 volt versions of the [NPK steel-pin RS485 sensor](../sensor-rs485-soil-npk/) revealed only a few options, all from China or India. Updating in January 2023 and then again in April 2023, a range of options for purchasing steel-pin NPK soil sensors with a watertight body and the RS485/MODBUS-RTU setup has become available.

While the wiring is straight forward and the MODBUS addresses given, I could not understand why I could not acceesing the sensor from Arduino. It turned out that buadrate for the NPK sensor must be set at 4800 (not the default 9600). Once I found this, the two RS485 NPK sensors I had ordered via AliExpress operated as expected.

I have not got the NPK sensor from the AliExpress vendor [ComWinTop](https://vi.aliexpress.com/item/1005001524845572.html). But other steel-pin RS485 sensors from this vendor has worked as expected and ComWinTop maintaines a complete set of versions of the steel-pin RS495 soil probes at favourable prizes.

<figure>
<img src="../../images/RS485-steel-pin-soil-npk-s.png">
<figcaption> RS485 MODBUS-RTU steel-pin field sensor for Nitrogen (N), Phosphorus (P) and Potasium (K).</figcaption>
</figure>

### pH

### All in one (or 7 in 1)
