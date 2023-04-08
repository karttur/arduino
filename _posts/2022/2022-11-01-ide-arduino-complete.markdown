---
layout: post
title: xSpectre spectrometer v0.78 json code
categories: ide
excerpt: "Arduino IDE arduinojson code for xSpectre's spectrometer v0.78"
tags:
  - xSpectre
  - spectrometer
  - arduino IDE
  - arduinojson
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2022-11-01 11:27'
modified: '2022-11-01 T12:17:25.000Z'
comments: true
share: true
---

## Introduction

This post contains the Arduino IDE code for deserializing json structured parameters and variables for xSpectre's spectromter v0.78.

## Arduino sketch

```
#include <ArduinoJson.h>

#if defined(USE_TINYUSB)
#include <Adafruit_TinyUSB.h> // for Serial
#endif

void setup() {
  // Initialize serial port
  Serial.begin(115200);
  while ( !Serial ) {
    digitalWrite(LED_RED, HIGH);
    delay(10);   // for nrf52840 with native usb
    digitalWrite(LED_RED, LOW);
    delay(10);
  }

  // Allocate the JSON document
  // https://arduinojson.org/v6/assistant/#/step1
  // Inside the brackets, 200 is the capacity of the memory pool in bytes.
  // Don't forget to change this value to match your JSON document.
  // Use arduinojson.org/v6/assistant to compute the capacity.

  StaticJsonDocument<4096> doc;

  // StaticJsonDocument<N> allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  // DynamicJsonDocument doc(200);

  // JSON input string.
  //
  // Using a char[], as shown here, enables the "zero-copy" mode. This mode uses
  // the minimal amount of memory because the JsonDocument stores pointers to
  // the input buffer.
  // If you use another type of input, ArduinoJson must copy the strings from
  // the input to the JsonDocument, so you need to increase the capacity of the
  // JsonDocument.

  char params[] =
      "{\"spectrometer\":{\"brand\":\"Hamamatsu\",\"model\":\"c1438ma\",\"id\":\"xyz\",\"SPEC_CHANNELS\":255,\"START_CHANNEL\":64,\"END_CHANNEL\":255,\"Wavelengths\":{\"64\":640,\"255\":1050}},\"spectralsensing\":{\"SPEC_INTEGRATION_TIME\":300,\"SPEC_READINGS\":6,\"DARK_READINGS\":6},\"BNCsensing\":{\"PH\":false,\"CA\":false,\"NO3\":false,\"NH4\":false,\"CL\":false,\"S\":false},\"BNCparams\":{\"PH\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"CA\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"NO3\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"NH4\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"CL\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"S\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7}},\"GXsensing\":{\"ANALOG\":{\"CAPACITIVE_SOILMOISTURE\":false},\"MODBUS\":{\"SEEED_SOILMOISTURE\":false},\"I2C\":{\"AMS_6CHANNEL_NIR\":true,\"AMS_6CHANNEL_VIS\":false,\"AMS_6CHANNEL_XTR\":false}},\"GXparams\":{\"ANALOG\":{\"CAPACITIVE_SOILMOISTURE\":{\"DRY\":2500,\"WET\":1060}},\"MODBUS\":{\"SEEED_SOILMOISTURE\":{\"X\":\"X\",\"Y\":\"Y\"}},\"I2C\":{\"AMS_6CHANNEL_NIR\":{\"brand\":\"AMS\",\"model\":\"AS7263\",\"id\":\"NA\",\"SPEC_CHANNELS\":6,\"START_CHANNEL\":1,\"END_CHANNEL\":6,\"Wavelengths:\":[{\"1\":610,\"2\":680,\"3\":730,\"4\":760,\"5\":810,\"6\":860}],\"spectralsensing\":{\"SPEC_INTEGRATION_TIME\":300,\"SPEC_READINGS\":6,\"DARK_READINGS\":6}},\"AMS_6CHANNEL_VIS\":{\"brand\":\"AMS\",\"model\":\"AS7262\",\"id\":\"NA\",\"SPEC_CHANNELS\":6,\"START_CHANNEL\":1,\"END_CHANNEL\":6,\"Wavelengths:\":[{\"1\":450,\"2\":500,\"3\":550,\"4\":570,\"5\":600,\"6\":650}],\"spectralsensing\":{\"SPEC_INTEGRATION_TIME\":300,\"SPEC_READINGS\":6,\"DARK_READINGS\":6},\"AMS_6CHANNEL_XTR\":{\"brand\":\"AMS\",\"model\":\"AS7261\",\"id\":\"NA\",\"SPEC_CHANNELS\":6,\"START_CHANNEL\":1,\"END_CHANNEL\":6,\"Wavelengths:\":[{\"1\":610,\"2\":680,\"3\":730,\"4\":760,\"5\":810,\"6\":860}],\"spectralsensing\":{\"SPEC_INTEGRATION_TIME\":300,\"SPEC_READINGS\":6,\"DARK_READINGS\":6}}}}}}";

      //"{\"spectrometer\":{\"brand\":\"Hamamatsu\",\"model\":\"c1438ma\",\"id\":\"xyz\",\"SPEC_CHANNELS\":255,\"START_CHANNEL\":64,\"END_CHANNEL\":255,\"Wavelengths\":{\"64\":640,\"255\":1050}},\"spectralsensing\":{\"SPEC_INTEGRATION_TIME\":300,\"SPEC_READINGS\":6,\"DARK_READINGS\":6},\"BNCsensing\":{\"PH\":false,\"CA\":false,\"NO3\":false,\"NH4\":false,\"CL\":false,\"S\":false},\"BNCparams\":{\"PH\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"CA\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"NO3\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"NH4\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"CL\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"S\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7}},\"GXsensing\":{\"ANALOG\":{\"CAPACITIVE_SOILMOISTURE\":false},\"MODBUS\":{\"SEEED_SOILMOISTURE\":false},\"I2C\":{\"AMS_6CHANNEL_NIR\":true,\"AMS_6CHANNEL_VIS\":false,\"AMS_6CHANNEL_XYZ+NIR\":false}},\"GXparams\":{\"ANALOG\":{\"CAPACITIVE_SOILMOISTURE\":{\"DRY\":2500,\"WET\":1060}},\"MODBUS\":{\"SEEED_SOILMOISTURE\":{\"X\":\"X\",\"Y\":\"Y\"}},\"I2C\":{\"AMS_6CHANNEL_NIR\":{\"brand\":\"AMS\",\"model\":\"AS7263\",\"id\":\"NA\",\"SPEC_CHANNELS\":6,\"START_CHANNEL\":1,\"END_CHANNEL\":6,\"Wavelengths:\":[{\"1\":610,\"2\":680,\"3\":730,\"4\":760,\"5\":810,\"6\":860}],\"spectralsensing\":{\"SPEC_INTEGRATION_TIME\":300,\"SPEC_READINGS\":6,\"DARK_READINGS\":6}},\"AMS_6CHANNEL_VIS\":{\"brand\":\"AMS\",\"model\":\"AS7262\",\"id\":\"NA\",\"SPEC_CHANNELS\":6,\"START_CHANNEL\":1,\"END_CHANNEL\":6,\"Wavelengths:\":[{\"1\":450,\"2\":500,\"3\":550,\"4\":570,\"5\":600,\"6\":650}],\"spectralsensing\":{\"SPEC_INTEGRATION_TIME\":300,\"SPEC_READINGS\":6,\"DARK_READINGS\":6},\"AMS_6CHANNEL_XYZ+NIR\":{\"brand\":\"AMS\",\"model\":\"AS7261\",\"id\":\"NA\",\"SPEC_CHANNELS\":6,\"START_CHANNEL\":1,\"END_CHANNEL\":6,\"Wavelengths:\":[{\"1\":610,\"2\":680,\"3\":730,\"4\":760,\"5\":810,\"6\":860}],\"spectralsensing\":{\"SPEC_INTEGRATION_TIME\":300,\"SPEC_READINGS\":6,\"DARK_READINGS\":6}}}}}}";

      //"{\"spectrometer\":{\"brand\":\"Hamamatsu\",\"model\":\"c1438ma\",\"id\":\"xyz\",\"SPEC_CHANNELS\":255,\"START_CHANNEL\":64,\"END_CHANNEL\":255,\"Wavelengths\":{\"64\":640,\"255\":1050}},\"spectralsensing\":{\"SPEC_INTEGRATION_TIME\":300,\"SPEC_READINGS\":6,\"DARK_READINGS\":6},\"BNCsensing\":{\"PH\":true,\"CA\":false,\"N03\":false,\"NH4\":true,\"CL\":false,\"S\":false},\"BNCparams\":{\"PH\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"CA\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"NO3\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"NH4\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"CL\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7},\"S\":{\"OFFSET_mV\":1650,\"GAIN\":3,\"mV_PER_UNIT\":-59.194,\"OFFSET_UNIT\":7}},\"GXsensing\":{\"ANALOG\":{\"CAPACITIVE_SOILMOISTURE\":false},\"MODBUS\":{\"SEEED_SOILMOISTURE\":false},\"I2C\":{\"AMS_6CHANNEL_NIR\":false,\"AMS_6CHANNEL_VIS\":true}},\"GXparams\":{\"ANALOG\":{\"CAPACITIVE_SOILMOISTURE\":{\"DRY\":2500,\"WET\":1060}},\"MODBUS\":{\"SEEED_SOILMOISTURE\":{\"X\":\"X\",\"Y\":\"Y\"}},\"I2C\":{\"AMS_6CHANNEL_NIR\":{\"brand\":\"AMS\",\"model\":\"6CHANNEL_NIR\",\"id\":\"NA\",\"SPEC_CHANNELS\":6,\"START_CHANNEL\":1,\"END_CHANNEL\":6,\"Wavelengths:\":[{\"FIRST_CHANNEL\":1,\"LAST_CHANNEL\":6,\"FIRST_WAVELENGTH\":640,\"LAST_WAVELENGTH\":1050}]},\"AMS_6CHANNEL_VIS\":{\"brand\":\"AMS\",\"model\":\"6CHANNEL_VIS\",\"id\":\"NA\",\"SPEC_CHANNELS\":6,\"START_CHANNEL\":1,\"END_CHANNEL\":6,\"Wavelengths:\":[{\"FIRST_CHANNEL\":1,\"LAST_CHANNEL\":6,\"FIRST_WAVELENGHT\":350,\"LAST_WAVELENGTH\":650}]}}}}";


  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, params);

  // Test if parsing succeeds.
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  // Fetch values.
  //
  // Most of the time, you can rely on the implicit casts.
  // In other case, you can do doc["time"].as<long>();
  const char* spectrometer_brand = doc["spectrometer"]["brand"];
  //long time = doc["time"];
  int SPEC_CHANNELS = doc["spectrometer"]["SPEC_CHANNELS"];
  int START_CHANNEL = doc["spectrometer"]["START_CHANNEL"];
  int END_CHANNEL = doc["spectrometer"]["END_CHANNEL"];

  // Print values.
  Serial.print("spectrometer_brand: ");
  Serial.println(spectrometer_brand);
  Serial.print("SPEC_CHANNELS: ");
  Serial.println(SPEC_CHANNELS);
  Serial.print("START_CHANNEL: ");
  Serial.println(START_CHANNEL);
  Serial.print("END_CHANNEL: ");
  Serial.println(END_CHANNEL);

  int wls = sizeof(doc["spectrometer"]["Wavelengths"]) / sizeof(double);

  Serial.print("wlarraysize: ");

  Serial.println( wls );

  if (wls == 2) {
    // If only 2 values, they must represent min and max
    String key = String(START_CHANNEL);
    int START_WL = doc["spectrometer"]["Wavelengths"][key];
    key = String(END_CHANNEL);
    int END_WL = doc["spectrometer"]["Wavelengths"][key];    
  }
  else if (wls == START_CHANNEL-END_CHANNEL) { // 60 <= temperature < 70
    // Warning! User attention required.
  }
  else { // temperature < 60
    // Safe! Continue usual tasks.
  }

  int SPEC_INTEGRATION_TIME = doc["spectralsensing"]["SPEC_INTEGRATION_TIME"];
  int SPEC_READINGS = doc["spectralsensing"]["SPEC_READINGS"];
  int DARK_READINGS = doc["spectralsensing"]["DARK_READINGS"];
  Serial.print("SPEC_INTEGRATION_TIME: ");
  Serial.println(SPEC_INTEGRATION_TIME);
  Serial.print("SPEC_READINGS: ");
  Serial.println(SPEC_READINGS);
  Serial.print("DARK_READINGS: ");
  Serial.println(DARK_READINGS);
  /*
  const char* FIRST_CHANNEL = doc["spectrometer"]["Wavelengths"][0]["FIRST_CHANNEL"];

  Serial.print("FIRST_CHANNEL: ");

  Serial.println( FIRST_CHANNEL );

  // Create the arrays for channel vs wavelenghts
  int FIRST_CHANNELS[wls];
  int LAST_CHANNELS[wls];
  int FIRST_WAVELENGTHS[wls];
  int LAST_WAVELENGTHS[wls];

  for (byte i = 0; i < wls; i++) {

    int FIRST_CHANNEL = doc["spectrometer"]["Wavelengths"][i]["FIRST_CHANNEL"];
    int LAST_CHANNEL = doc["spectrometer"]["Wavelengths"][i]["LAST_CHANNEL"];
    int FIRST_WAVELENGTH = doc["spectrometer"]["Wavelengths"][i]["FIRST_WAVELENGHT"];
    int LAST_WAVELENGTH = doc["spectrometer"]["Wavelengths"][i]["LAST_WAVELENGHT"];

    Serial.print ("FIRST_CHANNEL In LOOP ");
    Serial.print (i);
    Serial.print (": ");
    Serial.println (FIRST_CHANNEL);

    FIRST_CHANNELS[i] = FIRST_CHANNEL;
    LAST_CHANNELS[i] = FIRST_CHANNEL;
    FIRST_WAVELENGTHS[i] = FIRST_WAVELENGTH;
    LAST_WAVELENGTHS[i] = LAST_WAVELENGTH;
  }
  Serial.print("FIRST_CHANNEL: ");
  Serial.println(FIRST_CHANNELS[0]);

  Serial.print("LAST_CHANNEL: ");
  Serial.println(LAST_CHANNELS[0]);
  */

  const char *pointer[] = { "PH", "CA",  "NO3", "NH4", "CL", "S"};
  bool BNCL[6];

  int nBNC = 0;
  for (byte i = 0; i < 6; i++) {
    BNCL[i] = doc["BNCsensing"][pointer[i]];
    Serial.print(i);
    Serial.print(": ");
    Serial.println(BNCL[i] );
    if (BNCL[i]) {
      nBNC += 1;
    }
  }

  Serial.print("nBNC: ");
  Serial.println( nBNC );

  String BNC[nBNC];
  //String fString[8];

  int n = 0;
  for (byte i = 0; i < 6; i++) {
    if (BNCL[i] == 1) {
      Serial.print("SNULLERULLE: ");
      Serial.println( pointer[i] );
      BNC[n] += pointer[i];
      n += 1;
    }
  }

  Serial.print("n: ");
  Serial.println(n);
  Serial.print("ISE: ");
  Serial.println( BNC[0] );
  Serial.print("ISE: ");
  Serial.println( BNC[1] );

  Serial.print("nBNC: ");
  Serial.println( nBNC );
  for (byte i = 0; i < nBNC; i++) {
    String ISE = BNC[i];
    Serial.print("looping again : ");
    Serial.print(i);
    Serial.print("; ");
    Serial.println(ISE);
    if (ISE == "PH"){
      int PH_OFFSET_mV = doc["BNCparams"]["PH"]["OFFSET_mV"];
      int PH_GAIN = doc["BNCparams"]["PH"]["GAIN"];
      float PH_mV_PER_UNIT = doc["BNCparams"]["PH"]["mV_PER_UNIT"];
      int PH_OFFSET_UNIT = doc["BNCparams"]["PH"]["OFFSET_UNIT"];
      Serial.print("PH_OFFSET_mV : ");
      Serial.println(PH_OFFSET_mV);
      Serial.print("PH_GAIN : ");
      Serial.println(PH_GAIN);
      Serial.print("PH_mV_PER_UNIT : ");
      Serial.println(PH_mV_PER_UNIT);
      Serial.print("PH_OFFSET_UNIT : ");
      Serial.println(PH_OFFSET_UNIT);
    }
    else if (ISE == "CA"){
      int CA_OFFSET_mV = doc["BNCparams"]["CA"]["OFFSET_mV"];
      int CA_GAIN = doc["BNCparams"]["PH"]["GAIN"];
      float CA_mV_PER_UNIT = doc["BNCparams"]["CA"]["mV_PER_UNIT"];
      int CA_OFFSET_UNIT = doc["BNCparams"]["CA"]["OFFSET_UNIT"];
    }
    else if (ISE == "CA"){
      int CA_OFFSET_mV = doc["BNCparams"]["CA"]["OFFSET_mV"];
      int CA_GAIN = doc["BNCparams"]["PH"]["GAIN"];
      float CA_mV_PER_UNIT = doc["BNCparams"]["CA"]["mV_PER_UNIT"];
      int CA_OFFSET_UNIT = doc["BNCparams"]["CA"]["OFFSET_UNIT"];
    }
    else if (ISE == "NO3"){
      int NO3_OFFSET_mV = doc["BNCparams"]["NO3"]["OFFSET_mV"];
      int NO3_GAIN = doc["BNCparams"]["NO3"]["GAIN"];
      float NO3_mV_PER_UNIT = doc["BNCparams"]["NO3"]["mV_PER_UNIT"];
      int NO3_OFFSET_UNIT = doc["BNCparams"]["NO3"]["OFFSET_UNIT"];
    }
    else if (ISE == "NH4"){
      int NH4_OFFSET_mV = doc["BNCparams"]["NH4"]["OFFSET_mV"];
      int NH4_GAIN = doc["BNCparams"]["NH4"]["GAIN"];
      float NH4_mV_PER_UNIT = doc["BNCparams"]["NH4"]["mV_PER_UNIT"];
      int NH4_OFFSET_UNIT = doc["BNCparams"]["NH4"]["OFFSET_UNIT"];
      Serial.print("NH4_OFFSET_mV : ");
      Serial.println(NH4_OFFSET_mV);
      Serial.print("NH4_GAIN : ");
      Serial.println(NH4_GAIN);
      Serial.print("NH4_mV_PER_UNIT : ");
      Serial.println(NH4_mV_PER_UNIT);
      Serial.print("NH4_OFFSET_UNIT : ");
      Serial.println(NH4_OFFSET_UNIT);
    }
    else if (ISE == "CL"){
      int CL_OFFSET_mV = doc["BNCparams"]["CL"]["OFFSET_mV"];
      int CL_GAIN = doc["BNCparams"]["CL"]["GAIN"];
      float CL_mV_PER_UNIT = doc["BNCparams"]["CL"]["mV_PER_UNIT"];
      int CL_OFFSET_UNIT = doc["BNCparams"]["CL"]["OFFSET_UNIT"];
    }
    else if (ISE == "S"){
      int S_OFFSET_mV = doc["BNCparams"]["S"]["OFFSET_mV"];
      int S_GAIN = doc["BNCparams"]["S"]["GAIN"];
      float S_mV_PER_UNIT = doc["BNCparams"]["S"]["mV_PER_UNIT"];
      int S_OFFSET_UNIT = doc["BNCparams"]["S"]["OFFSET_UNIT"];
    }
    else{
      int tg = 1;
    }
  }

  /*
   * SETUP GX16 attached sensors

  const char *gxpointer[] = { "ANALOG", "MODBUS",  "I2C"};
  const char *gxanalogpointer[] = { "CAPACITIVE_SOILMOISTURE"};
  const char *gxmodbuspointer[] = { "SEEED_SOILMOISTURE"};
  const char *gxi2cpointer[] = { "AMS_6CHANNEL_VIS", "AMS_6CHANNEL_NIR", "AMS_6CHANNEL_XTR"};
  bool GXANALOG[1];
  bool GXMODBUS[1];
  bool GXI2C[2];

  int nGA = 0;
  int nGM = 0;
  int nGI = 0;

  for (byte gx = 0; gx < 3; gx++) {
    String gxp = gxpointer[gx];
    Serial.print("gxp: ");
    Serial.println( gxp );

    if (gxp == "ANALOG") {
      Serial.println( "LOOPING ANALOG" );

      for (byte ga = 0; ga < 1; ga++) {
        String gxa = gxanalogpointer[ga];
        Serial.print("gxa: ");
        Serial.println( gxa );
        GXANALOG[ga] = doc["GXsensing"]["ANALOG"][gxa];
        Serial.print("GXANALOG: ");
        Serial.println( GXANALOG[ga] );
        if (GXANALOG[ga] == 1){
          nGA += 1;
        }

      }
    } else if (gxp == "MODBUS") {
      Serial.println( "LOOPING MODBUS" );

      for (byte gm = 0; gm < 1; gm++) {
        String gxm = gxmodbuspointer[gm];
        Serial.print("gxm: ");
        Serial.println( gm );
        GXMODBUS[gm] = doc["GXsensing"]["MODBUS"][gxm];
        Serial.print("GXMODBUS: ");
        Serial.println( GXMODBUS[gm] );
        if (GXMODBUS[gm] == 1){
          nGM += 1;
        }
      }
    } else if (gxp == "I2C") {
      Serial.println( "LOOPING I2C" );
      for (byte gi = 0; gi < 2; gi++) {
        String gxi = gxi2cpointer[gi];
        Serial.print("gxi: ");
        Serial.println( gi );
        GXI2C[gi] = doc["GXsensing"]["I2C"][gxi];
        Serial.print("GXI2C: ");
        Serial.println( GXI2C[gi] );
        if (GXI2C[gi] == 1){
          // Sensor to use identified
          nGI += 1;
        }
      }
    } else {
      // pass
    }

    */
    /*
    int nGX = nGA+nGM+nGI;

    // Create
    if (nGX >= 1){
      Serial.println("nGX >= 1");
      if (nGA >= 1){
        Serial.println("nGA >= 1");
      }
      if (nGM >= 1){
        Serial.println("nGM >= 1");
      }
      if (nGI >= 1){
        Serial.println("nGI >= 1");

        for (byte gi = 0; gi < 2; gi++) {

          Serial.print("gi in params loop: ");
          Serial.println(gi);
          Serial.println(GXI2C[gi]);
          Serial.print ("looking for params for: ");
          Serial.println (gxi2cpointer[gi]);


          if (GXI2C[gi] == 1){
              Serial.print ("setting params for: ");
              Serial.println (gxi2cpointer[gi]);
              //String = GXI_sensor = gxi2cpointer[gi];
              if (gxi2cpointer[gi] == "AMS_6CHANNEL_VIS"){
                  const char* ams_spectrometer_brand = doc["GXparams"]["I2C"]["AMS_6CHANNEL_VIS"]["brand"];
                  const char* ams_spectrometer_model = doc["GXparams"]["I2C"]["AMS_6CHANNEL_VIS"]["model"];
                  const char* ams_spectrometer_id = doc["GXparams"]["I2C"]["AMS_6CHANNEL_VIS"]["id"];
                  int AMS_SPEC_CHANNELS = doc["GXparams"]["I2C"]["AMS_6CHANNEL_VIS"]["SPEC_CHANNELS"];
                  int AMS_START_CHANNEL = doc["GXparams"]["I2C"]["AMS_6CHANNEL_VIS"]["START_CHANNEL"];
                  int AMS_END_CHANNEL = doc["GXparams"]["I2C"]["AMS_6CHANNEL_VIS"]["END_CHANNEL"];

                  int amswls = sizeof(doc["GXparams"]["I2C"]["AMS_6CHANNEL_VIS"]["Wavelengths"]) / sizeof(double);

                  Serial.print("VIS amswlarraysize: ");

                  Serial.println( amswls );

              } else if (gxi2cpointer[gi] == "AMS_6CHANNEL_NIR"){
                  const char* ams_spectrometer_brand = doc["GXparams"]["I2C"]["AMS_6CHANNEL_NIR"]["brand"];
                  const char* ams_spectrometer_model = doc["GXparams"]["I2C"]["AMS_6CHANNEL_NIR"]["model"];
                  const char* ams_spectrometer_id = doc["GXparams"]["I2C"]["AMS_6CHANNEL_NIR"]["id"];
                  int AMS_SPEC_CHANNELS = doc["GXparams"]["I2C"]["AMS_6CHANNEL_NIR"]["SPEC_CHANNELS"];
                  int AMS_START_CHANNEL = doc["GXparams"]["I2C"]["AMS_6CHANNEL_NIR"]["START_CHANNEL"];
                  int AMS_END_CHANNEL = doc["GXparams"]["I2C"]["AMS_6CHANNEL_NIR"]["END_CHANNEL"];

                  int amswls = sizeof(doc["GXparams"]["I2C"]["AMS_6CHANNEL_NIR"]["Wavelengths"]) / sizeof(double);

                  Serial.print("NIR amswlarraysize: ");

                  Serial.println( amswls );   

              }
          }

        }

      }
    }

  }
  */
  Serial.println("setup finished");
}

void loop() {
  // not used in this example
}
```
