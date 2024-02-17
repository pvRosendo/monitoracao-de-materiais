/*
    Arquivo responsável por contar as instanciações e configurações iniciais para
    os arquivos gerais dos sensores DHT11/DHT22
    
*/
#ifdef SENSOR_DHT


#include <Adafruit_Sensor.h>                       // Biblioteca DHT Sensor Adafruit 
#include <DHT.h>
#include <DHT_U.h>


// Define os tipos dos sensores - para trocar de sensor basta apenas colocar DHT11
#define DHTTYPE1     DHT22
#define DHTTYPE2     DHT22
#define DHTTYPE3     DHT22

// Definição dos pinos que serão utilizados para os sensores
#define DHTPIN1 2
#define DHTPIN2 3
#define DHTPIN3 4

// Instanciando os objetos e configurando os sensores com o pino e o tipo
DHT dht1(DHTPIN1, DHTTYPE1);
DHT dht2(DHTPIN2, DHTTYPE2);
DHT dht3(DHTPIN3, DHTTYPE3);

// Instanciando os objetos para recolher as informações básicas
DHT_Unified informacoesDHT1(DHTPIN1, DHTTYPE1);
DHT_Unified informacoesDHT2(DHTPIN2, DHTTYPE2);
DHT_Unified informacoesDHT3(DHTPIN3, DHTTYPE3);

// Instanciando os tipos dos sensores
sensor_t sensor1;
sensor_t sensor2;
sensor_t sensor3;

#endif