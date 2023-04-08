---
layout: post
title: Hamamatsu C12880MA spectrometer
categories: module
excerpt: "Hamamatsu C12880MA miniaturised 288 band sensor"
tags:
  - spectrometer
  - Sensors
  - Hamamatsu
  - C12880MA
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-05-23 11:27'
modified: '2020-05-23 T18:17:25.000Z'
comments: true
share: true
component: null
sensor: sensor-C12880MA-spectrometer
module: module-C12880MA-spectrometer
project: project-C12880MA-spectrometer
projectuno: null
---

### Introduction

Hamamatsu's [C12880MA ultra-compact spectrometer](https://www.hamamatsu.com/jp/en/product/type/C12880MA/index.html) is at time of writing this (May 2020) perhaps the best option for a miniaturised spectrometer to put with a micro-controller. It has 288 pixels, and 256 channels with 15 nm of resolution. The internal CMOS image sensor and optics are hermetically sealed to increase humidity resistance.

### Versions

The C12880MA spectrometer is the second generation of this miniaturised sensor. Here are the specs as listed on [Hamamatus's own data sheet](https://www.hamamatsu.com/resources/pdf/ssd/c12880ma_kacc1226e.pdf):

- Size: 20.1 × 12.5 × 10.1 mm
- Weight: 5 g
- Spectral response range: 340 to 850 nm
- Spectral resolution: 15 nm max.
- Hermetic package
- Wavelength conversion factor is listed on test result sheet.

### Breakout boards

<figure>
<img src="../../images/module-hamamatsu-C12880MA-spectrometer.png">
<figcaption> Breakout board with the Hamamatsu C12880MA micro spectrometer.
</figcaption>
</figure>

[GetLab of GroupGets](https://groupgets.com/manufacturers/getlab) has a [C12880MA Breakout Board](https://groupgets.com/manufacturers/getlab/products/c12880ma-breakout-board) for sale at about 400 USD. This module is also sold by [DigiKey](https://www.digikey.se/product-detail/en/groupgets-llc/BO-HAMA-2-C12880MA/2077-BO-HAMA-2-C12880MA-ND/10223724?_ga=2.167694782.107621040.1590226174-761197709.1590226174) (that also stock the module by [Seeed](https://www.digikey.se/product-detail/en/seeed-technology-co-ltd/114991292/114991292-ND/7622897)).

[SeeedStudio](https://www.seeedstudio.com/Hamamatsu-C12880MA-MEMS-u-Spectrometer-and-Breakout-Board-p-2916.html) also produces as breakout board from the same sensor. it also sells for approximately 400 USD.

In Sweden, [Elfa](https://www.elfa.se/sv/hamamatsu-c12880ma-spectrometer-seeed-studio-114991292/p/30118361?gclid=Cj0KCQiA9orxBRD0ARIsAK9JDxSBoZ7hzrF4KpzFqj6pvyNkKLuvUZiM9abn-I-fIz7v3CDZi8Q00rUaAq1HEALw_wcB&%2F%3Fext_cid=shgooaqsesv-P-CSS-Shopping-MainCampaign-DevelopmentBoards-Kits&channel=b2c&ext_cid=shgooaqsesv-blcss&price_gs=5346.25&wt_mc=se.cse.gshop.sv.-&source=googleps&kw=%7Bkeyword%7D) sells the SeededStudie breakout board at approxiamtely 5,400 SEK (incl VAT).

Note that [SeeedStudio](https://www.seeedstudio.com/Seeeduino-XIAO-Arduino-Microcontroller-SAMD21-Cortex-M0+-p-4426.html) also produces there own brand of Arduino compatible boards.
