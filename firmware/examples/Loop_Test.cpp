// This #include statement was automatically added by the Spark IDE.
#include "NCD16Relay/NCD16Relay.h"
NCD16Relay relayController;

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("Running Relay Controller test");
    relayController.setAddress(0, 0, 0);
    if(relayController.initialized){
        Serial.println("Controller is ready");
    }else{
        Serial.println("Controller not ready");
    }
    
}

void loop() {
    //Toggle all relays on, then off
    relayController.turnOffAllRelays();
    for(int i = 1; i < 17; i++){
        delay(50);
        relayController.toggleRelay(i);
    }
    for(int i = 1; i < 17; i++){
        delay(50);
        relayController.toggleRelay(i);
    }
    //Flash banks
    delay(100);
    relayController.turnOnAllRelays(1);
    delay(100);
    relayController.turnOnAllRelays(2);
    delay(100);
    relayController.turnOffAllRelays(1);
    delay(100);
    relayController.turnOffAllRelays(2);
    delay(100);
    relayController.turnOnAllRelays();
    delay(100);
    relayController.turnOffAllRelays();
    //Pulse each relay
    for(int i = 1; i < 17; i++){
        relayController.turnOnRelay(i);
        delay(50);
        relayController.turnOffRelay(i);
        delay(50);
    }
    //Set status of both banks in a pattern
    for(int i = 1; i < 256; i++){
        relayController.setAllRelayStatus(i, i);
        delay(20);
    }
}