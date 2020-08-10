---
layout: post
title: MT3608 DC-DC stepup
categories: component
excerpt: "MT3608 DC-DC adjustable stepup converter module allowing 2000MA"
tags:
  - arduino
  - batteri
  - lithium
  - stepup
  - adjustable
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-04-19 11:27'
modified: '2020-07-17'
comments: true
project: project-MT3608-dc-dc-stepup
share: true
---

### Introduction

For a more complete discussion on power solution and stepup modules, see the post  on [Power solution for 3.7 volt Arduino](../../module/module-batteri/).

When writing this, in 2019 (updating in 2020) there are 4 typical voltages used with Arduino and the power supplied:

- 3.3 volt for a range of individual components and modules
- 3.7 volt for lithium batteries
- 5 volt for most arduino boards and most individual components and modules
- +7(-12) volt for use as input to a range of arduino boards (with internal regulation).

### 3.7 to 7-12 volt stepup

The power supply for an Arduino Nano board must either be exactly 5 volt (applied to the 5V port) or between 7 and 9 volt (applied to the VIN port). I tried the solution with a [fixed 5 volt DC-DC stepup module](../../component/component-dc-dc-stepup-5v/). But it was too weak and did not deliver a stable output of 5 volt at different loads.

I then instead got the [MT3608 2A DC-DC adjustable stepup module from Banggood.com](https://www.banggood.com/sv/1pcs-MT3608-2A-DC-DC-Adjustable-Step-Up-Power-Module-Booster-Power-Module-p-1213134.html?rmmds=search&cur_warehouse=CN).

<figure>
<img src="../../images/MT3608_dc-dc-stepup-2000mA.png">
<figcaption> DC-DC adjustable Stepup converter.</figcaption>
</figure>
