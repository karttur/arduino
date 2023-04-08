---
layout: post
title: AMS AS726X spectrometer
categories: sensor
sensingfeature: spectra
sensormethod: filter
sensorconnect: i2c
sensingmedia: soild+liquid+gas+soil+water+air
excerpt: "AMS 6-channel broad band sensors"
tags:
  - spectrometer
  - Sensors
  - AMS
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-10-20'
modified: '2022-11-04'
comments: true
share: true
component: null
sensor: null
sensor: null
module: module-AS726X-spectrometer
project: project-AS726X-spectrometer-nano
projectuno: project-AS726X-spectrometer-uno
---

### Introduction

The [AMS AS726x series of spectral sensing engines](https://ams.com/AS7261) are miniaturised broad band spectrometers, that are also available as [Arduino modules](../../modules/module-AS726X-spectrometer). AMS own [youtube video "ams Spectral ID iSPI Eval Kit"](https://www.youtube.com/watch?v=KKyHxXyaVPM) presents the spectrometers in detail, another AMS demo video on [AS7265x - Tricorder Mobile Demo](https://www.youtube.com/watch?v=y6ccmh24BXw&t=38s) and a third one on [Color Scanning Made Easy! ams AS7261 Spectral Sensor](https://www.youtube.com/watch?v=muxw1Sb2Kn0).

### Versions

There are three versions of the AMS series AS726x of 6-channel broad band micro-sensors:

- [AS7261 (Red-Green-Blue, Near InfraRed)](https://ams.com/AS7261)
- [AS7262 (Visible)](https://ams.com/AS7262)
- [AS7263 (Near InfraRed)](https://ams.com/AS7263)

The [AMS AS7341 11-band spectral sensor](https://ams.com/ko/as7341?fbclid=IwAR3RyybhA7qlqQo8N8hP6GgB0USwy7JsjBKn_7Tohk5hR1qRGd4WeozAuhA) was launched in 2019 and became available in 2020 as breakout board from [Adafruit](https://learn.adafruit.com/adafruit-as7341-10-channel-light-color-sensor-breakout). and [Mikroe](https://www.mikroe.com/spectrometer-click).

In February 2022 AMS presented a 14-band filter based visible (VIS) to Near Infra Red (NIR) sensor - the [AMS AS7343 Spectral Sensor](https://ams.com/AS7343).

In September 2022 AMS presented a 64-band Near Infra Red (NIR) sensor - the [[AS7421 Hyperspectral NIR Sensor](https://ams.com/as7421).

### Yotube presentation

https://www.youtube.com/watch?v=KKyHxXyaVPM

[Youtube presentation by AMS](https://www.youtube.com/watch?v=y6ccmh24BXw), including using it for separating different baking ingredients.

The video on [ams Spectral ID iSPI Eval Kit](https://www.youtube.com/watch?v=KKyHxXyaVPM) is a bit more technical. As I am using the Arduino interface I do not feel that I need the [AMS Evaluation Kit](https://ams.com/as726xdemokit).

There is also another AMS youtube presentation on [Smart Light Management with ams AS7261 Spectral Sensor](https://www.youtube.com/watch?v=BWD0_Vh66Jw). This presentation shows how to apply AS7261 for steering light colors and also include a module that does this.

A third youtube video [AMS - AS7261 Spectral Sensor - Color Scanning Made Easy!](https://www.youtube.com/watch?v=ofGJlK3BU-I) presents the commercial [NODE+ wireless sensor from Variable Inc.](https://www.variableinc.com). It is [available for approximately 60 USD](https://www.variableinc.com/shop.html). It comes with an android app that links it to a mobile phone.

### Breakout boards

The AS726X sensors are available as [Arduino breakout boards](../../modules/module-AS726X-spectrometer).

The [AS726x Demo Kit](https://ams.com/as726xdemokit) is a Windows PC-hosted evaluation environment, designed to provide the user a quick-start approach to spectral sensing.

[Demo kit available from mouser](https://www.mouser.se/ProductDetail/ams/AS7265X-DEMO-KIT-V30?qs=sGAEpiMZZMt6ebhnBMWiDOYh%2FMrMJUWru3SwCgM89GEEPBr%252BOZV9NQ%3D%3D) with all three sensors in one module (similar to the [sparkfun product](https://www.sparkfun.com/products/15050) but at almost double the price.)
