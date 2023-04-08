---
layout: post
title: Arduinojson
categories: ide
excerpt: "Arduinojson"
tags:
  - Arduino IDE
  - arduinojson

image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-10-31 11:27'
modified: '2022-10-31 T12:17:25.000Z'
comments: true
share: true
---

## Introduction

[Arduinojson](https://arduinojson.org) is a library for serialization and deserialization of json structured documents in Arduino IDE. This post outlines how to install and use [Arduinojson](https://arduinojson.org). The post also contains the complete json code for [version 0.78 of xSpectre handheld spectrometer](https://karttur.github.io/arduino/spectrolum/spectrolum-v078-summary/).

## Arduinojson

[Arduinojson](https://arduinojson.org) is an evolving project and widely used as a standard container for transferring data to and from Arduino microcontrollers. When receiving data to the Arduino microcontroller, arduinojson deserializes the content to ordinary data and when packaging data for sending from the microcontroller, arduinojson serializes the data.

### Add Arduinojson library

Open <span class='app'>Arduino IDE</span>, from the menu select:

<span class='menu'>Tools -> Manage Libraries...</span>

Type _arduinojeson_ in the <span class='searchbox'>search box</span>. The json library you want to install is the one by Benoit Blanchon, _Arduinojson_. At time of writing this in October 2022 the version available is 6.19.4. Go ahead and <span class='button'>install</span>. Accept to install additional libraries required.

### Deserialize (decode) json

Start a new Arduino IDE sketch and import _Arduinojson_.

```
/*
 Test for json handling in Arduino using Arduinojson
 Thomas Gumbricht 28 October 2022
 *
 */

#include <ArduinoJson.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
```

Arduino JSON uses a preallocated memory pool to store the JsonObject tree, this is done by the _StaticJsonBuffer_. You can use [ArduinoJson Assistant](https://arduinojson.org/v6/assistant/#/step1) to compute the exact buffer size, but for this example 200 is enough.

```
StaticJsonBuffer<200> jsonBuffer;
```

Create a char array called _json[]_ to store a sample JSON string, you have to escape ("/") for passing the syntax demands of both Arduino and Arduinojson:

```
StaticJsonBuffer<200> jsonBuffer;
char json[] = "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

JsonObject& root = jsonBuffer.parseObject(json);

if(!root.success()) {
  Serial.println("parseObject() failed");
  return false;
}

const char* sensor = root["sensor"];
long time = root["time"];
double latitude = root["data"][0];
double longitude = root["data"][1];
```
