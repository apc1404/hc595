#ifndef RelaysDriver_h
#define RelaysDriver_h

#include <Arduino.h>

class RelaysDriver{
	
public:
	
	RelaysDriver(byte dataPin, byte clockPin, byte loadPin, byte relaysStatePin);
	
	void relayControl(byte relayNumber, bool state);
	
	void relaysOff();
	
	void relaysOn();

private:
	
	byte relays;
	
	byte _dataPin;
	byte _clockPin;
	byte _loadPin;
	byte _relaysStatePin;
};

#endif
