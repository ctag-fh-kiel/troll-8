/* TROLL8 uSynth Development Platform
	(c) 2017 www.creative-technologies.de
	Main author robert.manzke@fh-kiel.de
	Contributors Henrik Langer FH-Kiel, Alexander Konradi FH-Kiel
	Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
*/

//#include <ADC.h>  // Teensy 3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Sample.h>
#include "Samples/kick.h"
#include "Samples/snare.h"
#include "Samples/hihat_clsd.h"
#include "Samples/hihat_open.h"
//#include "Samples/chord.h"

#include <Oscil.h> // oscillator template
#include <Metronome.h>
#include <mozzi_rand.h>
#include <Ead.h>
#include <EventDelay.h>
#include <StateVariable.h>


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
#define CAP1188_INT 0x27
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

#define STEP_SYNC_OUT 7
#define FRAME_SYNC_OUT 8

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSaw1(SAW_ANALOGUE512_DATA);
Metronome kMetro(250);

byte stepVoiceOnOff = 0x0;
Sample<kick_NUM_CELLS, AUDIO_RATE> sampleKick(kick_DATA);
Sample<snare_NUM_CELLS, AUDIO_RATE> sampleSnare(snare_DATA);
Sample<hihat_clsd_NUM_CELLS, AUDIO_RATE> sampleHHC(hihat_clsd_DATA);
Sample<hihat_open_NUM_CELLS, AUDIO_RATE> sampleHHO(hihat_open_DATA);
//Sample<chord_NUM_CELLS, AUDIO_RATE> sampleChord(chord_DATA);


// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // powers of 2 please
#define AUDIO_MODE STANDARD

uint16_t voiceOnOff = 0x0;
Ead kEnvelope(CONTROL_RATE);
EventDelay kDelay;
int gain;

StateVariable <BANDPASS> svf; // can be LOWPASS, BANDPASS, HIGHPASS or NOTCH

uint16_t noteFreqs[16] = {123, 131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233, 247, 262, 277, 294};

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

  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, HIGH); 

  pinMode(SPI_SS, OUTPUT);
  digitalWrite(SPI_SS, HIGH);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  SPI.setDataMode(SPI_MODE0);

  reset_cs();
  init_cs();

  reset_gpio();
  init_gpio();

  //attachInterrupt(0, getCS, RISING);

  kMetro.start();
  kMetro.set(100);
  
  sampleKick.setFreq(14.28f);
  sampleSnare.setFreq((float)snare_SAMPLERATE/(float)snare_NUM_CELLS);
  sampleHHO.setFreq((float)hihat_open_SAMPLERATE/(float)hihat_open_NUM_CELLS);
  sampleHHC.setFreq((float)hihat_clsd_SAMPLERATE/(float)hihat_clsd_NUM_CELLS);
  //sampleChord.setFreq((float)chord_SAMPLERATE/(float)chord_NUM_CELLS);

  svf.setResonance(255);
  svf.setCentreFreq(1200);
}
/*
void getCS(){
  noInterrupts();
  writeRegCS(0, CAP1188_MAIN, readRegCS(0, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff1 = readRegCS(0, CAP1188_SENINPUTSTATUS);

  writeRegCS(1, CAP1188_MAIN, readRegCS(1, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff2 = readRegCS(1, CAP1188_SENINPUTSTATUS);
  interrupts();
  //Serial.println(voiceOnOff1, HEX);
}
*/
void updateControl(){
  static byte cnt = 0;

  static byte stepVarArray[8] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  int sampleSelect = readADC(0)>>8;   
  byte *stepVar = &stepVarArray[((cnt&0x08)>>3) + (sampleSelect<<1)];
  //Serial.println(((cnt&0x08)>>3) + (sampleSelect<<1), HEX);

  writeRegCS(0, CAP1188_MAIN, readRegCS(0, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff = (uint16_t)readRegCS(0, CAP1188_SENINPUTSTATUS);

  writeRegCS(1, CAP1188_MAIN, readRegCS(1, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff |= (uint16_t)readRegCS(1, CAP1188_SENINPUTSTATUS)<<8;

  uint16_t notesOn[16];
  byte nNotesOn = 0;
  for(byte i=0;i<16;i++){
    if((voiceOnOff>>i)&0x01){
      notesOn[nNotesOn++] = noteFreqs[i];
    }
  }

  
  byte buttons = ~readRegGPIO(MCP23S18_GPIOB);
  static byte buttons_last = buttons;

  
  if(buttons && (buttons != buttons_last))
    *stepVar ^= buttons & ~buttons_last;
  buttons_last = buttons;
  
  unsigned int duration;
  unsigned int attack;
  unsigned int decay;
  unsigned int centerF;
  centerF = readADC(5)<<2;
  svf.setResonance(0xff - readADC(6)>>2);
  if(kMetro.ready()){
    if(nNotesOn){
      svf.setCentreFreq(centerF + rand(-300, 300));
      aSaw1.setFreq((int)notesOn[rand(nNotesOn)]);    
      duration = rand(200u)+100;
      attack = 10; // +5 so the internal step size is more likely to be >0
      decay = duration - attack;
      kEnvelope.start(attack,decay);
     }
  
    for(byte i=0;i<4;i++){
      stepVar = &stepVarArray[((cnt&0x08)>>3) + (i<<1)];
      byte val = ~(1 << (cnt%8)) ^ ~(*stepVar);
      switch(i){
        case 0:
          if(val & (1<<(cnt%8)))
            sampleKick.start();
          break;
        case 1:
          if(val & (1<<(cnt%8)))
            sampleSnare.start();
          break;
        case 2:
          if(val & (1<<(cnt%8)))
            sampleHHC.start();
          break;
        case 3:
          if(val & (1<<(cnt%8)))
            sampleHHO.start();
          break;
      }

      if(i==sampleSelect)
        writeRegGPIO(MCP23S18_GPIOA, val);
    }
    if(cnt%16 == 0)
      digitalWrite(FRAME_SYNC_OUT, 0x0);

    digitalWrite(STEP_SYNC_OUT, 0x0);

    cnt++;
  }else{
    digitalWrite(FRAME_SYNC_OUT, 1);
    digitalWrite(STEP_SYNC_OUT, 1);
  }

  kMetro.set(280 - (readADC(7)>>2));
  sampleKick.setFreq((int)readADC(1)>>3 + rand(1));
  sampleSnare.setFreq((int)readADC(2)>>3 + rand(1));
  sampleHHC.setFreq((int)readADC(3)>>3 + rand(1));
  sampleHHO.setFreq((int)readADC(4)>>3 + rand(1));

  gain = (int) kEnvelope.next();
  //Serial.println(gain);
}


int updateAudio(){
  int s = 0;
  int sk = 0;

  if(voiceOnOff)
    sk = (gain * aSaw1.next())>>8;

  s += svf.next(sk);

  s += sampleKick.next()<<1;
  s += sampleSnare.next()<<1;
  s += sampleHHO.next()<<1;
  s += sampleHHC.next()<<1;

  if(s>243)s=243;
  if(s<-244)s=-244;
  
  return s;//svf.next(s); // return an int signal centred around 0
}


void loop(){
  audioHook(); // required here
}



