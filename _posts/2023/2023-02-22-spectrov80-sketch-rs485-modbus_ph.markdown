---
layout: post
title: rs485/MODBUS pH
categories: sketch
version: v0.80
excerpt: "Arduino sketch for rs485/MODIS pH probe for Spectrolum v080"
tags:
  - spectrolum
  - v080
  - skecth
  - ph
  - ModbusMaster
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-02-22 11:27'
modified: '2022-02-22 T11:27'
comments: true
share: true
---

```
/*
 * Initial test program for
 * Adafruit Feather nRF52840 with XSPECLUM01 board.
 *
 * RS485/MODBUS:
 * - rs485 communication with ph sensor (modbusMaster)
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

#define SPECTRO_CHANNELS          256 // Nr of spectral channels in sensor
#define SPECTRO_START_CHANNEL     64 // First channel with valid data
#define SPECTRO_END_CHANNEL       256 // Last channel with valid data
#define SPECTRO_integration_time  300 // Integration time for spectral sensor sampling ("expsoture rime")

uint16_t data[SPECTRO_CHANNELS];

#include <Adafruit_NeoPixel.h>    //  Library that provides NeoPixel functions

// -- Create a NeoPixel object called onePixel that addresses 1 pixel in pin 8
Adafruit_NeoPixel rgbPixel = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);

#include <Wire.h>                 // Library
#include "SHT2x.h"                // Library for in-box temperature and relaive humidity

// -- Create a SHT2x object called sht for accessing the in-box Temperature and Relative Humidity
SHT2x sht;

/* ModbusMaster For communication with RS485+MODBUS sensors */
#include <ModbusMaster.h>  

/* tinyusb is for the serical connection with Adafruit nRF52 boards */
#if defined(USE_TINYUSB)
#include <Adafruit_TinyUSB.h> // for Serial
#endif

/* Setup the Modbus transmission basics */

void PreTransmission(){
  // Set transmit mode
  digitalWrite(nRE, HIGH);
}

void PostTransmission(){
  // Set receive mode
  digitalWrite(nRE, LOW);
}

// instantiate ModbusMaster object
ModbusMaster node;


/* END - Setup the Modbus transmission basics */

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

  pinMode(NEOPIXEL,     OUTPUT); // RGB

  // Disable LED driver
  digitalWrite(LED_BUCK_EN, LOW);
  digitalWrite(LED_PULSE, HIGH);

  // Start Spectrometer and RS485
  digitalWrite(SPECTRO_BOOST_EN, HIGH); // +5V for rs485
  digitalWrite(nRE, HIGH);          // Set transmit mode

  Serial1.begin(4800);
  node.begin(1, Serial1);
  node.preTransmission(PreTransmission);
  node.postTransmission(PostTransmission);
}

void print_rs485_modbus_ph(float ph){

  Serial.print("rs485/modbus pH:");

  Serial.print(ph,1);

  Serial.print("\n");

}


void rs485_modbus_ph(bool fullprint=0, bool valueprint=1){

  uint8_t resultMain;
  float phx10 = -999;
  float ph = -999;

  // 0x0000 = pH
  delay(2500);
  resultMain = node.readInputRegisters(0x0000, 1);
  if (resultMain == node.ku8MBSuccess)
  {
    phx10 = node.getResponseBuffer(0x00);
    ph = phx10/10;
  }

  if (fullprint){
    print_rs485_modbus_ph(ph);
  }
  else if (valueprint) {
    print_rs485_modbus_ph(ph);
  }

}


#define RA 68.0
#define RB 16.9
#define RD 75.0
#define DAC_VREF_mV 3300.0
#define DAC_MAX 4095.0
#define VSET_MIN_mV 566
#define VSET_MAX_mV 3558

#define pH_OFFSET_mV 1650
#define pH_GAIN 3
#define pH_mV_PER_pH 59.194
#define pH_OFFSET_pH 7


void loop()
{
  bool fullprint = 1;
  bool valueprint = 0;
  int adcvalue = 0;
  float ph,vbat,vid_in,an2;
  float mv_per_lsb = 3600.0F/1024.0F; // 10-bit ADC with 3.6V input range

  delay (100);
  digitalWrite(LED_RED, HIGH);

  rs485_modbus_ph(fullprint,valueprint);

  delay (100);
  digitalWrite(LED_RED, LOW);

}
```
