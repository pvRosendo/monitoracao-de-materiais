#include <Arduino.h>
#include "sensorDHT11.hpp"

void setup() {

  // Inicializa o monitor serial (necessário para podermos usar "Serial.print")
  Serial.begin(9600);

  // Determina um intervalo de 2 segundos antes de iniciar o código
  delay(2000);
}

void loop() {

  // Lendo as informações diretamente do pino do sensor
  DHT.read11(pinoDHT11); 

  // Imprime o valor da Umidade
  Serial.print("Umidade: ");
  Serial.print(DHT.humidity); // Imprime o valor da umidade 
  Serial.print("%"); // Adiciona o símbolo de porcentagem para representar a umidade
  
  // Imprime o valor da Temperatura
  Serial.print(" / Temperatura: ");
  Serial.print(DHT.temperature, 0); // Imprime o valor da temperatura e retira a parte decimal
  Serial.println("*C"); // Adiciona o símbolo de graus Celsius
  
  // Adiciona um intervalo de 2 segundos - não diminuir esse valor
  delay(2000);
}
