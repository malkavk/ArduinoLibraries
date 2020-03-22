#include "HBridgeMotor.h"

HBridgeMotor::HBridgeMotor(): Motor{} {

}

void HBridgeMotor::init( byte pID, byte pPinA, byte pPinB, byte pPinPWM ) {
    Motor::init( pID );
    this->_pinA = pPinA;
    this->_pinB = pPinB;
    this->_pwm = pPinPWM;
    pinMode( this->_pinA, OUTPUT );
    pinMode( this->_pinB, OUTPUT );
    pinMode( this->_pwm, OUTPUT );
}


void HBridgeMotor::write( byte pPin, bool pState ) {
    digitalWrite( pPin, pState );
}