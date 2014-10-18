// Based on http://arduino.cc/en/Tutorial/MasterWriter from Nicholas Zambetti <http://www.zambetti.com>
// Modified by pavelsuk
// Code available on 
// 	Github: https://github.com/pavelsuk/MicroView_I2CMasterSlave
// 	Codebender: 
// 		Master - https://codebender.cc/sketch:55265 
// 		Slave  - https://codebender.cc/sketch:55267 

#include <MicroView.h>
#include <Wire.h>



byte x = 0;

void setup()
{
	Wire.begin();
	
	uView.begin();			// start MicroView
	uView.setFontType(0); 	// set font to the smallest font
}


void loop()
{
  
	uView.clear(PAGE);
	uView.setCursor(0,0); 	// points cursor to first line
	uView.println("Writing..");
	
	uView.setCursor(0,10); 
	Wire.beginTransmission(4); // transmit to device #4
	Wire.write("x is ");        // sends five bytes
	uView.print("x is ");
	Wire.write(x);              // sends one byte  
	uView.print(x);
	uView.display();
	Wire.endTransmission();    // stop transmitting
	
	x++;
	delay(500);


}
