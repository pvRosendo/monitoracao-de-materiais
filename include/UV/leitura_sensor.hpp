#ifdef SENSOR_UV

#include "UV/configs.hpp"

/**
 * @brief Função responsável por ler o nível ultravioleta
 * 
*/
void lerSensorUV(){
  
  // Guarda na variável a leitura do sensor
  float valorSensorUV = analogRead(pinoSensorUV);
  Serial.println(valorSensorUV);

  //Calcula tensao em milivolts para seguir a tabela
  float tensaoConvertida = (valorSensorUV*(3.3/1023.0))*1000; 
  Serial.println(tensaoConvertida);
  Serial.println("************************************");
  
  //Compara a tensão calculada com valores tabela do nível ultravioleta
  if(tensaoConvertida <= 227) nivelUV = "00";
  else if (tensaoConvertida > 227  && tensaoConvertida <= 318 )   nivelUV = "01";
  else if (tensaoConvertida > 318  && tensaoConvertida <= 408 )   nivelUV = "02";
  else if (tensaoConvertida > 408  && tensaoConvertida <= 503 )   nivelUV = "03";
  else if (tensaoConvertida > 503  && tensaoConvertida <= 606 )   nivelUV = "04";
  else if (tensaoConvertida > 606  && tensaoConvertida <= 696 )   nivelUV = "05";
  else if (tensaoConvertida > 696  && tensaoConvertida <= 795 )   nivelUV = "06";
  else if (tensaoConvertida > 795  && tensaoConvertida <= 881 )   nivelUV = "07";
  else if (tensaoConvertida > 881  && tensaoConvertida <= 976 )   nivelUV = "08";
  else if (tensaoConvertida > 976  && tensaoConvertida <= 1079)   nivelUV = "09";
  else if (tensaoConvertida > 1079 && tensaoConvertida <= 1170)   nivelUV = "10";
  else nivelUV = "11";

}

#endif