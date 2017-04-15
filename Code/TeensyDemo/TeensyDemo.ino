/* TROLL8 uSynth Development Platform
	(c) 2017 www.creative-technologies.de
	Main author robert.manzke@fh-kiel.de
	Contributors Henrik Langer FH-Kiel, Alexander Konradi FH-Kiel
	Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
*/

/**
   Teensy 3.1 Troll8 Demo
*/

/**
   Definitions
*/
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

#define CONTROL_RATE 64
#define SPI_SS 10
#define CAP1188_RESET A7
#define GPIO_RESET A6


/**
   Arduino libs
*/
#include <ADC.h>  //Teensy 3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <SPI.h> //Faster SPI lib for Teensy 3.0 available also (https://www.pjrc.com/teensy/td_libs_SPI.html)
#include "MyMem.h"
#include "MyDelay.h"

/**
   Mozzi libs
*/
#include <MozziGuts.h>
#include <Oscil.h>
#include <mozzi_midi.h>
#include <Metronome.h>
#include <ADSR.h>
#include <tables/sin8192_int8.h>
#include <tables/triangle_warm8192_int8.h>
#include <tables/saw8192_int8.h>
#include <tables/smoothsquare8192_int8.h>
#include <tables/whitenoise8192_int8.h>

/**
   Global variables
*/
SPISettings spi_settings_global(2000000, MSBFIRST, SPI_MODE0);
SPISettings spi_settings_mem(16000000, MSBFIRST, SPI_MODE0);
uint16_t voiceOnOff = 0x0;
uint16_t voiceOnOff_o = 0x0;
uint16_t voiceOnOff_changed = 0x0;
byte osc_gain[2] = {0};
byte root_note[2] = {0};
float cents[2] = {0.0};
MyMem mem = MyMem();
MyDelay my_delay(mem, 0, 16384 * 5); //Mem controller / RAM start address / buffer 5 sec

