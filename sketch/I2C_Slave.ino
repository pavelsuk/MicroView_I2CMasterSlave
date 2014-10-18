// Based on http://arduino.cc/en/Tutorial/MasterWriter from Nicholas Zambetti <http://www.zambetti.com>
// Modified by pavelsuk
// Code available on 
// 	Github: https://github.com/pavelsuk/MicroView_I2CMasterSlave
// 	Codebender: 
// 		Master - https://codebender.cc/sketch:55265 
// 		Slave  - https://codebender.cc/sketch:55267 


#include <MicroView.h>
#include <Wire.h>


void setup()
{
	Wire.begin(4);                // join i2c bus with address #4
	Wire.onReceive(receiveEvent); // register event
	
	uView.begin();			// start MicroView
	uView.setFontType(0); 	// set font to the smallest font
}


void loop()
{
	delay(100);
}


// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
	uView.clear(PAGE);
	uView.setCursor(0,0); 	// points cursor to first line
  	uView.println("Reading..");
 	uView.display();
   	uView.setCursor(0,10); 	// points cursor to first line
 	
	while(1 < Wire.available()) // loop through all but the last
	{
		char c = Wire.read(); // receive byte as a character
		uView.print(c);         // print the character
	}
	int x = Wire.read();    // receive byte as an integer
	uView.println(x);         // print the integer
	uView.display();

}