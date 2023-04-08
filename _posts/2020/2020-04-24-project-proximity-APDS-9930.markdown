---
layout: post
title: APDS-9930 Digital Proximity and Ambient Light Sensor
categories: project
excerpt: "Digital Proximity and Ambient Light Sensor"
tags:
  - distance
  - ambient light
  - APDS-9930
  - adafruit
  - polulu
  - sparkfun
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-04-24 11:27'
modified: '2020-04-24 T18:17:25.000Z'
comments: true
share: true
component: null
sensor: sensor-proximity-APDS-9930
module: module-proximity-APDS-9930
project: project-proximity-APDS-9930-nano
---

### Introduction

This project page on the [diymore APDS-9930 Digital Proximity and Ambient Light Sensor](../../sensor/sensor-proximity-APDS-9930) is built from the [Arduinolearning library post]
(http://arduinolearning.com/code/arduino-apds-9930-sensor-example.php). Most other wiring pages relate to the APDS-9960 module, including this [youtube instruction](https://www.youtube.com/watch?v=qzSgZV_fbxI).

The more advanced PDS-9930 version is presented in a video from [sparkfun](https://learn.sparkfun.com/tutorials/apds-9960-rgb-and-gesture-sensor-hookup-guide/all).

The PDS-9930 requires an input voltage of between 2.2 to 3.6 volt, with 3.0 the nominal requirement.

The wiring online is not correct, If you get random numbers from the proximuty sensor [some suggest that you need to put 3.3 vlot to the VL pin](https://github.com/Depau/APDS9930/issues/7). Doing that I got = on all trials with the distance sensor.

The library is no logner maintaied, but available at
[github](https://github.com/Davideddu/APDS9930)
<figure>
<img src="../../images/nano-APDS-9930_bb.png">
<figcaption> Wiring for the APDS-9930 Digital Proximity and Ambient Light Sensor. </figcaption>
</figure>

<figure>
<img src="../../images/nano-APDS-9930_breadfree_bb.png">
<figcaption> Wiring for the APDS-9930 Digital Proximity and Ambient Light Sensor. </figcaption>
</figure>

### Sketch

<button id= "toggleAPDS-9930" onclick="hiddencode('APDS-9930D')">Hide/Show sketch</button>

<div id="APDS-9930" style="display:none">
{% capture text-capture %}
{% raw %}
```
/****************************************************************

 Arduino Pin  APDS-9930 Board  Function

 3.3V         VCC              Power
 GND          GND              Ground
 A4           SDA              I2C Data
 A5           SCL              I2C Clock
****************************************************************/

#define DUMP_REGS

#include <Wire.h>
#include <APDS9930.h>

// Global Variables
APDS9930 apds = APDS9930();
float ambient_light = 0; // can also be an unsigned long
uint16_t ch0 = 0;
uint16_t ch1 = 1;

void setup()
{

  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();

  // Initialize APDS-9930 (configure I2C and initial values)
  if ( apds.init() )
  {
    Serial.println(F("APDS-9930 initialization complete"));
  }
  else
  {
    Serial.println(F("Something went wrong during APDS-9930 init!"));
  }

  // Start running the APDS-9930 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) )
  {
    Serial.println(F("Light sensor is now running"));
  }
  else
  {
    Serial.println(F("Something went wrong during light sensor init!"));
  }

  // Wait for initialization and calibration to finish
  delay(500);
}


void loop()
{

  // Read the light levels (ambient, red, green, blue)
  if (  !apds.readAmbientLightLux(ambient_light) ||
        !apds.readCh0Light(ch0) ||
        !apds.readCh1Light(ch1) ) {
    Serial.println(F("Error reading light values"));
  }
  else
  {
    Serial.print(F("Ambient: "));
    Serial.print(ambient_light);
    Serial.print(F("  Ch0: "));
    Serial.print(ch0);
    Serial.print(F("  Ch1: "));
    Serial.println(ch1);
  }

  // Wait 1 second before next reading
  delay(1000);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>
