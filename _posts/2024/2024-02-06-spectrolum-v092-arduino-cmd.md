---
layout: post
title: Arduino commands
categories: spectrolum
version: v0.92
excerpt: "Arduino commands"
tags:
  - spectrometer
  - xspectrolum
  - arduino
  - command

image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2024-02-06'
modified: '024-02-06'
comments: true
share: true
---

## Introduction

This post explains the firmware setup and the commands sent to the microcontroller.

## Firmware

The firmware is uploaded via a USB cable. In version 0.7x through 0.9x the microcontroller had to be removed from the Printed Circuit Board (PCB) for the code to be compiled and uploaded. Starting with version 1.0x switching a jumper will allow a new firmware version to be uploaded. The firmware only occipies part of the memory capacity of the microcontroller internal memory, the remaining part can be used as a small hard drive reading and writing files. This capacity is utilised for storing metadata about each spectrometer, including calibration data for the spectral range and the setting of lamps. Files are read and written via commands sent by the user.

## Command structure

The command code sent from the user to the microcontroller is enclosed in a tag with individual arguments separated by semi-colon "<arg1;arg2;arg3>".

The first argument (argument 0) defines the command itself. All the following arguments are specific for each (group of) commands. The commands are divided in the following categories:

- File operations
- Spectra sensor setup and tuning
- Spectral scanning
- Probe tuning
- Probe observation

### File operations

File operations can be accessed directly by the user through sending commands to the microcontoller. The primary objective of the file operations, however, are for automatic (default) reading and writing of information generated as part of other processes (for example uuid tagging, instrument tuning, scan calibration and combination of sensor and muzzles).

Table 1 lists the different file system commands included in the Arduino code:

| command | argument | action |
| remove file(s) | removefiles4fs | remove (delete) listed files |
| remove directories |  removedirs4fs | remove (delete) listed directories |
| list files | listfiles4fs | list files in the branch of the directory tree defined |
| make directory | mkdris4fs | make directories as listed in the command |
| create file and write data | writedata4fs | create file with given name and write the given data |
| rename file | renamedata4fs | rename file from source name to target name |

All the actual data are parsed to and from json structured text.

#### Remove files command

Example code:

```
<removefiles4fs;2;1;sensors.json;/sensors/mainsensor.json>
```
Argument 0: command
Argument 1: number of files to delete
Argument 2: verbosity
Arguments 3 & 4: full path to the files to delete

#### Remove directories command

Example code:

```
<removedirs4fs;1;1;/sensors>
```
Argument 0: command
Argument 1: number of directories to delete
Argument 2: verbosity
Arguments 3: full path to the directory to delete

#### List files command

Example code:

```
<listfiles4fs;2;1;/sensors>
```
Argument 0: command
Argument 1: depth level from root directory to search for file listing
Argument 2: verbosity
Argument 3: full path to the root directory for which to list files

#### Make directory command

Example code:

```
<mkdirs4fs;7;1;spectralsensors;modbussensors;i2csensors;analogsensors;isesensors;scantuning;scandata>
```
Argument 0: command
Argument 1: number of directories to make
Argument 2: verbosity
Argument 3: full path to the directories to make

#### Create file and write data command

Example code:

```
 <writedata4fs;1;1;/sensors.json;{"spectralsensors":["c14384ma-01"],"modbussensors":["tsmnpkph","ph"],"i2csensors":["mhz16","ams6bandnir"],"analogsensors":["capacitive_sm","mic"],"isesensors":["ph"]}>
```
Argument 0: command
Argument 1: number of files to create and write
Argument 2: verbosity
Argument 3: full path to the file 1 to create
Argument 4: file 1 content in json format
Argument 5: full path to the file 2 to create
Argument 6: file 2 content in json format
...

#### Rename file command

Example code:

```
 <renamedata4fs;1;1;/sensors.json;/sensors_backup.json>
```
Argument 0: command
Argument 1: number of files to rename
Argument 2: verbosity
Argument 3: full path to the source file name
Argument 4: full path to the destination file name
...


### Spectra sensor and muzzle setup and tuning

