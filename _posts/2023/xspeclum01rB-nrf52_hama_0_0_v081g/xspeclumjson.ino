#include <ArduinoJson.h>

// Global arrays for json file content
#define USE_SERIAL Serial
char spectralSensors[3][32];
char modbusSensors[4][32]; 
char i2cSensors[6][32]; 
char analogSensors[6][32];
char iseSensors[12][32];

char SpectralSensorMeta[3][32];
int SpectralSensorChannels[5];
float SpectralSensorVin;

/*
 * moved to hama_calib.ino
double pixel2WlCalibration[6];
*/

/* Global arrays for tuned scans
char TunedScanMeta[3][32];
int TunedScanVin;
int TunedScanMaxDN;
int TunedScanStabilisationTime;
int TunedScanNrIntegrationTimes;
int TunedScanIntegrationTimes[5];
int TunedScanStartPixels[5];
int TunedScanEndPixels[5];*/

// Global arrays for modbus sensor
char modbusProbeMeta[4][32]; 
char probeSensors[8][32];

/*
 *  param4: return (0 = mean % std, 1 = full data)
  param5; nr Repeats, default = 6
  param6; nr headtrail, default = 2
  param7; warmup, defaut = 6
  param8 = maxDN = 800:
  
  ### From here on the params are only for spectral scanning       
  param9 = muzzle = 1206VINI:
  param10 = vset_mV = 1500:
  param11 = fetchWhiteRef: 0 = none, 1 = in-sampling, 2 = campaign white ref, 3 = muzzle white ref; 4 = automatic; 5 = file; 
  param12 = fetchScanTuning: 0 = none; 1 = user defined, 2 = campaign default, 3 = muzzle default; 4 = automatic; 5 = file; 
  param13 = stabilisationTime = 200;
  param14 = nIntegrationTimes = 3:
 */

String SerialiseScanTuning(String sensor, int samplerepeats, int darkrepeats, int headtrail, int warmup, int maxDN, String muzzle, int Vin, 
    int stabilisationTime, int nIntegrationTimes, int integrationTime[], int startPixel[], int endPixel[]){
  
  DynamicJsonDocument doc(1024);
  String tStr;
  //"0":[300,100,200],"1":[600,80,225],"2":[900,64,256]}>
    
  doc["sensor"] = sensor;
  doc["samplerepeats"] = samplerepeats;
  doc["darkrepeats"] = darkrepeats;
  doc["headtrail"] = headtrail;
  doc["warmup"] = warmup;
  doc["maxDN"] = maxDN;
  doc["muzzle"] = muzzle;
  doc["Vin"] = Vin;
  doc["stabilisationTime"] = stabilisationTime;
  doc["nIntegrationTimes"] = nIntegrationTimes;

  for (int t=0; t<nIntegrationTimes; t++){
    tStr = String(t);
    doc[tStr][0] = integrationTime[t];
    doc[tStr][1] = startPixel[t];
    doc[tStr][2] = endPixel[t];
  }

  /*
  serializeJson(doc, Serial);
  Serial.println();
  */
  
  /*
  serializeJson(doc, Serial);
  jsonString = String(Serial);
  */

  String jsonString;
  
  serializeJson(doc, Serial);
  USE_SERIAL.println();
  
  serializeJson(doc, jsonString);
  
  return jsonString.c_str();
  
}




String SerialiseWhiteRefMeta(String campaign, String importversion, String theme, String family, String verson, String scandate, String product, String sampleid, String scanTuningString ){
  
  DynamicJsonDocument doc(1024);

  doc["campaign"] = campaign;
  doc["importversion"] = importversion;
  doc["theme"] = theme;
  doc["family"] = family;
  doc["version"] = verson;
  doc["scandate"] = scandate;
  doc["product"] = product;
  doc["sampleid"] = sampleid;

  String jsonString;
  
  serializeJson(doc, Serial);
  USE_SERIAL.println();
  
  serializeJson(doc, jsonString);
  
  return jsonString.c_str();
 
}

