/***********************************************************
Description: Controler la couleur d'une LED RGB avec 3 potentiometres.
***********************************************************/

// Initialisation des Pins de la LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Initialisation des Pins des potentiometres
const int redPotPin = 0;
const int greenPotPin = 1;
const int bluePotPin = 2;

// Initialisation des variables de stockage des couleurs
int currentColorValueRed;
int currentColorValueGreen;
int currentColorValueBlue;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  currentColorValueRed = (255 - map( analogRead(redPotPin), 0, 1024, 0, 255 ) );
  currentColorValueBlue = (255 - map( analogRead(bluePotPin), 0, 1024, 0, 255 ) );
  currentColorValueGreen = (255 - map( analogRead(greenPotPin), 0, 1024, 0, 255 ) );

  analogWrite(redPin, currentColorValueRed);
  analogWrite(bluePin, currentColorValueBlue);
  analogWrite(greenPin, currentColorValueGreen);

}
