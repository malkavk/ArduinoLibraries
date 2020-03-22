#define pinEcho 12
#define pinTrigger 11

#include <UltraSonicDistanceSensor.h>

/*
    EN: Object initializartion ( Definitions: Trigger pin, Echo pin, Current temperature).
    PT-BR: Inicialização do objeto (Definições: pino de gatilho, pino de eco e temperatua atual).
*/
UltraSonicDistanceSensor usds1( pinTrigger, pinEcho, 45 );

void setup() {
  /*
    EN: Distance unit (CM or INCH).
    PT-BR: Unidade de distância (CM ou INCH).
  */
  usds1.setLengthType( CM );
  Serial.begin( 9600 );
}

void loop() {
  /*
    EN: Sensing...
    PT-BR: Sentindo...
  */
  usds1.sensing();
  /*
    EN: Printing RAW measured distance.
    PT-BR: Imprimindo distância medida crua.
  */
  Serial.print( usds1.getDistance() );
  Serial.print(" - ");
  /*
    EN: Printing filtered distance.
    PT-BR: Imprimindo distância filtrada.
  */
  Serial.println( usds1.getFilteredDistance() );
}
