---
layout: post
title: Sensors and accessories v0.80
categories: spectrolum
version: v0.80
excerpt: "List of sensors and accessories to consider for version 0.80"
tags:
  - spectrometer
  - xspectrolum
  - sensors
  - accessories

image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-11-03'
modified: '2022-11-03'
comments: true
share: true
---

### Introduction

On the verge of producing a first series of xSpectre´s spectrometer, which should be version 0.80, this post lists all the sensors and accessories that the model should be able to carry.

### Microcontroller

The microcontroller determines the available ports, power supply and processing capacity. As an outset version 0.80 will use the same microprocessor as version 0.78: [Adafruit Feather nrF62840 express](../../module/module-feather-nRF52840/).

### Spectral sensors

The built-in slot should primarily be built for Hamamatsu miniature spectral sensors.

#### Hamamatsu science grade sensors

The main sensor for xSpectre version 0.80 will be the Hamamatsu near infrared (NIR) miniature sensor [C14384MA-01](sensor/sensor-C14384MA-01-spectrometer/). But alternatively the visible (VIS) to NIR [C12880MA]() sensor should be possible to use as well. They build on the same principles and are similarly operated, but with the C14384MA sensor requiring a higher start pulse voltage.

#### AMS Hyperspectral NIR Sensor

The [AMS OSRAM AS7421 Hyperspectral NIR Sensor](https://ams.com/as7421) was launched in September 2022. It is announced as designed for Apple iPad, but I can not find any iPad with a built-in spectrometer advertised.

[Mouser](https://www.mouser.se/c/?q=AS7421) advertises the AMS 64 band NIR sensor for €16 each when buying 10 or more, increasing to €24 for buying a single sensor. Expected to become available late January 2022.

#### AMS hobby grade sensors

At time of writing this, AMS has a set of [eight (8) more miniature sensors](https://ams.com/spectral-sensing):

- [AS7261 - XYZ + NIR (2 versions)](https://ams.com/as7261)
- [AS7262 - 6-band VIS](https://ams.com/as7262)
- [AS7263 - 6-band NIR](https://ams.com/as7263)
- [AS7264N - 6-band VIS + 1NIR](https://ams.com/as7264n)
- [AS7265x - 6x3-bands XYZ+VIS+NIR](https://ams.com/as7265x)
- [AS7341 - 11-band VIS+1NIR](https://ams.com/as7341)
- [AS7343 - 14-band XYZ+VIS+1NIR](https://ams.com/as7343)

Several of these sensors are available as breakout boards, from e.g. Adafruit and Sparkfun.

- [Adafruit AS7262 - 6-band VIS](https://www.adafruit.com/product/3779)
- [Adafruit AS7341 - 11-band VIS+1NIRAS7341](https://www.adafruit.com/product/4698)
- [Sparkfun AS7262 - 6-band VIS](https://www.sparkfun.com/products/14347)
- [Sparkfun AS7263 - 6-band NIR](https://www.sparkfun.com/products/14351)
- [Sparkfun - 6x3-bands XYZ+VIS+NIR](https://www.sparkfun.com/products/15050)
- [Sparkfun/Mikroe AS7261 - XYZ + NIR](https://www.sparkfun.com/products/20012)
- [Sparkfun/Mikroe AS7263 - 6-band NIR](https://www.sparkfun.com/products/20010)
- [Sparkfun AS7341 - 11-band VIS+1NIR](https://www.sparkfun.com/products/17719)
- [Sparkfun(mikroe) AS7341 - 11-band VIS+1NIR](https://www.sparkfun.com/products/18785)

Note that while these AMS based miniature spectral sensors might work, the built-in light source of the modules are not good enough - they only cover the VIS wavelengths and the sensors operating n the NIR spectrum does not get sufficient light for acquiring useful signals.

To be used with xSpectre's spectrometer the AMS NIR spectral sensors must be built using the light source as built in the spectrometer.

### Light Resources

I have not been able to find a light source that fulfills all requirements. To cover the range from 400 to 1100 nm, the range that version 0.8 will cover, two light source need to be installed in parallel. The first must be the [OSRAM OSLON® P1616, SFH 4737](https://www.osram.com/ecat/OSLON®%20P1616%20SFH%204737/com/en/class_pim_web_catalog_103489/prd_pim_device_10751075/):

- spectral range (nm): 425-475, 650-1050
- voltage (V): 2.95-3.5
- mA (mA): 500 (max)
- viewing angle (degrees): 130

Identifying a suitable VIS light source to accompany.

https://www.digikey.se/sv/products/detail/luminus-devices-inc/MP-2016-1100-40-80/4807631?s=N4IgTCBcDaIIxjgFgLQISsKByAREAugL5A

https://www.digikey.se/sv/products/detail/solidlite/AL3020A-HWR-020MA/15903002

https://www.digikey.se/sv/products/detail/solidlite/AL5050A-WRL-060MA/15903012

The three below are really small, at 3 V and only 20mA, should perhaps fit?

https://www.digikey.se/sv/products/detail/würth-elektronik/158301227/4947918

https://www.digikey.se/sv/products/detail/osram-opto-ams-osram/LCW-MVSG-EC-AZBZ-4U9X-1/5231447

https://se.farnell.com/broadcom-limited/asmt-uwb1-nx3g2/led-smd-plcc2-warm-white-3500k/dp/1972478

[Researchgate discussion on efficient NIR light sources for spectroscopy](https://www.researchgate.net/post/Efficient-light-sources-for-NIR-spectroscopy)

IR emitters - check via https://www.photonics.com:

https://www.photonics.com/Buyers_Guide/ProdSpec/LEDs_Emitters/Infrared_Emitter_EMIRS50/psp8077

### BNC connected Ion Selective Electrodes (ISEs)

The BNC connection is primarily intended for Ion Selective Electrodes (ISEs). In Sweden, ISEs for [Pasco](https://www.pasco.com) are available via [Sagitta](https:/www.sagitta.se)

[pH](https://www.pasco.com/products/sensors/wireless/ps-3514)

[Nitrate](https://www.pasco.com/products/sensors/wireless/ps-3521)

[ammonium](https://www.pasco.com/products/sensors/wireless/ps-3516)

[calcium](https://www.pasco.com/products/sensors/wireless/ps-3518)

[chloride](https://www.pasco.com/products/sensors/wireless/ps-3519)

[Potassium](https://www.pasco.com/products/sensors/wireless/ps-3520)

[Oxidation Reduction Potential Probe](https://www.pasco.com/products/sensors/wireless/ps-3515)

[Carbon Dioxide](https://www.pasco.com/products/sensors/wireless/ps-3517)

[Shanghai Measuretech Scientific Instrument Co., Ltd](http://www.measureteq.com/electrode-and-sensor/) offers the same, and more.

[Shanghai Rex technologu Co (Alibaba)](https://shrex.en.alibaba.com/minisiteentrance.html?spm=a2700.details.0.0.b2092b79sAS4YE&from=detail&productId=1600229164961) is another supplier.

The ISE from the two latter comes at 1/10 the price of PASCO.

#### GX connections

The GX (aviator plug) connection is a general purpose connection that can handle three (3) different protocols:

- MODBUS RS485
- I2C
- analog signals

I need to fund out if the UART protocol can be achieved with the present setting.

##### ModBus

SEEED studio [soil moisture, temperature and electric conductivity](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-EC-Sensor-S-Soil-MTEC-02-p-4633.html)

### MQ gas sensors

The [MQ series of gas sensors](../..sensor//sensor-mq-gas) only require 3 wired, power, ground and an analog signal.
All  the gas sensors operate on 3.3 to 5V and require around 750mW for heating. That equals about 150 mA at 5V. Is that possible to deliver over the GX interface? If an external power supply is added, what is required? Aliexpress has a [AAA Battery Step Up to 5V Power Converter Module for Arduino](https://www.aliexpress.com/item/32840471284.html) that would do for testing. At $1.36.

### SEEED studio CO2 grove

The [SEEED studie Grove - Carbon Dioxide Sensor(MH-Z16)](../../sensor/sensor-mh-z16-c02) is interesting for environmental monitoring and potentially for calibrating Near Infra Red (NIR) CO2 sensitive spectral sensor. The Grove CO2 sensors also works with a NIR detector and an emitter. It thus requires up to 100 mA of power for heating the NIR emitter.

##### other

CO2 sensor (the one I have) - check if the port can deliver the voltage or if I need to use an external battery and a switch but still receive the signal back?

### To consider compared with v0.78

The start pulse voltage difference dependent on spectral sensor

Is a cheaper version with an [AMS AS7343 14-band sensor]() possible to combine with the Hamamatsu sensors?
