#include <MsTimer2.h>
void counter() {PORTD++;}
void setup() {MsTimer2::set(25, counter); MsTimer2::start();}
void loop() {}
