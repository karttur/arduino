---
layout: post
title: Setup CircuitPython
categories: ide
excerpt: "Setting up Micropython on MacOS"
tags:
  - Micropython
  - setup
  - Mac OSX
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-10-23 11:27'
modified: '2022-10-23 T12:17:25.000Z'
comments: true
share: true
---

## Introduction

[CircuitPython](https://circuitpython.org) is a tiny open source Python dialect that runs on microcontrollers - like the [Adafruit Feather nRF52840 Express](../../module/module-feather-nRF52840/) microcontroller that I use for developing [xSpectre's handheld spectrometer](../../spectrolum/spectrolum-v078-summary/).

At time of writing this, late October 2022, the stable version of CircuitPython is 7.3.3. While I can get some of my sensors to work with CircuitPython, I can now mount the Feather nRF52840 microcontroller on version 0.78 of the spectrometer as CircuitPython lack the function to use analog pins for output. That is required for the customised Printed Circuit Board (PCB) of the spectrometer to work properly and power some of the integrated devices.

## MicroPython and CiruitPython

[Micropython](https://micropython.org) is a lean and efficient implementation of the Python 3 programming language that includes a small subset of the Python standard library and is optimised to run on microcontrollers and in constrained environments.

The MicroPython pyboard is a compact electronic circuit board that runs MicroPython on the bare metal, giving you a low-level Python operating system that can be used to control all kinds of electronic projects.

MicroPython fit and run within just 256k of code space and 16k of RAM (Adafruit feather nRF52840 comes with 1MB flash space and 256KB RAM).

MicroPython aims to be as compatible with normal Python as possible to allow you to transfer code with ease from the desktop to a microcontroller or embedded system.

[CircuitPython](https://circuitpython.org) is developed and maintained by [Adafruit](https://www.adafruit.com) and is a derivative of MicroPython designed to simplify experimentation and education on low-cost microcontrollers.

For this tutorial I will use CircuitPython, following the original [Adafruit instructions: CircuitPython for Feather nRF52840](https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/circuitpython).

### Download circuitPython

Download the [latest version of CircuitPython for Feather nRF52840 Express](https://circuitpython.org/board/feather_nrf52840_express/), which at the time of writing this is version 7.3.3.

Double-click the Reset button next to the USB connector on the Feather nRF52840 Express board. The NeoPixel RGB LED should then emit a steady green light. Further, and ore importantely, the Feather board should show up as a disk. If you have MacOS you can locate it with <span class='app'>Finder</span>; the name of disk should be **FTHR840BOOT**.

To install CircuitPython just drag the downloaded <span class='file'>.uf2</span> file to the **FTHR840BOOT** disk. The LED will flash. Then, the **FTHR840BOOT** drive will disappear and a new disk drive called **CIRCUITPY** will appear.

You are ready to rock!, unless you want to build your own CircuitPython environment.

If you want to install [Mu]() and run script, continue to the [next](../ide-micropython-mu) post.

### Build the python 3 MacOS environment from scratch

This part is for building CircuitPython from scratch.

To create and run CircuitPython via MacOS you must have a Python 3 compiler and the ARM toolchain. I think, there is no clear instruction on this, I followed the suggestion on [Digikey](https://www.digikey.se/en/maker/projects/building-circuitpython/d5581a40fc4b403f8c1fbe7571b8c1c0).

The easiest way to get this setup is to use [Homebrew]():

<span class='terminal'>brew install git python3 gettext</span>

followed by

<span class='terminal'>brew install gcc-arm-embedded --cask</span>

Create a an empty disk image in <span class='app'>DiskImage</span> and put it under your home directory or some other directory that you remember. I called my empty DiskImage <span class='file'>CircuitPython</span>.


## Bulding from scratch

[macOS Setup](https://learn.adafruit.com/building-circuitpython/macos)
