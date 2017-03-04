//Pin de commande du module relai
const int POMPE_A_EAU= 8;

void setup(){
pinMode(POMPE_A_EAU,OUTPUT);
}

void loop() {
int sensorReading= analogRead(A1); //lire la valeur du capteur d'humidite

if (sensorReading > 2000){
  digitalWrite(POMPE_A_EAU,HIGH); //allumer la pompe à eau
  delay(1000); //pendant 1 seconde
  digitalWrite(POMPE_A_EAU,LOW); //eteindre la pompe à eau
  }
delay(10000);
}
