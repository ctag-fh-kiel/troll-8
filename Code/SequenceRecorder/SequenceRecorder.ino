/* TROLL8 uSynth Development Platform
	(c) 2017 www.creative-technologies.de
	Main author robert.manzke@fh-kiel.de
	Contributors Henrik Langer FH-Kiel, Alexander Konradi FH-Kiel
	Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
*/

//#include <ADC.h>  // Teensy 3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <Sample.h>
#include "Samples/piano.h"
#include "Samples/click.h"


#include <EventDelay.h>

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

#define CONTROL_RATE 64 // powers of 2 please
#define AUDIO_MODE STANDARD

uint16_t voiceOnOff = 0x0;
uint16_t voiceOnOff_o = 0x0;
byte gain[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
Sample<piano_NUM_CELLS, AUDIO_RATE> samplePiano[16];
//recording array with the form {Relative Time to next note, noteNumber, duration}
//uint16_t recordingArray[100][3] = {{1250, 2,128}, {2000, 3,248}, {300, 7,30}, {5000, 2,248}, {2000, 2, 248}};

//records can only save a maximum of 65 seconds delay to the next note
uint16_t recordingArray[50][3];
uint8_t lastNote = 0;
uint16_t sequenceNumber = 0;
uint16_t playlength = 0;
uint16_t recordingIndex = 0;
//since it saves microseconds and can get quite long . .
unsigned long recordStartTime = 0;
bool sequencerPlaying = false;
bool isRecording = false;
bool sequencerActive = false;

EventDelay timeControl(500);

byte cs_o[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte v_max[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


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

void writeRegCS(byte chip, byte adr, byte v) {
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

byte readRegCS(byte chip, byte adr) {
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

void addSignal() {


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
  reg |= 0x20; // sensitivity here, larger = less sensitive
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


uint16_t readADC(byte chan)
{

  digitalWrite(A0, 0x0); // a2
  digitalWrite(A1, 0x1); // a1
  digitalWrite(A2, 0x0); // a0

  uint16_t res;
  //noInterrupts();
  digitalWrite(SPI_SS, LOW);
  SPI.transfer(0x01);
  res = SPI.transfer((chan << 4) | 0x80);
  res = (res & 0x03) << 8;
  res |= SPI.transfer(0);
  digitalWrite(SPI_SS, HIGH);
  //interrupts();
  return res;
}

void setup() {
  Serial.begin(115200);
  startMozzi(); // start with default control rate of 64

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

  float f = (float)piano_SAMPLERATE / (float)piano_NUM_CELLS;
  for (int i = 0; i < 16; i++) {
    samplePiano[i] = Sample<piano_NUM_CELLS, AUDIO_RATE>(piano_DATA);
    samplePiano[i].setFreq(f);
    f *= 1.05946309;  // 12th root of 2
  }

  //timeControl.start(1000);

  writeRegGPIO(MCP23S18_GPIOA, 0xff);
  writeRegGPIO(MCP23S18_GPIOB, 0xff);
}

void updateVelocityReads() {
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

  for (byte i = 0; i < 16; i++) {
    v = cs[i] - cs_o[i];
    cs_o[i] = cs[i];
    if (v > v_max[i])
      v_max[i] = v;
  }
  //Serial.println(v_max[0]);
}

byte vToGain(int v) {
  if (v > 121)v = 121;
  if (v < 90)v = 90;
  v -= 90;
  v <<= 3;
  if (v < 32)v = 32;
  return (byte) v;
}

void updateControl() {
  // real-time piano stuff
  updateVelocityReads();

  writeRegCS(0, CAP1188_MAIN, readRegCS(0, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff = (uint16_t)readRegCS(0, CAP1188_SENINPUTSTATUS);

  writeRegCS(1, CAP1188_MAIN, readRegCS(1, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff |= (uint16_t)readRegCS(1, CAP1188_SENINPUTSTATUS) << 8;

  for (int i = 0; i < 16; i++) {
    if ((voiceOnOff & ~voiceOnOff_o) & (0x1 << i)) {
      gain[i] = vToGain(v_max[i]);
      v_max[i] = 0;
      samplePiano[i].start();

      //save, if recording is active and maximum number of notes not reached yet
      if (isRecording && (sizeof(recordingArray) / sizeof(recordingArray[0])) > recordingIndex) {
       
        //start at first note
        if (recordingIndex == 0) {
          recordingArray[recordingIndex][0] = 0;
        } else {
          recordStartTime = mozziMicros() - recordStartTime ;
          recordingArray[recordingIndex-1][0] = recordStartTime / 1000;
          //the last entry gets the delay from before . .so it has a duration
          recordingArray[recordingIndex][0] = recordStartTime / 1000;
        }
        recordingArray[recordingIndex][1] = i;
        recordingArray[recordingIndex][2] = gain[i];
        recordingIndex++;
        //reset counter since we are using a relative time sequence
        recordStartTime = mozziMicros();
        
      }
    }
  }
  voiceOnOff_o = voiceOnOff;

  //Push button 1 starts sequencer
  if ( readRegGPIO(MCP23S18_GPIOB) == 254) {
    sequenceNumber = 0 ;
    sequencerActive = true;
    recordStartTime = mozziMicros();
    writeRegGPIO(MCP23S18_GPIOA, 254);
  }

  //Push button 2 stops sequencer
  if ( readRegGPIO(MCP23S18_GPIOB) == 253) {
    sequencerActive = false;
    sequenceNumber = 0;
    timeControl.set(0);
    timeControl.start();
    writeRegGPIO(MCP23S18_GPIOA, 0xff);
  }

  //Push button 3 resets sequencer
  if ( readRegGPIO(MCP23S18_GPIOB) == 251) {
    sequenceNumber = 0;
  }

  //Button 8 Starts the recording
  if ( readRegGPIO(MCP23S18_GPIOB) == 127) {
    isRecording = true;
    writeRegGPIO(MCP23S18_GPIOA, 191);
  }

  //Button 7 Stops the recording
  if ( readRegGPIO(MCP23S18_GPIOB) == 191) {
    isRecording = false;
    lastNote = recordingIndex - 1;
    writeRegGPIO(MCP23S18_GPIOA, 0xff);
  }

  //Button 6 deletes recording array
  if(readRegGPIO(MCP23S18_GPIOB) == 223){
    lastNote = 0;
    recordingIndex = 0;

    for (int i = 0; i < 50; i++){
       recordingArray[i][0] = 0;
       recordingArray[i][1] = 0;
       recordingArray[i][2] = 0;
    }
  }

  //if the event is ready to play, allow the piano to play the note
  if (sequencerActive && timeControl.ready() && !sequencerPlaying && sequenceNumber <= lastNote) {
    samplePiano[recordingArray[sequenceNumber][1]].start();
    sequencerPlaying = true;
  }

   if (timeControl.ready() && sequencerActive) {
    if (sequencerPlaying) {
      if ((sizeof(recordingArray) / sizeof(recordingArray[0])) > sequenceNumber ) {
        sequenceNumber++;

     
        timeControl.set(recordingArray[sequenceNumber][0]);
        timeControl.start();
        sequencerPlaying = false;
      }
      else { 
        //the sequencer loops
        sequenceNumber = 0;
      }
    }
  }
}


int updateAudio() {

  int s = 0;

  if (voiceOnOff & 0x01 ) {
    s += (samplePiano[0].next() * gain[0]) >> 8;
  }
  if (voiceOnOff & 0x02 ) {
    s += (samplePiano[1].next() * gain[1]) >> 8;
  }
  if (voiceOnOff & 0x04 ) {
    s += (samplePiano[2].next() * gain[2]) >> 8;
  }
  if (voiceOnOff & 0x08 ) {
    s += (samplePiano[3].next() * gain[3]) >> 8;
  }
  if (voiceOnOff & 0x10) {
    s += (samplePiano[4].next() * gain[4]) >> 8;
  }
  if (voiceOnOff & 0x20) {
    s += (samplePiano[5].next() * gain[5]) >> 8;
  }
  if (voiceOnOff & 0x40) {
    s += (samplePiano[6].next() * gain[6]) >> 8;
  }
  if (voiceOnOff & 0x80) {
    s += (samplePiano[7].next() * gain[7]) >> 8;
  }
  if (voiceOnOff & 0x0100) {
    s += (samplePiano[8].next() * gain[8]) >> 8;
  }
  if (voiceOnOff & 0x0200) {
    s += (samplePiano[9].next() * gain[9]) >> 8;
  }
  if (voiceOnOff & 0x0400) {
    s += (samplePiano[10].next() * gain[10]) >> 8;
  }
  if (voiceOnOff & 0x0800) {
    s += (samplePiano[11].next() * gain[11]) >> 8;
  }
  if (voiceOnOff & 0x1000) {
    s += (samplePiano[12].next() * gain[12]) >> 8;
  }
  if (voiceOnOff & 0x2000) {
    s += (samplePiano[13].next() * gain[13]) >> 8;
  }
  if (voiceOnOff & 0x4000) {
    s += (samplePiano[14].next() * gain[14]) >> 8;
  }
  if (voiceOnOff & 0x8000 ) {
    s += (samplePiano[15].next() * gain[15]) >> 8;
  }

 
  //if a sound has been scheduled
  if ( sequencerActive) {
    //hotfix for recording entries beeing out of bound
    if(recordingArray[sequenceNumber][1]!= 256 && sequencerActive){
      // only works with  one at a time
          s += (samplePiano[recordingArray[sequenceNumber][1]].next() * 248) >> 8; 
          //if the next one is 50 ms together, play together . .needs some work . .
          if(recordingArray[sequenceNumber][0] < 30 && (sequenceNumber+1) <= lastNote){
              s += (samplePiano[recordingArray[sequenceNumber+1][1]].next() * 248) >> 8; 
          }
      }
  }
  return s;
}

void loop() {
  audioHook(); // required here
}




