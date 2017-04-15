/*
 * Class for RAM / Flash usage
 *
 * This class implements no exception handling for incorrect mem access!
 */

#ifndef MYMEM_H_
#define MYMEM_H_

#define RAM_MODE_BYTE 0x0
#define RAM_MODE_PAGE 0x80
#define RAM_MODE_SEQUENTIAL 0x40
#define BUFFER_SIZE 1024 //In bytes
#define SPI_FREQUENCY 16000000

#include <SPI.h>

class MyMem {
private:
	SPISettings _spi_settings;

public:
	byte buffer[BUFFER_SIZE] = {0};

	MyMem(unsigned int spi_frequency) {
		_spi_settings = SPISettings(spi_frequency, MSBFIRST, SPI_MODE0);
	}
	~MyMem() {}

  void initRAM(byte mode) {
    digitalWrite(A0, 0x1); // a2 / SRAM
    digitalWrite(A1, 0x0); // a1
    digitalWrite(A2, 0x0); // a0
    SPI.beginTransaction(_spi_settings);
    digitalWrite(SPI_SS, LOW);
    SPI.transfer(0x5);
    SPI.transfer(mode);
    SPI.transfer(0x1);
    byte tmp = SPI.transfer(mode);
    digitalWrite(SPI_SS, HIGH);
    SPI.endTransaction();
  }

	byte readByteMem(byte memType, uint32_t adr) const {
  	if (memType) {
    	digitalWrite(A0, 0x1); // a2
    	digitalWrite(A1, 0x0); // a1
    	digitalWrite(A2, 0x0); // a0
  	} else {
    	digitalWrite(A0, 0x0); // a2
    	digitalWrite(A1, 0x1); // a1
    	digitalWrite(A2, 0x1); // a0
  	}
  	SPI.beginTransaction(_spi_settings);
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
  	igitalWrite(SPI_SS, HIGH);
  	SPI.endTransaction();
  	
    return res;
	}

	void writeByteMem(byte memType, uint32_t adr, byte v) {
  	if (memType) {
    	digitalWrite(A0, 0x1); // a2 // SRAM
    	digitalWrite(A1, 0x0); // a1
    	digitalWrite(A2, 0x0); // a0
  	} else {
    	digitalWrite(A0, 0x0); // a2 // flash
    	digitalWrite(A1, 0x1); // a1
    	digitalWrite(A2, 0x1); // a0
  	}
  	SPI.beginTransaction(_spi_settings);
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
  	SPI.endTransaction();
	}

	void readBufMem(byte memType, uint32_t adr, unsigned int data_size) { //data size in bytes
		if (data_size > BUFFER_SIZE)
			return;

    if (memType) {
      digitalWrite(A0, 0x1); // a2 / SRAM
      digitalWrite(A1, 0x0); // a1
      digitalWrite(A2, 0x0); // a0
    } else {
      digitalWrite(A0, 0x0); // a2 // flash
      digitalWrite(A1, 0x1); // a1
      digitalWrite(A2, 0x1); // a0
    }
  	
  	SPI.beginTransaction(_spi_settings);
  	digitalWrite(SPI_SS, LOW);
  	SPI.transfer(0x03); // read instruction
  	byte a = (adr >> 16);
  	SPI.transfer(a);
  	a = (adr >> 8);
  	SPI.transfer(a);
  	a = adr;
  	SPI.transfer(a);
  	for (int i = 0; i < data_size; i++)
    	buffer[i] = SPI.transfer(0);
  	digitalWrite(SPI_SS, HIGH);
  	SPI.endTransaction();
	}

	void writeBufMem(byte memType, uint32_t adr, unsigned int data_size) {
		if (data_size > BUFFER_SIZE)
			return;

  	if (memType) {
      digitalWrite(A0, 0x1); // a2 / SRAM
      digitalWrite(A1, 0x0); // a1
      digitalWrite(A2, 0x0); // a0
    } else {
      digitalWrite(A0, 0x0); // a2 // flash
      digitalWrite(A1, 0x1); // a1
      digitalWrite(A2, 0x1); // a0
    }
  	SPI.beginTransaction(_spi_settings);
  	digitalWrite(SPI_SS, LOW);
  	SPI.transfer(0x02); // write instruction
  	byte a = (adr >> 16);
  	SPI.transfer(a);
  	a = (adr >> 8);
  	SPI.transfer(a);
  	a = adr;
  	SPI.transfer(a);
  	for (int i = 0; i < data_size; i++)
    	SPI.transfer(buffer[i]);
  	digitalWrite(SPI_SS, HIGH);
  	SPI.endTransaction();
	}

	void flashWriteEnable(bool v) {
  	digitalWrite(A0, 0x0); // a2
  	digitalWrite(A1, 0x1); // a1
  	digitalWrite(A2, 0x1); // a0
  	SPI.beginTransaction(_spi_settings);
  	digitalWrite(SPI_SS, LOW);
  	if (v)
    	SPI.transfer(0x06);
  	else
    	SPI.transfer(0x04);
  	digitalWrite(SPI_SS, HIGH);
  	SPI.endTransaction();
	}

	void eraseFlash() {
  	flashWriteEnable(1);
  	digitalWrite(A0, 0x0); // a2
  	digitalWrite(A1, 0x1); // a1
  	digitalWrite(A2, 0x1); // a0
  	SPI.beginTransaction(_spi_settings);
  	digitalWrite(SPI_SS, LOW);
  	SPI.transfer(0x60);
  	digitalWrite(SPI_SS, HIGH);
  	SPI.endTransaction();
  	flashWriteEnable(0);
	}

  int operator[](uint32_t adr) {
  	int ret = 0;
  	adr *= sizeof(int);
  	readBufMem(1, adr, sizeof(int));
  	for (int i=0; i<sizeof(int); i++)
  		ret = ret | buffer[i] << (8 * (sizeof(int)-i-1));
  	
    return ret;
	}

	void writeIntRAM(uint32_t adr, int val) {
		byte tmp = 0;
		adr *= sizeof(int);
		for (int i=0; i<sizeof(int); i++){
			tmp = val >> (8 * (sizeof(int)-i-1));
			buffer[i] = tmp;
		}
		writeBufMem(1, adr, sizeof(int));
	}

};

#endif
