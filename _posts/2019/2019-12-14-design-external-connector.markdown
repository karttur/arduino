---
layout: post
title: External & internal connector design
categories: blog
excerpt: "External and internal connectors for arduino senor unit"
tags:
  - design
  - arduino
  - external
  - connector
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-12-14 11:27'
modified: '2019-12-14 T18:17:25.000Z'
comments: true
share: true
---

## Introduction

In this post I investigate the different options for connecting external sensors to an Arduino sensor unit.

### Basic alternatives

Micro USB: Standard, but not so common for DIY.

2-4 Pin JST plug: These are small and fairly easy, but a bit instable and sensitive. If space is crucial this could be the alternative. For internal connection with might be the best alternative, for instance available from [cdon](https://cdon.se/leksaker/560-bitars-jst-anslutningssats-med-2-54-mm-jst-ph-2-3-4-5-stiftholje-jst-kabeladapteruttag-kontakt-for-man-och-kvinna-stiftkontakt-vitvit-p48224819). JST power cables from [grandado](https://se.grandado.com/products/10-uppsattningar-mini-micro-2-pin-jst-xh-kontaktplug-2-54mm-med-24awg-kablar-150mm-langd?variant=17358371094585&currency=SEK&gclid=Cj0KCQiAyp7yBRCwARIsABfQsnSPzhoIlHm-cRFd3-WF0P59q6ArcrWsWpZ-YtTGmJ4471RJITgKfUsaApW9EALw_wcB)

XLR plug: These are for audio signal transfer. I got some of these as a try. Internationally you can get XLR with any number of pins, also as chassis for mounting in box. In Sweden the options are more limiting.

GX Aviation plug: Rather cool and sturdy, but that is the problem: sturdy and space consuming.
