About This Library is intended for use with the NCD 16 Channel Spark compatible relay controller.

The intention of this library is to make use of the NCD 16 channel relay controller with Spark development web IDE as simple as possible for users.

How to use Setup and register your Spark interface module. Review all documentation provided by Spark on setup, programming, and use.

Install the Spark module into the relay controller and power it up with a regulated 12VDC power supply via on board screw terminals or 2.1mm barrel jack(center pin possitive).

Ensure your spark module is powered up and can establish connection to the Spark server.

Open the Spark WEB IDE for programming. Navigate to Libraries and import the NCD16Relay library into your new project.

Make sure to include the NCD16Relay Library and create an instance object of the NCD16Relay class in your application like this:

include "NCD16Relay.h"
NCD16Relay relayController;

Once you have a local instance of the class you can call all of its methods for interfacing with the 16 on board relays.

Features

Light weight library with very small memory footprint. Easy to use. Extensive command set for controlling and monitoring relays.

Methods for V1.0.0

'''//Constructor 
NCD16Relay(void);''' 

//Set Address. Indicate status of jumpers on board. Send 0 for not installed, send 1 for installed 
void setAddress(int a0, int a1, int a2); 

//Turn on Relay 
void turnOnRelay(int Relay); 

//Turn off Relay 
void turnOffRelay(int Relay); 

//Turn On all Relays 
void turnOnAllRelays(); 

//Turn Off All Relays 
void turnOffAllRelays(); 

//Turn On All Relays in bank 
void turnOnAllRelays(int bank); 

//Turn Off All Relays in bank 
void turnOffAllRelays(int bank); 

//Toggle Relay 
void toggleRelay(int relay); 

//Set status of all relays in bank 
void setBankStatus(int status, int bank); 

//Set status of all relays on board 
void setAllRelayStatus(int bank1, int bank2);

//Read status of relay. Valid return 0 for off 1 for on. 256 returned if there is an error 
int readRelayStatus(int relay); 

//Read status of all relays in bank. 0-255 valid return. 256 returned on error 
int readBankStatus(int bank);

Public accessible variables:

//Whether or not the controller is ready to accept commands 
bool initialized; 

//Status of relays in bank 1 byte 
bankOneStatus; 

//Status of relays in bank 2 byte 
bankTwoStatus;

Methods are quite intuitive but if there are any questions please let us know.
