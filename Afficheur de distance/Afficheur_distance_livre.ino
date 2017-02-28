/***********************************************************
Description: Afficheur de distance
***********************************************************/

#include <LiquidCrystal.h>
const int pingPin = 2;  // pin Echo du module de distance Ultrason
const int trigPin  = 3; // pin Trig du module de distance Ultrason
long duration;
int distance;
LiquidCrystal lcd(7, 8, 9, 10, 11 , 12); // Initialisation de l'ecran LCD
void setup()
{
  pinMode(pingPin, INPUT); //configuration du pin Echo en mode input
  pinMode(trigPin, OUTPUT); //configuration du pin trig en mode output
  lcd.begin(16, 2); //Initialisation de l'ecran LCD qui comporte 2 lignes de 16 caracteres chacune
  delay(1000); 
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(pingPin, HIGH);
  distance = duration*0.034/2;
  lcd.setCursor(0, 0);   // on repositionne le curseur en haut a gauche
  lcd.print("distance: ");
  lcd.print(distance);  // On affiche la variable de distance
  lcd.print(" cm");
  delay(1000); // On attend 1 seconde avant de recalculer une nouvelle distance
}
