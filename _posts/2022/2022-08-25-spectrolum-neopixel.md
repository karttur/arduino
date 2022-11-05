---
layout: post
title: Microcontroller on-board light
categories: spectrolum
version: "v0.78"
excerpt: "nRF52840 on-board light control v0.78"
tags:
  - led
  - Adafruit
  - neopixel
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-08-25'
modified: '2022-08-25'
comments: true
share: true
---

If you have problems connecting your Arduino Feather board to Arduino IDE, check out the post on [Adafruit Feather nRF52840](../../module/module-feather-nRF52840).

### Introduction

The [Adafruit feather express nRF52840 microcontroller board](https://www.adafruit.com/product/4062) comes with 4 on-board Light Emitting Diodes(LEDs):

- Yellow LED indicating data transfer and battery charging
- Red LED that is controlled by pin 13
- Blue LED that is turned on when Bluetooth is connected
- Programmable NeoPixel RGB LED that turns green when sketches are uploaded

This post describes how to access and program the NeoPixel RGB LED. For a more detailed explanation see the article [Blink the On-Board NeoPixel](https://web.cecs.pdx.edu/~gerry/class/feather_sense/on-board/blinkNeoPixel/) by Gerald Recktenwald. To pilot the NeoPixel using BLE look at the example from the Bluefruit nRF52 Library in Arduino IDE: File –> Examples –> Adafruit Bluefruit nRF52 Libraries –> Peripheral –> neopixel.

### NeoPixel

NeoPixel is an Adafruit brand that describes a family of programmable LED. Refer to Adafruit’s [The Magic of NeoPixels](https://learn.adafruit.com/adafruit-neopixel-uberguide) for details. NeoPixels exist as single chips or as combinations of chips. The Adafruit NeoPixel library makes it easy to control individual NeoPixels and NeoPixels in strips, rings, small arrays, large arrays, or bulk spools.

A NeoPixel has three LEDs – red (R), green (G) and blue (B) that can be turned on separately or together.

A NeoPixel could be useful for spectrometer calibration using a single component with three distinct wavelengths. I have difficulties finding individual NeoPixels (they are all assembled into strips, rings, balls etc). Only at [Farnell](https://se.farnell.com/adafruit/1558/breadboard-friendly-rgb-smart/dp/2799898?st=neopixel) I could find individual NeoPixles for surface mount. I think, because there is no image.

#### Install driver library for NeoPixel

From the Arduino IDE menu select: Sketch –> Include Library –> Manage Libraries…

Enter “neopixel” in the search box, then select the _Adafruit NeoPixel_ by Adafruit and click <span class='button'>install</span>.

#### Sketch

The sketch is copied from [Blink the On-Board NeoPixel](https://web.cecs.pdx.edu/~gerry/class/feather_sense/on-board/blinkNeoPixel/) by Gerald Recktenwald. The built-in NeoPixel is connected to port 8.

```
//  Code original from: https://web.cecs.pdx.edu/~gerry/class/feather_sense/on-board/blinkNeoPixel/
//
//  Blink the single built-in NeoPixel on a Feather nRF42840.
//  This code is a highly stripped down and simplified version of
//  neopixel.ino from the Adafruit Bluefruit nRF52 Library example

#include <Adafruit_NeoPixel.h>    //  Library that provides NeoPixel functions

// -- Create a NeoPixel object called onePixel that addresses 1 pixel in pin 8
Adafruit_NeoPixel onePixel = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);

void setup()  {
  onePixel.begin();             // Start the NeoPixel object
  onePixel.clear();             // Set NeoPixel color to black (0,0,0)
  onePixel.setBrightness(20);   // Affects all subsequent settings
  onePixel.show();              // Update the pixel state
}

void loop()  {

  int r=0, g=0, b=100;    //  Red, green and blue intensity to display

  onePixel.setPixelColor(0, r, g, b);   //  Set pixel 0 to (r,g,b) color value
  onePixel.show();                      //  Update pixel state
  delay(1000);

  // onePixel.setPixelColor(0, 0, 0, 0);  //  same effect as clear()
  onePixel.clear();                       //  Set pixel to black (0,0,0)
  onePixel.show();                        //  Update pixel state
  delay(1000);
}
```

#### xSpectre spectrometer version 0.7 sketch

The sketch for including Adafruit NeoPixel on the nRF52840 controller in xSpectre's spectrometer, version 0.7:

```
/*
 * Initial test program for
 * Adafruit Feather nRF52840 with XSPECLUM01 board.
 *
 * Test:
 * - feather express inbuild led
 *
 * Note: the feather needs to be removed from the board when updated,
 * since the bootloader does not set nKILL high (which will turn off the device after a few hundreds of ms).
 *
 *
 * Arduino IDE installation:
 * ========================
 *     Download and install the Arduino IDE (At least v1.8)
 *     Start the Arduino IDE
 *     Go into Preferences
 *     Add https://adafruit.github.io/arduino-board-index/package_adafruit_index.json as an 'Additional Board Manager URL'
 *     Restart the Arduino IDE
 *     
 *     Open the Boards Manager option from the Tools -> Board menu and install 'Adafruit nRF52 by Adafruit'
 *     Once the BSP is installed (takes long time with a long delay in the middle), select
 *     Adafruit Bluefruit nRF52840 Feather Express (for the nRF52840) from the Tools -> Board menu
 *     
 *
 *
 * To update the bootloader:
 * =========================
 * Step 1:
 * Tools -> Board: Adafruit Feather nRF52840 Express
 * select "Bootloader DFU for Bluefruit nRF52" for Tools->Programmer
 * Select the right com port
 * Tools->Burn Bootloader
 *
 * Step 2:
 * Double-click the Reset button. NeoPixel turns green.
 * Drag the downloaded .uf2 file to FTHR840BOOT. The LED will flash.
 *
 */

#define DAC6571_ADDR 0x4C

#define Ph            A0
#define VID_IN        A1
#define AN2           A2
#define nKILL         17
#define nPBINT        18
#define ONEWIRE       19

#define GPIOSCK       26  // NC
#define nRE           25
#define GPIOMISO      24
#define GPIORX        1
#define GPIOTX        0
#define GPIOD2        2

#define VID_CLK       13
#define VID_ST        12
#define VID_TRG       11
#define VID_EOS       10

#define VID_BOOST_EN  9
#define LED_BUCK_EN   6
#define LED_PULSE     5

#define GPIOSCL       23
#define GPIOSDA       22

#define USERSWITCH    7
#define BATTERYV2     A6
#define NEOPIXEL      8


#if defined(USE_TINYUSB)
#include <Adafruit_TinyUSB.h> // for Serial
#endif

#include <Wire.h>

#include <Adafruit_NeoPixel.h>    //  Library that provides NeoPixel functions

// -- Create a NeoPixel object called onePixel that addresses 1 pixel in pin 8
Adafruit_NeoPixel rgbPixel = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);


void setup() {

  pinMode(Ph,       INPUT);  // Ph
  pinMode(VID_IN,   INPUT);  // VID_IN
  pinMode(AN2,      INPUT);  // AN2 (from expansion socket)
  pinMode(nKILL,    OUTPUT); // #KILL
  pinMode(nPBINT,   INPUT);  // #PBINT (pushbutton)
  pinMode(ONEWIRE,   INPUT);  // 1W interface (pulle dup to 3v3 by 2k2)
  pinMode(SCK,      OUTPUT); // - (not connected)
  pinMode(nRE,      OUTPUT); // #RE (Receive enabled, RS485)
  pinMode(GPIOMISO, OUTPUT); // - (not connected)
  pinMode(GPIORX,   INPUT);  // Rx (Uart)
  pinMode(GPIOTX,   OUTPUT); // Tx (Uart)
  pinMode(GPIOD2,   OUTPUT); // - (not connected)

  pinMode(VID_CLK,   OUTPUT); // VID_CLK
  pinMode(VID_ST,    OUTPUT); // VID_ST
  pinMode(VID_TRG,   INPUT);  // VID_TRG
  pinMode(VID_EOS,   INPUT);  // VID_EOS
  pinMode(VID_BOOST_EN, OUTPUT); // VID_BOOST_EN
  pinMode(LED_BUCK_EN,  OUTPUT); // LED_BUCK_EN
  pinMode(LED_PULSE,    OUTPUT); // LED_PULSE
  pinMode(GPIOSCL,  INPUT);  // SCL
  pinMode(GPIOSDA,  INPUT);  // SDA

  pinMode(USERSWITCH,   INPUT);  // User switch

  pinMode(A6,           INPUT);  // Battery voltage/2
  pinMode(LED_BUILTIN,  OUTPUT); // Red LED
  pinMode(NEOPIXEL,     OUTPUT); // RGB LED

  digitalWrite(nKILL, HIGH);     // Keep the unit on. 3v3 feeds Rh/T sensor, Ph sensor and LED driver DAC

  digitalWrite(VID_CLK, LOW);
  digitalWrite(VID_ST, LOW);

    // Disable LED driver
  digitalWrite(LED_BUCK_EN, LOW);
  digitalWrite(LED_PULSE, HIGH);

  // Start Spectrometer and RS485
  digitalWrite(VID_BOOST_EN, HIGH); // +5V for rs485
  digitalWrite(nRE, HIGH);          // Set transmit mode

  // Loop until Serial started - just to test the led flash
  Serial.begin(115200);
  while ( !Serial ) {
    digitalWrite(LED_RED, HIGH);
    delay(100);  
    digitalWrite(LED_RED, LOW);
    delay(100);
  }

  rgbPixel.begin();             // Start the NeoPixel object
  rgbPixel.clear();             // Set NeoPixel color to black (0,0,0)
  rgbPixel.setBrightness(20);   // Affects all subsequent settings
  rgbPixel.show();              // Update the pixel state

}

// Set DAC voltage (raw DAC value)
// 12 bit, 0-4095 <=> 0-3.3V
void DAC6571_setVoltage(uint16_t v)
{
  uint16_t vh,vl;

  vh=(v>>8) & 0xff;
  vl=v & 0xff;
  Wire.beginTransmission(DAC6571_ADDR);
  Wire.write(vh); // PD bits =0 (bit 4-5) = Normal operation
  Wire.write(vl);
  Wire.endTransmission();
}

#define RA 68.0
#define RB 16.9
#define RD 75.0
#define DAC_VREF_mV 3300.0
#define DAC_MAX 4095.0
#define VSET_MIN_mV 566
#define VSET_MAX_mV 3558


void LED_setVoltage_mV(float vset_mV)
{
  float vdac_mV=600*(RD/RB+1)+(600-vset_mV)*RD/RA;
//  (600.0*(1+RA/RB)-vset_mV)*RD/RA+600.0;
  float r=vdac_mV/DAC_VREF_mV*DAC_MAX;

  DAC6571_setVoltage((uint16_t)r);
}


float LED_vset_mV = VSET_MIN_mV;

void loop()
{
  int adcvalue = 0;
  float ph,vbat,vid_in,an2;
  float mv_per_lsb = 3600.0F/1024.0F; // 10-bit ADC with 3.6V input range
  float soiLMoisture; //the soil moisture in percent
  uint8_t resultMain;


 int r=0, g=255, b=100;    //  Red, green and blue intensity to display for rgbPixel (NeoPixel object), 0 <= r <= 255

 delay (500);
 digitalWrite(LED_RED, HIGH);
 digitalWrite(LED_BLUE, HIGH);
 rgbPixel.setPixelColor(0, r, g, b);   //  Set pixel 0 to (r,g,b) color value
 rgbPixel.show();
 delay (500);
 digitalWrite(LED_RED, LOW);
 digitalWrite(LED_BLUE, LOW);
 rgbPixel.clear();                       //  Set pixel to black (0,0,0)
 rgbPixel.show();                        //  Update pixel state
/*
// Test LED power/ pulse
// With IC5 output=0V we should get 3.335V out.
// Pulse square wave drive, 500ms period:
 delay (250);
 digitalWrite(LED_PULSE, HIGH);
 digitalWrite(LED_RED, HIGH);
 digitalWrite(LED_BLUE, HIGH);
 delay (250);
 digitalWrite(LED_PULSE, LOW);
 digitalWrite(LED_RED, LOW);
 digitalWrite(LED_BLUE, LOW);
*/

 adcvalue = analogRead(AN2);
 an2=(float)adcvalue * mv_per_lsb;

 adcvalue = analogRead(PIN_VBAT);
 vbat=(float)adcvalue * mv_per_lsb *2;


 Serial.println();


}
```
