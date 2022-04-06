#include <Adafruit_NeoPixel.h>

#define ARGB_Pin   5
#define LED_Counts 7

#define GreenTime      6000
#define ChangingDelay  2000

Adafruit_NeoPixel pixels(LED_Counts, ARGB_Pin, NEO_GRB + NEO_KHZ800);

uint8_t DefaultPattern[2][3] = {{0x00, 0xff, 0xff}, {0xff, 0xff, 0x00}};
uint8_t            Red   [3] = {0xff, 0x00, 0x00};
uint8_t         Yellow   [3] = {0xff, 0xff, 0x00};
uint8_t          Green   [3] = {0x00, 0xff, 0x00};

void setup() {
  pinMode(ARGB_Pin, OUTPUT);
  pixels.begin();
  
  for (uint8_t i = 0; i < 3; i++){
    pixels.setPixelColor(i, pixels.Color(DefaultPattern[0][i], DefaultPattern[1][i], 0));
    pixels.show();
  }
  pixels.setPixelColor(4, pixels.Color(0,0,0));
  for (uint8_t i = 0; i < 3; i++){
    pixels.setPixelColor(i + 4, pixels.Color(DefaultPattern[0][i], DefaultPattern[1][i], 0));
    pixels.show();
  }
  delay(1000);
  Clear();
  delay(1000);
}

void loop(){
  //赤、青:
  Clear();
  pixels.setPixelColor(2, pixels.Color(Red[0], Red[1], Red[2]));
  pixels.setPixelColor(4, pixels.Color(Green[0], Green[1], Green[2]));
  pixels.show();
  delay(GreenTime);

  //赤、黃:
  Clear();
  pixels.setPixelColor(2, pixels.Color(Red[0], Red[1], Red[2]));
  pixels.setPixelColor(5, pixels.Color(Yellow[0], Yellow[1], Yellow[2]));
  pixels.show();
  delay(ChangingDelay);

  //赤、赤:
  Clear();
  pixels.setPixelColor(2, pixels.Color(Red[0], Red[1], Red[2]));
  pixels.setPixelColor(6, pixels.Color(Red[0], Red[1], Red[2]));
  pixels.show();
  delay(ChangingDelay);

  //青、赤:
  Clear();
  pixels.setPixelColor(0, pixels.Color(Green[0], Green[1], Green[2]));
  pixels.setPixelColor(6, pixels.Color(Red[0], Red[1], Red[2]));
  pixels.show();
  delay(GreenTime);
  
  //黃、赤:
  Clear();
  pixels.setPixelColor(1, pixels.Color(Yellow[0], Yellow[1], Yellow[2]));
  pixels.setPixelColor(6, pixels.Color(Red[0], Red[1], Red[2]));
  pixels.show();
  delay(ChangingDelay);

  //赤、赤:
  Clear();
  pixels.setPixelColor(2, pixels.Color(Red[0], Red[1], Red[2]));
  pixels.setPixelColor(6, pixels.Color(Red[0], Red[1], Red[2]));
  pixels.show();
  delay(ChangingDelay);
}

void Clear() {
  for(uint8_t i = 0; i < 7; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
  }
}
