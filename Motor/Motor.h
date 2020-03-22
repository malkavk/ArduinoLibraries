#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <Arduino.h>



class Motor{
    public:
        Motor();
        void init( byte pID );
        virtual void write( byte pPin, bool pState );
        void forward();    
        void stop();
        void breakStop();
        void backward();
        void setSpeed( byte pSpeed );    

    protected:
        byte _ID;
        byte _pinA;
        byte _pinB;
        byte _pwm;
        byte _speed;
};


#endif