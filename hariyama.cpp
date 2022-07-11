#include <SharpIR.h>

// Declarando os Pinos

int SensorLinha_1 = 8;
int SensorLinha_2 = 7;//Pinos para os sensores de linha
#define ir A1 //Pino analogico do Sensor de Distância
#define model 1080 //Modelo do Sensor de Distância (1080 PARA O 2Y0A21Y)
SharpIR sensor( 1, A1 ); //PASSA OS PAR METROS PARA A FUNÇÃO (PINO ANALÓGICO, MODELO DO SENSOR)
// Motor 1
int PWMA = 2;
int IN1A = 6;
int IN2A = 7;

// Motor 2
int PWMB = 5;
int IN1B = 8;
int IN2B = 9;

//Declarando velocidade
int MotorSpeed1 = 100;
int MotorSpeed2 = 100;

void setup(){

  Serial.begin(9600); //Enviar e receber dados em 9600 baud
  pinMode(SensorLinha_1, INPUT); //DEFINE O PINO COMO ENTRADA DO SENSOR DE LINHA
  pinMode(SensorLinha_2, INPUT); //DEFINE O PINO COMO ENTRADA DO SENSOR DE LINHA
  pinMode(PWMA, OUTPUT); //DEFINE O PINO COMO SAÍDA DA POTÊNCIA DO MOTOR A
  pinMode(PWMB, OUTPUT); //DEFINE O PINO COMO SAÍDA DA POTÊNCIA DO MOTOR B
  pinMode(IN1A, OUTPUT); //DEFINE O PINO COMO SAÍDA DA ENTRADA 1A
  pinMode(IN2A, OUTPUT); //DEFINE O PINO COMO SAÍDA DA ENTRADA 2A
  pinMode(IN1B, OUTPUT); //DEFINE O PINO COMO SAÍDA DA ENTRADA 1B
  pinMode(IN2B, OUTPUT); //DEFINE O PINO COMO SAÍDA DA ENTRADA 2B
}  
   
void loop(){
    SL1 = digitalRead(SensorLinha_1);
    SL2 = digitalRead(SensorLinha_2);
    SD = sensor.getDistance();
    if(SL1 == LOW && SL2 == LOW){
      //Movimentação Normal
      if(SD > 500){
         MotorSpeed1 = 100;
         MotorSpeed2 = 100;   
      }
      //Movimentação Rápida
      else{
        MotorSpeed1 = 180;
        MotorSpeed2 = 180; 
      }
      // Move o motor A para frente
      digitalWrite(IN1A, HIGH);
      digitalWrite(IN2A, LOW);
      // Move o Motor B para frente
      digitalWrite(IN1B, HIGH);
      digitalWrite(IN2B, LOW);
      analogWrite(PWMA, MotorSpeed1);
      analogWrite(PWMB, MotorSpeed2);
      delay(100); 

    }
    else if(SL1 == High && SL2 == LOW) {
      //Fazer com que motor 1 gire mais rapido que 2
      MotorSpeed1 = 180;
      MotorSpeed2 = 100; 

      // Move o motor A para tras
      digitalWrite(IN1A, LOW);
      digitalWrite(IN2A, HiGH);
      // Move o Motor B para tras
      digitalWrite(IN1B, LOW);
      digitalWrite(IN2B, HIGH);
      analogWrite(PWMA, MotorSpeed1);
      analogWrite(PWMB, MotorSpeed2);
      delay(100); 
    }
    else{
      //Fazer Motor 2 girar mais rapido que 1
      MotorSpeed1 = 100;
      MotorSpeed2 = 180; 

      // Move o motor A para tras
      digitalWrite(IN1A, LOW);
      digitalWrite(IN2A, HiGH);
      // Move o Motor B para tras
      digitalWrite(IN1B, LOW);
      digitalWrite(IN2B, HIGH);
      analogWrite(PWMA, MotorSpeed1);
      analogWrite(PWMB, MotorSpeed2);
      delay(100); 
    }

     
}
