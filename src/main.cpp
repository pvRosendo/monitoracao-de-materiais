#include <Arduino.h>
#include "sensorDHT11.hpp"

void setup() {
  Serial.begin(9600); //INICIALIZA A SERIAL
  delay(2000); //INTERVALO DE 2 SEGUNDO ANTES DE INICIAR
}

void loop() {

  // Lendo as informações diretamente do pino do sensor
  DHT.read11(pinoDHT11); 

  // Imprime o valor da Umidade
  Serial.print("Umidade: ");
  Serial.print(DHT.humidity); 
  Serial.print("%"); //ESCREVE O TEXTO EM SEGUIDA
  Serial.print(" / Temperatura: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(DHT.temperature, 0); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
  Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL
  delay(2000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR
}
