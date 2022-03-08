#include <MsTimer2.h>
uint8_t number = 0;

void setup() {
  DDRD = B11111111;  //D0~7:
  MsTimer2::set(1000, counter);
  MsTimer2::start;
}

void loop() {
}

void counter() {
  PORTD = counter;
  counter++;
}
