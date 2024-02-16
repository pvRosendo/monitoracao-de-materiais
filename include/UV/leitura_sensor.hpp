#include "UV/configs.hpp"

#ifdef SENSOR_UV

/**
 * @brief Função responsável por ler o nível ultravioleta
 * 
*/
void ler_sensor_UV(){
  
  // Guarda na variável a leitura do sensor
  float valor_sensor_UV = analogRead(pino_sensor_UV);
  Serial.println(valor_sensor_UV);

  //Calcula tensao em milivolts para seguir a tabela
  float tensao_convertida = (valor_sensor_UV*(3.3/1023.0))*1000; 
  Serial.println(tensao_convertida);
  Serial.println("************************************");
  
  //Compara a tensão calculada com valores tabela do nível ultravioleta
  if(tensao_convertida <= 227) nivel_uv = "00";
  else if (tensao_convertida > 227 && tensao_convertida <= 318)   nivel_uv = "01";
  else if (tensao_convertida > 318 && tensao_convertida <= 408)   nivel_uv = "02";
  else if (tensao_convertida > 408 && tensao_convertida <= 503)   nivel_uv = "03";
  else if (tensao_convertida > 503 && tensao_convertida <= 606)   nivel_uv = "04";
  else if (tensao_convertida > 606 && tensao_convertida <= 696)   nivel_uv = "05";
  else if (tensao_convertida > 696 && tensao_convertida <= 795)   nivel_uv = "06";
  else if (tensao_convertida > 795 && tensao_convertida <= 881)   nivel_uv = "07";
  else if (tensao_convertida > 881 && tensao_convertida <= 976)   nivel_uv = "08";
  else if (tensao_convertida > 976 && tensao_convertida <= 1079)  nivel_uv = "09";
  else if (tensao_convertida > 1079 && tensao_convertida <= 1170) nivel_uv = "10";
  else nivel_uv = "11";

}

#endif