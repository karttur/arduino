---
layout: post
title: SHTxy moisture and temperature project
categories: project
excerpt: "SHT1x and SHT3x moisture and temperature project"
tags:
  - SHT10
  - SHT30
  - DS18B20
  - temperature
  - humidity
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-16 11:27'
modified: '2020-02-16 T18:17:25.000Z'
comments: true
share: true
sensor: sensor-SHTXY-moisture-temp
module: module-SHTXY-moisture-temp
project: null
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

The SHTxy series of digital humidity and temperature sensors from [Sensirion](https://www.sensirion.com) are high quality and available for Arduino as integrated breakout boards from various producers.

#### Wiring

[SHT1x modules](../../modules/module-SHTXY-moisture-temp) have four wires: power or VCC (red), ground or GND (green), data or DI (blue) and SCK or clock (yellow). You need to put a 1 kOhm pull-up resistor between power and data (red and blue).

<figure>
<img src="../../images/nano-SHT10-waterproof-cable_bb.png">
<figcaption> Wiring of the SHT1x moisture and temperature sensor. The pull-up resistor is 1 kOhm.
</figcaption>
</figure>

#### Sketch

The easiest way to get sketch your SHT1x sensor is by using the [_SHT1x.h_ library](https://github.com/practicalarduino/SHT1x) from GitHub. Download the GitHub fodler with library as a zip file. Unzip and rename the exploded directory to _SHT1x_ (it probably arrived as _SHT1x-master_), and move it to the <span class='file'>documents/arduino/libraries</span> directory (if you installed Arduino using default setting this is under your personal folder "~"). Move the whole folder.

<button id= "toggleSHT1x" onclick="hiddencode('SHT1x')">Hide/Show sketch</button>

<div id="SHT1x" style="display:none">
{% capture text-capture %}
{% raw %}

```
#include <SHT1x.h>

// Specify data and clock connections and instantiate SHT1x object
#define dataPin  10
#define clockPin 11
SHT1x sht1x(dataPin, clockPin);

void setup()
{
   Serial.begin(9600); // Open serial connection to report values to host
   Serial.println("Starting up");
}

void loop()
{
  float temp_c;
  float temp_f;
  float humidity;

  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  temp_f = sht1x.readTemperatureF();
  humidity = sht1x.readHumidity();

  // Print the values to the serial port
  Serial.print("Temperature: ");
  Serial.print(temp_c, DEC);
  Serial.print("C / ");
  Serial.print(temp_f, DEC);
  Serial.print("F. Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

### Project with pin power

An alternative wiring is to put the power supply on a digital pin, allowing turning the power to the sensor on/off.

<figure>
<img src="../../images/nano-SHT10-waterproof-cable_v2_bb.png">
<figcaption> Wiring of the SHT1x moisture and temperature sensor using pin D7 for on/off power setting. The pull-up resistor is 1 kOhm. The wiring is set to pass through a 4-pin connector, that can also hold other sensors, and thus includes redundant pins.
</figcaption>
</figure>

<button id= "toggleCapSMpowerD7" onclick="hiddencode('CapSMpowerD7')">Hide/Show sketch</button>

<div id="CapSMpowerD7" style="display:none">
{% capture text-capture %}
{% raw %}

```

#include <SHT1x.h>

// Specify data and clock connections and instantiate SHT1x object
int probePowerPin = 7;
#define dataPin  2
#define clockPin 8

SHT1x sht1x(dataPin, clockPin);

void setup()
{
   Serial.begin(9600); // Open serial connection to report values to host
   Serial.print("Starting up sht mositure+temperature ");
   pinMode (probePowerPin, OUTPUT); // define the digital output
}

void loop()
{
  float temp_c;
  float temp_f;
  float humidity;

  digitalWrite (probePowerPin, HIGH); // Turn sensor On

  // Read values from the sensor
  temp_c = sht1x.readTemperatureC();
  temp_f = sht1x.readTemperatureF();
  humidity = sht1x.readHumidity();

  // Print the values to the serial port
  Serial.print("Temperature: ");
  Serial.print(temp_c, DEC);
  Serial.print("C / ");
  Serial.print(temp_f, DEC);
  Serial.print("F. Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>
