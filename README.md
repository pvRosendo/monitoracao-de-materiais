# Monitoração de Materiais

## Descrição

Este projeto foi feito visando o desenvolvimento de um modelo de monitoração do envelhecimento de materiais. O mesmo consistia em uma caixa especializada com três sensores DHT e um sensor Ultravioleta para o monitoramento de quadros de artes que estariam em condições de exposição e sujeitos a envelhecimento característico. Para isso, este código serve para monitorar alguns parâmetros como: **umidade relativa**, **temperatura**, **índice de aquecimento**, **índice UV**, entre outros.

## Tecnologias

Neste projeto foram utilizadas as seguintes tecnologias: ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=plastic&logo=Arduino&logoColor=white), ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=plastic&logo=c%2B%2B&logoColor=white), ![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=plastic&logo=visual-studio-code&logoColor=white) e [PlatformIO](https://platformio.org).

## Página de Informações

Na wiki do projeto você encontra dados específicos de cada sensor utilizado além de todas informações acerca das tecnologias utilizadas. Acesse diretamente ou através do link abaixo:

  [Wiki do Projeto]()

## Como utilizar o projeto

> Você pode simular a parte dos sensores DHT22, com o código e circuito montado, no Wokwi. Para isso, acesse o link abaixo:
>
> [Simulação Wokwi](https://wokwi.com/projects/389995022263283713)

### Através do VSCode/PlatformIO

1. Instale o VSCode: https://code.visualstudio.com/download ;
2. Instale o PlatformIO: https://platformio.org/platformio-ide ;
3. Clone o projeto;
4. Abra o projeto a partir do VSCode e selecione o ambiente de operação desejado (garanta que o platformIO esteja iniciado e funcional). Estão disponíveis:
```
- SENSOR_DHT: leitura apenas do sensor DHT;
- SENSOR_UV: leitura apenas do sensor UV;
- GERAL: leitura de ambos os sensores.
```
4. Faça o upload do projeto para o módulo do Arduíno.

### Através do Arduino IDE

- Neste meu outro repositório você encontrará o projeto na versão de sketch para incorporar a Arduino IDE.

Link: https://github.com/pvRosendo/arduinoIDE-monitoracao-materiais

Lá você encontrará as informações necessárias para executar o projeto.

## Sugestões e correções

Em qualquer caso de sugestão ou correção de problema, fique a vontade para identificar e evidenciar. Ficarei imensamente grato.

## Referências

- [Documentação escrita por Amir Mohammad Shojaei](https://electropeak.com/learn/interfacing-guva-s12sd-uv-light-sensor-module-with-arduino/)
- [Repositório original Adafruit/DHT-sensor](https://github.com/adafruit/DHT-sensor-library)
- [Site Adafruit](https://learn.adafruit.com/dht)
- [Documentação Wokwi](https://docs.wokwi.com/parts/wokwi-dht22)
- [Documentação por Daniel Lemos Rosa](https://www.usinainfo.com.br/blog/projeto-sensor-uv-guva-s12sd-com-arduino/)
