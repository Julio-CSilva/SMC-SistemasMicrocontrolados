void setup() {
  DDRB = DDRB | B00100000;

}

void loop() {
  PORTB = PORTB | B00100000;
}