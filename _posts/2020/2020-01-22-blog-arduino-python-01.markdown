---
layout: post
title: Arduino with Python
categories: blog
excerpt: "Arduino with Python"
tags:
  - microcontroller
  - Arduino
  - Python
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-22 11:27'
modified: '2020-01-22 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

### Prerequisites

to follow this manual you need to install Anaconda and Eclipse, and set up Eclipse for Python.

### Media sources

These youtube lessons are too lengthy (American) the same stuff i regurgitated a dozen times and you never get anywhere. But anyway.
1
[https://www.youtube.com/watch?v=95w4sx_zoB8](https://www.youtube.com/watch?v=95w4sx_zoB8)

2 [https://www.youtube.com/watch?v=mF5cE3DS50s&list=PLGs0VKk2DiYylFUUMMv9WiL3x3tpscDUQ](https://www.youtube.com/watch?v=mF5cE3DS50s&list=PLGs0VKk2DiYylFUUMMv9WiL3x3tpscDUQ)

https://www.youtube.com/watch?v=d8_xXNcGYgo

[Prototyping Arduino Projects using Python](https://hub.packtpub.com/prototyping-arduino-projects-using-python/)

### Virtual Conda environment for Arduino Python

I run all my Python projects as [Conda virtual environments](https://karttur.github.io/setup-ide/setup-ide/conda-environ/). To set up an environment for Arduino Python, start the <span class='app'>Terminal</span>.

The general command for creating a conda virtual environment is:

<span class='terminal'>$ conda create –name arduino_XX</span>

If you want to specify which version of python to install and the packages to start with, the command can be extended (see the conda page on [Managing environments](https://docs.conda.io/projects/conda/en/latest/user-guide/tasks/manage-environments.html#managing-environments) for details):

<span class='terminal'>$ conda create –n arduino_01 python=3.6 numpy</span>

If you have <span class='file'>.condarc</span> file defining a set of default packages and do **not**  want to include them in your arduino environment, then add the command _--no-default-packages_:

<span class='terminal'>$ conda create --no-default-packages –n arduino_01 python=3.6 numpy</span>

It is always best to install all (or as many as possible) of the packages that are needed for your environment in one go. Conda will then automatically resolve any dependency conflicts. For my arduino environment I wanted the following packages:

- pip
- pyfirmata
- time

As this is my first trial, I do not know about versions, so I will just go for the defaults in Python 3.6. The (theoretical) command for creating my virtual Python envirnment for Arduino Python thus becomes:

<span class='terminal'>$ conda create --no-default-packages –n arduino_01 python=3.6 pip pyfirmata time</span>

But that does not work, I get error messages. It might have to do with my <span class='file'>.condarc</span> file (or lack of this file). Having tried various commands I ended up with this stripped version:

<span class='terminal'>$ conda create -n arduino_01 python=3.6 pip</span>

And then the command (finally!)) went through. The terminal window reports what is happening, then stops and prompts for an answer whether to Proceed or not:

```
The following NEW packages will be INSTALLED:

  ca-certificates    pkgs/main/osx-64::ca-certificates-2019.11.27-0
  certifi            pkgs/main/osx-64::certifi-2019.11.28-py36_0
  libcxx             pkgs/main/osx-64::libcxx-4.0.1-hcfea43d_1
  libcxxabi          pkgs/main/osx-64::libcxxabi-4.0.1-hcfea43d_1
  libedit            pkgs/main/osx-64::libedit-3.1.20181209-hb402a30_0
  libffi             pkgs/main/osx-64::libffi-3.2.1-h475c297_4
  ncurses            pkgs/main/osx-64::ncurses-6.1-h0a44026_1
  openssl            pkgs/main/osx-64::openssl-1.1.1d-h1de35cc_3
  pip                pkgs/main/osx-64::pip-19.3.1-py36_0
  python             pkgs/main/osx-64::python-3.6.10-h359304d_0
  readline           pkgs/main/osx-64::readline-7.0-h1de35cc_5
  setuptools         pkgs/main/osx-64::setuptools-44.0.0-py36_0
  sqlite             pkgs/main/osx-64::sqlite-3.30.1-ha441bb4_0
  tk                 pkgs/main/osx-64::tk-8.6.8-ha441bb4_0
  wheel              pkgs/main/osx-64::wheel-0.33.6-py36_0
  xz                 pkgs/main/osx-64::xz-5.2.4-h1de35cc_4
  zlib               pkgs/main/osx-64::zlib-1.2.11-h1de35cc_3


Proceed ([y]/n)?
```

Just the the _Y_ key and install. Once finished, change to the virtual environment at the terminal:

<span class='terminal'>$ conda activate arduino_01<(span)>

If all has worked out, the terminal line should start the command line text with the name of the your environment in parenthesis:
<span class='terminal'>(arduino_01)<(span)>

### Install additional packages

As I did not manage to install the packages I wanted when creating the virtual environment, I need to do that while the new environment (arduino_01) is active. Going though the list of packages, here is how to install them at time of writing this manual (January 2020):

#### pyfirmata

[pyFirmata][https://pypi.org/projects/pyFirmata/] is a Python interface for the [Firmata](https://github.com/firmata/protocol) protocol. Firmata protocol is for communicating with microcontrollers from software on a computer (or smartphone/tablet, etc). The protocol can be implemented in firmware on any microcontroller architecture as well as software on any computer software package (see list of client libraries below).

<span class='terminal'>$ conda install -c conda-forge pyfirmata<(span)>

#### pyserial

<span class='terminal'>$ conda install -c anaconda pyserial<(span)>

#### time

<span class='terminal'>$ conda install -c conda-forge time<(span)>

#### tkinter

<span class='terminal'>$ conda install tk<(span)>

### Eclipse

I use <span class='app'>Eclipse</span> for writing my Python scripts. As stated in the Prerequistists you have to have <span class='app'>Eclipse</span> installed.

#### Define Python interpreter

In the Eclipse menu select:

<span class='menu'>Eclipse -> Preferences</span>

In the left column expand _Pydev_ and _Python Interpreter_ (as shown in the figure below). Click the button for <span class='button'>Browse for python/pydev exe</span> and navigate to the virtual environments under your <span class='app'>Anaconda</span> installation (also shown). Select the python program file and click <span class='button'>OK</span> in the <span class='window'>Select interpreter</span> window. With all options selected (default), also click <span class='button'>OK</span> in the <span class='window'>Selection needed</span> window that pops up. When finished click the <span class='button'>Apply and Close</span> button in the <span class='window'>Preferences</span> window.

<figure>
<img src="../../images/eclipse_select_python_interpreter.png">
<figcaption> Select python interpreter for Eclipse.</figcaption>
</figure>

#### Create Project

From the <span class='eclipse'>Eclipse</span> menu select:

<span class='menu'>File -> New -> Project </span>

<figure>
<img src="../../images/eclipse_new_project_wizard.png">
<figcaption> Select the PyDev Project Wizard.</figcaption>
</figure>

In the wizard for PyDev project, keep all the default entries and just add a <span class='textbox'>Project Name</span>.

<figure>
<img src="../../images/eclipse_define_python_project.png">
<figcaption> Define PyDev project</figcaption>
</figure>

When you click <span class='button'>Finish</span>, <span class='app'>Eclipse</span> will ask if you want to change to the Python perspective, accept that suggestion.

#### Create package and module

With <span class='app'>Eclipse</span> setup and prepared for Python, and your project defined, create a python package (shown in the figure below) and then a python module. Create both from the menu:

<span class='menu'>File -> New -> PyDev Package</span>
<span class='menu'>File -> New -> PyDev Module</span>

<figure>
<img src="../../images/eclipse_define_python_package.png">
<figcaption> Define Python package</figcaption>
</figure>

#### Test packages

Small test script that utilizes the packages you installed in your virtual environment:

```
import pyfirmata
import time

board = pyfirmata.Arduino('/dev/ttyACM0')

while True:
    board.digital[13].write(1)
    time.sleep(1)
    board.digital[13].write(0)
    time.sleep(1)
```

Try to run the script.

<figure>
<img src="../../images/arduino_python_module_01.png">
<figcaption>Arduino Python module</figcaption>
</figure>

If the script compiles you are fine. As you (probably) do not have any Arduino board attached, the script will report an error not finding the board, but that is OK for now.

### Arduino test

With the system setup you can search for online manuals that will take you through the details of how to run Arduino Python.

[Arduino With Python: How to Get Started](https://realpython.com/arduino-python/)

[How to Program and Control an Arduino With Python](https://www.makeuseof.com/tag/program-control-arduino-python/)

This manual uses pyserial instead of pyfirmata:

[Using Python with Arduino - Controlling an LED](https://circuitdigest.com/microcontroller-projects/arduino-python-tutorial)
