---
layout: post
title: GoSpectro spectrometer
categories: sketch
version: v0.80
excerpt: "Core Arduino sketch for Spectrolum v080"
tags:
  - spectrolum
  - v080
  - skecth
  - core
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2023-02-13 11:27'
modified: '2023-02-13 T11:27'
comments: true
share: true
---

The Arduino sketch below is the backbone defining all the Input/Output (IO) ports of xSpectre spectrometer version 0.80 on the Adafruit Feather nRF52832.

The sketch works without attaching the Adafruit Feather nRF52832 to the spectrolum Printed Circuit Board (PCB). The sketch result in a color LED loop of the bulit-in RGB (neopixel) LED, displaying a sequence 5 basic colors representing the rainbow

```
/*
 * Initial test program for
 * Adafruit Feather nRF52832 with XSPECLUM01 board.
 *
 * Core:
 * Initiate the ports and loop using the nRF52832 Adafruit_NeoPixel
 *
 * Note: the feather needs to be removed from the board when updated,
 * since the bootloader does not set nKILL high (which will turn off the device after a few hundreds of ms).
 *
 */

#define DAC6571_ADDR 0x4C

#define BNC               A0
#define SPECTRO_AN        A1 // The analog video signal for the spectrometer
#define GX16_AN           A2 // The GX16 analog sensor signal
#define nKILL             17
#define nPBINT            18
#define ONEWIRE           19

#define GPIOSCK           26  // NC
#define nRE               25
#define GPIOMISO          24
#define GPIORX            1
#define GPIOTX            0
#define GPIOD2            2

#define SPECTRO_CLK       13
#define SPECTRO_ST        12
#define SPECTRO_TRG       11
#define SPECTRO_EOS       10
#define SPECTRO_BOOST_EN  9

#define LED_BUCK_EN       6
#define LED_PULSE         5

#define GPIOSCL           23
#define GPIOSDA           22

#define USERSWITCH        7
#define BATTERYV2         A6
#define NEOPIXEL          8

/* Define the channels of the spectrometer
  The definition below, 256 channels starting at channel 64 is for HAMAMATSU SMD
*/

#define SPECTRO_CHANNELS          256 // Nr of spectral channels in sensor
#define SPECTRO_START_CHANNEL     64 // First channel with valid data
#define SPECTRO_END_CHANNEL       256 // Last channel with valid data
#define SPECTRO_integration_time  300 // Integration time for spectral sensor sampling ("expsoture rime")

uint16_t data[SPECTRO_CHANNELS];

#include <Adafruit_NeoPixel.h>    //  Library that provides NeoPixel functions

// -- Create a NeoPixel object called onePixel that addresses 1 pixel in pin 8
Adafruit_NeoPixel rgbPixel = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);

/* tinyusb is for the serical connection with Adafruit nRF52 boards */
#if defined(USE_TINYUSB)
#include <Adafruit_TinyUSB.h> // for Serial
#endif

void setup() {

  pinMode(BNC,      INPUT);  // BNc connection - usually an Ion Selecteve Electrode (ISE)
  pinMode(SPECTRO_AN,   INPUT);  // Spectro video analog signal
  pinMode(GX16_AN,      INPUT);  // Aalog signal from GX16 expansion socket)
  pinMode(nKILL,    OUTPUT); // #KILL
  pinMode(nPBINT,   INPUT);  // #PBINT (pushbutton)
  pinMode(ONEWIRE,   INPUT);  // 1W interface (pulled up to 3v3 by 2k2)
  pinMode(SCK,      OUTPUT); // - (not connected)
  pinMode(nRE,      OUTPUT); // #RE (Receive enabled, RS485)
  pinMode(GPIOMISO, OUTPUT); // - (not connected)
  pinMode(GPIORX,   INPUT);  // Rx (Uart)
  pinMode(GPIOTX,   OUTPUT); // Tx (Uart)
  pinMode(GPIOD2,   OUTPUT); // - (not connected)

  pinMode(SPECTRO_CLK,   OUTPUT); // Spectrometer clock pulse
  pinMode(SPECTRO_ST,    OUTPUT); // Spectrometer start pulse
  pinMode(SPECTRO_TRG,   INPUT);  // Spectrometer trigger pulse
  pinMode(SPECTRO_EOS,   INPUT);  // SPECTRO_EOS
  pinMode(SPECTRO_BOOST_EN, OUTPUT); // Spectrometer end of scan

  pinMode(LED_BUCK_EN,  OUTPUT); // LED_BUCK_EN
  pinMode(LED_PULSE,    OUTPUT); // LED_PULSE

  pinMode(GPIOSCL,  INPUT);  // SCL
  pinMode(GPIOSDA,  INPUT);  // SDA

  pinMode(USERSWITCH,   INPUT);  // User switch

  pinMode(A6,           INPUT);  // Battery voltage/2
  pinMode(LED_BUILTIN,  OUTPUT); // Red LED

  pinMode(NEOPIXEL,     OUTPUT); // RGB LED

  digitalWrite(nKILL, HIGH);     // Keep the unit on. 3v3 feeds Rh/T sensor, Ph sensor and LED driver DAC
  digitalWrite(nRE, HIGH);       // Set transmit mode
  digitalWrite(SPECTRO_CLK, LOW);
  digitalWrite(SPECTRO_ST, LOW);
  digitalWrite(SPECTRO_BOOST_EN, LOW);

  digitalWrite(LED_BUCK_EN, LOW);

  Serial.begin(115200);

  // Light source
  // Turn off LED_PULSE before starting
  //  digitalWrite(LED_PULSE, LOW);
  digitalWrite(LED_PULSE, LOW);

  // Start LED driver
  digitalWrite(LED_BUCK_EN, HIGH);
  //  Turn on LED_PULSE;
  digitalWrite(LED_PULSE, HIGH);

  // Prepare the builtin neopixel - will loop the rainbow to indicate that spetrometer is scanning
  rgbPixel.begin();             // Start the NeoPixel object
  rgbPixel.clear();             // Set NeoPixel color to black (0,0,0)
  rgbPixel.setBrightness(20);   // Affects all subsequent settings
  rgbPixel.show();              // Update the pixel state

  // Blonk the built-in REd and BLUE lights
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  delay(100);   
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
}

int red = 0; int green = 0; int blue = 0;

int loopnr = 0;

void loop()
{

  loopnr+=1;

  // Step rgbpixel values blue - gree - yellow - red - purple -blue
  if (loopnr == 1) { red=0; green=0; blue=100; }
  else if (loopnr == 2) { red=0; green=100; blue=0; }
  else if (loopnr == 3) { red=80; green=80; blue=0; }
  else if (loopnr == 4) { red=100; green=0; blue=0; }
  else  { red=80; green=0; blue=80; }

  rgbPixel.setPixelColor(0, red, green, blue); //  Set pixel 0 to (r,g,b) color value

  rgbPixel.show(); //  Update pixel state

  digitalWrite(LED_RED, HIGH);

  if (loopnr == 5) {
    loopnr = 0;
  }

 delay (200);

 digitalWrite(LED_RED, LOW);

 delay (200);

}
```