Every xSpectrometer<b>+</b> comes with a spectral sensor. As the xSpectrometer<b>+</b> can carry any of up to ten (10) different sensors, the make, model and version of the sensor attached must be registered. Each sensor also receives a universally unique identifier (UUID) that is written to the file system of the microcontroller and registered in the xSpectre online database. The registering is only done once and is completed by using the command argument <writedata4fs> listed above.

All the cheaper sensors operating in the visible to NIR range up to approximately 1050 nm are built using silicon based Complementary Metal Oxide Semiconductor (CMOS) technology. These senors have their peak sensitivity around 500 nm, with diminishing sensitivity towards both the shorter (blue) wavelengths and in particular towards the NIR wavelengths.

All spectral sensors have a nominal range and resolution of wavelengths that they capture. But the more advanced grating based sensors are also individually calibrated and come with (polynomial) translators that expresses each pixel (well) as a more exact wavelength. Also this calibration data is written to the file system of the microcontroller.

Except for the xSpectrometer<b>+</b> that carries the AS7421 64-band sensor with inbuilt light, all spectral sensors requires a muzzle with a light source. Muzzles as such only come in three (3) different types, for:

- solid samples,
- transparency (absorbance) of liquid/gaseous samples, and
- fluorescence/Raman spectroscopy of liquid/gaseous samples.

All three types can be equipped with a range of different lamps, including incandescent light bulbs, broad band LEDs, narrow band LEDs and lasers. It is also possible to combine two LEDs for solid samples. This leads to a total maybe 50 types of muzzles available for different applications.  

Every make and model of a lamp have nominal properties including for voltage setting (min, max, typical), power consumption, illumination and spreading angle. In reality these properties varies, a variation that is accentuated by minor differences in the PCBs and the (complex) components used for regulating voltage, and also the soldering and the exact position and tilt of the lamp of each single muzzle.

Each combination of muzzle type and lamp is given a code, an UUID and the typical, minimal and maximum voltage. This data is written to the EEPROM memory that sits in every light carrying muzzle and is also registered in the xSpectre online database.

#### Combined calibration of spectral sensor and muzzle

As a consequence of the individual variations in both spectral sensors and the muzzle light sources, each combination of sensor + muzzle needs to be separately tuned. The tuning in effect sets the final voltage and the integration time of the spectral sensor.

The final voltage is seldom tuned to deviate from the make and model given "typical" voltage. Only if the "typical" voltage causes the sensor to become saturated is the voltage reduced.

The integration time (equaling exposure time on a camera), however needs to be tuned. The main reason for this is to overcome variations in sensor sensitivity and lamp luminosity over the sensor observation range. The tuning is always done vis-a-vis a maximum reference object. For solid samples that equals a pure white surface, for transparency analysis of liquid/gaseous samples an empty sample space or sample holder (e.g. an empty cuvette).

The tuning can be done using either a single integration time or an automated segmentation of integration times over the sensor range. The latter is strongly recommended as it improves the useful spectral range and decreases the signal to noise ratio.

#### Scan tuning command

The tuning command is the same for all combination of sensors and muzzles(?).

Example code:

```
 <ma12880;0;1;0;0;6;2;2;6;900;-99;-99;-99;-99;>
```
- Argument 0: sensor [should be replaced with "scantuning"]
- Argument 1: not used [used to be campaign]
- Argument 2: verbosity
- Argument 3: not used [used to be operation - that is now the argument itself]
- Argument 4: not used [used to be return format]
- Argument 5: nr sample Repeats [6]
- Argument 6: nr darkRepeats [2]
- Argument 7: nr headtrail [2]
- Argument 8: warmup [6]
- Argument 10: not used [prev = muzzleid]
- Argument 11 = not used [prev = forward voltage, set in muzzle, needs to be part of tuning]
- Argument 12 = not used [prev = fetchwhiteref]
- Argument 13 = not used [prev = fetchscantuning]
- Argument 14 = stabilisationTime
- Argument 15 = nIntegrationTimes [number of integrationtimes to set]
- Argument 16 = iniIntegrationtime [initial integration time]
- Argument 17 = ascendingstep [increase in integration until maxDN is surpassed]
- Argument 18 = descendingstep [descending step in integration until signal max is below maxDN]

##### Alternative new command structure

