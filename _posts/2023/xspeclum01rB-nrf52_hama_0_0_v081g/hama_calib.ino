/* hama_calib
 * 
 * 
 */

double pixel2WlCalibration[6];

boolean HamamatsuWavelenghtCalibrated = false;
 
void hamamatsuWavelenghts(int START_CHANNEL, int END_CHANNEL, float wlnm[]) {
  if (!HamamatsuWavelenghtCalibrated) {
    String hamaCalibFPN;
    String sensorFileContent;
    // Set the file name for the spectralsensor

    if (sensor == "c14384ma-01") {
      hamaCalibFPN = "/spectralsensors/c14384ma-01.json";
    } else if (sensor == "c12880ma") {
      hamaCalibFPN = "/spectralsensors/c12880ma.json";
    }

    if (verbos > 1) {
      Serial.println("  Sensor: " + sensor);
      Serial.println("  Looking for " + hamaCalibFPN);
    }
    // Read the sensor calibration file
    sensorFileContent = ReadFile(hamaCalibFPN);
  
    DeSerialiseSpectralSensorJson(sensorFileContent);

    // convert pixel to calibrated wavelength
    pixel2wl(pixel2WlCalibration, START_CHANNEL, END_CHANNEL, wlnm);

    HamamatsuWavelenghtCalibrated = true;
  }    
}
  

// Convert pixel nr to band using the calibration data

void pixel2wl(double AB[], int start_ch, int end_ch, float wlnm[]){

  int bands = end_ch-start_ch;
  
  //float wlnm[end_ch];

  if (verbos > 1) {
    Serial.print("  Pixel to wavelength calibration:");
  }
  
  for(int b = start_ch; b < end_ch; b++){  

      wlnm[b] = (AB[0] + AB[1]*b + AB[2]*pow(b,2) + AB[3]*pow(b,3) + AB[4]*pow(b,4) + AB[5]*pow(b,5) );
      if (verbos > 1) {
        Serial.print("    pixel: ");
        Serial.print(b);
        Serial.print(" band: ");
        Serial.print(b-1);
        Serial.print(" wl: ");
        Serial.println(wlnm[b]);
      }    
  }
 
  if (verbos) {
    Serial.print("    wls:");
    for(int b = start_ch-1; b < end_ch-1; b++){ 
      Serial.print(wlnm[b]);
      if (b < end_ch-1){
        Serial.print(',');
      }    
    }
    Serial.print("\n");
  }
}


void hamamatsuCalibration(){

  
  
}
