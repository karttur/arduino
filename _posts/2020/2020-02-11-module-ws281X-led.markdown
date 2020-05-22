---
layout: post
title: SMD 5050 Programmable RGB LED
categories: module
excerpt: "Modules with WS2811/WS2812/WS2812B/APA104/APA106/SK6812 5050 programmable rgb LED"
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
component: component-ws281X-led
project: project-ws281X-led
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

Programmable LEDs come in many different module forms - strings, matrices like Adafruit's NeoPixels or the RGB123, or even 5mm LEDs. Note that while physically different (some are built into LEDs, some are separate chips), the WS2811/WS2812/WS2812B/APA104/APA106/SK6812 all work the same way electrically. The Youtube [LED Strips, what's the difference](https://www.youtube.com/watch?v=QnvircC22hU) explains some of the differences between these. It is a good starting point when selecting what kind to chose for your project. If you prefer reading, try the page [LED strip lights - everything you need to know before you buy](https://www.waveformlighting.com/led-strip-lights).

I am primarily interested in using programmable LEDs as a light source for a handheld spectrometer, and that only requires a single LED. The versions I have tested include 5 mm encapsulated LEDs, a breakout board, and a strip that I cut into single units.

### KY-009 3-color full-color LED SMD

The simplest modules only contain a single [SMD 5050 RGB component](../../components/component-SMD-5050-RGB) with connection points for red (R), green (G) and blue (B), plus ground (- or GND). For this kind of module you have to connect three separate and individually controlled power wires, including resistors for each.

The [KY-009 3-color full-color LED SMD module](https://tkkrlab.nl/wiki/Arduino_KY-009_3-color_full-color_LED_SMD_modules) component represent the simplest kind of module, where you have to [wire using separate and individual power, with resistors on each power](../../projects/project-rgb-led/).

### 8 mm LEDs

The ws281X series of addressable LEDs with inbuilt control chips are available as 8 mm LEDs. They look similar to older LEDs, but work differently. In Sweden you can get these kind of LEDs from [pchbutik](https://pchbutik.se/komponenter/197-10-st-8-mm-led-med-inbyggt-ws2811-chip-rgb-pixel-rod-gr-n-bla.html?search_query=RGB&results=12) at about 0.50 USD each.

<figure>
<img src="../../images/WS2811_8mm_frosted_led.png">
<figcaption> Single ws2811 8 mm LED. The wiring is only indicative, different brands can have different wiring. </figcaption>
</figure>

### Breakout board

The breakout board is more expensive (at least in Sweden, where [pchbutik](https://pchbutik.se/nytt-pa-lager/1103-ws2812-rgb-led-breakout-.html?search_query=WS2812&results=12) sells them at about 3 USD each).

<figure>
<img src="../../images/ws2811_breakout-board.png">
<figcaption> Single ws2811 LED as a breakout board module. </figcaption>
</figure>

### LED strip

LED strips are produced by a range of vendors and offered in many different versions. Usually the strips have either 30 or 60 LEDs per 100 cm. The number of LEDs naturally affect the power requirements and different strips have different solutions. Selecting a strip this requires careful consideration in order to get what you want. For use with Arduino you want strips that operate on 5 V. Some strips are encased and waterproof, other are not. In Sweden [Elfa](https://www.elfa.se) offers a wide range of LED strips.

<figure>
<img src="../../images/ws2811_led-strip.png">
<figcaption> LED strip with SMD 5050 LEDs. </figcaption>
</figure>
