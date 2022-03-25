---
layout: post
title: Components v07
categories: component
version: "Hole mounted components spectrometer v07"
tags:
  - components
  - hole mounted
  - v07
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-03-25'
modified: '2022-03-25'
comments: true
share: true
---

### Introduction

This post lists alternative hole mounted components for [version 07](#) of xSpectre's handheld spectrometer.

### Spectral sensor

As version 07 is intended for having a variety of spectral sensors, the mounting differs dependent on the sensor.

#### Hamamatsu C12880MA

For the [Hamamatsu C12880MA](*) sensor a 14 pin (2*7) DIP IC connection socket is required. Dependent on depth and quality, alternatives include:
[digikey 2.54 mm](https://www.digikey.se/en/products/detail/preci-dip/115-87-314-41-003101/3757295)
[digikey 0 mm](https://www.digikey.se/en/products/detail/mill-max-manufacturing-corp/0531-0-15-15-31-27-10-0/4879975?s=N4IgTCBcDaIAQAYCsBmAjAWgRtSd-QzAHYdsEQBdAXyA)  (14 individual required per sensor)
[ELFA 2.54 mm]()

<figure class="third">
<img src="../../images/Hamamatsu_C12880MA.png">
<img src="../../images/2*7_DIP_IC_connection.png">
<img src="../../images/CONN_PIN_RCPT.png">
<figcaption> The Hamamatsu C12880MA spectral sensor, 14 pin (2*7) DIP IC connection socket and single pin RCPT connector (14 required for each C12880MA sensor)..</figcaption>
</figure>

### Microprocessor

![NRF52840](../../images/adafruit_feather_NRF52840.png)
{: .pull-left}

[Version 07]() is built on the [Adafruit Feather NRF52840 Express](https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather?view=all) microcontroller. It is available from [Digi-digikey](https://www.digikey.se/sv/products/detail/adafruit-industries-llc/4062/9843410).
<br />
<br />
<br />
<br />
<br />

### Pogo pin

The bayonet solution requires a 5-pin pogo connector with a 90 degree angle. I have not been able to find that through the ordinary channels I use, instead I ordered a batch of 20 from [aliexpress](https://www.aliexpress.com/item/32937109716.html?spm=a2g0o.seodetail.topbuy.1.179d3abcJQZEB0) (for approx. 30 USD). These right angle bend spring probes are usually soldered directly the the PCB, Version 07 or the spectrometer, however, requires a larger distance. To achieve that a connection socket is needed. The height of the socket depends on the spectrometer socket and the spectrometer itself, as well as other components. 5 Pos SIP Connections sockets are available from [Digikey](https://www.digikey.se/sv/products/detail/aries-electronics/05-0513-10T/2638189). To find more alternatives use the search string "CONN SOCKET SIP 5POS TIN".

<figure class="half">
<img src="../../images/pogopin5pos_rightangle.png">
<img src="../../images/connsocket5pin_sip.png">
<figcaption> 5-position pogo connector with a 90 degree angle, and single row 5 positions connection socket (distance holder).</figcaption>
</figure>

### GX12 aviation plug and connections

Version 07 of the spectrometer is equipped with a general purpose [GX12 aviation plug with 6 pins](). I get these from [Amazon.se](). They need to be manually soldered, but using a prepared [cable assembly with 8 Positions rectangular socket](https://www.digikey.se/en/products/detail/jst-sales-america-inc/A08SUR08SUR32W51A/6009352) that then attaches to the [surface mounted connector header](https://www.digikey.se/en/products/detail/jst-sales-america-inc/BM08B-SURS-TF-LF-SN/9921980?s=N4IgTCBcDaIEIFkAMAOOBaAygVQEogF0BfIA).

<figure class="third">
<img src="../../images/GX12_6pin_aviator-plug.png">
<img src="../../images/8pos_cable-assembly_rect.png">
<img src="../../images/8pos_sufmount-conn_rect.png">
<figcaption>GX12 6-pin aviation plug, cable assembly and surface mounted connector header.</figcaption>
</figure>

### BNC connector

![BNCconn](../../images/BNC-connector_rightangle.png)
{: .pull-left}

For the Ion Selective Electrodes (ISEs) (pH, nitrate, ammonia etc) a [right angle jack BNC connector](https://www.digikey.se/sv/products/detail/linx-technologies-inc/CONBNC002/16013841?s=N4IgTCBcDaIMIHkByAhJcAMGIF0C%2BQA) is required.
