/***********************************************************
Description: Fait clignoter une LED toutes les secondes
***********************************************************/

int LED = 13;

void setup() {
  // On initialise le pin 13 en mode sortie
  pinMode(LED, OUTPUT);
  // On attend 1 seconde avant de commencer le programme
  delay(1000);
}

// La fonction loop se répète à l'infini
void loop() {
  // Trois signaux courts pour le premier "S"
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  delay(300);
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  delay(300);
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  delay(300);
  // Trois signaux longs pour le "O"
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(300);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(300);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(300);
  // Trois signaux courts pour le deuxième "S"
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  delay(300);
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  delay(300);
  digitalWrite(LED, HIGH);
  delay(300);
  digitalWrite(LED, LOW);
  delay(300);

  // On attend 10 secondes avant le prochains "SOS"
  delay(10000);
}
