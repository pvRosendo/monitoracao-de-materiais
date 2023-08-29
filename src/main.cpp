/*
  Arquivo: main.cpp

  Responsável por conter a base do projeto, ou seja, o código principal.

*/


// Importando os arquivos necessários
#include <Arduino.h>
#include "sensorDHT11.hpp"
#include "sensorGuva-S12SD.hpp"


/**
 * @brief Função básica de configuração do framework Arduino. Responsável por iniciar o código
 * 
*/
void setup() {

  // Inicializa o monitor serial (necessário para podermos usar "Serial.print")
  Serial.begin(9600);

  // Determina um intervalo de 2 segundos antes de iniciar o código
  delay(2000);

}

/**
 * @brief Função básica de loop do framework Arduino. Responsável por executar o código em loop
*/
void loop() {

  // Chama as funções de leitura dos sensores de Umidade e Temperatura
  leitura_sensores_DHT11(pino_do_DHT11_de_fora, "Sensor de Fora");
  leitura_sensores_DHT11(pino_do_DHT11_de_dentro1, "Sensor de Dentro 1");
  leitura_sensores_DHT11(pino_do_DHT11_de_dentro2, "Sensor de Dentro 2");

  // Chama a função de leitura do sensor de UV
  leituraSensorGuva();

}


 