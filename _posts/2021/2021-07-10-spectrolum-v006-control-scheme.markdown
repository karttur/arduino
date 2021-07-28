---
layout: post
title: Control schema v0.06
categories: spectrolum
version: "v0.06 control"
tags:
  - spectrometer
  - stulturum
  - v0.06
  - control
  - schema
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2021-07-10'
modified: '2021-07-10'
comments: true
share: true
---

## Stulturum spectrometer version v0.06 control schema

Version 0.06 of xSpectres spectrometers is built using the Arduino [NANO IOT 33 board](http://localhost:4000/module/module-nano-iot-33/). All versions in the 0.06 series (regardless of spectrometer) have the same basic functions. This post contains a simple schema to follow for testing the functions of the spectrometer.

### Functional control schema


_Control schema for xSpectre spectroemters v 0.6x_
| Function | status | comment |
| Power | | |
| on/off | ok/not ok | comment |
| battery charging | ok/not ok | comment |
| spectrometer | ok/not ok | comment |
| BNC connector | ok/not ok | comment |
| aviation connector | ok/not ok | comment |
| TRX | ok/not ok | comment |
| Spectrometer | | |
| light | ok/not ok | comment |
| sensor | ok/not ok | comment |
| Aviation connector | | |
| sensor Ax | ok/not ok | comment |
| sensor Ay | ok/not ok | comment |
| sensor Az | ok/not ok | comment |
| BNC connector | | |
| sensor Bx | ok/not ok | comment |
| sensor By | ok/not ok | comment |
| sensor Bz | ok/not ok | comment |
