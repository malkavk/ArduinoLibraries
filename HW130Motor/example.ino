#include <HBridgeMotor.h>

HBridgeMotor motor;
byte speed1 = 25;
void setup() {
  /*
    EN: Motor initialization (Motor in H-bridge bind, Pin 1 bind, Pin 2 bind, PWM bind)
    PT-BR: Inicialização do motor (Ligação do motor na ponte H, ligação do pino 1, ligação do pino 2, ligação PWM).
  */
  motor.init( 1, 11, 10, 9);
}

void loop() {
  speed1 = ( ( speed1 - 25 ) < 150 ) ? ( 255 ) : ( speed1 - 25 );
  /*
    EN: Speed definition.
    PT-BR: Definição da velocidade.
  */
  motor.setSpeed( pSpeed );
  /*
    EN: Forward.
    PT-BR: Para frente.
  */
  motor.forward(); 
  delay( 500 );
  /*
    EN: Stop.
    PT-BR: Parar.
  */
  motor.stop();
  delay( 500 );
  /*
    EN: Backward.
    PT-BR: Para trás.
  */
  motor.backward();
  delay( 500 );
  /*
    EN: Break (actually HW-130 doesn't breaks, just stops motor alimentation).
    PT-BR: Frear (na verdade, o HW-130 não freia, apenas para a alimentação do motor).
  */
  motor.breakStop();
  delay( 500 );

}
