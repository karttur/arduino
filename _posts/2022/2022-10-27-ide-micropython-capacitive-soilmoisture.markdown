---
layout: post
title: CircuitPython capacitive soil moisture
categories: ide
excerpt: "CircuitPython code for capacitive soil moisture sensing using the Adafruit Feather nRF52840 microcontroller"
tags:
  - CircuitPython
  - soil moisture
  - Adafruit Feather nRF52840
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-10-27 11:27'
modified: '2022-10-27 T12:17:25.000Z'
comments: true
share: true
---

## Introduction

CircuitPython is a tiny open source Python dialect that runs on microcontrollers - like the [Adafruit Feather nRF52840](../../module/module-feather-nRF52840/) microcontroller that I use for developing [xSpectre's handheld spectrometer](../../spectrolum/spectrolum-v078-summary/). CircuitPython is a dialect of MicroPython, with CircuitPython primarily maintained by Adafruit for there microcontrollers (including the Feather nRF52840).

## CircuitPython pin labels for Adafruit nRF52480 Express

The naming of the pins, both for Arduino IDE and CircuitPython, for the Adafruit nRF52480 Express board is [here](https://blog.adafruit.com/2021/05/25/pin-reference-adafruit-feather-nrf52840-prettypins/).

## Capacitive soil moisture

One of the external probes that I use for my spectrometer project is a [capacitive soil moisture sensor](../../sensor/sensor-capacitive-sm-v1-2/). It works fairly well, is cheap and returns an analog signal where the voltage is linearly related to the soil moisture.

Connecting the soil moisture sensing directly to the Adafruit nRF52480 Express microcontroller on a breadboard and the CircuitPython code works fine. Attaching the capacitive soil moisture sensor to [xSpectre spectrometer v0.78](../../spectrolum/spectrolum-v078-summary/), the spectrometer fails to start. I discovered that the crucial function of using analog ports for power output (the CircuitPython library analogOut) is not setup for the Adafruit nRF52480 Express microcontroller, or any other nrF based microcontroller.

With this I abandoned my trial of using micropyhon insted of Arduino IDE for setting up xSpectre's spectrometer.


```
"""
As AnalogOut does not work for nrF microcontrollers, this script could not be made to run on xSpectre's spectroetmer version 0.78
"""
import time
import board
import digitalio
from analogio import AnalogIn
import neopixel

# print the pins availabe on the attached board

dir(board)

# Define PINs

# PIN 8 = builtin NEOPIXEL
rgbPixel = neopixel.NeoPixel(board.NEOPIXEL, 8, brightness=0.1)

# PIN 16/A2 = analog input from GX16
# gx16analogpin = digitalio.DigitalInOut(board.A2)
gx16analogpin = AnalogIn(board.A2)

# PIN 17/A3 = nKill (kills the session when set to False or low)
killpin = digitalio.DigitalInOut(board.A3)
# PIN 18/A4
btnpin = digitalio.DigitalInOut(board.A4)

# Set analog probe pin from GX16 to input
# gx16analogpin.direction = digitalio.Direction.INPUT

# Set killpin (17) to True to keep board alive
# killpin.switch_to_output(value=True)
# or
killpin.direction = digitalio.Direction.OUTPUT
killpin.value = True

# Set btnpin (18) to input
btnpin.direction = digitalio.Direction.INPUT

loopnr = 0

outerloopnr = -1

RED = (255, 0, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)

def get_gx16_analog_soilmoisture(pin):
    return (pin.value * 3.3) / 65536

while True:

    print(loopnr)
    print((get_gx16_analog_soilmoisture(gx16analogpin),))
    print('soimoisture', get_gx16_analog_soilmoisture(gx16analogpin))

    # Step rgbpixel values blue - green - yellow - red - purple - blue
    if loopnr % 6 == 0:
        red = 0
        green = 0
        blue = 100
        rgbPixel.fill(BLUE)
        outerloopnr += 1
    elif (loopnr-outerloopnr*6) % 5 == 0:
        red = 0
        green = 100
        blue = 0
        rgbPixel.fill(CYAN)
    elif (loopnr-outerloopnr*6) % 4 == 0:
        red = 100
        green = 100
        blue = 0
        rgbPixel.fill(GREEN)
    elif (loopnr-outerloopnr*6) % 3 == 0:
        red = 100
        green = 0
        blue = 0
        rgbPixel.fill(YELLOW)
    elif (loopnr-outerloopnr*6) % 2 == 0:
        red = 100
        green = 0
        blue = 0
        rgbPixel.fill(RED)
    else:  
        red = 100
        green = 0
        blue = 100
        rgbPixel.fill(PURPLE)

    rgbPixel.show()
    time.sleep(0.5)
    loopnr += 1
```
Anohter Trinkeys
```
import time
import board
# import digitalio
from analogio import AnalogIn, AnalogOut
import neopixel

# Define PINs

# PIN 8 = builtin NEOPIXEL
rgbPixel = neopixel.NeoPixel(board.NEOPIXEL, 8, brightness=0.1)

# PIN 16/A2 = analog input from GX16
# gx16analogpin = digitalio.DigitalInOut(board.A2)
gx16analogpin = AnalogIn(board.A2)

# PIN 17/A3 = nKill (kills the session when set to False or low)
killpin = AnalogOut(board.A3)

# killpin = digitalio.DigitalInOut(board.A3)
# PIN 18/A4
# btnpin = digitalio.DigitalInOut(board.A4)
btnpin = AnalogIn(board.A4)


# Set analog probe pin from GX16 to input
# gx16analogpin.direction = digitalio.Direction.INPUT

# Set killpin (17) to True to keep board alive
# killpin.switch_to_output(value=True)
# or
# killpin.direction = digitalio.Direction.OUTPUT
# killpin.value = True

# Set btnpin (18) to input
# btnpin.switch_to_input()
# btnpin.direction = digitalio.Direction.INPUT

# killpin.value = 1

loopnr = 0

outerloopnr = -1

RED = (255, 0, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)

def get_gx16_analog_soilmoisture(pin):
    return (pin.value * 3.3) / 65536

while True:
    # print('killpin', get_gx16_analog_soilmoisture(killpin))

    print('btnpin', get_gx16_analog_soilmoisture(btnpin))

    print(loopnr)
    print((get_gx16_analog_soilmoisture(gx16analogpin),))
    print('soimoisture', get_gx16_analog_soilmoisture(gx16analogpin))

    # Step rgbpixel values blue - green - yellow - red - purple - blue
    if loopnr % 6 == 0:
        red = 0
        green = 0
        blue = 100
        rgbPixel.fill(BLUE)
        outerloopnr += 1
    elif (loopnr-outerloopnr*6) % 5 == 0:
        red = 0
        green = 100
        blue = 0
        rgbPixel.fill(CYAN)
    elif (loopnr-outerloopnr*6) % 4 == 0:
        red = 100
        green = 100
        blue = 0
        rgbPixel.fill(GREEN)
    elif (loopnr-outerloopnr*6) % 3 == 0:
        red = 100
        green = 0
        blue = 0
        rgbPixel.fill(YELLOW)
    elif (loopnr-outerloopnr*6) % 2 == 0:
        red = 100
        green = 0
        blue = 0
        rgbPixel.fill(RED)
    else:  
        red = 100
        green = 0
        blue = 100
        rgbPixel.fill(PURPLE)

    rgbPixel.show()
    time.sleep(0.5)
    loopnr += 1
```
