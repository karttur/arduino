---
layout: post
title: Arduino Nano project - VL6180X distance sensor
categories: project
excerpt: "Wire and sketch the VL6180X distance sensor for Arduino Nano"
tags:
  - arduino IDE
  - setup
  - Mac OSX
  - Nano
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-08 11:27'
modified: '2020-01-08 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>
### Introduction

This post details how to wire and sketch the [VL6180X lidar Time of Flight distance and ambient light sensor](../arduino-ToF-VL6180X/) to an Arduino Nano board.

#### The I2C communication bus

The default libraries and sketches for the VL6180X sensor all use the
[I2C protocol (communication bus)](../arduino-I2C/). The sensor data is sent in a serial address format using only two (2) wires: Serial Clock (or SCL) and Serial Data (or SDA).

#### I2C and the Arduino Nano board

Larger boards have dedicated connectors for SCL and SDA, but not the Nano board. Instead the Nano board uses the analogue ports A4 for SCL and A5 for SDA. This is like a standard for most Arduino boards.

#### Wiring

<figure>
<img src="../../images/nano-VL6180X-a4-a5_bb.png">
<figcaption> Wiring for the L6180X Time of Flight and ambient light sensor.</figcaption>
</figure>

#### Single shot measurement

The code is just a copy from [Pololus GithHub repo on the VL6180x sensor](https://github.com/pololu/vl6180x-arduino/blob/master/examples/RangeSingleShot/RangeSingleShot.ino).

<button id= "togglesingleshot" onclick="hiddencode('singleshot')">Hide/Show sketch</button>

<div id="singleshot" style="display:none">

{% capture text-capture %}
{% raw %}

```
/* This minimal example shows how to get single-shot range
measurements from the VL6180X.
The range readings are in units of mm. */

#include <Wire.h>
#include <VL6180X.h>

VL6180X sensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  sensor.init();
  sensor.configureDefault();
  sensor.setTimeout(500);
}

void loop()
{
  Serial.print(sensor.readRangeSingleMillimeters());
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

#### Continuous measurements

The code is just a copy from [Pololus GithHub repo on the VL6180x sensor](https://github.com/pololu/vl6180x-arduino/blob/master/examples/InterleavedContinuous/InterleavedContinuous.ino).

<button id= "toggleContinuous" onclick="hiddencode('Continuous')">Hide/Show sketch</button>

<div id="Continuous" style="display:none">

{% capture text-capture %}
{% raw %}

```
/* This example demonstrates how to use interleaved mode to
take continuous range and ambient light measurements. The
datasheet recommends using interleaved mode instead of
running "range and ALS continuous modes simultaneously (i.e.
asynchronously)".
In order to attain a faster update rate (10 Hz), the max
convergence time for ranging and integration time for
ambient light measurement are reduced from the normally
recommended defaults. See section 2.4.4 ("Continuous mode
limits") and Table 6 ("Interleaved mode limits (10 Hz
operation)") in the VL6180X datasheet for more details.
Raw ambient light readings can be converted to units of lux
using the equation in datasheet section 2.13.4 ("ALS count
to lux conversion").
Example: A VL6180X gives an ambient light reading of 613
with the default gain of 1 and an integration period of
50 ms as configured in this sketch (reduced from 100 ms as
set by configureDefault()). With the factory calibrated
resolution of 0.32 lux/count, the light level is therefore
(0.32 * 613 * 100) / (1 * 50) or 392 lux.
The range readings are in units of mm. */

#include <Wire.h>
#include <VL6180X.h>

VL6180X sensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  sensor.init();
  sensor.configureDefault();

  // Reduce range max convergence time and ALS integration
  // time to 30 ms and 50 ms, respectively, to allow 10 Hz
  // operation (as suggested by Table 6 ("Interleaved mode
  // limits (10 Hz operation)") in the datasheet).
  sensor.writeReg(VL6180X::SYSRANGE__MAX_CONVERGENCE_TIME, 30);
  sensor.writeReg16Bit(VL6180X::SYSALS__INTEGRATION_PERIOD, 50);

  sensor.setTimeout(500);

   // stop continuous mode if already active
  sensor.stopContinuous();
  // in case stopContinuous() triggered a single-shot
  // measurement, wait for it to complete
  delay(300);
  // start interleaved continuous mode with period of 100 ms
  sensor.startInterleavedContinuous(100);

}

void loop()
{
  Serial.print("Ambient: ");
  Serial.print(sensor.readAmbientContinuous());
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.print("\tRange: ");
  Serial.print(sensor.readRangeContinuousMillimeters());
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

#### Other alternatives

The post [VL6810X sketch and wiring](../project-ToF-VL6180X/) contains links to alternative sketches that retrieves more information from the VL6810X module.
