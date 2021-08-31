---
layout: post
title: Arduino spectrometers
categories: spectro
excerpt: "Article on Do It Yourself (DIY) Hamamatsu spectrometer with 288 bands"
tags:
  - Arduino
  - spectrometer
  - DIY
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-09-19 11:27'
modified: '2020-09-19 11:27'
comments: true
share: true
---

### Introduction

This post is a rather disorganised list of different spectral sensors built on the Arduino platform. There is a corresponding list of [commercial handheld spectral sensors](../spectro-commercial-handheld).

### DIY UV-VIS spectrometer

Journal of Chemical Education published an [article - Teaching UV–Vis Spectroscopy with a 3D-Printable Smartphone Spectrophotometer](https://doi.org/10.1021/acs.jchemed.5b00654), on a DIY spectrometer in 2018.

### DIY publiclab spectrometers

https://publiclab.org/wiki/spectrometry

### DIY AMS spectrometer

The [6-channel AMS arduino modules](../../module/module-AS726X-spectromete) where introduced in the very first post of this blog. The core of these modules (or breakout boards) are one of the three versions of the [AMS spectral sensor](../../sensor/sensor-AS726X-spectrometer/).

In this post I have just saved a link to a page explaining how to use the spectral sensor components and build your own spectrometer from scratch. As I am interested in other light sources then those available on the pre-fabricated modules, the design and Printed Circuit Board (PCB) layout introduced in the post on [Let's Build a Spectrometer](https://www.open-electronics.org/lets-build-a-spectrometer/) is very useful.

### DIY plasma glucose spectrophotometer

In 2018 the journal Spectrochimica Acta Part A: Molecular and Biomolecular Spectroscopy, published an article on [Development of mini-spectrophotometer for determination of plasma glucose](https://doi.org/10.1016/j.saa.2018.06.107).

### DIY Water dissolved phosphate colorimeter

In 2019 the journal Analytica Chimica Acta published an article on [Development of a portable setup using a miniaturized and high precision colorimeter for the estimation of phosphate in natural water](https://doi.org/10.1016/j.aca.2019.01.030).

### DIY Hamamatsu spectrometer C12666MA

The [256-channel Hamamatsu spectral sensor C12666MA](https://www.hamamatsu.com/eu/en/product/type/C12666MA/index.html) is an alternative to the [C1288MA](../spectro-Hamamatsu-C12880MA-diy) sensor for a more advanced handheld spectrometer.

This version of Hamamatsu's series of miniature spectrometers, were tested and evaluated in a 2016 article on [Ultra-portable, wireless smartphone spectrometer for rapid, non-destructive testing of fruit ripeness](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC5015488/)(https://doi.org/10.1038/srep32504).

### DIY Hamamatsu spectrometer C12880MA

The [288-channel Hamamatsu spectral sensor](../../sensor/sensor-hamamatsu-C12880MA/) has been identified as a suitable candidate for a more advanced handheld spectrometer. The sensor is offered as an [Arduino ready module](../../module/module-hamamatsu-C12880MA/) by several producers.

In April 2020, the scientific journal HardwareX published an [article (Portable low-cost open-source wireless spectrophotometer for fast and reliable measurements)](https://www.sciencedirect.com/science/article/pii/S246806722030016X) (https://doi.org/10.1016/j.ohx.2020.e00108) on both how to build a handheld spectrometer using the Hamamatsu C12880MA spectral sensor, and also evaluated its performance. The article is open source, and code, <span class='file'>.stl</span> (3D print files) and sketches are available online at [https://doi.org/10.17605/OSF.IO/RBFSE.](https://doi.org/10.17605/OSF.IO/RBFSE.).

[Low-cost setup developed for C12880MA micro-spectrometer](https://www.hamamatsu.com/eu/en/news/featured-products_technologies/2017/20170510045237.html). The system [details](https://impfs.github.io/review/) revleas that it is setup is for [Adafruit Fruit](https://www.adafruit.com/category/943) and also operatinal with other microcontrollers. The microcontroller interfaces directly with the Hamamatsu spectral sensor.

### DIY Ibsen

[Ibsen](https://shop.ibsen.com/product/freedom-arduino-kit/) offers a visible band Arduino spectrometer base don an Hamamatsu spectral sensor with 2048 pixels.
