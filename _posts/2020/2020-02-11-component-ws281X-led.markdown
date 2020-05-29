---
layout: post
title: SMD 5050 Programmable RGB LED
categories: component
excerpt: "WS2811/WS2812/WS2812B/APA104/APA106/SK6812 5050 programmable rgb LED"
tags:
  - LED
  - RGB
  - ws2811
  - ws2812
  - ws2813
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-11 11:27'
modified: '2020-02-11 T18:17:25.000Z'
comments: true
share: true
module: module-ws281X-led
project: project-ws281X-led
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

These [SMD 5050](https://www.tweaking4all.com/wp-content/uploads/2014/01/5050LED.pdf) components are individually addressable RGB LEDs - this means with just 3 wires, you can make each LED turn any one of 16 million colours. There a many different versions: WS2811/WS2812/WS2812B/APA104/APA106/SK6812, but all work the same way electrically. [Espruino](https://www.espruino.com/WS2811) have a short introduction to programmable LEDs. The Youtube [LED Strips, what's the difference](https://www.youtube.com/watch?v=QnvircC22hU) is more in depth and explains some of the differences between the listed components. It is a good point to start when selecting what kind to chose for your project. At [Alibaba ](https://www.alibaba.com/product-detail/wholesales-sk6812-ws2812-ws2812b-ws2811-5050_60666639287.html) you can get the components at 0,02 US$ - 0,10 US$ a piece.

<figure>
<img src="../../images/ws2812_component.png">
<figcaption> Single ws2812 LED component. </figcaption>
</figure>

### Dimming

LED light (and ELD strips) are not dimmable in the conventional sense. Attempting to vary the brightness of the LEDs by changing the external voltage is impractical. However, they can be dimmed using pulse-width modulation (PWM) dimmers. These rapidly switch the LEDs on and off, typically 500 times per second, by changing the voltage from zero to the expected value as a square wave. The relative width of the on and off portions of the square wave can be varied so that the LEDs are on or off for relatively more or less time to change brightness. Addressable LEDs (as in LED strips) do this dimming internally given a data signal with colour intensity information, while non-addressable LEDs require an external PWM controller to be dimmed.

Whether the PWM dimming is useful for adjusting the illumination for a spectrometer remains to be determined.
