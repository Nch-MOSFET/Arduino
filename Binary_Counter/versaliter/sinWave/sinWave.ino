#define turns 128
#define Pi 3.1416
uint8_t pattern[turns];

void setup() {
  Serial.begin(115200);
  for(uint8_t i = 0; i < turns; i++){
    float  theta = (2 * Pi * i)/(turns);
    Serial.print("sin(theta) = ");
    Serial.println(sin(theta));
    uint8_t value = uint8_t((sin(theta) + 1) * 4);
    switch(value){
      case 0:
        pattern[i] = 0b00000001;
        break;
      case 1:
        pattern[i] = 0b00000010;
        break;
      case 2:
        pattern[i] = 0b00000100;
        break;
      case 3:
        pattern[i] = 0b00001000;
        break;
      case 4:
        pattern[i] = 0b00010000;
        break;
      case 5:
        pattern[i] = 0b00100000;
        break;
      case 6:
        pattern[i] = 0b01000000;
        break;
      case 7:
        pattern[i] = 0b10000000;
        break;
    }
    Serial.print("pattern[i] = ");
    Serial.println(pattern[i], BIN);
  }
  Serial.end();
  DDRD = 0b11111111;
}

void loop() {
  for(uint8_t i = 0; i < turns; i++){
    PORTD = pattern[i];
    delayMicroseconds(250);
  }
}
