#define LED_Pattern_0_size  2
#define LED_Pattern_1_size  2
#define LED_Pattern_2_size 14
#define LED_Pattern_3_size  2
#define LED_Pattern_4_size 37
#define LED_Pattern_5_size 37

uint8_t LED_Pattern_0[LED_Pattern_0_size] = {B00001111, B11110000};
uint8_t LED_Pattern_1[LED_Pattern_1_size] = {B00000000, B11111111};
uint8_t LED_Pattern_2[LED_Pattern_2_size] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
uint8_t LED_Pattern_3[LED_Pattern_3_size] = {B01010101, B10101010};
uint8_t LED_Pattern_4[LED_Pattern_4_size] = {B10000000, B01000000, B00100000, B00010000, B00001000, B00000100, B00000010, B00000001, 
                                             B10000001, B01000001, B00100001, B00010001, B00001001, B00000101, B00000011, 
                                             B10000011, B01000011, B00100011, B00010011, B00001011, B00000111, 
                                             B10000111, B01000111, B00100111, B00010111, B00001111, 
                                             B10001111, B01001111, B00101111, B00011111, 
                                             B10011111, B01011111, B00111111,
                                             B10111111, B01111111, B11111111};
uint8_t LED_Pattern_5[LED_Pattern_5_size] = {B11111111, B11111110, 
                                             B11111101, B11111100, 
                                             B11111010, B11111001, B11111000, 
                                             B11110100, B11110010, B11110001, B11110000, 
                                             B11101000, B11100100, B11100010, B11100001, B11100000, 
                                             B11010000, B11001000, B11000100, B11000010, B11000001, B11000000, 
                                             B10100000, B10010000, B10001000, B10000100, B10000010, B10000001, B10000000, 
                                             B01000000, B00100000, B00010000, B00001000, B00000100, B00000010, B00000001, B00000000};

void setup() {
  DDRD = B11111111; //D0 - D7
}

void loop() {
  for(uint8_t i = 0; i < 4; i++){
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
