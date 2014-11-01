// Based on http://arduino.cc/en/Tutorial/MasterReader from Nicholas Zambetti <http://www.zambetti.com>
// Modified by pavelsuk
// Code available on 
// 	Github: https://github.com/pavelsuk/MicroView_I2CMasterSlave
// 	Codebender: 
// 		Master - https://codebender.cc/sketch:58263
// 		Slave  - https://codebender.cc/sketch:58279 


#include <Wire.h>

uint8_t devID = 4;
// uint8_t devID = 5;


byte x = 0;

void setup()
{
	Wire.begin(devID); // start as slave
	Wire.onRequest(requestEvent); // register event handler 
}


void loop()
{
}

void requestEvent()
{
	char buffer[9];
	sprintf(buffer, "id %d: %d", devID, x++);
 	Wire.write(buffer); 
}