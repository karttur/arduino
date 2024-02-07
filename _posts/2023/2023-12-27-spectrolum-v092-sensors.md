---
layout: post
title: Sensors and accessories v0.92
categories: spectrolum
version: v0.92
excerpt: "List of sensors, probes and accessories for version 0.92"
tags:
  - spectrometer
  - xspectrolum
  - sensors
  - accessories

image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2023-12-27'
modified: '2023-12-27'
comments: true
share: true
---

### Introduction

xspectrolum version 0.92 is the last version using the xspeclum1rB PCB. It is an experimental version used for evaluating combinations of different spectral sensors and lamps. In order to be able to evaluate the effect of the light bouncing inside the nozzle for solid sample, two different nozzle designs were developed for version 0.92. These were produced using different hue. The light bouncing should be reflected in variations between the nozzles of different hue.

Compared to v0.82 (the previous version used for scanning actual samples), the design of the female side of the bayonet is slightly changed. The inside "roof" is made thicker and a a piece of the outside is removed to make space for the soldering of the microporcessor (figure). The position of the pogo-pin foundation on the muzzle side is adjusted.

To better focus the light from incandescent light sources a small reflector has been added to the ledlum board. To focus in front of the spectral sensor the reflector must be rotated. This can be achieved in 2 different ways, 1) by rotating the entire ledlum PCB or, 2) by adding a rotated holder for the light bulb.

A change in version 0.92 compared to all other previous versions is the software calibration of the spectral sensor. It is well known that silica based spectral sensors have a narrow peak of sensitivity ... The shortcoming of silica based sensors is exacerbated when applying most LED based lamps as these also have diminishing power towards the NIR region.

### Xspeclum PCB

The xspeclum PCB is the same (version 1 revision b) that was first used with version 0.73 of the spectrometer.

### Ledlum PCB

Also the ledlum PCB is version 1 revision b, with space for 2 different lamps.

### Microcontroller

The microcontroller applied is the [Adafruit Feather nrF62840 express](../../module/module-feather-nRF52840/), introduced with version 0.72.

### Spectral sensors

As with versions 0.72 through 0.91, also version 0.92 is mainly built for Hamamatsu miniature sensors.

#### Hamamatsu science grade sensors

The main sensor for xSpectre version 0.92 are the Hamamatsu Visionbe (VIS) and near infrared (NIR) miniature sensor [C12880MA]() and [C14384MA-01](sensor/sensor-C14384MA-01-spectrometer/).

### Light Resources

