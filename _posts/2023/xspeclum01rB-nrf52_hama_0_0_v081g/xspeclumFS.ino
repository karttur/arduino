#include <Adafruit_LittleFS.h>
#include <InternalFileSystem.h>

using namespace Adafruit_LittleFS_Namespace;

File file(InternalFS);

String FP;
String FPN;
String fileContents;

String rawContents;

int fileread = 0;

#define MAX_LEVEL   2 //maximum levels of directories in internal file system

bool fileSystemInitiated = false;

void setupFileSystem() {
  if(!fileSystemInitiated) {
    InternalFS.begin();
    fileSystemInitiated = true;
  }
}

void RemoveFiles(int nscans){
  /* Remove files from flash memory
  Loops over the nscans = "n files to remove", and remove the indicated files if they exist*/
  setupFileSystem();
  
  for (int i=0; i< nscans; i++){
    FPN = getValue(i+3);
    if (verbos) {
      Serial.println("  Removing: " + FPN);
    }

    // Convert FPN from String to Char array
    int str_len = FPN.length() + 1;
    char FPNCharArr[str_len];
            
    FPN.toCharArray(FPNCharArr, str_len);

    if ( InternalFS.exists(FPNCharArr) ) {
      // remove file
      InternalFS.remove(FPNCharArr);
    } else {
      Serial.println("    File does not exists on flash");   
    }
    
  }

  Serial.println("\nRemaining files on flash:\n");
          
  // Print whole directory tree fwon to level 2
  printTreeDir("/", 2); 
  
} // RemoveFiles

void MkDirs(int nscans){
  // Loop over the nscans = "n dirs to make", and create the directories
  setupFileSystem();
  String FP;
  
  for (int i=0; i< nscans; i++){

    FP = getValue(i+3);
    if (verbos) {
      Serial.println("Making directory: " + FP);
    }
    // Convert FPN from String to Char array
    int str_len = FP.length() + 1;
    char FPCharArr[str_len];
        
    FP.toCharArray(FPCharArr, str_len);

    // Make directory
    InternalFS.mkdir(FPCharArr);
  }
} // MkDirs
         
void RemoveDirs(int nscans){
  //
  setupFileSystem();
  String FP;

  // Loop over the nscans = "n files to remove", and remove
  for (int i=0; i< nscans; i++){
  
    FP = getValue(i+3);
    if (verbos) {
      Serial.println("  Removing: " + FP);
    }

    // Convert FP from String to Char array
    int str_len = FP.length() + 1;
    char FPCharArr[str_len];       
    FP.toCharArray(FPCharArr, str_len);

    bool dirExist = false;
    dirExist = InternalFS.exists(FPCharArr);
        
    if (dirExist) {
      // remove dir
      InternalFS.rmdir(FPCharArr);
    } else {
      Serial.println("    directory does no exists on flash");   
    }
  }
  Serial.println("\nRemaining files on flash:\n");
          
  // Print whole directory tree fwon to level 2
  printTreeDir("/", 2);
  
} // RemoveDirs
      
