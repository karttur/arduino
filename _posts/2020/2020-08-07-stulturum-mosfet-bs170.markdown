---
layout: post
title: BS-170 MOSFET
categories: stulturum
startversion: 0.031
endversion: 0.059
excerpt: "BS-170 MOSFET transistor for switching power on/off"
tags:
- MOSFET
- BS-170
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-06-30 11:27'
modified: '2020-06-30 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

A _metal oxide semiconductor field-effect transistor_, or MOSFET is a type of transistor that is used for opening and closing a circuit. MOSFETs are the most manufactured human artefact on the planet. In Arduino projects, MOSFETs are typically used for switching power consuming actuators between On and Off states. Typical actuators include motors and stronger light sources. For building arduino spectroemters, MOSFETs are needed for supplying power to stronger light sources, including [xenon](#) and [broad spectrum infrared LEDs](#).

### MOSFET

A MOSFET has three pins: __gate (g)__, __drain (d)__ and __source (s)__. The __drain__ connects to the actuator (the machine or device that is put to work) and the __source__ to the external power supply; the __gate__ determines if the connection between the __source__ and the __drain__ is ON or OFF. For an N-channel transistor, the connection between the __drain__ and the __source__ is by default OFF. Only when a positive voltage over a given threshold is supplied to the __gate__ does the circuit between __source__ and __drain__ close and the MOSFET put ON. The power supply to the __gate__ is usually of low voltage and negligible current. For Arduino compatible N-channel MOSFETS, the threshold for the __gate__ to switch between OFF and ON needs to be less than 5 (or 3.3) Volt.

N-channel MOSFETs can only be used as switches for DC system, and applied for regulating the negative (-), or ground side of the actuator. That means that the MOSFET __source__ pin should be connected to the negative (ground) side of the external power source. Battery in this case. The MOSEFT __drain__ pin is then connected to the negative (ground) side of the actuator (xenon light in this example). When positive voltage is supplied to the __gate__, an electric current can flow between the __source__ and the __drain__, and the actuator is turned ON.

For modest power needs, including the external light sources used in the spectrometer projects presented here, the BS170 MOSFET is a most suitable candidate.

<figure>
<img src="../../images/MOSFET_BS170.png">
<figcaption> MOSFET BS170. </figcaption>
</figure>
