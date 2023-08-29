/*
    Arquivo responsável por contar as funções de leitura dos sensores DHT11,
    que são utilizados para medir a Umidade e a Temperatura do ambiente.

*/

// Importando a biblioteca do sensor
#include <dht.h>


// Definição do pino analógico utilizado pelo sensor DHT11
const int pino_do_DHT11_de_fora = A2;
const int pino_do_DHT11_de_dentro1 = A3;
const int pino_do_DHT11_de_dentro2 = A4;

// Instanciando o objeto do tipo DHT
dht DHT;


/**
 * @brief Função que realiza a leitura do sensor de Umidade e Temperatura
 * @param pino_sensor_de_umidade_e_temperatura Pino analógico utilizado pelo sensor
 * @param local_sensor Local onde o sensor está instalado fisicamente
*/
void leitura_sensores_DHT11(
    const int pino_sensor_de_umidade_e_temperatura, 
    String local_sensor
){

    // Lendo as informações diretamente do pino do sensor
    DHT.read11(pino_sensor_de_umidade_e_temperatura); 

    // Imprime qual o sensor que está sendo lido
    Serial.print(local_sensor);
    Serial.print(" - ");
    
    // Imprime o valor da Umidade
    Serial.print("Umidade: ");
    Serial.print(DHT.humidity); // Imprime o valor da umidade 
    Serial.print("%"); // Adiciona o símbolo de porcentagem para representar a umidade

    // Imprime o valor da Temperatura
    Serial.print(" / Temperatura: ");
    Serial.print(DHT.temperature, 0); // Imprime o valor da temperatura e retira a parte decimal
    Serial.println("*C"); // Adiciona o símbolo de graus Celsius

    // Adiciona um intervalo de 2 segundos - não diminuir esse valor
    delay(2000);
}