String ReadFile(String FPN){
  setupFileSystem();

  if (verbos) {
    Serial.println("  Reading file:" + FPN);
  }
      
  // Convert FPN from String to Char array
  int str_len = FPN.length() + 1;
  char FPNCharArr[str_len];
  FPN.toCharArray(FPNCharArr, str_len);

  // Set fileread to false (0)
  fileread = 0;

  fileContents = "";

  if ( InternalFS.exists(FPNCharArr) ){

    file.open(FPNCharArr, FILE_O_READ);
  
    char buffer[256] = { 0 };
  
    if ( file ) {
      
      uint32_t readlen;
      
      readlen = file.read(buffer, sizeof(buffer));
  
      buffer[readlen] = 0;
  
      if (verbos > 1) {
        Serial.print("    file content: ");
        Serial.println( buffer);
      }
  
      for ( int i = 0; i < readlen; i++){
        fileContents += buffer[i];
      }
    
      file.close();
      
      fileread = 1;
    } 

    if (fileread) {

      fileread = 0;

      return fileContents; 
    
    /* 
      // Get the directory path revealing the type of (json) file
      FP = getAnyValue(FPN, '/', 1);
 
      if (FPN == "/sensors.json"){    
        DeSerialiseSensorsJson(fileContents);
      }
          
      else if (FP == "spectralsensors") {    
        DeSerialiseSpectralSensorJson(fileContents);
      }
      /*
      else if (FP == "modbussensors") {   
        DeSerialiseModbusSensorJson(fileContents);     
      }
      
      else if (FP == "i2csensors") {   
        DeSerialiseI2CSensorJson(fileContents);     
      }

      else if (FP == "analogsensors") {   
        DeSerialiseAnalogSensorJson(fileContents);     
      }

      else if (FP == "isesensors") {   
        DeSerialiseIseSensorJson(fileContents);     
      }

      else if (FP == "scantuning") {   
        DeSerialiseScanTuningJson(fileContents);     
      }

      else if (FP == "scandata") {   
        DeSerialiseScanDataJson(fileContents);     
      }
      */
    } else {
       Serial.println("    File not read - unknown error");  
       return "-1";      
    }
  } else {
    Serial.println("    File does not exist on flash memory"); 
    return "-2";
  }
   
} // ReadFile


void WriteFileFromUser(int nscans){
  String filePath;
  String fileContents;
  
  setupFileSystem();
  //

  for (int i=0; i< nscans; i++){

    filePath = getValue(3+i);
    // Get the file content to write
    fileContents = getValue(4+i);

    WriteFile(filePath, fileContents);
  }
}
    

void WriteFile(String filePath, String fileContents){
  setupFileSystem();
  //

  //for (int i=0; i< nscans; i++){

    //FPN = getValue(3+i);
    
    if (verbos) {
      Serial.println("  Accessing file: " + filePath);
    }
  
    // Convert FPN from String to Char array
    int str_len = filePath.length() + 1;
    char FPNCharArr[str_len];
    filePath.toCharArray(FPNCharArr, str_len);
        
    if (verbos) {
      Serial.println("  Contents to write: " + fileContents);
    }
  
    // Convert fileContents from String to Char array
    str_len = fileContents.length() + 1;
    char ContentCharArr[str_len];
    fileContents.toCharArray(ContentCharArr, str_len);
    
    bool removeFile = false;
    bool writeFile = false;
  
    file.open(FPNCharArr, FILE_O_READ);
  
    if ( file ) {
  
      Serial.print("\n  file already exists: ");
      Serial.print( FPNCharArr );
  
      uint32_t readlen;
      char buffer[1024] = { 0 };
      readlen = file.read(buffer, sizeof(buffer));
  
      buffer[readlen] = 0;
      Serial.print("\n  Existing file content: ");
      Serial.println( buffer);
      file.close();
  
      if (!verbos) {
        Serial.println("  New Content to write: " + fileContents);
      }
  
      // Ask if file is to be overwritten
      //newData = false;
      action = false;
  
      Serial.println("\n  Press <Y> to overwrite <N> to keep");
    
      //while ( !newData )
      while(!getAction()){
        delay(1);
        // Listen for input string
        recvWithStartEndMarkers();
      }
      
      //if (newData == true) {
      if (getAction()){
        
        inString = String(receivedChars);
    
        if (inString == "Y"){
          removeFile = true;
          writeFile = true;
        }
        
      }
      
    } else {
      writeFile = true;
      removeFile = false;
    }
    
    if (removeFile){
      InternalFS.remove(FPNCharArr);
    }
  
    if (writeFile) {
      if( file.open(FPNCharArr, FILE_O_WRITE) )
      {
        
        //const char* charContents = contents.c_str();
        file.write(ContentCharArr, strlen(ContentCharArr));
        file.close();
        Serial.println("    File creted/updated");
      }else{
        Serial.println("  Failed!");
      }
    }
  
    Serial.println("");
    
  //}
  
} // WriteFile



