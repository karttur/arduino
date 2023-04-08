---
layout: post
title: Capacitive Soil Moisture Sensor v1.2
categories: project
xspectrolum: True
startversion: 0.017
endversion: 0.017
excerpt: "Capacitive Soil Moisture Sensor v1.2"
tags:
  - soil moisture
  - capacitive
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-15 11:27'
modified: '2021-07-07 T18:17:25.000Z'
comments: true
share: true
sensor: sensor-capacitive-sm-v1-2
module: module-capacitive-sm-v1-2
project: null
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

Capacitive soil moisture sensors measures soil moisture levels by capacitive sensing rather than resistive sensing like the more common soil moisture sensors on the market. There are different brands, for instance [DFROBOT SKU SEN0 193](https://wiki.dfrobot.com/Capacitive_Soil_Moisture_Sensor_SKU_SEN0193)

To learn about the advantages with capacitive soil moisture sensors, view the Youtube instruction [Why most Arduino Soil Moisture Sensors suck (incl. solution)](https://www.youtube.com/watch?v=udmJyncDvw0&t=134s), lesson \#207 by Andreas Spiess.

I got the capacitive soil moisture from [pchbutik](https://pchbutik.se/kretskort/1237-jordfukt-sensor-kapacitiv-avkanning-analogt-utgang-passar-arduino.html?search_query=fukt&results=14) in Sweden.

<figure>
<img src="../../images/capacitive-sm-v1-2.png">
<figcaption> Capacitive soil moisture sensor. </figcaption>
</figure>

### Arduino project

Link to online project on [Interface Capacitive Soil Moisture Sensor with Arduino](https://how2electronics.com/interface-capacitive-soil-moisture-sensor-with-arduino/), that also come with a [youtube video](https://www.youtube.com/watch?v=9h3JKwUsn2A).

<figure>
<img src="../../images/nano-capacitive-sm-v1-2_bb.png">
<figcaption> Wiring of capacitive soil moisture sensor. </figcaption>
</figure>

<button id= "toggleCapSM" onclick="hiddencode('CapSM')">Hide/Show sketch</button>

<div id="CapSM" style="display:none">
{% capture text-capture %}
{% raw %}

```
const int AirValue = 620;   //you need to replace this value with Value_1
const int WaterValue = 310;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;
void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
void loop() {
soilMoistureValue = analogRead(A2);  //put Sensor at A2 port
Serial.println(soilMoistureValue);
soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
if(soilmoisturepercent > 100)
{
  Serial.println("100 %");
}
else if(soilmoisturepercent <0)
{
  Serial.println("0 %");
}
else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
{
  Serial.print(soilmoisturepercent);
  Serial.println("%");
}
delay(250);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

### Project with pin power

An alternative wiring is to put the power supply on a digital pin, allowing turning the power to the sensor on/off.

<figure>
<img src="../../images/nano-capacitive-sm-v1-2_d7-power_bb.png">
<figcaption> Wiring of the Capacitive moisture and temperature sensor using pin D7 for on/off power setting. The wiring is set to pass through a 4-pin connector, that can also hold other sensors, and thus includes redundant pins.
</figcaption>
</figure>

<button id= "toggleCapSMpowerD7" onclick="hiddencode('CapSMpowerD7')">Hide/Show sketch</button>

<div id="CapSMpowerD7" style="display:none">
{% capture text-capture %}
{% raw %}

```
int probePowerPin = 7;

const int AirValue = 620;   //you need to replace this value with Value_1
const int WaterValue = 310;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;

void setup ()
{
   Serial.begin(9600);
   pinMode (probePowerPin, OUTPUT); // define the digital output

}

void loop () {
   // turn on external probe power
   digitalWrite (probePowerPin, HIGH); // Turn external probe power On
  soilMoistureValue = analogRead(A1);  //put Sensor at A1 port
  Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilmoisturepercent > 100)
  {
    Serial.println("100 %");
  }
  else if(soilmoisturepercent <0)
  {
    Serial.println("0 %");
  }
  else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
  {
    Serial.print(soilmoisturepercent);
  Serial.println("%");
  }
  delay(250);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>
