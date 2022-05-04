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
