/*
    Arquivo responsável por conter as funções de leitura dos sensores DHT11/DHT22,
    que são utilizados para medir a Umidade e a Temperatura do ambiente.

*/

#include "DHT/configs.hpp"
#include "DHT/init_sensor.hpp"


#ifdef SENSOR_DHT

void leituraSensor(DHT dht, int numeroSensor){

  // Fazendo a leitura dos valores  
  float umidade = dht.readHumidity();
  float temperaturaCelsius = dht.readTemperature();
  float temperaturaFahrenheit = dht.readTemperature(true);

  // Verifica se os valores estão nulos ou se tem algum problema com os atributos
  if (isnan(umidade) || isnan(temperaturaCelsius) || isnan(temperaturaFahrenheit)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Computando o indice de aquecimento para cada temperatura
  float indiceAquecimentoFahrenheit = dht.computeHeatIndex(temperaturaFahrenheit, umidade);
  float indiceAquecimentoCelsius = dht.computeHeatIndex(temperaturaCelsius, umidade, false);

  Serial.println("Sensor: " + String(numeroSensor));
  Serial.println("---------------------------------");

  Serial.print(F("Humidity: "));
  Serial.print(umidade);

  Serial.print(F("%  Temperature: "));
  Serial.print(temperaturaCelsius);
  Serial.print(F("°C "));

  Serial.print(temperaturaFahrenheit);
  Serial.print(F("°F  Heat index: "));

  Serial.print(indiceAquecimentoCelsius);
  Serial.print(F("°C "));

  Serial.print(indiceAquecimentoFahrenheit);
  Serial.println(F("°F"));

  Serial.print("-------------------------------------");

}

#endif