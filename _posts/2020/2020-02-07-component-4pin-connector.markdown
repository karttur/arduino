---
layout: post
title: 4-pin connector
categories: component
excerpt: "4-pin connector for external probes"
tags:
- 4pin connector
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-07 11:27'
modified: '2020-05-25 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction



#### SHTXY moisture and temperature sensor

From the [Adafruit product page](https://www.adafruit.com/product/1298): Old version with four color wires: Red = VCC (3-5VDC), Black or Green = Ground, Yellow = Clock, Blue = Data
Newer version with four color wires: Red = VCC (3-5VDC), Black = Ground, Yellow = Clock, Green = Data

table 1: Complete connection in Karttur's mojjäng


| socket | SHTXY wire | 4-pin code | 4-pin wire | nano port |
| VCC | red* | 4 | red | 5v |
| GND | green | 2 | black | GND |
| Clock | yellow | 3 | yellow | D11 |
| Data  | blue* | 1 | blue | D10 |

With 5v power there should be a 10 K Ohm resistor between VCC and the Data (blue and red) I have squeezed that resistor into the 4-pin connector.
