int botao = 12;
int ledVermelho = 11;
int ledAmarelo = 10;
int ledVerde = 9;
int buzzer = 8;
boolean parada = false;

void setup() {
  pinMode(botao, INPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  if(digitalRead(botao) == HIGH){
    delay(10);
    if(digitalRead(botao) == HIGH){
      parada = true;
    }
  }

  digitalWrite(ledVerde, HIGH);
  delay(2000);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, HIGH);
  delay(1000);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, HIGH);
  delay(3000);
  digitalWrite(ledVermelho, LOW);

  if(parada){
    parada = false;
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
  }
}