#include <MsTimer2.h>
uint8_t number = 0;
void counter() {PORTD = number;　number++;}
void setup() {DDRD = B11111111;　MsTimer2::set(1000, counter);　MsTimer2::start();}
void loop() {}
