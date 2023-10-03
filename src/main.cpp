/*
  Arquivo: main.cpp

  Responsável por conter a base do projeto, ou seja, o código principal.

*/


// Importando os arquivos necessários
#include <Arduino.h>
#include "sensores_DHT.hpp"
#include "sensor_UV.hpp"

// Objeto para usar as funções do sensor de Umidade e Temperatura
sensorDHT SENSOR_DHT;

// Variavel de ativação do sensor de UV (true = ativado, false = desativado)
bool ativar_sensor_UV = false;



/**
 * @brief Função básica de configuração do framework Arduino. Responsável por iniciar o código
 * 
*/
void setup() {

  // Inicializa o monitor serial (necessário para podermos usar "Serial.print")
  Serial.begin(9600);

  // Inicializa o sensor de UV
  iniciar_sensor_UV(ativar_sensor_UV);

  // Ativar os sensores de Umidade e Temperatura
  // Para desativar algum, basta comentar a linha correspondente
  SENSOR_DHT.ativar_sensor_dht(1);
  SENSOR_DHT.ativar_sensor_dht(2);
  SENSOR_DHT.ativar_sensor_dht(3);

  // Iniciando os sensores de Umidade e Temperatura
  SENSOR_DHT.iniciar_sensor("Sensor de Fora", 1);
  SENSOR_DHT.iniciar_sensor("Sensor de Dentro 1", 2);
  SENSOR_DHT.iniciar_sensor("Sensor de Dentro 2", 3);

  // Determina um intervalo de 2 segundos antes de iniciar o código
  delay(2000);
}

/**
 * @brief Função básica de loop do framework Arduino. Responsável por executar o código em loop
*/
void loop() {

  delay(2000);
  
  // Chama as funções de leitura dos sensores de Umidade e Temperatura
  SENSOR_DHT.leitura_sensores_dht();

  // Chama a função de leitura do sensor de UV
  ler_sensor_UV();

  // Imprime os dados do sensor de UV
  mostrar_nivel_uv(ativar_sensor_UV);

}


 