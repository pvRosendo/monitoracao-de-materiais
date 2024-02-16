/*
    Arquivo responsável por contar as instanciações e configurações iniciais para
    os arquivos gerais dos sensores DHT11/DHT22
    
*/


#include <Adafruit_Sensor.h>                       // Biblioteca DHT Sensor Adafruit 
#include <DHT_U.h>
#include <DHT.h>

#ifdef SENSOR_DHT

// Dependendo do tipo, selecione um sensor retirando o comentário (duas barras "//") da linha correspondente

// Se os sensores forem do tipo DHT11
#define DHTTYPE1     DHT11                       // Sensor DHT11
#define DHTTYPE2     DHT22                       // Sensor DHT22
#define DHTTYPE3     DHT22                       // Sensor DHT22

// Definição dos pinos que serão utilizados para os sensores
#define DHTPIN1 2
#define DHTPIN2 3
#define DHTPIN3 4

// Instanciando os objetos e configurando os sensores com o pino e o tipo
DHT dht1(DHTPIN1, DHTTYPE1);
DHT_Unified informacoes_dht1(DHTPIN1, DHTTYPE1);

DHT dht2(DHTPIN2, DHTTYPE2);
DHT_Unified informacoes_dht2(DHTPIN2, DHTTYPE2);

DHT dht3(DHTPIN3, DHTTYPE3);
DHT_Unified informacoes_dht3(DHTPIN3, DHTTYPE3);


// Tempo de atraso para leitura do sensor
uint32_t delayMS;

// Instanciando o objeto sensor para armazenar os dados do sensor
sensor_t sensor_DHT_de_fora;
sensor_t sensor_DHT_de_dentro1;
sensor_t sensor_DHT_de_dentro2;

// Instanciando os objetos de eventos para armazenar as leituras dos sensores
sensors_event_t evento_DHT_de_fora;
sensors_event_t evento_DHT_de_dentro1;
sensors_event_t evento_DHT_de_dentro2;

#endif