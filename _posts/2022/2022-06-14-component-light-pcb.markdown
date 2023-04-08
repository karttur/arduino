---
layout: post
title: Processing
categories: app
excerpt: "Adafruit Feather nRF52840 module"
tags:
  - Processing
  - serial port
  - graph
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-06-08 11:27'
modified: '2022-06-08 T11:27'
comments: true
share: true
---

### Introduction

https://www.digikey.se/sv/products/detail/samtec-inc/TSW-102-11-L-Q-RA/7862274 (only to order - not on shelf)

Mouser har en "off the shelf"
https://www.mouser.se/ProductDetail/TE-Connectivity/640453-4?qs=sGAEpiMZZMvlX3nhDDO4AKzs8QJUFIjWwDPrZt2EmhE%3D

https://www.digikey.se/en/products/detail/luminus-devices-inc/MP-2016-1100-40-80/4807631


### BOM list

| item | shop | product code |
| 5 pin R/A pogo female | AliExpress (RIPZV) | See below |
|| NIR LED | Farnell | 3580475 |
| white LED | digi-key  | 1214-1212-2-ND |
| xenon bulb | Conrad |  1590355 |
| blue laser | Civillaser  | SLD3134VL |
| green laser | Civillaser  |   |
| red laser | Civillaser |   |
| 1-wire |   |   |

#### 5 pin R/A pogo female

The 5-pin female right angle (R/A) pogo ("loaded spring") connector is difficult to find. I ordered a set via [AliExpress](https://www.aliexpress.com) from [RIPZV](https://www.aliexpress.com/item/1005003579709688.html?spm=a2g0o.order_detail.0.0.25eff19cQIoJ01). The only other source I could find was from another Chinese producer [Jiatel](https://www.jiatel.com/product/2-5mm-pitch-5pin-right-angle-female-target-connector-pogo-connector/) that sell male and female right angle pogo pins in male+female pairs. But from them you have to inquire and then order.

#### NIR LED (Osram)

Latest genration of [Osram NIR LED](https://www.osram.com/ecat/OSLON®%20P1616%20SFH%204737/com/en/class_pim_web_catalog_103489/prd_pim_device_10751075/), available from [Farnell.se](https://se.farnell.com/w/search/prl/resultat?st=SFH%204737&scope=partnumberlookahead&searchref=searchlookahead). I have a bunch of an [earlier generation  Osram NIR LED](https://se.farnell.com/osram-opto-semiconductors/sfh-4735/infrared-emitter-1050-nm-smd/dp/2981794?ICID=I-HP-STM7REC-RP-2); they will do with the same surface mount for the test series (see [datasheet](https://www.farnell.com/datasheets/2711902.pdf)).

#### White LED

Looking for a surface mounted bright white LED with approximately the same surface mount as the NIR LED, I settled for a Luminus Decives 3V, 60mA LED available from [Digi-key](https://www.digikey.se/sv/products/detail/luminus-devices-inc/MP-2016-1100-40-80/4807631?s=N4IgTCBcDaIIxjgFgLQISsKByAREAugL5A).

#### Xenon bulb (Conrad)

[Conrad](https://www.conrad.se) offers an optoelectrical bi-pin [xenon bulb](https://www.conrad.se/p/xenonlampa-260-v-156-w-sockel-bi-pin-127-mm-na-1590355-tru-components-1-st-1590355). It used to be available in different version, including one with 3v and 0.9 W. This is the one I prefer but we need to find an alternative supplier or change to the 2.6volt version now available.

#### Blue laser (Sony)

Other solutions using miniature spectral sensors have relied on a Sony Blue laser at 405 nm. The particular laser is available from [Civillaser](https://www.civillaser.com/index.php?main_page=product_info&products_id=78), and also from [GroupGets](), that also sell a complete spectrometer with this SONY laser integrated.

#### Green laser (Sony)

https://www.civillaser.com/index.php?main_page=product_info&products_id=2291

#### Red laser

https://www.civillaser.com/index.php?main_page=product_info&products_id=87
