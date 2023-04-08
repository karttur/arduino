---
layout: post
title: MOSFET transistor
categories: component
excerpt: "Regulating power supply with a MOSFET transistor"
tags:
  - transistor
  - MOSFET
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-08-07 11:27'
modified: '2021-07-05 11:27'
comments: true
share: true
---

### Introduction

A _metal oxide semiconductor field-effect transistor_, or MOSFET is a type of transistor that is used for opening and closing a circuit. MOSFETs are the most manufactured human artefact on the planet. In Arduino projects, MOSFETs are typically used for switching power consuming actuators between On and Off states. Typical actuators include motors and stronger light sources. For building arduino spectrometers, MOSFETs are needed for supplying power to stronger light sources, including [xenon](#) and [broad spectrum infrared LEDs](#).

### MOSFET

A MOSFET has three pins: __gate (g)__, __drain (d)__ and __source (s)__. The __drain__ connects to the actuator (the machine or device that is put to work) and the __source__ to the external power supply; the __gate__ determines if the connection between the __source__ and the __drain__ is ON or OFF. For an N-channel transistor, the connection between the __drain__ and the __source__ is by default OFF. Only when a positive voltage over a given threshold is supplied to the __gate__ does the circuit between __source__ and __drain__ close and the MOSFET put ON. The power supply to the __gate__ is usually of low voltage and negligible current. For Arduino compatible N-channel MOSFETS, the threshold for the __gate__ to switch between OFF and ON needs to be less than 5 (or 3.3) Volt.

N-channel MOSFETs can only be used as switches for DC system, and applied for regulating the negative (-), or ground side of the actuator. That means that the MOSFET __source__ pin should be connected to the negative (ground) side of the external power source. Battery in this case. The MOSEFT __drain__ pin is then connected to the negative (ground) side of the actuator (xenon light in this example). When positive voltage is supplied to the __gate__, an electric current can flow between the __source__ and the __drain__, and the actuator is turned ON.

#### 5 volt alternatives

The N-channel MOSFET supplied with the Arduino Projects Book is an IRF520. As this MOSFET has a low gate threshold voltage of 4V it has been popular to use with Arduino 5 volt systems.

<figure>
<img src="../../images/MOSFET_IRF520.png">
<figcaption> MOSFET IRF520. </figcaption>
</figure>

For more modest power needs, the BS170 MOSFET able to conduct 500 mA at a maximum of 60 V is popular. The BS170 is packaged in a 3-legged TO-92 capsule. Also this mosfet requires a 5 volt system to reach the fully open state and transmit 500mA, it is thus **not** suitable for 3.3 volt systems or lower.

<figure>
<img src="../../images/MOSFET_BS170.png">
<figcaption> MOSFET BS170. </figcaption>
</figure>

Note how the positions of the __G__, __D__, __S__ pins differ between the IRF520 and BS170 MOSFETs. The wiring with the BS170 thus differs compared to the MOSFET project (_Mothorized pinwheel_) in the Arduino Projects Book.

#### 3 volt alternatives

Having switched to the arduino [Nano33 system](../../module/module-nano-iot-33), I discovered that the BS170 MOSFET could not feed forward the 500 mA the my system solution with a xenon light required. Looking for an N-channel MOSFET with a lower gate threshold, I came across the following alternatives:

[SI2300](https://www.vishay.com/docs/65701/si2300ds.pdf) (several versions with different ratings) available from e.g. [digi-key](https://www.digikey.com/en/products/filter/transistors-fets-mosfets-single/278?s=N4IgTCBcDaIMoEkwGYAMqQF0C%20Q&utm_campaign=buynow&utm_medium=aggregator&utm_source=allaboutcircuits), available as surface mount format SOT (small-outline transistor) 23.

[SQ2310](https://www.vishay.com/docs/67036/sq2310es.pdf)  (several versions with different ratings) available from e.g. [digi-key](https://www.digikey.com/en/products/filter/transistors-fets-mosfets-single/278?s=N4IgTCBcDaIMoEUwGYCMAGEBdAvkA&utm_campaign=buynow&utm_medium=aggregator&utm_source=allaboutcircuits) available as surface mount format SOT (small-outline transistor) 23.

[irlml2502pbf](https://www.infineon.com/dgdl/irlml2502pbf.pdf?fileId=5546d462533600a401535668048e2606) available from [Elfa](https://www.elfa.se/en/mosfet-20-25-sot-23-ir-irlml2502pbf/p/17139652) and also packaged as SOT-23.

[IRLML2502TRPBF](https://www.infineon.com/dgdl/irlml2502pbf.pdf?fileId=5546d462533600a401535668048e2606) is yet another SOT-23 packaged N-channel MOSFET, available from [digi-key](https://www.digikey.se/product-detail/en/infineon-technologies/IRLML2502TRPBF/IRLML2502TRPBFCT-ND/812502?utm_adgroup=Semiconductor%20Modules&utm_source=google&utm_medium=cpc&utm_campaign=Dynamic%20Search_EN_Product&utm_term=&productid=&gclid=CjwKCAjwuIWHBhBDEiwACXQYsbtAMSVRv3U0dAIrJABa2HObk9QIcP3aNyweCfX9kDCGoZC7Y2cJGBoCf10QAvD_BwE) but also [fyndiq.se](https://fyndiq.se/produkt/50st-irlml2502trpbf-stromforsorjning-ny-och-original-n-kanal-pa-f8a34e4bc99342e1/).

<figure>
<img src="../../images/MOSFET_FQP30N06L.png">
<figcaption> MOSFET FQP30N06L. </figcaption>
</figure>

Looking for an alternative in a "TO" (three legged) package, I could only find T0-220 alternatives (and no TO-92 like the BS170). The price for a _TO_ compared to _SOT_ packaged MOSFET is about an order of magnitude.
[FQP30N06L](https://cdn.sparkfun.com/datasheets/Components/General/FQP30N06L.pdf) is available from [fyndiq.se]https://fyndiq.se/produkt/10st-fqp30n06l-fqp-30n06l-60v-logik-n-kanal-mosfet-to-220-0-one-size-2bbde9ae34e94730/). The gate opens fully at 2.5 volt.
