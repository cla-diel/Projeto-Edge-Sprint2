#include <LiquidCrystal.h>

// LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// SENSOR ULTRASSÔNICO
const int trigPin = 10;
const int echoPin = 9;

// OUTROS COMPONENTES
const int botaoPin = 13;
const int ledVerde = 6;
const int ledVermelho = 8;
const int buzzer = 7;

// VARIÁVEIS
unsigned long tempoInicio;
unsigned long tempoFim;
bool medindo = false;

float distanciaInicial = 100; // cm (referência)
float distanciaFinal = 20;    // cm (quando atleta passa)

// ======================
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(botaoPin, INPUT_PULLUP);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Pronto...");
}

// ======================
float medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracao = pulseIn(echoPin, HIGH);

  float distancia = duracao * 0.034 / 2;
  return distancia;
}

// ======================
void loop() {

  // INICIAR MEDIÇÃO
  if (digitalRead(botaoPin) == LOW && !medindo) {
    medindo = true;
    lcd.clear();
    lcd.print("Corra!");
    tone(buzzer, 1000, 200);

    // Espera o atleta sair da posição inicial
    while (medirDistancia() < distanciaInicial) {
      delay(10);
    }

    tempoInicio = millis();
  }

  // DURANTE MEDIÇÃO
  if (medindo) {

    float d = medirDistancia();

    // Quando o atleta chega perto (linha final)
    if (d <= distanciaFinal) {
      tempoFim = millis();
      medindo = false;

      float tempo = (tempoFim - tempoInicio) / 1000.0;

      // Distância fixa do percurso (ex: 2 metros)
      float percurso = 2.0;

      float velocidade = percurso / tempo;

      lcd.clear();
      lcd.print("Vel: ");
      lcd.print(velocidade);
      lcd.print(" m/s");

      lcd.setCursor(0, 1);

      if (velocidade >= 2.5) {
        lcd.print("Excelente");
        digitalWrite(ledVerde, HIGH);
        tone(buzzer, 2000, 300);

      } else if (velocidade >= 1.5) {
        lcd.print("Medio");
        tone(buzzer, 1500, 300);

      } else {
        lcd.print("Ruim");
        digitalWrite(ledVermelho, HIGH);
        tone(buzzer, 800, 500);
      }

      delay(4000);

      digitalWrite(ledVerde, LOW);
      digitalWrite(ledVermelho, LOW);

      lcd.clear();
      lcd.print("Aperte botao");
    }
  }
}