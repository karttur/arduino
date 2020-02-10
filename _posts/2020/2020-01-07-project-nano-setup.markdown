---
layout: post
title: Arduino Nano project preparation
categories: projects
excerpt: "Prepare Arduino for Nano board project"
tags:
  - arduino IDE
  - setup
  - Mac OSX
  - Nano
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-07 11:27'
modified: '2020-01-07 T18:17:25.000Z'
comments: true
share: true
---

## Introduction

Building a "stand alone" Arduino project in most cases also equals changing from a large Arduino board (e.g. Uno) to a smaller board like [Nano](https://store.arduino.cc/arduino-nano) or [Pro Micro]. Other companies produce Arduino compatible boards that are as small, or smaller, and that also contain some built in features. But let us save that for a later post. In this post you will use an Arduino Nano board as that is almost like a smaller version of the Uno board.

## Setup Arduino IDE for Arduino Nano

When you did setup <span class='app'>Arduino IDE</span> the first time you probably did choose a board - usually Uno, from the menu:

<span class='menu'>Tools -> Board</span>

Change the _Board_ to _Nano_ as illustrated in the figure.

<figure>
<img src="../../images/arduino-nano-setup_01.png">
<figcaption> Change to the Nano board in the Arduino IDE.</figcaption>
</figure>

Then you also have to give the usb-port to which you have connected your Arduino Nano, also done from the menu:

<span class='menu'>Tools -> Port</span>

<figure>
<img src="../../images/arduino-nano-setup_02.png">
<figcaption> Change connection port in the Arduino IDE.</figcaption>
</figure>

There are different versions available for both the <span class='app'>Arduino IDE</span> and the Nano board. You have to make sure that you have the correct Processor set. The version of the <span class='app'>Arduino IDE</span> at time of writing this (January 2020) has the _ATmega328P_ as default _Processor_ (in Nano boards from 2018 or newer); for older boards you need to set the _Processor_ to  _ATmega328P (Old Bootloader)_:

 <span class='menu'>Tools -> Processor</span>

 <figure>
 <img src="../../images/arduino-nano-setup_03.png">
 <figcaption> Change Processor for the Nano board in the Arduino IDE.</figcaption>
 </figure>

## Test board connection

As you have different options regarding the <span class='app'>Arduino IDE</span>, the Processor on the Nano and probably more than one USB port on you computer you might have to do a bit of trial error before getting it all correctly setup. Below is a simple sketch to use for trying your connection setup. Attach a led to pin _D7_ and another to ground (GND) on your Arduino Nano board. If you use a standard LED, the longer leg should be connected to _D7_ (positive), and you should use a 220 Ohm resistor. But you can skip the latter if you are only going to try the connection.

<figure>
<img src="../../images/nano-single-led-d7_bb.png">
<figcaption> Wiring for testing the connection to an Arduino Nano Board.</figcaption>
</figure>

```

int ledPin = 7;  

void setup() {
  // put your setup code here, to run once:

pinMode(ledPin, OUTPUT);      // sets the digital pin as output

}

void loop() {

  digitalWrite(ledPin, HIGH);   // sets the LED on
  delay(1000);                  // waits for a second
  digitalWrite(ledPin, LOW);    // sets the LED off
  delay(1000);                  // waits for a second

}
```

## My settings

This is how I got my older Nano board to connect using the USB port on the right side of my Macbook Air 2017.

<figure>
<img src="../../images/arduino-nano-setup_04.png">
<figcaption> Change to the Nano board in the Arduino IDE.</figcaption>
</figure>
