void TM1638_Init() {
  //各種デジタルピンの入出力設定:
  pinMode(TM1638_STB, OUTPUT);
  pinMode(TM1638_CLK, OUTPUT);
  pinMode(TM1638_DIO, OUTPUT);

  //デジタルピンの初期値の設定:
  digitalWrite(TM1638_STB, HIGH);
  digitalWrite(TM1638_CLK, HIGH);
  digitalWrite(TM1638_DIO,  LOW);

  //書き込みモードに設定:
  sendDat(Read_Key_Register);

  //ディスプレイをONにし輝度を設定:
  sendDat(Display_ON + Display_Intensity);

  //全レジスタの初期化:
  digitalWrite(TM1638_STB,  LOW);
  for(uint8_t i = 0; i < 16; i++){
    dataOut(0);
  }
  digitalWrite(TM1638_STB, HIGH);
}

void sendDat(uint8_t dat) {
  digitalWrite(TM1638_STB,  LOW);
  dataOut(dat);
  digitalWrite(TM1638_STB, HIGH);
}

void dataOut(uint8_t dat) {
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, dat);
}

void Display_TM1638(uint8_t D1, uint8_t D2, uint8_t D3, uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7, uint8_t D8, uint8_t LED) {
  digitalWrite(TM1638_STB,  LOW);
  dataOut(Set_Register_Addr_00H);
  dataOut(segments[D1]);
  dataOut((LED && 0b10000000) >> 7);
  dataOut(segments[D2]);
  dataOut((LED && 0b01000000) >> 6);
  dataOut(segments[D3]);
  dataOut((LED && 0b00100000) >> 5);
  dataOut(segments[D4]);
  dataOut((LED && 0b00010000) >> 4);
  dataOut(segments[D5]);
  dataOut((LED && 0b00001000) >> 3);
  dataOut(segments[D6]);
  dataOut((LED && 0b00000100) >> 2);
  dataOut(segments[D7]);
  dataOut((LED && 0b00000010) >> 1);
  dataOut(segments[D8]);
  dataOut((LED && 0b00000001));
  digitalWrite(TM1638_STB, HIGH);
}
