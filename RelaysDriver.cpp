#include "RelaysDriver.h"

RelaysDriver::RelaysDriver(byte dataPin, byte clockPin, byte loadPin, byte relaysStatePin){
	
	_dataPin = dataPin;
	_clockPin = clockPin;
	_loadPin = loadPin;
	_relaysStatePin = relaysStatePin;
	
	pinMode(_dataPin, OUTPUT);
	pinMode(_clockPin, OUTPUT);
	pinMode(_loadPin, OUTPUT);
	pinMode(_relaysStatePin, OUTPUT);
	
	relaysOn();
}

void RelaysDriver::relayControl(byte relayNumber, bool state){
	
	switch(relayNumber){
		
	case 0:
		if (relays <= 1)state ? relays += 1 : relays -= 1;
		break;
	case 1:
		if (relays <= 2) state ? relays += 2 : relays -= 2;
		break;
	case 2:
		if (relays <= 4) state ? relays += 4 : relays -= 4;
		break;
	case 3:
		if (relays <= 8) state ? relays += 8 : relays -= 8;
		break;
	case 4:
		if (relays <= 16) state ? relays += 16 : relays -= 16;
		break;
	case 5:
		if (relays <= 32) state ? relays += 32 : relays -= 32;
		break;
	case 6:
		if (relays <= 64) state ? relays += 64 : relays -= 64;
		break;
	case 7:
		if (relays <= 128) state ? relays += 128 : relays -= 128;
		break;
		
	}
	
	digitalWrite(_loadPin, LOW);
	shiftOut(_dataPin, _clockPin, MSBFIRST, relays);
	digitalWrite(_loadPin, HIGH);
}

void RelaysDriver::relaysOff(){
	
	digitalWrite(_relaysStatePin, HIGH);
	
} 

void RelaysDriver::relaysOn(){
	
	digitalWrite(_relaysStatePin, LOW);
	
} 
