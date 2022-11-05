---
layout: post
title: CO2 dual thermal sensors
categories: sensor
excerpt: "Comparing different producer options for dual CO2 sensors"
tags:
  - CO2
  - Sensor
  - thermopile
  - InAsSb
  - MicroHybrid
  - Hamamatsu
  - Pyreos
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-03-26 11:27'
modified: '2022-03-26 T11:27'
comments: true
share: true
---

### Introduction

Estimating the content of carbon dioxide (CO2) in a gas sample (e.g in the atmosphere or from breath) requires a dual band sensor. One band for reference (usually around 3.9 micro meter) and a second band that is affected by CO2, usually around 4.3 micro meter. There are different sensor technologies for acquiring photons emitted at 3.9 and 4.3 micro meters. Different producers of spectral sensors apply different techniques, but all use a dual filter approach - with the two windows embedded in a small TO based casing. This post compares the CO2 dual filter sensors available from [Hamamatsu](), [MicroHybrid]() and [Pyreos]().

### MIR sensor technologies

I am not an expert in sensor technology. I have only taken excerpts from the web pages of the vendors.

#### Hamamatsu Si and InAsSb

Hamamatsu offers two different dual filter CO2 sensors, based on two different technologies. The simpler solution is based on a Silicon (Si) sensor and the more advanced on a InAsSb sensor.

The Si based photodiode sensor [T11722-01](https://www.hamamatsu.com/eu/en/product/optical-sensors/infrared-detector/thermopile-detector/T11722-11.html) is a dual type thermopile detector. The central wavelengths for the dual band filters are 4.26 μm (CO2) and 3.9 μm (reference). It is encased as a TO-5 housing. A similar device is also available for methane (CH4) detection (3.3 μm and the same reference).

The InAsSb photovoltaic sensor [P13243-016CF](https://www.hamamatsu.com/eu/en/product/optical-sensors/infrared-detector/inassb-photovoltaic-detector/P13243-016CF.html) use the same band filters. It comes as a surface mounted ceramic package. Also this sensor type is available for detecting CH4.

#### MicroHydrid

MicroHybrid has a series of Silica (Si) based Micro-Hybrid thermopile sensors (MTS), including a [dual band IR sensor MTS2 for CO2](https://www.microhybrid.com/en/shop/gasanalysis/ndir-bundle-co2/?file=files/docs/downloads/datenblaetter/thermische-ir-detektoren/MH-datasheet-MTS2%20SENS%20single%20gas.pdf) with the CO2 sensor filter 2xch TP E1/D2.  The price for a bundle box in their own online shop is 500€, for a set of 5 detectors and 5 emitters. A single detector is 35€.

#### Pyreos

Pyreos is building all their sensors on a patented thin film sensor. They offer two versions of their CO2 sensor, one analog, with a TO-39 casing and one digital for surface mounting. Regarding the casing, this is very similar to the alternatives offered by Hamamatsu. The band filter for CO2 is also at 4.26 μm, with the reference at 3.9 μm. The analog dual band CO2 sensor comes in five (5) different versions, PY0234, PY3151, PY2343, PY2572 and PY1943. These are for sale by [Mouser](#) at 60€ each.

The digital equivalents are EPY12211 (3.9 μm) and EPY12231 (4.3 μm) both available from [mouser](#) at 30€ each.

#### Summary

| Technology | company | sensor | unit price |
| Si photodiode | Hamamatsu | T11722-01 | ? |
| InAsSb photovoltaic | Hamamatsu | P13243-016CF | ? |
| Si thermopile | MicroHybrid | MTS2 | 35€ |
| Thin film | Pyreos | PY0234, PY3151, PY2343, PY2572, PY1943 | 30€ |
| Thin film | Pyreos | EPY12231 | 30€ |
