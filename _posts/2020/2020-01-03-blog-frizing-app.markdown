---
layout: post
title: The Fritzing design app
categories: blog
excerpt: "Install the Fritzing project design app"
tags:
  - arduino IDE
  - Fritzing
  - Mac OSX
  - Nano
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-01-03 11:27'
modified: '2020-01-03 T18:17:25.000Z'
comments: true
share: true
---

## Introduction

"[Fritzing](https://fritzing.org/home/) is an open-source hardware initiative that makes electronics accessible as a creative material for anyone. We offer a software tool, a community website and services in the spirit of Processing and Arduino, fostering a creative ecosystem that allows users to document their prototypes, share them with others, teach electronics in a classroom, and layout and manufacture professional pcbs."

This tutorial is just a quick startup guide for <span class='app'>Fritzing</span>, if you want to learn a bit more the [youtube Fritzing Tutorial - A Beginners Guide to Making Circuit & Wiring Diagrams by Troy Baverstock](https://www.youtube.com/watch?v=-saXw1EipX0) is a good place.

## Get the Fritzing app

Go to the [Fritzing download page](https://fritzing.org/download/) and either pay the voluntary amount or skip it. The Mac OSX binary is downloaded as a disk image (<span class='app'>.dmg</span>) file. Open it by double clicking and drag (copy) the <span class='app'>Fritzing</span> app to your <span class='file'>Applications</span> folder.

If <span class='app'>Fritzing</span> requires security clearance for being "unverified" you have to go via the Mac OSX menu:

<span class='menu'>"apple" -> System Preferences... </span>

and then to _Security & Privacy_ and allow <span class='app'>Fritzing</span> to launch.

The first time you (successfully) launch <span class='app'>Fritzing</span> it will create a <span class='file'>Fritzing</span> folder in your home directory. The folder contains two sub-folders: <span class='file'>bins</span> and <span class='file'>parts</span> where your diagrams and custom components etc will be stored once you start using <span class='app'>Fritzing</span>.

## Your first project

Start <span class='app'>Fritzing</span>. You should get the welcome screen shown below.

<figure>
<img src="../../images/fritzing-app_01.png">
<figcaption> Fritzing app startup GUI.</figcaption>
</figure>

### Organize the breadboard

![fritzing-app-inspector_03](../../images/fritzing-app-inspector_03.png)
{: .pull-right}
Click the <span class='button'>Breadboard</span> menu button (illustrated in the figure below), and you should see a full size breadboard. The breadboard attributes are shown in the _Inspector_ window (full inspector window for the breadboard shown to the right) at the bottom of the right column in the GUI. In the _Inspector_ you can change the breadboard _size_ as indicated in the figure below. For this tutorial I changed to _half+_ and then rotated the breadboard 90 degrees (under the _rotation_ option just above the _size_ option). To move the breadboard, hold down the _space_ bar/key, grab the breadboard with the mouse and move it.

<figure>
<img src="../../images/fritzing-app_02.png">
<figcaption> Arrange the breadboard in the Fritzing app.</figcaption>
</figure>

### Add arduino board

![fritzing-app-select-arduino-board_04](../../images/fritzing-app-inspector_04.png)
{: .pull-right}
In the upper _Parts_ window of the right column, click the <span class='button'>Arduino</span> button (shown to the right), and select the microprocessor that goes with your project. For my project I selected an _Arduino Nano_ board. Note how the _Inspector_ changed to reflect that the Arduino Nano board is now the selected item in the Breadboard window.

### Add a wire

![fritzing-app-inspector_03](../../images/fritzing-app_05.png)
{: .pull-right}
When you hover over connection point on either the breadboard or the Arduino board, the app will change color for the connection point and a small info-box pops up (as for the _GND_ connection on the Arduino Nano board to the right). To attach a wire to the connection, click and hold the left mouse button, then drag the mouse to the target connector and release the left mouse button to attach the wire. As illustrated below.

<figure>
<img src="../../images/fritzing-app_06.png">
<figcaption> While holding the left mouse button, drag the wire to the target connector, then release the buttom to attach.</figcaption>
</figure>

Use the mouse to add bendpoints and move the wire - left click anywhere along the wire, hold the button and drag into place, then release to let go of the wire. To change the color, either hover over the wire and click the ctrl-key, then _color_ in the pop-up window, or select the wire and use the _Inspector_ entry for color. To force 90-degree bends (or horisontal and vertical wires), hold down the shift-key while moving the bendpoint and it will only take on discrete positions.

### Add led and resistor

![fritzing-app-inspector_07](../../images/fritzing-app_07.png)
{: .pull-right}
The <span class='app'>Fritzing</span> app comes preloaded with all kinds of standard components. They are all available under different tabs in the _Parts_ window. In the example below I have completed a very simple project adding just a LED, a resistor and a power wire for the LED. The code (sketch) for turning the led on and off are in the post on [Arduino Nano project preparation](../arduino-nano-setup).

![fritzing-app-inspector_07](../../images/fritzing-app_08.png)
{: .pull-left}
In the _Parts_ window you can also search for any module or component (board, breakout board, module, component etc) that you want to add. Modules that are not preloaded in the <span class='app'>Fritzing</span> app can often be found in online libraries. The best place to look is probably [arduinomodules](https://arduinomodules.info). If you find the module you are looking for just download the parts module, a file with the extension <span class='file'>.fzpz</span>, but usually stored as a <span class='file'>zip</span> file. I store my downloaded modules in a special folder under the <span class='file'>Frtizing</span> folder in my home directory. Import the downloaded module to <span class='app'>Fritzing</span>, as shown to the left.

<figure>
<img src="../../images/nano-single-led-d7_bb.png">
<figcaption> Wiring for testing the connection to an Arduino Nano Board.</figcaption>
</figure>
