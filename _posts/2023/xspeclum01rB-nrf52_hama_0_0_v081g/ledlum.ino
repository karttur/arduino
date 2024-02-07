/*
 * 
 * 
 * 
 * 
 */

 #define ONEWIRE           19

/* START Define the muzzle ONEWIRE EEPROM memory */
#include "OneWire.h"
OneWire ds(ONEWIRE);                    // OneWire bus on digital pin 19 (defiend as ONEWIRE aboe)
// Definde the 1-wire address @ 8 bytes
byte OneWireAddr[8]; // The 1-wire unique ID
/* END Define the muzzle ONEWIRE EEPROM memory */

// Set the arrays holding the EEPROM data
String eepromStrings[4];
int eepromInts[3];

bool ledLumInitiated = false;

void setupLedLum () {
  if(!ledLumInitiated) {
    pinMode(ONEWIRE,   INPUT);  // 1W interface (pulled up to 3v3 by 2k2)
    ledLumInitiated = true;
  }
}

String ledLumGetMuzzleuuid() {
  return eepromStrings[0];
}

String ledLumGetMuzzleType() {
  return eepromStrings[0];
}

int ledLumGetLedVset() {
  return eepromInts[6];
}

int ledLumGetIntegrationTime() {
  return eepromInts[7];
}

int ledLumGetStabilizationTime() {
  return eepromInts[8];
}

/* START Search for the connected muzzle 1-wire address and check that it is OK, return false or true */
bool SearchOneWireAddress(byte* address) //Search for address and confirm it
{
  int i;
  if (verbos){
    Serial.println("SearchOneWireAddress:");
  }
  ds.reset_search();
  
  if ( !ds.search(OneWireAddr))
  {
    // no ONEWIRE ATTACH - red blink
    setRGBNeopixel(100, 0, 0);

    if (verbos) {
      Serial.print("  No muzzle (eeprom device) found.\n");
    } 
    ds.reset_search();
    delay(250);
    turnOffNeopixel();

    return false;
  }

  if (verbos) {
    // Print the 1wire ID
    Serial.print("  muzzle HEX ID=");
    for( i = 0; i < 8; i++) {
      Serial.print(OneWireAddr[i], HEX);
      Serial.print(" ");
    }
    Serial.println(" ");  
  }
  
  // Cyclic Redundance Check (CRC)
  if ( OneWire::crc8( OneWireAddr, 7) != OneWireAddr[7]) {
    // CRC error - orange blink
    setRGBNeopixel(50, 50, 0);

    if (verbos) {
      Serial.print("  Invalid muzzle (eeprom device) address!\n");
    }
    delay(250);
    setRGBNeopixel(100, 100, 0);

    return false;
  }
  
  if ( OneWireAddr[0] != 0x2D) {
    // wrong ONEWIRE ATTACH - yellow blink
    setRGBNeopixel(100, 100, 0);

    if (verbos) {
      Serial.print("  Device is not a 1-wire Eeprom.\n");
    } 
    delay(250);
    turnOffNeopixel();

    return false;
  }

  return true;
}
/* END Search for the connected muzzle 1-wire address and check that it is OK*/

/* START Read the complete content of the 1-wide DS2431 memory and
 *  retrieve the values of the predefined parameters */

void Read1WDS2431Mem(String* eepromStrings, int* eepromInts, bool diagnos)
{
  int i;
  ds.reset();
  ds.select(OneWireAddr);
  ds.write(0xF0,1);  // Read Memory
  ds.write(0x00,1);  //Read Offset 0000h
  ds.write(0x00,1);

  String muzzleuuid; // 36 [5]
  String muzzleversion; // 4
  String muzzleid; // 8 [1]
  String emittorid; // 32 [4]
  String minV; // 4
  String maxV; // 4
  String forwardV; //4
  String stabilisationtime; //4
  String creationdate; //8 = Summa 105 bitar
 
  for ( i = 0; i < 104; i++) //whole mem is 144 
  {
    char c = ds.read();
    
    if (i < 36) {
      muzzleuuid += c;
    } else if (i < 40) {
      muzzleversion += c;
    } else if (i < 48) {
      muzzleid += c;  
    } else if (i < 80) {
      emittorid += c;  
    } else if (i < 84) {
      minV += c;
    } else if (i < 88) {
      maxV += c; 
    } else if (i < 92) {
      forwardV += c;  
    } else if (i < 96) {
      stabilisationtime += c;
    } else if (i < 104) {
      creationdate += c;
    }
  }

  // Convert strings to string array
  eepromStrings[0] = muzzleuuid;
  eepromStrings[1] = muzzleversion;
  eepromStrings[2] = muzzleid;
  eepromStrings[3] = emittorid;
  eepromStrings[4] = creationdate;

  // Convert integers to integer array
  eepromInts[0] = minV.toInt();
  eepromInts[1] = maxV.toInt();
  eepromInts[2] = forwardV.toInt();
  eepromInts[3] = stabilisationtime.toInt();

  if (verbos) {
    Serial.println("  muzzleuuid:" + eepromStrings[0]);
    Serial.println("  muzzleversion:" + eepromStrings[1]);
    Serial.println("  muzzleidn:" + eepromStrings[2]);
    Serial.println("  emittorid:" + eepromStrings[3]);
    Serial.println("  minV:" + minV);
    Serial.println("  maxV:" + maxV);
    Serial.println("  forwardV:" + forwardV);
    Serial.println("  stabilisationtime:" + stabilisationtime);
    Serial.println("  creationdate:" + eepromStrings[3]);
    Serial.println();   
  }
  
}

/* END Read the complete content of the muzzle 1-wide DS2431 memory */
