---
layout: post
title: RGB led alternative
categories: project
excerpt: "Wire and sketch for LED with separate RGB"
tags:
  - LED
  - RGB
  - wire
  - sketch
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-02 11:27'
modified: '2020-02-02 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

Several products with separate light-emitting diodes (LED) for red (R) green (G) and blue (B) exists, and they require different wiring and sketching. This post goes through some of the RGB LEDs that are available, both as breakout boards and as simple components. This post is restricted to LEDs where each color is controlled by its own cord.

### Common cathode or anode

All RGB LEDs with individual cords have 4 connections, three for controlling the power supply and one common that closes the circuits of all three power supplies. The common one can either be the cathode (the most common and standard solution) or the anode. There is no physical difference that can be used to distinguish whether the common (the longest leg) is the cathode or the anode.

### Common cathode

To have a common cathode is standard, you connect the longest leg of the LED component to the Arduino board ground (GND). If you only intend to light one color at the time it is sufficient to have one 220 Ohm resistor on the common cathode.

<figure>
<img src="../../images/nano-led-RGB-cathode-rgb-only_bb.png">
<figcaption> Wiring of an RGB LED with a common anode. The wiring with the 220 Ohm resistor on the anode is only applicable when a single color (red, green or blue) is lit at the time. </figcaption>
</figure>

<button id= "toggleRGBcathodeOnly" onclick="hiddencode('RGBcathodeOnly')">Hide/Show sketch</button>

