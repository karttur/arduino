---
layout: post
title: Xenon light with MOSFET regulation
categories: project
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
component: component-mosfet-xenon
sensor: null
module: null
project: null
---

### Introduction

Some light sources, including xenon lights, require more current then the 40 mA that can be supplied by a normal Arduino board pin. To use such a light source in an arduino project, for instance as [light soruce for a spectrometer](https://karttur.github.io/spectro/spectrolight), you need to have a switch that can regulate the load from an external power source. There are different alternatives to achieve that, including relays or transistors. In this project, on regulating an external light source, we will use a transistor as a solid state switch. More specifically a _metal oxide semiconductor field-effect transistor_, or MOSFET.

The project described here used the _Mothorized pinwheel_ project (number 09) the from [Arduino Projects Book](https://bastiaanvanhengel.files.wordpress.com/2016/06/arduino_projects_book.pdf), as inspiration. All the online instructions and youtube videos I found were more or less confusing and all failed to present the required theoretical knowledge and the practical steps.

### MOSFET

A MOSFET has three pins: __gate (g)__, __drain (d)__ and __source (s)__. The __drain__ connects to the actuator (the machine or device that is put to work) and the __source__ to the external power supply; the __gate__ determines if the connection between the __source__ and the __drain__ is ON or OFF. For an N-channel transistor, the connection between the __drain__ and the __source__ is by default OFF. Only when a positive voltage over a given threshold is supplied to the __gate__ does the circuit between __source__ and __drain__ close and the MOSFET put ON. The power supply to the __gate__ is usually of low voltage and negligible current. For Arduino compatible N-channel MOSFETS, the threshold for the __gate__ to switch between OFF and ON needs to be less than 5 (or 3.3) Volt.

N-channel MOSFETs can only be used as switches for DC system, and applied for regulating the negative (-), or ground side of the actuator. That means that the MOSFET __source__ pin should be connected to the negative (ground) side of the external power source. Battery in this case. The MOSEFT __drain__ pin is then connected to the negative (ground) side of the actuator (xenon light in this example). When positive voltage is supplied to the __gate__, an electric current can flow between the __source__ and the __drain__, and the actuator is turned ON.

The N-channel MOSFET supplied with the Arduino Projects Book is an IRF520. As this MOSFET has a low gate threshold voltage of 4V it is popular to use with Arduino.

<figure>
<img src="../../images/MOSFET_IRF520.png">
<figcaption> MOSFET IRF520. </figcaption>
</figure>

For this project, however, the IRF520 is too large. The power requirements of the [Barthelme](https://www.barthelme.de) xenon bulb is only around 300 mA, whereas the IRF520 can handle 9.2 A. For our project we are instead going to use the smaller, but equally popular, BS170 MOSFET.

<figure>
<img src="../../images/MOSFET_BS170.png">
<figcaption> MOSFET BS170. </figcaption>
</figure>

The BS170 has a maximum capacity of 500 mA and can handle 60 V. As the xenon light source is at 300 mA and only requires 3 Volt, the BS170 MOSFET will do just fine.

Note how the positions of the __G__, __D__, __S__ pins differ between the IRF520 and BS170 MOSFETs. The wiring with the BS170 thus differs compared to the MOSFET project (_Mothorized pinwheel_) in the Arduino Projects Book.

### Xenon light

The xenon high-pressure light bulb from [Barthelme](https://www.barthelme.de) is available from [Condar.com](https://www.conrad.com) that also has a Swedish outlet [Conrad.se](https://www.conrad.se/p/tru-components-1590267-xenonlampa-3-v-090-w-sockel-bi-pin-127-mm-klar-1-st-1590267). The xenon light requires 3 V and 300 mA, it has a diameter of 3mm and a length of 10.5 mm. It thus neatly fits into holders for micro leds. The xenon does not have any dedicated anode or cathode.

<figure>
<img src="../../images/xenon-barthelme_3V-09W.png">
<figcaption> Barthelme xenon bulb 3V, 300 mA, 0.90 W. </figcaption>
</figure>

### Wiring

Apart from understanding how to connect G, D and S of the MOSFET to your Arduino board and the battery, there are two additional things you should keep in my mind. First you must connect the ground form the Arduino and the ground from the external power source (the battery). And secondly you also need a 2 Ohm resistor to reduce the 3.7 V from the battery to the 3.0 V required by the Xenon bulb. You could also use a pull-down resistor on the MOSFET gate, but I am not sure if that is really needed as the battery voltage is just 3.7 V, or how to calculate the required ohms.

<figure>
<img src="../../images/nano-xenon-mosfet-switch_breaded_bb.png">
<figcaption> Wiring of a xenon light bulb using a MOSFET and and Ardunio Nano running from an external battery. The resistor at the xenon light bulb is 2 Ohm. </figcaption>
</figure>


### Sketch

in the sketch below, the xenon light toggles between On and Off, with a 2 sec Off state and 0.2 sec On state.


```
const int xenonPin = 9;

void setup() {
  pinMode(xenonPin, OUTPUT);
}

void loop() {
 digitalWrite (xenonPin,LOW); // Turn xenon Off
 delay(2000);
 digitalWrite (xenonPin,HIGH); // Turn xenon On
 delay(200);
}
```
