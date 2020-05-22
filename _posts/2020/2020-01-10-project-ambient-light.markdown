---
layout: post
title: Ambient light sensor project
categories: project
excerpt: "Projects for BH1750FVI digital Ambient Light Sensor IC for I2C bus interface"
tags:
  - ambient light
  - I2C
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-10 11:27'
modified: '2020-01-10 T18:17:25.000Z'
comments: true
share: true
component: null
sensor: sensor-ambient-light
module: module-ambient-light
project: null
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

There is a range of breakout boards with ambient light sensors available. This post lists some of the more common. They all work on the [I2C bus interface](../../ide/ide-I2C).

### Identify I2C address

Note that Arduino Nano boards do not have dedicated I2C connections points. Instead A4 is used for SDA (data) and A5 as SCL (clock). The I2C connection is SDA -> SDA and SCl -> SCL.

If you do not know the I2C address of your module, first wire the component and then follow the instructions in the post on [I2C scenner](../../ide/ide-scanner).

#### BH1750

The [BH1750 module](../../modules/module-ambient-light) is based on the older [BH1750FVI component](../../components/component-BH1750VFI-ambient-light).

I2C adress: 0x23 (from [I2C scenner](../../ide/ide-scanner).
)

<figure>
<img src="../../images/nano-bh1750_bb.png">
<figcaption> Breadboard wiring of the BH1750 ambient light sensor to an Arduino Nano board.</figcaption>
</figure>

<figure>
<img src="../../images/nano-bh1750-breadfree_bb.png">
<figcaption> Direct wiring of the BH1750 ambient light sensor to an Arduino Nano board.</figcaption>
</figure>

#### Without specific library

The sketch below is **not** using the _BH1750.h_ or _BH1750VFI.h_  libraries and explicitly calls the I2C address.

<button id= "toggleBH1750_01" onclick="hiddencode('BH1750_01')">Hide/Show sketch</button>

<div id="BH1750_01" style="display:none">
{% capture text-capture %}
{% raw %}

```
#include <Wire.h>
#include <math.h>
int BH1750address = 0x23; //i2c address

byte buff[2];
void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  int i;
  uint16_t val=0;
  BH1750_Init(BH1750address);
  delay(200);

  if(2==BH1750_Read(BH1750address))
  {
    val=((buff[0]<<8)|buff[1])/1.2;
    Serial.print(val,DEC);
    Serial.println(" lux");
  }
  delay(150);
}

int BH1750_Read(int address) //
{
  int i=0;
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 2);
  while(Wire.available()) //
  {
    buff[i] = Wire.read();  // receive one byte
    i++;
  }
  Wire.endTransmission();
  return i;
}

void BH1750_Init(int address)
{
  Wire.beginTransmission(address);
  Wire.write(0x10);//1lx reolution 120ms
  Wire.endTransmission();
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

#### With library

In the example below, the library __ form [Github/claws/BH1750](https://github.com/claws/BH1750) has been added.

With library (not tested) as [outlined in this post](https://create.arduino.cc/projecthub/afsh_ad/measure-lux-with-arduino-using-bh1750-91dad1).

```
#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

void setup(){
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println("Running...");
}

void loop() {
  uint16_t lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000);
}
```
