---
layout: post
title: AMS AS726X spectrometer (nano)
categories: project
excerpt: "Wiring up the AMD as726x spectrometer with Arduino nano"
tags:
  - arduino
  - spectrometer
  - wiring
  - sketch
  - I2C
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-10-20 11:27'
modified: '2020-01-24 T18:17:25.000Z'
comments: true
share: true
component: null
sensor: sensor-AS726X-spectrometer
module: module-AS726X-spectrometer
project: project-AS726X-spectrometer-nano
projectuno: project-AS726X-spectrometer-uno
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>
### Introduction

This small "project" post covers how to wire an integrated module with the [AMS AS72Sx 6 channel broad band spectrometer](../../modules/module-AS726X-spectrometer/) to an Arduino UNO nano. The project post on [Arduino UNO](../project-AS726X-spectrometer-uno) contains more information.

#### The I2C communication bus

The spectrometer sends data for 6 (12 or 18) spectral bands using the [I2C communication bus](../../ide/ide-I2C).

#### Preparing the Arduino IDE

Arduino nano uses A4 and A5 for I2C connections as outlined in [this GitHub repo](https://github.com/felias-fogg/SoftI2CMaster/blob/master/README.md),

### Adafruit or sparkfun

Breakout boards with the AMD AS72Sx sensor(s) are offered both by [Adafruit](../../components/components-adafruit/) and [Sparkfun](../../components/components-sparkfun-spectrometer/). Sparkfun is easier to work with if you use their [Qwiic](https://www.sparkfun.com/qwiic) connect system for I2C devices. You can then use the [Qwiic Cable - Breadboard Jumper (4-pin)](https://www.sparkfun.com/products/14425) for connecting the spectrometer to the board. If you use the Adafruit spectrometer you have to solder the breakout board.

### Wiring

The wiring is (almost) the same regardless if you use the Adafruit or Sparkfun breakout boards. The Adafruit manual is [here](https://learn.adafruit.com/adafruit-as7262-6-channel-visible-light-sensor?view=all).

The difference between Adafruit and Sparkfun is that the Sparkfun breakout board requires 3.3 v power, whereas the Adafruit breakout board can be powered with either 3.3 or 5 v. The Adafruit breakout board also has an additional light source that must be individually wired.

<figure>
<img src="../../images/sparkfun-AS726Xx-nano-breadfree_bb.png">
<figcaption> Wiring an AS726x 6-channel spectrometer. The Adafruit breakout board can be powered with either 3.3 or 5 v (as shown), whereas the Sparkfun board only have a connection for 3.3 v.</figcaption>
</figure>

#### Sketch

The sketch below works both with the Adafruit and Sparkfun breakout boards.

<button id= "toggleAS7262_01" onclick="hiddencode('AS7262_01')">Hide/Show sketch</button>

<div id="AS7262_01" style="display:none">
{% capture text-capture %}
{% raw %}

```
/******
  Sketch for the AS7262 6-Channel Visible Light Sensor

  This sketch is a slight modification of the
  adafruit original sketch. The sketch also works for the Sparkfun AS726x breakout board.

  These sensors use I2C to communicate. The device's I2C address is 0x49
 ******/

#include <Wire.h>
#include "Adafruit_AS726x.h"

//create the object
Adafruit_AS726x ams;

//buffer to hold raw values
uint16_t sensorValues[AS726x_NUM_CHANNELS];

//buffer to hold calibrated values (not used by default in this example)
//float calibratedValues[AS726x_NUM_CHANNELS];

void setup() {
  Serial.begin(9600);
  while(!Serial);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  //begin and make sure we can talk to the sensor
  if(!ams.begin()){
    Serial.println("could not connect to sensor! Please check your wiring.");
    while(1);
  }
}

void loop() {

  //read the device temperature
  uint8_t temp = ams.readTemperature();

  ams.drvOn(); //uncomment this if you want to use the driver LED for readings
  ams.startMeasurement(); //begin a measurement

  //wait till data is available
  bool rdy = false;
  while(!rdy){
    delay(5);
    rdy = ams.dataReady();
  }
  ams.drvOff(); //uncomment this if you want to use the driver LED for readings

  //read the values!
  ams.readRawValues(sensorValues);
  //ams.readCalibratedValues(calibratedValues);

  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" Violet: "); Serial.print(sensorValues[AS726x_VIOLET]);
  Serial.print(" Blue: "); Serial.print(sensorValues[AS726x_BLUE]);
  Serial.print(" Green: "); Serial.print(sensorValues[AS726x_GREEN]);
  Serial.print(" Yellow: "); Serial.print(sensorValues[AS726x_YELLOW]);
  Serial.print(" Orange: "); Serial.print(sensorValues[AS726x_ORANGE]);
  Serial.print(" Red: "); Serial.print(sensorValues[AS726x_RED]);
  Serial.println();
  Serial.println();
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>
