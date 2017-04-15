/* TROLL8 uSynth Development Platform
	(c) 2017 www.creative-technologies.de
	Main author robert.manzke@fh-kiel.de
	Contributors Henrik Langer FH-Kiel, Alexander Konradi FH-Kiel
	Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
*/

#include <ADC.h>  // Teensy 3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Oscil.h> // oscillator template
#include <LowPassFilter.h>
#include <Metronome.h>
#include <mozzi_rand.h>
#include <ADSR.h>
#include <StateVariable.h>
#include <AudioDelayFeedback.h>
#include <SPI.h>

#include <tables/sin2048_int8.h>
#include <tables/saw2048_int8.h>
#include <tables/triangle2048_int8.h>
#include <tables/square_no_alias_2048_int8.h>
#include <tables/whitenoise8192_int8.h>

#include "notes.h"

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

// use #define for CONTROL_RATE, not a constant
#define CONTROL_RATE 64 // powers of 2 please

#define WAVEFORM_SIN 1
#define WAVEFORM_TRIANGLE 2
#define WAVEFORM_SAW 3
#define WAVEFORM_SQUARE 4

Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc1(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc2(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc3(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc4(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc5(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc6(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc7(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc8(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc9(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc10(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc11(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc12(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc13(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc14(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc15(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc16(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc17(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc18(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc19(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc20(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc21(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc22(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc23(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc24(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc25(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc26(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc27(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc28(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc29(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc30(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc31(SIN2048_DATA);
Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> osc32(SIN2048_DATA);
Oscil <WHITENOISE8192_NUM_CELLS, AUDIO_RATE> osc_noise(WHITENOISE8192_DATA);

Oscil <SIN2048_NUM_CELLS, AUDIO_RATE> *osc_array [] = {
  &osc1, &osc2, &osc3, &osc4, &osc5, &osc6, &osc7, &osc8, 
  &osc9, &osc10, &osc11, &osc12, &osc13, &osc14, &osc15, &osc16,
  &osc17, &osc18, &osc19, &osc20, &osc21, &osc22, &osc23, &osc24,
  &osc25, &osc26, &osc27, &osc28, &osc29, &osc30, &osc31, &osc32
};

ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc1;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc2;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc3;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc4;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc5;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc6;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc7;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc8;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc9;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc10;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc11;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc12;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc13;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc14;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc15;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc16;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc17;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc18;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc19;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc20;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc21;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc22;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc23;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc24;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc25;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc26;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc27;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc28;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc29;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc30;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc31;
ADSR <CONTROL_RATE, AUDIO_RATE> kEnvelopeOsc32;

ADSR <CONTROL_RATE, AUDIO_RATE> *env_array [] = {
  &kEnvelopeOsc1, &kEnvelopeOsc2, &kEnvelopeOsc3, &kEnvelopeOsc4, 
  &kEnvelopeOsc5, &kEnvelopeOsc6, &kEnvelopeOsc7, &kEnvelopeOsc8, 
  &kEnvelopeOsc9, &kEnvelopeOsc10, &kEnvelopeOsc11, &kEnvelopeOsc12, 
  &kEnvelopeOsc13, &kEnvelopeOsc14, &kEnvelopeOsc15, &kEnvelopeOsc16, 
  &kEnvelopeOsc17, &kEnvelopeOsc18, &kEnvelopeOsc19, &kEnvelopeOsc20, 
  &kEnvelopeOsc21, &kEnvelopeOsc22, &kEnvelopeOsc23, &kEnvelopeOsc24, 
  &kEnvelopeOsc25, &kEnvelopeOsc26, &kEnvelopeOsc27, &kEnvelopeOsc28, 
  &kEnvelopeOsc29, &kEnvelopeOsc30, &kEnvelopeOsc31, &kEnvelopeOsc32
};

Metronome kMetro(250);
StateVariable<LOWPASS> low_pass_fil;
StateVariable<BANDPASS> band_pass_fil;
StateVariable<HIGHPASS> high_pass_fil;
StateVariable<NOTCH> notch_fil;
//AudioDelayFeedback delay_fb;
uint16_t voiceOnOff = 0x0;
uint16_t voiceOnOff_o = 0x0;
byte volume[3] = {0, 0, 0};

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

void reset_cs() //Original: A3 (Changed by Henrik)
{
  pinMode(A7, OUTPUT);
  digitalWrite(A7, LOW);
  delay(100);
  digitalWrite(A7, HIGH);
  delay(100);
  digitalWrite(A7, LOW);
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

void reset_gpio() //Original A4 (Changed by Henrik)
{
  pinMode(A6, OUTPUT);
  digitalWrite(A6, HIGH);
  delay(100);
  digitalWrite(A6, LOW);
  delay(100);
  digitalWrite(A6, HIGH);
  delay(100);
}

void writeRegGPIO(byte adr, byte v)
{
  
   digitalWrite(A0, 0x1); // a2
   digitalWrite(A1, 0x0); // a1
   digitalWrite(A2, 0x1); // a0
   //noInterrupts();
   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x40);
   SPI.transfer(adr);
   SPI.transfer(v);
   digitalWrite(SPI_SS, HIGH);
   //interrupts();
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
   //noInterrupts();
   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x01);
   res = SPI.transfer((chan<<4)|0x80);
   res = (res&0x03)<<8;
   res |= SPI.transfer(0);
   digitalWrite(SPI_SS, HIGH);
   //interrupts();
   return res;
}

void setWaveform(int index, int osc_index){
  int i;

  switch(index){
    case WAVEFORM_SIN: //Sin
      for (i=0; i < 16; i++)
        osc_array[i + osc_index]->setTable(SIN2048_DATA);
    break;

    case WAVEFORM_TRIANGLE: //Triangle
      for (i=0; i < 16; i++)
        osc_array[i + osc_index]->setTable(TRIANGLE2048_DATA);
    break;

    case WAVEFORM_SAW: //Saw
      for (i=0; i < 16; i++)
        osc_array[i + osc_index]->setTable(SAW2048_DATA);
    break;

    case WAVEFORM_SQUARE: //Square
      for (i=0; i < 16; i++)
        osc_array[i + osc_index]->setTable(SQUARE_NO_ALIAS_2048_DATA);
    break;

  }
}

void setup() {
  int i = 0;

  Serial.begin(9600);

  startMozzi(); // set a control rate of 64 (powers of 2 please)

  for (i=0; i < 32; i++)
    osc_array[i]->setFreq(notes_frequency_DATA[3*12 - 1 + (i % 16)]); //Beginning with H2

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
  SPI.setClockDivider(SPI_CLOCK_DIV8); //TODO: Change for Teensy and use faster SPI lib
  SPI.setDataMode(SPI_MODE0);

  reset_cs();
  init_cs();
  reset_gpio();
  init_gpio();

  kMetro.start();
  kMetro.set(250);

  writeRegGPIO(MCP23S18_GPIOA, 0xff);
  writeRegGPIO(MCP23S18_GPIOB, 0xff);

  //Setup filters
  low_pass_fil.setResonance(255);
  low_pass_fil.setCentreFreq(20000);
  band_pass_fil.setResonance(255);
  band_pass_fil.setCentreFreq(1000);
  high_pass_fil.setResonance(255);
  high_pass_fil.setCentreFreq(0);
  notch_fil.setResonance(255);
  notch_fil.setCentreFreq(20000);
  //delay_fb.set(0);
}

void updateControl(){
  byte knobs[8], i;

  for (i=0; i<8; i++)
    knobs[i] = readADC(i) >> 2; //range 0 - 256

  //Control update routine
  if (kMetro.ready()){
    byte buttons = ~readRegGPIO(MCP23S18_GPIOB);
    static byte buttons_last = buttons;

    if (buttons){
      buttons = buttons_last ^ buttons;
      writeRegGPIO(MCP23S18_GPIOA, ~buttons);
      buttons_last = buttons;
    }
    //Serial.println(buttons_last, HEX);

    //Oscillator Control (Buttons 1/2)
    switch(buttons_last & 0x03){
      case 0: //Volume control
        volume[0] = knobs[0];
        volume[1] = knobs[1];
      break;

      case 1: //Waveform select
        //Oscillator 1
        if (knobs[0] > 0 && knobs[0] < 64)
          setWaveform(WAVEFORM_SIN, 0);
        else if (knobs[0] > 64 && knobs[0] < 128)
          setWaveform(WAVEFORM_TRIANGLE, 0);
        else if (knobs[0] > 128 && knobs[0] < 192)
          setWaveform(WAVEFORM_SAW, 0);
        else if (knobs[0] > 192 && knobs[0] < 256)
          setWaveform(WAVEFORM_SQUARE, 0);

        //Oscillator 2
        if (knobs[1] > 0 && knobs[1] < 64)
          setWaveform(WAVEFORM_SIN, 1);
        else if (knobs[1] > 64 && knobs[1] < 128)
          setWaveform(WAVEFORM_TRIANGLE, 1);
        else if (knobs[1] > 128 && knobs[1] < 192)
          setWaveform(WAVEFORM_SAW, 1);
        else if (knobs[1] > 192 && knobs[1] < 256)
          setWaveform(WAVEFORM_SQUARE, 1);
      break;

      case 2: //Octave
        //Oscillator 1
        if (knobs[0] > 0 && knobs[0] < 64)
          for (i=0; i < 16; i++){
            osc_array[i]->setFreq(notes_frequency_DATA[2*12 - 1 + i]);
          }
        else if (knobs[0] > 64 && knobs[0] < 128)
          for (i=0; i < 16; i++){
            osc_array[i]->setFreq(notes_frequency_DATA[3*12 - 1 + i]);
          }
        else if (knobs[0] > 128 && knobs[0] < 192)
          for (i=0; i < 16; i++){
            osc_array[i]->setFreq(notes_frequency_DATA[4*12 - 1 + i]);
          }
        else if (knobs[0] > 192 && knobs[0] < 256)
          for (i=0; i < 16; i++){
            osc_array[i]->setFreq(notes_frequency_DATA[5*12 - 1 + i]);
          }
        //Oscillator 2
        if (knobs[1] > 0 && knobs[1] < 64)
          for (i=0; i < 16; i++)
            osc_array[i+16]->setFreq(notes_frequency_DATA[2*12 - 1 + i]);
        else if (knobs[1] > 64 && knobs[1] < 128)
          for (i=0; i < 16; i++)
            osc_array[i+16]->setFreq(notes_frequency_DATA[3*12 - 1 + i]);
        else if (knobs[1] > 128 && knobs[1] < 192)
          for (i=0; i < 16; i++)
            osc_array[i+16]->setFreq(notes_frequency_DATA[4*12 - 1 + i]);
        else if (knobs[1] > 192 && knobs[1] < 256)
          for (i=0; i < 16; i++)
            osc_array[i+16]->setFreq(notes_frequency_DATA[5*12 - 1 + i]);
      break;

      case 3: //Cents
      break;
    }

    //Oscillator envelopes
    switch((buttons_last & 0x0C) >> 2){
      case 0:
        for (i=0; i < 16; i++){
          env_array[i]->setLevels(knobs[2], knobs[3], knobs[4], knobs[5]);
          env_array[i]->update();
        }
      break;

      case 1:
        for (i=0; i < 16; i++){
          env_array[i+16]->setLevels(knobs[2], knobs[3], knobs[4], knobs[5]);
          env_array[i+16]->update();
        }
      break;
    }
  }

  writeRegCS(0, CAP1188_MAIN, readRegCS(0, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff = (uint16_t)readRegCS(0, CAP1188_SENINPUTSTATUS);

  writeRegCS(1, CAP1188_MAIN, readRegCS(1, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff |= (uint16_t)readRegCS(1, CAP1188_SENINPUTSTATUS)<<8;

  if (voiceOnOff != voiceOnOff_o){
    // noteOn if new state is pressed / noteOff if new state is unpressed
    for (i=0; i < 16; i++){
      if (voiceOnOff & (0x01 << i) && !(voiceOnOff_o & (0x01 << i))){
        env_array[i]->noteOn();
        env_array[i+16]->noteOn();
      }
      else {
        env_array[i]->noteOff();
        env_array[i+16]->noteOff();
      }
    }
  }
  
  voiceOnOff_o = voiceOnOff;
}


int updateAudio() {
  int s = 0, i = 0;

  for (i=0; i < 32; i++){
    //s += (int) (env_array[i]->next() * osc_array[i]->next()) >> 8;
    s += (int) (osc_array[i]->next()) >> 8;
  }

  //s += .next()

  return s;
}

void loop() {
  audioHook(); // required here
}
