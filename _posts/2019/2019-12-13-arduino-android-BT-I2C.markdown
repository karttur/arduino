---
layout: post
title: Bluetooth
categories: project
excerpt: " Arduino Bluetooth setup"
tags:
  - arduino IDE
  - Bluetooth
  - IPC
  - reading data
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-11-10 11:27'
modified: '2019-11-10 T18:17:25.000Z'
comments: true
share: true
---

## Introduction

This post explains how to receive data from an arduino over Bluetooth.

## Yotube instruction

I started out with this [Youtube instructable](https://www.youtube.com/watch?v=JQ3tDhpmSFE)


https://www.youtube.com/watch?v=JQ3tDhpmSFE

### Sketch

```
#define ledPin 7

int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    state = Serial.read();
  }
  if (state == '0') {
    digitalWrite(ledPin, LOW);
    Serial.println("LED: OFF");
    state = 0;
  }
  else if (state =='1') {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED: ON");
    state = 0;
  }
}
```
