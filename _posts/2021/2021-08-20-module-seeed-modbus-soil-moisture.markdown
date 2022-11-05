---
layout: post
title: MODBUS soil moisture
categories: module
excerpt: "MODBUS soil moisture"
tags:
  - arduino
  - soil moisture
  - MODBUS
  - SEEED studio
  - S-Soil MT-02A
  - S-Soil MTEC-02A

image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2021-08-20 11:27'
modified: '2022-08-21 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

[SEEED-studio](https://www.seeedstudio.com/) offers an industrial-grade MODBUS-RTU RS485 Soil Moisture and Temperature Sensor features high accuracy - [S-Soil MT-02A](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-Sensor-S-Soil-MT-02-p-4634.html). This manual is an attempt to set the sensor up with Arduino and xSpectre version 0.7 handheld spectrometer.

### Versions

Note that SEEED-studio offers two versions, one for [soil moisture and temperature](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-Sensor-S-Soil-MT-02-p-4634.html) and one for [soil moisture, temperature and electric conductivity](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-EC-Sensor-S-Soil-MTEC-02-p-4633.html). In August 2021, both versions were available from [elfa](https://www.elfa.se/en/industrial-soil-moisture-temperature-sensor-modbus-rtu-rs485-2v-analogue-ip68-seeed-studio-101990668/p/30215414?track=true&no-cache=true&marketingPopup=false).

### GitHub code

[https://github.com/Miceuz/rs485-moist-sensor](https://github.com/Miceuz/rs485-moist-sensor)

### Project

Arduino project setup for [soil moisture and temperature](https://www.seeedstudio.com/RS485-Soil-Moisture-Temperature-Sensor-S-Soil-MT-02-p-4634.html). The project is modelled after [DIY Soil EC Salinity Meter using Arduino & Soil EC Sensor](https://how2electronics.com/diy-soil-ec-salinity-meter-using-arduino-soil-ec-sensor/).

#### Youtube tutorial

[TUTORIAL: How To Use RS-485 TTL MODBUS - Arduino Controller Module (Part 1/2 - Wire Up)](https://www.youtube.com/watch?v=HPZrGuBtk_c)

[TUTORIAL: How To Use RS-485 TTL MODBUS - Arduino Controller Module (Part 2/2 - Wire Up) Solar](https://www.youtube.com/watch?v=tBw15SfmuwI)

### Setup of SEEED/SENSECAP Soil Moisture & Temperature & EC Sensor

In this case we have a sensor (the SEEED/SENSECAP Soil Moisture & Temperature & EC Sensor) with a built in chip (EPROM memory?) that is setup for communication using the MODBUS software protocol. To get the sensor to actually communicate with Arduino we need to connect it using a hardware device. For that our sensor is prepared for using the RS485 hardware protocol. Thus, to get the SEEED/SENSECAP Sensor to work you need to first setup a physical connection using the RS485 hardware protocol and then sketch a script using the MODBUS protocol for communication over the RS485 wiring to drive (D) and receive (R) information.

In the setup of the SEEED/SENSECAP Sensor with Arduino in this project, the Arduino microcontroller will act as the master and the sensor as the slave.

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

Vin is usually 5v and both Vin and GND are just for running the RS485 hardware itself (I think, not completely clear to me). The data pins A and B are usually given in the documentation of the slave. If not I am not sure how to find out. But for the SEEED/SENSECAP sensor used in here the information is available in the detailed manual (page 5 under the heading WIRING, the connections are given related to the colors of the sensor cables with Yellow: A and White: B).

#### Sketch (MODBUS)

In the [Soil Moisture & Temperature & EC Sensor User Manual (Product Model: S-Temp&VWC&EC-02)](#) the default communication setting is defined:

##### Register

To access the sensor readings the user must know the how the MODBUS Register is defined in the particular device that is connected. The complete MODBUS register for the SEEED/SENSECAP sensor is given on page 8 in the manual. The table below is a summary of the read only (sensor) registers (the registry also contains a dozen read/write parameters that can be changed and read - see sectiob below on _Default communication settings_).

| Abbr | Parameter | Reg adress (HEX/DEC) | Parameter type |
| Temp | Temperature | 0x0000 /0 | INT16 |
| VWC | Volumetric Water Content | 0x0001 /1 | UINT16 |
| EC | Electrical Conductivity | 0x0002 /2 | UINT16 |
| Salinity | Salinity | 0x0003 /3 | UINT16 |
| TDS | Total Dissolved Solids | 0x0004 /4 | UINT16 |
| Epsilon | Dielectric Constant | 0x0005 /5 | UINT16 |

#### Default communication settings

The deafult MODBUS dialect set in the SEEED/SENSECAP sensor is MODBUS RTU (Remote Terminal Unit). It can be changed to MODBUS ASCII, but that should not be needed.

The SEEED/SENSECAP sensor comes with default communication setting (see page 5 under the heading Wiring, the communication default settings are given under the green cable); or on page 7 under the heading Modbus Communication Protocol:

| parameter | setting |
| BPS | 9600 |
| start bit | 1  |
| parity | no parity |
| stop bit | 1 |

The default address of the SEEED/SENSECAP sensor is 1 (see manual page 12 SLAVE ADDR).

These settings are stored in the EEPROM (Electrically Erasable Programmable Read Only Memory), and can be changed. If I have understood correctly these settings are under a fixed address of 0 SEEED/SENSECAP sensor in and can be called and changed via the green cable (not used in normal communication).

### Arduino with esp32

For xSpectre later version (07 and higher), building on other microcontrollers, the library ModbusMaster does not work. Instead you need to define the MODBUS protocol at a lower level, using the library ???. The best tutorial I found online is [ESP32 with MODBUS RTU RS485 Protocol Using Arduino IDE](https://microdigisoft.com/esp32-with-modbus-rtu-rs485-protocol-using-arduino-ide/).

### Resources

google search string "modbus function code arduino softwareserial"

[Youtube: Fun and Easy Modbus RTU Protocol - RS485](https://www.youtube.com/watch?v=nhQ_HQC7CRg)

[Arduino: ModBus implementation](https://forum.arduino.cc/t/modbus-implemntation/674118) (Arduino IDE sketch with explanation comments for function call etc, scroll down to see the edited code after comments.)

[GitHub repo: Modbus for Arduino (FOR RS 232)](https://github.com/mcci-catena/Modbus-for-Arduino/blob/master/examples/software_serial_simple_host/software_serial_simple_host.ino) (GitHub repo)

[GitHub: Arduino Library: SerialModbus](https://github.com/legicore/SerialModbus) - too esoteric at the moment.

Lots of MODBUS libraries in a single repo
https://github.com/IndustrialShields/arduino-Tools40
