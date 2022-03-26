#include <MsTimer2.h>
uint8_t pattern;
void ledOut() {pattern = pattern << 1; pattern = pattern + random(2); PORTD = pattern;}
void setup() { DDRD = 0xFF; MsTimer2::set(50, ledOut); MsTimer2::start();}
void loop() {}
