#ifndef _HW130_H_
#define _HW130_H_

#include <Arduino.h>


class HW130{
    public:
        HW130();
        void init();
        void write( byte pPin, bool pState);
        void enable();
        void disable();
    private:
        int _sh;
        int _st;
        int _ds;
        int _enable;
};


#endif