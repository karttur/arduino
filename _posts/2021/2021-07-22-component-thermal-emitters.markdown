---
layout: post
title: Thermal emitters
categories: component
excerpt: "Thermal emitters for MIR spectroscopy"
tags:
  - spectrometer
  - Thermal
  - emitters
image: ts-mdsl-rntwi_RNTWI_id_2001-2016_AS
date: '2021-07-22 11:27'
modified: '2021-07-22 11:27'
comments: true
share: true

---

## Introduktion

Identifying a suitable thermal emitter for the mid-IR (MIR) regions has turned out to be difficult. A good introduction is given in the article [Match the Emitter to the Task](https://www.photonics.com/Articles/Match_the_Emitter_to_the_Task/a35272) by Brian Elias, Cal Sensors Iin, published by [Photonics](https://www.photonics.com). A more practical guide, including links to different products is the [Pyreos](https://pyreos.com) article [Guide to building mid-infrared spectral analysis system using Pyreos technology (milk example)](https://pyreos.com/wp-content/uploads/2020/11/Pyreos-Guide-to-building-a-mid-infrared-spectrometer-using-Pyreos-milk-example.pdf).

## Selecting IR emitter

The following parameters should be considered when selecting an IR emitter:

1. Physical size
2. Electrical input power of the emitter
3. Output IR power curve showing the maximum response at various input voltage vs. wavelengths (blackbody curve)
4. If it covers the wavelength of the application
5. Operating voltage
6. Power consumption
7. Lifetime
8. Optical Collimation

For pyroelectric sensors there are two possible choices for emitters:

1. Steady state emitter with an optical chopper
- Usually filament based
- High thermal IR output
- Higher power consumption
- Lower lifetime
- Require simpler circuitry to power up emitter and chopper
- Involves mechanical components – a rotating optical chopper
- Relies on the optical collimation to enhance IR gain
2. Emitter capable of being pulsed electrically
- Usually semiconductor thin film (MEMS) based design
- Higher lifetime which depends on the pulse rate (usually 100,000 hours of operation)
- Lower power consumption and therefore output power (cost effective)
- Relies on the optical collimation to enhance IR gain (usually parabolic)
- Pulsed power circuitry not preferred by manufacturers (more complex than stead state operation)
- Can also be operated at steady state (but
not preferred, as it requires other means of modulation)
- Allows designs with no moving parts, which may be beneficial for robustness, stability and lifetime of the solution

Pyreos recommends pulsed emitters for the majority of the spectroscopy setups.

### Steady state emitters

Steady state emitter examples:

1. [Boston Electronics](http://www.boselec.com/product-category/ir-uv-sources/)
2. [Hawkeye Technologies](http://www.hawkeyetechnologies.com/source-selection/#steady)
3. For wavelength 3 to 4.5 um, [HeimannSensor](https://www.heimannsensor.com) offers the low cost and robust [HSL series](https://www.heimannsensor.com/HSL-Series) that should be possible to build directly into an microcontroller using a [MOSFET](#). Some of the HSL series emitters can be bought directly from [Boston Electronics](https://shop.boselec.com/products/hsl-5-115).
4. [IBSG](http://www.ibsg-st-petersburg.com) (Russia) offers IR LED emitters with fixed wavelengths from 0.7 to 5.0 um.


### Pulsed emitters

1. [Axetris](https://www.axetris.com/en/infrared-sources/products) Recommended: [EMIRS 200](https://www.axetris.com/en/irs/products/emirs200) (no prices given)
2. [Hawkeye Technologies](http://www.hawkeyetechnologies.com/source-selection/#pulsable) Recommended: [IR-75](https://shop.boselec.com/products/ir-70) @ $75 + UPS breakout board (driver: @ $525.
3. [Micro-Hybrid](https://www.micro-hybrid.de/en/products/ir-components-and-systems/ir-sources.html) Recommended: JSIR350-4 (see the special post on [micro-hybrid](../../sensor/sensor-microhybrid01))

### Specific suppliers

### http://www.ibsg-st-petersburg.com

[IBSG](http://www.ibsg-st-petersburg.com) (Independent Business Scientific Group) Mid infrared optoelectronics is a Russian producer (S:t Petersburg).

### Micro-Hybrid

I bought both emitters and sensors from [micro-hybrid](../../sensor/sensor-microhybrid01) in December 2021.
