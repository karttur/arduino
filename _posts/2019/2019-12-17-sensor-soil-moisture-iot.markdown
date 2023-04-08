---
layout: post
title: Internet of Things soil moisture probes
categories: sensor
sensingfeature: soil-moisture
sensormethod: review
sensorconnect: NA
sensingmedia: soil+air
excerpt: "External connectors for arduino senor unit"
tags:
  - probe
  - soil moisture

image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2019-12-17 11:27'
modified: '2019-12-17 T18:17:25.000Z'
comments: true
share: true
---

## Introduction

Soil moisture devices that can act as stationary Internet of Things (IoT) devices.

Article: [How IoT Soil Condition Monitoring Is Empowering Farmers](https://www.iotforall.com/soil-moisture-monitoring/)

Many companies offer Soil monitoring with IoT, among them [mtg](https://www.manxtechgroup.com/soil-monitoring-with-iot-smart-agriculture/).

To look for devices I used the [sigfox partner network](https://partners.sigfox.com) with a search set to [soil](https://partners.sigfox.com/search/products?or[categories][0]=device&q=soil).

Simpler devices for Arduino include probes that are based on resistivity or capacitans. The former eventually erode, regardless of the metal used, the latter are more durable. The youtube presentation by Andreas Spiess: [Why most Arduino Soil Moisture Sensors suck (incl. solution)](https://www.youtube.com/watch?v=udmJyncDvw0), summarizes the alternatives.

## Youtube

Youtube [overview of Arduino soil moisture sensors](https://www.youtube.com/watch?v=udmJyncDvw0).

Youtube [LoRa](https://www.youtube.com/watch?v=hMOwbNUpDQA&list=PL3XBzmAj53Rkkogh-lti58h_GkhzU1n7U])

#### LoRa

[LoRa (Long Range)](https://en.wikipedia.org/wiki/LoRa) is a low-power wide-area network (LPWAN) technology. It is based on spread spectrum modulation techniques. LoRa enables long-range transmissions (more than 10 km in rural areas) with low power consumption. LoRa devices have geolocation capabilities used for triangulating positions of devices via timestamps from gateways. LoRa and LoRaWAN permit long-range connectivity for Internet of Things (IoT) devices in different types of industries.

[Arduino Pro Gateway for LoRa](https://www.kjell.com/se/produkter/el-verktyg/arduino/utvecklingskort/arduino-pro-gateway-for-lora-p87188?gclid=Cj0KCQiAxrbwBRCoARIsABEc9sjIxmnak9eae2isGVhPulJxFXB6rNa7oJPYnLKUv0SWvfYQLh-pLkQaAnXQEALw_wcB&gclsrc=aw.ds).

This [LHT65 LoRaWAN SHT20 Temperature and Humidity Sensor](https://www.elfa.se/search?q=LHT65+Temperature&filter_categoryCodePathROOT=cat-L1D_1859641) is available at elfa.se.

[LoRa + Arduino project for soil moisture](https://randomnerdtutorials.com/esp32-lora-rfm95-transceiver-arduino-ide/)

### HD Denmark

[https://www.digital.hededanmark.com/portfolio/soil-moisture-sensors/?xdomain_data=D84RScBZBtAO2xDX4HmTI9y5b4ZQl9CIWjRpHFFxwnbXctq3j4Nd5oyTPok%3D](Soil moisture sensor).

### EVVOS

[Irrigation solution UC1](https://www.evvos.com/product/irrigation-solution-uc1/)

### Wired article

[A Solar-Powered Soil Sensor for Serious Gardeners](https://www.wired.com/2015/04/edyn-garden-sensors/)

### Enviro Pro

[Enviro Pro](https://enviroprosoilprobes.com) is an Australian company.

### Arduino based stand alone thing

[LHT65 LoRaWAN Temperature & Humidity Sensor Built-in SHT20 - 868MHz](https://hitechchain.se/arduinokompatibel/lht65-lorawan-temperature-humidity-sensor-built-in-sht20-868mhz?gclid=Cj0KCQiAxrbwBRCoARIsABEc9sjqXysIpQbxa8Lwmd56VpA_5Kl1CNc-eWbhdIYusEN81rws8BPnVVwaAkzvEALw_wcB)

[Same device from UK](https://www.antratek.com/lht65-lorawan-temperature-humidity-sensor)

### Arduino capacitive moisture sensor

You get a [capacitive moisture sensor from Banggod](https://www.banggood.com/Capacitive-Soil-Moisture-Sensor-Not-Easy-To-Corrode-Wide-Voltage-Monitor-Module-p-1309033.html?cur_warehouse=CN) for around 3 USD. In Sweden you can get it for 6 USD through [fyndiq.se](https://fyndiq.se/product/25281124-capacitive-soil-moisture-sensor-v12-c/?tduid=63ab169c26da64207d33d12fc38a0eb2&utm_source=tradedoubler&utm_medium=affiliate&utm_content=252052&utm_campaign=Kelkoo).

Under 1 USD at [Ali Express](https://www.aliexpress.com/item/32830732786.html?scm=1007.22893.149154.0&pvid=cbb3f819-817d-4288-9fea-b81dec7c2c03&onelink_page_from=ITEM_DETAIL&onelink_item_to=32830732786&onelink_publisherid=172076246&onelink_memberseq=0&onelink_duration=1.144336&onelink_status=noneresult&onelink_item_from=32830732786&onelink_subid=220725&onelink_page_to=ITEM_DETAIL&af=220725&afref=&cv=565204&dp=565204%253A%253A220725%253A%253A%253A%253A%253A%253A1578517053&cn=15647&aff_platform=aaf&cpt=1578517053322&sk=Y7bAZbY&aff_trace_key=63baf75040d84175b6f5f3b52839bff7-1578517053322-07617-Y7bAZbY&terminal_id=f7b26140facc4e0b98529a003f6dc12e)
