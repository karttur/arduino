/*
 * 
 * 
 * 
 * 
 */

#define SPECTRO_AN        A1 // The analog video signal for the spectrometer 
#define SPECTRO_CLK       13 // Spectrometer clock
#define SPECTRO_ST        12 // Spectrometer start
#define SPECTRO_TRG       11 // Spectroemter trigger
#define SPECTRO_EOS       10
#define SPECTRO_BOOST_EN  9 // Spectrometer booster engage - on/off needs to be turned off after scanning to allow sensor to recover

#define LED_BUCK_EN       6 // muzzle LED light buck engage - some light drains power and must be turned off when not in use
#define LED_PULSE         5 // LED light Pulse on/off

// MAXIMUM_CHANNELS is the overall (among all spectral possible sensors) highest number of channels
#define MAXIMUM_CHANNELS          288

// SPECTRO_CHANNELS, START_CHANNEL and END_CHANNEL define the channels for the actual sensor in use
int SPECTRO_CHANNELS; // Nr of spectral channels in sensor
int START_CHANNEL; // First channel with valid data
int END_CHANNEL; // Last channel with valid data

// the first integration argument when looping for manual seetings
const int firstIntegrationArgument = 16;

uint8_t samplerepeats;
uint8_t darkrepeats;
uint8_t warmup;
uint8_t headtrail;
uint8_t returnformat;

uint16_t spectra[MAXIMUM_CHANNELS];
uint16_t spectraSignal[MAXIMUM_CHANNELS];
uint16_t spectraDark[MAXIMUM_CHANNELS];
uint16_t spectraSection[MAXIMUM_CHANNELS];
float spectraSignalMean[MAXIMUM_CHANNELS];
float spectraSignalStd[MAXIMUM_CHANNELS];
float spectraDarkMean[MAXIMUM_CHANNELS];
float spectraDarkStd[MAXIMUM_CHANNELS];
float waveLenghtsNanometer[MAXIMUM_CHANNELS];

// 2D arrays for signal and dark
uint16_t spectraSignal2D[8][MAXIMUM_CHANNELS];
uint16_t spectraDark2D[8][MAXIMUM_CHANNELS];

boolean HamamatsuConnected = false;

void connectHamamatsu() {
  if (!HamamatsuConnected) {
    pinMode(SPECTRO_AN,   INPUT);  // Spectro video analog signal
    pinMode(SPECTRO_CLK,   OUTPUT); // Spectrometer clock pulse
    pinMode(SPECTRO_ST,    OUTPUT); // Spectrometer start pulse
    pinMode(SPECTRO_TRG,   INPUT);  // Spectrometer trigger pulse
    pinMode(SPECTRO_EOS,   INPUT);  // SPECTRO_EOS
    pinMode(SPECTRO_BOOST_EN, OUTPUT); // Spectrometer end of scan

    pinMode(LED_BUCK_EN,  OUTPUT); // LED_BUCK_EN
    pinMode(LED_PULSE,    OUTPUT); // LED_PULSE
  
    digitalWrite(SPECTRO_CLK, LOW);
    digitalWrite(SPECTRO_ST, LOW);
    digitalWrite(SPECTRO_BOOST_EN, LOW);

    digitalWrite(LED_BUCK_EN, LOW);

    // Turn off LED_PULSE before starting
    digitalWrite(LED_PULSE, LOW);
    
    if (verbos) {
      Serial.println("\n  Connected to spectral sensor");
    }

    HamamatsuConnected = true;
  }
}

String campaign;
String muzzle;
int maxDN;
int vset_mV;
int operation;
int fetchWhiteRef;
int fetchScanTuning;
uint8_t nIntegrationTimes;
int stabilisationTime;
int SPECTRO_integration_times[5];
int SPECTRO_start_pixels[5];
int SPECTRO_end_pixels[5];

// Global params from json files

// Global arrays for tuned scans
char TunedScanMeta[3][32];
uint8_t TunedScanSampleRepeats;
uint8_t TunedScanDarkRepeats;
uint8_t TunedScanHeadTrail;
uint8_t TunedScanWarmup;
int TunedScanVin;
int TunedScanMaxDN;
int TunedScanStabilisationTime;
uint8_t TunedScanNrIntegrationTimes;
int TunedScanIntegrationTimes[5];
int TunedScanStartPixels[5];
int TunedScanEndPixels[5];
  

// Duplicate params from filesystem (_fs)
String sensor_fs;
String muzzle_fs;
String lamp_fs;

int adcvalue = 0;
float vbat;
// Set conversion between 10-bit ADC and input range
float mv_per_lsb = 3600.0F/1024.0F; // 10-bit ADC with 3.6V input range

String metadata;

/* START main spectra scan */

