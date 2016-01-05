#include "Global.h"

#define SERVO_MIN_POS	20
#define SERVO_MAX_POS	150
#define THRESHOLD		100

//Average light variable 
int averageLight;

void setup() 
{
	Serial.begin(9600);
	servo.attach(SERVO_SIGNAL_PIN);
	servo.write(SERVO_MIN_POS);
	Serial.println("start");
  
	//Get average light:
	averageLight = ldr.readAverage();

	//Print average light
	Serial.print("Average light:");
	Serial.println(averageLight); 
	
	delay(1000);
	Serial.println("start running");
}

void loop() 
{	
	int sample = ldr.read();
	int diff = abs(averageLight - sample);
	
	//print the difference
	Serial.print("Light: ");
	Serial.print(sample);
	Serial.print(", difference from average: "); 
	Serial.println(diff);
	
	//above threshold move servo:
	if(diff > THRESHOLD)
	{
		Serial.println("light changed drastically");
		servo.write(SERVO_MAX_POS);
		delay(1000);
		servo.write(SERVO_MIN_POS);
	}
	
	delay(200);
}
