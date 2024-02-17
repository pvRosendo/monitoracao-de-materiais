/*
    Arquivo responsável por conter as funções iniciais de configuração dos sensores DHT11/DHT22
*/
#ifdef SENSOR_DHT



#include "DHT/configs.hpp"


void iniciarSensores(){
    dht1.begin();
    dht2.begin();
    dht3.begin();
}


/**
* @brief Função responsável por imprimir as informações básicas
* @param sensor Objeto sensor_t que armazena as informações básicas do sensor
*/
void imprimirConfiguracoesBasicas(sensor_t sensor, int numeroSensor) {

  // Coleta e imprime as informações básicas de temperatura do sensor
  informacoesDHT1.temperature().getSensor(&sensor);
  informacoesDHT2.temperature().getSensor(&sensor);
  informacoesDHT3.temperature().getSensor(&sensor);

  // Coleta e imprime as informações básicas de umidade do sensor
  informacoesDHT1.humidity().getSensor(&sensor);
  informacoesDHT2.humidity().getSensor(&sensor);
  informacoesDHT3.humidity().getSensor(&sensor);


  // Imprime as informações básicas de temperatura do sensor
  Serial.println("----------- Sensor Número " + (String) numeroSensor + "-----------");
  Serial.println("Temperatura");
  Serial.print  ("Tipo do Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Valor max:            "); Serial.print(sensor.max_value);   Serial.println("*C");
  Serial.print  ("Valor min:            "); Serial.print(sensor.min_value);   Serial.println("*C");
  Serial.print  ("Resolucao:            "); Serial.print(sensor.resolution);  Serial.println("*C");

  // Imprime as informações básicas de umidade do sensor
  Serial.println("------------------------------------");
  Serial.println("Umidade");
  Serial.print  ("Tipo do Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Valor max:            "); Serial.print(sensor.max_value);   Serial.println("%");
  Serial.print  ("Valor min:            "); Serial.print(sensor.min_value);   Serial.println("%");
  Serial.print  ("Resolucao:            "); Serial.print(sensor.resolution);  Serial.println("%");
  Serial.println("");

}

#endif