/*
 * Program for 
 * Adafruit Feather nRF52840 with XSPECLUM01 board.
 * 
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

/* Set the wire library transmission hub */
#define DAC6571_ADDR 0x4C

#define BNC               A0 // The BNC (coaxial) port signal - mainly for Ion Selective Electrodes
#define GX16_AN           A2 // The aviator (GX) port analog sensor signal 
#define nKILL             17
#define nPBINT            18

#define GPIOSCK           26  // NC
#define nRE               25
#define GPIOMISO          24
#define GPIORX            1
#define GPIOTX            0
#define GPIOD2            2

#define GPIOSCL           23
#define GPIOSDA           22

#define USERSWITCH        7
#define BATTERYV2         A6

/* END pin definitions */

#if defined(USE_TINYUSB)
#include <Adafruit_TinyUSB.h> // for Serial
#endif

#include <Wire.h>
#include "SHT2x.h"

SHT2x sht;

void setup() {

  pinMode(BNC,      INPUT);  // BNc connection - usually an Ion Selecteve Electrode (ISE)
  
  pinMode(GX16_AN,      INPUT);  // Aalog signal from GX16 expansion socket)
  pinMode(nKILL,    OUTPUT); // #KILL
  pinMode(nPBINT,   INPUT);  // #PBINT (pushbutton)
  
  pinMode(SCK,      OUTPUT); // - (not connected)
  pinMode(nRE,      OUTPUT); // #RE (Receive enabled, RS485)
  pinMode(GPIOMISO, OUTPUT); // - (not connected)
  pinMode(GPIORX,   INPUT);  // Rx (Uart)
  pinMode(GPIOTX,   OUTPUT); // Tx (Uart)
  pinMode(GPIOD2,   OUTPUT); // - (not connected)

  pinMode(GPIOSCL,  INPUT);  // SCL
  pinMode(GPIOSDA,  INPUT);  // SDA

  pinMode(USERSWITCH,   INPUT);  // User switch

  pinMode(A6,           INPUT);  // Battery voltage/2
  pinMode(LED_BUILTIN,  OUTPUT); // Red LED

  digitalWrite(nKILL, HIGH);     // Keep the unit on. 3v3 feeds Rh/T sensor, Ph sensor and LED driver DAC
  digitalWrite(nRE, HIGH);       // Set transmit mode
  

  Serial.begin(115200);

  // Start the builtin temperature and moisture sensor
  sht.begin();

  // Blink red and blue builtin LEDs
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  delay(100);   
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);

  /* START Define the channels of the main spectrometer */
  /* Set the Hamamatsu sensor, false if none */

  // Initiate the bulitin NeoPixel
  initNeopixel();
  // White blink Neopixel for 250 milliseconds
  blinkNeopixel(100,100,100,250);
  delay(100);
  // Turn on dim blue light - waiting for input
  setRGBNeopixel(0,0,25);
   
}

// Set global variable varbos to define Serial print messages
int verbos = 0;

// Set global variables inString and  sensor - the full input and the key word received with every command

String inString = "";
String sensor = "";

