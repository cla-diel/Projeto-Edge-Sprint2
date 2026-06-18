# 🏃‍♂️ Estação de Avaliação Física do Atleta

## 📌 Descrição do Projeto

Este projeto consiste em uma **estação de avaliação física automatizada**, desenvolvida com Arduino, capaz de medir o desempenho de um atleta com base em tempo e velocidade.

A proposta simula um sistema utilizado em peneiras esportivas, onde o atleta percorre uma distância e seu desempenho é classificado automaticamente.

---

## 🎯 Objetivo

Desenvolver um sistema embarcado que:

* Meça o tempo de deslocamento do atleta
* Calcule a velocidade média
* Classifique o desempenho em categorias
* Exiba os resultados em tempo real
* Forneça feedback visual e sonoro

---

## ⚙️ Componentes Utilizados

* Arduino Uno R3
* Display LCD 16x2 (HD44780)
* Sensor Ultrassônico HC-SR04
* Botão (início da medição)
* LED verde (bom desempenho)
* LED vermelho (baixo desempenho)
* Buzzer (feedback sonoro)
* Protoboard e jumpers

---

## 🔌 Funcionamento do Sistema

1. O usuário pressiona o botão para iniciar a avaliação
2. O sistema aguarda o “atleta” sair da posição inicial
3. O sensor ultrassônico mede a distância em tempo real
4. Ao detectar a chegada do atleta, o tempo é registrado
5. A velocidade é calculada com base na distância fixa
6. O resultado é exibido no LCD
7. O sistema classifica o desempenho:

   * 🟢 Excelente
   * 🟡 Médio
   * 🔴 Ruim
8. LEDs e buzzer são acionados conforme o resultado

---

## 📏 Lógica de Cálculo

* Fórmula utilizada:

```
velocidade = distância / tempo
```

* Distância fixa adotada: **2 metros**
* Tempo medido em segundos
* Velocidade em m/s

---

## 🧠 Classificação de Desempenho

| Velocidade (m/s) | Classificação |
| ---------------- | ------------- |
| ≥ 2.5            | Excelente     |
| ≥ 1.5            | Médio         |
| < 1.5            | Ruim          |

---

## 💻 Estrutura do Código

O código foi organizado em:

* Inicialização de componentes (`setup`)
* Função de leitura do sensor ultrassônico
* Loop principal com:

  * Controle de estado
  * Medição
  * Cálculo
  * Classificação
  * Feedback

---

## 🧪 Simulação no Tinkercad

Devido à limitação do simulador:

* O sensor ultrassônico é controlado manualmente
* A distância é ajustada por um **slider**
* O usuário simula o movimento do atleta

### Passos:

1. Iniciar simulação
2. Pressionar o botão
3. Alterar a distância rapidamente (ex: 100 cm → 20 cm)
4. Observar o resultado no LCD

---

## 🚀 Possíveis Melhorias

* Uso de **dois sensores ultrassônicos** (início e fim)
* Substituição por sensores IR para maior precisão
* Integração com **ESP32** para envio de dados via Wi-Fi
* Armazenamento de resultados
* Interface com aplicativo ou dashboard

---

## 📚 Aplicações Reais

* Avaliação física esportiva
* Treinamento de atletas
* Monitoramento de desempenho
* Projetos educacionais em IoT e sistemas embarcados

---

## 📝 Considerações Finais

Este projeto demonstra a aplicação prática de conceitos de:

* Sensoriamento
* Processamento local (Edge Computing)
* Interação homem-máquina
* Sistemas embarcados

Mesmo em ambiente simulado, a solução representa uma abordagem funcional e escalável para avaliação de desempenho físico.

---
