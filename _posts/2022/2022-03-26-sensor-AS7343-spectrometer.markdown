---
layout: post
title: AMS AS7343 spectrometer
categories: sensor
sensingfeature: spectra
sensormethod: filter
sensorconnect: i2c
sensingmedia: solid+liguid+gas+soil+water+air
excerpt: "AMS 14-channel broad band sensors"
tags:
  - spectrometer
  - Sensors
  - AMS
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-03-26 11:27'
modified: '2022-03-26 T11:27'
comments: true
share: true
---

### Introduction

In February 2022 [AMS](https://ams.com/) presented a 14-band filter based visible (VIS) to Near Infra Red (NIR) sensor - the [AMS AS7343 Spectral Sensor](https://ams.com/AS7343)

The AS7343 14-Channel Multi-Spectral Sensors integrate high-precision optical filters onto standard CMOS silicon via deposited interference filter technology. The sensors feature a spectral response that is defined by individual channels covering approximately 380nm to 900nm with 11 visible (VIS) channels and one Neat Infra Red (NIR) channel, plus channels for clear and flicker. It comes at a physical size of 3.1 x 2 x 1 mm.

The sensor is available from e.g. [Digikey](https://www.digikey.se/en/products/filter/optical-sensors-ambient-light-ir-uv-sensors/536?s=N4IgTCBcDaIIIGUDsBmALCkBdAvkA) prized for approximately 5 to 10 USD dependent on the amount you buy.

#### Data

I2C slave address: 0x39

#### Bands

| Channel | min(nm) | typ(nm) | max(nm) | FWHM(nm) |
| F1 | min(nm) | typ(nm) | max(nm) | FWHM(nm) |
| F2 |   |   |   |   |
| FZ |   |   |   |   |
| F3 |   |   |   |   |
| F4 |   |   |   |   |
| FY |   |   |   |   |
| F5 |   |   |   |   |
| FXL |   |   |   |   |
| F6 |   |   |   |   |
| F7 |   |   |   |   |
| F8 |   |   |   |   |
| FNIR |   |   |   |   |
| FD |   |   |   |   |
| VIS |   |   |   |   |

*FD = Flicker Detection

### Resources

[AMS page for as7343](https://ams.com/en/as7343)

[AMS Datasheet AS7343 14-Channel Multi-Spectral Sensor](https://ams.com/documents/20143/6705498/AS7343_DS001046_6_00.pdf)

[Waveshare review, project and code for AMS as7343](https://www.waveshare.com/as7341-spectral-color-sensor.htm)
https://www.waveshare.com/wiki/AS7341_Spectral_Color_Sensor
[Arduino discussion on the Waveshare code](https://forum.arduino.cc/t/as7341-spectral-color-sensor/905445/3)

Adafruit blog post [Eye on this ams OSRAM AS7343 Spectral Sensor](https://blog.adafruit.com/2022/08/11/eye-on-npi-ams-osram-as7343-spectral-sensor-digikey-eyeonnpi-digikey-amsosram-adafruit/)

Adafruit AS7341 [GitHub resources](https://github.com/adafruit/Adafruit-AS7341-PCB)

Adafruit AS7341 [Arduino library code on GitHub](https://github.com/adafruit/Adafruit_AS7341)

[Spectral Sensor Calibration Methods - AS7343/AS7352 Evaluation Kit](https://www.mouser.se/pdfDocs/SpectralSensorCalibrationMethods.pdf) found at Mouser.

[Building Your Own Spectrometer](https://github.com/tigoe/LightProjects/blob/main/spectrometers/AS7341/AS7341_Spectrometer_serial/AS7341_Spectrometer_serial.ino), code for AS4731 on GitHub (but one of the Arduino founders). Summarizes available breakout boards and codes - plus offers his own code.

[DF Robot breakout board with the AMS as 4731 spectral sensor](https://wiki.dfrobot.com/Gravity_AS7341_Visible_Light_Sensor_SKU_SEN0364)
