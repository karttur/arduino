/*
 * 
 * 
 * 
 */


bool initiatedLamp = false;

// Set DAC voltage (raw DAC value)
// 12 bit, 0-4095 <=> 0-3.3V
void DAC6571_setVoltage(uint16_t v)
{ 
  uint16_t vh,vl;
 
  vh=(v>>8) & 0xff;
  vl=v & 0xff;
  
  Wire.beginTransmission(DAC6571_ADDR);
  Wire.write(vh); // PD bits =0 (bit 4-5) = Normal operation
  Wire.write(vl);
  Wire.endTransmission();
}

#define RA 68.0
#define RB 16.9
#define RD 75.0
#define DAC_VREF_mV 3300.0
#define DAC_MAX 4095.0

// Set the LED PULSE milli Volt

void LED_setVoltage_mV(float vset_mV)
{
  float vdac_mV=600*(RD/RB+1)+(600-vset_mV)*RD/RA;
//  (600.0*(1+RA/RB)-vset_mV)*RD/RA+600.0;
  float r=vdac_mV/DAC_VREF_mV*DAC_MAX;

  DAC6571_setVoltage((uint16_t)r);
}

/* END LED voltage control */
