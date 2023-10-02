/*
  Arquivo: main.cpp

  Responsável por conter a base do projeto, ou seja, o código principal.

*/


// Importando os arquivos necessários
#include <Arduino.h>
#include "sensores_DHT.hpp"
#include "sensor_UV.hpp"


/**
 * @brief Função básica de configuração do framework Arduino. Responsável por iniciar o código
 * 
*/
void setup() {

  // Inicializa o monitor serial (necessário para podermos usar "Serial.print")
  Serial.begin(9600);

  // Inicializa o sensor de UV
  iniciar_sensor_UV();

  // Inicializa os sensores DHT
  dht1.begin();
  // dht2.begin();
  // dht3.begin();

  // Iniciando os sensores de Umidade e Temperatura
  iniciar_sensores_DHT(sensor_DHT_de_fora,    "Sensor de Fora",     1);
  // iniciar_sensores_DHT(sensor_DHT_de_dentro1, "Sensor de Dentro 1", 2);
  // iniciar_sensores_DHT(sensor_DHT_de_dentro2, "Sensor de Dentro 2", 3);

  // Determina um intervalo de 2 segundos antes de iniciar o código
  delay(2000);

}

/**
 * @brief Função básica de loop do framework Arduino. Responsável por executar o código em loop
*/
void loop() {

  delay(2000);
  // Chama as funções de leitura dos sensores de Umidade e Temperatura
  leitura_dos_sensores_DHT(evento_DHT_de_fora,    "Sensor de Fora",     1);
  // leitura_dos_sensores_DHT(evento_DHT_de_dentro1, "Sensor de Dentro 1", 2);
  // leitura_dos_sensores_DHT(evento_DHT_de_dentro2, "Sensor de Dentro 2", 3);

  // Chama a função de leitura do sensor de UV
  // ler_sensor_UV();

  // Serial.println(nivel_uv);
}


 