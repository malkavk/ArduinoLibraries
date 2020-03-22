#ifndef _HW130MOTOR_H_
#define _HW130MOTOR_H_


#include <Arduino.h>
#include "Motor.h"
#include "HW-130.h"

class HW130Motor: public Motor {
    public:
        HW130Motor();
        void init( byte pID, HW130 pHW130 );
        void write( byte pPin, bool pState );
        void setID( byte pID );
    private:
        HW130 _hw130;
};

#endif