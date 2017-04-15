/* TROLL8 uSynth Development Platform
	(c) 2017 www.creative-technologies.de
	Main author robert.manzke@fh-kiel.de
	Contributors Henrik Langer FH-Kiel, Alexander Konradi FH-Kiel
	Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
*/

/**
   Use Arduino Nano (clone) and TROLL8 as MIDI controller
   Requires Hairless MIDI (https://projectgus.github.io/hairless-midiserial/) on Host PC
   and Arduino MIDI lib (https://github.com/FortySevenEffects/arduino_midi_library/)
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

#define CONTROL_RATE 128
#define SPI_SS 10
#define CAP1188_RESET A3
#define GPIO_RESET A4
#define MIDI_CHANNEL 1

/**
   Libraries
*/
#include <SPI.h> //Faster SPI lib for Teensy 3.0 available also (https://www.pjrc.com/teensy/td_libs_SPI.html)
#include <MIDI.h>

/**
   Global variables
*/
uint16_t voiceOnOff = 0x0;
uint16_t voiceOnOff_o = 0x0;
byte gain[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte cs_o[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte v_max[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte clickGain = 127;
SPISettings spi_settings_global(2000000, MSBFIRST, SPI_MODE0);


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

void reset_cs() //Original: A3 (Changed by Henrik)
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

void reset_gpio() //Original A4 (Changed by Henrik)
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

void updateVelocityReads(){
  byte cs[16];
  int v;
  cs[0] = readRegCS(0, 0x10);
  cs[1] = readRegCS(0, 0x11);
  cs[2] = readRegCS(0, 0x12);
  cs[3] = readRegCS(0, 0x13);
  cs[4] = readRegCS(0, 0x14);
  cs[5] = readRegCS(0, 0x15);
  cs[6] = readRegCS(0, 0x16);
  cs[7] = readRegCS(0, 0x17);
  cs[8] = readRegCS(1, 0x10);
  cs[9] = readRegCS(1, 0x11);
  cs[10] = readRegCS(1, 0x12);
  cs[11] = readRegCS(1, 0x13);
  cs[12] = readRegCS(1, 0x14);
  cs[13] = readRegCS(1, 0x15);
  cs[14] = readRegCS(1, 0x16);
  cs[15] = readRegCS(1, 0x17);
  
  for(byte i=0;i<16;i++){
    v = cs[i] - cs_o[i];
    cs_o[i] = cs[i];
    if(v>v_max[i])
      v_max[i] = v;
  }
  //Serial.println(v_max[0]);
}

byte vToGain(int v){
  if(v>121)v=121;
  if(v<90)v=90;
  v-=90;
  v<<=3;
  if(v<32)v=32;
  return (byte) v;
}

/**
   Main functions
*/
MIDI_CREATE_DEFAULT_INSTANCE();
void setup() {
  MIDI.begin(1);
  Serial.begin(115200);

  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, HIGH);

  pinMode(SPI_SS, OUTPUT);
  digitalWrite(SPI_SS, HIGH);

  pinMode(7, OUTPUT); //For what???
  pinMode(8, OUTPUT);

  SPI.begin();

  reset_cs();
  init_cs();
  reset_gpio();
  init_gpio();

  //LED startup animation
  for (int i=0; i < 2; i++){
    if (!(i%2)){
      for (int j=0; j < 7; j++){
        writeRegGPIO(MCP23S18_GPIOA, ~(1<<j));
        delay(50);
      }
    }
    else{
      for (int j=0; j < 8; j++){
        writeRegGPIO(MCP23S18_GPIOA, ~(0x80>>j));
        delay(50);
      }
    }
  }
  delay(50);
  writeRegGPIO(MCP23S18_GPIOA, ~(0x00));
  byte leds = 0;
  for (int i=0; i < 4; i++){
    if (!(i%2)){
      for (int j=0; j < 4; j++){
        leds |= (0x08 >> j);
        leds |= (0x10 << j);
        writeRegGPIO(MCP23S18_GPIOA, ~leds);
        delay(75);
      }
    }
    else {
      for (int j=0; j < 4; j++){
        leds &= ~(0x08 >> j);
        leds &= ~(0x10 << j);
        writeRegGPIO(MCP23S18_GPIOA, ~leds);
        delay(75);
      }
    }
  }
  for (int i=0; i < 12; i++){
    if (i%2)
      writeRegGPIO(MCP23S18_GPIOA, ~(0x00));
    else
      writeRegGPIO(MCP23S18_GPIOA, ~(0xFF));
    delay(75);
  }
}


void loop() {
  static byte octave = 0;
  byte knobs[8] = {0};
  static byte knobs_old[8] = {0};
  byte knobs_changed = 0;
  byte buttons = 0;
  static byte buttons_state = 0;
  static byte buttons_cache = 0;
  byte buttons_changed = 0;

  //Get and process state of knobs
  for (int i = 0; i < 8; i++) {
    knobs[i] = readADC(i) >> 2; //Range: 0 - 255
    if (knobs[i] != knobs_old[i] && i != 7) {
      MIDI.sendControlChange(i, knobs[i] >> 1, MIDI_CHANNEL);
      knobs_old[i] = knobs[i];
    }
    if (i==7) {
      octave = knobs[7] >> 5; //Octave range: 8
    }
  }

  //Get and process state of buttons
  buttons = ~readRegGPIO(MCP23S18_GPIOB);
  if (buttons) {
    for (int i = 0; i < 8; i++) {
      if ((buttons & (1 << i)  &&  ((buttons_cache ^ buttons) & (1<<i)))) {
        if (buttons_state & (1 << i)){
          buttons_state &= ~(1 << i);
          MIDI.sendControlChange(i+8, 0, MIDI_CHANNEL);
        }
        else{
          buttons_state |= (1 << i);
          MIDI.sendControlChange(i+8, 127, MIDI_CHANNEL);
        } 
      }
    }
    writeRegGPIO(MCP23S18_GPIOA, ~buttons_state);
  }
  buttons_cache = buttons;

  // Get and process state of touch sensitive keyboard
  updateVelocityReads();
  writeRegCS(0, CAP1188_MAIN, readRegCS(0, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff = (uint16_t)readRegCS(0, CAP1188_SENINPUTSTATUS);
  writeRegCS(1, CAP1188_MAIN, readRegCS(1, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff |= (uint16_t)readRegCS(1, CAP1188_SENINPUTSTATUS) << 8;
  for(int i=0; i < 16;i++){
    if((voiceOnOff & ~voiceOnOff_o) & (0x1<<i)){
      gain[i] = vToGain(v_max[i]);
      v_max[i] = 0;
    }
  }
  for (int i = 0; i < 16; i++) {
    if ((voiceOnOff & (1 << i)) != (voiceOnOff_o & (1 << i))) {
      if (voiceOnOff & (1<<i))
        MIDI.sendNoteOn((23+i)+(12*octave), gain[i] >> 1, MIDI_CHANNEL); //Beginn with H-1
      else
        MIDI.sendNoteOff((23+i)+(12*octave), gain[i] >> 1, MIDI_CHANNEL);
    }
  }
  voiceOnOff_o = voiceOnOff;
}