/**
   Mozzi components
*/
Metronome kMetro(100);
Oscil <8192, AUDIO_RATE> osc_white_noise(WHITENOISE8192_DATA);
Oscil <8192, AUDIO_RATE> osc1(SIN8192_DATA); //Used as two separate oscillators
Oscil <8192, AUDIO_RATE> osc2(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc3(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc4(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc5(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc6(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc7(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc8(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc9(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc10(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc11(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc12(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc13(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc14(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc15(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc16(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc17(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc18(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc19(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc20(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc21(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc22(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc23(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc24(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc25(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc26(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc27(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc28(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc29(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc30(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc31(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> osc32(SIN8192_DATA);
Oscil <8192, AUDIO_RATE> *osc_array [] = {
  &osc1, &osc2, &osc3, &osc4, &osc5, &osc6, &osc7, &osc8,
  &osc9, &osc10, &osc11, &osc12, &osc13, &osc14, &osc15, &osc16,
  &osc17, &osc18, &osc19, &osc20, &osc21, &osc22, &osc23, &osc24,
  &osc25, &osc26, &osc27, &osc28, &osc29, &osc30, &osc31, &osc32
};
ADSR <CONTROL_RATE, AUDIO_RATE> envelope_osc1;
ADSR <CONTROL_RATE, AUDIO_RATE> envelope_osc2;
ADSR <CONTROL_RATE, AUDIO_RATE> envelope_noise;
ADSR <CONTROL_RATE, AUDIO_RATE> envelope_filter;


/**
   Control elements helper functions
*/
void writeRegCS(byte chip, byte adr, byte v) {
  digitalWrite(A0, chip & 0x04);
  digitalWrite(A1, chip & 0x02);
  digitalWrite(A2, chip & 0x01);
  SPI.beginTransaction(spi_settings_global);
  digitalWrite(SPI_SS, LOW);
  SPI.transfer(0x7d);
  SPI.transfer(adr);
  SPI.transfer(0x7e);
  SPI.transfer(v);
  digitalWrite(SPI_SS, HIGH);
  SPI.endTransaction();
}

byte readRegCS(byte chip, byte adr) {
  digitalWrite(A0, chip & 0x04);
  digitalWrite(A1, chip & 0x02);
  digitalWrite(A2, chip & 0x01);
  byte res = 0;
  SPI.beginTransaction(spi_settings_global);
  digitalWrite(SPI_SS, LOW);
  SPI.transfer(0x7d);
  SPI.transfer(adr);
  SPI.transfer(0x7f);
  res = SPI.transfer(0);
  digitalWrite(SPI_SS, HIGH);
  SPI.endTransaction();

  return res;
}

void reset_cs()
{
  pinMode(CAP1188_RESET, OUTPUT);
  digitalWrite(CAP1188_RESET, LOW);
  delay(100);
  digitalWrite(CAP1188_RESET, HIGH);
  delay(100);
  digitalWrite(CAP1188_RESET, LOW);
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
  pinMode(GPIO_RESET, OUTPUT);
  digitalWrite(GPIO_RESET, HIGH);
  delay(100);
  digitalWrite(GPIO_RESET, LOW);
  delay(100);
  digitalWrite(GPIO_RESET, HIGH);
  delay(100);
}

void writeRegGPIO(byte adr, byte v)
{
  digitalWrite(A0, 0x1); // a2
  digitalWrite(A1, 0x0); // a1
  digitalWrite(A2, 0x1); // a0
  SPI.beginTransaction(spi_settings_global);
  digitalWrite(SPI_SS, LOW);
  SPI.transfer(0x40);
  SPI.transfer(adr);
  SPI.transfer(v);
  digitalWrite(SPI_SS, HIGH);
  SPI.endTransaction();
}

byte readRegGPIO(byte adr)
{

  digitalWrite(A0, 0x1); // a2
  digitalWrite(A1, 0x0); // a1
  digitalWrite(A2, 0x1); // a0
  byte res = 0;
  SPI.beginTransaction(spi_settings_global);
  digitalWrite(SPI_SS, LOW);
  SPI.transfer(0x41);
  SPI.transfer(adr);
  res = SPI.transfer(0);
  digitalWrite(SPI_SS, HIGH);
  SPI.endTransaction();

  return res;
}

uint16_t readADC(byte chan)
{
  digitalWrite(A0, 0x0); // a2
  digitalWrite(A1, 0x1); // a1
  digitalWrite(A2, 0x0); // a0
  uint16_t res;
  SPI.beginTransaction(spi_settings_global);
  digitalWrite(SPI_SS, LOW);
  SPI.transfer(0x01);
  res = SPI.transfer((chan << 4) | 0x80);
  res = (res & 0x03) << 8;
  res |= SPI.transfer(0);
  digitalWrite(SPI_SS, HIGH);
  SPI.endTransaction();

  return res;
}


/**
   Setup / init
*/
void setup() {
  Serial.begin(9600);

  //Set oscillator frequencies beginning with H1 (47)
  for (int i = 0; i < 32; i++)
    osc_array[i]->setFreq(mtof((float)i + 47));
  startMozzi(CONTROL_RATE);

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

  reset_cs();
  init_cs();
  reset_gpio();
  init_gpio();

  //RAM Test
  for (uint32_t i=0; i<40; i++){
    mem.writeByteMem(1, i, 0);
  }
  for (uint32_t i=0; i<20; i++){
    mem.writeIntRAM(i, 0xCACACACA);
    int tmp = mem[i];
    Serial.println(tmp, HEX);
  }

  envelope_noise.setADLevels(255, 170);
  envelope_osc1.setADLevels(255, 170);
  envelope_osc2.setADLevels(255, 170);
  envelope_filter.setADLevels(255, 170);

  //LED startup animation
  writeRegGPIO(MCP23S18_GPIOA, ~(0x00));
  byte leds = 0;
  for (int i = 0; i < 6; i++) {
    if (!(i % 2)) {
      for (int j = 0; j < 4; j++) {
        leds |= (0x08 >> j);
        leds |= (0x10 << j);
        writeRegGPIO(MCP23S18_GPIOA, ~leds);
        delay(60);
      }
    }
    else {
      for (int j = 0; j < 4; j++) {
        leds &= ~(0x08 >> j);
        leds &= ~(0x10 << j);
        writeRegGPIO(MCP23S18_GPIOA, ~leds);
        delay(60);
      }
    }
  }

  kMetro.start();
}

/**
   Parameter update helper functions
*/
#define WAVEFORM_SIN 0
#define WAVEFORM_TRI 1
#define WAVEFORM_SAW 2
#define WAVEFORM_SQUARE 3
void setOscWaveform(int osc, int waveform) {
  switch (waveform) {
    case WAVEFORM_SIN:
      for (int i = 0; i < 16; i++)
        osc_array[i + (16 * osc)]->setTable(SIN8192_DATA);
      break;
    case WAVEFORM_TRI:
      for (int i = 0; i < 16; i++)
        osc_array[i + (16 * osc)]->setTable(TRIANGLE_WARM8192_DATA);
      break;
    case WAVEFORM_SAW:
      for (int i = 0; i < 16; i++)
        osc_array[i + (16 * osc)]->setTable(SAW8192_DATA);
      break;
    case WAVEFORM_SQUARE:
      for (int i = 0; i < 16; i++)
        osc_array[i + (16 * osc)]->setTable(SMOOTHSQUARE8192_DATA);
      break;

  }
}

void updateControl() {
  byte knobs[8] = {0};
  static byte knobs_old[8] = {0};
  byte knobs_changed = 0;
  byte buttons = 0;
  static byte buttons_state = 0;
  static byte buttons_cache = 0;
  byte buttons_changed = 0;


  //if (kMetro.ready()) {
    //Serial.println(knobs[0] >> 6);

  //Get state of knobs
  for (int i = 0; i < 8; i++)
    knobs[i] = readADC(i) >> 2; //Range: 0 - 255

  //Get state of buttons
  buttons = ~readRegGPIO(MCP23S18_GPIOB);
  if (buttons) {
    for (int i = 0; i < 8; i++) {
      if ((buttons & (1 << i)  &&  ((buttons_cache ^ buttons) & (1 << i)))) {
        if (buttons_state & (1 << i)) {
          buttons_state &= ~(1 << i);
        }
        else {
          buttons_state |= (1 << i);
        }
      }
    }
    writeRegGPIO(MCP23S18_GPIOA, ~buttons_state);
  }

  //Oscillators parameters
  switch (buttons_state & 0x3) {
    case 0: //gain
      if (knobs[0] != knobs_old[0])
        osc_gain[0] = knobs[0];
      if (knobs[1] != knobs_old[1])
        osc_gain[1] = knobs[1];
    break;
    case 1: //Waveform
      if (knobs[0] != knobs_old[0])
        setOscWaveform(0, knobs[0] >> 6);
      if (knobs[1] != knobs_old[1])
        setOscWaveform(1, knobs[1] >> 6);
    break;
    case 2: //Octaves
      if (knobs[0] != knobs_old[0]){
        root_note[0] = 35 + (12*(knobs[0]>>6));
        for (int i=0; i < 16; i++)
          osc_array[i]->setFreq(mtof((float) root_note[0] + i + cents[0]));
      }
      if (knobs[1] != knobs_old[1]){
        root_note[1] = 35 + (12*(knobs[1]>>6));
        for (int i=0; i < 16; i++)
          osc_array[i+16]->setFreq(mtof((float) root_note[1] + i + cents[1]));
      }
    break;
    case 3: //Cents
      if (knobs[0] != knobs_old[0]){
        cents[0] = (float) knobs[0] / 128.0 - 1.0;
        for (int i=0; i < 16; i++)
          osc_array[i]->setFreq(mtof((float) root_note[0] + i + cents[0]));
      }
      if (knobs[1] != knobs_old[1]){
        cents[1] = (float) knobs[1] / 128.0 - 1.0;
        for (int i=0; i < 16; i++)
          osc_array[i+16]->setFreq(mtof((float) root_note[1] + i + cents[1]));
      }
    break;
  }

  //Envelope parameters
  unsigned int times[4];
  if (knobs[2] != knobs_old[2] || knobs[3] != knobs_old[3] ||
          knobs[4] != knobs_old[4] || knobs[5] != knobs_old[5] ){
    switch ((buttons_state & 0x18)>>3){
      case 0: //Oscillator 1
        if (buttons_state & 0x4){ //Times
          for (int i=0; i < 4; i++){
            times[i] = (unsigned int) knobs[i+2] * 4;
          }
          envelope_osc1.setTimes(times[0], times[1], times[2], times[3]);
        }
        else { //Levels
          //envelope_osc1.setLevels(knobs[2], knobs[3], knobs[4], knobs[5]);
          envelope_osc1.setADLevels(knobs[2], knobs[3]); //problems with Teensy (endless note)
        }
        //envelope_osc1.update();
      break;
      case 1: //Oscillator 2
        if (buttons_state & 0x4){ //Times
          for (int i=0; i < 4; i++){
            times[i] = (unsigned int) knobs[i+2] * 4; 
          }
          envelope_osc2.setTimes(times[0], times[1], times[2], times[3]);
        }
        else { //Levels
          //envelope_osc2.setLevels(knobs[2], knobs[3], knobs[4], knobs[5]);
          envelope_osc2.setADLevels(knobs[2], knobs[3]);
        }
        envelope_osc2.update();
      break;
      case 2: //White noise oscillator
        if (buttons_state & 0x4){ //Times
          for (int i=0; i < 4; i++){
            times[i] = (unsigned int) knobs[i+2] * 4; //Up to 1024 ms
          }
          envelope_noise.setTimes(times[0], times[1], times[2], times[3]);
        }
        else { //Levels
          //envelope_noise.setLevels(knobs[2], knobs[3], knobs[4], knobs[5]);
          envelope_noise.setADLevels(knobs[2], knobs[3]);
        }
        envelope_noise.update();
      break;
      case 3: //Filter
        if (buttons_state & 0x4){ //Times
          for (int i=0; i < 4; i++){
            times[i] = (unsigned int) knobs[i+2] * 4;
          }
          envelope_filter.setTimes(times[0], times[1], times[2], times[3]);
        }
        else { //Levels
          //envelope_filter.setLevels(knobs[2], knobs[3], knobs[4], knobs[5]);
          envelope_filter.setADLevels(knobs[2], knobs[3]);
        }
        envelope_filter.update();
      break;
    }
  }
  //}
  
  buttons_cache = buttons;
  for (int i = 0; i < 8; i++)
    knobs_old[i] = knobs[i];

  // Get state of touch sensitive keyboard
  writeRegCS(0, CAP1188_MAIN, readRegCS(0, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff = (uint16_t)readRegCS(0, CAP1188_SENINPUTSTATUS);
  writeRegCS(1, CAP1188_MAIN, readRegCS(1, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff |= (uint16_t)readRegCS(1, CAP1188_SENINPUTSTATUS) << 8;

  if (voiceOnOff != voiceOnOff_o){
    voiceOnOff_changed = voiceOnOff ^ voiceOnOff_o;
    if (voiceOnOff){
      envelope_noise.noteOn();
      envelope_osc1.noteOn();
      envelope_osc2.noteOn();
      envelope_filter.noteOn();
    } else {
      envelope_noise.noteOff();
      envelope_osc1.noteOff();
      envelope_osc2.noteOff();
      envelope_filter.noteOff();
    }
  }
  voiceOnOff_o = voiceOnOff;
  envelope_noise.update();
  envelope_osc1.update();
  envelope_osc2.update();
  envelope_filter.update();
}

int updateAudio() {
  int s = 0;
  unsigned char envs[4];
  envs[0] = envelope_osc1.next();
  envs[1] = envelope_osc2.next();
  envs[2] = envelope_noise.next();
  envs[3] = envelope_filter.next();

  for (int i = 0; i < 16; i++) {
    if (voiceOnOff & (1 << i)) {
      s += (int) (osc_array[i]->next() * envs[0]) >> 8;
      s += (int) (osc_array[i+16]->next() * envs[1]) >> 8;
      //my_delay.next(0);
      mem.writeByteMem(1, 0, 0);
      mem.readByteMem(1, 0);
    }
  }

  return s;
}

void loop() {
  audioHook();
}
