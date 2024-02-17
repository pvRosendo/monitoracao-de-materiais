#include <Arduino.h>

#ifdef SENSOR_UV
// Pino do sensor de UV
int pinoSensorUV = A3;

// Variável que armazena o nível ultravioleta de acordo com a tabela
String nivelUV = "00";

#endif