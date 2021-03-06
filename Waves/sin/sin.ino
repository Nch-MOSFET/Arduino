/*
 * PORTDの出力にR-2R DACをつなぐと任意周波数の正弦波を出力します
 * いい感じにdelayを調整することで周波数を変えることができます
 */

#define delayTime     1
#define DDR_ALLOUTPUT 0b11111111

uint8_t sinWave[360];

void setup() {
  for(uint16_t i = 0; i < sizeof(sinWave); i++){
    float theta = i * (PI / 180);
    sinWave[i]  = floor((sin(theta) * 127.9) + 128);
    Serial.println("sinWave[" + String(i) + "] = " + String(sinWave[i]));
  }

 DDRD = DDR_ALLOUTPUT;
}

void loop() {
  for(uint16_t i = 0; i < sizeof(sinWave); i++){
    PORTD = sinWave[i];
    delayMicroseconds(delayTime);
  }
}
