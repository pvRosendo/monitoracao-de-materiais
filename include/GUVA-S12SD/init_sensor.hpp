#ifdef SENSOR_UV

#include <Arduino.h>


// Pino do sensor de UV
int pinoSensorUV = A3;

// Variável que armazena o nível ultravioleta de acordo com a tabela
int nivelUV;


/**
 * @brief Função responsável por iniciar o sensor ultravioleta
 * 
*/
void iniciarSensorUV() {
  pinMode(pinoSensorUV, INPUT);
}

#endif