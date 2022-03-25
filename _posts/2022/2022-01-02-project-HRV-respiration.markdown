---
layout: post
title: EEG, ECG, HRV & respiration
categories: project
version: "electroencephalogram (EEG), Electrocardiogram (ECG), Heart Rate Variability (HRV) and respiration monitoring with Arduino"
tags:
  - EEG
  - HRV
  - respiration
  - mental health
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-01-02'
modified: '2022-01-02'
comments: true
share: true
---

## Introduction

The monitoring schemes of electroencephalogram (EEG), Electrocardiogram (ECG), Heart Rate Variability (HRV) and respiration in this post were all inspired by the Book [_The Body Keeps the Score: Brain, Mind, and Body in the Healing of Trauma_ by Bessel van der Kolk](https://www.amazon.com/Body-Keeps-Score-Healing-Trauma/dp/0143127748/ref=sr_1_1?crid=2PEYLQBUSKH8&keywords=The+Body+Keeps+the+Score&qid=1641137839&sprefix=the+body+keeps+the+score%2Caps%2C171&sr=8-1). Specifically the post deals with monitoring Heart Rate versus breathing (inhaling, exhaling) and EEG. The book outlines how such observations can be used for resetting the Autonomic nervous system (ANS) (the "limbic" brain). The ideas linked together in this post are not intended for medical use, but only as a means to better understand the technology behind some popular methods for health monitoring.

## Heart Rate Variability (HRV)

Heart Rate (HR) is the easiest to monitor, you can buy a wrist band with integrated pulse-meter for as little as 10 USD. For medical purposes it is more common to use a clip for earlobes or a finger pulse meter. The latter often come with an oxymeter that simultaneously estimate the blood oxygen levels. There are numerous finger pulse-oxymeters available from a few tens of dollars and upward - including lots of online reviews. for mental health applications, however, you need a pulse-meter that you can wire together with other monitoring and thus you need a device that you can connect to a microcontroller. Some alternatives follow.

### Arduino finger pulse oxymeter

The MAX30102 (MAXREFDES117#/MAXREFDES120#)  integrated circuit board is a pulse-oxymeters that is intended fro use with a microcontroller. The older version of this [_Maxim Integrated sensor_ (MAXREFDES117#) ](https://www.newark.com/maxim-integrated-products/maxrefdes117/ref-des-brd-heart-rate-pulse-oximeter/dp/96Y9339) is no longer produced, the later version [(MAXREFDES120#)](https://www.newark.com/maxim-integrated-products/maxrefdes220/ref-des-brd-oximeter-heart-rate/dp/61AC0161?MER=sy-me-pd-mi-alte) is widely available, but at a fairly exorbitant price of 100 USD. Looking a bit more I also found the MAX30102 sensor available at [Bangood](https://www.banggood.com/MAX30102-Heartbeat-Frequency-Tester-Heart-Rate-Sensor-Module-Puls-Detection-Blood-Oxygen-Concentration-Test-p-1354772.html?utm_source=googleshopping&utm_medium=cpc_organic&gmcCountry=SE&utm_content=minha&utm_campaign=minha-se-en-pc&currency=SEK&cur_warehouse=CN&createTmp=1&utm_source=googleshopping&utm_medium=cpc_union&utm_content=lynna&utm_campaign=lynna-ssc-se-all-0716&ad_id=367117562532&gclid=Cj0KCQiAt8WOBhDbARIsANQLp952fyZABNUE0D2K8qpuMlNFpzknZ-8d0sMkpc-_QJ6qsdpvg7P8Z5QaAjrHEALw_wcB) for less than 5 USD. The same basic sensor is also available via [conrad](https://www.conrad.se/p/whadda-wps473-max30102-hjaertfrekvens-och-syresensor-2481953?gclid=Cj0KCQiAt8WOBhDbARIsANQLp97jsUflrLOFeJL5BmsyXMSAOLILa8h26UoVkKFIABTzbCwMjiwmylkaAiJ6EALw_wcB&gclsrc=aw.ds&utm_campaign=shopping-feed&utm_content=free-google-shopping-clicks&utm_medium=surfaces&utm_source=google&utm_term=2481953&vat=true), at around 20 USD. Also [digi-key](https://www.digikey.se/sv/products/detail/analog-devices-inc-maxim-integrated/MAX30102EFD-T/6188734) has the MAX30102 sensor type for about 11 USD.


Another alternative is [MIKROE-2000](https://se.rs-online.com/web/p/sensor-development-tools/1360770?cm_mmc=SE-PLA-DS3A-_-google-_-PLA_SE_EN_Fallback-_-All+products-_-1360770&matchtype=&pla-293946777986&gclid=Cj0KCQiAt8WOBhDbARIsANQLp95En76R_ED9SFt4sVkoINCgS0HBls5QJumyGGEmn6IdQ4evsk5cHowaAsfVEALw_wcB&gclsrc=aw.ds), that is available for around 20 USD.


The wiring and coding, and 3D printed skeleton for a finger pulse oxymeter based on the (outdated) Maxim MAX30102 is published as an [Arduino project hub](https://create.arduino.cc/projecthub/gatoninja236/open-source-pulse-oximeter-for-covid-19-4764c5). A less advances set-up, without 3D-printed finger holder, is also [published at Arduino project hub](https://create.arduino.cc/projecthub/SurtrTech/measure-heart-rate-and-spo2-with-max30102-c2b4d8?ref=similar&ref_id=127308&offset=0).

I can not find any Arduino compatibly wiring and coding for the [MIKROE-2000 sensor](https://se.rs-online.com/web/p/sensor-development-tools/1360770?cm_mmc=SE-PLA-DS3A-_-google-_-PLA_SE_EN_Fallback-_-All+products-_-1360770&matchtype=&pla-293946777986&gclid=Cj0KCQiAt8WOBhDbARIsANQLp95En76R_ED9SFt4sVkoINCgS0HBls5QJumyGGEmn6IdQ4evsk5cHowaAsfVEALw_wcB&gclsrc=aw.ds).

[DFRobot](https://wiki.dfrobot.com) has developed the [Heart Rate Sensor SKU SEN0203](https://wiki.dfrobot.com/Heart_Rate_Sensor_SKU__SEN0203), available for around 25 USD. As always, the DFRobot products are well documented and presumably of good quality. It is also available from [digi-key](https://www.digikey.se/sv/products/detail/SEN0203/1738-1192-ND/6588613?itemSeq=385912101).

### Arduino Electrocardiogram (ECG) monitor

I found an [ECG analog heart rate monitor sensor](https://www.dfrobot.com/product-1510.html)https://wiki.dfrobot.com/Heart_Rate_Monitor_Sensor_SKU__SEN0213 for Arduino made by [DFRobot](https://www.dfrobot.com). it comes with a [DFRobot manual](https://wiki.dfrobot.com/Heart_Rate_Monitor_Sensor_SKU__SEN0213) and also [third party Arduino wiring and coding](https://emersonkeenan.net/arduino-hrv/). It is unclear what is included when you buy the product, but it is available for [digi-key](https://www.digikey.se/sv/products/detail/SEN0213/1738-1195-ND/6588616?itemSeq=386168826).

The [disposable ECG Electrodes](https://www.dfrobot.com/product-1554.html) I can only find at DFrobot.

### Breathing sensor

DIY Arduino:
https://create.arduino.cc/projecthub/marco-polo-sauza-aguirre/breathing-sensor-1-respiration-sensor-1b18de

Using a water flow meter (YF-S201), published as science article using Arduino:


#### Pressure based spirometer

[article on how to build a spirometer using an atmospheric pressure sensor and a microcontroller](https://www.nxp.com/docs/en/application-note/AN4325.pdf). And [here](https://github.com/hydronics2/COVID-19-Airflow-Sensor-AFH55M12) is the project on GitHub. What I thin is an [updated version](https://maker.pro/arduino/tutorial/diy-arduino-nano-spirometer) of the same device.


#### Hot wire anemometer

[With two sensors, one for each nostril](https://www.cooking-hacks.com/airflow-breathing-sensor-mysignals-ehealth-medical.html) looks like the moustache-holder that Hercule Poiroit uses. Here is [another producer](https://www.ternimed.de/Sleep-Lab-Accessories/Respiratory-Sensor-to-detect-of-respiratory-flow) offering a similar device.

#### Using AI and wavelets

There is an article that suggest [using a pulse-meter for estimating breathing](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC1726217/pdf/v020p00524.pdf), also summarised [here](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC1726217/). But as I want independent estimates I am not happy with that solution.

### EEC

[Neurosky mind wave Arduino project](https://create.arduino.cc/projecthub/sieuwe/3-amazing-brain-mind-control-projects-with-led-strips-95aee5?ref=tag&ref_id=eeg&offset=3). The version of the Neurosky mind wave device used in the above project is no longer available.


## Resources

[Linkura - Hjärtfrekvensvariabilitet](https://www.linkura.com/sv/hjartfrekvensvariabilitet) (in Swedish)

[digitalhälsan - HRV träning](https://digitalhalsan.se/kroppsscanning-med-hrv/) (in Swedish)

[10 Best Heart Rate Variability Biofeedback Monitors (2021 Review & Comparison) Used By Pros](https://outliyr.com/best-hrv-biofeedback-monitors)

[The Flow chest strap tracks breathing to improve your running performance](https://www.wareable.com/wearable-tech/sweetzpot-flow-breathing-chest-strap-2018)

[Biopac - respiration transducer](https://www.biopac.com/product/respiration-transducer-bionomadix/)

[medgadget - noseclip for HRV and breathing](https://www.medgadget.com/2015/08/first-response-monitor-tracks-heart-respiratory-rates-in-multiple-trauma-victims.html)
