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
  digitalWrite(TM1638_STB,  LOW);
  dataOut(Set_Register_Addr_00H);
  dataOut(segments[0]);
  dataOut(0b00000001);
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
  digitalWrite(TM1638_STB, HIGH);
  
  delay(1000);

  digitalWrite(TM1638_STB,  LOW);
  dataOut(Set_Register_Addr_00H);
  dataOut(segments[8]);
  dataOut(0b00000000);
  dataOut(segments[9]);
  dataOut(0b00000000);
  dataOut(segments[10]);
  dataOut(0b00000000);
  dataOut(segments[11]);
  dataOut(0b00000000);
  dataOut(segments[12]);
  dataOut(0b00000000);
  dataOut(segments[13]);
  dataOut(0b00000000);
  dataOut(segments[14]);
  dataOut(0b00000000);
  dataOut(segments[15]);
  dataOut(0b00000000);
  digitalWrite(TM1638_STB, HIGH);
  
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
