/*
 * PORTDの出力にR-2R DACをつなぐと三角波を出力します
 * いい感じにdelayを調整することで周波数を変えることができます
 */

#define delayTime     3
#define DDR_ALLOUTPUT 0b11111111

void setup() {

 DDRD = DDR_ALLOUTPUT;
}

void loop() {
  for(uint8_t i = 0; i < 255; i++) {
    PORTD = i;
    delayMicroseconds(delayTime);
  }
  for(uint8_t i = 255; i > 0; i--) {
    PORTD = i;
    delayMicroseconds(delayTime);
  }
}
