/*
  Arquivo: main.cpp

  Responsável por conter a base do projeto, ou seja, o código principal.

*/

#include <Arduino.h>

#ifdef SENSOR_DHT

#include "DHT/configs.hpp"
#include "DHT/init_sensor.hpp"
#include "DHT/leitura_sensor.hpp"
#endif

void setup(){
  Serial.begin(9600);

  #ifdef SENSOR_DHT

  iniciarSensores();
  imprimirConfiguracoesBasicas(sensor1, 1);
  imprimirConfiguracoesBasicas(sensor2, 2);
  imprimirConfiguracoesBasicas(sensor3, 3);

  #endif 

}


void loop(){

  delay(2000);

  #ifdef SENSOR_DHT

  leituraSensor(dht1, 1);
  leituraSensor(dht2, 2);
  leituraSensor(dht3, 3);

  #endif

}


