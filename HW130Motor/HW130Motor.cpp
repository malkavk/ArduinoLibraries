#include "HW130Motor.h"

HW130Motor::HW130Motor(): Motor{} {
    
}

void HW130Motor::init( byte pID, HW130 pHW130 ) {
    Motor::init( pID );
    this->setID(pID);
    this->_hw130 = pHW130;
}

void HW130Motor::setID( byte pID ) {
    switch (pID){
        case 1: {
            this->_pinA = 2;
            this->_pinB = 3;
            this->_pwm = 11;
            break;
        }
        case 2: {
            this->_pinA = 1;
            this->_pinB = 4;
            this->_pwm = 3;
            break;
        }
        case 3: {
            this->_pinA = 5;
            this->_pinB = 7;
            this->_pwm = 6;
            break;
        }
        case 4: {
            this->_pinA = 0;
            this->_pinB = 6;
            this->_pwm = 5;
            break;
        }
    }
    pinMode( this->_pwm, OUTPUT );
}

void HW130Motor::write( byte pPin, bool pState ) {
    this->_hw130.write( pPin, pState );
}


