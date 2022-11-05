---
layout: post
title: Setup Mu
categories: ide
excerpt: "Setting up Mu for Micropython"
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

[Mu](https://learn.adafruit.com/welcome-to-circuitpython/installing-mu-editor) is a simple code editor that works with the Adafruit CircuitPython boards. It is written in Python and works on Windows, MacOS, Linux and Raspberry Pi. The serial console is built right in so you get immediate feedback from your board's serial output! This post closely follows the [Adafruit tutorial Installing the Mu editor](https://learn.adafruit.com/welcome-to-circuitpython/installing-mu-editor).

## Install Mu

Download Mu from [https://codewith.mu](https://codewith.mu). in MacOS double click the diskimage (<span class='file'>.dmg</span>), then drag the app <span class='app'>Mu Editor</span> to the <span class='file'>Applications</span> folder.

## First startup

The first time you start Mu, you will be prompted to select your _mode_ - you can always change your mind later. For now please select **CircuitPython**.

If you have the disk (Volume) called **CIRUITPY** mounted, <span class='app'>Mu editor</span> will automatically detect it. Otherwise it will ask for a local directory for storing the python modules.

For more details on installeing and starting up <span class='app'>Mu editor</span>, please see the Arduino page on [Installing the Mu Editor](https://learn.adafruit.com/welcome-to-circuitpython/installing-mu-editor).

## How it works

When you plug a board into your computer with CircuitPython already installed, the board shows up on your computer as a USB drive called **CIRCUITPY**.

Each time the board is powered up (or you save a new file to the disk **CIRCUITPY**) the python module <span class='module'>code.py</span> is executed. Thus you can start by making simple changes to <span class='module'>code.py</span> for testing how CircuitPython works. For more details see the Arduino page on [The CIRCUITPY Drive](https://learn.adafruit.com/welcome-to-circuitpython/the-circuitpy-drive).

## A first python module

[Adafruit Feather nRF52840 Express](https://www.adafruit.com/product/4062) comes with 4 built-in LED lights. To actually write a python script (or _module_) that affects the board go to the Arduino tutorial [Creating and Editing Code](https://learn.adafruit.com/welcome-to-circuitpython/creating-and-editing-code). Copy the following code as suggested on that page:

```
import board
import digitalio
import time

led = digitalio.DigitalInOut(board.LED)
led.direction = digitalio.Direction.OUTPUT

while True:
    led.value = True
    time.sleep(0.5)
    led.value = False
    time.sleep(0.5)
```

Paste this code, using the <span class='app'>Mu editor</span> interface and save it as <span claas='file'>code.py</span> and save it to the board mounted as **CIRCUITPY** (you have to overwrite the existing file). When the script file is uploaded, the red LED next to the usb port on the Feather board should start blinking. For details on the imports and functions, please see the Arduino tutorial [Creating and Editing Code](https://learn.adafruit.com/welcome-to-circuitpython/creating-and-editing-code).

## Read-Evaluate-Print-Loop (REPL)

When working more with CircuitPython you will encounter the abbreviation _REPL_. To access REPL in the <span class='app'>Mu editor</span>, click the <span class='button'>Serial</span> button to open a REPL window below the code window of the <span class='app'>Mu editor</span>. Now you can start and stop the execution of the <span class='module'>code.py</span>.

```
ctrl+C to stop the execution
ctrl+D to restart the execution
```

For more details on how to use the _REPL, please see the Arduino tutorial [The REPL](https://learn.adafruit.com/welcome-to-circuitpython/the-repl).
