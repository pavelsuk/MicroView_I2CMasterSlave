// Based on http://arduino.cc/en/Tutorial/MasterReader from Nicholas Zambetti <http://www.zambetti.com>
// Modified by pavelsuk
// Code available on 
// 	Github: https://github.com/pavelsuk/MicroView_I2CMasterSlave
// 	Codebender: 
// 		Master - https://codebender.cc/sketch:58263
// 		Slave  - https://codebender.cc/sketch:58279 


#include <MicroView.h>
#include <Wire.h>


void setup()
{
	Wire.begin();                // join i2c bus as master
	
	uView.begin();			// start MicroView
	uView.setFontType(0); 	// set font to the smallest font
}


void loop()
{
	uView.clear(PAGE);
	uView.setCursor(0,0); 	// points cursor to first line
  	uView.println("Reading");
 	uView.display();
   	uView.setCursor(0,10); 	// points cursor to first line
	readFromDevice(4, 16);
   	uView.setCursor(0,18); 	// points cursor to first line
	readFromDevice(5, 16);
	uView.display();
  	delay(100);
}


void readFromDevice(uint8_t devID, uint8_t byteCnt)
{
	uint8_t retBytes;
	
 	retBytes = Wire.requestFrom(devID, byteCnt);	// request 16 bytes, slave can send less
 	if(retBytes) {
		while(Wire.available()) // loop through all but the last
		{
			char c = Wire.read(); // receive byte as a character
			uView.print(c);         // print the character
		}
 	}

}

