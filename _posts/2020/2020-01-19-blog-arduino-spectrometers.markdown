---
layout: post
title: Miniature spectrometers
categories: blog
excerpt: "Miniature spectrometers made from sensors and modules listed in this repo"
tags:
  - spectrometer
  - Sensors
  - AMS
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-10-20 11:27'
modified: '2019-10-20 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

The spectral [sensors](../../sensor/index.html) and [modules](../../module/index.html) listed in this blog have been used for developing spectral sensors of different types by different companies.

### AMS AS726x

[Youtube presentation by AMS](https://www.youtube.com/watch?v=y6ccmh24BXw), including using it for separating different baking ingredients.

There is also another AMS youtube presentation on [Smart Light Management with ams AS7261 Spectral Sensor](https://www.youtube.com/watch?v=BWD0_Vh66Jw). This presentation shows how to apply AS7261 for steering light colors and also include a module that does this.

A third youtube video [AMS - AS7261 Spectral Sensor - Color Scanning Made Easy!](https://www.youtube.com/watch?v=ofGJlK3BU-I) presents the commercial [NODE+ wireless sensor from](https://www.variableinc.com). The history of this device is also presented on a dedicated [wikipedia page](https://en.wikipedia.org/wiki/NODE_(wireless_sensor). It is [available for approximately 60 USD](https://www.variableinc.com/shop.html). It comes with an android app that links it to a mobile phone.

University of Novi Sad have [demo project for creating a AS7261 XYZ Sensor - Colorimeter](https://www.optolab.ftn.uns.ac.rs/index.php/education/project-base/252-as7261-xyz-sensor-colorimeter). The project include wiring to an Arduino board, include a 3D-printed shell, and a [demo video on youtube](https://www.youtube.com/watch?v=f3F8kJKQuLE) and code written in [Laboratory Virtual Instrument Engineering Workbench (LabVIEW)](https://en.wikipedia.org/wiki/LabVIEW). The STL model is under the repo subfolder <span class='file'>stl</span> and the LabVIEW file under the directory <span class='file'>code/AS7261-VI</span>.

<figure>
<img src="../../images/AS7261-spectral-click-arduno.jpg">
<figcaption> Arduino wiring of the Mikroe "Spectral Click" AS7261 spectrometer.
</figcaption>
</figure>

<figure>
<img src="../../images/AS7261-spectral-click-stl.png">
<figcaption> STL model for casing to the Mikroe "Spectral Click" AS7261 spectrometer.
</figcaption>
</figure>
