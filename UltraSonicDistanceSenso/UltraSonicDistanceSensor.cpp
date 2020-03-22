/**
 * UltraSonic Distance Sensor Library for HC-SR04.
 *
 * CPP file for UltraSonic Distance Sensor Library.
 *
 * @author Kempes J. <malkavk@gmail.com>
 *			
 * @version V1.0.0
 * @date 2020-03-17
*/
#include "UltraSonicDistanceSensor.h"

#include "Kalman.h"

UltraSonicDistanceSensor::UltraSonicDistanceSensor( int triggePin, int echoPin, float temperature ):_kalmanFilter( 0.125, 32, 4000, 4000 ){
	
	this->_triggerPin = triggePin;
    this->_echoPin = echoPin;
    this->setTemperature( temperature );
    this->setLengthType( CM );

	pinMode( this->_triggerPin, OUTPUT );
	pinMode( this->_echoPin, INPUT );

}

void UltraSonicDistanceSensor::sensing(){
    long duration;
	float distance;
	digitalWrite( this->_triggerPin, LOW );
	delayMicroseconds(2);
	digitalWrite(_triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_triggerPin, LOW);	
	duration = pulseIn( _echoPin, HIGH );
    distance = ( duration / 2.0 ) / 1.09e6 * this->_soundSpeed;
	if( this->_lengthType == INCH)
		distance = distance * 0.393701;
	this->_distance = distance;
	this->_filteredDistance = this->_kalmanFilter.getFilteredValue( this->_distance );
}


void UltraSonicDistanceSensor::printDistance(){
	this->sensing();
	Serial.print( "Distance: " );
	Serial.print( this->_distance );
    Serial.println( this->_lengthText );
}

void UltraSonicDistanceSensor::setLengthType( int lengthType ) {
    this->_lengthType = lengthType;
    if ( this->_lengthType == CM ) {
        strcpy( this->_lengthText, " cm" );
    } else {
        strcpy( this->_lengthText, " IN" );
    }
}

void UltraSonicDistanceSensor::setTemperature( float temperature) {
    this->_temperature = temperature;
    this->_soundSpeed = ( 331.45 * sqrt( ( this->_temperature + 273.15 ) / 273.15 ) ) * 100.0;
}

float UltraSonicDistanceSensor::getDistance() {
	return this->_distance;
}

float UltraSonicDistanceSensor::getFilteredDistance() {
	return this->_filteredDistance;
}