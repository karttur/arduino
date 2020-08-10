---
layout: post
title: Xenon light with MOSFET regulation
categories: component
excerpt: "Xenon light with MOSFET regulation"
tags:
  - xenon
  - light source
  - MOSFET
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-08-07 11:27'
modified: '2020-08-07 11:27'
comments: true
share: true
component: null
sensor: null
module: null
project: project-mosfet-xenon
---

### Introduction

A _metal oxide semiconductor field-effect transistor_, or MOSFET is a type of transistor that is used for opening and closing a circuit. MOSFETs are the most manufactured human artefact on the planet. In Arduino projects, MOSFETs are typically used for switching power consuming actuators between On and Off states. Typica actuators include motors and stronger light sources.

### MOSFET

A MOSFET has three pins: __gate (g)__, __drain (d)__ and __source (s)__. The __drain__ connects to the actuator (the machine or device that is put to work) and the __source__ to the external power supply; the __gate__ determines if the connection between the __source__ and the __drain__ is ON or OFF. For an N-channel transistor, the connection between the __drain__ and the __source__ is by default OFF. Only when a positive voltage over a given threshold is supplied to the __gate__ does the circuit between __source__ and __drain__ close and the MOSFET put ON. The power supply to the __gate__ is usually of low voltage and negligible current. For Arduino compatible N-channel MOSFETS, the threshold for the __gate__ to switch between OFF and ON needs to be less than 5 (or 3.3) Volt.

N-channel MOSFETs can only be used as switches for DC system, and applied for regulating the negative (-), or ground side of the actuator. That means that the MOSFET __source__ pin should be connected to the negative (ground) side of the external power source. Battery in this case. The MOSEFT __drain__ pin is then connected to the negative (ground) side of the actuator (xenon light in this example). When positive voltage is supplied to the __gate__, an electric current can flow between the __source__ and the __drain__, and the actuator is turned ON.

The N-channel MOSFET supplied with the Arduino Projects Book is an IRF520. As this MOSFET has a low gate threshold voltage of 4V it is popular to use with Arduino.

<figure>
<img src="../../images/MOSFET_IRF520.png">
<figcaption> MOSFET IRF520. </figcaption>
</figure>

For more modest powre needs, the BS170 MOSFET able to conduct 500 mA at a maximum of 60 V is popular.

<figure>
<img src="../../images/MOSFET_BS170.png">
<figcaption> MOSFET BS170. </figcaption>
</figure>

Note how the positions of the __G__, __D__, __S__ pins differ between the IRF520 and BS170 MOSFETs. The wiring with the BS170 thus differs compared to the MOSFET project (_Mothorized pinwheel_) in the Arduino Projects Book.

### Xenon light

The xenon high-pressure light bulb from [Barthelme](https://www.barthelme.de) is available from [Condar.com](https://www.conrad.com) that also has a Swedish outlet [Conrad.se](https://www.conrad.se/p/tru-components-1590267-xenonlampa-3-v-090-w-sockel-bi-pin-127-mm-klar-1-st-1590267). The xenon light requires 3 V and 300 mA, it has a diameter of 3mm and a length of 10.5 mm. It thus neatly fits into holders for micro leds. The xenon does not have any dedicated anode or cathode.

<figure>
<img src="../../images/xenon-barthelme_3V-09W.png">
<figcaption> Barthelme xenon bulb 3V, 300 mA, 0.90 W. </figcaption>
</figure>
