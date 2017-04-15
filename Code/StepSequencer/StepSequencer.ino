/* TROLL8 uSynth Development Platform
	(c) 2017 www.creative-technologies.de
	Main author robert.manzke@fh-kiel.de
	Contributors Henrik Langer FH-Kiel, Alexander Konradi FH-Kiel
	Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
*/

//#include <ADC.h>  // Teensy 3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <LowPassFilter.h>
#include <Metronome.h>
#include <mozzi_rand.h>

#include <tables/saw_analogue512_int8.h>
#include <tables/cos2048_int8.h> // for filter modulation

#include <SPI.h>

#define SPI_SS 10

// Reset Pin is used for I2C or SPI
#define CAP1188_RESET  A7

// CS pin is used for software or hardware SPI
#define CAP1188_CS1  6
#define CAP1188_CS2  7
#define CAP1188_SENINPUTSTATUS 0x3
#define CAP1188_MTBLK 0x2A
#define CAP1188_LEDLINK 0x72
#define CAP1188_PRODID 0xFD
#define CAP1188_MANUID 0xFE
#define CAP1188_STANDBYCFG 0x41
#define CAP1188_CONFIG1 0x20
#define CAP1188_CONFIG2 0x44
#define CAP1188_REV 0xFF
#define CAP1188_MAIN 0x00
#define CAP1188_MAIN_INT 0x01
#define CAP1188_LEDPOL 0x73
#define CAP1188_SENSITIVITY_CTRL 0x1F
#define CAP1188_AVERAGING_SAMPLE_REG 0x24

// MCP23S18 definitions
#define MCP23S18_IODIRA 0x00
#define MCP23S18_IODIRB 0x01
#define MCP23S18_IPOLA 0x02
#define MCP23S18_IPOLB 0x03
#define MCP23S18_GPINTENA 0x04
#define MCP23S18_GPINTENB 0x05
#define MCP23S18_DEFVALA 0x06
#define MCP23S18_DEFVALB 0x07
#define MCP23S18_INTCONA 0x08
#define MCP23S18_INTCONB 0x09
#define MCP23S18_IOCONA 0x0a
#define MCP23S18_IOCONB 0x0b
#define MCP23S18_GPPUA 0x0c
#define MCP23S18_GPPUB 0x0d
#define MCP23S18_INTFA 0x0e
#define MCP23S18_INTFB 0x0f
#define MCP23S18_INTCAPA 0x10
#define MCP23S18_INTCAPB 0x11
#define MCP23S18_GPIOA 0x12
#define MCP23S18_GPIOB 0x13
#define MCP23S18_OLATA 0x14
#define MCP23S18_OLATB 0x15


// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSaw1(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSaw2(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSaw3(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSaw4(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSaw5(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSaw6(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSaw7(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSaw8(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> bSaw1(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> bSaw2(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> bSaw3(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> bSaw4(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> bSaw5(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> bSaw6(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> bSaw7(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> bSaw8(SAW_ANALOGUE512_DATA);
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> bass(SAW_ANALOGUE512_DATA);
Oscil<COS2048_NUM_CELLS, CONTROL_RATE> kFilterMod(COS2048_DATA);
LowPassFilter svf; // can be LOWPASS, BANDPASS, HIGHPASS or NOTCH
Metronome kMetro(250);


// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // powers of 2 please

byte voiceOnOff1 = 0x0, voiceOnOff2 = 0;
byte stepVoiceOnOff = 0x0;

void writeRegCS(byte chip, byte adr, byte v){
   digitalWrite(A0, chip & 0x04);
   digitalWrite(A1, chip & 0x02);
   digitalWrite(A2, chip & 0x01);
  
   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x7d);
   SPI.transfer(adr);
   SPI.transfer(0x7e);
   SPI.transfer(v);
   digitalWrite(SPI_SS, HIGH);
}

byte readRegCS(byte chip, byte adr){
   digitalWrite(A0, chip & 0x04);
   digitalWrite(A1, chip & 0x02);
   digitalWrite(A2, chip & 0x01);
   byte res = 0;
   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x7d);
   SPI.transfer(adr);
   SPI.transfer(0x7f);
   res = SPI.transfer(0);
   digitalWrite(SPI_SS, HIGH);
   return res;
}

void reset_cs()
{
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW);
  delay(100);
  digitalWrite(A3, HIGH);
  delay(100);
  digitalWrite(A3, LOW);
  delay(100);
}

void init_cs_chip(byte chip)
{
  byte reg;
  writeRegCS(chip, CAP1188_MTBLK, 0); 
  writeRegCS(chip, CAP1188_LEDLINK, 0xFF); 
  writeRegCS(chip, CAP1188_STANDBYCFG, 0x30); 
  writeRegCS(chip, 0x28, 0x00); 
  reg = readRegCS(chip, CAP1188_SENSITIVITY_CTRL);
  reg &= 0x0f;
  reg |= 0x30;
  writeRegCS(chip, CAP1188_SENSITIVITY_CTRL, reg);
  writeRegCS(chip, CAP1188_AVERAGING_SAMPLE_REG, 0x00);
  reg = readRegCS(chip, CAP1188_CONFIG2);
  reg &= ~0x40;
  writeRegCS(chip, CAP1188_CONFIG2, reg);
  writeRegCS(chip, CAP1188_MAIN, readRegCS(chip, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
}

void init_cs()
{
    init_cs_chip(0);
    init_cs_chip(1);
}

void init_gpio()
{
  // port a as output
  writeRegGPIO(MCP23S18_IODIRA, 0x00);
  // port b as input with pullup
  writeRegGPIO(MCP23S18_IODIRB, 0xff);
  writeRegGPIO(MCP23S18_GPPUB, 0xff);
}

void reset_gpio()
{
  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);
  delay(100);
  digitalWrite(A4, LOW);
  delay(100);
  digitalWrite(A4, HIGH);
  delay(100);
}

void writeRegGPIO(byte adr, byte v)
{
  
   digitalWrite(A0, 0x1); // a2
   digitalWrite(A1, 0x0); // a1
   digitalWrite(A2, 0x1); // a0
   noInterrupts();
   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x40);
   SPI.transfer(adr);
   SPI.transfer(v);
   digitalWrite(SPI_SS, HIGH);
   interrupts();
}

