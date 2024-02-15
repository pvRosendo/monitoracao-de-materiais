/*
    Arquivo responsável por conter as funções de leitura dos sensores DHT11/DHT22,
    que são utilizados para medir a Umidade e a Temperatura do ambiente.

*/

#include "DHT/configs.hpp"
#include "DHT/init_sensor.hpp"

// Classe que faz todo tratamento dos dados do sensor DHT
class LEITURA_SENSOR_DHT : CONFIGURAR_SENSOR_DHT {

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





