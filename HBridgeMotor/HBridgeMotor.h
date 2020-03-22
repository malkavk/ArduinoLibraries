#ifndef _HBRIDGEMOTOR_H_
#define _HBRIDGEMOTOR_H_

#include "Motor.h"
#include <Arduino.h>

class HBridgeMotor: public Motor {
    public:
        HBridgeMotor();
        void init( byte pID, byte pPinA, byte pPinB, byte pPinPWM );
        void write( byte pPin, bool pState );
    private:
        
};

#endif