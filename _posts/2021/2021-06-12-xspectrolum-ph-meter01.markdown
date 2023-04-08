---
layout: post
title: pH meter - DFRobot
categories: xspectrolum
startversion: 0.060
endversion: 0.99
excerpt: "ph meter DFRobot for 5 volt"
tags:
  - arduino
  - pH
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2021-06-12 11:27'
modified: '2021-06-12 T18:17:25.000Z'
comments: true
share: true
---

### Introduction

This is the first of three pH meters that I tested for Arduino. The pH meter in this article is the (same as the) [DFRobot, Gravity: Analog pH Sensor / Meter Kit For Arduino](https://www.dfrobot.com/product-1025.html?tracking=5cfb9465c247d). But I got my copy from [Amazon.se](https://www.amazon.se/gp/product/B081QK9TX2/ref=ppx_od_dt_b_asin_title_s00?ie=UTF8&psc=1). The control board (breakout board) is constructed for 5 volt power (Vin = 5). The [pH meter in the next post](module-ph-meter02) can be calibrated also for Vin = 3.3.

<figure>
<img src="../../images/phmeter_dfrobot_gravity.png">
<figcaption> DFRobot, Gravity: Analog pH Sensor / Meter Kit For Arduino </figcaption>
</figure>

### Online manuals

I found instructions and code for this exact model posted by [Electronic clinic on their own web page](https://www.electroniclinic.com/ph-sensor-arduino-how-do-ph-sensors-work-application-of-ph-meter-ph-sensor-calibration/) both on [Youtube](https://www.youtube.com/watch?v=dfoH5iPWkwo) and also as a [Youtube instruction](https://www.youtube.com/watch?v=dfoH5iPWkwo).

### Wiring

The wiring is very easy as the pH-meter comes with a prepared contact with only three wires, power, ground and an analog signal (see figure above).  

### Sketch

The simple sketch below is supplied by [Electronic clinic](https://www.electroniclinic.com/ph-sensor-arduino-how-do-ph-sensors-work-application-of-ph-meter-ph-sensor-calibration/):

```
#define SensorPin A2          // the pH meter Analog output is connected with the Arduino’s Analog
unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10],temp;

void setup()
{
  Serial.begin(9600);  
  Serial.println("Ready");    //Test the serial monitor
}
void loop()
{
  for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
  {
    buf[i]=analogRead(SensorPin);
    delay(10);
  }
  for(int i=0;i<9;i++)        //sort the analog from small to large
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }
  avgValue=0;
  for(int i=2;i<8;i++)                      //take the average value of 6 center sample
    avgValue+=buf[i];
  float phValue=(float)avgValue*5.0/1024/6; //convert the analog into millivolt

  Serial.print("    raw pH:");  
  Serial.print(phValue,2);
  phValue=3.5*phValue;                      //convert the millivolt into pH value

  Serial.print("    calibrated pH:");  
  Serial.print(phValue,2);
  Serial.println(" ");

}
```

[Seeed stduio](https://wiki.seeedstudio.com/Grove-PH-Sensor-kit/) offers a more advanced code for a similar ph_meter. This code also contains a calibration _Offset_ parameter, and the manual also states how to set the linear equation slope.

```
/*
  # This sample code is used to test the pH meter V1.1.
  # Editor : YouYou
  # Date   : 2014.06.23
  # Ver    : 1.1
  # Product: analog pH meter
  # SKU    : SEN0161
*/
#define SensorPin A2            //pH meter Analog output to Arduino Analog Input 0
#define Offset 41.02740741      //deviation compensate
#define LED 13
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40    //times of collection
#define uart  Serial
int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex = 0;
void setup(void)
{
  pinMode(LED, OUTPUT);
  uart.begin(9600);
  uart.println("pH meter experiment!");    //Test the uart monitor
}
void loop(void)
{
  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  static float pHValue, voltage;
  if (millis() - samplingTime > samplingInterval)
  {
    pHArray[pHArrayIndex++] = analogRead(SensorPin);
    if (pHArrayIndex == ArrayLenth)pHArrayIndex = 0;
    voltage = avergearray(pHArray, ArrayLenth) * 5.0 / 1024;
    pHValue = -19.18518519 * voltage + Offset;
    samplingTime = millis();
  }
  if (millis() - printTime > printInterval)  //Every 800 milliseconds, print a numerical, convert the state of the LED indicator
  {
    uart.print("Voltage:");
    uart.print(voltage, 2);
    uart.print("    pH value: ");
    uart.println(pHValue, 2);
    digitalWrite(LED, digitalRead(LED) ^ 1);
    printTime = millis();
  }
}
double avergearray(int* arr, int number) {
  int i;
  int max, min;
  double avg;
  long amount = 0;
  if (number <= 0) {
    uart.println("Error number for the array to avraging!/n");
    return 0;
  }
  if (number < 5) { //less than 5, calculated directly statistics
    for (i = 0; i < number; i++) {
      amount += arr[i];
    }
    avg = amount / number;
    return avg;
  } else {
    if (arr[0] < arr[1]) {
      min = arr[0]; max = arr[1];
    }
    else {
      min = arr[1]; max = arr[0];
    }
    for (i = 2; i < number; i++) {
      if (arr[i] < min) {
        amount += min;      //arr<min
        min = arr[i];
      } else {
        if (arr[i] > max) {
          amount += max;  //arr>max
          max = arr[i];
        } else {
          amount += arr[i]; //min<=arr<=max
        }
      }//if
    }//for
    avg = (double)amount / (number - 2);
  }//if
  return avg;
}
```

### Calibration

The core translation from the analog signal to initial pH is similar for all analog pH meters used with Arduino. In the first step the analog signal is translated to voltage:

```
voltage = signal * Vin / 1024
```

The DFRobot pH-meter used in this article require 5 volt as Vin, and the conversion to voltage registered by the analog port thus becomes:

```
voltage = signal * 5.0 / 1024
```
Most pH-meters also have linear responses between pH and analog voltage output (registered by the Arduino analog port), and the actual pH value is thus calculated as a linear conversion:

```
pH-value = votage*ScaleFac + Offset
```

The two sketches above use greatly different values for ScaleFac and Offset:

| Sketch | ScaleFac | Offset |
| Electronic clinic  | 3.5  | 0 |
| DFRobot | -19.18518519 | 41.02740741 |

Setting ScaleFac and Offset requires solving a linear equation and retrieving the slope (ScaleFac) and intercept (Offset) in two steps:

ScaleFac = (PH2-PH1)/(V2-V1)

Offset = [(PH2+PH1)-ScaleFac*(V1+V2)]/2

This of course requires testing the pH meter against two liquids with a priori known pH.

### Resources

[DFRobot, Gravity: Analog pH Sensor / Meter Kit For Arduino](https://www.dfrobot.com/product-1025.html?tracking=5cfb9465c247d).

[Electronic clinic text manual](https://www.electroniclinic.com/ph-sensor-arduino-how-do-ph-sensors-work-application-of-ph-meter-ph-sensor-calibration/).

[Electronic clinic youtube manual](https://www.youtube.com/watch?v=dfoH5iPWkwo).
