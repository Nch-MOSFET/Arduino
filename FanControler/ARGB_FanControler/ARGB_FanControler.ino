#include <MsTimer2.h>
#include <Adafruit_NeoPixel.h>

#define        FanCtrl 5
#define      ARGB_Port 3
#define     LED_Counts 18  //ARGBファンの場合18っぽい:

#define R_MaxIntensity 64
#define G_MaxIntensity 64
#define B_MaxIntensity 64

uint8_t ARGB_Intensity[LED_Counts][3];  //0=R, 1=G, 2=B:
uint8_t fullColorData[360][3];
uint8_t val;
uint16_t colorRad = 0;

Adafruit_NeoPixel pixels(LED_Counts, ARGB_Port, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(FanCtrl, OUTPUT);
  Serial.begin(115200);
  pixels.begin();
  MsTimer2::set(50, fanCont);
  MsTimer2::start();
  /*
  for(int i = 0; i < LED_Counts; i++){
    makeColors();
  }
   */
}

void loop() {
}

void fanCont(){
  val = analogRead(3) / 4;
  analogWrite(FanCtrl, val);
  makeColors();
  for (int i = 0; i < LED_Counts; i++){
    pixels.setPixelColor(i, pixels.Color(ARGB_Intensity[i][0], ARGB_Intensity[i][1], ARGB_Intensity[i][2]));
    pixels.show();
  }
}

void makeColors(){
  /*
  //最初の色をランダムに生成する:
  ARGB_Intensity[0][0] = random(R_MaxIntensity);
  ARGB_Intensity[0][1] = random(G_MaxIntensity);
  ARGB_Intensity[0][2] = random(B_MaxIntensity);
   */
  //色相環から色引っ張り出してくる:
  ARGB_Intensity[0][0] = makeFullColorData(colorRad, 0);
  ARGB_Intensity[0][1] = makeFullColorData(colorRad, 1);
  ARGB_Intensity[0][2] = makeFullColorData(colorRad, 2);
  if(colorRad >= 360){
    colorRad = 0;
  }else{
    colorRad = colorRad + 4;
  }
  //一個づつデータをずらす:
  Serial.println(ARGB_Intensity[0][0], HEX);
  Serial.println(ARGB_Intensity[0][1], HEX);
  Serial.println(ARGB_Intensity[0][2], HEX);
  Serial.println();
  for (int i = LED_Counts; i > 0; i--){
    ARGB_Intensity[i][0] = ARGB_Intensity[i - 1][0];
  }
  for (int i = LED_Counts; i > 0; i--){
    ARGB_Intensity[i][1] = ARGB_Intensity[i - 1][1];
  }
  for (int i = LED_Counts; i > 0; i--){
    ARGB_Intensity[i][2] = ARGB_Intensity[i - 1][2];
  }
}

uint32_t makeFullColorData(uint16_t theta, uint8_t colorSelect){
  uint8_t r,g,b;
  if(theta >= 0 && 60 >= theta){
    r = 255;
    g = (256/60)*theta;
    b = 0;
  }else if(120 >= theta){
    theta = theta - 120;
    r = 255 - (256/60)*theta;
    g = 255;
    b = 0;
  }else if(180 >= theta){
    theta = (256/60)*theta - 180;
    r = 0;
    g = 255;
    b = (256/60)*theta;
  }else if(240 >= theta){
    theta = (256/60)*theta - 240;
    r = 0;
    g = 255 - (256/60)*theta;
    b = 255;
  }else if(300 >= theta){
    theta = theta - 300;
    r = (256/60)*theta;
    g = 0;
    b = 255;
  }else if(360 >= theta){
    theta = theta - 360;
    r = 255;
    g = 0;
    b = 255 - (256/60)*theta;
  }else{
    r = 0;
    g = 0;
    b = 0;
  }
  switch (colorSelect){
    case 0:
      return r;
      break;
    case 1:
      return g;
      break;
    case 2:
      return b;
      break;
  }
}
