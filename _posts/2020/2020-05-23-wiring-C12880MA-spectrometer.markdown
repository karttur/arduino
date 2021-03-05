---
layout: post
title: Hamamatsu C12880MA spectrometer wiring
categories: project
excerpt: "Hamamatsu C12880MA miniaturised 288 band sensor"
tags:
  - spectrometer
  - Sensors
  - Hamamatsu
  - C12880MA
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-05-23 11:27'
modified: '2021-01-06 T18:17:25.000Z'
comments: true
share: true
component: null
sensor: sensor-C12880MA-spectrometer
module: module-C12880MA-spectrometer
project: null
projectuno: null
---

### Introduction

The breakout out boards by ??? are constructed to fit directly to the pins of an Arduino UNO board. No need even to put a single wire.


### Internal wiring

Pdf document for [GroupGets C12880MA Breakout Board](https://groupgets-files.s3.amazonaws.com/hamamatsu/uspectrometer/C12880MA%20Breakout%20Board%20-%20Datasheet%20-%201.1.pdf).

### mbed

[mbed code](https://os.mbed.com/users/mikehogan62/code/Hamamatsu_C12880MA/) but I have no idea how to get it started.

### impfs.github.io/review/

[Review of Hamamastu C128880 Microspec Module](https://impfs.github.io/review/), including firmware and python piloting code. This study is also highlighted in an article: [Researchers develop a low-cost setup for Hamamatsu’s micro-spectrometer](https://www.laserfocusworld.com/home/article/16546371/researchers-develop-a-lowcost-setup-for-hamamatsus-microspectrometer)

#### Firmware

The [firmware at impfs.github.io/](https://github.com/open-eio/arduino-microspec/tree/master/microspec) consists of 3 parts plus a python module.

- c12880.cpp (Source file for the Arduino library)
- c12880.h (Header file for Arduino library)
- microspec.ino (the native Arduino script)
- test.py (the python module)

In your default Arduino folder (usually under ~user/documents/arduino), create a new folder called <span class='file'>microspec</span>. Copy the file <span class='file'>microspec.ino</span> into the newly created directory.

The library files (<span class='file'>c12880.h</file> and <span class='file'>c12880.cpp</file>) should be accessible from inside the  <span class='file'>microspec</span> diretory, but I prefer to put them under the <span class='file'>library</span> directory inside  ~user/documents/arduino. Thus go the Arduino <span class='file'>library</span> foder and crate a new sub-directory called <span class='file'>c12880</span>. Copy the two library files to this library directory.

The firmware also requires a custom built version of SerialCommand, available at [github.com/p-v-o-s](https://github.com/p-v-o-s/Arduino-SerialCommand). This version is a fork of the more widely used [kroimon version of SeriealCommand](https://github.com/kroimon/Arduino-SerialCommand) by Stefan Rado. You then also need to install [elapsedMillis](https://github.com/pfeerick/elapsedMillis)

Download the SerialCommand version via the url above and put it in your library file. Then start the library manager

<span class='menu'>Tools -> Manage Libraries...</span>

Install _elapsedMillis_ via the Library tool, and the library will be automatically updated, including for the version of SerialCommand that you copied in place.

#### Compatible boards

The [microspec](https://github.com/open-eio/arduino-microspec/) firmware is not compatible with the standard Arduino boards (UNO, Nano), but requires later generation boards. Compatible boards include:

- Arduino MO
- Arduino Nano 33 IoT
- Arduino mkr wifi 1010
- [Adafruit Feather](https://www.adafruit.com/feather)


### Simple Arduino Sketch

This sketch is available from [GroupGets](https://groupgets.com) repo on [GitHub](https://github.com) called [c12880ma](https://github.com/groupgets/c12880ma). It works directly with an [Arduino Uno](https://store.arduino.cc/arduino-uno-rev3) board.

```
/*
 * Macro Definitions
 */
#define SPEC_TRG         A0
#define SPEC_ST          A1
#define SPEC_CLK         A2
#define SPEC_VIDEO       A3
#define WHITE_LED        A4
#define LASER_404        A5

#define SPEC_CHANNELS    288 // New Spec Channel
uint16_t data[SPEC_CHANNELS];

void setup(){

  //Set desired pins to OUTPUT
  pinMode(SPEC_CLK, OUTPUT);
  pinMode(SPEC_ST, OUTPUT);
  pinMode(LASER_404, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);

  digitalWrite(SPEC_CLK, HIGH); // Set SPEC_CLK High
  digitalWrite(SPEC_ST, LOW); // Set SPEC_ST Low

  Serial.begin(115200); // Baud Rate set to 115200

}

/*
 * This functions reads spectrometer data from SPEC_VIDEO
 * Look at the Timing Chart in the Datasheet for more info
 */
void readSpectrometer(){

  int delayTime = 1; // delay time

  // Start clock cycle and set start pulse to signal start
  digitalWrite(SPEC_CLK, LOW);
  delayMicroseconds(delayTime);
  digitalWrite(SPEC_CLK, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(SPEC_CLK, LOW);
  digitalWrite(SPEC_ST, HIGH);
  delayMicroseconds(delayTime);

  //Sample for a period of time
  for(int i = 0; i < 15; i++){

      digitalWrite(SPEC_CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(SPEC_CLK, LOW);
      delayMicroseconds(delayTime);

  }

  //Set SPEC_ST to low
  digitalWrite(SPEC_ST, LOW);

  //Sample for a period of time
  for(int i = 0; i < 85; i++){

      digitalWrite(SPEC_CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(SPEC_CLK, LOW);
      delayMicroseconds(delayTime);

  }

  //One more clock pulse before the actual read
  digitalWrite(SPEC_CLK, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(SPEC_CLK, LOW);
  delayMicroseconds(delayTime);

  //Read from SPEC_VIDEO
  for(int i = 0; i < SPEC_CHANNELS; i++){

      data[i] = analogRead(SPEC_VIDEO);

      digitalWrite(SPEC_CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(SPEC_CLK, LOW);
      delayMicroseconds(delayTime);

  }

  //Set SPEC_ST to high
  digitalWrite(SPEC_ST, HIGH);

  //Sample for a small amount of time
  for(int i = 0; i < 7; i++){

      digitalWrite(SPEC_CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(SPEC_CLK, LOW);
      delayMicroseconds(delayTime);

  }

  digitalWrite(SPEC_CLK, HIGH);
  delayMicroseconds(delayTime);

}

/*
 * The function below prints out data to the terminal or
 * processing plot
 */
void printData(){

  for (int i = 0; i < SPEC_CHANNELS; i++){

    Serial.print(data[i]);
    Serial.print(',');

  }

  Serial.print("\n");
}

void loop(){

  readSpectrometer();
  printData();
  delay(10);  

}
```

Connect the simple skecth to python

<span class='terminal'>$ conda install -c anaconda pyserial</span>


Hamamatsu's [C12880MA ultra-compact spectrometer](https://www.hamamatsu.com/jp/en/product/type/C12880MA/index.html) has been tested in several studies, summarised here.

### Groupgets:

[C12880MA Breakout Board](https://groupgets.com/manufacturers/getlab/products/c12880ma-breakout-board) by GetLab.

[C12880MA Micro-Spectrometer](https://groupgets.com/manufacturers/hamamatsu-photonics/products/c12880ma-micro-spectrometer)

[Arduino code c12880ma by groupgets on GitHub](https://github.com/groupgets/c12880ma)

#### Groupgets github project for c12880ma

https://github.com/groupgets/c12880ma (the one used above)

[Review of Hamamastu C128880 Microspec Module](https://impfs.github.io/review/), including spectral analysis of liquids (drinks and oils).

[tindie C12666MA Micro-Spectrometer](https://www.tindie.com/products/GroupGets/c12880ma-mems-u-spectrometer-and-breakout-board/)
