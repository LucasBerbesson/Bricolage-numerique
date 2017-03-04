/***********************************************************
Description: Fait clignoter une LED toutes les secondes
***********************************************************/

int LED = 13;
int s = 300;
int o = 800;

void setup() {
  // On initialise le pin 13 en mode sortie
  pinMode(LED, OUTPUT);
  // On attend 1 seconde avant de commencer le programme
  delay(1000);
}

// La fonction loop se répète à l'infini
void loop() {
    for (int x = 1; x <= 3; x++) {
      ecrire_lettre(s);
    }
    for (int x = 1; x <= 3; x++) {
      ecrire_lettre(o);
    }
    for (int x = 1; x <= 3; x++) {
      ecrire_lettre(s);
    }
    // On attend 10 secondes avant le prochains "SOS"
    delay(10000);
}


void ecrire_lettre(int speed) {
  digitalWrite(LED, HIGH);
  delay(speed);
  digitalWrite(LED, LOW);
  delay(300);
}
