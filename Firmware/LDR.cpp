#include "LDR.h"

LDR::LDR(int pin)
{
	analogPin = pin;
}

int LDR::read()
{
	return analogRead(analogPin);
}
int LDR::readAverage(int samples)
{
	int sum = 0;
	for(int i=0;i<samples;i++)
	{
		sum += read();
		delay(2); //minimum delay for prevent sticky samples
	}
	return (int)(sum/samples);
}



