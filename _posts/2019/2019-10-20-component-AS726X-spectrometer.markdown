---
layout: post
title: AMS spectrometers breakout boards
categories: component
excerpt: "Breakout board with AMS spectrometer"
tags:
  - spectrometer
  - AS726X
  - AS7261
  - AS7262
  - AS7263
  - AS7341
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-10-20'
modified: '2022-11-04'
comments: true
share: true
component: null
sensor: sensor-AS726X-spectrometer
module: null
project: project-AS726X-spectrometer-nano
projectuno: project-AS726X-spectrometer-uno
---

### Introduction

The Austrian company [AMS](https://ams.com) produce filter based miniature spectrometers. When I first wrote this post in 2019 AMS produced three miniature spectrometers, each with 6 bands.

The [AMS AS7341 11-band spectral sensor](https://ams.com/ko/as7341?fbclid=IwAR3RyybhA7qlqQo8N8hP6GgB0USwy7JsjBKn_7Tohk5hR1qRGd4WeozAuhA) was launched in 2019 and became available in 2020 as breakout board from [Adafruit](https://learn.adafruit.com/adafruit-as7341-10-channel-light-color-sensor-breakout). and [Mikroe](https://www.mikroe.com/spectrometer-click).

In February 2022 AMS presented a 14-band filter based visible (VIS) to Near Infra Red (NIR) sensor - the [AMS AS7343 Spectral Sensor](https://ams.com/AS7343).

In September 2022 AMS presented a 64-band Near Infra Red (NIR) sensor - the [[AS7421 Hyperspectral NIR Sensor](https://ams.com/as7421).

### Sparkfun

Sparkfun offers the AMS AS726X sensor engines as barebone components:

- [AS7261 RGB+NIR](https://www.sparkfun.com/products/15490)
- [AS7262 Visible bands](https://www.sparkfun.com/products/15491)
- [AS7263 Red to NIR bands](https://www.sparkfun.com/products/15492)

At time of writing this (January 2020) they are approximately 9 USD each.

Sparkfun also offers modules with integrated the AMS AS726X sensor engines and light sources. Only two of the three sensors components are offered as single breakout boards:

- [AS7262 Visible bands](https://www.sparkfun.com/products/14347)
- [AS7263 Red to NIR bands](https://www.sparkfun.com/products/14351)

These two modules are priced at approximately 26 USD each.

Sparkfun also offers a [breakout board that combines all three AMS spectrometers to an 18 channel spectrometer (SparkFun Triad Spectroscopy Sensor - AS7265x)](https://www.sparkfun.com/products/15050), prized at approximately 65 USD.

Sparfun presentation with video on
[AS726X NIR/VIS Spectral Sensor Hookup Guide](https://learn.sparkfun.com/tutorials/as726x-nirvi?_ga=2.211969364.15411215.1573062302-739318782.1573062302)

I bought the Sparkfun modules from [digi-key Sweden](https://www.digikey.se), they arrived within 48 hours at my doorstep (now shipment cost). I was rather impressed by that.

Sparkfun offers the [11 channel AMS spectrometer, AS7341](https://ams.com/as7341) as [barebone component](https://www.sparkfun.com/products/15500), and as a [breakout board](https://www.sparkfun.com/products/17141).

### Adafruit

Adafruit only offers the [visible sensor engine as an integrated module](https://www.adafruit.com/product/3779). The Adafruit component costs 20 USD.

Adafruit has a nice blog on wiring including a small TFT-screen ["Adafruit AS7262 6-Channel Visible Light / Color Sensor Breakout"](https://blog.adafruit.com/2018/03/29/new-product-adafruit-as7262-6-channel-visible-light-color-sensor-breakout/)

The Adafruit AMS AS7262 breakout board is available in Sweden from [Elfa](https://www.elfa.se/sv/as7262-koppling-till-sensor-foer-synligt-ljus-och-faerg-3v-adafruit-3779/p/30139177?channel=b2c&price_gs=237.5&wt_mc=se.cse.gshop.sv.-&source=googleps&ext_cid=shgooaqsesv-blcss&kw=%7Bkeyword%7D&&gclid=Cj0KCQiA-4nuBRCnARIsAHwyuPqSPZTEjfoprswfdB8c7i0HC-y9g0DKSvoAV360DCei4QqBRgstdysaAlipEALw_wcB), priced at 237.50 SKE incl. VAT.

Adafruit also offers the [11 channel AMS spectrometer, AS7341](https://ams.com/as7341) assembled on a [breakout board](https://learn.adafruit.com/adafruit-as7341-10-channel-light-color-sensor-breakout). It is available from [Digikey](https://www.digikey.se/product-detail/en/adafruit-industries-llc/4698/1528-4698-ND/13162109) at about 15 USD.
