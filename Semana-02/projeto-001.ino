int ledVermelhoPin = 11;
int ledAmareloPin = 10;
int ledVerdePin = 9;

void setup() {
  pinMode(ledVermelhoPin, OUTPUT);
  pinMode(ledAmareloPin, OUTPUT);
  pinMode(ledVerdePin, OUTPUT);
}

void loop() {
  digitalWrite(ledVerdePin, HIGH);
  delay(2000);
  digitalWrite(ledVerdePin, LOW);
  digitalWrite(ledAmareloPin, HIGH);
  delay(1000);
  digitalWrite(ledAmareloPin, LOW);
  digitalWrite(ledVermelhoPin, HIGH);
  delay(3000);
  digitalWrite(ledVermelhoPin, LOW);
}