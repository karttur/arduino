/*
 * 
 * 
 * 
 * 
 */

/* Set the RS485 MODBUS steel-pin sensors */
String rs485ModBusSensor = "npk-s";

 /* START Modbus setup for communication with RS485+MODBUS sensors 
#include <ModbusMaster.h> 

void PreTransmission(){
  // Set transmit mode
  digitalWrite(nRE, HIGH);
}

void PostTransmission(){
  // Set receive mode
  digitalWrite(nRE, LOW);
}

// instantiate ModbusMaster object
ModbusMaster node;

 END ModbusMaster For communication with RS485+MODBUS sensors 


  if ( (rs485ModBusSensor == "npkphcth-s") || (rs485ModBusSensor == "npk-s") || (rs485ModBusSensor == "ph-s") ) {
    Serial1.begin(4800);
  } else {
    Serial1.begin(9600);
  }
  
  node.begin(1, Serial1);
  node.preTransmission(PreTransmission);
  node.postTransmission(PostTransmission);
  */
