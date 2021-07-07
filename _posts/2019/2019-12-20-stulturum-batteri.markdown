---
layout: post
title: Power solution for 3.7 volt Arduino
categories: stulturum
startversion: 0.021
endversion: 0.069
excerpt: "Power solution including regulator and Lithium Polymer battery for Arduino"
tags:
  - arduino
  - batteri
  - lithium
  - stepup
  - TP4056
  - charge control
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-12-20 11:27'
modified: '2020-07-17'
comments: true
share: true
---

### Introduction

It seems that stand alone Arduino project must eventually run from a 3.3 volt system solution. To be powered it needs a charge regulator and a battery. And to run 5v components it would also need a stepup device that boosts from 3.7v to 5v if you really can trust the device, otherwise between 7 and 12 volts.

The battery should be charged using a standard usb-solution. For me the battery capacity is less important, my device will not consume much. The battery should be a Lithium Polymer (LiPo).

### Youtobe introduction

A good, but also outdated, introduction is the youtube video by LessonStudio on [HOW TO: Use Lithium 3.7v batteries in small Arduino projects.](https://www.youtube.com/watch?v=nh9lEM5L28k). The video is outdated regarding the TP4056 module - the later versions can be used for power supply, as explained further down in this post. The part called 18650 in the video is now the new TP4056.

The video is also not explaining how to actually power your arduino project. If you have very well regulated 5volt supply you can directly put the power from the regulator to the 5V port on the arduino. But if yuour power supply (battery) is not regulated, but vary, you should instead put the power to the Vin port on the Arduino, and then (7)9-12 volts is required, as explained on [stackexchange](https://arduino.stackexchange.com/questions/4458/what-are-the-5v-and-vin-pins-for).

### Battery control board

LiPo batteries require a control board, or manager. The most advanced module that I have found is the [SparkFun Battery Babysitter](https://www.sparkfun.com/products/13777). This device both controls the charging and the power (draining), can be connected to Arduino and show the battery status. At time of writing this (December 2019), this module is not available in Sweden. Having gotten deeper into this subjects it seems that the "babysitter" is an overkill anyway.

The deeper look (i.e. the Youtube introduction mentioned above) instead led me to the TP4056 Lithium Battery Charging Module. Older version of this module only function as a charge regulator. Newer versions can also be used for supplying power, for instance to an Arduino board.

You can get a TP4056 module for about 1 USD, even in Sweden if you buy a dozen or so (from [fyndiq.se](https://fyndiq.se/search/?q=TP4056&search=enter#31040599-12510pcs-tp4056-lithium-battery-charg). They are even cheaper if you buy from for example [BangGood](https://www.banggood.com).

### 3.7 to 5v stepup

Even if more and more small electronic modules and components tend to rely on 3.7 v, there are still a lot that require 5 v. If you go for a 3.7 LiPo battery you then need a 3.7 v to 5 v stepup module. Here are two alternatives with different output connections:

 [With USB connection](https://www.banggood.com/20pcs-DC-DC-0_9V-5V-to-5V-600mA-USB-Step-Up-Power-Boost-Module-PFM-Control-Mini-Mobile-Booster-p-1590024.html?rmmds=detail-left-hotproducts__2&cur_warehouse=CN).

 [For soldering](https://www.banggood.com/DC-DC-1V-5V-to-5V-Converter-Step-Up-Power-Supply-Module-Boost-Adapter-Converter-Board-500MA-Voltage-Regulator-p-1578191.html?rmmds=search&cur_warehouse=CN).

 <figure>
 <img src="../../images/dc-dc-5v-stepup-500mA.png">
 <figcaption> DC-DC 1V-5V to 5V Stepup converter.</figcaption>
 </figure>

### Other solutions

Alternatively one can use separate break out boards for charge control and fuel gauging, available from e.g. [Sparkfun battery related stuff](https://www.sparkfun.com/search/results?term=lipo), or [Adafruit lipo search](https://www.adafruit.com/?q=lipo).

### Adafruit Micro-Lipo Charger

I got the [Adafruit Micro-Lipo Charger for LiPo/LiIon Batt w/MicroUSB Jack - v1](https://www.adafruit.com/product/1904) as a first trial. Because it seemed to be able to do what I want and was available from [elfa.se](https://www.elfa.se/sv/micro-lipo-med-mikro-usb-uttag-usb-litiumjon-lipoly-laddare-v1-micro-usb-adafruit-1904-micro-lipo/p/30091160?q=micro+lipo&pos=1&origPos=1&origPageSize=10&track=true). But it turned out it can only be used for charging the battery. Neither draining the battery nor powering any components.

### Battery

I just got a small standard PIS-1218 - PiJuice Zero LiPo-batteri 500 mAh from [elfa.se](https://www.elfa.se/sv/pijuice-zero-lipo-batteri-500-mah-pi-supply-pis-1218/p/30163396?queryFromSuggest=true). It was quite expensive and I need to find a cheaper solution.

### On/off button

I need an on/off button to be able to turn the device on/off physically. My first solution was a bulky "nostalgia" version from [pchbutik](https://pchbutik.se/stroembrytare/267-5-st-mini-strombrytare-1-polig-2-vags.html?search_query=0604%09&results=1). But in 2020 I found [another alternative](../../component/component-onoff-02), also at [PchButik](https://pchbutik.se/search?controller=search&orderby=position&orderway=desc&search_query=0751&submit_search=).

### Wiring

<figure>
<img src="../../images/TP4056+battery-breadboard_bb.png">
<figcaption> Wiring the TP4056 battery control and a battery to a breadboard.</figcaption>
</figure>

<figure>
<img src="../../images/TP4056+battery-nano_bb.png">
<figcaption> Wiring the TP4056 battery control and a battery to an Arduino Nano board.</figcaption>
</figure>

<figure>
<img src="../../images/TP4056+battery-nano-switch_bb.png">
<figcaption> Wiring the TP4056 battery control and a battery to an Arduino Nano board with on/off button.</figcaption>
</figure>
