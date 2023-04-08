---
layout: post
title: rs485 MODBUS sketch alternatives
categories: sketch
version: v0.80
excerpt: "Alternative packages for connecting to rs485-MODBUS devices"
tags:
  - spectrolum
  - v080
  - skecth
  - rs485
  - modbus
  - modbusmaster
  - softwareserial
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-02-17 11:27'
modified: '2022-02-17 T11:27'
comments: true
share: true
---

xSpectre spectrometer **+** can connect external sensors using the rs485/MODBUS standard. This option is available via the GX16 plug. For v080 of the spectrometer it is primarily the soil probes built using stainless steel pins that make use of the rs485/MDOBUS standard.

There are two different Arduino IDE compatible libraries that are commonly used for communicating using the rs485/MODBUS standard:

- SoftwareSerial
- Modbusmaster

The [SoftwareSerial library](https://docs.arduino.cc/learn/built-in-libraries/software-serial) allows serial communication on non-dedicated digital pins of an Arduino board, using software to replicate the dedicated pins functionality (hence the name "SoftwareSerial"). SoftwareSerial is the more common library used for communicating with rs485/MDOBUS devices. Developing the sketches for the rs485/MDOBUS stainless steel probes I mostly used SoftwareSerial as the documentation for that is in general better.

Once I had tested and evaluated the communication with the rs485/MDOBUS devices, I, however, opted for changing to the [ModbusMaster library](https://github.com/4-20ma/ModbusMaster). ModbusMaster is a more clean library intended for communicating with Modbus slaves over RS232/RS485 via the RTU protocol.

To illustrate the difference between using SoftwareSerial and ModbusMaster, both versions as given below - for reading the soil NPK sensor.

### Soil NPK sensor SoftwareSerial


```
/*
 * Initial test program for
 * Adafruit Feather nRF52840 with XSPECLUM01 board.
 *
 * Test:
 * - rs485 communication with NPK sensor, SoftwareSerial
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

#define ISE           A0
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
//#include <ModbusMaster.h>   // ModbusMaster For communication with MODBUS+RS485 sensors
#include <SoftwareSerial.h>

void PreTransmission(){
  // Set transmit mode
  digitalWrite(nRE, HIGH);
}

void PostTransmission(){
  // Set receive mode
  digitalWrite(nRE, LOW);
}

// Modbus RTU requests for reading NPK values
const byte nitro[] = {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
const byte phos[] = {0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
const byte pota[] = {0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};

// A variable used to store NPK values
byte values[11];

// Connection for SoftwareSerial
SoftwareSerial mod(1, 0);

void setup() {

  pinMode(ISE,      INPUT);  // Ion Selective Electrode
  pinMode(VID_IN,   INPUT);  // VID_IN
  pinMode(nKILL,    OUTPUT); // #KILL
  pinMode(nPBINT,   INPUT);  // #PBINT (pushbutton)

  pinMode(ONEWIRE,   INPUT);  // 1W interface (pulle dup to 3v3 by 2k2)
  pinMode(SCK,      OUTPUT); // - (not connected)
  pinMode(nRE,      OUTPUT); // #RE (Receive enabled, RS485)
  pinMode(GPIOMISO, OUTPUT); // - (not connected)
  pinMode(GPIORX,   INPUT);  // Rx (Uart)
  pinMode(GPIOTX,   OUTPUT); // Tx (Uart)
  pinMode(GPIOD2,   OUTPUT); // - (not connected)

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

  // Disable LED driver
  digitalWrite(LED_BUCK_EN, LOW);
  digitalWrite(LED_PULSE, HIGH);

  // Start Spectrometer and RS485
  digitalWrite(VID_BOOST_EN, HIGH); // +5V for rs485
  digitalWrite(nRE, HIGH);          // Set transmit mode

  // Set the baud rate for the SerialSoftware object
  // The soil-NPK sensor is set to a baudrate of 4800
  mod.begin(4800);

}

void rs485_modbus_softwareserial() {
  // Read values
  byte val1,val2,val3;
  val1 = nitrogen();
  delay(250);
  val2 = phosphorous();
  delay(250);
  val3 = potassium();
  delay(250);

  // Print values to the serial monitor
  Serial.print("Nitrogen: ");
  Serial.print(val1);
  Serial.println(" mg/kg");
  Serial.print("Phosphorous: ");
  Serial.print(val2);
  Serial.println(" mg/kg");
  Serial.print("Potassium: ");
  Serial.print(val3);
  Serial.println(" mg/kg");

  delay(2000);
}

byte nitrogen(){

  digitalWrite(nRE,HIGH);
  delay(10);
  if(mod.write(nitro,sizeof(nitro))==8){

    digitalWrite(nRE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
    Serial.print(values[i],HEX);
    }
    Serial.println();
  }
  return values[4];
}

byte phosphorous(){

  digitalWrite(nRE,HIGH);
  delay(10);
  if(mod.write(phos,sizeof(phos))==8){

    digitalWrite(nRE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
    Serial.print(values[i],HEX);
    }
    Serial.println();
  }
  return values[4];
}

byte potassium(){

  digitalWrite(nRE,HIGH);
  delay(10);
  if(mod.write(pota,sizeof(pota))==8){

    digitalWrite(nRE,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod.read();
    Serial.print(values[i],HEX);
    }
    Serial.println();
  }
  return values[4];
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
  int adcvalue = 0;
  float ph,vbat,vid_in,an2;
  float mv_per_lsb = 3600.0F/1024.0F; // 10-bit ADC with 3.6V input range

  delay (100);
  digitalWrite(LED_RED, HIGH);

  rs485_modbus_softwareserial();

  delay (100);
  digitalWrite(LED_RED, LOW);

}
```

### Soil NPK sensor ModbusMaster

```
/*
 * Initial test program for
 * Adafruit Feather nRF52840 with XSPECLUM01 board.
 *
 * Test:
 * - rs485 communication with NPK sensor, ModbusMaster
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

  // Set the baud rate for the sensor connection
  // The soil-NPK sensor is set to a baudrate of 4800
  Serial1.begin(4800);
  node.begin(1, Serial1);
  node.preTransmission(PreTransmission);
  node.postTransmission(PostTransmission);
}

void print_rs485_modbus_npk(int nitrogen, int phosphorus, int potassium){

  Serial.print(nitrogen);
  Serial.print(',');
  Serial.print(phosphorus);
  Serial.print(',');
  Serial.print(potassium);

  Serial.print("\n");

}

void rs485_modbus_npk(){

  uint8_t resultMain;
  int nitrogen = -999;
  int phosphorus = -999;
  int potassium = -999;

  // 0x0002 = Nitrogen (mg/kg)
  delay (50);
  resultMain = node.readInputRegisters(0x0002, 1);
  if (resultMain == node.ku8MBSuccess)
  {
    nitrogen = node.getResponseBuffer(0x00);
  }

  // 0x0000 = Phosphorus (mg/kg)
  delay (50);
  resultMain = node.readInputRegisters(0x000, 1);
  if (resultMain == node.ku8MBSuccess)
  {
    phosphorus = node.getResponseBuffer(0x00);
  }

  // 0x0001 = Potassium (mg/kg)
  delay (50);
  resultMain = node.readInputRegisters(0x0001, 1);
  if (resultMain == node.ku8MBSuccess)
  {
    potassium = node.getResponseBuffer(0x00);
  }

  print_rs485_modbus_npk(nitrogen, phosphorus, potassium);

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
  int adcvalue = 0;
  float ph,vbat,vid_in,an2;
  float mv_per_lsb = 3600.0F/1024.0F; // 10-bit ADC with 3.6V input range

  delay (100);
  digitalWrite(LED_RED, HIGH);

  rs485_modbus_npk();

  delay (100);
  digitalWrite(LED_RED, LOW);

}
```
