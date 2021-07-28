---
layout: post
title: Adafruit Feather nRF52840
categories: microcontroller
excerpt: "Adafruit Feather nRF52840"
tags:
  - Adafruit Feather nRF52840
  - BLE
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2021-06-16 11:27'
modified: '2021-06-16 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

[https://www.inesarex.com/electrode/](https://www.inesarex.com/electrode/)

Building a 3.7v LiPo 1200mAh battery powered project using Arduino Nano and Arduino Nano33 IoT ([spectrolum version 61](../../spectrolum/spectrolum-v0061/)), I could not get the AMS spectrometer started while on battery power only. As long as the usb power is connected, the AMS spectrometer initiates and captures the incident light. If only on battery power, the AMS spectrometer flickers a single blue flare, but never initiates. Strangely, if the usb is connected and the AMS allowed to start, the usb can be pulled out and the AMD continues to register the light conditions while on battery power only.

I also tried with an external power supply (9v, 2A) but the behaviour is the same when on battery power. Also reported by [others](https://forum.arduino.cc/t/unable-to-run-my-project-on-battery/702514/7). All hints I could find online point towards insufficient power supply being the culprit while on battery power. It is also reported that sketch (programmatic) errors can cause similar behavior.

As Arduino Nano and Arduino Nano33 IoT does not have any battery charge or drain regulation, the setup tested included a [separate power solution](../../module/module-batteri/). An alternative solution is to use a microcontroller board with integrated battery power control. The [Arduino Feather ecosystem of microcontrollers](https://www.adafruit.com/category/943) were built specifically for battery powered projects.

### Adafruit Feather nRF52840

Among the many alternative Feather boards, I opted for the [nRF52840](https://learn.adafruit.com/introducing-the-adafruit-nrf52840-feather/downloads).

#### Setup IDE

This section is following the article  [Setup Arduino IDE for Feather nRF52840](https://web.cecs.pdx.edu/~gerry/class/feather_sense/setup/).

Open the preferences

<span class='menu'> -> preferences</span>

Under the <span class='tag'>Settings</span> tag enter the following url to the <span class='textbox'>Additional Boards Manager URLs</span> textbox:

```
https://www.adafruit.com/package_adafruit_index.json
```

<figure>
<img src="../../images/arduino-ide_preferences-settings.png">
<figcaption> </figcaption>
</figure>

Note: If you have other boards installed in the Additional Boards Manager, the individual URLs should be separated with a comma, or on separate lines. Clicking on the icon to the right of the text input box will expand the box so that you can easily add multiple libraries on separate lines.

#### Add Arduino Support for the Adafruit Feathers

From the Arduino IDE select menu select:

<span class='menu'>Tools –> Board –> Boards Manager</span>

Type _adafruit_ in the search box and then scroll down until you see the _Adafruit rFN52_ entry.

<figure>
<img src="../../images/arduino-ide_boards-adafruit-rFN52.png">
<figcaption> </figcaption>
</figure>

### Connect to board


#### Fuckup

And then Arduino IDE can not compile, reporting a Python related error:

```
Error loading Python lib '/var/folders/89/5hq4qf4s46dct8lrl9w46f640000gn/T/_MEIehQT3R/libpython3.8.dylib': dlopen: dlopen(/var/folders/89/5hq4qf4s46dct8lrl9w46f640000gn/T/_MEIehQT3R/libpython3.8.dylib, 10): Symbol not found: _preadv
```

This problem is [reported by others,(https://forums.adafruit.com/viewtopic.php?f=25&t=168759) but due to my complex installation of Python using Anaconda, I am not sure how to solve the problem.

```
pip3 install --user adafruit-nrfutil
Collecting adafruit-nrfutil
  Downloading adafruit-nrfutil-0.5.3.post16.tar.gz (49 kB)
     |████████████████████████████████| 49 kB 3.1 MB/s
Requirement already satisfied: click>=5.1 in /Applications/anaconda3/lib/python3.7/site-packages (from adafruit-nrfutil) (7.1.2)
Collecting ecdsa>=0.13
  Downloading ecdsa-0.17.0-py2.py3-none-any.whl (119 kB)
     |████████████████████████████████| 119 kB 10.5 MB/s
Requirement already satisfied: six>=1.9.0 in /Applications/anaconda3/lib/python3.7/site-packages (from ecdsa>=0.13->adafruit-nrfutil) (1.15.0)
Collecting pyserial>=2.7
  Downloading pyserial-3.5-py2.py3-none-any.whl (90 kB)
     |████████████████████████████████| 90 kB 6.4 MB/s
Building wheels for collected packages: adafruit-nrfutil
  Building wheel for adafruit-nrfutil (setup.py) ... done
  Created wheel for adafruit-nrfutil: filename=adafruit_nrfutil-0.5.3.post16-py3-none-any.whl size=85180 sha256=68500e2db23b79509025a5ffb3d861741a886db22a632ca0811e6ae924ec7f67
  Stored in directory: /Users/thomasgumbricht/Library/Caches/pip/wheels/50/07/33/74ac2ec517a709070f93e95e54b0bb79df42d7774642498af4
Successfully built adafruit-nrfutil
Installing collected packages: pyserial, ecdsa, adafruit-nrfutil
  WARNING: The scripts pyserial-miniterm and pyserial-ports are installed in '/Users/thomasgumbricht/.local/bin' which is not on PATH.
  Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
  WARNING: The script adafruit-nrfutil is installed in '/Users/thomasgumbricht/.local/bin' which is not on PATH.
  Consider adding this directory to PATH or, if you prefer to suppress this warning, use --no-warn-script-location.
Successfully installed adafruit-nrfutil-0.5.3.post16 ecdsa-0.17.0 pyserial-3.5
(base) Thomass-Air:~ thomasgumbricht$
```

So I added the PATH to <span class='file'>.bash_profile</span>:

<span class='terminal'>$ pico .bash_profile</span>

```
export PATH="/Users/thomasgumbricht/.local/bin:$PATH
```

### ESP32 processor

As an alternative I got an ESP32 based development board from [Bnaggood.com]().

Th particular board that I got (LOLIN32 V1.0.0 ESP32) is introduced in a [youtube](https://www.youtube.com/watch?v=0UiqDL8x7ek), whereas The guy with the Swiss accent (Andreas Spiess) has a general introduction on the [ESP32 Tutorial / Arduino IDE / Tests ...](https://www.youtube.com/watch?v=jhjZZkKupk8).
