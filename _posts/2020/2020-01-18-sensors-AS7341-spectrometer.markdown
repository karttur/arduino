---
layout: post
title: AMS spectral sensor AS7341
categories: sensors
excerpt: "AMS 11-channel broad band sensors"
tags:
  - spectrometer
  - Sensors
  - AMS
  - AS7341
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-17 11:27'
modified: '2020-01-17 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

The [AMS AS7341 11-band spectral sensor](https://ams.com/ko/as7341?fbclid=IwAR3RyybhA7qlqQo8N8hP6GgB0USwy7JsjBKn_7Tohk5hR1qRGd4WeozAuhA) was launched in 2019 and is not yet (January 2020) available as a module. To use it at this time you have to solder it together with all required components to make it work.

To me it seems like a later and upgraded version of the [AMS AS726x series of spectral sensing engines](https://ams.com/AS7261), also linked in [this post](../sensors-AS726X-spectrometer).


### Versions

There are three versions of the AMS series AS726x of 6-channel broad band micro-sensors:

- [AS7261 (Red-Green-Blue, Near InfraRed)](https://ams.com/AS7261)
- [AS7262 (Visible)](https://ams.com/AS7262)
- [AS7263 (Near InfraRed)](https://ams.com/AS7263)

### Yotube presentation

[Youtube presentation by AMS](https://www.youtube.com/watch?v=y6ccmh24BXw), including using it for separating different baking ingredients.

There is also another AMS youtube presentation on [Smart Light Management with ams AS7261 Spectral Sensor](https://www.youtube.com/watch?v=BWD0_Vh66Jw). This presentation shows how to apply AS7261 for steering light colors and also include a module that does this.

A third youtube video [AMS - AS7261 Spectral Sensor - Color Scanning Made Easy!](https://www.youtube.com/watch?v=ofGJlK3BU-I) presents the commercial [NODE+ wireless sensor from](https://www.variableinc.com). The history of this device is also presented on a dedicated [wikipedia page](https://en.wikipedia.org/wiki/NODE_(wireless_sensor). It is [available for approximately 60 USD](https://www.variableinc.com/shop.html). It comes with an android app that links it to a mobile phone.

### Breakout boards

The AS726X sensors are available as [Arduino breakout boards](../../modules/module-AS726X-spectrometer).

The [AS726x Demo Kit](https://ams.com/as726xdemokit) is a Windows PC-hosted evaluation environment, designed to provide the user a quick-start approach to spectral sensing.

[Demo kit available from mouser](https://www.mouser.se/ProductDetail/ams/AS7265X-DEMO-KIT-V30?qs=sGAEpiMZZMt6ebhnBMWiDOYh%2FMrMJUWru3SwCgM89GEEPBr%252BOZV9NQ%3D%3D) with all three sensors in one module (similar to the [sparkfun product](https://www.sparkfun.com/products/15050))
