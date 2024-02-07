/* parameters
 * created 18 Oct 2023 
 * last update 18 oct 2023
 * 
 * Manage variables initiated from Desktop or Bluetooth
 * 
 * 
 * Core variables in argument
 * 0 - sensor
 * 1 - repeats
 * 2 - verbose
 * ...
 */
String paramString = "";
bool action = false;

const String SENSOR = "";
const uint8_t VERBOSE = 0;
const String CAMPAIGN = "";
const uint8_t OPERATION = 0;
const uint8_t REPEATS = 6;
const uint8_t HEADTRAIL = 2;
const uint8_t WARMUP = 6;
const uint8_t RETURNFORMAT = 0;

bool getAction() {
  return action;
}

void turnOffAction() {
  action = false;
}

/* Generic parameters for all sensors */

String getSensor() {
  String param = getValue(0);
  return param.length() > 0 ? param : SENSOR;
}

String getCampaign() {
  String param = getValue(1);
  return param.length() > 0 ? param : CAMPAIGN;
}

uint8_t getVerbos() {
  String param = getValue(2);
  return param.length() > 0 ? param.toInt() : VERBOSE;
}

int getOperation() {
  String param = getValue(3);
  return param.length() > 0 ? param.toInt() : OPERATION;
}
/* Hamamatsu sensor parameters 
   0 = test scan; 1 = sample scan;  2 = set/update campaign auto scan tuning; 3 = set/update muzzle auto scan tuning;
   4 = set/update campaign fixed scan tuning; 5 = set/update muzzle fixed scan tuning;
   6 = set/update campaign white ref; 7 = set/update muzzle white ref;
   26 = set/update campaign auto scan tuning + campaign white ref; 46 = set/update campaign fixed scan tuning + campaign white ref;
   37 = set/update muzzle auto scan tuning + muzzle white ref; 57 = set/update muzzle fixed scan tuning + muzzle white ref.*/

uint8_t getReturnFormat() {
  String param = getValue(4);
  return param.length() > 0 ? param.toInt() : RETURNFORMAT;
}

/* REPEATS, HEADTRAIL and WARMUP are all limited to different numerical values */
uint8_t getNumberOfSampleRepeats() {
  String param = getValue(5);
  if  ( param.length() > 0){
    if (param.toInt() > 6) {
      return 6;
    } else {
      return param.toInt();
    } 
  } else {
    return REPEATS;
  }
}

uint8_t getNumberOfDarkRepeats() {
  String param = getValue(6);
  if  ( param.length() > 0){
    if (param.toInt() > 6) {
      return 6;
    } else {
      return param.toInt();
    } 
  } else {
    return REPEATS;
  }
}

/* HeadTrail is doubled when setting the scna repeats, thus imited to 3  */
uint8_t getNumberOfHeadTrail() {
  String param = getValue(7);
  if  ( param.length() > 0){
    if (param.toInt() > 3) {
      return 3;
    } else {
      return param.toInt();
    } 
  } else {
    return HEADTRAIL;
  }
}

uint8_t getNumberOfWarmUp() {
  String param = getValue(8);
  if  ( param.length() > 0){
    if (param.toInt() > 12) {
      return 12;
    } else {
      return param.toInt();
    } 
  } else {
    return WARMUP;
  }
}

int getMaxDN() {
  String param = getValue(9);
  return param.toInt();
}

/* End of generic parameters for all sensors */

/* Specific parameters for spectral sensors */

String getMuzzle() {
  String param = getValue(10);
  return param;
}

/* vset_mV is given in milli Volt */
int getVset_mV() {
  String param = getValue(11);
  return param.toInt();
}

int getWhiteRef() {
  String param = getValue(12);
  return param.toInt();
}
/* whiteRef: 0 = none; 1 = in-sampling; 2 = campaign white ref; 3 = muzzle white ref; 4 = automatic; 5 = file */

int getScanTuning() {
  String param = getValue(13);
  return param.toInt();
}
/* ScanTuning: 1 = user defined, 2 = campaign default, 3 = muzzle default; 4 = automatic; 5 = file*/

/* Stabilisationtime in milli seconds -  */
int getStabilisationTime(){
  String param = getValue(14);
  return param.toInt();  
}

/* Nr of integration times */
int getNrOfIntegrationTimes(){
  String param = getValue(15);
  return param.toInt();
}

/* if operation is set to automatic tuning of integration time */
int getInitialTuningIntegrationTime(){
  String param = getValue(16);
  return param.toInt();
}

int getAscendingTuningStep(){
  String param = getValue(17);
  return param.toInt();
}

int getDescendingTuningStep(){
  String param = getValue(18);
  return param.toInt();
}

/* END if operation is set to automatic tuning of integration time */

/* if operation is set to automatic tuning of integration time */
int getManualIntegrationTime(uint8_t timeNr ){
  if ((timeNr == 16) || (timeNr == 19) || (timeNr == 22) || (timeNr == 25)  || (timeNr == 28)) {
    String param = getValue(timeNr);
    return param.toInt();
  } else {
    return 0;
  } 
}

int getManualStartPixel(uint8_t  startPixelNr){
  if ((startPixelNr == 17) || (startPixelNr == 20) || (startPixelNr == 23) || (startPixelNr == 26) || (startPixelNr == 29)) {
    String param = getValue(startPixelNr);
    return param.toInt();
  } else {
    return 0;
  }
}

int getManualEndPixel(uint8_t endPixelNr){
  if ((endPixelNr == 18) || (endPixelNr == 21) || (endPixelNr == 24) || (endPixelNr == 27) || (endPixelNr == 30)) {
    String param = getValue(endPixelNr);
    return param.toInt();
  } else {
    return 0;
  }
}


/* if operation is set to manual
tuning of integration time */

String getSensorSettingFilePath() {
  String param = getValue(16);
  return param;
}

int getParameterInt(int paramNr){
  String param = getValue(paramNr);
  return param.toInt();
}

String getParameterStr(int paramNr){
  String param = getValue(paramNr);
  return param;
}
 
/* START receive commands */

const int SerialBufferSize = 1024;

char receivedChars[SerialBufferSize];   // an array to store the received data

void recvWithStartEndMarkers() {
    boolean newData = false;
    static boolean recvInProgress = false;
    static int ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();
        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= SerialBufferSize) {
                    ndx = SerialBufferSize - 1;
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
    if (newData) {
      paramString = String(receivedChars);
      action = true;
    }
}

String getValue(int index){
  if (paramString.length() == 0) return "";
  char separator = ';';
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = paramString.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (paramString.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
  }
  return found > index ? paramString.substring(strIndex[0], strIndex[1]) : "";
}

String getAnyValue(String paramStr, char separator, int index){
  if (paramStr.length() == 0) return "";

  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = paramStr.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (paramStr.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
  }
  return found > index ? paramStr.substring(strIndex[0], strIndex[1]) : "";
}

/* END receive commands */

void showCoreParams() {
  /*
  int errorCode = initiateLedLum();
  if (errorCode > 0) {
    Serial.println(utilGetError(errorCode));
  } else {
  */
  if ( getVerbos() ) {
    Serial.println("\n\nPROCESSING");
    Serial.print("  Sensor: ");
    Serial.println(getSensor());
    Serial.print("  verbos: ");
    Serial.println(getVerbos());
    if ( getVerbos() > 1 ) {
      Serial.print("  paramString: ");
      Serial.println(paramString);
    }
    Serial.println();   
  }
}
