---
layout: post
title: Micropython rainbow blink
categories: ide
excerpt: "Micropython rainbow blink"
tags:
  - Micropython
  - setup
  - Mac OSX
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-10-26 11:27'
modified: '2022-10-26 T12:17:25.000Z'
comments: true
share: true
---

## Introduction

MicroPython is a tiny open source Python dialect that runs on microcontrollers - like the Adafruit Feather nRF52840 microcontroller that I use for developing xSpectre's handheld spectrometer.

```
"""
Rainbow Blink example for NeoPixel LED Arduino Feather Express.
Includes QT Py and various Trinkeys.
Requires two libraries from the Adafruit CircuitPython Library Bundle.
Download the bundle from circuitpython.org/libraries and copy the
following files to your CIRCUITPY/lib folder:
* neopixel.mpy
* adafruit_pixelbuf.mpy
Once the libraries are copied, save this file as code.py to your CIRCUITPY
drive to run it.
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