void RenameFile(int nscans){
  setupFileSystem();
  //

  String srcFPN;
  String dstFPN;
  
  srcFPN = getValue(3);
  if (verbos) {
    Serial.println("Renaming file:" + srcFPN);
  }

  // Convert FPN from String to Char array
  int str_len = srcFPN.length() + 1;
  char srcFPNCharArr[str_len];
  srcFPN.toCharArray(srcFPNCharArr, str_len);

  dstFPN = getValue(4);
  if (verbos) {
    Serial.println("to:" + dstFPN);
  }

  // Convert FPN from String to Char array
  str_len = dstFPN.length() + 1;
  char dstFPNCharArr[str_len];
  dstFPN.toCharArray(dstFPNCharArr, str_len);

  if ( InternalFS.exists(srcFPNCharArr) ) {

    if ( InternalFS.exists(dstFPNCharArr) ) {

      Serial.println("\n  Press <Y> to overwrite <N> to keep");
    
      while ( !getAction() )
      {
        delay(1);
        // Listen for input string
        recvWithStartEndMarkers();
      }
      
      //if (newData == true) {
      if (getAction()){
        
        inString = String(receivedChars);
    
        if (inString == "Y"){
          InternalFS.remove(dstFPNCharArr);

          InternalFS.rename(srcFPNCharArr, dstFPNCharArr);
        }
        
      } else {
        Serial.println("\n  Source file not copied as target already esists");    
      }
      
    } else {

      InternalFS.rename(srcFPNCharArr, dstFPNCharArr);
      
    }

  } else {
    Serial.println("\n  Source file for renaming does not exists - skipping");
  }
      
  Serial.println("");
} // RenameFile

void printTreeDir(const char* cwd, uint8_t level){
  setupFileSystem();
  // Open the input folder
  File dir(cwd, FILE_O_READ, InternalFS);

  // Print root
  if (level == 0) Serial.println("root");
 
  // File within folder
  File item(InternalFS);

  // Loop through the directory 
  while( (item = dir.openNextFile(FILE_O_READ)) )
  {
    // Indentation according to dir level
    for(int i=0; i<level; i++) Serial.print("|  ");

    Serial.print("|_ ");
    Serial.print( item.name() );

    if ( item.isDirectory() )
    {
      Serial.println("/");

      // ATTENTION recursive call to print sub folder with level+1 !!!!!!!!
      // High number of MAX_LEVEL can cause memory overflow
      if ( level < MAX_LEVEL )
      {
        char dpath[strlen(cwd) + strlen(item.name()) + 2 ];
        strcpy(dpath, cwd);
        strcat(dpath, "/");
        strcat(dpath, item.name());
        
        printTreeDir( dpath, level+1 );
      }
    }else
    {
      // Print file size starting from position 30
      int pos = level*3 + 3 + strlen(item.name());

      // Print padding
      for (int i=pos; i<30; i++) Serial.print(' ');

      // Print at least one extra space in case current position > 50
      Serial.print(' ');
      
      Serial.print( item.size() );
      Serial.println( " Bytes");
    }

    item.close();
  }

  dir.close();
} //printTreeDir

void SaveScanTuningToFS(){
  
  String dstRootFN = getParameterStr(15);
  
  String scanTuningDstFPN = "/scantuning/" + dstRootFN + "_scantuning_n" + String(nIntegrationTimes) + ".json";
  String whiteRefDstFPN = "/scantuning/" + dstRootFN + "_whiteref_n" + String(nIntegrationTimes) + ".json";

  Serial.println("  scanTuningDstFPN: " + scanTuningDstFPN);
  Serial.println("  whiteRefDstFPN: " + whiteRefDstFPN);

  value_print_Main_spectra_dark(sensor, START_CHANNEL, END_CHANNEL); 
}


