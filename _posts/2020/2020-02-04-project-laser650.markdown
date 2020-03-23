---
layout: post
title: Red laser 650nm
categories: project
excerpt: "Module with red laser 650nm"
tags:
  - laser
  - red
  - 650nm
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-07 11:27'
modified: '2020-02-07 T18:17:25.000Z'
comments: true
share: true
component: component-laser650
project: project-laser650
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

Laser projects can build either directly on [laser components](../../component/component-laser650/) or [modules with lasers](../../module/module-laser650/). When wiring a laser, the only additional component needed is a resistor. Modules come with a built-in resistor, but also take unnecessary large volume. The sketch (script) is the same in both cases.

### Laser Module

The [laser module KY-008](../../module/module-laser650/) is a bit secretive, I have not been able to find a proper datasheet. But at  [arduinomodules.info](https://arduinomodules.info/ky-008-laser-transmitter-module/) it is stated that it requires 5 v input, thus you only need to wire directly to power and ground.

The central pin is connected to the 5v input and all it does is reveal the voltage sent to the module. it can be used for surveillance of the power supplied to the laser, and for instance sound a warning when the power is too low or has been on for a certain amount of time.

<figure>
<img src="../../images/nano-laser-module-5v_bb.png">
<figcaption> Wiring of a 5v laser module. </figcaption>
</figure>

### Laser component

Wiring for a 3v laser that consumes 40 mA. The information available is vague. But I put a 56 Ohm resistor as that is what is required for changing from 5v to 3v when the current is 0.04 A (40 mA), calculated [here](http://www.hebeiltd.com.cn/?p=zz.led.resistor.calculator) or [here](http://www.gtsparkplugs.com/Dropping_Resistor_Calc.html) (with the same result).

<figure>
<img src="../../images/nano-laser-component-3v_bb.png">
<figcaption> Breadboard wiring of a 5v laser module. </figcaption>
</figure>

<figure>
<img src="../../images/nano-laser-component-3v-breadfree_bb.png">
<figcaption> Direct wiring of a 5v laser module. </figcaption>
</figure>

### Sketch

The sketch is the same for all of the wiring above.

```

int laserPin = 6;

void setup ()
{
   pinMode (laserPin, OUTPUT); // define the digital output
}
void loop () {
   digitalWrite (laserPin, HIGH); // Turn Laser On
   delay (500); // On For Half a Second
   digitalWrite (laserPin, LOW); // Turn Laser Off
   delay (500); // Off for half a second
}
```
