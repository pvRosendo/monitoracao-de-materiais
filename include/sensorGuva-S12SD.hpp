#include <Arduino.h>

int indiceUV;

void leituraSensorGuva(){
    // Leitura dos dados do sensor UV
  int leitura_porta = analogRead(A0);

  // De acordo com a leitura define o indice UV correspondente
  if (leitura_porta <= 10) {
    indiceUV = 0;
  } else if (leitura_porta > 10 && leitura_porta <= 46) {
    indiceUV = 1;
  } else if (leitura_porta > 46 && leitura_porta <= 65) {
    indiceUV = 2;
  } else if (leitura_porta > 65 && leitura_porta <= 83) {
    indiceUV = 3;
  } else if (leitura_porta > 83 && leitura_porta <= 103) {
    indiceUV = 4;
  } else if (leitura_porta > 103 && leitura_porta <= 124) {
    indiceUV = 5;
  } else if (leitura_porta > 124 && leitura_porta <= 142) {
    indiceUV = 6;
  } else if (leitura_porta > 142 && leitura_porta <= 162) {
    indiceUV = 7;
  } else if (leitura_porta > 162 && leitura_porta <= 180) {
    indiceUV = 8;
  } else if (leitura_porta > 180 && leitura_porta <= 200) {
    indiceUV = 9;
  } else if (leitura_porta > 200 && leitura_porta <= 221) {
    indiceUV = 10;
  } else {
    indiceUV = 11;
  }

  // Mostra os valores no Serial Monitor
  Serial.print("Valor porta: ");
  Serial.print(leitura_porta);
  Serial.print(" - Indice: ");
  Serial.println(indiceUV);

  delay(2000);
}