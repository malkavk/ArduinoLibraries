#include "HW-130.h"


HW130::HW130() {
    this->_sh = 4;
    this->_st = 12;
    this->_ds = 8;
    this->_enable = 7;
    
}

void HW130::init() {
    pinMode( this->_sh, OUTPUT );
    pinMode( this->_st, OUTPUT );
    pinMode( this->_ds, OUTPUT );
    pinMode( this->_enable, OUTPUT );
    this->enable();
}

void HW130::write( byte pPin, bool pState){
    static byte vBuffer;

    bitWrite(vBuffer, pPin % 8, pState);
  
    digitalWrite( this->_st, LOW );
  
    digitalWrite( this->_ds, LOW ); 
    digitalWrite( this->_sh, LOW );

    for (int vByte = 7; vByte >= 0; vByte--) {
  
        digitalWrite( this->_sh, LOW ); 
          
        digitalWrite( this->_ds,  bitRead( vBuffer, vByte ) );
          
        digitalWrite( this->_sh, HIGH );
        digitalWrite( this->_ds, LOW ); 
    }  
  
    digitalWrite( this->_st, HIGH);
}

void HW130::enable() {
    digitalWrite( this->_enable, LOW );
}

void HW130::disable() {
    digitalWrite( this->_enable, HIGH );
}

