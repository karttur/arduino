---
layout: post
title: ws2811 5050 programmable rgb LED
categories: projects
excerpt: "Wire and sketch for single ws2811 5050 programmable rgb LED"
tags:
  - LED
  - RGB
  - ws2811
  - wire
  - sketch
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-12 11:27'
modified: '2020-02-11 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>
### Introduction



### Wiring of single LED

The SMD 5050 component is available both as a single component, and module with a single component. The figures below illustrate how to wire these alternatives. As all SMD 5050 components have the same controller chips, all sketches work for all components and modules.

<figure>
<img src="../../images/nano-ws2811-rgbled-single-5mm_bb.png">
<figcaption> Wiring of a single SMD 5050 WS2811 component. </figcaption>
</figure>

<figure>
<img src="../../images/nano-ws2811led-5050-single_bb.png">
<figcaption> Wiring of a single SMD 5050 WS2811 module. </figcaption>
</figure>


The sketch under the "Hide/Show" button works for both of the above wirings.

<button id= "toggleFastLED" onclick="hiddencode('FastLED')">Hide/Show sketch</button>

<div id="FastLED" style="display:none">
{% capture text-capture %}
{% raw %}
```
// (c) Michael Schoeffler 2017, http://www.mschoeffler.de
#include "FastLED.h"

#define DATA_PIN 2
#define LED_TYPE WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS 1
#define BRIGHTNESS 120

CRGB leds[NUM_LEDS];

void setup() {
  delay(3000); // initial delay of a few seconds is recommended
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // initializes LED strip
  FastLED.setBrightness(BRIGHTNESS);// global brightness
}

// switches off all LEDs
void showProgramCleanUp(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(delayTime);
}

// switches on all LEDs. Each LED is shown in random color.
// numIterations: indicates how often LEDs are switched on in random colors
// delayTime: indicates for how long LEDs are switched on.
void showProgramRandom(int numIterations, long delayTime) {
  for (int iteration = 0; iteration < numIterations; ++iteration) {
    for (int i = 0; i < NUM_LEDS; ++i) {
      leds[i] = CHSV(random8(),255,255); // hue, saturation, value
    }
    FastLED.show();
    delay(delayTime);
  }
}

// Shifts a single pixel from the start of strip to the end.
// crgb: color of shifted pixel
// delayTime: indicates how long the pixel is shown on each LED
void showProgramShiftSinglePixel(CRGB crgb, long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    leds[i] = crgb;
    FastLED.show();
    delay(delayTime);
    leds[i] = CRGB::Black;
  }
}

// Shifts multiple pixel from the start of strip to the end. The color of each pixel is randomized.
// delayTime: indicates how long the pixels are shown on each LED
void showProgramShiftMultiPixel(long delayTime) {
  for (int i = 0; i < NUM_LEDS; ++i) {
    for (int j = i; j > 0; --j) {
      leds[j] = leds[j-1];
    }
    CRGB newPixel = CHSV(random8(), 255, 255);
    leds[0] = newPixel;
    FastLED.show();
    delay(delayTime);
  }
}

// main program
void loop() {
  showProgramCleanUp(2500); // clean up
  showProgramRandom(100, 100); // show "random" program

  showProgramCleanUp(2500); // clean up
  showProgramRandom(10, 1000); // show "random" program

  showProgramCleanUp(2500); // clean up
  showProgramShiftSinglePixel(CRGB::Blue, 250); // show "shift single pixel program" with blue pixel

  showProgramCleanUp(2500); // clean up
  showProgramShiftSinglePixel(CRGB::Maroon, 100); // show "shift single pixel program" with maroon pixel

  showProgramCleanUp(2500); // clean up
  showProgramShiftMultiPixel(500); // show "shift multi pixel" program

  showProgramCleanUp(2500); // clean up
  showProgramShiftMultiPixel(50); // show "shift multi pixel" program
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>