void procsessLittleFS(String sensor){
  
  // Initialize Internal File System
  setupFileSystem();

  int nItems = getNumberOfSampleRepeats();
  
  if (sensor == "removefiles4fs"){
      // example code diagnostic run delete files in file system: <removefiles4fs;5;1;sensors.txt;mainsensor.txt;c14384ma-01.json;1101VIS_trucomp_1590331.json;adafruit.txt>
      // nscans = number of files (items separates by ";" after the initial 3 parameters)

      RemoveFiles(nItems); 
      
    } else if (sensor == "removedirs4fs"){
      // example code diagnostic run delete dirs in file system: <removedirs4fs;2;1;testdir;i2csensors>
      // nscans = number of files (items separates by ";" after the initial 3 parameters)

      RemoveDirs(nItems); 
        
    } else if (sensor == "listfiles4fs"){
      // example code diagnostic run write sensors to file system: <listfiles4fs;2;1>
      // nscans = max hierarchical level to print
      
      printTreeDir("/", nItems);
        
    } else if (sensor == "mkdirs4fs"){
      // example code diagnostic run make dirs to file system: <mkdirs4fs;7;1;spectralsensors;modbussensors;i2csensors;analogsensors;isesensors;scantuning;scandata>

      //<mkdirs4fs;1;1;/scantuning/c14384ma-01/campaign/1206VINI>
      //<mkdirs4fs;1;1;/scantuning/c14384ma-01>
  
      MkDirs(nItems);
              
    } else if (sensor == "writedata4fs"){  
      // example code diagnostic run write sensors to file system: <writedata4fs;1;1;/sensors.json;{"spectralsensors":["c14384ma-01"],"modbussensors":["tsmnpkph","ph"],"i2csensors":["mhz16","ams6bandnir"],"analogsensors":["capacitive_sm","mic"],"isesensors":["ph"]}>
      // example code diagnostic run c14384ma-01 calibration sensors to file system: <writedata4fs;1;1;/spectralsensors/c14384ma-01.json;{"sensor":"c14384ma-01","source":"Hamamatsu","serialnr":"20J00751","pixels":256,"bands":192,"startpixel":64,"endpixel":256,"Vin":5,"wlcalibration":[164.4638893,6.504915196,-0.01776057311,0.00007644566137,-3.418545472e-7,5.622808731e-10]}>
      // <writedata4fs;1;1;/spectralsensors/c12880ma.json;{"sensor":"c12880ma","source":"Hamamatsu","serialnr":"22K03828","pixels":288,"bands":288,"startpixel":0,"endpixel":288,"Vin":3.0,"wlcalibration":[300.7222380,2.702125865,-0.001042606675,-8.737096786E-06,1.363190023E-08,-1.047236568E-12]}>
      // example code diagnostic light tuning to file system: <writedata4fs;1;1;/scantuning/1101VIS_trucomp_1590331.json;{"sensor":"c14384ma-01","muzzle":"1101VIS","lamp":"trucomp_1590331","Vin":2950,"nIntegrationTimes":3,"0":[300,100,200],"1":[600,80,225],"2":[900,64,255]}>
      // example code diagnostic light tuning to file system: <writedata4fs;1;1;/scantuning/1101VIS_trucomp_1590331_3.json;{"sensor":"c14384ma-01","muzzle":"1101VIS","lamp":"trucomp_1590331","Vin":2950,"maxDN":800,"stabilisationTime":200,"nIntegrationTimes":3,"0":[300,100,200],"1":[600,80,225],"2":[900,64,256]}>

      WriteFileFromUser(nItems);
      
   } else if (sensor == "readdata4fs"){ 
      // example code diagnostic run read sensors from file system: <readdata4fs;1;1;/sensors.json>
      // example code diagnostic run read c14384ma-01 from file system: <readdata4fs;1;1;/spectralsensors/c14384ma-01.json>
      // example code diagnostic run read scantuning with nozzel+lamp from file system: <readdata4fs;1;1;/scantuning/1101VIS_trucomp_1590331.json>

      // example code diagnostic run read scantuning with nozzel+lamp from file system: <readdata4fs;1;2;/scantuning/1101VIS_trucomp_1590331_3.json>
      //<readdata4fs;1;2;/scantuning/c14384ma-01/campaign/1206VINI/defaultScanTuning.json>
      //<readdata4fs;1;2;/spectralsensors/c12880ma.json>

      String fileContent = ReadFile( getValue(3) );

      if (verbos > 1) {
        Serial.print("    file content: ");
        Serial.println( fileContent);
      }
 
   } else if (sensor == "renamedata4fs"){ 
      // example code diagnostic run read sensors from file system: <renamedata4fs;1;1;/sensors.json;/sensors_backup.json>

      // Read the file - the data is saved in the global variable fileContents
      RenameFile(verbos);
 
   }
}
