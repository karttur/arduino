---
layout: post
title: Red laser 650nm
categories: projects
excerpt: "Module with red laser 650nm"
tags:
  - LED
  - RGB
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-07 11:27'
modified: '2020-02-07 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

Laser projects can build either directly on [laser components](../../components/component-laser650/) or [modules with lasers](../../modules/module-laser650/). When wiring a laser, the only additional component needed is a resistor. Modules come with a resístor, but also take unnecessary large volume. The value of the resistor is a bit vague, also because there are so many different lasers that look the same and most shops do not specify the lasers very well.

### Laser component

Wiring for a 3v laser that consumes 40 mA. The information available is vague. But I put a 56 Ohm resistor as that is what is required for changing from 5v to 3v when the current is 0.04 A (40 mA), calculated [here](http://www.hebeiltd.com.cn/?p=zz.led.resistor.calculator) or [here](http://www.gtsparkplugs.com/Dropping_Resistor_Calc.html) (with the same result).

<figure>
<img src="../../images/nano-laser-component-3v_bb.png">
<figcaption> Wiring of a 5v laser module. </figcaption>
</figure>

```

int laserPin = 9;

void setup ()
{
   pinMode (laserPin, OUTPUT); // define the digital output
}
void loop () {
   digitalWrite (laserPin, HIGH); // Turn Laser On
   delay (1000); // On For Half a Second
   digitalWrite (laserPin, LOW); // Turn Laser Off
   delay (500); // Off for half a second
}
```

### Laser module

The laser module KY-008 is secretive, I have not bene able to find a proper datasheet.

The central pin is connected to the 5v input and all it does is reveal the voltage sent to the module. it can be used for surveillance of the power supplied to the laser, and for instance sound a warning when the power is too low or has been on for a certain amount of time. The sketch is the same.

<figure>
<img src="../../images/nano-laser-module-5v_bb.png">
<figcaption> Wiring of a 5v laser module. </figcaption>
</figure>
