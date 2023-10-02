/*
    Arquivo responsável por contar as funções de leitura dos sensores DHT11/DHT22,
    que são utilizados para medir a Umidade e a Temperatura do ambiente.

*/

#include <Adafruit_Sensor.h>                       // Biblioteca DHT Sensor Adafruit 
#include <DHT_U.h>
#include <DHT.h>


// Dependendo do tipo, selecione um sensor retirando o comentário (duas barras "//") da linha correspondente

// Se os sensores forem do tipo DHT11, temos as definições para os 3 sensores
#define DHTTYPE1    DHT11                           // Sensor DHT11
#define DHTTYPE2    DHT11                           // Sensor DHT11
#define DHTTYPE3    DHT11                           // Sensor DHT11

// Para o caso de serem DHT22, temos as definições para os 3 sensores
// #define DHTTYPE1     DHT22                       // Sensor DHT22 ou AM2302
// #define DHTTYPE2     DHT22                       // Sensor DHT22 ou AM2302
// #define DHTTYPE3     DHT22                       // Sensor DHT22 ou AM2302

// Definição dos pinos que serão utilizados para os sensores
#define DHTPIN1 2
#define DHTPIN2 3
#define DHTPIN3 4

// Instanciando os objetos e configurando os sensores com o pino e o tipo
DHT dht1(DHTPIN1, DHTTYPE1);
DHT_Unified informacoes_dht1(DHTPIN1, DHTTYPE1);


DHT_Unified dht2(DHTPIN2, DHTTYPE2);
DHT_Unified dht3(DHTPIN3, DHTTYPE3);


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

/**
 * @brief Função responsável por iniciar os sensores DHT e pegar as informações básicas
 * @param sensor Objeto sensor_t que armazena as informações básicas do sensor
 * @param nome_sensor String que armazena nome do sensor que está sendo iniciado
 * @param numero_sensor Inteiro que armazena qual o número do sensor que está sendo iniciado
*/
void iniciar_sensores_DHT(sensor_t sensor, String nome_sensor, int numero_sensor) {

    // Imprime qual o sensor que está sendo iniciado
    Serial.println("Iniciando o ");
    Serial.print(nome_sensor);

    if(numero_sensor == 1) {
        // Coleta e imprime as informações básicas de temperatura do sensor
        informacoes_dht1.temperature().getSensor(&sensor);

        // Coleta e imprime as informações básicas de umidade do sensor
        informacoes_dht1.humidity().getSensor(&sensor);
    }
    else if(numero_sensor == 2) {
        // Coleta e imprime as informações básicas de temperatura do sensor
        dht2.temperature().getSensor(&sensor);

        // Coleta e imprime as informações básicas de umidade do sensor
        dht2.humidity().getSensor(&sensor);
    }
    else if(numero_sensor == 3) {
        // Coleta e imprime as informações básicas de temperatura do sensor
        dht3.temperature().getSensor(&sensor);

        // Coleta e imprime as informações básicas de umidade do sensor
        dht3.humidity().getSensor(&sensor);  
    }
    
    // Imprime as informações básicas de temperatura do sensor
    Serial.println("------------------------------------");
    Serial.println("Temperatura");
    Serial.print  ("Sensor:       "); Serial.println(sensor.name);
    Serial.print  ("Valor max:    "); Serial.print(sensor.max_value); Serial.println(" *C");
    Serial.print  ("Valor min:    "); Serial.print(sensor.min_value); Serial.println(" *C");
    Serial.print  ("Resolucao:    "); Serial.print(sensor.resolution); Serial.println(" *C");
    Serial.println("------------------------------------");
    
    // Imprime as informações básicas de umidade do sensor
    Serial.println("------------------------------------");
    Serial.println("Umidade");
    Serial.print  ("Sensor:       "); Serial.println(sensor.name);
    Serial.print  ("Valor max:    "); Serial.print(sensor.max_value); Serial.println("%");
    Serial.print  ("Valor min:    "); Serial.print(sensor.min_value); Serial.println("%");
    Serial.print  ("Resolucao:    "); Serial.print(sensor.resolution); Serial.println("%");
    Serial.println("------------------------------------");
}


float umidade;
float temperatura;


/**
 * @brief Função responsável por ler os dados dos sensores DHT
 * @param event Objeto sensor_event_t que armazena os dados do sensor
 * @param nome_sensor String que armazena qual o sensor que está sendo lido
*/
void leitura_dos_sensores_DHT(sensors_event_t event, String nome_sensor, int numero_sensor) {
    
    delayMS = sensor_DHT_de_fora.min_delay / 1000;

    // Setando o tempo de atraso para leitura do sensor
    delay(delayMS);

    // Condicional para verificar qual o sensor que está sendo lido
    // A partir disso, é feita a leitura do sensor e armazenada no objeto event
    if(numero_sensor == 1) {
        // dht1.temperature().getEvent(&event);
        // dht1.humidity().getEvent(&event);

        umidade = dht1.readHumidity();
        temperatura = dht1.readTemperature();
    }
    else if(numero_sensor == 2) {
        dht2.temperature().getEvent(&event);
        dht2.humidity().getEvent(&event);
    }
    else if(numero_sensor == 3) {
        dht3.temperature().getEvent(&event);
        dht3.humidity().getEvent(&event); 
    }

    // Tratamento de exceção para o caso de dar erro na leitura da temperatura
    if (isnan(temperatura)) {
        Serial.println("Erro na leitura da Temperatura!");
    }

    // Se não possuir nenhum tipo de erro, imprime a temperatura
    else{
        Serial.print("Temperatura: ");
        Serial.print(temperatura);
        Serial.println(" *C");
    }

    // Tratamento de exceção para o caso de dar erro na leitura de umidade
    if (isnan(umidade)) {
        Serial.println("Erro na leitura da Umidade!");
    }
    
    // Se não possuir nenhum tipo de erro, imprime a umidade
    else {
        Serial.print("Umidade: ");
        Serial.print(umidade);
        Serial.println("%");
    }

}