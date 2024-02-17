
#include <Arduino.h>

#ifdef SENSOR_DHT
#include "DHT/leitura_sensor.hpp"
#endif

#ifdef SENSOR_UV
#include "GUVA-S12SD/leitura_sensor.hpp"
#endif

void setup(){
  
  Serial.begin(9600);


  #ifdef SENSOR_UV
  
  iniciarSensorUV();
  
  #endif


  #ifdef SENSOR_DHT

  iniciarSensoresDHT();
  imprimirConfiguracoesBasicas(sensor1, 1);
  imprimirConfiguracoesBasicas(sensor2, 2);
  imprimirConfiguracoesBasicas(sensor3, 3);

  #endif 

}


void loop(){

  delay(2000);

  #ifdef SENSOR_UV

  lerSensorUV();

  #endif
    
  #ifdef SENSOR_DHT

  leituraSensor(dht1, 1);
  leituraSensor(dht2, 2);
  leituraSensor(dht3, 3);

  #endif

}


