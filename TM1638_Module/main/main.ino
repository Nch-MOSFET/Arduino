#include "TM1638_Driver.h"

void setup() {
  Serial.begin(115200);

  //TM1638を初期化:
  TM1638_Init();
  
  //ディスプレイレジスタに表示:
  Display_TM1638(1, 2, 3, 4, 5, 6, 7, 8, 0b10110010);
}

void loop() {
  Display_TM1638(random(16), random(16), random(16), random(16), random(16), random(16), random(16), random(16), random(256));
  delay(1000);
}

/* 以下テスト中のコード
void Display(uint16_t dat) {
  String txt = String(dat);
  Serial.println("dat         = " + String(dat));
  Serial.println("txt         = " + txt);
  Serial.println("sizeof(txt) = " + String(sizeof(txt)));
  Serial.println();
}
 */
