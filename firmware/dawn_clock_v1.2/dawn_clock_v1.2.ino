#define DATA_PIN 13
#define LATCH_PIN 12
#define CLOCK_PIN 11

byte segments[10] = {
  0b01111101, 0b00100100, 0b01111010, 0b01110110, 0b00100111, 0b01010111, 0b01011111, 0b01100100, 0b01111111, 0b01110111 
};

void setup() 
{
  pinMode(DATA_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, segments[1]);
  digitalWrite(LATCH_PIN, HIGH);
}