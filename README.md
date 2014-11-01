MicroView_I2CMasterSlave
========================

Simple example of I2C communication between 2 Microviews. Based on [Master/Slave Arduino tutorial](http://arduino.cc/en/Tutorial/MasterWriter) 
from [Nicholas Zambetti](http://www.zambetti.com).


### Content
- /sketch: code for MicroView. 
  - [/sketch/I2C_Master.ino](/sketch/I2C_Master.ino) - Master, sending text and number 
  - [/sketch/I2C_Slave.ino](/sketch/I2C_Slave.ino) - Slave, listening on bus address 4
  - [/sketch/I2C_MasterAsReader.ino](/sketch/I2C_MasterAsReader.ino) - Master, listening to receive data from device 4 and 5
  - [/sketch/I2C_SlaveAsWriter.ino](/sketch/I2C_SlaveAsWriter.ino) - Slave, sending data on bus address 4 (or 5 - just change devID)
 
- /doc: documentation 
 
### Schema 
You need to connect both Microviews PIN2->PIN2 and PIN3->PIN3 (see photo). If you don't use one power supply, 
you have to connect at least GND on both Microviews. 
In the Master as Reader setup, you can use any Arduino device, just connect SDA-SDA and SLC-SLC. Tested with Arduino Pro Mini - you need to solder PIN4 (SDA) and PIN5 (SCL).
![Photo](/doc/master_slave.png) 
![Photo](/doc/master_2slaves.png) 
