int ledVerde1 = 12;
int ledVerde2 = 11;
int ledAmarelo = 10;
int ledVermelho = 9;
int pinoSensor = A0;
int valorSensor = 0;

void setup() {
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(pinoSensor, INPUT);
  Serial.begin(9600);

}

void loop() {
    valorSensor = analogRead(pinoSensor);
    Serial.println(valorSensor);
    if(valorSensor < 640){
      digitalWrite(ledVerde1, HIGH);
      digitalWrite(ledVerde2, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, LOW);
    }
    if(valorSensor >=640 & valorSensor < 768){
      digitalWrite(ledVerde1, HIGH);
      digitalWrite(ledVerde2, HIGH);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledVermelho, LOW);
    }
    if(valorSensor >= 768 & valorSensor < 896){
      digitalWrite(ledVerde1, HIGH);
      digitalWrite(ledVerde2, HIGH);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVermelho, LOW);
    }
    if (valorSensor >= 896) {
      digitalWrite(ledVerde1, HIGH);
      digitalWrite(ledVerde2, HIGH);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledVermelho, HIGH);
    }
}