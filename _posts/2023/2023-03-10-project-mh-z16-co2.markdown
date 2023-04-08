---
layout: post
title: MH-Z16 CO2 sensor
categories: project
excerpt: "Module with red laser 650nm"
tags:
- Spectrometer
- gas
- CO2
- arduno
- sketch
image: avg-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
date: '2020-02-04 11:27'
modified: '2020-02-04 T18:17:25.000Z'
comments: true
share: true
component: component-laser650
module: module-laser650
project: null
---
<script src="https://karttur.github.io/common/assets/js/karttur/togglediv.js"></script>

[CO2 probe for soil respiration](../../sensor/sensor-mh-z16-c02/).



[](https://blog.devmobile.co.nz/2019/01/)

### Connection

The [Arduino code for the [NDIR MH-Z16 is available on GitHub](https://github.com/SandboxElectronics/NDIRZ16). The code is available in two versons, for UART and I2C.

### SEEED studio IoT into the wild

In 2022 [seeedstudio](https://www.seeedstudio.com) launched the product line [IoT into the wild](https://www.seeedstudio.com/iot_into_the_wild.html). As part of the product line they offer a [LoRaWAN integrated sensor for CO<sub>2</sub>, temperature and humidity](https://www.seeedstudio.com/SenseCAP-S2103-LoRaWAN-CO2-Temperature-and-Humidity-Sensor-p-5356.html?queryID=c39b94b6fdd39a01ee87b361d1ce0651&objectID=5356&indexName=bazaar_retailer_products).


<figure>
<img src="../../images/mh-z16_uno_bb.png">
<figcaption> MH-Z16 wiring to Arduino UNO, whihc SoftwareSerial connection to pins 2 and 3. </figcaption>
</figure>



```
/*
  This test code is write for Arduino AVR Series(UNO, Leonardo, Mega)
  If you want to use with LinkIt ONE, please connect the module to D0/1 and modify:

  // #include <SoftwareSerial.h>
  // SoftwareSerial s_serial(2, 3);      // TX, RX

  #define sensor Serial1
*/


#include <SoftwareSerial.h>
SoftwareSerial s_serial(2, 3);      // TX, RX

#define sensor s_serial

const unsigned char cmd_get_sensor[] =
{
    0xff, 0x01, 0x86, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x79
};

unsigned char dataRevice[9];
int CO2PPM;

void setup()
{
    sensor.begin(9600);
    Serial.begin(9600);
    Serial.println("get a 'g', begin to read from sensor!");
    Serial.println("********************************************************");
    Serial.println();
}

void loop()
{
    if(dataRecieve())
    {
        Serial.print("  CO2: ");
        Serial.print(CO2PPM);
        Serial.println("");
    }
    delay(10000);
}

bool dataRecieve(void)
{
    byte data[9];
    int i = 0;

    //transmit command data
    for(i=0; i<sizeof(cmd_get_sensor); i++)
    {
        sensor.write(cmd_get_sensor[i]);
    }
    Serial.flush();

    //begin reveiceing data
    if(sensor.available())
    {
        while(sensor.available())
        {
            for(int i=0;i<9; i++)
            {
                data[i] = sensor.read();
            }
        }
    }

    for(int j=0; j<9; j++)
    {
        Serial.print(data[j],HEX);
        Serial.print(" ");
    }
    Serial.println("");

    // First calculate then validate the check sum as there is no point in proceeding if the packet is corrupted. (code inspired by datasheet algorithm)
    byte checksum = 0 ;
    for(int j=1; j<8; j++)
    {
      checksum += data[j];
    }
    checksum=0xff-checksum;
    checksum+=1;

    if  (checksum != data[8])
    {
      Serial.println("Error checksum");
      return false;
    }

    // Then check the start byte to make sure response is what we were expecting
    if ( data[0] != 0xFF )
    {
        Serial.println("Error start byte");
        return false;
    }

    // Then check the command byte to make sure response is what we were expecting
    if ( data[1] != 0x86 )
    {
        Serial.println("Error command");
        return false;
    }


    CO2PPM = (int)data[2] * 256 + (int)data[3];

    return true;
}
```

Also take a look at a later post by devmobile

[](https://blog.devmobile.co.nz/2019/02/01/carbon-dioxide-sensormh-z16-library-comparison/)

```
#include <MHZ16_uart.h>

//Select 2 digital pins as SoftwareSerial's Rx and Tx. For example, Rx=2 Tx=3
MHZ16_uart mySensor(4,5);

void setup()
{
  Serial.begin(9600);

  mySensor.begin(4,5);
}


void loop()
{
  if ( !mySensor.isWarming())
  {
    Serial.print("CO2 Concentration is ");
    Serial.print(mySensor.getPPM());
    Serial.println("ppm");
  }
  else
{
    Serial.println("isWarming");
  }

  delay(10000);
}
```

#### Scientific studies



[A low-cost versatile system for continuous real-time respiratory activity measurement as a tool in environmental research](https://www.sciencedirect.com/science/article/abs/pii/S0263224121008654)