byte readRegGPIO(byte adr)
{
   digitalWrite(A0, 0x1); // a2
   digitalWrite(A1, 0x0); // a1
   digitalWrite(A2, 0x1); // a0
   byte res = 0;
   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x41);
   SPI.transfer(adr);
   res = SPI.transfer(0);
   digitalWrite(SPI_SS, HIGH);
   return res;
}


uint16_t readADC(byte chan)
{
  
   digitalWrite(A0, 0x0); // a2
   digitalWrite(A1, 0x1); // a1
   digitalWrite(A2, 0x0); // a0

   uint16_t res;
   noInterrupts();
   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x01);
   res = SPI.transfer((chan<<4)|0x80);
   res = (res&0x03)<<8;
   res |= SPI.transfer(0);
   digitalWrite(SPI_SS, HIGH);
   interrupts();
   return res;
}
void setup(){
  //Serial.begin(115200);
  startMozzi(); // set a control rate of 64 (powers of 2 please)
  aSaw1.setFreq(262); // set the frequency
  aSaw2.setFreq(278); // set the frequency
  aSaw3.setFreq(294); // set the frequency
  aSaw4.setFreq(311); // set the frequency
  aSaw5.setFreq(330); // set the frequency
  aSaw6.setFreq(349); // set the frequency
  aSaw7.setFreq(370); // set the frequency
  aSaw8.setFreq(392); // set the frequency
  bSaw1.setFreq(415); // set the frequency
  bSaw2.setFreq(440); // set the frequency
  bSaw3.setFreq(466); // set the frequency
  bSaw4.setFreq(494); // set the frequency
  bSaw5.setFreq(523); // set the frequency
  bSaw6.setFreq(554); // set the frequency
  bSaw7.setFreq(587); // set the frequency
  bSaw8.setFreq(622); // set the frequency

  kFilterMod.setFreq(4.0f);
  svf.setResonance(127);
  svf.setCutoffFreq(127);

  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, HIGH); 



  pinMode(SPI_SS, OUTPUT);
  digitalWrite(SPI_SS, HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  SPI.setDataMode(SPI_MODE0);

  reset_cs();
  init_cs();

  reset_gpio();
  init_gpio();

  attachInterrupt(0, getCS, RISING);

  kMetro.start();
  kMetro.set(100);
  
  

}

void getCS(){
  noInterrupts();
  writeRegCS(0, CAP1188_MAIN, readRegCS(0, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff1 = readRegCS(0, CAP1188_SENINPUTSTATUS);

  writeRegCS(1, CAP1188_MAIN, readRegCS(1, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff2 = readRegCS(1, CAP1188_SENINPUTSTATUS);
  interrupts();
  //Serial.println(voiceOnOff1, HEX);
}

void updateControl(){
  static byte cnt = 0;
  static byte stepVar = 0;

  byte buttons = ~readRegGPIO(MCP23S18_GPIOB);
  static byte buttons_last;
  if(buttons && (buttons != buttons_last))
    stepVar ^= buttons & ~buttons_last;
  buttons_last = buttons;
  int adc = readADC(cnt%8)>>2;   
  if(kMetro.ready()){
    byte val = ~(1 << (cnt%8)) ^ ~stepVar;
    stepVoiceOnOff = val & (1<<(cnt%8));
    writeRegGPIO(MCP23S18_GPIOA, val);
    cnt++;
    bass.setFreq(65 + adc);
  }
}


int updateAudio(){
  int s = 0;
  if(voiceOnOff1&0x01) 
    s += aSaw1.next() >> 2;
  if(stepVoiceOnOff) 
    s += bass.next() >> 2;
  if(voiceOnOff1&0x02) s += aSaw2.next() >> 2;
  if(voiceOnOff1&0x04) s += aSaw3.next() >> 2;
  if(voiceOnOff1&0x08) s += aSaw4.next() >> 2;
  if(voiceOnOff1&0x10) s += aSaw5.next() >> 2;
  if(voiceOnOff1&0x20) s += aSaw6.next() >> 2;
  if(voiceOnOff1&0x40) s += aSaw7.next() >> 2;
  if(voiceOnOff1&0x80) s += aSaw8.next() >> 2;

  if(voiceOnOff2&0x01) s += bSaw1.next() >> 2;
  if(voiceOnOff2&0x02) s += bSaw2.next() >> 2;
  if(voiceOnOff2&0x04) s += bSaw3.next() >> 2;
  if(voiceOnOff2&0x08) s += bSaw4.next() >> 2;
  if(voiceOnOff2&0x10) s += bSaw5.next() >> 2;
  if(voiceOnOff2&0x20) s += bSaw6.next() >> 2;
  if(voiceOnOff2&0x40) s += bSaw7.next() >> 2;
  if(voiceOnOff2&0x80) s += bSaw8.next() >> 2;
  
  return svf.next(s); // return an int signal centred around 0
}


void loop(){
  audioHook(); // required here
}



