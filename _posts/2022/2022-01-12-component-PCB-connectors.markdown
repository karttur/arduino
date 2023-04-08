---
layout: post
title: Connection components
categories: component
excerpt: "Alternatives for connecting the spectrometer box and the muzzles"
tags:
  - Connection
  - PCB
  - muzzel
  - speclum
  - ledlum
  - sampler
  - bayonet
  - pogo
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-01-12'
modified: '2022-01-12'
comments: true
share: true
---

### Introduction

The first versions (up to v06) of the xSpectre spectrometer used TRX connectors for holding the muzzle samplers in place. TRX has several shortcomings; there are only two contacts, it is bulky and it becomes a 1-sided attachment that easily forming gaps. This post first identifies some different solutions for increasing the number of contacts and for better attachment of the muzzle, and then the solution selected for version 07 of the spectrometer is presented.

### Magnetic Connector

Being a Mac user, I looked for a solution similar to the Apple MagCharger, and found this [magnetic pin connector](https://www.alibaba.com/product-detail/Electronic-device-anti-reverse-pogo-4_62537762978.html). I later learnt that this type of spring supported connectors are called "pogo" pins.

The magnetic based types are commonly availab, e.g. on [ebay](https://www.ebay.com/itm/144017332948?mkevt=1&siteid=1&mkcid=2&mkrid=21578-161791-641484-7&source_name=google&mktype=pla_ssc&campaignid=12973198226&groupid=124712055351&targeted=pla-1248581038030&MT_ID=&adpos=&device=c&googleloc=9062457&itemid=144017332948&merchantid=116792603&geo_id=192&gclid=CjwKCAiAlfqOBhAeEiwAYi43F5kt-N-4mAdb_jvgrdWXfchSO2RWgnA-wOCurWe2mQacCIesqMfhAxoCjpcQAvD_BwE)

### Non-magnetic pogo connectors

Even if the magnetic version is cool, they are not strong enough to hold the muzzles. Having found the spring based "pogo" pins, I soon found a plethora of different kinds, also from the standard stores for electronic components, including: [farnell](https://se.farnell.com/w/c/connectors/spring-loaded-connectors?st=pogo) and [digi-key](https://www.digikey.se/en/products/filter/contacts-spring-loaded-pogo-pins-and-pressure). Selecting one out of many producer, here is [Zhenge](https://pogopin.net)

### 3D printed bayonet connector

A non-magnetic pogo needs to be combined with a solution for firnly attaching the muzzle to the spectrometer box. Inspired by the bayonet attachment of lenses to a camera body, I found [thingiverse](https://www.thingiverse.com/thing:4721555) drawings for 3D printing, both the [male](https://www.thingiverse.com/thing:1500383) and [female](https://www.thingiverse.com/thing:182044) (or if it is the other way around - queer).

### xSpectre spectrometer solution

With the aim of only requiring a single action for attachment, I opted for a solution including a customized bayonet attachment combined with a 3- or 4-pin standard (non-magnetic) pogo connector. I considered three ways to link up the pogo connectors:

1. Like on camera mounted lenses - parallel to the rotation direction with individual pogo pins perpendicular to the rotation direction
2. Pogo pins planar with the rotation, with the female connectors directed towards the muzzle
3. With pins lined up along the radius of the rotation, with male pins in the muzzle pointing in the direction of the attachment rotation.

Solution 1 is the most elegant, but also the most difficult, and would ideally require a curved pogo array. It requires more customization compared to the other two solutions. Solution 2 is the simplest to achieve, but like solution 1 also means that the male pins must glide over the female pins until the rotation comes to its end positions. Solution 3 requires a deep bayonet to create the space needed. It must also involve an arm-structure for holding the female (box) pogo connectors bridging the male bayonet part of the muzzle.

In the end I opted for solution 2 for version 07 of the spectrometer (January 2022). The bayonet 3D drawings are shown i the figure 1.

<figure class="third">
<img src="../../images/baynett_box_3Ddrawing_inside_w_opening4pogo.png">
<img src="../../images/baynett_box_3Ddrawing_outside_w_opening4pogo.png">
<img src="../../images/bayonet_obective_3Ddrawing_w_opening4pogo.png">
<figcaption> Figure 1, 3D drawings of the bayonet for attaching muzzle samplers to the spectrometer box; left: view from inside spectrometer box (female pogo to fit in small opening); centre: view from outside spectrometer box (female pogo to fit in small opening); right: view into muzzle sampler (male pogo to fit in small opening).</figcaption>
</figure>
