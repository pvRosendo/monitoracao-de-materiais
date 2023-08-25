#include <dht.h>

// Definição do pino analógico utilizado pelo sensor DHT11
const int pinoDHT11 = A2;

// Instanciando o objeto do tipo DHT
dht DHT;


void leituraSensorDHT11(){

    // Lendo as informações diretamente do pino do sensor
    DHT.read11(pinoDHT11); 

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