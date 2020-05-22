---
layout: post
title: Ambient light sensors
categories: module
excerpt: "Modules with Ambient light sensors for Arduino"
tags:
  - ambient light
  - I2C
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-10 11:27'
modified: '2020-01-10 T18:17:25.000Z'
comments: true
share: true
component: null
sensor: sensor-ambient-light
module: null
project: project-ambient-light
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

There is a range of breakout boards with digital ambient light sensors available. This post lists some of the more common. Analog ambient light sensors ("photoresistors") are not covered.

#### BH1750FVI

BH1750FVI is a digital Ambient Light Sensor IC for [I2C bus interface](../../ide/ide-I2C).  It is possible to detect wide range at High resolution (1 - 65535 lx). It is produced by [ROHM](http://rohmfs.rohm.com) that also provide a [datasheet](http://rohmfs.rohm.com/en/products/databook/datasheet/ic/sensors/light/bh1721fvc-e.pdf).

The component is outdated, there are more advanced ambient light sensors available. You get these at 2 USD at [Banggood.com](https://www.banggood.com/sv/3pcs-BH1750FVI-Digital-Light-Intensity-Sensor-Module-AVR-3V-5V-p-1088322.html?gmcCountry=SE&currency=SEK&createTmp=1&utm_source=googleshopping&utm_medium=cpc_union&utm_content=xibei&utm_campaign=xibei-ssc-se-all-0716&ad_id=367117562532&gclid=CjwKCAiA1fnxBRBBEiwAVUouUjPHJVFEAMNatPflexpifdbfpMZxqx12Kqnnbjy7ho6GK9sInW401xoCPi0QAvD_BwE&cur_warehouse=CN).

#### Adafruit TSL2591

The [Adafruit TSL2591 High Dynamic Range Digital Light Sensor](https://www.adafruit.com/product/1980) is more precise, allowing for exact lux calculations and can be configured for different gain/timing ranges to detect light ranges from 188 uLux up to 88,000 Lux on the fly.

#### Adafruit TSL2561

The [Adafruit TSL2561 Digital Luminosity/Lux/Light Sensor Breakout](https://www.adafruit.com/product/439) contains both infrared and full spectrum diodes. That means it can separately measure infrared, full-spectrum or human-visible light. But it has lower dynamic range compared to the TSL2591.

This module is [available in Sweden from elfa.se](https://www.elfa.se/sv/tsl2591-high-dynamic-range-digital-ljussensor-5v-adafruit-1980/p/30091163?channel=b2c&price_gs=89.75&wt_mc=se.cse.gshop.sv.-&source=googleps&ext_cid=shgooaqsesv-na&/?ext_cid=shgooaqsesv-P-Shopping-MainCampaign&&gclid=CjwKCAiA1fnxBRBBEiwAVUouUrvOQBRbd5DkLGgOS3S8ff9X4OXmfK7VVfUryLk8C7t6XtBii4wYUBoCNkMQAvD_BwE).

#### Adafruit SI1145

The [Adafruit Digital UV Index / IR / Visible Light Sensor](https://www.adafruit.com/product/1777) extends all the way to Ultraviolett (UV) light. That could be of interest when determining the bacground light source, or for assessing needs of sun protection (as a completely different usage).
