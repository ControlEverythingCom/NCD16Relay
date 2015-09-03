#include "spark_wiring_i2c.h"
#include "spark_wiring_usbserial.h"
#include "spark_wiring_constants.h"

class NCD16Relay{
public:
    //Constructor
    NCD16Relay(void);
    //Set Address.  Indicate status of jumpers on board.  Send 0 for not installed, send 1 for installed
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
    //Read status of relay. Valid return 0 for off 1 for on.  256 returned if there is an error
    int readRelayStatus(int relay);
    //Read status of all relays in bank.  0-255 valid.  256 returned on error
    int readBankStatus(int bank);
    
    //User Accessible Variables
    //Whether or not the controller is ready to accept commands
    bool initialized;
    //Status of relays in bank 1
    byte bankOneStatus;
    //Status of relays in bank 2
    byte bankTwoStatus;
private:
    void readStatus();
};
