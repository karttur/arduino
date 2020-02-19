---
layout: post
title: Red laser 650nm
categories: components
excerpt: "Red laser 650nm"
tags:
  - LED
  - RGB
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-03 11:27'
modified: '2020-02-03 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

Red lasers at 650 nm are quite commun as components or breakout boards (modules). Actually pinning down which laser it is, is not so easy. I have different versions, and I am not sure if they are 3 or 5 v, or 1 or 5 mW. They do differ slightly is diameter and also in the focus of the beam. So I think they are different.

You can wire the laser directly, without a module (or breakout board). Or you can get the [laser on a breakout board](../../modules/module-laser650), the one I have does include a small resistor, so maybe it is 3v after all? But then again, you can buy loose lasers indicated to run at 5v (below).

### 3v laser from pchbutik

The component lasers that I have are from [pchbutik.se](https://pchbutik.se/led/143-2-st-laser-1mw-3v-650nm-rod-metall-kapslad-passar-arduino.html?search_query=laser&results=27), they are 3 v and with an output of 1 mW and require less less than 40 mA. This is sufficient for my needs. Link to post on the [wiring and sketching of the 3v laser components](../../projects/project-laser650).

### 5v lasers

At [aliexpress](https://www.aliexpress.com/item/32841413427.html?scm=1007.22893.149154.0&pvid=d49e4eac-5769-4b00-89d3-a04bb21c558c&onelink_page_from=ITEM_DETAIL&onelink_item_to=32841413427&onelink_publisherid=172076246&onelink_memberseq=0&onelink_duration=1.464337&onelink_status=noneresult&onelink_item_from=32841413427&onelink_subid=220725&onelink_page_to=ITEM_DETAIL&af=220725&afref=&cv=565204&dp=565204%253A%253A220725%253A%253Apla%253A%253A%253A%253A1581160630&cn=15647&aff_request_id=7f1cc802672c416c8aac90a305cc7504-1581160630751-02860-Y7bAZbY&aff_platform=aaf&cpt=1581160630751&sk=Y7bAZbY&aff_trace_key=7f1cc802672c416c8aac90a305cc7504-1581160630751-02860-Y7bAZbY&terminal_id=f7b26140facc4e0b98529a003f6dc12e) you can get a package of 10 5v 5mW similar lasers at 1/10 of the price (if you buy 10).
