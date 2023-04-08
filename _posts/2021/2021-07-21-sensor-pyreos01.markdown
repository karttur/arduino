---
layout: post
title: Pyreos MIR sensors
categories: sensor
sensingfeature: spectra
sensormethod: filter
sensorconnect: I2C
sensingmedia: solid+liquid+gas+soil+water+air
excerpt: "Pyreos thin film thermal emissivity sensors"
tags:
  - pyreos
  - MIR
  - thinflilm
  - sensor
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2021-07-21'
modified: '2021-07-21'
comments: true
share: true
---

### Introduction

[Pyreos](https://pyreos.com), a company founded on an original patent by Siemens for thin film MIR sensing, offers both analog and digital uncooled sensors in the Mid Infra Red (MIR) wavelengths between 2.5 and 12 micro meters. This post summarises the Pyros sensors and links to online resources. Note that Pyreos does not offer any emitters. MIR emitters are listed in the posts on [Thermal emitters](../../component/component-thermal-emitters) and [Microhybrid IR](../sensor/sensor-microhybrid-co2-kit).

### Filters

The actual sensor is, I think, the same in all Pyreos products. It is the filter that differs. The list below summarises the filters available in March 2022.

| CWL µm | (HPB nm) |	Use |
| 2.55 | 90 | - |
| 2.9 | 300 | - |
| 3.3 | 160 | CH4 |
| 3.33 | 160 | H-C |
| 3.38 | 190 | H-C |
| 3.7 | 110 | Reference |
| 3.9 | 200 | N2O |
| 3.91 | 90 | Reference |
| 4.26 | 180 | CO2 |
| 4.43 | 60 | CO2 (Special) |
| 4.64 | 90 | CO |
| 4.64 | 180 | CO (Narrow) |
| 4.85 | 90 | - |
| 4.9 | 130 | Reference |
| 5.3 | 180 | NO |
| 5.6 | 80 | Milk, Reference |
| 5.73 | 80 | Milk, Fat |
| 6.2 | 200 | NO2 |
| 6.46 | 130 | Milk, Protein |
| 6.7 | 120 | Milk, Reference |
| 7.3 | 200 | SO2 |
| 8.01 | 440 | - |
| 8.42 | 180 | Refrigerants, Anaesthetics |
| 8.55 | 180 | Anaesthetics |
| 8.75 | 220 | Anaesthetics |
| 8.95 | 330 | Refrigerants |
| 9.5 | 400 | Sugar, Ethanol |
| 9.61 | 150 | Milk, Lactose, Sugar |
| 9.65 | 220 | Anaesthetics |
| 10.27 | 210 | - |
| 12.23 | 210 | Anaesthetics |

#### Analog sensors

The analog sensors are packages as [TO39 single, dual and quad channel uncooled precision IR detectors](https://pyreos.com/ir-to-39-detectors/?productnum=PY0317).
Available filters are [listed by application and wavelength](https://pyreos.com/infrared-sensing-by-wavelength/#filters). Some of the filters, and filter combinations, are offered as pre-configured standard products. For example via Mouser, also available in [Mouser Sweden](https://www.mouser.se). The figure below illustrates the design of the Pyreos single, dual and quad IR detectors.

<figure class="third">
<img src="../../images/Pyreos_single_TO39.png">
<img src="../../images/Pyreos_dual_TO39.png">
<img src="../../images/Pyreos_quad_TO39.png">
<figcaption> Pyreos single, dual and quad cell MIR sensors.</figcaption>
</figure>

#### Digital Sensors

The digital sensor units are available as smaller size (5.6 x 3.7 x 2.8 mm) surface mount devices (SMDs). They are available as single or dual SMD units.

<figure class="half">
<img src="../../images/Pyreos_SMD_single.png">
<img src="../../images/Pyreos_SMD_dual.png">
<figcaption> Pyreos single and dual analog SMD MIR sensors.</figcaption>
</figure>

#### Linear arrays

Pyreos also offers linear element line sensor arrays including a metal casing and integrated read-out electronics. When writing this, March 2022, the following arrays and filters are offered:

| Array | filter | range |
| 128 | LVF | 2.5 - 5 |
| 128 | LVF | 5.5 - 11 |
| 255  | custom | custom |
| 510  | custom  | custom |

#### Applications

[Applications and case studies of the Pyroes family of sensors.](https://pyreos.com/case-studies/). A more practical Do-It-Yourself guide, including links to different products is the [Pyreos](https://pyreos.com) article [Guide to building mid-infrared spectral analysis system using Pyreos technology (milk example)](https://pyreos.com/wp-content/uploads/2020/11/Pyreos-Guide-to-building-a-mid-infrared-spectrometer-using-Pyreos-milk-example.pdf).
