#include "TM1638_Driver.h"

void setup() {
  Serial.begin(115200);

  //TM1638を初期化:
  TM1638_Init();
  
  //ディスプレイレジスタに表示:
  digitalWrite(TM1638_STB,  LOW);
  dataOut(Set_Register_Addr_00H);
  dataOut(segments[1]);
  dataOut(0b00000001);
  dataOut(segments[2]);
  dataOut(0b00000001);
  dataOut(segments[3]);
  dataOut(0b00000001);
  dataOut(segments[4]);
  dataOut(0b00000001);
  dataOut(segments[5]);
  dataOut(0b00000001);
  dataOut(segments[6]);
  dataOut(0b00000001);
  dataOut(segments[7]);
  dataOut(0b00000001);
  dataOut(segments[8]);
  dataOut(0b00000001);
  digitalWrite(TM1638_STB, HIGH);
}

void loop() {
  Display(random(1000000));
  delay(1000);
}

void Display(uint16_t dat) {
  String txt = String(dat);
  Serial.println("dat         = " + String(dat));
  Serial.println("txt         = " + txt);
  Serial.println("sizeof(txt) = " + String(sizeof(txt)));
  Serial.println();
}
