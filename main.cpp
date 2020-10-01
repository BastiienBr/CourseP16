

#include <Arduino.h>
#include <librobus.h>


int32_t EncodeurDroite = 0;
int32_t EncodeurGauche = 0;

float vitesse = 0;


void MasterSlave(float MasterMOTOR, int32_t MasterENCODEUR, int32_t SlaveENCODEUR)  //Prends en entrée la valeur du moteur maitre et les valeurs d'encodeur
  {
    float SlaveMOTOR = 0;   //valeur du moteur slave
    int32_t Diff_ENCODEUR = MasterENCODEUR - SlaveENCODEUR; //différence de pas entre les deux moteurs
    float kp = 0.0001;  //valeur de la constante P
    float ki = 0.0002;  //valeur de la constante I
    SlaveMOTOR = MasterMOTOR + kp * Diff_ENCODEUR + ki * Diff_ENCODEUR;  //équation de la valeur du moteur slave
    MOTOR_SetSpeed(1, SlaveMOTOR);

  }



void setup()
{
  BoardInit();  //pour librairie

  MOTOR_SetSpeed(0, 0); //Set les moteurs à 0
  MOTOR_SetSpeed(1, 0);
}

void loop() {


if(millis()<= 5000){  //Test de 5 secondes
  vitesse = 0.3;   //vitesse du moteur Master
  MOTOR_SetSpeed(0, vitesse);
  MasterSlave(vitesse, EncodeurGauche, EncodeurDroite);
  EncodeurGauche =ENCODER_Read(0);
  EncodeurDroite =ENCODER_Read(1);
  Serial.print(EncodeurDroite);
  Serial.print("  ");
  Serial.println(EncodeurGauche);
  
 
  }
  else{
    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);
  }
}