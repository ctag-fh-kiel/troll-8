/* TROLL8 uSynth Development Platform
	(c) 2017 www.creative-technologies.de
	Main author robert.manzke@fh-kiel.de
	Contributors Henrik Langer FH-Kiel, Alexander Konradi FH-Kiel
	Licensed under Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License
*/

#include <SPI.h>

#define SPI_SS 10

// CAP1188 definitions
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

void check_cs(byte chip)
{
  Serial.print("Product ID: 0x");
  Serial.println(readRegCS(chip, CAP1188_PRODID), HEX);
  Serial.print("Manuf. ID: 0x");
  Serial.println(readRegCS(chip, CAP1188_MANUID), HEX);
  Serial.print("Revision: 0x");
  Serial.println(readRegCS(chip, CAP1188_REV), HEX);
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
  
   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x40);
   SPI.transfer(adr);
   SPI.transfer(v);
   digitalWrite(SPI_SS, HIGH);
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

void check_gpio()
{
 static byte tog = 0;
 Serial.print("IOCONA: 0x");
 Serial.println(readRegGPIO(MCP23S18_IOCONA), HEX);
 Serial.print("IODIRA: 0x");
 Serial.println(readRegGPIO(MCP23S18_IODIRA), HEX);
 Serial.print("Tog: 0x"); Serial.println(tog);
 tog==0 ? tog=0xff : tog=0x0;
 writeRegGPIO(MCP23S18_IODIRA, tog);
}

void init_gpio()
{
  // port a as output
  writeRegGPIO(MCP23S18_IODIRA, 0x00);
  // port b as input with pullup
  writeRegGPIO(MCP23S18_IODIRB, 0xff);
  writeRegGPIO(MCP23S18_GPPUB, 0xff);
}

uint16_t readADC(byte chan)
{
   digitalWrite(A0, 0x0); // a2
   digitalWrite(A1, 0x1); // a1
   digitalWrite(A2, 0x0); // a0

   uint16_t res;
   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x01);
   res = SPI.transfer((chan<<4)|0x80);
   res = (res&0x03)<<8;
   res |= SPI.transfer(0);
   digitalWrite(SPI_SS, HIGH);
   return res;
}

void checkADC()
{
  uint16_t val;
  for(byte i=0; i<8; i++)
  {
    val = readADC(i);
    Serial.print(i);
    Serial.print(": ");
    Serial.print(val, HEX);
    Serial.print(" ");
  }
  Serial.println("");
}

byte readByteMem(byte memType, uint32_t adr)
{
   if(memType){
     digitalWrite(A0, 0x1); // a2
     digitalWrite(A1, 0x0); // a1
     digitalWrite(A2, 0x0); // a0
   }else{
     digitalWrite(A0, 0x0); // a2
     digitalWrite(A1, 0x1); // a1
     digitalWrite(A2, 0x1); // a0
   }

   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x03);  //read
   byte a = (adr >> 16);
   SPI.transfer(a);
   a = (adr >> 8);
   SPI.transfer(a);
   a = adr;
   SPI.transfer(a);
   byte res;
   res = SPI.transfer(0);
   digitalWrite(SPI_SS, HIGH);
   return res;
}

void  writeByteMem(byte memType, uint32_t adr, byte v)
{
   if(memType){
     digitalWrite(A0, 0x1); // a2 // SRAM
     digitalWrite(A1, 0x0); // a1
     digitalWrite(A2, 0x0); // a0
   }else{
     digitalWrite(A0, 0x0); // a2 // flash
     digitalWrite(A1, 0x1); // a1
     digitalWrite(A2, 0x1); // a0
   }

   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x02); //read
   byte a = (adr >> 16);
   SPI.transfer(a);
   a = (adr >> 8);
   SPI.transfer(a);
   a = adr;
   SPI.transfer(a);
   SPI.transfer(v);
   digitalWrite(SPI_SS, HIGH);
}

void flashWriteEnable(bool v)
{
   digitalWrite(A0, 0x0); // a2
   digitalWrite(A1, 0x1); // a1
   digitalWrite(A2, 0x1); // a0

   digitalWrite(SPI_SS, LOW);
   if(v)
    SPI.transfer(0x06);
   else
    SPI.transfer(0x04);

   digitalWrite(SPI_SS, HIGH);
}

void eraseFlash()
{
  flashWriteEnable(1);
   digitalWrite(A0, 0x0); // a2
   digitalWrite(A1, 0x1); // a1
   digitalWrite(A2, 0x1); // a0

   digitalWrite(SPI_SS, LOW);
   SPI.transfer(0x60);
   digitalWrite(SPI_SS, HIGH);
   flashWriteEnable(0);
}

byte flashReadID()
{
     digitalWrite(A0, 0x0); // a2
   digitalWrite(A1, 0x1); // a1
   digitalWrite(A2, 0x1); // a0

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
   return res;
}

// do not call in endless loop, exhausts flash write cycles quickly!
void checkFlash()
{
  Serial.print("Device ID: ");
  Serial.print(flashReadID(), HEX);
  Serial.print(" --> ");
  eraseFlash();
  flashWriteEnable(1);
  byte i;
  for(i=0;i<0xff;i++)
  {
    writeByteMem(0, i, i);
  }
  writeByteMem(0, i, i);
  flashWriteEnable(0);
  Serial.print("Flash: ");
  for(i=0;i<0xff;i++)
  {
    Serial.print(i, HEX);
    Serial.print(": ");
    Serial.print(readByteMem(0, i), HEX);
    Serial.print(" ");
  }
  Serial.print(i, HEX);
  Serial.print(": ");
  Serial.print(readByteMem(0, i), HEX);
  Serial.print(" ");
  Serial.println("");
}

void checkSRAM()
{
  byte i;
  for(i=0;i<0xff;i++)
  {
    writeByteMem(1, i, i);
  }
  writeByteMem(1, i, i);
  Serial.print("SRAM: ");
  for(i=0;i<0xff;i++)
  {
    Serial.print(i, HEX);
    Serial.print(": ");
    Serial.print(readByteMem(1, i), HEX);
    Serial.print(" ");
  }
  Serial.print(i, HEX);
  Serial.print(": ");
  Serial.print(readByteMem(1, i), HEX);
  Serial.print(" ");
  Serial.println("");
}

void setup() {
  Serial.begin(115200);

  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, HIGH); 

  reset_cs();
  reset_gpio();

  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  SPI.setDataMode(SPI_MODE0);

  init_cs();
  init_gpio();

}

void loop() {
  byte val;
  static int cs_old = 0;
  static int cs, dcsdt, maxdcsdt = 0;
  static byte voiceOnOff_old = 0;
  byte voiceOnOff;
  val = readRegGPIO(MCP23S18_GPIOB);
  writeRegGPIO(MCP23S18_GPIOA, val);
  //checkADC();
  cs = readRegCS(0, 0x10);
  dcsdt = cs-cs_old;
  cs_old=cs;
  if(dcsdt>maxdcsdt) 
    maxdcsdt = dcsdt;

  writeRegCS(0, CAP1188_MAIN, readRegCS(0, CAP1188_MAIN) & ~CAP1188_MAIN_INT);
  voiceOnOff = readRegCS(0, CAP1188_SENINPUTSTATUS);
  if((voiceOnOff&0x01) && voiceOnOff_old==0){
    Serial.print(maxdcsdt);Serial.print(", ");
    Serial.println(voiceOnOff);
    maxdcsdt = 0;
  }
  voiceOnOff_old = voiceOnOff;
    

}
