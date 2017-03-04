/***********************************************************
Description: Controler la rotation d'un servo moteur à l'aide
d'un potentiometre.
***********************************************************/

//On commence par inclure la bibliothèque de commande des servo
#include <Servo.h>

// Initialisation du servo-moteur
Servo monServo;

//Initialisation de la valeur du potentiometre
int potentiometre = 0; 

void setup()
{
    monServo.attach(9); // on va commander l'angle du servo-moteur avec la pin 9
    monServo.write(0); // on place le servo à 0 degré au demarrage
}

void loop()
{
    int val = analogRead(potentiometre); // lecture de la valeur du potentiometre, comprise entre 0 et 1024
    int angle = val / 5.7; // On converti cette valeur en degrés entre 0 et 180.
    monServo.write(angle); // On envoi la commande de l'angle au servo-moteur
    delay(100); // petit temps de pause pour laisser le moteur respirer
}
