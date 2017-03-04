/***********************************************************
Description: Feu rouge de circulation
***********************************************************/

// Initialisation des Pins de la LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop()
{
  // le feu est rouge
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);

  delay(4000);

  // le feu est vert
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);

  delay(4000);

  // le feu est orange
  analogWrite(redPin, 255);
  analogWrite(greenPin, 177);
  analogWrite(bluePin, 0);
  
  delay(1000);

}
