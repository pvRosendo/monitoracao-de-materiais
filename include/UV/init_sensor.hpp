#ifdef SENSOR_UV

#include "UV/configs.hpp"


/**
 * @brief Função responsável por iniciar o sensor ultravioleta
 * 
*/
void iniciarSensorUV(bool modo) {

  if (modo) { pinMode(pinoSensorUV, INPUT); }

}

void mostrar_nivel_uv(bool modo){
  
  if (modo){
    Serial.println("************************************");
    Serial.println("Nível ultravioleta: " + nivelUV);
    Serial.println("************************************");
  }
}

#endif