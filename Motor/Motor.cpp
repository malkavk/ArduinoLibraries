#include "Motor.h"


Motor::Motor(  ) {}

void Motor::init( byte pID ) {
    Serial.begin(9600);
    this->_ID = pID;
}

void Motor::forward() {
    Serial.print( this->_pwm );
    Serial.print( " - " );
    Serial.println( this->_speed );
    analogWrite( this->_pwm, this->_speed );
    this->write( this->_pinA, HIGH );
    this->write( this->_pinB, LOW );
}

void Motor::stop() {
    analogWrite( this->_pwm, 0 );
    this->write( this->_pinA, LOW );
    this->write( this->_pinB, LOW );
}

void Motor::breakStop() {
    analogWrite( this->_pwm, this->_speed );
    this->write( this->_pinA, HIGH );
    this->write( this->_pinB, HIGH );
}

void Motor::backward() {
    analogWrite( this->_pwm, this->_speed );
    this->write( this->_pinA, LOW );
    this->write( this->_pinB, HIGH );
}

void Motor::setSpeed( byte pSpeed ) {
    this->_speed = pSpeed;
    // Serial.print( this->_speed );
    // Serial.print(" - ");
    // Serial.println(this->_pwm);
    
}