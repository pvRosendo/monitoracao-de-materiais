/*
    Arquivo responsável por conter as funções iniciais de configuração dos sensores DHT11/DHT22
*/



#include "DHT/configs.hpp"


// Classe exclusiva para manter os métodos de impressão de dados
class CONFIGURAR_SENSOR_DHT {

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