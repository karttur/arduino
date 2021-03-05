---
layout: post
title: Arduino and Python
categories: project
excerpt: "Serial connect Arduino and Python"
tags:
  - spectrometer
  - Sensors
  - Hamamatsu
  - C12880MA
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-05-23 11:27'
modified: '2021-01-06 T18:17:25.000Z'
comments: true
share: true

projectuno: null
---

### Introduction

Serial connect Arduino and Python


### Arduino sketch

The simple Arduino code below reads a number, adds one (1) to the number and returns the number via _Serial.print_.

```
int x;
void setup() {
 Serial.begin(115200);
 Serial.setTimeout(1);
}
void loop() {
 while (!Serial.available());
 x = Serial.readString().toInt();
 Serial.print(x + 1);
}
```

### Python module

Import the [pyserial](https://github.com/pyserial/pyserial) package. If. like me, you use _Anaconda_ for managing your Python environments, use conda to get _pyserial_:

<span class='terminal'>$ conda install pyserial</span>

or get it via _pip_:

<span class='terminal'>$ pip install pyserial</span>

You can now use python to identify the serial ports on your machine:

<span class='terminal'>$ python -m serial.tools.list_ports</span>

Copy the port that harbours your Arduino board and paste it into the code snippet:

```
import serial

import time

arduino = serial.Serial(port='/yourPortType/yourPortId', baudrate=115200, timeout=.1)

def write_read(x):

    arduino.write(bytes(x, 'utf-8'))

    time.sleep(0.05)

    data = arduino.readline()

    return data

while True:

    num = input("Enter a number: ") # Taking input from user

    value = write_read(num)

    print(value) # printing the value
  ```

If all worked your Python script should connect to Arduino, ask for a number that will be returned by Arduino + one.

## Resources

[](https://create.arduino.cc/projecthub/ansh2919/serial-communication-between-python-and-arduino-e7cce0)

[](https://problemsolvingwithpython.com/11-Python-and-External-Hardware/11.04-Reading-a-Sensor-with-Python/)
