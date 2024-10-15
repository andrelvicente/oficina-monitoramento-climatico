#define sensorSolo A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int valorSolo = analogRead(sensorSolo);
  float umidadeSolo = map(valorSolo, 0, 1023, 100, 0);

  Serial.print("Umidade do Solo: ");
  Serial.print(umidadeSolo);
  Serial.println("%");

  delay(2000);
}
