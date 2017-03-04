/***********************************************************
Description: Une petite roue de la fortune.
Pour la lancer il suffit d'appuyer sur le bouton reste de l'arduino.
***********************************************************/

//On commence par inclure la bibliothèque de commande des servo
#include <Servo.h>

// Initialisation du servo-moteur
Servo monServo;


void setup()
{
    monServo.attach(9); // on va commander l'angle du servo-moteur avec la pin 9

    // On génère un angle aléatoire entre 0 et 180
    randomSeed(analogRead(A0));
    int angle_aleatoire = random(0, 180);

    // On agite l'aiguille pour le suspens
    delay(1000);
    monServo.write(0);
  	delay(1000);
    monServo.write(180);
  	delay(1000);
    monServo.write(0);
    delay(1000);
    monServo.write(180);
    delay(1000);

    // On place le servo sur l'angle aléatoire choisi
    monServo.write(angle_aleatoire);
}

void loop()
{
}