```
 <scantuning;1;6;2;2;6;900;300;3;100;5;2>
```
- Argument 0: scantuing
- Argument 1: verbosity [0/1]
- Argument 2: nr sample Repeats [6]
- Argument 6: nr darkRepeats [2]
- Argument 7: nr headtrail [2]
- Argument 8: warmup [6  depends on lamp]
- Argument 9: stabilisationTime [in milliseconds, depends on lamp]
- Argument 10: nIntegrationTimes [number of integrationtimes to set]
- Argument 11: iniIntegrationtime [initial integration time, depends on combination of sensor and lamp]
- Argument 12: ascendingstep [increase in integration until maxDN is surpassed, could be automated?]
- Argument 13: descendingstep [descending step in integration until signal max is below maxDN, could be automated?]



The first three arguments carry the same kind of information regardless of the command:

1.sensor (e.g. c12880ma)
  param1 = campaign = uuid:
  param2: verbose (0 = quiet, 1 = verboe, 2 = more verbose)
  param3; operation





param0: sensor (e.g. c12880ma)
  param1 = campaign = uuid:
  param2: verbose (0 = quiet, 1 = verboe, 2 = more verbose)
  param3; operation
   0 = test scan;
   1 = sample scan;
   2 = set/update default auto scan tuning;
   3 = set/update default fixed scan tuning;
   4 = set/update named scan tuning;
   6 = adjust scan tuning integration times;
   7 = set/update default white ref;
   8 = set/update named white ref;  
   9 = test scan with options;

   26 = set/update default auto scan tuning + adjust scan tuning integration times
   36 = set/update default fixed scan tuning + adjust scan tuning integration times
   46 = set/update named scan tuning + adjust scan tuning integration times


   27 = (2+7) set/update default auto scan tuning + whiteref;
   37 = (3+7) set/update default fixed scan tuning + whiteref;

   267 = (2+6+7) set/update default auto scan tuning + adjust scan tuning integration times + whiteref;

   47 = set/update named scan tuning + whiteref;

   125 = sample scan with default scan tuning + whiteref;

   145 = sample scan with named scan tuning +

   129 = sample scan with default scan tuning + in-sampling whiteref;

   149 = sample scan with namedscan tuning + in-sampling whiteref;

   92 = test scan with default scan tuning
   94 = test scan with named scan tuning

   11 = read scan tuning, 12 = read whiteRef, 13 read and test campaign scan tuning,

  ### param 4 to 8 not required is the scantuning is set to auto
  param4: return (0 = mean % std, 1 = full data)
  param5; nr sample Repeats, default = 6
  param5; nr darkRepeats, default = 6
  param7; nr headtrail, default = 2
  param8; warmup, defaut = 6
  param9 = maxDN = 800:



  ### From here on the params are only for spectral scanning       
  param10 = muzzle = 1206VINI:
  param11 = vset_mV = 1500:
  param12 = fetchWhiteRef: 0 = none, 1 = in-sampling, 2 = campaign white ref, 3 = muzzle white ref; 4 = automatic; 5 = file;
  param13 = fetchScanTuning: 0 = none; 1 = user defined, 2 = campaign default, 3 = muzzle default; 4 = automatic; 5 = file;
  param14 = stabilisationTime = 200;
  param15 = nIntegrationTimes = 3:

  // Automatic scan tuning
  param16 = iniIntegrationtime = 200:
  param17 = ascendingstep = 20:
  param18 = descendingstep = 5:

  // Params if operation expects filename
  param19 = filename = /path/to/file.json

  // Params if operation in [7, 8 27, 28] or operation in [0,1] and get integrationtime = 0
  param16 = integrationsTime0 = 200:
  param17 = startPixelIntegrationTime0 = 64:
  param18 = endPixelIntegrationTime0 = 256:

  param19 = integrationsTime1 = 200:
  param20 = startPixelIntegrationTime1 = 89:
  param21 = endPixelIntegrationTime1 = 200:

  oaram22 = integrationsTime2 = 200:
  param23 = startPixelIntegrationTime2 = 89:
  param24 = endPixelIntegrationTime2 = 200:

  param25 = integrationsTime3 = 200:
  param26 = startPixelIntegrationTime3 = 89:
  param27 = endPixelIntegrationTime3 = 200:  

  param28 = integrationsTime4 = 200:
  param29 = startPixelIntegrationTime4 = 89:
  param30 = endPixelIntegrationTime4 = 200:
*/
