#define LED_Pattern_0_size  2
#define LED_Pattern_1_size  2
#define LED_Pattern_2_size 14
#define LED_Pattern_3_size  2
#define LED_Pattern_4_size

uint8_t LED_Pattern_0[LED_Pattern_0_size] = {B00001111, B11110000};
uint8_t LED_Pattern_1[LED_Pattern_1_size] = {B00000000, B11111111};
uint8_t LED_Pattern_2[LED_Pattern_2_size] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
uint8_t LED_Pattern_3[LED_Pattern_3_size] = {B01010101, B10101010};
uint8_t LED_Pattern_4[LED_Pattern_4_size] = {B10000000, B01000000, B00100000, B00010000, B00001000, B00000100, B00000010, B00000001, B10000001, B01000001, B00100001, B00010001};  //まだあるけどやってられんからそのうち・・・:

void setup() {
  DDRD = B11111111; //D0 - D7
}

void loop() {
  for(uint8_t uint8_t i = 0; i < 4; i++){
    PORTD = LED_Pattern_0[0];
    delay(500);
    PORTD = LED_Pattern_0[1];
    delay(500);
  }
  delay(1000);
  for(uint8_t i = 0; i < 4; i++){
    PORTD = LED_Pattern_1[0];
    delay(500);
    PORTD = LED_Pattern_1[1];
    delay(500);
  }
  delay(1000);
  for(uint8_t i = 0; i < 8; i++){
    for(uint8_t o = 0; o < LED_Pattern_2_size; o++){
      LED_Pattern_2[o];
      delay(200);
    }
  }
  delay(1000);
  for(uint8_t i = 0; i < LED_Pattern_4_size; i++){
    PORTD = LED_Pattern_4[i];
    delay(200);
  }
  delay(1000);
}
