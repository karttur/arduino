---
layout: post
title: VL6810X sketch and wiring
categories: project
excerpt: "Wiring up the Pololu VL6180X Time Of Fight distance sensor"
tags:
  - arduino
  - time of flight
  - lidar
  - pololu
  - distance
  - ambient light
  - VL6180X
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-12-10 11:27'
modified: '2019-12-10 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

This post is about wiring the [VL6180X lidar Time of Flight distance and ambient light meter](../../module/module-VL6180X) to an Arduino UNO board.

The Adafruit manual for [VL6180X Time of Flight Micro-LIDAR Distance Sensor Breakout](https://www.elfa.se/Web/Downloads/_t/ds/Adafruit_VL6180X_eng_tds.pdf?pid=30129217) contains more information.

Another post covers [Arduino Nano project - VL6180X distance sensor](../project-nano-VL6180X/)

#### The I2C communication bus

The default libraries and sketches for the VL6180X sensor all use the
[I2C protocol (communication bus)](https://howtomechatronics.com/tutorials/arduino/how-i2c-communication-works-and-how-to-use-it-with-arduino/). For details on the I2C protocol see the post on [I2C communication](../../arduinoide/arduino-I2C).

#### Arduino library

Code packages that connects an Arduino board to different devices, including break out boards, sensors, displays, communication and storage devices, are available from different libraries. The <span class='app'>Arduino</span> app has a library manager that you reach from the menu:

<span class='menu'>Sketch -> Include Library -> Manage Libraries</span>

The basics for handling libraries is explained on Arduinos official page [Installing Additional Arduino Libraries](www.arduino.cc/en/Guide/Libraries).

### Adafruit, sparkfun or Pololu

Breakout boards with the VL6180X lidar+ambinent light sensors are offered both by [adafruit](https://www.adafruit.com/product/3316), [sparkfun](https://www.sparkfun.com/products/14722) and [Pololu](https://www.pololu.com/product/2489). Sparkfun is easier to work with if you use their [Qwiic](https://www.sparkfun.com/qwiic) connect system for I2C devices. You can then use the [Qwiic Cable - Breadboard Jumper (4-pin)](https://www.sparkfun.com/products/14425) for connecting the spectrometer to the board. If you use Adafruit or Pololu you have to solder the breakout board.

### Wiring

The wiring is the same regardless if you use the Adafruit, Sparkfun or Pololu breakout boards.
Just connect power (5v) and ground, and then the SCL and SDA ports. All connections are item to item (5v -> 5v, gnd -> gnd, SCL -> SCL, SDA -> SDA).

The [Adafruit manual for VL6180X Time of Flight Micro-LIDAR Distance Sensor Breakout](https://www.elfa.se/Web/Downloads/_t/ds/Adafruit_VL6180X_eng_tds.pdf?pid=30129217) contains illustrations on how to wire the VL6810X module with different boards.

### Coding

In my project I used the Pololu module, and [the Pololu GitHub library for the Arduino IDE interface with the VL6180X breakout board.](https://github.com/pololu/vl6180x-arduino). The code below is just copies from that repo. Further down there are some url links to alternative codes.

#### Single shot range

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

#### Continuous

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

### Advanced sketch 1

The [Tutorial: STMicroelectronics VL6180X Time-of-Flight LIDAR Sensor](https://mcuoneclipse.com/2016/12/03/tutorial-stmicroelectronics-vl6180x-time-of-flight-lidar-sensor/) is an in depth explanation of the VL6180X component and its breakout board, including different alternatives on how to sketch.

### Advanced sketch 2

GitHub repo that contains [Arduino Sketch for connecting multiple VL6180x sensors](https://github.com/luetzel/VL6180x). The code includes how to connect multiple I2C devices.

### Advanced sketch 3

[Alternative code that shows how to access other data from the I2C stream](https://os.mbed.com/users/highroads/code/VL6180X_Explorer/file/126b6cd0f4f5/main.cpp/).

### Advanced sketch 4

[A more detailed (exhaustive) sketch from GitHub](https://github.com/kriswiner/VL6180X/blob/master/VL6180Xbasic.ino).
