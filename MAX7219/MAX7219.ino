#define LED_DIN 12
#define LED_CS  11
#define LED_CLK 10

void setup() {
  pinMode(LED_CS,  OUTPUT);
  pinMode(LED_CLK, OUTPUT);
  pinMode(LED_DIN, OUTPUT);
  
  digitalWrite(LED_CS,  HIGH);
  digitalWrite(LED_CLK, LOW);
  digitalWrite(LED_DIN, LOW);

  LED_OUT(0x9, 0b11111111);   //7セグでデコードするビットに1を立てる:
  LED_OUT(0xA, 5);    //輝度を設定, 0-15:
  LED_OUT(0xB, 7);    //使用する桁数を指定, 桁数-1:
  LED_OUT(0xC, 1);    //特にいじる必要なし:
  LED_OUT(0xF, 0);    //同上:

  LED_OUT(0x1, 8);  //1ケタ目のセグメントに表示するものを指定:
  LED_OUT(0x2, 7);  //2ケタ目:
  LED_OUT(0x3, 6);  //3ケタ目:
  LED_OUT(0x4, 5);  //4ケタ目:
  LED_OUT(0x5, 4);  //5ケタ目:
  LED_OUT(0x6, 3);  //6ケタ目:
  LED_OUT(0x7, 2);  //7ケタ目:
  LED_OUT(0x8, 1);  //8ケタ目:
}

void loop() {
  Display_Number(random(-10000000, 100000000));
  delay(250);
}

void LED_OUT(uint8_t addr, uint8_t dat){
  digitalWrite(LED_CS, LOW);
  shiftOut(LED_DIN, LED_CLK, MSBFIRST, addr);
  shiftOut(LED_DIN, LED_CLK, MSBFIRST, dat);
  digitalWrite(LED_CS, HIGH);
}

void LED_LOOP(int a, int b){
  LED_OUT(0x9, 0x00);
  LED_OUT(0x1, 0b00000000);
  LED_OUT(0x2, 0b00000000);
  LED_OUT(0x3, 0b00000000);
  LED_OUT(0x4, 0b00000000);
  LED_OUT(0x5, 0b00000000);
  LED_OUT(0x6, 0b00000000);
  LED_OUT(0x7, 0b00000000);
  LED_OUT(0x8, 0b00000000);
  for(int i=0; i<a; i++){
    LED_OUT(0x1, 0b01000000);
    delay(b);
    LED_OUT(0x1, 0b00000000);
    LED_OUT(0x2, 0b01000000);
    delay(b);
    LED_OUT(0x2, 0b00000000);
    LED_OUT(0x3, 0b01000000);
    delay(b);
    LED_OUT(0x3, 0b00000000);
    LED_OUT(0x4, 0b01000000);
    delay(b);
    LED_OUT(0x4, 0b00000000);
    LED_OUT(0x5, 0b01000000);
    delay(b);
    LED_OUT(0x5, 0b00000000);
    LED_OUT(0x6, 0b01000000);
    delay(b);
    LED_OUT(0x6, 0b00000000);
    LED_OUT(0x7, 0b01000000);
    delay(b);
    LED_OUT(0x7, 0b00000000);
    LED_OUT(0x8, 0b01000000);
    delay(b);
    LED_OUT(0x8, 0b00000000);
    LED_OUT(0x8, 0b00000010);
    delay(b);
    LED_OUT(0x8, 0b00000000);
    LED_OUT(0x8, 0b00000100);
    delay(b);
    LED_OUT(0x8, 0b00000000);
    LED_OUT(0x8, 0b00001000);
    delay(b);
    LED_OUT(0x8, 0b00000000);
    LED_OUT(0x7, 0b00001000);
    delay(b);
    LED_OUT(0x7, 0b00000000);
    LED_OUT(0x6, 0b00001000);
    delay(b);
    LED_OUT(0x6, 0b00000000);
    LED_OUT(0x5, 0b00001000);
    delay(b);
    LED_OUT(0x5, 0b00000000);
    LED_OUT(0x4, 0b00001000);
    delay(b);
    LED_OUT(0x4, 0b00000000);
    LED_OUT(0x3, 0b00001000);
    delay(b);
    LED_OUT(0x3, 0b00000000);
    LED_OUT(0x2, 0b00001000);
    delay(b);
    LED_OUT(0x2, 0b00000000);
    LED_OUT(0x1, 0b00001000);
    delay(b);
    LED_OUT(0x1, 0b00000000);
    LED_OUT(0x1, 0b00010000);
    delay(b);
    LED_OUT(0x1, 0b00000000);
    LED_OUT(0x1, 0b00100000);
    delay(b);
    LED_OUT(0x1, 0b00000000);
  }
}

void Display_Err(){
  LED_OUT(0x9, 0x00);
  LED_OUT(0x1, 0b10000101);  //r.:
  LED_OUT(0x2, 0b00000101);  //r:
  LED_OUT(0x3, 0b01001111);  //E
  LED_OUT(0x4, 0b00000000);
  LED_OUT(0x5, 0b00000000);
  LED_OUT(0x6, 0b00000000);
  LED_OUT(0x7, 0b00000000);
  LED_OUT(0x8, 0b00000000);
}