void loop()
{
   delay(1);
  // Read data string, e.g. sent via monitor or usb
  recvWithStartEndMarkers();

  // Trigger command
  if (getAction()) {
    setRGBNeopixel(0,50,0);
    showCoreParams();
    verbos = getVerbos();
    sensor = getSensor();
    if ((sensor == "c12880ma") || (sensor == "c14384ma-01"))  {
      HamamatsuGratingSensor();
    } else if ((sensor == "removefiles4fs") or (sensor == "mkdirs4fs") or (sensor == "removedirs4fs") or (sensor == "listfiles4fs") or (sensor == "writedata4fs") or (sensor == "readdata4fs")){
      procsessLittleFS(sensor); 
    } 
        
    turnOffAction();
    // return Neopixel to dim blue waiting
    if (verbos) {
      Serial.println("FINISHED");
    }
    setRGBNeopixel(0,0,25);
  }
  
  /*
      // Set parameters derived from eeprom
      String muzzleId;
      String emittor1;
      String emittor2;
              
      // Search for and identify the attached muzzle via its 1-wire EEPROM memory
      bool OneWireOK = SearchOneWireAddress(OneWireAddr);

      if (verbos){
        Serial.print("  OneWireOK: ");
        Serial.println(OneWireOK);  
      }

      if (OneWireOK) {
        int m;
        // Set the arrays that hold the data from the muzzle EEPROM
        int eepromInts[9];
        String eepromStrings[4];

        Read1WDS2431Mem(eepromStrings, eepromInts, diagnos);

        eepromStrings[0].trim();
        eepromStrings[1].trim();
        eepromStrings[2].trim();

        muzzleId = eepromStrings[0];
        emittor1 = eepromStrings[1];
        emittor2 = eepromStrings[2];
        
        if ( xparam[0] != eepromStrings[0] ){
          if (verbos) {
            Serial.println("WARNING - the muzzle id (" + eepromStrings[0] + ") is different compared to the command sent: " + xparam[0]);
          }
        }

        if (xparam[2].toInt() <= 0){
          vset_mV = eepromInts[6];
        } else {
          vset_mV = xparam[2].toInt();
          if (vset_mV > eepromInts[1] & diagnos) {              
            Serial.print("WARNING - the user defined LED power, " +  xparam[2] + " is higher than the maximum allowed for the muzzle primary emittor: ");
            Serial.println(eepromInts[1]);   
          } else if (eepromInts[4] > 0 & vset_mV > eepromInts[5] & diagnos) {
            Serial.print("WARNING - the user defined LED power, " + xparam[1] + " is higher than the maximum allowed for the muzzle secondary emittor: ");
            Serial.println(eepromInts[5]);
          } else if (vset_mV < eepromInts[0]  & diagnos) {
            Serial.print("WARNING - the user defined LED power, " + xparam[1] + " is lower than the minimum threshold for the muzzle primary emittor: ");
            Serial.println(eepromStrings[0]);
          } else if (eepromInts[2] > 0 & vset_mV < eepromInts[4]  & diagnos) {
            Serial.print("WARNING - the user defined LED power, " + xparam[1] + "  is lower than the minimum threshold for the muzzle secondary emittor: ");
            Serial.println(eepromStrings[4]);
          }
        }
        
        if (vset_mV > vbat) {
            Serial.print("WARNING - the available battery voltage, " + xparam[1] + "  is lower than the required voltage: ");
            Serial.println("EXITING");
        }
        
        if (xparam[3].toInt() <= 0){
          SPECTRO_stabilisation_time = eepromInts[6];
        } 
        
      } else {
        // no onewire EEPROM

        muzzleId = "unknown";
        emittor1 = "unknown";
        emittor2 = "unknown";
        
      }

      if (autoIntegrationTime){

        int iniIntegrationTime=xparam[6].toInt();
        int ascendingIntegrationTimeStep=xparam[7].toInt();
        int descedingIntegrationTimeStep=xparam[8].toInt();
        if (verbos){
          Serial.println("\nAutomatic setting of integrationtimes");
        }
        
        SetIntegrationTimes(sensor, SPECTRO_stabilisation_time, vset_mV, n_integration_times, maxDN, iniIntegrationTime,
                            ascendingIntegrationTimeStep,descedingIntegrationTimeStep,
                            SPECTRO_integration_times, SPECTRO_start_pixels, SPECTRO_end_pixels);
      } else {

        for(int t = 0; t < n_integration_times; t++){
        int u = 6+t*3;
          SPECTRO_integration_times[t] = xparam[u].toInt();
          SPECTRO_start_pixels[t] = xparam[u+1].toInt();
          SPECTRO_end_pixels[t] = xparam[u+2].toInt();
          if (verbos){
            Serial.print("IntegrationTime");
            Serial.print(t);
            Serial.print(":");
            Serial.print( xparam[u] );
            Serial.print(" startPixel:");
            Serial.print( xparam[u+1] );
            Serial.print(" endPixel:");
            Serial.println( xparam[u+2] );
          }  
        }
      }
 
     
      // Create a json object of the metadata for the spectral emittor(s) and their settings
      metadata = "{\"muzzleid\":\"" + muzzleId + "\",\"emittor1\":\"" + emittor1 + "\",\"emittor2\":\"" + emittor2 + "\""; 
      metadata.concat(",\"vset_mV\":");
      metadata.concat( vset_mV );
      metadata.concat(",\"stabilisationtime\":");
      metadata.concat(SPECTRO_stabilisation_time);
        
      metadata.concat(",\"integrationtimes\": {");
        
      for(int t = 0; t < n_integration_times; t++){
        metadata.concat("\"IntegrationTime");
        metadata.concat(t);
        metadata.concat("\":{\"ms\":");
     
        metadata.concat( SPECTRO_integration_times[t] );
        metadata.concat(",\"startPixel\":");
        metadata.concat( SPECTRO_start_pixels[t] );
        metadata.concat(",\"endPixel\":");
        metadata.concat( SPECTRO_end_pixels[t] );
        if (t == n_integration_times-1){
          metadata.concat( "}}");
        } else {
          metadata.concat( "},");
        }
        
          
      }
      metadata.concat( "}");
       
    } else {
      // No sensor detected
      Serial.println("ERROR: no sensor detector with inString:" + inString);
      metadata = "{}";
    }
    
    Serial.println("End of spectra scan");
    
    // print metadata as single row of data

    Serial.print( "metadata=" );
    Serial.println( metadata );

    newData = false;

    inString = "-99";
        
   }
    
 delay (200);
 digitalWrite(LED_RED, LOW);
*/
}
