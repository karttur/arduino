/*
 * 
 * 
 */

#define NEOPIXEL          8


#include <Adafruit_NeoPixel.h>    //  Library that provides NeoPixel functions

// -- Create a NeoPixel object called rgbPixel that addresses 1 pixel in pin 8
Adafruit_NeoPixel rgbPixel = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);

bool initiatedNeopixel = false;

void initNeopixel() {
  if (!initiatedNeopixel) {
    if (verbos > 1) {
      Serial.println("Initiate Neopixel");
    }
    pinMode(NEOPIXEL,     OUTPUT); // RGB LED
    rgbPixel.begin();             // Start the NeoPixel object
    rgbPixel.clear();             // Set NeoPixel color to black (0,0,0)
    rgbPixel.setBrightness(20);   // Affects all subsequent settings
    rgbPixel.show();              // Update the pixel state
    initiatedNeopixel = true;
  }
}

void setLoopNeopixel (int scan) {
  scan++;
  initNeopixel();
  int red = 0; int green = 0; int blue = 0;
  
  if ( (scan % 4) == 0) {
    blue=100;
  } else if ( (scan % 3) == 0) {
    red=100;
  } else if ( (scan % 2) == 0) {
    red=100; 
    green=100;
  } else  {
    green=100;
  }
  
  rgbPixel.setPixelColor(0, red, green, blue); //  Set pixel 0 to (r,g,b) color value
  rgbPixel.show(); //  Update pixel state
}

void setRGBNeopixel (int red, int green, int blue) {
  rgbPixel.setPixelColor(0, red, green, blue); //  Set pixel 0 to (r,g,b) color value
  rgbPixel.show(); //  Update pixel state
}

void turnOffNeopixel () {
  if (initiatedNeopixel) {
    rgbPixel.setPixelColor(0, 0, 0, 0); //  Set pixel 0 to (r,g,b) color value
    rgbPixel.show(); //  Update pixel state
  }
}

void blinkNeopixel (int red, int green, int blue, int millseonds) {
  rgbPixel.setPixelColor(0, red, green, blue); //  Set pixel 0 to (r,g,b) color value
  rgbPixel.show(); //  Update pixel state
  delay(millseonds);
  turnOffNeopixel();
}
