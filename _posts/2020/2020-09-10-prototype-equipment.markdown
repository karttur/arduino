---
layout: post
title: Prototyping equipment
categories: prototype
excerpt: "Equipment for soldering Surface Mount Devices."
tags:
  - prototype
  - equipment
  - soldering
  - flux
  - power supply
  - logic analyser
  - transistor tester
  - pliers
  - cable stripper
  - hot air
  - SMD resistors
  - fan
  - tweezers
  - microscope
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-09-10 11:27'
modified: '2020-09-19 11:27'
comments: true
share: true
---

### Introduction

This post on recommended equipment was inspired by Andreas Spiess Youtube turorial on [Most used tools, tips and tricks to spend your money wisely](https://www.youtube.com/watch?v=vZtkbUc2i_Y). Having watched that video I realised that I lacked several key tools for building my Arduino projects. Especially when it comes to Surface Mounted Devices (SMDs). In this post I have listed key equipment for SMD soldering, including links to sellers of the tools.

### Solder iron

Probably the most important tool of all is the soldering iron. Spiess recommends [TS80](https://www.youtube.com/watch?v=_Z9es-D9_8g) or TS100 pen soldering irons. The TS80 is available from [Banggood](https://www.banggood.com/TS80P-More-30W-Soldering-Iron-Station-OLED-USB-Type-C-Programable-Solder-Iron-Built-in-STM32-Chip-PD2_0-or-QC3_0-Standard-Input-p-1680934.html?gmcCountry=SE&currency=SEK&createTmp=1&utm_source=googleshopping&utm_medium=cpc_union&utm_content=xibei&utm_campaign=xibei-ssc-se-all-0716&gclid=CjwKCAjw2dD7BRASEiwAWCtCbziSPAQvej2rtL1ds3aYw75353ZDvkrnvoG6A518jMSgbwIr4C2VzxoCSToQAvD_BwE&cur_warehouse=CN), the closest I can find in Sweden is from [Conrad](https://www.conrad.se/p/seeed-studio-loedkolv-65-w-loedspets-100-till-400-c-1881781?gclid=Cj0KCQjwtZH7BRDzARIsAGjbK2aEs6_Z4dCsipP1QlzFkwCK4GDRClJL-DYR96YY1QK0hpGZBZneq5oaAp_5EALw_wcB&gclsrc=aw.ds&vat=true). However, I already have an excellent soldering station, so I will not invest in a new soldering pen at the moment. The station I have (GM) is no longer manufactured, nor are any spare parts.

#### Flux

I never used flux before, but having watched the youtube tutorial on [What's the best flux for soldering? A comparison with PCBs from JLCPCB](https://www.youtube.com/watch?v=iKDAmY9Rdag), it seems quite helpful.

The RF800 flux is not covered in the youtube video, but is highly recommended on other pages, and available at [fyndiq.se](https://fyndiq.se/produkt/flytande-flussmedel-50-ml-for-t-ex-smd-b05a1df5b5d84e53/) and (cheaper) at [Autemashop](http://www.autemashop.com/category_Lkomp_Solder1.htm).

The Weller "lötfett" paste is covered in the video, but the packages itself is labelled as not suitable for PCBs at [kjell.com](https://www.kjell.com/se/produkter/el-verktyg/verktyg/lodning/flussmedel/weller-lf25-flussmedel-p40375).

I also found a pen with flux at [fyndiq.se](https://fyndiq.se/produkt/10ml-flux-pen-welding-fluxes-solder-pen-1pc-1pc-e49f4c7844714a22/).

[Autemashop](http://www.autemashop.com/category_Lkomp_Solder1.htm) has a selection of flux for soldering of surface mounted devices (SMD). I bought the flux I use from them.

#### Power supply (Nätaggregat)

I never had a separate power supply, only just using the usb-port and the Arduino board itself. But I understand that a separate power supply, where you can regulate both the current and voltage, would be useful. There are lots of alternatives. The cheapest I could find in Sweden were from [Fyndiq](https://fyndiq.se/produkt/nataggregat-laboratorieaggregat-15v-2a-ps1502d-a5e8472f5019437a/) and [Wish](https://www.wish.com/product/5d7e1de0782ce2419cfb21e6?hide_login_modal=true&from_ad=goog_shopping&_display_country_code=SE&_force_currency_code=SEK&pid=googleadwords_int&c=%7BcampaignId%7D&ad_cid=5d7e1de0782ce2419cfb21e6&ad_cc=SE&ad_lang=SV&ad_curr=SEK&ad_price=822.00&campaign_id=9527731155&guest=true&gclid=CjwKCAjw74b7BRA_EiwAF8yHFEUKW8851KwuNgi05rVW0haDwbCcsw8invsdMEutMlzvqX2bcnyWZRoCizoQAvD_BwE&share=web). It seems that the Fyndiq alternative is also available via [Tradera](https://www.tradera.com/item/340198/415617832/nataggregat-15v-2a-ps1502d) and that it is actually [Autemashop](http://www.autemashop.com/category_power_aggregat2.htm) that is the seller behind. I got also this piece of equipment from [Autemashop](http://www.autemashop.com/category_power_aggregat2.htm).

#### Oscilliscope or logic analyser

Not sure why I need an oscilloscope, or how to use them. I settled for a logic analyser, that I really neither understand how to use. I found several on [Banggood](https://www.banggood.com/USB-Logic-Analyzer-24M-8CH-Microcontroller-ARM-FPGA-Debug-Tool-p-1177821.html?gmcCountry=SE&currency=SEK&createTmp=1&utm_source=googleshopping&utm_medium=cpc_bgs&utm_content=xibei&utm_campaign=xibei-ssc-se-en-ecs-0724&gclid=Cj0KCQjwtZH7BRDzARIsAGjbK2bh8gu9TrbEOP9iH-eSJay2WKUR5k_6rHb6mgeQFmX-qFfky7owMjsaAjMhEALw_wcB&cur_warehouse=CN). I can not guess the Swedish translation and thus could not find any product for sale in Sweden. Spiess [Video 72](https://www.youtube.com/watch?v=18Ew5_r17AA) is a tutorial on how to use a USB logic analyser.

#### Transistor tester

A transistor tester that can determine the resistance of any resistor, the legs of
N and P mosfets, diod connection etc. seems a very valuable tool. I had no idea these existed. At [Banggod](https://www.banggood.com/sv/search/transistortester.html?from=nav) there are a long list of alternatives. In Sweden I found a simple one from [fyndiq.se](https://fyndiq.se/produkt/lcr-t4-esr-meter-transistor-testers-lcr-diode-triode-scr-9a0a716c6a4340ce/), but the exactly same item is available from [Banggood](https://www.banggood.com/sv/Geekcreit-LCR-T4-12864-LCD-Graphical-Transistor-Tester-Resistance-Capacitance-ESR-SCR-Meter-p-1311439.html?rmmds=search&cur_warehouse=CN) for a third of the price.

#### Pliers

I have some old pliers, but I realise that a new and more diverse set would be helpful. In Sweden, sets of pliers are available from either [fyndiq.se](https://fyndiq.se/produkt/cutting-wire-pliers-jewelry-pliers-fit-beadwork-repair-beading-h-a2-303b8cd11ed3437d/) or [kjell.com](https://www.kjell.com/se/produkter/el-verktyg/verktyg/tanger-kabelskalare/dibotech-tangset-3-delar-p40544).

#### Cable stripper (kabelskalare)

I have longed wished for a cable stripper, but as I did not know that this was the name under which they went, I was never able to find one. Now I know. But then again, buying one in Sweden is not so easy. As usual, [Banggood](https://www.banggood.com/sv/search/cable-stripper.html?from=nav) have a wide selection.

In Sweden I found a simple manual stripper from [kjell.com](https://www.kjell.com/se/produkter/el-verktyg/verktyg/tanger-kabelskalare/manuell-kabelskalare-p40182). And an [automatic](https://www.kjell.com/se/produkter/el-verktyg/verktyg/tanger-kabelskalare/automatisk-kabelskalare-p40247) one, the kind that are used in most youtube videos. Having a closer look, the latter is neither available online, nor in any nearby physical shops. [Biltema](https://www.biltema.se/verktyg/handverktyg/tanger/kabelskalare/kabelskalare-2000016798) has one it seems. Finally I found that [Autemashop](http://www.autemashop.com/category_tool_Stripper.htm) had two better ones, but under a different name and thus very difficult to find!

#### Hot air station

[Kjell.com](https://www.kjell.com/se/produkter/el-verktyg/verktyg/lodning/lodverktyg/digital-varmluftsstation-smd-p40399?gclid=CjwKCAjw74b7BRA_EiwAF8yHFOJzQMRLQSdTL28FmZv3SnxkIOr2UVBCBszFa_nKr603pDoHijxGiRoC5JUQAvD_BwE&gclsrc=aw.ds) has a simple and cheap hot air station. [Autema](http://www.autemashop.com/category_tool_HotAir.htm), has a larger selection, including combined hot air a soldering pen stations. And then, on a separate page at [Autemashop](http://www.autemashop.com/category_tool_SoldAir.htm) I found a Hot Air station that seems to fit my needs.

#### SMD resistor pack (motståndssats)

The only alternatives available in Sweden that I can find, that are actually stocked, seems to be [fyndiq.se](https://fyndiq.se/produkt/0805-smd-resistor-kit-assorted-kit-1ohm-1m-ohm-1-33values-x-20p-one-size-c18bf2cde10e48b1/) and [Autemashop](http://www.autemashop.com/category_Lkomp_Res_0805.htm). But then you have to order each resistor (Ohm value) separately. Useful for production, but not for prototyping.

[Banggood](https://www.banggood.com/0805-SMD-Resistor-And-Capacitor-Sample-Book-Full-Version-p-1103180.html?gmcCountry=SE&currency=SEK&createTmp=1&utm_source=googleshopping&utm_medium=cpc_union&utm_content=xibei&utm_campaign=xibei-ssc-se-all-0716&gclid=CjwKCAjwkoz7BRBPEiwAeKw3q2U0wCbR9SzSL3lTAhmsoJvC_457bOqFAW46Brfh1zixnYEgyth7hBoCVdEQAvD_BwE&cur_warehouse=CN) have much better assortment, even bound into a book. A smaller set is also available from [Banggood](https://www.banggood.com/8500Pcs-0402-1-pencent-SMD-SMT-Chip-Resistor-Assortment-Kit-170-Values-Sample-Book-p-1328296.html?gmcCountry=SE&currency=SEK&createTmp=1&utm_source=googleshopping&utm_medium=cpc_union&utm_content=xibei&utm_campaign=xibei-ssc-se-all-0716&gclid=CjwKCAjwkoz7BRBPEiwAeKw3q8E0B1kLUZo2nQXMo4rfOTVmzmDeUv-OIbfG-d_Ybwz3TaJiCePd2xoCjScQAvD_BwE&cur_warehouse=CN)

#### Fan

Fan for protecting the person soldering from the fumes. 12 volt cooling fan for PC seems a good alternative. Different sizes available at [kjell.com](https://www.kjell.com/se/produkter/el-verktyg/elektronik/elektromekanik/flaktar/12-v/axialflakt-12-v-40x40x10-mm-p36171).

#### Tweezers (pincett)

Package with 7 electronic tweezers from [kjell.com](https://www.kjell.com/se/produkter/natverk/installationsmateriel/esd-antistat/luxorparts-esd-pincettset-p40709). At [fyndiq](https://fyndiq.se/produkt/anti-statisk-pincett-pincetter-till-finelektronik-6-pack-bec32158e2e145fd/) 6 tweezers for electronics is only a third of the price.

[Autemashop](http://www.autemashop.com/category_Lkomp_Tweezer.htm) have higher quality tweezers at 3 USD each.

#### Microscope

Microscope for work from [banggood.com](https://www.banggood.com/Phone-PCB-Soldering-Repair-Lab-Industrial-7X-45X-90X-Simul-focal-Trinocular-Stereo-Microscope-VGA-HDMI-Video-Camera-720P-13MP-p-1476003.html?rmmds=search&cur_warehouse=CZ). In Sweden I can only find from [AstroSweden](https://mikro.astrosweden.se/sv/articles/2.370.933/breukhoven-breukhoven-handarbetslupp-med-rorlig-belysning-bms-st-50), but it lacks some of the peripheral stuff that the Banggood alternative comes with.