The problems with finding a light source that emits throughout the spectral range of the sensors adopted (400 to 1100 nm) still persists in version 0.92. The software solution of applying varying integration times (see below ???) across the spectral range of each individual sensor, however, party solves this problem. But while solving this, the production of the NIR LED OSRAM OSLON® P1616, SFH 4737](https://ams-osram.com/products/leds/ir-leds/osram-oslon-p1616-sfh-4737) was ended after [AMS took over OSRAM and formed ams-OSRAM](https://en.wikipedia.org/wiki/AMS-Osram). The only alternative I have been able to find (December 2023) is the [EPI OCL-480 GIR](https://www.epigap-osa.com/products/leds/smd/broad-band-conversion-smd/) produced by [EGIBAP](https://www.epigap-osa.com) and available from [DigiKey](https://www.digikey.se/en/products/detail/epigap-osa-photonics/OCL-480-GIR-XD-T/21357595). But due to size differences between the OSRAM SFH 4737 and the EPI OCL-480 a redesign of the Ledlum PCB will be required for subsequent versions (when the stock of SFH 4737 runs out).

Several of the miniature incandescent light bulbs that I have tested over the past years have also been withdrawn from production. But after years of searching tungsten based incandescent miniature lamps I have found two alternatives:

- [Mcro-Glühlampen-Gesellschaft (MGG)](https://www.mgg-lamps.de)
- [Eiko](https://www.eiko.com)
- [Barthelme](https://www.barthelme.de)

[DigiKey](https://www.digikey.se) offers a range on miniature incandescent light bulbs, but it is difficult to get adequate information on the filament and other properties. I ordered the two alternative bulbs that were available in stock:

- [JKL components](https://www.jkllamps.com/home/)
- [Visual Communications Company - VCC](https://vcclite.com)

#### Barthelme

Barthelme used to offer a T1 xenon high pressure Bi-pin bulb for optoelectronics, but discontinued the production. I still have a few bulbs and wanted to test them as they might be the superior solution.

20710330 T1, 3.0v, 300mA, 09W, long[10]

I think it is the same bulb also once produced by TRU COMPOMENTS 1590267 and still announced on both [Conrad](https://www.conrad.se/sv/p/xenonlampa-3-v-0-90-w-sockel-bi-pin-1-27-mm-n-a-1590267-tru-components-1-st-1590267.html) and [Amazon](https://www.amazon.se/TRU-Components-1590267-Xenonlampe-Miniaturlampen/dp/B075F971ZT), but not available.

T1 lamps at 5v [caatlog](https://www.barthelme.de/shared/download/katalog/Barthelme-Leuchtmittel-Spezial-Gluehlampen.pdf)

21090515 T3/4, 5v, 115mA, 0.6W, standard
21109157, T1 1.5v, 75 mA, 0,11W standard

21025115, T1 5v, 60 mA, 0.3W, long [9.5 mm], lens
21025115, T1 5v, 115 mA, 0.58W, long [9.5 mm], lens

#### MGG lamps

For testing we used the MGG T.3/4 (diameter of 2.3 mm) 4043-00 (4V, 50 mA, C-2R - see the [T.3/4 catalog](https://www.mgg-lamps.de/fileadmin/mgg/Dokumente/T_3-4.pdf)). C-2R is the coil type (single C = single coil) and the design of how the filament in held together (2R). The minimum amount to order is 100 lamps per type and the only lamp available was the 4043-00. Trying it out is rather weak (@ 4V and 50 mA). But for the tests of v0.92 it will do.

As the lamp we tested is a bit to dim (0.0250 Mean Spherical Candle Power [MSCP]) and with the new solution reaching 5V power and including a reflector, lamps with  T.1 (diameter 3.0) fits better (the Eiko lamp is a T.1). Thus the following alternative lamps (from the MGG [T.1 catalog](https://www.mgg-lamps.de/fileadmin/mgg/Dokumente/T1.pdf)) would probably be better:


- 1033-00 (5V, 115 mA, C-2R, 0.15 MSCP, 40000 hours, short)
- 1042-00 (5V, 115 mA, C-2R, 0.15 MSCP, 40000 hours, standard)
- 1150-20 (5V, 115 mA, CC-6, 0.15 MSCP, 40000 hours, short+flat top)
- 1150-00 (5V, 115 mA, CC-6, 0.15 MSCP, 40000 hours, standard+lens)


#### Eiko

Secondary information indicate that the Eiko 42005 T1 Bi-pin at 1.35 V (2.14 lm, 5 hours) is a tungsten based incandescent bulb. It is only available for purchase in the United States and Canada. We ordered 100 bulbs via an acquaintance and had them sent to Sweden.

Alternative EIKO lamps that could be tested:

- 715 (5V, T1, 1.89 lm, 40000 hours, standard)
- 6022 (5V, T1, 0.38 lm, 10000 hours, standard)

#### JKL

The JKL miniature lamp available from DigiKey is the [5V T-3/4 wire terminal bulb with product nr 7152AS15](https://www.digikey.se/en/products/detail/visual-communications-company-vcc/7152AS15/4175982?s=N4IgTCBcDaKHAEB2AjAVjAQQMqoLQDkAROEAXQF8g).

#### VCC

The VCC miniature lamp available from DigiKey is the [5V T-1 wire terminal bulb with product nr 7153](https://www.digikey.se/sv/products/detail/jkl-components-corp/7153/1552826?s=N4IgTCBcDaIFIGkAyACQcAQHYCMBWAzALQByAImiALoC%2BQA).

#### Reflector

A reflector can assemble and direct the light in a favourable way. I could only find a single reflector small enough for a 3-5 mm bulb and that fits on the Ledlum PCB; a 12 x 9 mm LED-reflector from [Mentor]() available from [Elfa](https://www.elfa.se/sv/led-reflektor-instick-12-9mm-mentor-2450-5100/p/17500516?pos=5&origPos=1&pageSize=50&origPageSize=50&track=true&sort=Price:asc&sid=7rPIWpWN0C&itemList=category).

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
