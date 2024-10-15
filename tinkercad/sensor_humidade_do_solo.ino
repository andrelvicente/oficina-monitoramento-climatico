const int limiteUmidade = 87;
int umidadeSolo = 0;
const int pinoSensor = A0;
const int LED = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  umidadeSolo = analogRead(pinoSensor);
 
  // Converte a variação do sensor de 0 a 1023 para 0 a 100
  umidadeSolo = map(umidadeSolo, 1023, 0, 0, 100);
 
  // Porcentagem de umidade do solo
  Serial.println(umidadeSolo);
 
  // Verifica se umidade está no limite estipulado
 
  if( umidadeSolo > limiteUmidade ) {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
 
  delay(1000);    
}