/* TROLL8 uSynth Development Platform
	(c) 2017 www.creative-technologies.de
	Main author robert.manzke@fh-kiel.de
	Contributors Henrik Langer FH-Kiel, Alexander Konradi FH-Kiel
	Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
*/

/**
 * Flash writer for Troll8
 */

#define SPI_SS 10
#define SERIAL_BUF_SIZE 64
#define CMD_FLASH_READ 0x1
#define CMD_FLASH_WRITE 0x2

#define CONTROL_RATE 128

#include <SPI.h>

#include <ADC.h>
#include <MozziGuts.h>

#include "MyMem.h"
#include "Troll8_IO.h"

SPISettings spi_settings_global(2000000, MSBFIRST, SPI_MODE0);
MyMem mem(16000000);
byte serial_buffer[SERIAL_BUF_SIZE];
uint32_t data_size = 0, adr = 0;

void memTest(){
  
  delay(4000);

  for (int i=0; i < 100; i++){
    //mem.writeByteMem(1, i, 0);
    Serial.println(mem.readByteMem(1, i), HEX);
  }

  //mem.flashMemLockEnable(0);
  //mem.eraseFlash();
  //delay(1000);
  /*
  for (uint32_t i=0; i<20; i++){
    mem.writeIntRAM(i, 0xCACACACA);
    int tmp = mem[i];
    Serial.println(tmp, HEX);
  }*/
  /*
  for (byte i=0; i < 10; i++){
    mem.buffer[i] = i;
  }
  mem.writeBufMem(0, 0, 10);
  for (byte i=0; i < 10; i++){
    mem.buffer[i] = 0;
  }
  mem.readBufMem(0, 0, 10);
  for (byte i=0; i < 10; i++){
    Serial.println(mem.buffer[i], HEX);
  }*/

  //Serial.println(mem.flashReadStatus(), HEX);
  
  for (uint32_t i=0; i<10; i++){
    mem.writeByteMem(0, i, i);
    delay(10);
    Serial.println(mem.readByteMem(0, i));
  }
}

byte flashReadID()
{
   digitalWrite(A0, 0x0); // a2
   digitalWrite(A1, 0x1); // a1
   digitalWrite(A2, 0x1); // a0

   SPI.beginTransaction(spi_settings_global);
   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x90);
   SPI.transfer(0x00);
   SPI.transfer(0x00);
   SPI.transfer(0x00);
   SPI.transfer(0x00);
   byte res = SPI.transfer(0);
   SPI.transfer(0x00);
   SPI.transfer(0x00);
   digitalWrite(SPI_SS, HIGH);
   SPI.endTransaction();
   return res;
}

void setup(){
	Serial.begin(9600);

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

  //mem.flashMemLockEnable(0);
  //memTest();
  
  while(!Serial.available()){} //wait for serial data
  byte req = Serial.read();
  if (req == 0x02){
    mem.flashMemLockEnable(0);
    mem.eraseFlash();
    delay(1000);
    //Serial.print(0x0);
  }

  while(!Serial.available()){} //wait for serial data
  req = Serial.read();
  switch(req){
    case 0x01: //Data transfer
      for (int i=0; i<4; i++){
    		while(!Serial.available()){}
      	data_size = data_size | (Serial.read() << (8 * (3-i)));
      }
    
  		for (int i=0; i<4; i++){
    		while(!Serial.available()){}
      	adr = adr | Serial.read() << (8 * (3-i));
  		}

   		for (uint32_t i=0; i < data_size - 1; i++){
        while (!Serial.available()){}
        mem.writeByteMem(0, adr+i, Serial.read());
   		}
    break;
  }

  delay(100);
  startMozzi(CONTROL_RATE);
}

void updateControl(){

}

int updateAudio(){
  static int i = 0;
  int val = 0;

  val = mem.readByteMem(0, adr+i);
  i++;
  i %= data_size;
  
  return val << 2;
}

void loop(){
	audioHook();
}
