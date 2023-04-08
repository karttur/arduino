---
layout: post
title: Adafruit Feather nRF52840
categories: xspectrolum
startversion: 0.78
endversion: 0.9
excerpt: "Adafruit Feather nRF52840 microcontroller, technical details, setup bootloader and use with Arduino IDE"
tags:
  - Adafruit
  - feather
  - nRF52840
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-06-01 11:27'
modified: '2022-06-01 T11:27'
comments: true
share: true
---

### Introduction

The [Adafruit](https://www.adafruit.com) series of microcontroller main-boards, [Feathers](https://www.adafruit.com/category/943) and daughter-boards (Wings) comes in different varieties with a wide range of capabilities. One of the alternative Feathers for the spectral sensor project is the [Adafruit Feather nRF52840 Express](https://www.adafruit.com/product/4062). It comes the Bluetooth Low Energy (BLE) and native USB support and is prepared for programming with Arduino IDE. Adafruit also offers the [Adafruit app](https://learn.adafruit.com/bluefruit-le-connect) for both [Android](https://play.google.com/store/apps/details?id=com.adafruit.bluefruit.le.connect&hl=en) and [iOS](https://learn.adafruit.com/bluefruit-le-connect) to communicate with their Feather Bluefruit LE devices.

<figure>
<img src="../../images/adafruit_feather_NRF52840.png">
<figcaption> Adafruit Feather NRF52840 Express.</figcaption>
</figure>

[Feather nRF52840](https://www.adafruit.com/product/4062) comes with the following features:

- ARM Cortex M4F (with HW floating point acceleration) running at 64MHz
- 1MB flash and 256KB SRAM
Native Open Source USB stack - pre-programmed with UF2 bootloader
- Bluetooth Low Energy compatible 2.4GHz radio (Details available in the nRF52840 product specification)
- FCC / IC / TELEC certified module
- Up to +8dBm output power
1.7v to 3.3v operation with internal linear and DC/DC voltage regulators
- 21 GPIO, 6 x 12-bit ADC pins, up to 12 PWM outputs (3 PWM modules with 4 outputs each)
- Pin \#3 red LED for general purpose blinking, NeoPixel for colorful feedback
- Power/enable pin
- Measures 2.0" x 0.9" x 0.28" (51mm x 23mm x 7.2mm) without headers soldered in
- Light as a (large?) feather - 6 grams
- 4 mounting holes
- Reset button
- SWD connector for debugging

### Prepare Arduino IDE

If you have not installed [Arduino IDE](https://www.arduino.cc/en/software), or have a version older than 08.15, you need to install/update your [Arduino IDE](../../ide/ide-arduino-IDE-setup/).

Adafruit has detailed [instructions for setting up the Feather nRF52840](https://learn.adafruit.com/adafruit-feather-sense/arduino-support-setup). Gerald Recktenwald has written a shorthand instruction for [Set up the Arduino IDE for the Feather nRF52840 Sense](https://web.cecs.pdx.edu/~gerry/class/feather_sense/setup/).

#### Port driver

This is the correct url for the [port driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers).

#### Update bootloader

I think (!) that you have to update the bootloader, see [learn adafruit: Update Bootloader](https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/update-bootloader).

![trx-connector](../../images/finder_nrf52840Bootloader-mounted-FTHR840BOOT.png)
{: .pull-right}
If your usb cable connects properly to nRF52840, you will see the bootloader as a mounted disk (on MacOS: /Volumes/FTHR840BOOT). Explore the mounted Bootloader disk, and you should see (at least) three files:

```
CURRENT.UF2
INDEX.HTM
INFO_UF2.TXT
```

Open <span class='file'>INFO_UF2.TXT</span> to check the Bootloader version. My nRF52840 came with this version:

```
UF2 Bootloader 0.2.6 lib/nrfx (v1.1.0-1-g096e770) lib/tinyusb (legacy-525-ga1c59649) s140 6.1.1
Model: Adafruit Feather nRF52840 Express
Board-ID: NRF52-Bluefruit-v0
Bootloader: s140 6.1.1
Date: Dec 21 2018
```

The nRF52 Bootloader can be upgraded/downgraded without any additional hardware. There are 3 different ways to update bootloader as outlined on the [Update Bootloader page](https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/update-bootloader). The easiest and fastest is to use the _UF2_ method (the alterantives is to use Arduino IDE or the command line version of the Arduino IDE setup).

##### UF2 Bootloader update

UF2 Bootloader update is the fastest and safest way to update bootloader. However, it requires your existing bootloader is at least 0.4.0 and only work with nRF52840. As you can see above my nRF52840 is too old (UF2 Bootloader = 0.2.6), I cannot use the UF2 Bootloader update.

If you have at least Bootloader 0.4.0 see the page [Use UF2](https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/update-bootloader-use-uf2) and simply drag and drop the most recent Bootloader on to the mounted Bootloader disk.

##### Command line Bootloader Update

Follow the instructions on the Arduino page for updating the [nRF52840 bootloader using Command Line](https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/update-bootloader-use-command-line).

![bootloader](../../images/nRF52840_bootloader-zip-link-button.png)
{: .pull-right}
Start by downloading the files, click the green button (right) and you will end up in a GitHub repo. The file you want to download is <span class='file'>feather_nrf52840_express_bootloader-0.6.4_s140_6.1.1.zip</span>.

![adafuit-nrfutility](../../images/adafruit-nrfutil-macos-button.png)
{: .pull-right}
You also need either python3 or the _adafuit-nrfutility_ app. Download the app by clicking the button on the Adafruit page (shown to the right). You will again end up in a [GitHub repo](https://github.com/adafruit/Adafruit_nRF52_nrfutil/releases/tag/0.5.3.post17), the file you want (for MacOS) is <span class=file>adafruit-nrfutil--0.5.3.post17-win.zip</span>. Copy the adafruit-nrfutil to the directory where you want it. Then open the <span class='app'>Terminal</span>, change directory (<span class='terminapp'>cd</span>) to the directory where you saved it.

<span class='terminal'>% cd /Users/thomasgumbricht/Documents/Arduino/nRF52840</span>

Change the mode of the file to allow it to be executed:

<span class='terminal'>% chmod +x adafruit-nrfutil</span>

Make sure the Bootloader is mounted. If it is not double click the reset button near the micro-usb on the nRF52840 board. The use <span class='app'>Finder</span> to open the Bootlodear.

Return to the <span class='app'>Terminal</span> and run the command:

<span class='terminal'>ls /dev/cu.*</span>

```
/dev/cu.Bluetooth-Incoming-Port	/dev/cu.usbmodem14101
```

The response indicates the usb port where nRF52840 is mounted.

```
./adafruit-nrfutil --verbose dfu serial --package feather_nrf52840_express_bootloader-0.6.4_s140_6.1.1.zip -p /dev/cu.usbmodem14101 -b 115200 --singlebank --touch 1200
```

```
(base) thomasgumbricht@MacBook-Air BootLoader % ./adafruit-nrfutil --verbose dfu serial --package feather_nrf52840_express_bootloader-0.6.4_s140_6.1.1.zip -p /dev/cu.usbmodem14101 -b 115200 --singlebank --touch 1200
Upgrading target on /dev/cu.usbmodem14101 with DFU package /Users/thomasgumbricht/Documents/Arduino/nRF52840/BootLoader/feather_nrf52840_express_bootloader-0.6.4_s140_6.1.1.zip. Flow control is disabled, Single bank, Touch 1200
Touched serial port /dev/cu.usbmodem14101
Opened serial port /dev/cu.usbmodem14101
Starting DFU upgrade of type 3, SoftDevice size: 151016, bootloader size: 39000, application size: 0
Sending DFU start packet
Sending DFU init packet
Sending firmware file
########################################
########################################
########################################
########################################
########################################
########################################
########################################
########################################
########################################
############
Activating new firmware

DFU upgrade took 20.710694789886475s
Device programmed.
```

If you check the Bootloader file <span class='file'></span>, it should now show that the bootloader is updated:

```
UF2 Bootloader 0.6.4 lib/nrfx (v2.0.0) lib/tinyusb (0.12.0-145-g9775e7691) lib/uf2 (remotes/origin/configupdate-9-gadbb8c7)
Model: Adafruit Feather nRF52840 Express
Board-ID: nRF52840-Feather-revD
Date: May 17 2022
SoftDevice: S140 6.1.1
```

### Arduino IDE

To use Arduino nRF528 Feather boards with Arduino IDE, follow the instructions [Set up the Arduino IDE for the Feather nRF52840 Sense](https://web.cecs.pdx.edu/~gerry/class/feather_sense/setup/).
