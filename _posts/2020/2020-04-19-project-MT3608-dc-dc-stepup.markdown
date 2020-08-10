---
layout: post
title: Adjustable power solution
categories: project
excerpt: "Adjustable power solution with MT3608 DC-DC adjustable stepup converter module allowing 2000MA"
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
component: component-MT3608-dc-dc-stepup
share: true
---

### Introduction

Another attempt towards a reliable power solution for the Arduino Xspectre project. The difference between this attempt and the [previous](../../module/module-batteri/) is the replacement of the stepup module, form a [fixed 5volt stepup module for max 500mA](../../component/component-dc-dc-stepup-5v/) to an [adjustable stepup module for max 2000mA](../../component/component-MT3608-dc-dc-stepup/).

### 3.7 to 7-12 volt stepup

<figure>
<img src="../../images/nano-TP4056+battery-MT3608stepup-switch_bb.png">
<figcaption> Wiring for a battery powered solution with the MT3608 DC-DC adjustable stepup converter.</figcaption>
</figure>
