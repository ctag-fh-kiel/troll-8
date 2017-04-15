/*
 * Class for Troll8 I/O
 */

#ifndef TROLL8_IO_H_
#define TROLL8_IO_H_

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

#define SPI_SS 10
#define CAP1188_RESET A7
#define GPIO_RESET A6

#include <SPI.h>

class Troll8_IO {
private:
	SPISettings _spi_settings;

public:

	Troll8_IO(unsigned int spi_frequency) {
		_spi_settings = SPISettings(spi_frequency, MSBFIRST, SPI_MODE0);
    reset_cs();
    init_cs();
    reset_gpio();
    init_gpio();
	}
  ~Troll8_IO(){}

	void writeRegCS(byte chip, byte adr, byte v) {
 		digitalWrite(A0, chip & 0x04);
  	digitalWrite(A1, chip & 0x02);
  	digitalWrite(A2, chip & 0x01);
  	SPI.beginTransaction(_spi_settings);
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
  	SPI.beginTransaction(_spi_settings);
  	digitalWrite(SPI_SS, LOW);
  	SPI.transfer(0x7d);
  	SPI.transfer(adr);
  	SPI.transfer(0x7f);
  	res = SPI.transfer(0);
  	digitalWrite(SPI_SS, HIGH);
  	SPI.endTransaction();

  	return res;
	}

	void reset_cs() {
  	pinMode(CAP1188_RESET, OUTPUT);
  	digitalWrite(CAP1188_RESET, LOW);
  	delay(100);
  	digitalWrite(CAP1188_RESET, HIGH);
  	delay(100);
  	digitalWrite(CAP1188_RESET, LOW);
  	delay(100);
	}

	void init_cs_chip(byte chip) {
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

	void init_cs() {
  	init_cs_chip(0);
  	init_cs_chip(1);
	}

	void init_gpio() {
  	// port a as output
  	writeRegGPIO(MCP23S18_IODIRA, 0x00);
  	// port b as input with pullup
  	writeRegGPIO(MCP23S18_IODIRB, 0xff);
  	writeRegGPIO(MCP23S18_GPPUB, 0xff);
	}

	void reset_gpio() {
  	pinMode(GPIO_RESET, OUTPUT);
  	digitalWrite(GPIO_RESET, HIGH);
  	delay(100);
  	digitalWrite(GPIO_RESET, LOW);
  	delay(100);
  	digitalWrite(GPIO_RESET, HIGH);
  	delay(100);
	}

	void writeRegGPIO(byte adr, byte v) {
	  digitalWrite(A0, 0x1); // a2
  	digitalWrite(A1, 0x0); // a1
  	digitalWrite(A2, 0x1); // a0
  	SPI.beginTransaction(_spi_settings);
  	digitalWrite(SPI_SS, LOW);
  	SPI.transfer(0x40);
  	SPI.transfer(adr);
  	SPI.transfer(v);
  	digitalWrite(SPI_SS, HIGH);
  	SPI.endTransaction();
	}

	byte readRegGPIO(byte adr) {
  	digitalWrite(A0, 0x1); // a2
  	digitalWrite(A1, 0x0); // a1
  	digitalWrite(A2, 0x1); // a0
  	byte res = 0;
  	SPI.beginTransaction(_spi_settings);
  	digitalWrite(SPI_SS, LOW);
  	SPI.transfer(0x41);
  	SPI.transfer(adr);
  	res = SPI.transfer(0);
  	digitalWrite(SPI_SS, HIGH);
 		SPI.endTransaction();

  	return res;
	}

	uint16_t readADC(byte chan) {
  	digitalWrite(A0, 0x0); // a2
  	digitalWrite(A1, 0x1); // a1
  	digitalWrite(A2, 0x0); // a0
  	uint16_t res;
  	SPI.beginTransaction(_spi_settings);
  	digitalWrite(SPI_SS, LOW);
  	SPI.transfer(0x01);
  	res = SPI.transfer((chan << 4) | 0x80);
  	res = (res & 0x03) << 8;
  	res |= SPI.transfer(0);
  	digitalWrite(SPI_SS, HIGH);
  	SPI.endTransaction();

  	return res;
	}
};

#endif //TROLL8_IO_H_
