---
layout: post
title: DC-DC stepup 5 volt
categories: stulturum
startversion: 0.021
endversion: 0.021
excerpt: "DC-DC 1V-5V to 5V Stepup converter module allowing 500MA"
tags:
  - arduino
  - batteri
  - lithium
  - stepup
  - 5 volt
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-12-12 11:27'
modified: '2020-07-17'
comments: true
share: true
---

### Introduction

For a more complete discussion on power solution and stepup modules, see the post  on [Power solution for 3.7 volt Arduino](../../module/module-batteri/).

When writing this, in 2019 (updating in 2020) there are 4 typical voltages used with Arduino and the power supplied:

- 3.3 volt for a range of individual components and modules
- 3.7 volt for lithium batteries
- 5 volt for most arduino boards and most individual components and modules
- +7 volt for use as input to a range of arduino boards (with internal regulation).

### 3.7 to 5v stepup

My first trials of connecting power via a battery to run my Arduino Spectrometer project included a [DC-DC 1V-5V to 5V Stepup converter module allowing 500MA, that I got from Banggood.com](https://www.banggood.com/DC-DC-1V-5V-to-5V-Converter-Step-Up-Power-Supply-Module-Boost-Adapter-Converter-Board-500MA-Voltage-Regulator-p-1578191.html?rmmds=search&cur_warehouse=CN).

<figure>
<img src="../../images/dc-dc-5v-stepup-500mA.png">
<figcaption> DC-DC 1V-5V to 5V Stepup converter.</figcaption>
</figure>
