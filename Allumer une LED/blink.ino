/***********************************************************
Description: Fait clignoter une LED toutes les secondes
***********************************************************/


void setup() {
  // On initialise le pin 13 en mode sortie
  pinMode(LED_BUILTIN, OUTPUT);
}

// La fonction loop se répète à l'infini
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Allumer la LED
  delay(1000);                       // Attendre une seconde
  digitalWrite(LED_BUILTIN, LOW);    // Eteindre la LED
  delay(1000);                       // Attendre une seconde
}
