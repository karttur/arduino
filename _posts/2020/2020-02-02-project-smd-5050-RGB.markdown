---
layout: post
title: SMD 5050 RGB modules
categories: project
excerpt: "modules built on the SMD 5050 RGB modules"
tags:
  - RGB
  - LED
  - SMD 5050 RGB
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-02 11:27'
modified: '2020-02-02 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

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
