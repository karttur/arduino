---
layout: post
title: RS485 steel-pin soil moisture probe
categories: sensor
sensingfeature: temperature+soil-moisture+electric-conductivity+salinity+tds+epsilon
sensormethod: steel-pin
sensorconnect: rs485/modbus-rtu
sensingmedia: soil
excerpt: "Industrial Soil Moisture & Temperature & EC Sensor MODBUS-RTU RS485 (S-Soil MTEC-02B)"
tags:
  - arduino
  - soil moisture
  - Electric conductivity
  - salinity
  - RS485
  - MODBUS RTU
  - SEEED studio
  - S-Soil MT-02A
  - S-Soil MTEC-02A

image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2021-08-20 11:27'
modified: '2023-04-02 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

[SEEED-studio](https://www.seeedstudio.com/) offers an industrial-grade RS485 MODBUS-RTU  Soil Moisture and Temperature Sensor - [S-Soil MT-02A](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-Sensor-S-Soil-MT-02-p-4634.html). It is a field ready probe with 3 stainless steel pins, an IP68 grade resin sealed and watertight body with integrated electronics. The more advanced version, [S-Soil MTEC-02A](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-EC-Sensor-S-Soil-MTEC-02-p-4633.html?queryID=48f04f346f15bfe19420a561080bc973&objectID=4633&indexName=bazaar_retailer_products) also senses electrical conductivity.

These kind of steel-pinned field sensors have only recently become available for 5 volt systems. Probes with the same basin design are now available also for sensing soil Nitrogen (N), Phosphorus (P) and Potassium (K), and pH. Further, sensors for almost any combination (temp-sm-ec, NPK, pH) are now available. Note that these kind of sensors are available for using different communication standards and protocols. xSpectre's spectrometer<b>+</b> are built for using the RS485 MODBUS-RTU protocol and standard.

### Versions and vendors

As noted above SEEED-studio offers two versions, one for [soil moisture and temperature](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-Sensor-S-Soil-MT-02-p-4634.html) (temp-sm) and one for [soil moisture, temperature and electric conductivity](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-EC-Sensor-S-Soil-MTEC-02-p-4633.html) (temp-sm-ec). In August 2021, both versions were available from [elfa](https://www.elfa.se/en/industrial-soil-moisture-temperature-sensor-modbus-rtu-rs485-2v-analogue-ip68-seeed-studio-101990668/p/30215414?track=true&no-cache=true&marketingPopup=false). The costs are approximately 100 USD for the more advanced including ec and 80 USD for the temp-sm.

Sensors with identical design, down to the label, are also available on [AliExpress](https://aliexpress.com). The Aliexpress prices for these probes varies. But the temp-sm-ec sensor that I got from the seller [ComWinTop](https://vi.aliexpress.com/item/1005001524845572.html?spm=a2g0o.order_list.order_list_main.17.21ef1802VQQ0bb&gatewayAdapt=glo2vnm) operates exactly like the SEEED studio version, but at only 33 USD (1/3 of the SEEED studio price).

<figure>
<img src="../../images/rs485-modbus-rtu_temp-sm-ec_probe.png">
<figcaption> RS485 MODBUS-RTU steel-pin field sensor for temperature, soil moisture and electric conductivity.</figcaption>
</figure>

### GitHub code

[https://github.com/Miceuz/rs485-moist-sensor](https://github.com/Miceuz/rs485-moist-sensor)

### Project

Arduino project setup for [soil moisture and temperature](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-Sensor-S-Soil-MT-02-p-4634.html). The project is modelled after [DIY Soil EC Salinity Meter using Arduino & Soil EC Sensor](https://how2electronics.com/diy-soil-ec-salinity-meter-using-arduino-soil-ec-sensor/).

#### Youtube tutorial

[TUTORIAL: How To Use RS-485 TTL MODBUS - Arduino Controller Module (Part 1/2 - Wire Up)](https://www.youtube.com/watch?v=HPZrGuBtk_c)

[TUTORIAL: How To Use RS-485 TTL MODBUS - Arduino Controller Module (Part 2/2 - Wire Up) Solar](https://www.youtube.com/watch?v=tBw15SfmuwI)

### Setup of SEEED/SENSECAP Soil Moisture & Temperature & EC Sensor

The communication between Arduino and the temp-sm/temp-sm-ec probes uses the RS485 hardware protocol. The data transfer uses the MODBUS-RTU standard with the Arduino microcontroller acting as the master and the sensor as the slave.

#### Wiring (RS485)

The RS485 has 4 ports that connect to pins on the Arduino board (the master in this project):

| port id | port function | typical connection pin |
| DI | Driver (Transmitter) In | TX |
| DE | Driver (Transmitter) Enable  | D3  |
| RE | Receiver Enable | D2 |
| RO | Receiver Out | RX |  

When RE = DE = 0 Receive signal mode
When RE = DE = 1 transmit signal mode

The RS485 also has 4 ports for connecting to the slave:

| port id | port function |
| Vin | Power |
| B | data pin  |
| A | data pin |
| GND | Ground |

Vin is usually 5v. The data pins A and B are usually given in the documentation of the slave. the connections are given related to the colors of the sensor cables. As the colors can vary you need to consult the documentation for the particular model you have.

##### Register

To access the sensor readings the user must know the how the MODBUS Register is defined in the particular device that is connected. The complete MODBUS register for the SEEED/SENSECAP sensor is given on [page 8 in the manual](https://files.seeedstudio.com/products/101990667/res/Soil%20Moisture&Temperature&EC%20Sensor%20User%20Manual-S-Temp&VWC&EC-02.pdf). Note that for some, but not all, probes of this kind the registry contains a dozen read/write parameters that can be changed and read - (see section below on _Default communication settings_). The tables below refer to the default settings of the temp-sm-ec sensor for SEEED studios. Summary of the read only (sensor) registers:

| **Abbr** | Parameter | Reg adress (HEX/DEC) | Parameter type | unit | accuracy |
| Temp | Temperature | 0x0000 /0 | INT16 | Celsius | 0.5 |
| VWC | Volumetric Water Content | 0x0001 /1 | UINT16 | vol/vol | 3 |
| EC | Electrical Conductivity | 0x0002 /2 | UINT16 | μS/cm | 3% |
| Salinity | Salinity | 0x0003 /3 | UINT16 | mg/L | 3% |
| TDS | Total Dissolved Solids | 0x0004 /4 | UINT16 | TDS | 3% |
| Epsilon | Dielectric Constant | 0x0005 /5 | UINT16 | DiConst | 3% |

As the retrieved data is in integer format, some of the parameters are multiplied with a factor before sent to to receiver:

| **Abbr** | Min | Max | Factor|
| Temp | -40 | 80 | 100 |
| VWC | 0 | 100 | 100 |
| EC | 0 | 20000 | 1 |
| Salinity | 0 | 20000 | 1 |
| TDS | 0 | 20000 | 1 |
| Epsilon | 0 | 8200 | 100 |

#### Default communication settings

The default MODBUS dialect set in the SEEED/SENSECAP sensor is MODBUS RTU (Remote Terminal Unit). It can be changed to MODBUS ASCII, but that should not be needed.

The SEEED/SENSECAP sensor comes with default communication setting (see [the manual page 5](https://files.seeedstudio.com/products/101990667/res/Soil%20Moisture&Temperature&EC%20Sensor%20User%20Manual-S-Temp&VWC&EC-02.pdf) under the heading Wiring, the communication default settings are given under the green cable); or on [page 7](https://files.seeedstudio.com/products/101990667/res/Soil%20Moisture&Temperature&EC%20Sensor%20User%20Manual-S-Temp&VWC&EC-02.pdf) under the heading **5 Modbus Communication Protocol**:

| parameter | setting |
| BPS | 9600 |
| start bit | 1  |
| parity | no parity |
| stop bit | 1 |

The default address of the SEEED/SENSECAP sensor is 1 (see [manual page 12 SLAVE ADDR)](https://files.seeedstudio.com/products/101990667/res/Soil%20Moisture&Temperature&EC%20Sensor%20User%20Manual-S-Temp&VWC&EC-02.pdf).

These settings are stored in the EEPROM (Electrically Erasable Programmable Read Only Memory), and can be changed.

### Resources

[Datasheet for ](https://files.seeedstudio.com/products/101990667/res/RS485%20Soil%20Moisture%20&%20Temperature%20&%20EC%20Sensor%20(S-Temp&VWC&EC-02A).pdf) for the latter.

https://www.faranux.com/product/soil-npk-sensor/

https://forum.arduino.cc/t/modbus-npk-sensor-does-not-respond-at-all/898377

https://lastminuteengineers.com/soil-npk-sensor-arduino-tutorial/
