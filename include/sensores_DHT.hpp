/*
    Arquivo responsável por contar as funções de leitura dos sensores DHT11/DHT22,
    que são utilizados para medir a Umidade e a Temperatura do ambiente.

*/

#include <Adafruit_Sensor.h>                       // Biblioteca DHT Sensor Adafruit 
#include <DHT_U.h>
#include <DHT.h>


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

// Classe exclusiva para manter os métodos de impressão de dados
class impressaoDadosSensorDHT {

    protected:

    /**
    * @brief Função responsável por imprimir as informações básicas
    * @param sensor Objeto sensor_t que armazena as informações básicas do sensor
    */
    void imprimir_configuracoes_basicas(sensor_t sensor){
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

    void imprimir_dados(float temperatura, float umidade) {
        
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


};

// Classe que faz todo tratamento dos dados do sensor DHT
class sensorDHT : impressaoDadosSensorDHT {

    private:

    // Variáveis de controle para ativar/desativar os sensores
    bool _primeiroSensorDHTAtivado = false;
    bool _segundoSensorDHTAtivado = false;
    bool _terceiroSensorDHTAtivado = false;

        

    public:

    // Variáveis para armazenar os valores dos dados
    float umidade_sensor1;
    float temperatura_sensor1;
    
    float umidade_sensor2;
    float temperatura_sensor2;
    
    float umidade_sensor3;
    float temperatura_sensor3;

    /**
    * @brief Função responsável por ativar o sensor que está sendo usado
    * @param numero_sensor Inteiro que armazena qual o número do sensor que está sendo iniciado
    */
    void ativar_sensor_dht(int numeroSensor) {
        if(numeroSensor == 1) {
            _primeiroSensorDHTAtivado = true;
        }
        else if(numeroSensor == 2) {
            _segundoSensorDHTAtivado = true;
        }
        else if(numeroSensor == 3) {
            _terceiroSensorDHTAtivado = true;
        }
    }

    /**
    * @brief Função responsável por iniciar os sensores DHT e pegar as informações básicas
    * @param nome_sensor String que armazena nome do sensor que está sendo iniciado
    */
    void iniciar_sensor(String nome_do_sensor, int numero_sensor) {
        
        String nome_sensor = nome_do_sensor;

        if (_primeiroSensorDHTAtivado && numero_sensor == 1) {
            // Imprime qual o sensor que está sendo iniciado
            Serial.println("Iniciando o ");
            Serial.print(nome_sensor);
            
            // Inicia o sensor
            dht1.begin();

            // Coleta e imprime as informações básicas de temperatura do sensor
            informacoes_dht1.temperature().getSensor(&sensor_DHT_de_fora);

            // Coleta e imprime as informações básicas de umidade do sensor
            informacoes_dht1.humidity().getSensor(&sensor_DHT_de_fora);

            imprimir_configuracoes_basicas(sensor_DHT_de_fora);
        }
        
        if (_segundoSensorDHTAtivado && numero_sensor == 2) {
            // Imprime qual o sensor que está sendo iniciado
            Serial.println("Iniciando o ");
            Serial.print(nome_sensor);
            
            // Inicia o sensor
            dht2.begin();

            // Coleta e imprime as informações básicas de temperatura do sensor
            informacoes_dht2.temperature().getSensor(&sensor_DHT_de_dentro1);

            // Coleta e imprime as informações básicas de umidade do sensor
            informacoes_dht2.humidity().getSensor(&sensor_DHT_de_dentro1);

            imprimir_configuracoes_basicas(sensor_DHT_de_dentro1);
        }
        
        if (_terceiroSensorDHTAtivado && numero_sensor == 3) {
            // Imprime qual o sensor que está sendo iniciado
            Serial.println("Iniciando o ");
            Serial.print(nome_sensor);
            
            // Inicia o sensor
            dht3.begin();

            // Coleta e imprime as informações básicas de temperatura do sensor
            informacoes_dht3.temperature().getSensor(&sensor_DHT_de_dentro2);

            // Coleta e imprime as informações básicas de umidade do sensor
            informacoes_dht3.humidity().getSensor(&sensor_DHT_de_dentro2);  

            imprimir_configuracoes_basicas(sensor_DHT_de_dentro2);
        }

    }

    // Função que irá ler os sensores para armazenar os dados obtidos
    void ler_sensores_dht(){
        delayMS = sensor_DHT_de_fora.min_delay / 1000;

        // Setando o tempo de atraso para leitura do sensor
        delay(delayMS);

        // dht1.temperature().getEvent(&event);
        // dht1.humidity().getEvent(&event);

        umidade_sensor1 = dht1.readHumidity();
        temperatura_sensor1 = dht1.readTemperature();

        umidade_sensor2 = dht2.readHumidity();
        temperatura_sensor2 = dht2.readTemperature();

        umidade_sensor3 = dht3.readHumidity();
        temperatura_sensor3 = dht3.readTemperature();

    }

    // Função para mostrar os dados dos sensores de acordo com os que estão ativados
    void leitura_sensores_dht() {

        if (!_primeiroSensorDHTAtivado && !_segundoSensorDHTAtivado && !_terceiroSensorDHTAtivado) {
            // Todos os sensores estão desativados.
            Serial.print("Todos os sensores estão desativados!");

        } 
        else if (_primeiroSensorDHTAtivado && !_segundoSensorDHTAtivado && !_terceiroSensorDHTAtivado) {
            // Apenas o primeiro sensor está ativado.
            ler_sensores_dht();
            imprimir_dados(temperatura_sensor1, umidade_sensor1);
        } 
        else if (!_primeiroSensorDHTAtivado && _segundoSensorDHTAtivado && !_terceiroSensorDHTAtivado) {
            // Apenas o segundo sensor está ativado.
            ler_sensores_dht();
            imprimir_dados(temperatura_sensor2, umidade_sensor2);
        } 
        else if (!_primeiroSensorDHTAtivado && !_segundoSensorDHTAtivado && _terceiroSensorDHTAtivado) {
            // Apenas o terceiro sensor está ativado.
            ler_sensores_dht();
            imprimir_dados(temperatura_sensor3, umidade_sensor3);
        } 
        else if (_primeiroSensorDHTAtivado && _segundoSensorDHTAtivado && !_terceiroSensorDHTAtivado) {
            // O primeiro e o segundo sensor estão ativados.
            ler_sensores_dht();
            imprimir_dados(temperatura_sensor1, umidade_sensor1);
            imprimir_dados(temperatura_sensor2, umidade_sensor2);
        } 
        else if (_primeiroSensorDHTAtivado && !_segundoSensorDHTAtivado && _terceiroSensorDHTAtivado) {
            // O primeiro e o terceiro sensor estão ativados.
            ler_sensores_dht();
            imprimir_dados(temperatura_sensor1, umidade_sensor1);
            imprimir_dados(temperatura_sensor3, umidade_sensor3);
        } 
        else if (!_primeiroSensorDHTAtivado && _segundoSensorDHTAtivado && _terceiroSensorDHTAtivado) {
            // O segundo e o terceiro sensor estão ativados.
            ler_sensores_dht();
            imprimir_dados(temperatura_sensor2, umidade_sensor2);
            imprimir_dados(temperatura_sensor3, umidade_sensor3);
        } 
        else if (_primeiroSensorDHTAtivado && _segundoSensorDHTAtivado && _terceiroSensorDHTAtivado) {
            // Todos os sensores estão ativados.
            ler_sensores_dht();
            imprimir_dados(temperatura_sensor1, umidade_sensor1);
            imprimir_dados(temperatura_sensor2, umidade_sensor2);
            imprimir_dados(temperatura_sensor3, umidade_sensor3);
        }
        
    }

};





