int ledVerdePin = 10;
int ledVermelhoPin = 11;
int botaoPin = 12;
int botao = 0;

void setup(){
  pinMode(ledVermelhoPin, OUTPUT);
  pinMode(ledVerdePin, OUTPUT);
  pinMode(botaoPin, INPUT);
}

void loop() {
  botao = digitalRead(botaoPin);
  if(botao == HIGH){
    digitalWrite(ledVermelhoPin, HIGH);
    digitalWrite(ledVerdePin, LOW);
  }else{
    digitalWrite(ledVermelhoPin, LOW);
    digitalWrite(ledVerdePin, HIGH);
  }
}