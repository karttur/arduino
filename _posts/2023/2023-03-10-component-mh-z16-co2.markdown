---
layout: post
title: MH-Z16 CO2 sensor
categories: component
excerpt: "Nondispersive infrared (NDIR) gas detection using MIR emitter and dual window sensor."
tags:
- Spectrometer
- gas
- CO2
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2023-03-10 11:27'
modified: '2023-03-10 T18:17:25.000Z'
comments: true
share: true
module: module-mh-z16-co2
project: project-mh-z16-co2
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

Carbon Dioxide (CO2) is transparent in visible wavelengths (the sunlight passes through) but opaque in some Mid Infra-Red (MIR) wavelengths. This is of course also the physical basis for CO2 acting as a greenhouse gas. The content of CO2 in air can be determined by measuring the absorption of light in the wavelengths where CO2 is opaque. CO2 strongest MIR absorbance ("opaqueness") is at 2.0, 2.7 and 4.3 nano meters (nm) and spectral sensors for determining CO2 concentrations usually focus on the 4.3 nm band. In practice the concentration is determined by the difference in absorbance between 4.3 nm and a reference band, usually 3.9 nm for CO2. This is a typical setup also for medical studies where the CO2 in exhaled air is a nice summary of the bodily workload. It requires a dual window MIR spectral sensor - with one window focusing on 4.3 nm and the other on 3.9 nm (for example). And then a MIR emitter that covers (at least) the range 3.7 to 4.5 nm. Typically both the emitter and the sensor are packaged as TO39.

The module and component in the adjoining posts use the [Winsen MH-Z16 Infrared CO2 Gas Sensor](https://www.winsen-sensor.com/product/mh-z16.html). It has the setup described above with a dual window TO39 sensor and TO39 emitter. The available documentation, however, does neither reveal the actual wavelengths used, nor the make of the component.

This post lists and links some different options for dual (CO2+reference) CO2 spectral sensors and emitters. It overlaps the older post on [CO2 dual thermal sensors](../../sensor/sensor-C02dualsensor-comparison/).

### NIR-MIR emitters

Different alternative NIR-MIR emitters are listed in the post [Thermal emitters](../component-thermal-emitters).

### CO2 dual window NDIR spectral sensors

Producers of dual window (reference + CO2) CO2 sensors include:

- [Pyreos](https://pyreos.com) (now a [Broadband](https://www.broadcom.com/) company)
- [Micro-hybrid](https://www.microhybrid.com/en/)
- [Hamamatsu](#)
- [Boston electronics](http://www.boselec.com/)

Pyreos thin film technology and standard dual and quad sensors are listed in [another post](../../sensor/sensor-pyreos01/). I think these are the superior thermal sensors. Pyreos does not provide emitters.

#### Microhybrid

[Microhybrid](https://www.microhybrid.com/en/company/about-us/) have been developing and producing innovative microelectronics and infrared sensors for over 25 years. [Online shop in english](https://www.microhybrid.com/en/shop/).

[Microhybrid.com](https://www.microhybrid.com/) offers [1-4 band thermal (thermopile or IR) sensors](https://www.microhybrid.com/de/shop/thermische-ir-detektoren/), [IR emitters](https://www.microhybrid.com/de/shop/ir-strahler/) and [ready made dual-band IR spectrometers for gas sensing](https://www.microhybrid.com/de/shop/gassensoren/). they also offer a range of [bundled development products](https://www.microhybrid.com/de/shop/ndir-bundles/). For instance a bundle for [alcohol detection](https://www.microhybrid.com/en/shop/ir-emitter/ndir-bundle-oh/) applicable for use in wineries and small breweries.

#### Boston electronics

[Boston electronics](http://www.boselec.com/) offers (UV, Visible, to IR and THz photodetectors](https://www.boselec.com/product-category/ir-uv-thz-photodetectors/), [steady state IR emitters](http://www.boselec.com/product-category/ir-uv-sources/) and [?](#). they also offer a range of [?bundled development products](#).

The [thermopile (IR) sensors](http://www.boselec.com/product-category/infrared-ir-thermopile-pyroelectric-room-temperature-detectors/) are available as 1-4 band sensors housed as TO-8, TO-39, TO-46 packages.

[Boston electronics](http://www.boselec.com/) offers both broad band IR emitter and [IR LEDs](https://www.boselec.com/product-category/infrared-light-emitting-diodes-ir-led/) with centre wavelengths from 1.9 to 7 microns.

The [Application Note NDIR-Measurement](https://www.boselec.com/wp-content/uploads/Linear/Heimann/HeimannLiterature/Application_Note_-_NDIR_Measurements.pdf) gives a clear overview of using [thermopile (IR) sensors](http://www.boselec.com/product-category/infrared-ir-thermopile-pyroelectric-room-temperature-detectors/) for detecting organic gas molecules.