void readSpectrometer(){

  int delayTime = 25; // delay time in microseconds

  // Start clock cycle and set start pulse to signal start
  digitalWrite(SPECTRO_CLK, LOW);
  delayMicroseconds(delayTime);
  digitalWrite(SPECTRO_CLK, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(SPECTRO_CLK, LOW);
  digitalWrite(SPECTRO_ST, HIGH);
  delayMicroseconds(delayTime);

  //Sample for a period of time
  for(int i = 0; i < 15; i++){
      digitalWrite(SPECTRO_CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(SPECTRO_CLK, LOW);
      delayMicroseconds(delayTime); 
  }

  //Set SPECTRO_ST to low
  digitalWrite(SPECTRO_ST, LOW);

  //Sample for a period of time
  for(int i = 0; i < 85; i++){
      digitalWrite(SPECTRO_CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(SPECTRO_CLK, LOW);
      delayMicroseconds(delayTime);    
  }

  //One more clock pulse before the actual read
  digitalWrite(SPECTRO_CLK, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(SPECTRO_CLK, LOW);
  delayMicroseconds(delayTime);

  //Read from SPECTRO_VIDEO
  for(int i = 0; i < SPECTRO_CHANNELS; i++){
      spectra[i] = analogRead(SPECTRO_AN);
      digitalWrite(SPECTRO_CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(SPECTRO_CLK, LOW);
      delayMicroseconds(delayTime);     
  }

  //Set SPECTRO_ST to high
  digitalWrite(SPECTRO_ST, HIGH);

  //Sample for a small amount of time
  for(int i = 0; i < 7; i++){
    
      digitalWrite(SPECTRO_CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(SPECTRO_CLK, LOW);
      delayMicroseconds(delayTime);
    
  }

  digitalWrite(SPECTRO_CLK, HIGH);
  delayMicroseconds(delayTime); 
}
/* END readSpectrometer() */

// print results from main spectral sensor

void value_print_spectra_dark_mean_std(String sensor, int start_ch, int end_ch){
  int i;
  int n = 0;
  while (n < 2) { 
    int m = 0;
    while (m < 2) { 
      if (verbos){
        Serial.print("    data=");
      } else {
        Serial.print("data=");
      }
      Serial.print(sensor);
      if (m == 0) {
        Serial.print(",mean");
      } else {
        Serial.print(",std");
      }
      Serial.print(',');
      Serial.print(n);
      Serial.print(',');
      for ( i = start_ch ; i < end_ch ; i++ )
      {
        if (n == 0) {
          if (m == 0) {
            Serial.print(spectraDarkMean[i]);
          } else {
            Serial.print(spectraDarkStd[i]);
          }
               
        } else {
          if (m == 0){
            Serial.print(spectraSignalMean[i]);
          } else {
            Serial.print(spectraSignalStd[i]);
          }
          
        }
        
        if (i < end_ch-1){
          Serial.print(',');
        }    
      }
      Serial.print("\n");
      m += 1;
    }
    n += 1;
  }
}

void calc_spectra_dark_mean_std(String sensor, int headTrailScans, int coreScans, int start_ch, int end_ch){
  int i;
  //int n = 0;
  uint16_t scannr = 0;
 
  float sum;
  float meanSignal;
  float varianceSignal;
  float sqDiff;
  float stdSignal;
  //uint16_t transposeArray[MAXIMUM_CHANNELS][12]; 
  uint16_t reps = headTrailScans*2+coreScans;
  //uint16_t repeatArray[12];
  //uint16_t coreArray[6];
  uint16_t repeatArray[reps];
  uint16_t coreArray[coreScans];
  
  if (verbos > 1) {
     Serial.println("    Calculating pixel mean and std: ");
     Serial.print("      start_ch: ");
     Serial.print(start_ch);
     Serial.print(" end_ch: ");
     Serial.println(end_ch);
  }

  int n = 0;
  while (n < 2) { 
    for(int j=start_ch;j<end_ch;j++) {
      sum = 0;
      
      if (n == 0) {
        for(int i=0;i<reps;i++){
          repeatArray[i]=spectraDark2D[i][j];
        }

        if (verbos > 2) {
          Serial.print("      dark pixel ");
          Serial.print(j);
          Serial.print(":");
          for(int i=0;i<reps;i++){
            Serial.print(repeatArray[i]);
            if (i < reps-1){
              Serial.print(',');
            }
          }
          Serial.println();
         
        }
      } else { 
        for(int i=0;i<reps;i++){
          repeatArray[i]=spectraSignal2D[i][j];

        }
        if (verbos > 2) {
          Serial.print("      signal pixel ");
          Serial.print(j);
          Serial.print(":");
          for(int i=0;i<reps;i++){
            Serial.print(repeatArray[i]);
            if (i < reps-1){
              Serial.print(',');
            }
          }
          Serial.println();
        }
      }
        
      if (headTrailScans > 0) {
        
        // Sort the complete array for this pixel
        qsort(repeatArray, reps, sizeof(repeatArray[0]), sortDescending);
        // Loop over the array and only pick the central values
        for(int i=0;i<reps;i++){ 
          
          if (i >= headTrailScans && i <= coreScans+headTrailScans) {
            
            coreArray[i-headTrailScans] = repeatArray[i];
            
          }
        }
        
        if (verbos > 2) {
          Serial.print("      sorted: ");
          for(int i=0;i<reps;i++){ 
            Serial.print(repeatArray[i]);
            if (i < reps-1){
              Serial.print(',');
            }
          }
          Serial.println();  
        }
        
      } else { // No headTrailScans
        for(int i=0;i<reps;i++){                    
          coreArray[i] = repeatArray[i];
        }
        
      }

      if (verbos > 2) {
        Serial.print("      coreArray: ");
        for(int i=0;i<coreScans;i++){ 
          Serial.print(coreArray[i]);
          if (i < coreScans-1){
            Serial.print(',');
          }
        }
        Serial.print("; mean: ");   
      }

      // SUM of each pixel
      for(int i=0;i<coreScans;i++){
          sum += coreArray[i];
      }
      meanSignal = (float)sum/coreScans;
      //Serial.print(" mean:");
      //Serial.print(meanSignal);

      if (verbos > 2) {
        Serial.print(meanSignal);
        Serial.print("; std: ");   
      }
      
      sqDiff = 0;
      for(int i=0;i<coreScans;i++){ 
          sqDiff += (coreArray[i] - meanSignal) * (coreArray[i] - meanSignal); 
      }
      varianceSignal = sqDiff / coreScans;
      //Serial.print(" variance:");
      //Serial.print(varianceSignal);
  
      stdSignal = sqrt(varianceSignal);

      if (verbos > 2) {
        Serial.println(stdSignal);
      }
      if (n == 0) {
        spectraDarkMean[j] = meanSignal;
        spectraDarkStd[j] = stdSignal;
      } else {
        spectraSignalMean[j] = meanSignal;
        spectraSignalStd[j] = stdSignal;
      }
    }
    n +=1;
  }   
}


void calc_spectra_mean_std(String sensor, int headTrailScans, int coreScans, int start_ch, int end_ch){
  int i;
  //int n = 0;
  uint16_t scannr = 0;
 
  float sum;
  float meanSignal;
  float varianceSignal;
  float sqDiff;
  float stdSignal;

  uint16_t reps = headTrailScans*2+coreScans;

  uint16_t repeatArray[reps];
  uint16_t coreArray[coreScans];
  
  if (verbos > 1) {
     Serial.println("    Calculating pixel mean and std: ");
     Serial.print("      start_ch: ");
     Serial.print(start_ch);
     Serial.print(" end_ch: ");
     Serial.println(end_ch);
  }
  for(int j=start_ch;j<end_ch;j++) {
    sum = 0;
    for(int i=0;i<reps;i++){
      repeatArray[i]=spectraSignal2D[i][j];
    }
    if (verbos > 2) {
      Serial.print("      signal pixel ");
      Serial.print(j);
      Serial.print(":");
      for(int i=0;i<reps;i++){
        Serial.print(repeatArray[i]);
        if (i < reps-1){
          Serial.print(',');
        }
      }
      Serial.println();
    }    
    if (headTrailScans > 0) {
      // Sort the complete array for this pixel
      qsort(repeatArray, reps, sizeof(repeatArray[0]), sortDescending);
      // Loop over the array and only pick the central values
      for(int i=0;i<reps;i++){    
        if (i >= headTrailScans && i <= coreScans+headTrailScans){   
          coreArray[i-headTrailScans] = repeatArray[i];    
        }
      }
        
      if (verbos > 2) {
        Serial.print("      sorted: ");
        for(int i=0;i<reps;i++){ 
          Serial.print(repeatArray[i]);
          if (i < reps-1){
            Serial.print(',');
          }
        }
        Serial.println();  
      }
        
    } else { // No headTrailScans
      for(int i=0;i<reps;i++){                    
        coreArray[i] = repeatArray[i];
      }
        
    }

    if (verbos > 2) {
      Serial.print("      coreArray: ");
      for(int i=0;i<coreScans;i++){ 
        Serial.print(coreArray[i]);
        if (i < coreScans-1){
          Serial.print(',');
        }
      }
      Serial.print("; mean: ");   
   }

    // SUM of each pixel
    for(int i=0;i<coreScans;i++){
      sum += coreArray[i];
    }
    meanSignal = (float)sum/coreScans;
    //Serial.print(" mean:");
    //Serial.print(meanSignal);

    if (verbos > 2) {
      Serial.print(meanSignal);
      Serial.print("; std: ");   
    }
      
    sqDiff = 0;
    for(int i=0;i<coreScans;i++){ 
      sqDiff += (coreArray[i] - meanSignal) * (coreArray[i] - meanSignal); 
    }
    varianceSignal = sqDiff / coreScans;
  
    stdSignal = sqrt(varianceSignal);

    if (verbos > 2) {
      Serial.println(stdSignal);
    }
    spectraSignalMean[j] = meanSignal;
    spectraSignalStd[j] = stdSignal; 
  }
}

void calc_dark_mean_std(String sensor, int darkScans, int start_ch, int end_ch){
  int i;
  //int n = 0;
  uint16_t scannr = 0;
 
  float sum;
  float meanSignal;
  float varianceSignal;
  float sqDiff;
  float stdSignal;

  //uint16_t reps = darkScans:

  uint16_t coreArray[darkScans];
  
  if (verbos > 1) {
     Serial.println("    Calculating dark mean and std: ");
     Serial.print("      start_ch: ");
     Serial.print(start_ch);
     Serial.print(" end_ch: ");
     Serial.println(end_ch);
  }
  for(int j=start_ch;j<end_ch;j++) {
    sum = 0;
    for(int i=0;i<darkScans;i++){
      coreArray[i]=spectraDark2D[i][j];
    }
    if (verbos > 2) {
      Serial.print("      dark pixel ");
      Serial.print(j);
      Serial.print(":");
      for(int i=0;i<darkScans;i++){
        Serial.print(coreArray[i]);
        if (i < darkScans-1){
          Serial.print(',');
        }
      }
      Serial.print("; mean: ");
    }    

    // SUM of each pixel
    for(int i=0;i<darkScans;i++){
      sum += coreArray[i];
    }
    meanSignal = (float)sum/darkScans;
    //Serial.print(" mean:");
    //Serial.print(meanSignal);

    if (verbos > 2) {
      Serial.print(meanSignal);
      Serial.print("; std: ");   
    }
      
    sqDiff = 0;
    for(int i=0;i<darkScans;i++){ 
      sqDiff += (coreArray[i] - meanSignal) * (coreArray[i] - meanSignal); 
    }
    varianceSignal = sqDiff / darkScans;
  
    stdSignal = sqrt(varianceSignal);

    if (verbos > 2) {
      Serial.println(stdSignal);
    }
    spectraDarkMean[j] = meanSignal;
    spectraDarkStd[j] = stdSignal; 
  }
}

void single_w_headtrail_spectra_dark_mean(String sensor, int headTrailScans, int coreScans, int start_ch, int end_ch){
  int i;
  //int n = 0;
  uint16_t scannr = 0;
  uint16_t reps = headTrailScans*2+coreScans;
  uint16_t repeatArray[12];
  uint16_t coreArray[6];

  if (verbos > 1) {
     Serial.println("    Single scan with head and trail: ");
     Serial.print("    start_ch: ");
     Serial.print(start_ch);
     Serial.print(" end_ch: ");
     Serial.println(end_ch);
  }

  int n = 0;
  while (n < 2) { 
    for(int j=start_ch;j<end_ch;j++) {
      
      if (n == 0) {
        for(int i=0;i<reps;i++){
          repeatArray[i]=spectraDark2D[i][j];
        }
      } else { 
        for(int i=0;i<reps;i++){
          repeatArray[i]=spectraSignal2D[i][j];
        }
      }
        
      if (headTrailScans > 0) {
        // Sort the complete array for this pixel
        qsort(repeatArray, reps, sizeof(repeatArray[0]), sortDescending);
        // Loop over the array and only pick the central values
        for(int i=0;i<reps;i++){ 
          if (i >= headTrailScans && i <= headTrailScans+coreScans) {
            coreArray[i-headTrailScans] = repeatArray[i];  
          }
        } 
      } else { // No headTrailScans
        for(int i=0;i<reps;i++){                    
          coreArray[i] = repeatArray[i];
        }   
      }
      if (n == 0) {
        spectraDarkMean[j] = coreArray[0];
      } else {
        spectraSignalMean[j] = coreArray[0];
      }
    }
    n +=1;
  }   
}


void single_w_headtrail_spectra_mean(String sensor, int headTrailScans, int coreScans, int start_ch, int end_ch){
  int i;

  uint16_t reps = headTrailScans*2+coreScans;
  uint16_t repeatArray[12];
  uint16_t coreArray[6];

  if (verbos > 1) {
     Serial.println("    Single scan with head and trail: ");
     Serial.print("    start_ch: ");
     Serial.print(start_ch);
     Serial.print(" end_ch: ");
     Serial.println(end_ch);
  }
  for(int j=start_ch;j<end_ch;j++) {
    for(int i=0;i<reps;i++){
      repeatArray[i]=spectraSignal2D[i][j];
    }
   
    if (headTrailScans > 0) {
      // Sort the complete array for this pixel
      qsort(repeatArray, reps, sizeof(repeatArray[0]), sortDescending);
      // Loop over the array and only pick the central values
      for(int i=0;i<reps;i++){ 
        if (i >= headTrailScans && i <= headTrailScans+coreScans) {
          coreArray[i-headTrailScans] = repeatArray[i];  
        }
      } 
    } else { // No headTrailScans
      for(int i=0;i<reps;i++){                    
        coreArray[i] = repeatArray[i];
      }   
    }
    spectraSignalMean[j] = coreArray[0];
  }   
}

void single_dark_mean(String sensor, int start_ch, int end_ch){
  int i;
  uint16_t repeatArray[12];
  uint16_t coreArray[6];
  if (verbos > 1) {
     Serial.println("    Single  dark scan: ");
     Serial.print("    start_ch: ");
     Serial.print(start_ch);
     Serial.print(" end_ch: ");
     Serial.println(end_ch);
  }
  for(int j=start_ch;j<end_ch;j++) {
    spectraDarkMean[j] = spectraDark2D[0][j];
    spectraDarkStd[j] = 0;
  }   
}

void value_print_Wavelengths(String sensor, int start_ch, int end_ch){
  int i;
  if (verbos){
    Serial.print("    data=");
  } else {
    Serial.print("data=");
  }
  Serial.print(sensor);
  Serial.print(",wl,");
  Serial.print(-1);
  Serial.print(',');
  for ( i = start_ch ; i < end_ch ; i++ ) {
    Serial.print(waveLenghtsNanometer[i]);     
    if (i < end_ch-1){
      Serial.print(',');
    }    
  }
  Serial.print("\n");
}

void value_print_Main2D_spectra_dark(String sensor, uint16_t repeats, int start_ch, int end_ch){
  int i;
  int n = 0;
  uint16_t scannr = 0;
  
  while (scannr < repeats) {
    n = 0;
    while (n < 2) { 
      
      if (verbos){
        Serial.print("    data=");
      } else {
        Serial.print("data=");
      }
      Serial.print(sensor);
      Serial.print(",raw,");
      Serial.print(':');
      Serial.print(n);
      Serial.print(',');
      for ( i = start_ch ; i < end_ch ; i++ )
      {
        if (n == 0) {
          Serial.print(spectraDark2D[scannr][i]);     
        } else {
          Serial.print(spectraSignal2D[scannr][i]);
        }
        
        if (i < end_ch-1){
          Serial.print(',');
        }    
      }
      Serial.print("\n");
      n += 1;
    }
    scannr += 1;
  }
}

void value_print_Main_spectra_dark(String sensor, int start_ch, int end_ch){
  int i;
  int n = 0;
  while (n < 2) { 
    if (verbos){
      Serial.print("    data=");
    } else {
      Serial.print("data=");
    }
    Serial.print(sensor);
    Serial.print(sensor);
    Serial.print(",raw,");
    Serial.print(n);
    Serial.print(',');
    for ( i = start_ch ; i < end_ch ; i++ )
    {
      if (n == 0) {
        Serial.print(spectraDark[i]);     
      } else {
        Serial.print(spectraSignal[i]);
      }
      
      if (i < end_ch-1){
        Serial.print(',');
      }    
    }
    Serial.print("\n");
    n += 1;
  }
}

void value_print_Main_spectra(String sensor, int start_ch, int end_ch){
  int i;
    if (verbos){
      Serial.print("    data=");
    } else {
      Serial.print("data=");
    }
    Serial.print(sensor);
    Serial.print(sensor);
    Serial.print(",raw,");
    Serial.print('1');
    Serial.print(',');
    for ( i = start_ch ; i < end_ch ; i++ ){
      Serial.print(spectraSignal[i]);
      if (i < end_ch-1){
        Serial.print(',');
      }    
    }
    Serial.print("\n");
}

void value_print_Main_dark(String sensor, int start_ch, int end_ch){
  int i;
    if (verbos){
      Serial.print("    data=");
    } else {
      Serial.print("data=");
    }
    Serial.print(sensor);
    Serial.print(sensor);
    Serial.print(",raw,");
    Serial.print('0');
    Serial.print(',');
    for ( i = start_ch ; i < end_ch ; i++ ){
      Serial.print(spectraDark[i]);
      if (i < end_ch-1){
        Serial.print(',');
      }    
    }
    Serial.print("\n");
}

void value_print_SortedSpectra(String sensor, uint16_t sortedSpectra[], int start_ch, int end_ch){
  Serial.print("  sortedSpectra=");
  Serial.print(sensor);
  Serial.print(',');

  for ( int i = start_ch ; i < end_ch ; i++ )
  {
    Serial.print(sortedSpectra[i]);     
    if (i < end_ch-1){
      Serial.print(',');
    }    
  }
    Serial.print("\n");
}
/* END value_print_SortedSpectra() */

// Function to copy 'len' elements from 'src' to 'dst'
void copy(uint16_t* src, uint16_t* dst, int startPixel, int endPixel, bool verbso) {
  if (verbso){
    Serial.print("      Copying pixel: ");
    Serial.print(startPixel);
    Serial.print(" to ");
    Serial.println(endPixel);
  }   
  for (int i = startPixel; i < endPixel; i++) {
    dst[i] = src[i];
  }
}
/* END copy */

void copyNull(uint16_t* dst, int startPixel, int endPixel, bool verbso) {
  if (verbso){
    Serial.print("      Nullifying pixel: ");
    Serial.print(startPixel);
    Serial.print(" to ");
    Serial.println(endPixel);
  }   
  for (int i = startPixel; i < endPixel; i++) {
    dst[i] = 0;
  }
}
/* END copy */


void copySpectraSignal(uint16_t* src, uint16_t* dst, uint16_t m, int startPixel, int endPixel, bool verbso) {
  if (verbso){
    Serial.print("      Copying pixel: ");
    Serial.print(startPixel);
    Serial.print(" to ");
    Serial.print(endPixel);
    Serial.print("; scannr: ");
    Serial.println(m);
    
  }   
  for (int i = startPixel; i < endPixel; i++) {
    dst[i] = src[i];
    //dst2D[m][i] = src[i];
    spectraSignal2D[m][i] = src[i];
  }
}
/* END copySpectraSignal */

void copySpectraDark(uint16_t* src, uint16_t* dst, uint16_t m, int startPixel, int endPixel, bool verbso) {
  if (verbso){
    Serial.print("      Copying pixel: ");
    Serial.print(startPixel);
    Serial.print(" to ");
    Serial.print(endPixel);
    Serial.print("; scannr: ");
    Serial.print(m);
  }   
  for (int i = startPixel; i < endPixel; i++) {
    dst[i] = src[i];
    //dst2D[m][i] = src[i];
    spectraDark2D[m][i] = src[i];
  }
}
/* END copySpectraSignal */

void hamamatsu_dark_scan(uint8_t nIntTimes, uint8_t loopnr, uint8_t scannr){

  const int N = nIntTimes;

  int integTime;
  int startPixel;
  int endPixel;
  
  for (int j = N-1; j>=0; j--){

    loopnr += 1;

    integTime = SPECTRO_integration_times[j];
    startPixel = SPECTRO_start_pixels[j];
    endPixel = SPECTRO_end_pixels[j];

    setLoopNeopixel(loopnr);

    if (verbos) {  
      Serial.print("    dark scan integration time: ");
      Serial.println(integTime);
    }
      
    // Empty spectrometer wells to get clean read 
    readSpectrometer();
  
    // Fill up the spectrometer wells
    delay (integTime);
      
    // Read the sample signal
    readSpectrometer();
      
    // copy the spectra to spectraDark 
    
    copySpectraDark(spectra, spectraDark, scannr, startPixel, endPixel, false); //Call a function copy    
  } // end for 
  if (verbos) {
    value_print_Main_dark(sensor, START_CHANNEL, END_CHANNEL);
  }
}

void hamamatsu_spectra_scan_half(uint8_t headTrailScans, uint8_t coreScans, uint8_t darkScans, uint8_t nIntTimes){

  int integTime;
  int startPixel;
  int endPixel;
  int reps = headTrailScans*2 + coreScans;

  //const int N = nIntegrationTimes;
  const int N = nIntTimes;
  
  // Set LED voltage
  float LED_vset_mV = vset_mV;

  // reset spectraScan and darkScan
  memset(spectraSignal, 0, sizeof(spectraSignal));
  memset(spectraDark, 0, sizeof(spectraDark));
  
  uint8_t scannr = 0;
  int loopnr = 0;

  if (verbos) {
    Serial.println("\n  Starting spectral scan: ");
  }

  // Power up spectrometer
  digitalWrite(SPECTRO_BOOST_EN, HIGH);
  delay(10);
  
  if (darkScans) { // if darkscan [any nr] start with one
    hamamatsu_dark_scan(nIntTimes, 0, 0);
    loopnr += 1;
    setLoopNeopixel(loopnr);
  }

  // Start LED driver 
  digitalWrite(LED_BUCK_EN, HIGH);
  delay (10);
  
  // Turn on the light source
  LED_setVoltage_mV(LED_vset_mV);
  
  digitalWrite(LED_PULSE, HIGH);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, HIGH);
      
  // Let light stabilize
  delay (stabilisationTime);
  
  while (scannr < reps) { 

    for (int j = N-1; j>=0; j--){

      loopnr += 1;

      integTime = SPECTRO_integration_times[j];
      startPixel = SPECTRO_start_pixels[j];
      endPixel = SPECTRO_end_pixels[j];

      setLoopNeopixel(loopnr);

      if (verbos) {  

        Serial.print("    integration time: ");
        Serial.println(integTime);
      }
      
      // Empty spectrometer wells to get clean read 
      readSpectrometer();
  
      // Fill up the spectrometer wells
      delay (integTime);
      
      // Read the sample signal
      readSpectrometer();
      
      // copy the spectra to spectraSignal
      //copy(spectra, spectraSignal, startPixel, endPixel, verbos); //Call a function copy 
      copySpectraSignal(spectra, spectraSignal, scannr, startPixel, endPixel, verbos); //Call a function copy 
      
    } // end for 
    // Write out the scan result

    if (verbos > 1) {
      value_print_Main_spectra(sensor, START_CHANNEL, END_CHANNEL);
    }
    scannr += 1;  
  } // end while

  // Turn off light source
  LED_setVoltage_mV(0);
    
  digitalWrite(LED_PULSE, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);

  // Turn off LED driver 
  digitalWrite(LED_BUCK_EN, LOW);
  
  if (darkScans == 2) { // if darkscan is 2 finish with one
    // the scannr for this darkscan is then = 1
    hamamatsu_dark_scan(nIntTimes, loopnr, 1);
  }
  
  // Power down spectrometer
  digitalWrite(SPECTRO_BOOST_EN, LOW);
    
  turnOffNeopixel();

  Serial.println("\nStartWavelengths: ");

  // Print out the exact wavelegnths for this sensor
  value_print_Wavelengths(sensor, START_CHANNEL, END_CHANNEL);

  Serial.println("EndWavelengths");

  Serial.println("\nStartSpectralData: ");
  
  // Calculate the mean and standard deviation
  if (getReturnFormat()){
    // Print out all individual scans
    value_print_Main2D_spectra_dark(sensor, reps, START_CHANNEL, END_CHANNEL);
        
  } else {
    
    if (coreScans > 1) {
      calc_spectra_mean_std(sensor, headTrailScans, coreScans, START_CHANNEL, END_CHANNEL);
    } else {
      single_w_headtrail_spectra_mean(sensor, headTrailScans, coreScans, START_CHANNEL, END_CHANNEL);
    }
    if (darkScans == 0) {
      if (verbos > 1) {
        Serial.println("  Dark signal from file");
      }
    } else if (darkScans == 1) {
      if (verbos > 1) {
        Serial.println("  Single dark signal");
      }
      single_dark_mean(sensor, START_CHANNEL, END_CHANNEL);
    } else {
      if (verbos > 1) {
        Serial.println("  Calculatiing dark signal mean and std");
      }
      calc_dark_mean_std(sensor, darkScans, START_CHANNEL, END_CHANNEL);
    }

    // Print out mean and standard deviation
    value_print_spectra_dark_mean_std(sensor, START_CHANNEL, END_CHANNEL);
  }
  Serial.println("EndSpectralData");
}
/* hamamatsu_spectra_scan_half */

void hamamatsu_spectra_scan_full(uint8_t headTrailScans, uint8_t coreScans, uint8_t darkScans, uint8_t nIntTimes){

  int integTime;
  int startPixel;
  int endPixel;
  int reps = headTrailScans*2 + coreScans;

  //const int N = nIntegrationTimes;
  const int N = nIntTimes;
  
  // Set LED voltage
  float LED_vset_mV = vset_mV;

  // reset spectraScan and darkScan
  memset(spectraSignal, 0, sizeof(spectraSignal));
  memset(spectraDark, 0, sizeof(spectraDark));
  
  uint8_t scannr = 0;
  int loopnr = 0;

  if (verbos) {
    Serial.println("\n  Starting spectral scan: ");
  }

  // Power up spectrometer
  digitalWrite(SPECTRO_BOOST_EN, HIGH);
  // Start LED driver 
  digitalWrite(LED_BUCK_EN, HIGH);
  delay (10);
  
  while (scannr < reps) { 

    for (int j = N-1; j>=0; j--){

      loopnr += 1;

      integTime = SPECTRO_integration_times[j];
      startPixel = SPECTRO_start_pixels[j];
      endPixel = SPECTRO_end_pixels[j];

      setLoopNeopixel(loopnr);

      if (verbos) {  

        Serial.print("    integration time: ");
        Serial.println(integTime);
      }

      // Turn on the light source
      LED_setVoltage_mV(LED_vset_mV);
  
      digitalWrite(LED_PULSE, HIGH);
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_BLUE, HIGH);
      
      // Let light stabilize
      delay (stabilisationTime);
      
      // Empty spectrometer wells to get clean read 
      readSpectrometer();
  
      // Fill up the spectrometer wells
      delay (integTime);
      
      // Read the sample signal
      readSpectrometer();
      
      // copy the spectra to spectraSignal
      //copy(spectra, spectraSignal, startPixel, endPixel, verbos); //Call a function copy 
      copySpectraSignal(spectra, spectraSignal, scannr, startPixel, endPixel, verbos); //Call a function copy 

      // Turn off light source
      LED_setVoltage_mV(0);
    
      digitalWrite(LED_PULSE, LOW);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_BLUE, LOW);
      
      // Wait a bit for light to go off completely
      delay (stabilisationTime);
      
      // Empty spectrometer wells to get a clean read 
      readSpectrometer();
  
      // Set the same integration time as in the sample read
      delay (integTime);
      
      // Read the dark signal
      readSpectrometer();
      
      // copy the spectra to darkSignal
      //copy(spectra, spectraDark, startPixel, endPixel, 0); //Call a function copy
      copySpectraDark(spectra, spectraDark, scannr, startPixel, endPixel, false); //Call a function copy 
      
    } // end for 
    // Write out the scan result
    if (verbos > 1) {
      value_print_Main_spectra_dark(sensor, START_CHANNEL, END_CHANNEL);
    }
    scannr += 1;  
  } // end while
  turnOffNeopixel();

  // Turn off LED driver 
  digitalWrite(LED_BUCK_EN, LOW);
  // Power down spectrometer
  digitalWrite(SPECTRO_BOOST_EN, LOW);
  
  Serial.println("\n  Scan results: ");

  // Print out the exact wavelegnths for this sensor
  value_print_Wavelengths(sensor, START_CHANNEL, END_CHANNEL);
  
  // Calculate the mean and standard deviation
  if (getReturnFormat()){
    // Print out all individual scans
    value_print_Main2D_spectra_dark(sensor, reps, START_CHANNEL, END_CHANNEL);
        
  } else {
    if (coreScans > 1) {
      calc_spectra_dark_mean_std(sensor, headTrailScans, coreScans, START_CHANNEL, END_CHANNEL);
    } else {
      single_w_headtrail_spectra_dark_mean(sensor, headTrailScans, coreScans, START_CHANNEL, END_CHANNEL);
    }
      
    // Print out mean and standard deviation
    value_print_spectra_dark_mean_std(sensor, START_CHANNEL, END_CHANNEL);
  }
}
/* hamamatsu_spectra_scan_full */

void hamamatsu_spectra_scan(uint8_t headTrailScans, uint8_t coreScans, uint8_t darkScans, uint8_t nIntTimes) {
  
  if (darkScans == coreScans){
    if (verbos) {
      Serial.println("  Full scan of both sample and dark");
    } 
    hamamatsu_spectra_scan_full(headTrailScans, coreScans, darkScans, nIntTimes);
  } else if (darkScans == 0) {
    if (verbos) {
      Serial.println("  No scanning of dark signal");
    }
    hamamatsu_spectra_scan_half(headTrailScans, coreScans, darkScans, nIntTimes);
  } else if (darkScans == 1) {
    if (verbos) {
      Serial.println("  Dark signal from single scan");
    }
    hamamatsu_spectra_scan_half(headTrailScans, coreScans, darkScans, nIntTimes);
  } else {
    if (verbos) {
      Serial.println("  Dark signal from twoscans");
    }
    hamamatsu_spectra_scan_half(headTrailScans, coreScans, 2, nIntTimes);
  } 
}

void LampWarmUp(int vset_mV, int cycles) {
  if (verbos) {
    Serial.println("\n  Warming up lamp");
  }

  // Power up the spectrometer
  digitalWrite(SPECTRO_BOOST_EN, HIGH);
  // Start LED driver 
  digitalWrite(LED_BUCK_EN, HIGH);
  delay (10);

  // Set LED voltage
  float LED_vset_mV = vset_mV;
  uint8_t scannr = 0;
  while (scannr < cycles) { 
    setLoopNeopixel(scannr);
    // Turn on the light source
    LED_setVoltage_mV(LED_vset_mV);
  
    digitalWrite(LED_PULSE, HIGH);
    digitalWrite(LED_RED, HIGH);
      
    delay (500);

    // Turn off light source
    LED_setVoltage_mV(0);
    
    digitalWrite(LED_PULSE, LOW);
    digitalWrite(LED_RED, LOW);
      
    delay (50); 

    scannr += 1;
     
  } // end while
  turnOffNeopixel();
  
  // Turn off LED driver 
  digitalWrite(LED_BUCK_EN, LOW);
  // Power down spectrometer
  digitalWrite(SPECTRO_BOOST_EN, LOW);
}
/* END LampWarmUpn */


int sortDescending(const void *cmp1, const void *cmp2)
{
  // Need to cast the void * to int *
  uint16_t  a = *((uint16_t  *)cmp1);
  uint16_t  b = *((uint16_t  *)cmp2);
  // The comparison
  return a > b ? -1 : (a < b ? 1 : 0);
  // A simpler, probably faster way:
  //return b - a;
}
/* END sortDescending() */

void adjustIntegratinTimes(){
  bool cont = true;
  int startPixel;
  int endPixel;
  // Set the initial maxSignal
  int maxSignal = 0;
  int intTime;

  if (verbos) {
    Serial.println("\n    Adjusting integration times");
  }
  
  while (cont) { // Continue until cont == false
    memset(spectraSection, 0, sizeof(spectraSection));

    // set cont to false, reset to true if signal is outside 5 % of maxDN
    cont = false;
    
    // Do the sepctral scan
    hamamatsu_spectra_scan(0,1,0,nIntegrationTimes);
    
    if (verbos) {
      Serial.println("\n      Checking integration times");
    }
    
    const int N = nIntegrationTimes;
  
    for (int j = 0; j<N; j++){
       
      startPixel = SPECTRO_start_pixels[j];
      endPixel = SPECTRO_end_pixels[j];
        
      copy(spectraSignal, spectraSection, startPixel, endPixel, 1); //Call a function copy

      /* Set zeroes to all pixels except those in the active range */      
      for (int k = 0; k<j; k++){
        startPixel = SPECTRO_start_pixels[k];
        endPixel = SPECTRO_end_pixels[k];
        copyNull(spectraSection, startPixel, endPixel, verbos+1);
      }

      // Get max signal for the scan
      maxSignal = 0;
         
      for (int i = START_CHANNEL; i < END_CHANNEL ; i++) {
            
        if (spectraSection[i] > maxSignal) {
          maxSignal = spectraSection[i];
        }
      }
      
      if (verbos > 2) {
        for (int i = START_CHANNEL; i < END_CHANNEL ; i++) {

          Serial.print("    pixel: ");
          Serial.print(i);
          Serial.print(", DN: ");
          Serial.println(spectraSection[i]);
           
        }
      }
        
      if (verbos) {
        Serial.print("      maxSignal: ");
        Serial.println(maxSignal);
        Serial.print("      deviation (percent) from maxDN: ");
        Serial.println((100*maxDN-100*maxSignal)/maxDN);

      }

      if ( abs(100*maxDN-100*maxSignal)/maxDN  > 5) {
        if (verbos) {
          Serial.print("      Resetting integration time from: ");
          Serial.print(SPECTRO_integration_times[j]);
        }
        intTime = SPECTRO_integration_times[j];
        intTime *= float(maxDN)/float(maxSignal);
        SPECTRO_integration_times[j] = int(intTime);
        cont = true;
        if (verbos) {
          Serial.print(" to: ");
          Serial.println(SPECTRO_integration_times[j]);
        }
      }
    }
  }
}

void autoSetIntegrationTimes(String sensor, int stabilisationTime, int vset_mV, int nIntegrationTimes, int maxDN,
                        int iniIntegrationTime, int ascendingIntegrationTimeStep, int descedingIntegrationTimeStep){

  int startPixel;
  int endPixel;
      
  // Set repeats to single scan
  uint8_t samplerepeats = 1;
  uint8_t darkrepeats = 1;
  
  // define the arrays (size = 1) to send to hamamatsu_spectra_scan
  /*int startPixels[1];
  int endPixels[2];
  int SPECTRO_integration_times[2];*/

  memset(SPECTRO_integration_times, 0, sizeof(SPECTRO_integration_times));
  memset(SPECTRO_start_pixels, 0, sizeof(SPECTRO_start_pixels));
  memset(SPECTRO_end_pixels, 0, sizeof(SPECTRO_end_pixels));

  // Set initial integration time and define the full range of channels/pixels
  SPECTRO_integration_times[0] = iniIntegrationTime;
  SPECTRO_start_pixels[0] = START_CHANNEL;
  SPECTRO_end_pixels[0] = END_CHANNEL;

  //integrationTimes[0] = iniIntegrationTime;
  //startPixels[0] = START_CHANNEL;
  //endPixels[0] = END_CHANNEL;
  //integrationTimes[1] = iniIntegrationTime;
  //startPixels[1] = START_CHANNEL;
  //endPixels[1] = END_CHANNEL;
  
  // The boolean variables ascending and cont are used for detrmining if the intergration time should increase or decrease
  bool ascending = true;
  bool cont = true;

  // Set the initial maxSignal
  int maxSignal = 0;

  if (verbos) {
    Serial.print("  nIntegrationTimes: ");
    Serial.println( nIntegrationTimes);
    Serial.print("  start pixel: ");
    Serial.println(SPECTRO_start_pixels[0]);
    Serial.print("  end pixel: ");
    Serial.println(SPECTRO_end_pixels[0]);  
  }

  LampWarmUp(vset_mV,12);
                             
  while (cont) { // Continue until cont == false
    
    // reset spectra
    memset(spectra, 0, sizeof(spectra));
    
    if (verbos) {
      Serial.print("  integration time: ");
      Serial.println(SPECTRO_integration_times[0]);   
    }
    
    hamamatsu_spectra_scan(0, 1, 0, 1);

    // Get max signal for the scan
    maxSignal = spectra[0];
    
    for (int i = START_CHANNEL; i < END_CHANNEL ; i++) {
      if (spectraSignal[i] > maxSignal) {
         maxSignal = spectraSignal[i];
      }
    }
    
    if (verbos) {
      Serial.print("      maxSignal: ");
      Serial.println(maxSignal);
    }
    
    // Check the maxSignal vs the maxDN of the sensor and adjust, if ready set cont to False to break loop
    if (ascending && maxSignal < maxDN) {
      SPECTRO_integration_times[0] += ascendingIntegrationTimeStep;   
    } else {
      ascending = false;
      if (maxSignal < maxDN){
        cont = false;
      } else {
        SPECTRO_integration_times[0] -= descedingIntegrationTimeStep;
      }    
    } 
  }

  // sort the last scan in place
  int scan_length = sizeof(spectraSignal) / sizeof(spectraSignal[0]);
  qsort(spectraSignal, scan_length, sizeof(spectraSignal[0]), sortDescending);

  // extract the channels with valid values
  int LIVE_CHANNELS = END_CHANNEL-START_CHANNEL;
  uint16_t sortedSpectra[LIVE_CHANNELS];
  for (int s = 0; s <= LIVE_CHANNELS; s++) {
      sortedSpectra[s] = spectraSignal[s];
  }

  if (verbos) {
    Serial.print("\n  Tuned integration time: ");
    Serial.println(SPECTRO_integration_times[0]);
    // print the sorted spectra
    if (verbos > 2) {
      value_print_SortedSpectra(sensor, sortedSpectra, 0, LIVE_CHANNELS); 
    } 
  }

  // Find the optimal DN split levels
  int SpectraSplit[nIntegrationTimes];
  int integrationTimeFactors[nIntegrationTimes];
  int split = 0;
  int ns = 0;
  int intTime = SPECTRO_integration_times[0];
  
  // Split with linear division
  // Most straight forward and OK result
  split = maxSignal/nIntegrationTimes;
  for (int r = 0; r < nIntegrationTimes-1; r++) {
    ns = nIntegrationTimes-1-r;
    SpectraSplit[r] = split*(ns);
    intTime = SPECTRO_integration_times[0]*(r+1);
    integrationTimeFactors[r] = intTime;   
  }
  
  /*
  // Sequential split in halfs; gives a wider center but is generally not better
  split = maxSignal;
  for (int r = 0; r < nIntegrationTimes-1; r++) {
    split /= 2;
    SpectraSplit[r] = split;
    intTime *= 2;
    integrationTimeFactors[r] = intTime
  }
  */
  
  // reset spectraScan and darkScan
  memset(spectraSignal, 0, sizeof(spectraSignal));
  memset(spectraDark, 0, sizeof(spectraDark));

  // rescan as the previous scan is sorted
  if (verbos) {
    Serial.print("  Rescanning tuned integration time: ");
    Serial.println(SPECTRO_integration_times[0]);
  }
  
  // Do the sepctral scan, only 1 integration item for sample and 0 for dark

  hamamatsu_spectra_scan(0,1, 0, 1);

  if (verbos) {
    Serial.println("  Splitting the tuned spectra histogram: ");
  }
   
  // Divide the spectra using the split levels
  int s;
  int n;
  for (int r = 0; r < nIntegrationTimes-1; r++) {
    split = SpectraSplit[r];
    if (verbos) {
      Serial.print("    split@: ");
      Serial.println(SpectraSplit[r]);   
    }
    
    s = 0;
    n = 0;
 
    SPECTRO_integration_times[r] = integrationTimeFactors[r];
    while (s < split){
      s = spectraSignal[n];
      SPECTRO_start_pixels[r] = n;
      n+=1;
    }
    n = END_CHANNEL;
    s = 0;
    while (s < split){
      s = spectraSignal[n];
      SPECTRO_end_pixels[r] = n;
      n-=1;
    }
  }

  // Set the last integrationTime which should cover the full pixel range from startPixel to endPixel
  SPECTRO_integration_times[nIntegrationTimes-1] = SPECTRO_integration_times[0]*(nIntegrationTimes);
  SPECTRO_start_pixels[nIntegrationTimes-1] = START_CHANNEL;
  SPECTRO_end_pixels[nIntegrationTimes-1] = END_CHANNEL;

  /* FineTune by adhusting the integration times */
  adjustIntegratinTimes();
 
  if (verbos){
     Serial.println("  Finished automatic setting of integrationtimes");
     PrintScanTuning();
   }
}
/* END autoSetIntegrationTimes() */

void PrintScanTuning(){

    Serial.print("    maxDN: ");
    Serial.println(maxDN);
    Serial.print("    vset_mV: ");
    Serial.println(vset_mV);
    Serial.print("    stabilisationTime: ");
    Serial.println(stabilisationTime);
    Serial.print("    nIntegrationTimes: ");
    Serial.println(nIntegrationTimes);

    for (int t = 0; t < nIntegrationTimes; t++){
      Serial.print("    IntegrationTime");
      Serial.print(t);
      Serial.print(":");
      Serial.print( SPECTRO_integration_times[t] );
      Serial.print(" startPixel:");
      Serial.print( SPECTRO_start_pixels[t] );
      Serial.print(" endPixel:");
      Serial.println( SPECTRO_end_pixels[t] );
    }  
}

void PrintAutoScanTuning(int iniIntegrationTime, int ascendingIntegrationTimeStep, int descendingIntegrationTimeStep){
  if (verbos){
    Serial.print("    maxDN: ");
    Serial.println(maxDN);
    Serial.print("    vset_mV: ");
    Serial.println(vset_mV);
    Serial.print("    stabilisationTime: ");
    Serial.println(stabilisationTime);
    Serial.print("    nIntegrationTimes: ");
    Serial.println(nIntegrationTimes);

    Serial.print("    iniIntegrationTime: ");
    Serial.println(iniIntegrationTime);

    Serial.print("    ascendingIntegrationTimeStep: ");
    Serial.println(ascendingIntegrationTimeStep);

    Serial.print("    descendingIntegrationTimeStep: ");
    Serial.println(descendingIntegrationTimeStep);
  }
}

void ReadScanTuningFS(String FPN, String firstLine) {

  String fileContents = ReadFile( FPN );

  if (verbos > 1) {
    Serial.print ("    Scan tuning from file: " + fileContents);
  }

  DeSerialiseScanTuning( fileContents );
  sensor_fs = TunedScanMeta[0];
  muzzle_fs = TunedScanMeta[1];
  lamp_fs = TunedScanMeta[2];
  vset_mV = TunedScanVin;
  maxDN = TunedScanMaxDN;
  stabilisationTime = TunedScanStabilisationTime;
  nIntegrationTimes = TunedScanNrIntegrationTimes;
   
  for (int t=0; t < TunedScanNrIntegrationTimes; t++) {

    SPECTRO_integration_times[t] = TunedScanIntegrationTimes[t];
    SPECTRO_start_pixels[t] = TunedScanStartPixels[t];
    SPECTRO_end_pixels[t] = TunedScanEndPixels[t];
  }
  PrintScanTuning();
}

void setSpectralScanTuning(){
  
  // integration times are either userdefined in command , predefined in file or automatically set
  if   (fetchScanTuning == 1){  //1 = user defined 
    // manual setting requires that vset_mV and stabilisationtime are defined by the user
    vset_mV = getVset_mV();
    maxDN = getMaxDN();
    stabilisationTime = getStabilisationTime();
    nIntegrationTimes = getNrOfIntegrationTimes();

    for (int t = 0; t < nIntegrationTimes; t++){
      int u = firstIntegrationArgument+t*3;
      SPECTRO_integration_times[t] = getManualIntegrationTime(u);
      SPECTRO_start_pixels[t] =  getManualStartPixel(u+1);
      SPECTRO_end_pixels[t] = getManualEndPixel(u+2);
    }

    if (operation == 36) {
      // warm up the lamp
      LampWarmUp(vset_mV, warmup);
      // adjust the integration times
      adjustIntegratinTimes();  
    }
    
  } else if   (fetchScanTuning == 2){  //2 = default 
    // campaing default is defined on the flash drive
    
    //String FPN = "/campaign/" + campaign + "/"+ sensor + "/" + muzzle +"/" + "/setting/default.json";
    String scanTuningFPN = "/scantuning/" + sensor + "/" + campaign + "/" + muzzle + "/defaultScanTuning.json";
    
    String firstLine = "\n      Spectral Scan tuning: " + scanTuningFPN;
    ReadScanTuningFS(scanTuningFPN, firstLine); 
 


  } else if   (fetchScanTuning == 3){  //3 = muzzle default 
    // muzzle default is defined on the flash drive
    String FPN = "/muzzle/" + muzzle +"/" + "/setting/default.json";
    String firstLine = "\n      Spectral settings from file: " + FPN;
    ReadScanTuningFS(FPN, firstLine); 

    
  } else if (fetchScanTuning == 4){ // 4 = automatic
    int iniIntegrationTime= getInitialTuningIntegrationTime();
    int ascendingIntegrationTimeStep=getAscendingTuningStep();
    int descendingIntegrationTimeStep=getDescendingTuningStep();
    // automatic setting require requires that vset_mV, maxDN and stabilisationtime are defined by the user
    vset_mV = getVset_mV();
    maxDN = getMaxDN();
    stabilisationTime = getStabilisationTime();
    nIntegrationTimes = getNrOfIntegrationTimes();
    PrintAutoScanTuning(iniIntegrationTime, ascendingIntegrationTimeStep, descendingIntegrationTimeStep);
    
    autoSetIntegrationTimes(sensor, stabilisationTime, vset_mV, nIntegrationTimes, maxDN, iniIntegrationTime,
                            ascendingIntegrationTimeStep,descendingIntegrationTimeStep);

  } else if (fetchScanTuning == 5){  //5 = filenname 
    
    String FPN = getSensorSettingFilePath();
    String firstLine = "\n      Spectral settings from file: " + FPN;
    ReadScanTuningFS(FPN, firstLine); 
         
  }
} /* END setSpectralScanTuning() */

void HamamatsuScanParameters(){
  // Set the initial parameters

  sensor = getSensor();
  verbos = getVerbos();
  
  operation = getOperation();
  // Get fetchWhiteRef and fetchScanTuning - these are both forced to a value=4 if integrationtime is set to auto
  fetchWhiteRef = getWhiteRef();
  fetchScanTuning = getScanTuning();

  if (operation == 0) {

  } else if (operation == 1) {
 
  } else if (operation == 2) {
    fetchWhiteRef = 4; fetchScanTuning = 4;

  } else if (operation == 3) {
    fetchWhiteRef = 4; fetchScanTuning = 1;
 
  } else if (operation == 4) {
    fetchWhiteRef = 4; fetchScanTuning = 0;

  } else if (operation == 5) {
    

  } else if (operation == 6) {

  } else if (operation == 7) {

  } else if (operation == 8) {
    
  } else if (operation == 9) {
 
  } else if (operation == 26) {

  } else if (operation == 46) {

  } else if (operation == 36) {
    fetchWhiteRef = 4; fetchScanTuning = 1;

  } else if (operation == 57) {

  } else if (operation == 92) {
    fetchWhiteRef = 0; fetchScanTuning = 2;

  } else {

  }
    
  if (verbos) {
    Serial.println("  Process: Hamamatsu spectral scanning");
    Serial.print("  Operation: ");
    // put operation labels in json file?
    if (operation == 0) {
      Serial.println ("test scan");
    } else if (operation == 1) {
      Serial.println ("sample scan");
    } else if (operation == 2) {
      Serial.println ("set/update campaign auto integrationtime");
    } else if (operation == 3) {
      Serial.println ("set/update default fixed scan tuning with adjustment");
    } else if (operation == 4) {
      Serial.println ("set/update campaign fixed integrationitme");
    } else if (operation == 5) {
      Serial.println ("set/update default whiteref");
    } else if (operation == 6) {
      Serial.println ("set/update campaign white ref");
    } else if (operation == 7) {
      Serial.println ("set/update muzzle white ref");
    } else if (operation == 26) {
      Serial.println ("set/update campaign auto integrationitme + campaign white ref");
    } else if (operation == 46) {
      Serial.println ("set/update campaign fixed integrationitme + campaign white ref");
    } else if (operation == 37) {
      Serial.println ("set/update muzzle auto integration time + muzzle white ref");
    } else if (operation == 57) {
      Serial.println ("set/update muzzle fixed integration time + muzzle white ref");
    } else if (operation == 92) {
      Serial.println ("test scan with default scan tuning");
    } else {
      Serial.println ("Unknown operation type - please enter new command");
    }
  }

  // Print the source of the white reference
  if (verbos) {
    Serial.print("  Define White Reference: ");
    if (fetchWhiteRef == 0) {
      Serial.println ("None");
    } else if (fetchWhiteRef == 1) {
      Serial.println ("in-sampling");
    } else if (fetchWhiteRef == 2) {
      Serial.println ("from campaign default");
    } else if (fetchWhiteRef == 3) {
      Serial.println ("from muzzle default");
    } else if (fetchWhiteRef == 4) {
      Serial.println ("automatic");
    } else if (fetchWhiteRef == 5) {
      Serial.println ("from file");
    } else {
      Serial.println ("Unknown Definition of White Reference - please enter new command");
    }
  }

  // Print the source of the integration time
  if (verbos) {
    Serial.print("  Scan tuning: ");
    // put operation labels in json file?
    if (fetchScanTuning == 1) {
      Serial.println ("user defined");
    } else if (fetchScanTuning == 2) {
      Serial.println ("from default");
    } else if (fetchScanTuning == 4) {
      Serial.println ("automatic");
    } else if (fetchScanTuning == 5) {
      Serial.println ("adjusted");
    } else if (fetchScanTuning == 6) {
      Serial.println ("from file");
    } else {
      Serial.println ("Unknown definition of spectral scan tuning - please enter new command");
    }
  }

  campaign = getCampaign();
  muzzle = getMuzzle();
  muzzle = "1206VINI";
  
  if (verbos) {
    Serial.println("  campaign: " + campaign);
    Serial.println("  muzzle: " + muzzle);
  }

  // reset the global SPECTRO arrays
  memset(SPECTRO_integration_times, 0, sizeof(SPECTRO_integration_times));
  memset(SPECTRO_start_pixels, 0, sizeof(SPECTRO_start_pixels));
  memset(SPECTRO_end_pixels, 0, sizeof(SPECTRO_end_pixels));

  // Set the channels - must be before the scan tuning
  if (sensor == "c12880ma") {
    SPECTRO_CHANNELS=288; // Nr of spectral channels in sensor
    START_CHANNEL=0; // First channel with valid data
    END_CHANNEL=288; // Last channel with valid data
  } else if (sensor == "c14384ma-01") {
    SPECTRO_CHANNELS=256; // Nr of spectral channels in sensor
    START_CHANNEL=64; // First channel with valid data
    END_CHANNEL=256; // Last channel with valid data
  } else {
    SPECTRO_CHANNELS=0; // Nr of spectral channels in sensor
    START_CHANNEL=0; // First channel with valid data
    END_CHANNEL=0; // Last channel with valid data
  }
  
  // Connect to the Hamamatsu mini spectral sensor
  if (!HamamatsuConnected){
    connectHamamatsu();
    // Get the calibrated waveleoghts
    hamamatsuWavelenghts(START_CHANNEL, END_CHANNEL, waveLenghtsNanometer);
  }

  samplerepeats = getNumberOfSampleRepeats();

  darkrepeats = getNumberOfDarkRepeats();

  warmup = getNumberOfWarmUp();

  headtrail = getNumberOfHeadTrail();  
} /* END HamamatsuScanParameters*/

void PrintScanParameters(){
  Serial.println("\n  Spectral scan parameter settings: ");
  Serial.println("    sensor: " + sensor);
  Serial.println("    campaign: " + campaign);
  Serial.print("    verbosity: ");
  Serial.println(verbos);
  Serial.print("    operation: ");
  Serial.println(operation);
  Serial.print("    returnformat: ");
  Serial.println(returnformat);
  Serial.print("    sample repeats: ");
  Serial.println(samplerepeats);
  Serial.print("    dark repeats: ");
  Serial.println(darkrepeats);
  Serial.print("    headtrail: ");
  Serial.println(headtrail);
  Serial.print("    warmup: ");
  Serial.println(warmup);
  Serial.print("    maxDN: ");
  Serial.println(maxDN);
  Serial.println("    muzzle: " + muzzle);
  Serial.print("    vset_mV: ");
  Serial.println(vset_mV);
  Serial.print("    fetchWhiteRef: ");
  Serial.println(fetchWhiteRef);
  Serial.print("    fetchScanTuning: ");
  Serial.println(fetchScanTuning);
  Serial.print("    stabilisationTime: ");
  Serial.println(stabilisationTime);
  Serial.print("    nIntegrationTimes: ");
  Serial.println(nIntegrationTimes);  
} /* END PrintScanParameters*/

void MetaData(String sensor, int samplerepeats, int darkrepeats, int headtrail, int warmup, int maxDN, String muzzle, int vset_mV, 
    int stabilisationTime, int nIntegrationTimes) {
  Serial.print("metadata=");
  String jsonString = SerialiseScanTuning(sensor, samplerepeats, darkrepeats, headtrail, warmup, maxDN, muzzle, vset_mV, 
    stabilisationTime, nIntegrationTimes, SPECTRO_integration_times, SPECTRO_start_pixels, SPECTRO_end_pixels );
  Serial.println("EndMetaData");
}

/*
  param0: sensor (e.g. c12880ma)
  param1 = campaign = uuid:
  param2: verbose (0 = quiet, 1 = verboe, 2 = more verbose)
  param3; operation 
   0 = test scan; 
   1 = sample scan; 
   2 = set/update default auto scan tuning; 
   3 = set/update default fixed scan tuning; 
   4 = set/update named scan tuning; 
   6 = adjust scan tuning integration times;
   7 = set/update default white ref; 
   8 = set/update named white ref;  
   9 = test scan with options;

   26 = set/update default auto scan tuning + adjust scan tuning integration times
   36 = set/update default fixed scan tuning + adjust scan tuning integration times
   46 = set/update named scan tuning + adjust scan tuning integration times
   

   27 = (2+7) set/update default auto scan tuning + whiteref; 
   37 = (3+7) set/update default fixed scan tuning + whiteref;

   267 = (2+6+7) set/update default auto scan tuning + adjust scan tuning integration times + whiteref;
   
   47 = set/update named scan tuning + whiteref;

   125 = sample scan with default scan tuning + whiteref;
 
   145 = sample scan with named scan tuning + 

   129 = sample scan with default scan tuning + in-sampling whiteref;

   149 = sample scan with namedscan tuning + in-sampling whiteref;
   
   92 = test scan with default scan tuning
   94 = test scan with named scan tuning
   
   11 = read scan tuning, 12 = read whiteRef, 13 read and test campaign scan tuning, 
       
  ### param 4 to 8 not required is the scantuning is set to auto
  param4: return (0 = mean % std, 1 = full data)
  param5; nr sample Repeats, default = 6
  param5; nr darkRepeats, default = 6
  param7; nr headtrail, default = 2
  param8; warmup, defaut = 6
  param9 = maxDN = 800:

  ### From here on the params are only for spectral scanning       
  param10 = muzzle = 1206VINI:
  param11 = vset_mV = 1500:
  param12 = fetchWhiteRef: 0 = none, 1 = in-sampling, 2 = campaign white ref, 3 = muzzle white ref; 4 = automatic; 5 = file; 
  param13 = fetchScanTuning: 0 = none; 1 = user defined, 2 = campaign default, 3 = muzzle default; 4 = automatic; 5 = file; 
  param14 = stabilisationTime = 200;
  param15 = nIntegrationTimes = 3:

  // Automatic scan tuning
  param16 = iniIntegrationtime = 200:
  param17 = ascendingstep = 20:
  param18 = descendingstep = 5:

  // Params if operation expects filename 
  param19 = filename = /path/to/file.json

  // Params if operation in [7, 8 27, 28] or operation in [0,1] and get integrationtime = 0
  param16 = integrationsTime0 = 200:
  param17 = startPixelIntegrationTime0 = 64:
  param18 = endPixelIntegrationTime0 = 256:

  param19 = integrationsTime1 = 200:
  param20 = startPixelIntegrationTime1 = 89:
  param21 = endPixelIntegrationTime1 = 200:

  oaram22 = integrationsTime2 = 200:
  param23 = startPixelIntegrationTime2 = 89:
  param24 = endPixelIntegrationTime2 = 200:

  param25 = integrationsTime3 = 200:
  param26 = startPixelIntegrationTime3 = 89:
  param27 = endPixelIntegrationTime3 = 200:  

  param28 = integrationsTime4 = 200:
  param29 = startPixelIntegrationTime4 = 89:
  param30 = endPixelIntegrationTime4 = 200:
*/

/* Main function for hamamatusMini */
void HamamatsuGratingSensor(){
  /* Manual scanning
   * <sensor;campaign;verbos;operation;returnformat;samplerepeats;darkrepeats,headtrail;warmup;maxDN;muzzle;vset_mV;fetchWhiteRef;fetchScanTuning;stabilisationTime;nIntegrationTimes;integrationTime0;startPixel0;endPixel0;integrationTime1;startPixel1;endPixel1>
   * <sensor, campaign,verbos,operation,returnformat,samperepeats,darkrepeats,headtrail,warmup,maxDN,muzzle,vset_mV,fetchwhiteref,fetchscantuning,stabilisationtime,nIntegrationTimes
   * Automatic scan tuning
   * <sensor;campaign;verbos;operation;returnformat;samplerepeats;darkrepeat,headtrail;warmup;maxDN; muzzle;vset_mV;fetchWhiteRef;fetchScanTuning;stabilisationTime;nIntegrationTimes;initIntegrationTime;ascendingstep;descendingstep>
   * Examples:
   * op=0 Manual testscan, verbos 1, 4 warmups, 2 repeats:                          <c14384ma-01;campaign;1;0;0;2;1;0;4;800;1206VINI;2500;0;1;200;1;200;64;256>
   * op=0 Manual testscan, verbos 2, 4 warmups, 2 repeats 1 darkrepeat 1 headtrail: <c14384ma-01;campaign;2;0;0;2;1;1;4;800;1206VINI;2500;0;1;200;1;200;64;256>
   * 
   * <c14384ma-01;campaign;2;0;0;2;1;1;0;800;1206VINI;2700;0;1;200;3;38;111;157;65;82;187;166;64;256>
   * 
   * <c14384ma-01;campaign;2;0;0;2;1;1;0;800;1206VINI;2900;0;1;200;4;6;111;157;14;82;187;45;78;215;200;64;256>
   * 
   * MGG lamp
   * <c14384ma-01;campaign;2;0;0;2;1;1;0;800;1206VINI;2900;0;1;200;4;60;111;157;140;82;187;450;78;215;2000;64;256>
   * 
   * <c12880ma;campaign;2;0;0;2;1;1;0;800;1206VINI;2900;0;1;200;4;40;111;157;100;82;187;250;78;215;400;0;288>400;15;110
   * <c12880ma;campaign;2;0;0;2;1;1;0;800;1206VINI;4000;0;1;200;1;200;0;288>
   * <c12880ma;campaign;2;0;0;2;1;1;0;800;1206VINI;2900;0;1;200;1;200;0;288>
   * <c12880ma;campaign;2;0;0;2;1;1;0;800;1206VINI;1500;0;1;200;1;200;0;288>
   * <c12880ma;campaign;2;0;0;2;1;1;0;800;1206VINI;2900;0;1;200;2;400;15;110;200;0;288>
   * 
   * op=0 Manual testscan, verbos 2, 4 warmups 2 repeats 1 darkrepeat 1 headtrail 2 integrationtimes: <c14384ma-01;campaign;2;0;0;2;1;1;4;800;1206VINI;2700;0;1;200;2;80;64;256;5;128;188>
   *  
   * 
   * op=2 set/update campaign auto scan tuning; <c14384ma-01;campaign;2;2;0;6;2;1;2;800;1206VINI;2700;4;4;200;3;5;2;1>
   * 
   * op=3 set/update default fixed scan tuning with adjustment; <c14384ma-01;campaign;1;3;0;6;2;1;6;800;1206VINI;2400;4;4;200;3;330;104;179;555;90;203;1344;64;256>
   * 
   * op=36 set/update default fixed scan tuning with adjustment; <c14384ma-01;campaign;1;36;0;6;2;1;6;800;1206VINI;2400;4;4;200;3;330;104;179;555;90;203;1344;64;256>
   *                                                           
   * 
   * op=5 set/update default white ref; <c14384ma-01;campaign;1;7;0>
   * 
   * op=92, read settings from campaign auto scan tuning; <c14384ma-01;campaign;1;92;0>
   */
      
  // Get the spectral scanning parameters
  HamamatsuScanParameters();
  
  //Serial.println("\n  Start of spectra scan\n");
  
  if (operation == 0) {
    // op0 = test scan
    
    setSpectralScanTuning();
    if (verbos) {
      PrintScanParameters();
      PrintScanTuning();
    }
    
    if (warmup){
      LampWarmUp(vset_mV, warmup);
    }

    hamamatsu_spectra_scan(headtrail, samplerepeats, darkrepeats, nIntegrationTimes);

    MetaData(sensor, samplerepeats, darkrepeats, headtrail, warmup, maxDN, muzzle, vset_mV, 
    stabilisationTime, nIntegrationTimes);
    
  } else if (operation == 2) { // set/update campaign auto scan tuning
    //String jsonString;
    
    setSpectralScanTuning();
    String scanTuningFPN = "/scantuning/" + sensor + "/" + campaign + "/" + muzzle + "/defaultScanTuning.json";
    String jsonString = SerialiseScanTuning(sensor, samplerepeats, darkrepeats, headtrail, warmup, maxDN, muzzle, vset_mV, 
      stabilisationTime, nIntegrationTimes, SPECTRO_integration_times, SPECTRO_start_pixels, SPECTRO_end_pixels );
    // Set the spectral scan tuning

     Serial.println("  jsonString:" + jsonString);
     Serial.println("  scanTuningFPN:" + scanTuningFPN);
     WriteFile(scanTuningFPN, jsonString);

  } else if ((operation == 3) or (operation == 36)) { // set/update default fixed scan tuning with adjustment
    //String jsonString;
    String scanTuningFPN = "/scantuning/" + sensor + "/" + campaign + "/" + muzzle + "/defaultScanTuning.json";

    // Set the spectral scan tuning
    setSpectralScanTuning();

    // Assemble the tuned scan setting
    String jsonString = SerialiseScanTuning(sensor, samplerepeats, darkrepeats, headtrail, warmup, maxDN, muzzle, vset_mV, 
      stabilisationTime, nIntegrationTimes, SPECTRO_integration_times, SPECTRO_start_pixels, SPECTRO_end_pixels );

    // Write tuning to file
    WriteFile(scanTuningFPN, jsonString);

  } else if (operation == 7) { // set/update default whiteref
    //First get the scan tuning
    
    String scanTuningFPN = "/scantuning/" + sensor + "/" + campaign + "/" + muzzle + "/defaultScanTuning.json";
    String scanTuningString = SerialiseScanTuning(sensor, samplerepeats, darkrepeats, headtrail, warmup, maxDN, muzzle, vset_mV, 
    stabilisationTime, nIntegrationTimes, SPECTRO_integration_times, SPECTRO_start_pixels, SPECTRO_end_pixels );

    Serial.println("  scanTuningString:" + scanTuningString);
    Serial.println("  scanTuningFPN:" + scanTuningFPN);

    Serial.println("  Ready to run white reference");

    samplerepeats = TunedScanSampleRepeats;

    darkrepeats = TunedScanDarkRepeats;

    warmup = TunedScanWarmup;

    headtrail = TunedScanHeadTrail;

    String importversion = "importxspectrev080";
    String theme = "whiteref";
    String family = "xspectre";
    String verson = "202311";
    String scandatetime = "20230627";
    String product = "stats-spectra";
    String sampleid = "default";

    //String jsonString = SerialiseWhiteRef( campaign, importversion, theme, family, verson, scandate, product, sampleid, scanTuningString );

    hamamatsu_spectra_scan(headtrail, samplerepeats, darkrepeats, nIntegrationTimes);

  } else if (operation == 92) {
    
    samplerepeats = TunedScanSampleRepeats;

    darkrepeats = TunedScanDarkRepeats;

    warmup = TunedScanWarmup;

    headtrail = TunedScanHeadTrail;

    hamamatsu_spectra_scan(headtrail, samplerepeats, darkrepeats, nIntegrationTimes);
 
  } else {

    delay(5000);
    
    // Get the battery status - if battery is below vset_mV the spectral scan is not done
    adcvalue = analogRead(PIN_VBAT);
    vbat=(float)adcvalue * mv_per_lsb *2;
                        
    hamamatsu_spectra_scan(headtrail, samplerepeats, darkrepeats, nIntegrationTimes);
  
    if ((operation == 2) || (operation == 3)){
      String dstFPN = "/scantuning/" + sensor + "/" + campaign + "/" + muzzle + "/defaultScanTuning.json";
      //String filecontent = 
      //<writedata4fs;1;1;/scantuning/1101VIS_trucomp_1590331_3.json;{"sensor":"c14384ma-01","muzzle":"1101VIS","lamp":"trucomp_1590331","Vin":2950,"maxDN":800,"stabilisationTime":200,"nIntegrationTimes":3,"0":[300,100,200],"1":[600,80,225],"2":[900,64,256]}> 
      SaveScanTuningToFS(); 
      //SaveWhiterfe
    }
    if ((operation == 8) || (operation == 9)){
      SaveScanTuningToFS(); 
      //SaveWhiterfe
    }                            
  }
  
}
      
