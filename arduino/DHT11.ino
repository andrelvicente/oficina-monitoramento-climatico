#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Falha ao ler do sensor DHT11!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println("°C");

  Serial.print("Umidade: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000);
}