<div id="RGBcathodeOnly" style="display:none">
{% capture text-capture %}
{% raw %}
```
int red_light_pin= 4;
int green_light_pin = 5;
int blue_light_pin = 6;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
void loop() {

  RGB_color(0, 255, 255); // Green
  delay(1000);
  RGB_color(255, 0, 255); // Red
  delay(1000);
  RGB_color(255, 255, 0); // Blue
  delay(1000);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

#### All color combinations

If you want to mix two, or all, colors you need to put a 220 Ohm resistor on each.

<figure>
<img src="../../images/nano-led-RGB-cathode-rgb-combo_bb.png">
<figcaption> Wiring of an RGB LED with a common cathode. The wiring with a 220 Ohm resistor on each power supply allows any combination of lit LEDs. </figcaption>
</figure>

<button id= "toggleRGBcathodeCombo" onclick="hiddencode('RGBcathodeCombo')">Hide/Show sketch</button>

<div id="RGBcathodeCombo" style="display:none">
{% capture text-capture %}
{% raw %}
```
int red_light_pin= 4;
int green_light_pin = 5;
int blue_light_pin = 6;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
void loop() {

  RGB_color(0, 255, 255); // Green
  delay(1000);
  RGB_color(255, 0, 255); // Red
  delay(1000);
  RGB_color(255, 255, 0); // Blue
  delay(1000);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

### Common anode

As noted above, also the anode can be the common connection point, in which case the longest (anode) leg is connected to power (5v).

#### Only red, green and blue

If you only intend to light one color at the time it is sufficient to have one 220 Ohm resistor on the common andode.

<figure>
<img src="../../images/nano-led-RGB-anode-rgb-only_bb.png">
<figcaption> Wiring of an RGB LED with a common anode. The wiring with the 220 Ohm resistor on the anode is only applicable when a single color (red, green or blue) is lit at the time. </figcaption>
</figure>

<button id= "toggleRGBanodeOnly" onclick="hiddencode('RGBanodeOnly')">Hide/Show sketch</button>

<div id="RGBanodeOnly" style="display:none">
{% capture text-capture %}
{% raw %}
```
int red_light_pin= 4;
int green_light_pin = 5;
int blue_light_pin = 6;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
void loop() {

  RGB_color(0, 255, 255); // Green
  delay(1000);
  RGB_color(255, 0, 255); // Red
  delay(1000);
  RGB_color(255, 255, 0); // Blue
  delay(1000);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

#### All color combinations

If you want to mix two, or all, colors you need to put a 220 Ohm resistor on each.

<figure>
<img src="../../images/nano-led-RGB-anode-rgb-combo_bb.png">
<figcaption> Wiring of an RGB LED with a common anode. The wiring with a 220 Ohm resistor on each power supply allows any combination of lit LEDs. </figcaption>
</figure>

<button id= "toggleRGBanodeCombo" onclick="hiddencode('RGBanodeCombo')">Hide/Show sketch</button>

<div id="RGBanodeCombo" style="display:none">
{% capture text-capture %}
{% raw %}
```
int red_light_pin= 4;
int green_light_pin = 5;
int blue_light_pin = 6;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
void loop() {

  RGB_color(0, 255, 255); // Green
  delay(1000);
  RGB_color(255, 0, 255); // Red
  delay(1000);
  RGB_color(255, 255, 0); // Blue
  delay(1000);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

### KY-009 Breakout board

The KY-009, built on the [SMD 5050 RGB component](../../components/component-SMD-5050-RGB) gives a more homogenous beam compared to the above LEDs and is probably the better choice for use with a spectrometer.

The KY-009 breakout board comes in two versions: with and without integrated resistors. You just have to inspect the breakout board to see if there are resistors built in. Below are two different sketches and two different wirings. The first sketch is more basic and applies different resistors for each power source (R=180 Ohn, B = G = 100 Ohm). The second wiring assembles all resistors (to 390 Ohm). The function does not seem to change dependent on the wiring.

Note that the fading is achieved using Pulse Width Modulation (PWM) and I am uncertain if this is really useful when it comes to using the LED as a light source for spectrometers. I will have to look into that and write a separate post. Later.

#### Basic

Sketch and wiring for the [KY-009 3-color full-color LED SMD modules](../../modules/module-KY-009-RGB-LED/). As the red (R) diode requires a lower voltage compared to green (G) and blue (B) you need to use 100 Ohm resistors for G and B and a 180 Ohm resistor for R.

<figure>
<img src="../../images/nano-led-ky-009_bb.png">
<figcaption> Wiring of th KY-009 breakout board with individual resistors for R (180 Ohm) G (100 Ohm) and B (100 Ohm). </figcaption>
</figure>

Basic sketch for looping over red, green, blue, cyan, magenta, yellow and white.

<button id= "toggleRGBanodeCombo" onclick="hiddencode('RGBanodeCombo')">Hide/Show sketch</button>

<div id="RGBanodeCombo" style="display:none">
{% capture text-capture %}
{% raw %}
```
int red_light_pin= 4;
int green_light_pin = 5;
int blue_light_pin = 6;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
void loop() {
  RGB_color(255, 0, 0); // Red
  delay(1000);
  RGB_color(0, 0, 0); // none
  delay(100);
  RGB_color(0, 255, 0); // Green
  delay(1000);
  RGB_color(0, 0, 0); // none
  delay(100);
  RGB_color(0, 0, 255); // Blue
  delay(1000);
  RGB_color(0, 0, 0); // none
  delay(100);
  RGB_color(0, 255, 255); // Cyan
  delay(1000);
  RGB_color(0, 0, 0); // none
  delay(100);
  RGB_color(255, 0, 255); // Magenta
  delay(1000);
  RGB_color(0, 0, 0); // none
  delay(100);
  RGB_color(255, 255, 0); // Yellow
  delay(1000);
  RGB_color(0, 0, 0); // none
  delay(100);
  RGB_color(255, 255, 255); // White
  delay(3000);
  RGB_color(0, 0, 0); // none
  delay(5000);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

Sketch for testing the fading of all three colors uisng PWM. It works for G and B, but not for R.

<button id= "toggleRGBfading" onclick="hiddencode('RGBfading')">Hide/Show sketch</button>

<div id="RGBfading" style="display:none">
{% capture text-capture %}
{% raw %}
```
int red_light_pin= 4;
int green_light_pin = 5;
int blue_light_pin = 6;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
void loop() {

  RGB_color(255, 255, 255); // White
  delay(1000);
  RGB_color(200, 200, 200); // White
  delay(1000);
  RGB_color(100, 100, 100); // White
  delay(1000);
  RGB_color(50, 50, 50); // White
  delay(1000);
  RGB_color(0, 0, 0); // none
  delay(50);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>

#### Comprehensive

Here is a more advanced [Testing RGB LEDs and the KY009 Three Colour LED](https://rydepier.wordpress.com/2015/07/02/ky009-three-colour-led/). According to that test the function of the KY-009 breakout board is not great, which is also my experience. First the wiring and then the sketch as described on that page.

<figure>
<img src="../../images/nano-led-ky-009-390ohm_bb.png">
<figcaption> Wiring of an RGB LED with a common anode and a common 390 Ohm resistor.</figcaption>
</figure>

<button id= "toggleKY009advanced" onclick="hiddencode('KY009advanced')">Hide/Show sketch</button>

<div id="KY009advanced" style="display:none">
{% capture text-capture %}
{% raw %}

```
*
RGB LED Test
This sketch checks a RGB LED to ensure that PWM can be used
to produce a complete range of colours
For best colour mixing results use a diffuser
*/
int gndPin = 2; // the RGB LED common connection
int redLed = 3; // the Red LED
int greenLed = 4; // the green LED
int blueLed = 5; // the blue LED
int brightness = 0; // how bright the LED is
int fadeAmount = 5; // how many points to fade the LED by
//
// set either of these to false to disable the effect
boolean rainbow = true; // enable the rainbow display
boolean fader = true; // enable the fade display
//
void setup() {
// declare pin 2 and 3 to be an output:
pinMode(gndPin, OUTPUT);
digitalWrite(gndPin, LOW);
pinMode(redLed, OUTPUT);
pinMode(greenLed, OUTPUT);
pinMode(blueLed, OUTPUT);
}
void loop(){
if (rainbow){
// Rainbow
for(int r=0; r<3; r++){
analogWrite(redLed, 255); // Red
delay(2000);
analogWrite(greenLed, 255); // Yellow
delay(2000);
analogWrite(redLed, 0); // Green
delay(2000);
analogWrite(blueLed, 128); //Blue/Green
delay(2000);
analogWrite(blueLed, 255); //Blue/Green
analogWrite(greenLed, 0); //Blue
delay(2000);
analogWrite(redLed, 255); // Violet
delay(2000);
analogWrite(redLed, 0); // LEDs all OFF
analogWrite(blueLed, 0);
}
}
// the fader effect
if(fader){
brightness = 0;
fadeAmount = 5;
redLedLoop();
analogWrite(redLed, 0);
//
brightness = 0;
fadeAmount = 5;
greenLedLoop();
//
analogWrite(greenLed, 0);
//
brightness = 0;
fadeAmount = 5;
blueLedLoop();
analogWrite(blueLed, 0);
}
}
// the fade routines
//
void redLedLoop() {
for(int i=0; i<255; i++){
analogWrite(redLed, brightness);
// change the brightness for next time through the loop:
brightness = brightness + fadeAmount;
// reverse the direction of the fading at the ends of the fade:
if (brightness == 0 || brightness == 255) {
fadeAmount = -fadeAmount ;
}
// wait for 30 milliseconds to see the dimming effect
delay(30);
}
}
void greenLedLoop(){
//
for(int i=0; i<255; i++){
analogWrite(greenLed, brightness);
// change the brightness for next time through the loop:
brightness = brightness + fadeAmount;
// reverse the direction of the fading at the ends of the fade:
if (brightness == 0 || brightness == 255) {
fadeAmount = -fadeAmount ;
}
// wait for 30 milliseconds to see the dimming effect
delay(30);
}
}
void blueLedLoop(){
for(int i=0; i<255; i++){
analogWrite(blueLed, brightness);
// change the brightness for next time through the loop:
brightness = brightness + fadeAmount;
// reverse the direction of the fading at the ends of the fade:
if (brightness == 0 || brightness == 255) {
fadeAmount = -fadeAmount ;
}
// wait for 30 milliseconds to see the dimming effect
delay(30);
}
}
```
{% endraw %}
{% endcapture %}
{% include widgets/toggle-code.html  toggle-text=text-capture  %}
</div>
