#ifndef MYDELAY_H_
#define MYDELAY_H_

#define SAMPLE_RATE 163847
#define RING_BUF_SIZE 256

class MyDelay {
private:
	MyMem& _mem;
	byte _feedback, _mix;
	byte _mixInput, _mixDelay;
	uint32_t _delay, _pBuffer, _ramStartAdr, _pBufFlow;
	const uint32_t _bufSize;
	int readIntFromRAM(uint32_t adr){
		int val;
		val = _mem.readByteMem(1, adr) << 8;
		//val += 
	}
	void writeIntToRAM(uint32_t adr, int val){

	}
public:
	MyDelay(MyMem mem, uint32_t ramStartAdr, uint32_t bufSize) : _mem(mem), 
		_pBuffer(0), _ramStartAdr(ramStartAdr), _bufSize(bufSize), _feedback(0.5), 
		_delay(SAMPLE_RATE/1000 * 1), _pBufFlow(0) {
			setMix(0.5);
		}
	~MyDelay() {}
	void setDelay(unsigned int delay){
		_delay = delay * SAMPLE_RATE/1000);
	}
	uint32_t getDelay() const {
		return _delay;
	}
	void setFeedback(uint8_t feedback){
		_feedback = feedback;
	}
	uint8_t getFeedback() const {
		return _feedback;
	}
	void setMix(float mix) {
		if (mix <= 0.5){
        	_mixInput = 1.0;
        	_mixDelay = mix / 0.5;
    	}
    	else{
        	_mixDelay = 1.0;
        	_mixInput = -2.0 * (mix - 0.5) + 1.0;
    	}
	}
	float getMix(){
		return _mix;
	}
	int next(int input){
		int s = 0;
		uint32_t tmp_adr = 0;

		//Mem buffer is used as ring buffer with 2 periods
		/*if (_pBufFlow==0){
			_mem.writeBufToRAM(RING_BUF_SIZE/2, RING_BUF_SIZE/2);
			_mem.readBufFROMRAM(_pBufFlow, RING_BUF_SIZE/2);
		}
		else if (_pBufFlow==RING_BUF_SIZE/2){
			_mem.writeBufToRAM(0, RING_BUF_SIZE/2);
			_mem.readBufFROMRAM(_pBufFlow, RING_BUF_SIZE);
		}
		_pBufFlow++;
		_pBufFlow %= RING_BUF_SIZE;*/

		//Avoid floating points
		_mem.writeIntRAM(_pBuffer, _mem[_pBuffer] + input);
		tmp_adr = (_pBuffer + _delay) % _bufSize;
		_mem.writeIntRAM(tmp_adr, _mem[tmp_adr] + _mem[_pBuffer] * _feedback * _mixDelay);
		_mem.writeIntRAM(_pBuffer, _mem[_pBuffer] - input * (1.0 - _mixInput));
		s = _mem[_pBuffer];
		_mem.writeIntRAM(_pBuffer, _mem[_pBuffer] - input);
		_pBuffer++;
		_pBuffer %= _bufSize;

		return s;
	}
};

#endif
