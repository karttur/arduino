---
layout: post
title: ws281X 5050 programmable rgb LED
categories: modules
excerpt: "ws281X 5050 programmable rgb LED"
tags:
  - LED
  - RGB
  - ws2811
  - ws2812
  - ws2813
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-12 11:27'
modified: '2020-02-11 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

These are individually addressable RGB LEDs - this means with just 3 wires, you can make each LED turn any one of 16 million colours. They come in many different forms - LED Strings (like above), LED Strip, Matrices like Adafruit's NeoPixels or the RGB123, or even 5mm LEDs. Note that while physically different (some are built into LEDs, some are separate chips), the WS2811/WS2812/WS2812B/APA104/APA106/SK6812 all work the same way electrically. The Youtube [LED Strips, what's the difference](https://www.youtube.com/watch?v=QnvircC22hU) explains some of the differences between these. it is a good point to start when selecting what kind to chose for your project.


<figure>
<img src="../../images/nano-ws2811led-5050-single_bb.png">
<figcaption> Wiring of a single SMD 5050 WS2811 module. </figcaption>
</figure>

### 5mm LEDs

The ws281X series of addressable LEDs with inbuilt control chips are available as 5mm LEDs. They look similar to older LEDs, but work differently. In Sweden you can get these kind of LEDs from [pchbutik](https://pchbutik.se/komponenter/197-10-st-8-mm-led-med-inbyggt-ws2811-chip-rgb-pixel-rod-gr-n-bla.html?search_query=RGB&results=12) at about 0.50 USD each.

<figure>
<img src="../../images/WS2811_5mm.jpg">
<figcaption> Single ws2811 LED. The wiring is only indicative, different brands can have different wiring. </figcaption>
</figure>

Wiring and sketching for a [single ws2811 LED](https://www.espruino.com/WS2811).
