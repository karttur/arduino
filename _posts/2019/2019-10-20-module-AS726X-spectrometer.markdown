---
layout: post
title: AMS AS726X spectrometer
categories: module
excerpt: "Breakout board with AMS AS726X spectrometer"
tags:
  - spectrometer
  - broadband
  - AMS
  - AS726X
  - AS7261
  - AS7262
  - AS7263
  - AS7341
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-10-20 11:27'
modified: '2021-11-04'
comments: true
share: true
component: component-AS726X-spectrometer
sensor: sensor-AS726X-spectrometer
module: null
project: project-AS726X-spectrometer-nano
projectuno: project-AS726X-spectrometer-uno
---

### Introduction

The [AMS AS726X series of spectral sensing engines](https://ams.com/AS7261) are miniaturised broad band spectrometers, that are also available as modules for use with e.g. Arduino. In 2020 AMS also launched an [11-channel version, AS7341](https://ams.com/as7341).

Breakout boards, modules, with the AMS AS726X and AS7341 sensors are available from from both [Sparkfun](../../components/component-AS726X-spectrometer/) and [adafruit](../../components/component-AS726X-spectrometer/).

Cheaper [alternative 1](https://www.ebay.co.uk/itm/143307220364), [alternative 2](https://shop.pimoroni.com/products/as7262-6-channel-spectral-sensor-spectrometer-breakout), and from [Amazon](https://www.amazon.co.uk/AS7262-6-channel-Spectral-Spectrometer-Breakout/dp/B07RCGKNPQ).

### Adafruit

Adafruit only offers the [visible sensor engine as an integrated module](https://www.adafruit.com/product/3779). The Adafruit component costs 20 USD.

Adafruit offers a nice blog on wiring including a small TFT-screen ["Adafruit AS7262 6-Channel Visible Light / Color Sensor Breakout"](https://blog.adafruit.com/2018/03/29/new-product-adafruit-as7262-6-channel-visible-light-color-sensor-breakout/)

The Adafruit AMS AS7262 breakout board is available in Sweden from [Elfa](https://www.elfa.se/sv/as7262-koppling-till-sensor-foer-synligt-ljus-och-faerg-3v-adafruit-3779/p/30139177?channel=b2c&price_gs=237.5&wt_mc=se.cse.gshop.sv.-&source=googleps&ext_cid=shgooaqsesv-blcss&kw=%7Bkeyword%7D&&gclid=Cj0KCQiA-4nuBRCnARIsAHwyuPqSPZTEjfoprswfdB8c7i0HC-y9g0DKSvoAV360DCei4QqBRgstdysaAlipEALw_wcB), priced at 237.50 SKE incl. VAT.

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

### Pimoroni

There is, at least, one more producer, [pimoroni.com](https://pimoroni.com), that offers the [AMS AS7262 visible spectrometer](https://shop.pimoroni.com/products/as7262-6-channel-spectral-sensor-spectrometer-breakout), at a slightly lower price.

### Mikroelektronika (Mikroe)

[Mikroe](https://www.mikroe.com) offers the [AS7261 RGB+NIR sensor](https://www.mikroe.com/spectral-click) as a breakout board, but not specifically for Arduino. They also offer the [11 channel AMS spectrometer, AS7341](https://www.mikroe.com/spectrometer-click) as a breakout board.

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
