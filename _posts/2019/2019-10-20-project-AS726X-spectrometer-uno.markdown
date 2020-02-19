---
layout: post
title: AMD six band spectrometer project (UNO)
categories: projects
excerpt: "Wiring up the AMD as726x spectrometer with Arduino UNO"
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
project: null
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>
### Introduction

This small "project" post covers how to wire an integrated module with the [AMS AS72Sx 6 channel broad band spectrometer](../../modules/module-AS726X-spectrometer/) to an Arduino board.

#### The I2C communication bus

The spectrometer sends data for 6 (12 or 18) spectral bands using the [I2C communication bus](../../ide/ide-I2C).


#### Preparing the Arduino IDE

Your Arduino board must have the SDA and SCL ports required for the I2C communication bus. If you are using one of [Arduino's standard boards](https://www.arduino.cc/en/main/boards) they should be included with the latest version of <span class='app'>[Arduino IDE](https://www.arduino.cc/en/main/software)</span>. On smaller boards that lack dedicated SDA and SCL ports A4 is used for SDA and A5 for SCL. For boards that do not have A4 and A5, the alternative is to program the I2C board, outlines in [this GitHub repo](https://github.com/felias-fogg/SoftI2CMaster/blob/master/README.md),

If you are using a board from a partner, you probably need to configure Arduino IDE for that particular board. As an example, you can look at the manuals for how to [configure Arduino for the Adafruit's Metro Express board](https://learn.adafruit.com/experimenters-guide-for-metro/configure-arduino-for-the-metro-express).

### Adafruit or sparkfun

Breakout boards with the AMD AS72Sx sensor(s) are offered both by [Adafruit](../../components/components-adafruit/) and [Sparkfun](../../components/components-sparkfun-spectrometer/). Sparkfun is easier to work with if you use their [Qwiic](https://www.sparkfun.com/qwiic) connect system for I2C devices. You can then use the [Qwiic Cable - Breadboard Jumper (4-pin)](https://www.sparkfun.com/products/14425) for connecting the spectrometer to the board. If you use the Adafruit spectrometer you have to solder the breakout board.

### Wiring

The wiring is (almost) the same regardless if you use the Adafruit or Sparkfun breakout boards. The Adafruit manual is [here](https://learn.adafruit.com/adafruit-as7262-6-channel-visible-light-sensor?view=all).

The difference between Adafruit and Sparkfun is that the Sparkfun breakout board requires 3.3 v power, whereas the Adafruit breaout board can be powered with either 3.3 or 5 v.


<figure>
<img src="../../images/AS726Xx-UNO_bb.png">
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

### Adafruit additional components

[Adafruit TFT display 1.44 (240 x 135)](https://www.adafruit.com/product/4383), also available from [Elfa](https://www.elfa.se/sv/44-tums-tft-lcd-skaerm-adafruit-2088/p/30129195?channel=b2c&price_gs=176.25&wt_mc=se.cse.gshop.sv.-&source=googleps&ext_cid=shgooaqsesv-na&&gclid=Cj0KCQiA-4nuBRCnARIsAHwyuPo4YAQ16hq3lAwA2j1m6p-NhvISnPZBGCaRi5XegqPpJp5-LjVZA0MaAv2REALw_wcB).

[Adafruit TFT display 0.96 (160 x 80)](https://www.elfa.se/sv/96-tums-160-80-tft-display-delning-adafruit-3533/p/30139159?q=Adafruit+0.96&pos=2&origPos=2&origPageSize=10&track=true).

The board used in the Adafruits manual for [Arduino wiring of these components](https://learn.adafruit.com/adafruit-as7262-6-channel-visible-light-sensors/arduino-wiring-test) is the Adafruit METRO M0 Express, also available from [Elfa](https://www.elfa.se/sv/adafruit-metro-m0-express-adafruit-3505/p/30129229?q=Adafruit+Metro+M0+&pos=1&origPos=1&origPageSize=10&track=true). But an ordinary Arduino UNO board works as well.

### Mikroelektronika (Mikroe)

[Mikroe](https://www.mikroe.com) offers the [AS7261 RGB+NIR sensor](https://www.mikroe.com/spectral-click) as a breakout board, but not specifically for Arduino.

University of Novi Sad have [demo project for creating a AS7261 XYZ Sensor - Colorimeter](https://www.optolab.ftn.uns.ac.rs/index.php/education/project-base/252-as7261-xyz-sensor-colorimeter). The project include wiring to an Arduino board, include a 3D-printed shell, and a [demo video on youtube](https://www.youtube.com/watch?v=f3F8kJKQuLE) and code written in [Laboratory Virtual Instrument Engineering Workbench (LabVIEW)](https://en.wikipedia.org/wiki/LabVIEW). The STL model is under the repo subfolder <span class='file'>stl</span> and the LabVIEW file under the directory <span class='file'>code/AS7261-VI</span>.

<figure>
<img src="../../images/AS7261-spectral-click-arduno.jpg">
<figcaption> Arduino wiring of the Mikroe "Spectral Click" AS7261 spectrometer.
</figcaption>
</figure>

<figure>
<img src="../../images/AS7261-spectral-click-stl.png">
<figcaption> STL model for casing to the Mikroe "Spectral Click" AS7261 spectrometer.
</figcaption>
</figure>
