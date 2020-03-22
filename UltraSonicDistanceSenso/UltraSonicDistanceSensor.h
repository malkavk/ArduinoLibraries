/**
 * UltraSonic Distance Sensor Library for HC-SR04.
 *
 * Header file for UltraSonic Distance Sensor Library.
 *
 * @author Kempes J. <malkavk@gmail.com>
 *			
 * @version V1.0.0
 * @date 2020-03-17
*/

#ifndef _UltraSonicDistanceSensor_H_
#define _UltraSonicDistanceSensor_H_

#include "Arduino.h"


#include "Kalman.h"

enum {
	CM = 0, INCH
};

class UltraSonicDistanceSensor{
	public :
		UltraSonicDistanceSensor( int triggePin, int echoPin, float temperature );
		
		void printDistance();
		
        void setLengthType( int lengthType );

        void setTemperature( float temperature );
        void sensing();
		float getFilteredDistance();
		float getDistance();
		
	private : 
		float _distance;
		int _echoPin;
		float _filteredDistance;
		Kalman _kalmanFilter;
        int _lengthType;
        char _lengthText[4];
        float _soundSpeed;
        float _temperature; 
		int _triggerPin;
};


#endif
