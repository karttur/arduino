---
layout: post
title: Programmable rgb LED
categories: project
excerpt: "Wire and sketch project for WS2811/WS2812/WS2812B/APA104/APA106/SK6812 5050 programmable rgb LED"
tags:
  - LED
  - RGB
  - ws2811
  - wire
  - sketch
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-11 11:27'
modified: '2020-02-12 T18:17:25.000Z'
comments: true
share: true
component: component-ws281X-led
module: module-ws281X-led
project: null
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>
### Introduction

The [LED components](../../component/component-ws281X-led) S2811/WS2812/WS2812B/APA104/APA106/SK6812 are available both as a single components, as modules with a single component, or as LED strips or matrices. They are very common. This post only shows how to wire a single LED.

### Wiring of single LED

 The figures below illustrate how to wire single LED modules. As all SMD 5050 components have the same controller chips, the sketches should work for all components/modules.

<figure>
<img src="../../images/nano-ws2811-rgbled-single-5mm_bb.png">
<figcaption> Breadboard wiring of a single SMD 5050 WS2811 component. </figcaption>
</figure>

<figure>
<img src="../../images/nano-ws2811-rgbled-single-5mm-breadfree_bb.png">
<figcaption> Direct wiring of a single SMD 5050 WS2811 component. </figcaption>
</figure>

<figure>
<img src="../../images/nano-ws2811led-5050-single_bb.png">
<figcaption> Wiring of a single SMD 5050 WS2811 module. </figcaption>
</figure>


The sketch under the "Hide/Show" button works for all of the above wirings. The sketch is written for testing the amount of reflected (emitted) light in different wavelengths.

<button id= "toggleFastLED" onclick="hiddencode('FastLED')">Hide/Show sketch</button>

<div id="FastLED" style="display:none">
{% capture text-capture %}
{% raw %}
```
// Code for controlling single WS2812 LED, looping brightness for red, green, blue, yellow and white light
// Written By Thomas Gumbricht, Karttur AB

#include "FastLED.h"

#define DATA_PIN 7
#define LED_TYPE WS2812
#define COLOR_ORDER RGB
#define NUM_LEDS 1
#define BRIGHTNESS 120

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  delay(1000); // initial delay is recommended
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
  FastLED.setBrightness(BRIGHTNESS);// global brightness
}

void loop() {

    // Loop red exponential brightness
  Serial.println();
  for (int x = 32; x <= 256; x = x * 2) {
    Serial.print("Red:"); Serial.println(x-1);
    FastLED.setBrightness(x-1);
    //leds[0] = CRGB::Red;
    leds[0] = CRGB( 255, 0, 0);
    FastLED.show();
    delay(500);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(100);
  }

  // Loop green exponential brightness
  Serial.println();
  for (int x = 32; x <= 256; x = x * 2) {
    Serial.print("Green:"); Serial.println(x-1);
    FastLED.setBrightness(x-1);
    //leds[0] = CRGB::Green;
    leds[0] = CRGB( 0, 255, 0);
    FastLED.show();
    delay(500);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(100);
  }

  // Loop blue exponential brightness
  Serial.println();
  for (int x = 32; x <= 256; x = x * 2) {
    Serial.print("Blue:"); Serial.println(x-1);
    FastLED.setBrightness(x-1);
    //leds[0] = CRGB::Blue;
    leds[0] = CRGB( 0, 0, 255);
    FastLED.show();
    delay(500);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(100);
  }

  // Loop yellow exponential brightness
  Serial.println();
  for (int x = 32; x <= 256; x = x * 2) {
    Serial.print("Yellow:"); Serial.println(x-1);
    FastLED.setBrightness(x-1);
    //leds[0] = CRGB::Yellow;
    leds[0] = CRGB( 255, 255, 0 );
    FastLED.show();
    delay(500);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(100);
  }

  // Loop white expontential brightness
  Serial.println();
  for (int x = 32; x <= 256; x = x * 2) {
    Serial.print("White:"); Serial.println(x-1);
    FastLED.setBrightness(x-1);
    //leds[0] = CRGB::White;
    leds[0] = CRGB( 255, 255, 255 );
    FastLED.show();
    delay(500);
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(100);
  }

}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>