String SerialiseSpectraStats(float statsmoment[], int wls){

  // compute the required size
  const size_t CAPACITY = JSON_ARRAY_SIZE(288);
  
  // allocate the memory for the document
  StaticJsonDocument<CAPACITY> doc;
  
  // create an empty array
  JsonArray array = doc.to<JsonArray>();

  for (int s=0; s<wls; s++){
    // add some values
    array.add(statsmoment[s]);
  }

  String jsonString;
  
  // serialize the array and send the result to Serial  
  serializeJson(doc, Serial);
  USE_SERIAL.println();
  
  serializeJson(doc, jsonString);
  
  return jsonString.c_str();
}

void DeSerialiseSensorsJson(String jsonStr){

  // Convert json from String to Char array
  int str_len = jsonStr.length() + 1;
  char jsonCharArr[str_len];
  jsonStr.toCharArray(jsonCharArr, str_len);

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, jsonCharArr);
   
  for (int s=0; s< doc["spectralsensors"].size(); s++){
    //Used this in parseJSON function
    //const char* dummy = doc["spectralsensors"][s];
    strcpy( spectralSensors[s],  (const char*)doc["spectralsensors"][s] );
    if (verbos){
      Serial.print("      spectralSensors: ");
      Serial.println( spectralSensors[s] );
    }
  }

  for (int s=0; s< doc["modbussensors"].size(); s++){
    //Used this in parseJSON function
    //const char* dummy = doc["modbussensors"][s];
    strcpy( modbusSensors[s],  (const char*)doc["modbussensors"][s] );
    if (verbos){
      Serial.print("      modbusSensors: ");
      Serial.println( modbusSensors[s] );
    }
  }

  for (int s=0; s< doc["i2csensors"].size(); s++){
    //Used this in parseJSON function
    //const char* dummy = doc["i2csensors"][s];
    strcpy( i2cSensors[s],  (const char*)doc["i2csensors"][s] );
    if (verbos){
      Serial.print("      i2cSensors: ");
      Serial.println( i2cSensors[s] );
    }
  }

  for (int s=0; s< doc["analogsensors"].size(); s++){
    //Used this in parseJSON function
    //const char* dummy = doc["analogsensors"][s];
    strcpy( analogSensors[s],  (const char*)doc["analogsensors"][s] );
    if (verbos){
      Serial.print("      analogSensors: ");
      Serial.println( analogSensors[s] );
    }
  }

  for (int s=0; s< doc["isesensors"].size(); s++){
    //Used this in parseJSON function
    //const char* dummy = doc["isesensors"][s];
    strcpy( iseSensors[s],  (const char*)doc["isesensors"][s] );
    if (verbos){
      Serial.print("      iseSensors: ");
      Serial.println( iseSensors[s] );
    }
  }
}

void DeSerialiseSpectralSensorJson(String jsonStr){

  // Convert json from String to Char array
  int str_len = jsonStr.length() + 1;
  char jsonCharArr[str_len];
  jsonStr.toCharArray(jsonCharArr, str_len);

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, jsonCharArr);

  // Get the String meta data for the spectral sensor
  strcpy( SpectralSensorMeta[0],  (const char*)doc["sensor"] );
  strcpy( SpectralSensorMeta[1],  (const char*)doc["source"] );
  strcpy( SpectralSensorMeta[2],  (const char*)doc["serialnr"] );
  if (verbos){
    Serial.print("    Sensor: ");
    Serial.print( SpectralSensorMeta[0] );
    Serial.print("; Source: ");
    Serial.print( SpectralSensorMeta[1] );
    Serial.print("; SerialNr: ");
    Serial.println( SpectralSensorMeta[2] );
  }

  SpectralSensorChannels[0] = doc["pixels"];
  SpectralSensorChannels[1] = doc["bands"];
  SpectralSensorChannels[2] = doc["startpixel"];
  SpectralSensorChannels[3] = doc["endpixel"];
  SpectralSensorVin = doc["Vin"];

  if (verbos){
    Serial.print("    Sensor pixels: ");
    Serial.print( SpectralSensorChannels[0] );
    Serial.print("; bands: ");
    Serial.print( SpectralSensorChannels[1] );
    Serial.print("; startpixel: ");
    Serial.print( SpectralSensorChannels[2] );
    Serial.print("; endpixel: ");
    Serial.println( SpectralSensorChannels[3] );
  }

  pixel2WlCalibration[0] = doc["wlcalibration"][0];
  pixel2WlCalibration[1] = doc["wlcalibration"][1];
  pixel2WlCalibration[2] = doc["wlcalibration"][2];
  pixel2WlCalibration[3] = doc["wlcalibration"][3];
  pixel2WlCalibration[4] = doc["wlcalibration"][4];
  pixel2WlCalibration[5] = doc["wlcalibration"][5];
  
  if (verbos){
    Serial.print("    Sensor wavelength calibration, A0: ");
    Serial.print( pixel2WlCalibration[0],9 );
    Serial.print("; B1: ");
    Serial.print( pixel2WlCalibration[1], 9 );
    Serial.print("; B2: ");
    Serial.print( pixel2WlCalibration[2], 12 );
    Serial.print("; B3: ");
    Serial.print( pixel2WlCalibration[3], 14 );
    Serial.print("; B4: ");
    Serial.print( pixel2WlCalibration[4], 16 );
    Serial.print("; B5: ");
    Serial.println( pixel2WlCalibration[5], 18 );
  }
}

