---
layout: post
title: Setup Arduino IDE
categories: ide
excerpt: "Setting up Arduino IDE on Mac OSX"
tags:
  - arduino IDE
  - setup
  - Mac OSX
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-11-10 11:27'
modified: '2019-11-10 T18:17:25.000Z'
comments: true
share: true
---

## Introduction

The Arduino Integrated development Environment (IDE) can be accessed using the could, or installed locally. This post covers how to setup Arduino IDE locally on Mac OSX. At time of writing this (November 2019) the Arduino IDE does not recognize the usb port for all kinds of board and the post describes how to use [<span class='app'>Homebrew</span>](https://brew.sh) to fix this problem.

If <span class='app'>Ardiono IDE</span> recognizes the USB and the sketch (script) compiles but does not load with an error like:

```
avrdude: stk500_recv(): programmer is not responding
avrdude: stk500_getsync() attempt 1 of 10: not in sync: resp=0x00
```

a probable cause is that you have some componets connected to your rx and tx pins.

## prerequisits

[<span class='app'>Homebrew</span>](https://brew.sh) must be installed on your machine, as described in [this post](https://karttur.github.io/setup-theme-blog/blog/install-imagemagick/#installation) or on the [Homebrew site](https://brew.sh).

## Arduino IDE

Get the latest <span class='app'>Arduino IDE</span> from the [Arduino software page](https://www.arduino.cc/en/main/software). Select the operating system, that will take you the page giving you the option of contributing towards the development of the Arduino software. You can either <span class='button'>JUST DOWNLOAD</span> or <span class='button'>CONTRIBUTE & DOWNLOAD</span>.

### Install

Once downloaded on Mac OSX, all you need to do is to drag the <span class='app'>Arduino</span> app to the <span class='file'>Applications</span> folder.

### Start

Start <span class='app'>Arduino</span> by double clicking. You probably need to allow it to start as you downloaded directly from the Arduino homepage (not via the repository deisgnated for your Operating System).

### Test port access

Attach an Arduino board via a USB cable to your computer. If you have several USB ports, try all of them out before concluding that your <span class='app'>Arduino IDE</span> does not connect to the Arduino board.

In the Arduino menu select:

<span class='menu'>Tools -> Port</span>

and if the list that appears contain a usb port entry you are fine to go. In the example below, the second line is the serial port connection to your arduino board.

```
Serial ports
/dev/cu.Bluetooth-incoming-Port
/dev/cu.usbmodemFD121 ("Your Arduino Board")
```

If not, you have to install a driver that allows <span class='app'>Arduino</span> to recognize the usb port.

### Install usb port driver

The driver that you need is called CH34x, and is available on [GitHub](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver). The <span class='file'>README.MD</span> document (also available as a pdf) include all the required instructions.

I used the Homebrew alternative, which boils down to the following two <span class='app'>Terminal</span> commands:

<span class='terminal'>$ brew tap adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver</span>

<span class='terminal'>$ brew cask install wch-ch34x-usb-serial-driver</span>

Then again try to see
