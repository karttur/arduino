---
layout: post
title: APDS-9930 Digital Proximity and Ambient Light Sensor
categories: module
excerpt: "Digital Proximity and Ambient Light Sensor"
tags:
  - distance
  - ambient light
  - APDS-9930
  - adafruit
  - polulu
  - sparkfun
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-04-24 11:27'
modified: '2020-04-24 T18:17:25.000Z'
comments: true
share: true
component: null
sensor:
module: module-proximity-APDS-9930
project: project-proximity-APDS-9930-nano
---

### Introduction

Integrated modules with the APDS-9930 are available from [diymore](https://www.diymore.cc/products/apds-9930-proximity-sensor-approaching-and-non-contact-proximity-module-ckin). The APDS-9960 sensor based modules are available from both [sparkfun](https://www.sparkfun.com/products/12787) and [adafruit](https://www.adafruit.com/product/3595).


I can not find any vendor offering the APDS-9930 in Sweden, neither the sensor nor as a module.

I got my APDS-9930 modules for [Banggood.com](https://www.banggood.com/10pcs-CJMCU-9930-APDS-9930-Proximity-and-Non-Contact-Gesture-Recognition-Detection-Attitude-Sensor-p-1104981.html?utm_design=131&utm_email=1585396804_2324_08&utm_source=emarsys&utm_medium=Shipoutinform190813&utm_campaign=trigger-emarsys&utm_content=Gakki&sc_src=email_2671705&sc_eh=9a59c5efb8cf9f481&sc_llid=20461599&sc_lid=104858042&sc_uid=53Z60pdPrF&cur_warehouse=CN).

The APDS-9960 are more widely available, but at significantly higher costs compared to the diymore module with the APDS-9930 sensor. The [sparkfun version available at elfa.se](https://www.elfa.se/sv/apds-9960-faerg-och-roerelsesensor-sparkfun-electronics-sen-12787/p/30145503?channel=b2c&price_gs=177.5&wt_mc=se.cse.gshop.sv.-&source=googleps&ext_cid=shgooaqsesv-blcss&kw=%7Bkeyword%7D&ext_cid=shgooaqsesv-P-CSS-Shopping-MainCampaign-DevelopmentBoards-Kits&gclid=CjwKCAjwnIr1BRAWEiwA6GpwNVLWHKUDhjWEwRahuu5gDD36DjhAIKsYzmKEDCmlO9mntR62W9EnABoCwMIQAvD_BwE) is around 17 USD. Getting [10 units Banggood.com](https://uk.banggood.com/10pcs-GY-9960-3_3-APDS-9960-RGB-Infrared-IR-Gesture-Sensor-Motion-Direction-Recognition-Module-p-1118017.html?rmmds=search&cur_warehouse=CN) reduces the price per item to 2.5 USD, still almost double the price of the APDS-9930 module at [Banggood.com](https://www.banggood.com/10pcs-CJMCU-9930-APDS-9930-Proximity-and-Non-Contact-Gesture-Recognition-Detection-Attitude-Sensor-p-1104981.html?utm_design=131&utm_email=1585396804_2324_08&utm_source=emarsys&utm_medium=Shipoutinform190813&utm_campaign=trigger-emarsys&utm_content=Gakki&sc_src=email_2671705&sc_eh=9a59c5efb8cf9f481&sc_llid=20461599&sc_lid=104858042&sc_uid=53Z60pdPrF&cur_warehouse=CN).

<figure>
<img src="../../images/module-APDS-9930.png">
<figcaption> diymore APDS-9930 Digital Proximity and Ambient Light Sensor. </figcaption>
</figure>

### Meta data

[Data sheet for APDS-9930](../docs/av02-3190en_ds_apds-9930_2015-11-13.pdf).

### Sketch and wire project

The [project post on the APDS-9930](../../project/project-proximity-APDS-9930) contains instructions for how to wire the module to an Arduino Nano board and links to libraries and codes.
