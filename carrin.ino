#include <VirtualWire.h>
#include <AFMotor.h>

AF_DCMotor motor1(1); //direito atras
AF_DCMotor motor2(2); // direito frente
AF_DCMotor motor3(3); // esquerdo frente
AF_DCMotor motor4(4); // esquerdo atras
int valor_recebido_RF;
char recebido_RF_char[40];

 
byte message[VW_MAX_MESSAGE_LEN];    
byte msgLength = VW_MAX_MESSAGE_LEN; 


int x = 2000;
char recebido=0;
int cont;

void setup() {

Serial.begin(9600);

    vw_set_rx_pin(2);
    vw_setup(2000);             
    vw_rx_start();             
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  uint8_t message[VW_MAX_MESSAGE_LEN];    
  uint8_t msgLength = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(message, &msgLength)) // Non-blocking
    {
        for (int i = 0; i < msgLength; i++)
       {
         recebido = message[i];
       }
     Serial.println(recebido);
    }
    if(recebido=='B'){tras();}
    if(recebido=='F'){frente();}
    if(recebido=='E'){tesquerda();}
    if(recebido=='D'){tdireita();}
    if(recebido=='P'){parado();}
    if(recebido=='L'){esquerda();}
    if(recebido=='R'){direita();}
}  

void frente(){
motor1.run(FORWARD); //
motor2.run(FORWARD); //
motor3.run(FORWARD);
motor4.run(BACKWARD);
delay(x);
}

void parado(){
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
delay(x);
}

void tras(){
motor1.run(BACKWARD); //
motor2.run(BACKWARD); //
motor3.run(BACKWARD);
motor4.run(FORWARD);
delay(x);
}

void tdireita(){
motor1.run(BACKWARD);
motor2.run(BACKWARD);
motor3.run(FORWARD);
motor4.run(BACKWARD);
delay(x);
}

void tesquerda(){
motor1.run(FORWARD); //
motor2.run(FORWARD); //
motor3.run(BACKWARD); //
motor4.run(FORWARD); //
delay(200);
}
///////////////////////////////////////////////
void direita(){
motor1.run(BACKWARD);
motor2.run(BACKWARD);
motor3.run(FORWARD);
motor4.run(BACKWARD);
delay(200);
}

void esquerda(){
motor1.run(FORWARD); //
motor2.run(FORWARD); //
motor3.run(BACKWARD); //
motor4.run(FORWARD); //
delay(200);
}
