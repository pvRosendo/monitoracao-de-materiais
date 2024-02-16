#include "UV/configs.hpp"

#ifdef SENSOR_UV

/**
 * @brief Função responsável por iniciar o sensor ultravioleta
 * 
*/
void iniciar_sensor_UV(bool modo) {

  if (modo) { pinMode(pino_sensor_UV, INPUT); }

}

void mostrar_nivel_uv(bool modo){
  
  if (modo){
    Serial.println("************************************");
    Serial.println("Nível ultravioleta: " + nivel_uv);
    Serial.println("************************************");
  }
}

#endif