#define turns 14

uint8_t pattern[] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010};

void setup() {
  DDRD = 0b11111111;
}

void loop() {
  for(uint8_t i = 0; i < turns; i++){
    PORTD = pattern[i];
    delay(1);
  }
}
