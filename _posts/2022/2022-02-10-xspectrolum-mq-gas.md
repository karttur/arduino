---
layout: post
title: MQ gas sensors
categories: xspectrolum

sensingfeature: ambient-gas
sensormethod: heatedelement
sensorconnect: analog
sensingmedia: gas+air
startversion: 0.8
endversion: 0.9
port: gx16
protocol: analog
excerpt: "MQ series of gas sensors for Arduino"
tags:
  - MQ
  - gas
  - sensors
  - gx16
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-02-10'
modified: '2022-02-10'
comments: true
share: true
---

### Introduction

The series of MQ gas sensors are available for a range of combustable gases. Both more generic sensors as well sensors for specific gases (e.g. methane, butane, alcohol), are available. The sensors require heating up and after heated the analog output signal is proportional to the gas concentration. All comes with a potentiometer that can be used for adjusting the sensitivity.

These sensors are offered, and I think produced, by a range of companies. For instance [DF Robot](https://www.dfrobot.com), have them in their portfolio of [air sensors](https://www.dfrobot.com/category-85.html).

### DFRobot

At time of updating this post in November 2022 [DF Robot](https://www.dfrobot.com/category-85.html), offers the following MQ gas sensors:

- [Smoke (MQ2)](https://www.dfrobot.com/product-681.html)
- [Alcohol (MQ3)](https://www.dfrobot.com/product-681.html)
- [Methane (MQ4)](https://www.dfrobot.com/product-683.html)
- [LPG - propane (MQ5)](https://www.dfrobot.com/product-684.html)
- [Gas - propane (MQ5) (MQ6)](https://www.dfrobot.com/product-685.html),
- [CO (MQ7)](https://www.dfrobot.com/product-686.html)
- [Hydrogen Gas (MQ8)](https://www.dfrobot.com/product-687.html),
- [CO/Compustable gas (MQ9)](https://www.dfrobot.com/product-688.html)
- [HCHO - Formaldehyde (MQ10)](https://www.dfrobot.com/product-1574.html)

I think that the sensors offered by DFRobot are actually produced by [Hanwei](https://www.hwsensor.com) in China.

### Amazon multi-sensor package

I got a [set of 9 MQ gas sensors](https://www.amazon.se/Gasdetekteringssensormodul-MQ-135-Sensormodul-Sensor-Starter/dp/B08XG1CVCG/ref=asc_df_B08XG1CVCG/?tag=shpngadsglede-21&linkCode=df0&hvadid=476436733339&hvpos=&hvnetw=g&hvrand=14920957982192276642&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9062465&hvtargid=pla-1327513563094&psc=1) from Amazon, including:
- MQ-2 (Smoke)
- MQ-3 (Alcohol)
- MQ-4 (Methane)
- MQ-5 (LPG - propane)
- MQ-6 (Gas - propane)
- MQ-7 (CO)
- MQ-8 (Hydrogen)
- MQ-9 (CO & CH4)
- MQ-135 (air quality)

### Aliexpress

At [Aliexpress](https://www.aliexpress.com) you can get the standard sensors for about 1 USD a piece.

### Project

Sketch and wiring for a multi-sensor setup at [Arduino Project Hub: Gas Analyser Using Arduino](https://create.arduino.cc/projecthub/noneedforit/gas-ananlyser-using-arduino-1d6f95).

For single sensor setup: [Interfacing MQ4 Methane Gas Sensor with Arduino](https://microdigisoft.com/interfacing-mq4-methane-gas-sensor-with-arduino/).

### Power consumption

The gas analyzers operate by heating up the gas that passes the active sensor membrane (or whatever). Most of the sensors require between 750 and 900 mW (some less, none more). That would approximately equal 200 mA at 5V. Long term operation thus requires a separate power supply, but for calibration and measuring for periods of minutes, it should be sufficient with a smaller LiPo battery.
