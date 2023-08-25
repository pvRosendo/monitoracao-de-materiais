#include <Arduino.h>
#include "sensorDHT11.hpp"
#include "sensorGuva-S12SD.hpp"

void setup() {

  // Inicializa o monitor serial (necessário para podermos usar "Serial.print")
  Serial.begin(9600);

  // Determina um intervalo de 2 segundos antes de iniciar o código
  delay(2000);

}

void loop() {

  // Chama a função de leitura do sensor de Umidade e Temperatura
  leituraSensorDHT11();

  // Chama a função de leitura do sensor de UV
  leituraSensorGuva();

}


 