void Display_null(){
  LED_OUT(0x9, 0x00);
  LED_OUT(0x1, 0b00000000);
  LED_OUT(0x2, 0b00000000);
  LED_OUT(0x3, 0b00000000);
  LED_OUT(0x4, 0b00000000);
  LED_OUT(0x5, 0b00000000);
  LED_OUT(0x6, 0b00000000);
  LED_OUT(0x7, 0b00000000);
  LED_OUT(0x8, 0b00000000);
}

void Display_full(){
  LED_OUT(0x9, 0x00);
  LED_OUT(0x1, 0b11111111);
  LED_OUT(0x2, 0b11111111);
  LED_OUT(0x3, 0b11111111);
  LED_OUT(0x4, 0b11111111);
  LED_OUT(0x5, 0b11111111);
  LED_OUT(0x6, 0b11111111);
  LED_OUT(0x7, 0b11111111);
  LED_OUT(0x8, 0b11111111);
}

void Display_on(){
  LED_OUT(0x9, 0x00);
  LED_OUT(0x1, 0b10010101);  //n.:
  LED_OUT(0x2, 0b00011101);  //o:
  LED_OUT(0x3, 0b00000000);
  LED_OUT(0x4, 0b00000000);
  LED_OUT(0x5, 0b00000000);
  LED_OUT(0x6, 0b00000000);
  LED_OUT(0x7, 0b00000000);
  LED_OUT(0x8, 0b00000000);
}

void Display_off(){
  LED_OUT(0x9, 0x00);
  LED_OUT(0x1, 0b11000111);  //f.:
  LED_OUT(0x2, 0b01000111);  //f:
  LED_OUT(0x3, 0b00011101);  //o
  LED_OUT(0x4, 0b00000000);
  LED_OUT(0x5, 0b00000000);
  LED_OUT(0x6, 0b00000000);
  LED_OUT(0x7, 0b00000000);
  LED_OUT(0x8, 0b00000000);
}

void Display_Number(long a){
  byte Digit8 = 0;
  byte Digit7 = 0;
  byte Digit6 = 0;
  byte Digit5 = 0;
  byte Digit4 = 0;
  byte Digit3 = 0;
  byte Digit2 = 0;
  byte Digit1 = 0;
  long b = abs(a);
  Display_null();
  if(a > 99999999 || a < -9999999){  //例外処理:
   Display_Err();
  }else{
    if(a >= 10000000){        //8ケタ目の処理:
      Digit8 = (b & 90000000);
      Display_Number_Decode(8, Digit8);
    }else if(a <= -1000000 && a >= -9999999){  
      Display_Number_Decode(8, 10);
    }
    if(abs(a) >= 1000000){    //7ケタ目の処理:
      Digit7 = (b & 9000000);
      Display_Number_Decode(7, Digit7);
    }else if(a <= -100000 && a >= -999999){  
      Display_Number_Decode(7, 10);
    }
    if(abs(a) >= 100000){     //6ケタ目の処理:
      Digit6 = (b & 900000);
      Display_Number_Decode(6, Digit6);
    }else if(a <= -10000 && a >= -99999){  
      Display_Number_Decode(6, 10);
     }
   if(abs(a) >= 10000){      //5ケタ目の処理:
      Digit5 = (b & 90000);
      Display_Number_Decode(5, Digit5);
    }else if(a <= -1000 && a >= -9999){  
      Display_Number_Decode(5, 10);
    }
    if(abs(a) >= 1000){       //4ケタ目の処理:
      Digit4 = (b & 9000);
      Display_Number_Decode(4, Digit4);
    }else if(a <= -100 && a >= -999){  
      Display_Number_Decode(4, 10);
    }
    if(abs(a) >= 100){        //3ケタ目の処理:
      Digit3 = (b & 900);
      Display_Number_Decode(3, Digit3);
    }else if(a <= -10 && a >= -99){  
      Display_Number_Decode(3, 10);
    }
    if(abs(a) >= 10){         //2ケタ目の処理:
      Digit2 = (b & 90);
      Display_Number_Decode(2, Digit2);
    }else if(a <= -1 && a >= -9){  
      Display_Number_Decode(2, 10);
    }
    if(abs(a) >= 0){          //1ケタ目の処理:
      Digit1 = (b & 9);
      Display_Number_Decode(1, Digit1);
    }
  }
}

void Display_Number_Decode(byte digit, byte number){
  switch(number){
    case 0:
      LED_OUT(digit, 0b01111110);
      break;
    case 1:
      LED_OUT(digit, 0b00110000);
      break;
    case 2:
      LED_OUT(digit, 0b01101101);
      break;
    case 3:
      LED_OUT(digit, 0b01111001);
      break;
    case 4:
      LED_OUT(digit, 0b00110011);
      break;
    case 5:
      LED_OUT(digit, 0b01011011);
      break;
    case 6:
      LED_OUT(digit, 0b01011111);
      break;
    case 7:
      LED_OUT(digit, 0b01110010);
      break;
    case 8:
      LED_OUT(digit, 0b01111111);
      break;
    case 9:
      LED_OUT(digit, 0b01111011);
      break;
    default:
      LED_OUT(digit, 0b00000001);
  }
}
