---
layout: post
title: AMS 6-band spectral sensor
categories: sketch
version: v0.80
excerpt: "Arduino sketch for AMS 6-band sensor, Spectrolum v080"
tags:
  - spectrolum
  - v080
  - skecth
  - NPK
  - pH
  - SM
  - EC
  - ModbusMaster
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-02-24 11:27'
modified: '2022-02-24 T11:27'
comments: true
share: true
---

This Arduino sketch is for a GX16 connected Capacitive Soil Moisture probe that signals the result via the analog port (GX16_AN).

```
/*
 * Initial test program for
 * Adafruit Feather nRF52840 with XSPECLUM01 board.
 *
 * Test:
 * - GX16 analog signal from Capacitive soil moisture
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

#include <Wire.h>                 // Library

#include "Adafruit_AS726x.h"      // Library for the AMS GX16 sensor

//create the ams spectrometer object
Adafruit_AS726x ams;

//buffer to hold raw values
uint16_t amsScan[AS726x_NUM_CHANNELS];

#if defined(USE_TINYUSB)
#include <Adafruit_TinyUSB.h> // for Serial
#endif

bool gx16ams = false;

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


  Serial.begin(115200);

  //begin and make sure we can talk to the sensor
  if(!ams.begin()){
    Serial.println("No AMS sensor connected to external GX16 port.");
    //while(1);
  } else {
    Serial.println("AMS sensor connected to external GX16 port.");
    gx16ams = true;
  }

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

void value_print_SpectraScan(String idStr, int onoff, int start_ch, int end_ch){

  int i;

  Serial.print(idStr);
  Serial.print(onoff);
  Serial.print(',');

  for ( i = start_ch ; i < end_ch ; i++ )
  {
    Serial.print(amsScan[i]);
    if (i < end_ch-1){
      Serial.print(',');
    }

  }

  Serial.print("\n");
}

void gx16spectraScan(bool valueprint=true)
{
  //read the device temperature
  uint8_t temp = ams.readTemperature();

  String idStr = "6-band ams scan:";

  ams.drvOn(); // turn on LED

  ams.startMeasurement(); //begin a measurement

  //wait till data is available
  bool rdy = false;
  while(!rdy){
    delay(5);
    rdy = ams.dataReady();
  }

  ams.readRawValues(amsScan);

  if (valueprint) {

    value_print_SpectraScan(idStr, 1, 0, 6);

  }

  ams.drvOff(); // turn on LED

  ams.startMeasurement(); //begin a measurement

  //wait till data is available
  bool rdy2 = false;
  while(!rdy2){
    delay(5);
    rdy2 = ams.dataReady();
  }

  ams.readRawValues(amsScan);

  if (valueprint) {

    value_print_SpectraScan(idStr, 0, 0, 6);

  }
}

void LED_setVoltage_mV(float vset_mV)
{
  float vdac_mV=600*(RD/RB+1)+(600-vset_mV)*RD/RA;
//  (600.0*(1+RA/RB)-vset_mV)*RD/RA+600.0;
  float r=vdac_mV/DAC_VREF_mV*DAC_MAX;

  DAC6571_setVoltage((uint16_t)r);
}

#define pH_OFFSET_mV 1650
#define pH_GAIN 3
#define pH_mV_PER_pH 59.194
#define pH_OFFSET_pH 7

// in: ADC value (mV)
// Out: pH
float pH_mV_to_pH(float mv)
{
// 0V in => pH=7
// 59.194mV/pH
 float p;

 p= mv-pH_OFFSET_mV;
 p= p/pH_GAIN;
 return (p/pH_mV_PER_pH+pH_OFFSET_pH);
}

float LED_vset_mV = VSET_MIN_mV;

void loop()
{
  bool fullprint = 1;
  bool valueprint = 0;

  float mv_per_lsb = 3600.0F/1024.0F; // 10-bit ADC with 3.6V input range

  int adcvalue = 0;
  float ph,vbat,vid_in,an2;

  float soiLMoisture; //the soil moisture in percent
  uint8_t resultMain;

 delay (200);
 digitalWrite(LED_RED, HIGH);

 if (gx16ams) {

    gx16spectraScan();

 }

 delay (200);
 digitalWrite(LED_RED, LOW);

}
```
