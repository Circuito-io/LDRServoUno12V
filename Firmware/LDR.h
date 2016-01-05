#ifndef LDR_H
#define LDR_H

#include "arduino.h"

class LDR
{
	public:
		LDR(int pin);
		int read(); 
		int readAverage(int samples = 10);
		
	private:
		int analogPin;
		
};
#endif //LDR_H
