MicroView_I2CMasterSlave
========================

Simple example of I2C communication between 2 Microviews. Based on [Master/Slave Arduino tutorial](http://arduino.cc/en/Tutorial/MasterWriter) 
from [Nicholas Zambetti](http://www.zambetti.com).


### Content
- /sketch: code for MicroView. 
  - [/sketch/I2C_Master.ino](/sketch/I2C_Master.ino) - Master, sending text and number 
  - [/sketch/I2C_Slave.ino](/sketch/I2C_Slave.ino) - Slave, listening on bus address 4
- /doc: documentation 
 
### Schema 
You need to connect both Microviews PIN2->PIN2 and PIN3->PIN3 (see photo). If you don't use one power supply, 
you have to connect at least GND on both Micriviews.  
![Photo](/doc/master_slave.png) 