void DeSerialiseModbusSensorJson(String jsonStr){

  String sStr;

  // Convert json from String to Char array
  int str_len = jsonStr.length() + 1;
  char jsonCharArr[str_len];
  jsonStr.toCharArray(jsonCharArr, str_len);

  DynamicJsonDocument doc(1024);
  deserializeJson(doc, jsonCharArr);

  // Get the String meta data for the modbus sensor
  strcpy( modbusProbeMeta[0],  (const char*)doc["probe"] );
  strcpy( modbusProbeMeta[1],  (const char*)doc["probeid"] );
  strcpy( modbusProbeMeta[2],  (const char*)doc["source"] );
  strcpy( modbusProbeMeta[3],  (const char*)doc["model"] );
  /*
  for (int s=0; s< doc["probesensors"].size(); s++){
    sStr = String(s);
    strcpy( probeSensors[s]["quantity"],  (const char*)doc["probesensors"][sStr]["quantity"] );
    strcpy( probeSensors[s]["unit"],  (const char*)doc["probesensors"][sStr]["unit"] );
    strcpy( probeSensors[s]["sensingkey"],  (const char*)doc["probesensors"][sStr]["sensingkey"] );
    
    if (verbos){
      Serial.print("      spectralSensors:");
      Serial.println( spectralSensors[s] );
    }
    
  }
  */
  
}

void DeSerialiseI2CSensorJson(String jsonStr){
  
}

void DeSerialiseAnalogSensorJson(String jsonStr){
  
}

void DeSerialiseIseSensorJson(String jsonStr){
  
}

void DeSerialiseScanTuning(String jsonStr){
  // File content = {"sensor":"c14384ma-01","repeats":6,"headtrail":1,"warmup":2,"maxDN":800,"muzzle":"1206VINI","Vin":2400,"stabilisationTime":200,"nIntegrationTimes":3,"0":[335,103,178],"1":[670,90,202],"2":[1005,64,256]}

  // Convert json from String to Char array
  int str_len = jsonStr.length() + 1;
  char json[str_len];
  String iStr;
  jsonStr.toCharArray(json, str_len);
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, json);
  // Get the String meta data for the tuned scanning
  // spectralsensor, muzzle, lamp
  strcpy( TunedScanMeta[0],  (const char*)doc["sensor"] );
  strcpy( TunedScanMeta[1],  (const char*)doc["muzzle"] );

  TunedScanSampleRepeats = doc["samplerepeats"];
  TunedScanDarkRepeats = doc["darkrepeats"];
  TunedScanHeadTrail = doc["headtrail"];
  TunedScanWarmup = doc["warmup"];
  TunedScanMaxDN = doc["maxDN"];
  TunedScanVin = doc["Vin"];
  
  TunedScanStabilisationTime = doc["stabilisationTime"];
  TunedScanNrIntegrationTimes = doc["nIntegrationTimes"];
  for (int i=0; i < TunedScanNrIntegrationTimes; i++) {
    iStr = String(i);
    TunedScanIntegrationTimes[i] = doc[iStr][0];
    TunedScanStartPixels[i] = doc[iStr][1];
    TunedScanEndPixels[i] = doc[iStr][2];
  } 
}

void DeSerialiseScanDataJson(String jsonStr){
  
}
