---
layout: post
title: Prototyping Arduino projects
categories: prototype
excerpt: "Prototyping Arduino projects"
tags:
  - prototype

image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-09-15 11:27'
modified: '2020-09-15 11:27'
comments: true
share: true
---

### Introduction

Some Arduino projects are fine to use only on a breadboard. But in many cases you want to go a step further and create a "stand-alone" solution inside a case. You then need to leave the breadboard and instead create a prototype. Basically there are three options for prototyping:

- Connect all components (breakout boards and microcontroller) using Dupond wires
- Connect all components on a prototype printed circuit board (PCB)
- Design and produce a custom manufacture PCB

### Prototyping with wires

With Dupond wires you get the largest degree of freedom, also in positioning and orientation of your components. That is important if you have components that operate together and depend on relative angles and positions.

A good introduction on prototyping using Dupond wires is the video by Andreas Spiess [From Breadboard to Prototype (Arduino)](https://www.youtube.com/watch?v=pMgxpK2CClY).

In my experience, Dupond wires are too unstable and fickle, and render continuous connection problems. The alternative is then to crimp ordinary wires with male and female connectors. That works better but is a very tedious work. Illustrated for instance in the youtube tutorial [How to crimp your own cable harness](https://www.youtube.com/watch?v=8sHeR4Uozck) by Playful technology.

A last alternative is solder wires directly between the microcontroller and the breakout boards, skipping any connectors, and then put the whole package in place in the case. The soldering work is exactly the same as when using Dupond wires or crimping, but there are no connectors whatsoever. Having tried both Dupond wires and crimping. I have settled for creating my initial prototypes by soldering the wires directly using the through-holes of the breakout boards.

### Prototyping with prefabricated PCBs

For the projects I am working with, this is not a feasible alternative.

### Customized PCB

Creating a customized PCB requires several steps.

#### Design

Several youtube tutorial cover the principles of designing a cutomized PCB:

- [From Idea to Schematic to PCB - How to do it easily!](https://www.youtube.com/watch?v=35YuILUlfGs)

#### Traditional methods (etching)

How to use chemical etching for creating a customized PCB is described in Swedish on [Kejll.com](https://www.kjell.com), at the page [Tillverkning av mönsterkort](https://www.kjell.com/se/kunskap/hur-funkar-det/elelektronik/lodning/tillverkning-av-monsterkort).

#### Soldering

A good youtube tutorial on [How to Solder Surface Mount parts](https://www.youtube.com/watch?v=f9fbqks3BS8), or [How To Solder Surface Mount Components](https://www.youtube.com/watch?v=hoLf8gvvXXU).

#### Online ordering

Several companies offer online ordering of designed printed circuit board (PCBs), for instance. [Conrad](https://www.conrad.se/om-oss/tjaenster/pcb-service).

#### More on PCB

Understanding how a PCB is built up [Introduction to Basic Concepts in PCB Design](https://www.youtube.com/watch?v=ESnDQl7ZM5o), is a very verbose tutorial that refers to "covered later".

#### Fritzing

The Youtube tutorial [How To Arduino Basics From Breadboard to PCB Part 2 // Converting Project to PCB](https://www.youtube.com/watch?v=AEhpEUvy6rc) steps through how to convert an Arduino project to a PCB using [Fritzing](https://fritzing.org). Including some hints on good practice (especially for how to handle ground).
