---
layout: post
title: I2C scanner
categories: project
excerpt: "Arduino sketch for scanning I2C addresses on breakout boards"
tags:
  - arduino
  - I2C scanner
  - I2C
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-12-10 11:27'
modified: '2019-12-10 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

If you want to connect multiple breakout components relying on the [I2C communication bus]() to your arduino project, you need to know the addresses of these components. That address you can either find in the documentation, or you can use the [Arduino I2C_scanner sketch](https://playground.arduino.cc/Main/I2cScanner/). The sketch is also included below.

#### Youtube explanation on I2C

[Youtube explanation on I2C from [How to Mechatronics]](https://howtomechatronics.com/tutorials/arduino/how-i2c-communication-works-and-how-to-use-it-with-arduino/)

[Youtube Tutorial: Multiple Devices on One Arduino I2C Bus (The Swiss guy)](https://www.youtube.com/watch?v=QQLfzlPGjjE)

#### The I2C_scanner sketch

[I2C_scanner sketch](https://playground.arduino.cc/Main/I2cScanner/)

<button id= "toggle" onclick="hiddencode('togglesketch')">Hide/Show i2c_scanner sketch</button>

<div id="togglesketch" style="display:none">

{% capture text-capture %}
{% raw %}

```
// --------------------------------------
// i2c_scanner
//
// Version 1
//    This program (or code that looks like it)
//    can be found in many places.
//    For example on the Arduino.cc forum.
//    The original author is not know.
// Version 2, Juni 2012, Using Arduino 1.0.1
//     Adapted to be as simple as possible by Arduino.cc user Krodal
// Version 3, Feb 26  2013
//    V3 by louarnold
// Version 4, March 3, 2013, Using Arduino 1.0.3
//    by Arduino.cc user Krodal.
//    Changes by louarnold removed.
//    Scanning addresses changed from 0...127 to 1...119,
//    according to the i2c scanner by Nick Gammon
//    https://www.gammon.com.au/forum/?id=10896
// Version 5, March 28, 2013
//    As version 4, but address scans now to 127.
//    A sensor seems to use address 120.
// Version 6, November 27, 2015.
//    Added waiting for the Leonardo serial communication.
//
//
// This sketch tests the standard 7-bit addresses
// Devices with higher bit address might not be seen properly.
//

#include <Wire.h>


void setup()
{
 Wire.begin();

 Serial.begin(9600);
 while (!Serial);             // Leonardo: wait for serial monitor
 Serial.println("\nI2C Scanner");
}


void loop()
{
 byte error, address;
 int nDevices;

 Serial.println("Scanning...");

 nDevices = 0;
 for(address = 1; address < 127; address++ )
 {
   // The i2c_scanner uses the return value of
   // the Write.endTransmisstion to see if
   // a device did acknowledge to the address.
   Wire.beginTransmission(address);
   error = Wire.endTransmission();

   if (error == 0)
   {
     Serial.print("I2C device found at address 0x");
     if (address<16)
       Serial.print("0");
     Serial.print(address,HEX);
     Serial.println("  !");

     nDevices++;
   }
   else if (error==4)
   {
     Serial.print("Unknown error at address 0x");
     if (address<16)
       Serial.print("0");
     Serial.println(address,HEX);
   }    
 }
 if (nDevices == 0)
   Serial.println("No I2C devices found\n");
 else
   Serial.println("done\n");

 delay(5000);           // wait 5 seconds for next scan
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

### My components

| Component | Address|
| VL6810X (Pololu)| 0x29 |
| AS72SX  | 0x49   |

#### Internal component addresses

##### VL6810X (Pololu)

| Value | Address|
| RESULT__RANGE_VAL (final range value in mm)| 0x062 |
| RESULT__ALS_VAL ()  | 0x050   |

The output from the ambient light sensor is a 16 bit count value, this count output is proportional to the light level and is converted into lux with VL6180x_AlsGetLux(). The ALS read measurement functions VL6180x_AlsPollMeasurement() & VL6180x_AlsGetMeasurement() both call this function.
