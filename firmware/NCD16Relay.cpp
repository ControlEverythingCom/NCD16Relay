#include "NCD16Relay.h"

int address = 0x20;

//Constructor
NCD16Relay::NCD16Relay(){
}

void NCD16Relay::setAddress(int a0, int a1, int a2){
    address = 0x20;
    if(a0 == 1){
        address = address | 1;
    }
    if(a1 == 1){
        address = address | 2;
    }
    if(a2 == 1){
        address = address | 4;
    }
    //Start I2C port
    Wire.begin();
    //Open connection to specified address
    Wire.beginTransmission(address);
    //Set all channels to outputs
    Wire.write(0);
    Wire.write(0);
    Wire.write(0);
    //Determine if device is present at that address
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }else{
        // Serial.println("Command Successful");
        initialized = true;
        readStatus();
    }
}

void NCD16Relay::turnOnRelay(int relay){
    byte bankValue;
    byte registerAddress;
    if(relay <= 8){
        bankValue = bankOneStatus;
        registerAddress = 18;
    }else{
        relay = relay - 8;
        bankValue = bankTwoStatus;
        registerAddress = 19;
    }
    switch(relay){
            case 1:
            bankValue = bankValue | 1;
            break;
            case 2:
            bankValue = bankValue | 2;
            break;
            case 3:
            bankValue = bankValue | 4;
            break;
            case 4:
            bankValue = bankValue | 8;
            break;
            case 5:
            bankValue = bankValue | 16;
            break;
            case 6:
            bankValue = bankValue | 32;
            break;
            case 7:
            bankValue = bankValue | 64;
            break;
            case 8:
            bankValue = bankValue | 128;
            break;
    }
    Wire.beginTransmission(address);
    Wire.write(registerAddress);
    Wire.write(bankValue);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }else{
        initialized = true;
        readStatus();
    }
}

void NCD16Relay::turnOffRelay(int relay){
    byte bankValue;
    byte registerAddress;
    if(relay <= 8){
        bankValue = bankOneStatus;
        registerAddress = 18;
    }else{
        relay = relay - 8;
        bankValue = bankTwoStatus;
        registerAddress = 19;
    }
    switch(relay){
            case 1:
            bankValue = bankValue & ~1;
            break;
            case 2:
            bankValue = bankValue & ~2;
            break;
            case 3:
            bankValue = bankValue & ~4;
            break;
            case 4:
            bankValue = bankValue & ~8;
            break;
            case 5:
            bankValue = bankValue & ~16;
            break;
            case 6:
            bankValue = bankValue & ~32;
            break;
            case 7:
            bankValue = bankValue & ~64;
            break;
            case 8:
            bankValue = bankValue & ~128;
            break;
    }
    Wire.beginTransmission(address);
    Wire.write(registerAddress);
    Wire.write(bankValue);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }else{
        initialized = true;
        readStatus();
    }
}

void NCD16Relay::turnOnAllRelays(){
    Wire.beginTransmission(address);
    Wire.write(18);
    Wire.write(255);
    Wire.write(255);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }else{
        initialized = true;
    }
}

void NCD16Relay::turnOffAllRelays(){
    Wire.beginTransmission(address);
    Wire.write(18);
    Wire.write(0);
    Wire.write(0);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }else{
        initialized = true;
    }
}

void NCD16Relay::turnOnAllRelays(int bank){
    Wire.beginTransmission(address);
    bank = 17+bank;
    Wire.write(bank);
    Wire.write(255);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }else{
        initialized = true;
    }
}

void NCD16Relay::turnOffAllRelays(int bank){
    Wire.beginTransmission(address);
    bank = 17+bank;
    Wire.write(bank);
    Wire.write(0);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }else{
        initialized = true;
    }
}

void NCD16Relay::toggleRelay(int relay){
    byte bankValue;
    byte registerAddress;
    if(relay <= 8){
        bankValue = bankOneStatus;
        registerAddress = 18;
    }else{
        relay = relay - 8;
        bankValue = bankTwoStatus;
        registerAddress = 19;
    }
    switch(relay){
            case 1:
            bankValue = bankValue ^ 1;
            break;
            case 2:
            bankValue = bankValue ^ 2;
            break;
            case 3:
            bankValue = bankValue ^ 4;
            break;
            case 4:
            bankValue = bankValue ^ 8;
            break;
            case 5:
            bankValue = bankValue ^ 16;
            break;
            case 6:
            bankValue = bankValue ^ 32;
            break;
            case 7:
            bankValue = bankValue ^ 64;
            break;
            case 8:
            bankValue = bankValue ^ 128;
            break;
    }
    Wire.beginTransmission(address);
    Wire.write(registerAddress);
    Wire.write(bankValue);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }else{
        initialized = true;
        readStatus();
    }
}

void NCD16Relay::setBankStatus(int status, int bank){
    Wire.beginTransmission(address);
    bank = 17+bank;
    Wire.write(bank);
    Wire.write(status);
    byte s = Wire.endTransmission();
    if(s != 0){
        initialized = false;
    }else{
        initialized = true;
        readStatus();
    }
}

void NCD16Relay::setAllRelayStatus(int bank1, int bank2){
    Wire.beginTransmission(address);
    Wire.write(18);
    Wire.write(bank1);
    Wire.write(bank2);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }else{
        initialized = true;
    }
}

int NCD16Relay::readRelayStatus(int relay){
    byte registerAddress;
    if(relay <= 8){
        registerAddress = 18;
    }else{
        relay = relay - 8;
        registerAddress = 19;
    }
    int value;
    switch(relay){
            case 1:
            value = 1;
            break;
            case 2:
            value = 2;
            break;
            case 3:
            value = 4;
            break;
            case 4:
            value = 8;
            break;
            case 5:
            value = 16;
            break;
            case 6:
            value = 32;
            break;
            case 7:
            value = 64;
            break;
            case 8:
            value = 128;
            break;
    }
    Wire.beginTransmission(address);
    Wire.write(registerAddress);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
        return 256;
    }
    Wire.requestFrom(address, 1);
    byte bankStatus = Wire.read();
    if(bankStatus & value){
        return 1;
    }else{
        return 0;
    }
}

int NCD16Relay::readBankStatus(int bank){
    bank = bank + 17;
    Wire.beginTransmission(address);
    Wire.write(bank);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
        return 256;
    }
    Wire.requestFrom(address, 1);
    byte bankStatus = Wire.read();
    return bankStatus;
}

void NCD16Relay::readStatus(){
    //Open Connection to controller
    Wire.beginTransmission(address);
    //Get current status of relays 1-8
    Wire.write(18);
    byte status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }
    Wire.requestFrom(address, 1);
    bankOneStatus = Wire.read();
    // Serial.print("Bank One Status: ");
    // Serial.println(bankOneStatus);
    //Get current status of relays 9-16
    Wire.write(19);
    status = Wire.endTransmission();
    if(status != 0){
        initialized = false;
    }
    Wire.requestFrom(address, 1);
    bankTwoStatus = Wire.read();
    // Serial.print("Bank Two Status: ");
    // Serial.println(bankTwoStatus);
    
}
