---
layout: post
title: littleFS
categories: project
excerpt: "Adafruit Little File System for NRF boards."
tags:
- weight
- pressure
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2023-09-29 11:27'
modified: '2023-09-29 T18:17:25.000Z'
comments: true
share: true
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

### Introduction

The _littleFS_ library is used for reading and writing local data to the Adafruit nrF52 Flash memory (Nordic semiconductors).

```
#include <Adafruit_LittleFS.h>
#include <InternalFileSystem.h>
#include <Adafruit_TinyUSB.h> // for Serial

using namespace Adafruit_LittleFS_Namespace;

#define SENSORFN    "/sensors.txt"
#define SENSORCONTENTS    "mainspectralsensor:c14384ma-01,modbussesnor:tsmnpkph"

#define MAINSENSORFN    "/mainsensor.txt"
#define MAINSENSORCONTENTS    "id:45J3039,AO:2.234,B1:7.678"

File file(InternalFS);

/* receive commands */

const byte numChars = 196;

char receivedChars[numChars];   // an array to store the received data

boolean newData = false;

char userInput;

String inString = "";

void setup() {
  Serial.begin(115200);
  while ( !Serial ) delay(10);   // for nrf52840 with native usb

  Serial.println("Press <Y> to continue");

  while ( !Serial.available() ) {
    delay(1);
    // Listen for input string
    recvWithOutStartEndMarkers();
  }

}

void WriteSensorsLitteFS(){

  bool removeFile = false;
  bool writeFile = false;

  // Initialize Internal File System
  InternalFS.begin();

  file.open(SENSORFN, FILE_O_READ);


  if ( file ) {
    Serial.println("\n  file exists: " SENSORFN );

    uint32_t readlen;
    char buffer[256] = { 0 };
    readlen = file.read(buffer, sizeof(buffer));

    buffer[readlen] = 0;
    Serial.print("\n    file content: ");
    Serial.println( buffer);
    file.close();

    Serial.print("\n     new content: ");
    Serial.println( SENSORCONTENTS);

    // Ask if file is to be overwritten
    newData = false;

    Serial.println("\n  Press <Y> to overwrite <N> to keep");

    while ( !newData )
    {
      delay(1);
      // Listen for input string
      recvWithOutStartEndMarkers();
    }

    if (newData == true) {

      inString = String(receivedChars);

      if (inString == "Y"){
        removeFile = true;
        writeFile = true;
      }

    }

  } else {
    writeFile = true;
  }

  if (removeFile){
    InternalFS.remove(SENSORFN);
  }

  if (writeFile) {
    Serial.print("\n  Opening file " SENSORFN " for writing ... ");

    if( file.open(SENSORFN, FILE_O_WRITE) )
    {
      Serial.println("OK");
      file.write(SENSORCONTENTS, strlen(SENSORCONTENTS));
      file.close();
    }else
    {
      Serial.println("Failed!");
    }
  }

  Serial.println("");
}



void recvWithOutStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

// the loop function runs over and over again forever
void loop()
{
  if (newData == true) {
    inString = String(receivedChars);
    Serial.println("\n  reply: " + inString);
    WriteSensorsLitteFS();
    //WriteMainSensorLitteFS();
  }
}
```


### Resources

https://github.com/adafruit/Adafruit_nRF52_Arduino/tree/master

https://github.com/adafruit/Adafruit_nRF52_Arduino/tree/master/libraries/InternalFileSytem

[LittleFS formatting](https://github.com/adafruit/Adafruit_nRF52_Arduino/blob/master/libraries/InternalFileSytem/examples/Internal_Format/Internal_Format.ino)

[LittleFS file read & write](https://github.com/adafruit/Adafruit_nRF52_Arduino/blob/master/libraries/InternalFileSytem/examples/Internal_ReadWrite/Internal_ReadWrite.ino)

[LittleFS list files](https://github.com/adafruit/Adafruit_nRF52_Arduino/blob/master/libraries/InternalFileSytem/examples/Internal_ListFiles/Internal_ListFiles.ino)

[LittleFS stresstest](https://github.com/adafruit/Adafruit_nRF52_Arduino/tree/master/libraries/InternalFileSytem/examples/Internal_StressTest)

https://github.com/adafruit/Adafruit_nRF52_Arduino/

https://github.com/adafruit/Adafruit_nRF52_Arduino/tree/master/libraries/Adafruit_LittleFS/src/littlefs

https://github.com/adafruit/Adafruit_nRF52_Arduino/blob/master/libraries/InternalFileSytem/examples/Internal_ReadWrite/Internal_ReadWrite.ino
