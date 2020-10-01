#include <Arduino.h>
#include <librobus.h>
int32_t EncodeurDroite = 0;
int32_t EncodeurGauche = 0;

unsigned long compteur = 5000;
void setup() {

BoardInit();

MOTOR_SetSpeed(0, 0);
MOTOR_SetSpeed(1, 0);


}

void loop() {


if(millis()<= 5000){
  
  MOTOR_SetSpeed(0, 0.01);
  MOTOR_SetSpeed(1, 0.01);
  EncodeurGauche =ENCODER_Read(0);
  EncodeurDroite =ENCODER_Read(1);
  Serial.print(EncodeurDroite - EncodeurGauche);
  Serial.print("  ");
  Serial.println(EncodeurGauche);
  }
  else{
    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0.);
  }
}