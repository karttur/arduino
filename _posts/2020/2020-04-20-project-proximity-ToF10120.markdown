---
layout: post
title: ToF10120 Laser Range Sensor
categories: sensor
excerpt: "ToF10120 Laser Range Sensor"
tags:
  - distance
  - laser
  - ToF
  - ToF10120
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-04-20 11:27'
modified: '2020-04-20 T18:17:25.000Z'
comments: true
share: true
component: null
sensor:
module:
project:
---

### Introduction

The [APDS-9930 Digital Proximity and Ambient Light Sensor](../docs/av02-3190en_ds_apds-9930_2015-11-13.pdf) by [Avago technologies/Broadcom](www.avagotech.com) uses infra-red (850 nm) lidar for estimating distances. While the APDS-9930 is factory calibrated at a given pulse count, the number of proximity LED pulses can be programmed from 1 to 255 pulses, which will allow greater proximity distances to be achieved. Each pulse has a 16 μs period.

<figure>
<img src="../../images/sensor-APDS-9930.png">
<figcaption> Broadcom's APDS-9930 Digital Proximity and Ambient Light Sensor. </figcaption>
</figure>

### Module

Integrated modules with the APDS-9930 are available from [diymore](https://www.diymore.cc/products/apds-9930-proximity-sensor-approaching-and-non-contact-proximity-module-ckin).

### Availability

I can not find any vendor offering the APDS-9930 in Sweden, neither the sensor nor as a module.

I got my modules for [Banggood.com](https://www.banggood.com/10pcs-CJMCU-9930-APDS-9930-Proximity-and-Non-Contact-Gesture-Recognition-Detection-Attitude-Sensor-p-1104981.html?utm_design=131&utm_email=1585396804_2324_08&utm_source=emarsys&utm_medium=Shipoutinform190813&utm_campaign=trigger-emarsys&utm_content=Gakki&sc_src=email_2671705&sc_eh=9a59c5efb8cf9f481&sc_llid=20461599&sc_lid=104858042&sc_uid=53Z60pdPrF&cur_warehouse=CN).

### Meta data

[Data sheet for VL6180X](https://www.pololu.com/file/0J961/VL6180X.pdf).

### Wiring

https://surtrtech.com/2019/03/18/easy-use-of-tof-10120-laser-rangefinder-to-measure-distance-with-arduino-lcd/

### Sketch

```
/* This code is to use with ToF10120 to measure distance in (mm) and shows it on the Serial monitor using I²c inteface
 * Modified and adapted from a code found on some dodgy chinese website
 * Refer to www.SurtrTech.com for more details
 */

#include <Wire.h>

unsigned char ok_flag;
unsigned char fail_flag;

unsigned short lenth_val = 0;
unsigned char i2c_rx_buf[16];
unsigned char dirsend_flag=0;


void setup() {
  Wire.begin();
  Serial.begin(9600,SERIAL_8N1);
  printf_begin();          

}

void loop() {


   int x=ReadDistance();
   Serial.print(x);
   Serial.println(" mm");

}

int serial_putc( char c, struct __file * )
{
  Serial.write( c );
  return c;
}

void printf_begin(void)
{
  fdevopen( &serial_putc, 0 );
}



void SensorRead(unsigned char addr,unsigned char* datbuf,unsigned char cnt)
{
  unsigned short result=0;
  // step 1: instruct sensor to read echoes
  Wire.beginTransmission(82); // transmit to device #82 (0x52)
  // the address specified in the datasheet is 164 (0xa4)
  // but i2c adressing uses the high 7 bits so it's 82
  Wire.write(byte(addr));      // sets distance data address (addr)
  Wire.endTransmission();      // stop transmitting
  // step 2: wait for readings to happen
  delay(1);                   // datasheet suggests at least 30uS
  // step 3: request reading from sensor
  Wire.requestFrom(82, cnt);    // request cnt bytes from slave device #82 (0x52)
  // step 5: receive reading from sensor
  if (cnt <= Wire.available()) { // if two bytes were received
    *datbuf++ = Wire.read();  // receive high byte (overwrites previous reading)
    *datbuf++ = Wire.read(); // receive low byte as lower 8 bits
  }
}

int ReadDistance(){
    SensorRead(0x00,i2c_rx_buf,2);
    lenth_val=i2c_rx_buf[0];
    lenth_val=lenth_val<<8;
    lenth_val|=i2c_rx_buf[1];
    delay(300);
    return lenth_val;
}
```
