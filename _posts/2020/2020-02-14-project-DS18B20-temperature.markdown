---
layout: post
title: DS18B20 temperature
categories: project
excerpt: "Wiring and scripts for the DS18B20 temperature sensor"
tags:
  - temperature
  - sensor
  - DS18B20
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-14 11:27'
modified: '2020-02-14 T18:17:25.000Z'
comments: true
share: true
component: null
sensor: sensor-DS18B20-temperature
module: module-DS18B20-temperature
project: null
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

The DS18B20 digital thermometer provides 9-bit to 12-bit Celsius temperature measurements and has an alarm function with nonvolatile user-programmable upper and lower trigger points. The DS18B20 communicates over a 1-Wire bus that by definition requires only one data line (and ground) for communication with a central microprocessor. In addition, the DS18B20 can derive power directly from the data line (“parasite power”), eliminating the need for an external power supply. [Datasheet](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf).

### Wiring

Below are two different wirings, with a breakout board including the pull-up resistor, and with the pull up resistor added. The sketch is the same for both wiring alternatives.

#### KY-001

The [KY-001 Arduino Temperature Module](http://www.mikroblog.net/37-sensor-kit/ky-001-temperature-sensor-module.php) has a built-in pull-up resistor and you can wire it directly to the 5 volt power supply as shown below.

<figure>
<img src="../../images/nano-DS18B20-ky001_bb.png">
<figcaption> Wiring of the KY-001 Arduino module with the DS18B20 temperature sensor. </figcaption>
</figure>

### Waterproof and cabled

If your module lacks the pull-up resistor you must put a 4.7 kOhm resistore between the %v poser and the data cable, as shown in the sketch below.

<figure>
<img src="../../images/nano-DS18B20-waterproof-cable_bb.png">
<figcaption> Wiring of the waterproof and encased DS18B20 temperature sensor, the wiring must include the pull-up resistor of 4.7 kOhm. </figcaption>
</figure>

### Sketch

The sketch includes two libraries: _OneWire.h_ and _DallasTemperature.h_. You need to install both to your library as explained in the official Arduino page on [Installing Additional Arduino Libraries](https://www.arduino.cc/en/guide/libraries). In this version I have put the analog sensor signal on port A1.

<button id= "toggleDS18B20" onclick="hiddencode('DS18B20')">Hide/Show sketch</button>

<div id="DS18B20" style="display:none">
{% capture text-capture %}
{% raw %}

```
/********************************************************************/
// First we include the libraries
#include <OneWire.h>
#include <DallasTemperature.h>
/********************************************************************/
// Data wire is plugged into pin 1 on the Arduino
#define ONE_WIRE_BUS 1
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
/********************************************************************/
void setup(void)
{
 // start serial port
 Serial.begin(9600);
 Serial.println("Dallas Temp. IC Control Library Demo");
 // Start up the library
 sensors.begin();
}
void loop(void)
{
 // call sensors.requestTemperatures() to issue a global temperature
 // request to all devices on the bus
/********************************************************************/
 Serial.print(" Requesting temp...");
 sensors.requestTemperatures(); // Send the command to get temperature readings
 Serial.println("DONE");
/********************************************************************/
 Serial.print("Temp (C) is: ");
 Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire
   delay(1000);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>
