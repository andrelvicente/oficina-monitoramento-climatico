#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
#define sensorSolo A0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int valorSolo = analogRead(sensorSolo);
  float umidadeSolo = map(valorSolo, 0, 1023, 100, 0);

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Falha ao ler do sensor DHT11!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");

  Serial.print("Umidade do Ar: ");
  Serial.print(humidity);
  Serial.println("%");

  Serial.print("Umidade do Solo: ");
  Serial.print(umidadeSolo);
  Serial.println("%");

  delay(2000);
}