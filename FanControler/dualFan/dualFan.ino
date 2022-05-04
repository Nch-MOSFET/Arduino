#define analogPin   6
#define PWM_OUT_1   3
#define PWM_OUT_2   5
#define SW_INPUT   12
#define onBoardLED 13

uint16_t ana;
uint8_t Fan1, Fan2, SW, pinRead;

uint8_t LED_Pattern[3][6] = {{0, 0, 0, 0, 1, 0}, 
                             {0, 0, 1, 0, 1, 0}, 
                             {1, 0, 1, 0, 1, 0}};

void setup() {
  pinMode(PWM_OUT_1 , OUTPUT       );
  pinMode(PWM_OUT_2 , OUTPUT       );
  pinMode(onBoardLED, OUTPUT       );
  pinMode(SW_INPUT  ,  INPUT_PULLUP);

  pinRead = 0xff * digitalRead(SW_INPUT);
}

void loop() {
  pinRead = (pinRead << 1) + digitalRead(SW_INPUT);

  //プッシュスイッチの状態が変化した際の処理:
  if((pinRead & 0b00001111) == 0b00001000) {
    SW = counter(SW, 3);
  }
  
  for(uint8_t i = 0; i < 6; i += 2){
    digitalWrite(onBoardLED, LED_Pattern[(SW & 0b00000011)][i  ]);
    delay(30);
    digitalWrite(onBoardLED, LED_Pattern[(SW & 0b00000011)][i+1]);
    delay(70);
  }

  //セレクタ変数による処理の割り振り:
        if((SW & 0b00000011) == 0b00) {
    ana  = analogRead(analogPin);
    Fan1 = (ana >> 2);
    analogWrite(PWM_OUT_1, Fan1);
  }else if((SW & 0b00000011) == 0b01) {
    ana  = analogRead(analogPin);
    Fan2 = (ana >> 2);
    analogWrite(PWM_OUT_2, Fan2);
  }

  delay(200);
}

uint8_t counter(uint8_t dat, uint8_t border) {
  if(dat < (border - 1)) {
    dat++;
  }else{
    dat = 0;
  }

  return dat;
}
