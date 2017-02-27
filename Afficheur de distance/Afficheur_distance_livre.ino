/***********************************************************
Description: Afficheur de distance
Author: Lucas
***********************************************************/

#include <LiquidCrystal.h>
const int pingPin = 2;  // pin Echo du module de distance Ultrason
const int trigPin  = 3; // pin Trig du module de distance Ultrason

LiquidCrystal lcd(7, 8, 9, 10, 11 , 12); // Initialisation de l'ecran LCD
void setup()
{
   pinMode(pingPin, INPUT); //configuration du pin Echo en mode input
   pinMode(trigPin, OUTPUT); //configuration du pin trig en mode output
   lcd.begin(16, 2); //Initialisation de l'ecran LCD qui comporte 2 lignes de 16 caracteres chacune
   lcd.clear(); //
   lcd.setCursor(0,1); // On positionne le curseur en haut a gauche de l'ecran
   lcd.write("La Fabrique DIY"); // On affiche La Fabrique DIY au debut du programme
   delay(1000); //On attend 1000ms
}

void loop()
{
   int cm = ping(pingPin) ;
    lcd.setCursor(0, 0);   // on repositionne le curseur en haut a gauche
    lcd.print("distance: ");
    lcd.print(cm);  // On affiche la variable de distance
    lcd.print(" cm");
    delay(1000); // On attend 1 seconde avant de recalculer une nouvelle distance
}

int ping(int pingPin)
{
   // On cree des variables pour stocker les information de temps et de distance
   long duration, cm;
   // Le PING est une impulsion d'environ 5 microsecondes.
   pinMode(trigPin, OUTPUT);
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(5);
   digitalWrite(trigPin, LOW);

   pinMode(pingPin, INPUT);
   duration = pulseIn(pingPin, HIGH);  // Fonction Arduino qui permet de detecter une impulsion

   // convertion du temps en distance
   cm = microsecondsToCentimeters(duration);
   return cm ;
}

long microsecondsToCentimeters(long microseconds)
{
  // La vitesse du son est de 340 m/s soit 29 microsecondes par centimetre
  // Le ping genere par l'Arduino va faire un aller retour vers l'objet
  // Pour connaitre la distance a laquelle l'objet se situe, il faut diviser la distance
  // totale parcourue par 2 puis par 29
   return microseconds / 29 / 2;
}
