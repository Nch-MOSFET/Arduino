/*
 * コマンドとして送信するデータについて、コマンドデータは8bitで構成されています。内容は以下の通りです
 *              bit Number | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | Functions and Descriptions |  - : Don't Care
 * ------------------------|---|---|---|---|---|---|---|---|----------------------------|      Fill with 0
 *            Data Command | 0 | 1 | - | - | - | - | 0 | 0 | Write Data to Register     |
 *                         | 0 | 1 | - | - | - | - | 1 | 0 | Read Key Scan Data         |  x : Fill Required Data as 0 or 1
 *                         | 0 | 1 | - | - | - | 0 | - | - | Auto Increment Register    |
 *                         | 0 | 1 | - | - | - | 1 | - | - | Fixed Address              |
 *                         | 0 | 1 | - | - | 0 | - | - | - | Set Mode to Mormal Mode    |
 *                         | 0 | 1 | - | - | 1 | - | - | - | Set Mode to Test Mode      |
 *         Address Command | 1 | 1 | - | - | x | x | x | x | Set Register Address   0~F |
 * Display Control Command | 1 | 0 | - | - | - | x | x | x | Set Display Blightness 0~7 | Display means 7-Segments LEDs
 *                         | 1 | 0 | - | - | 0 | - | - | - | Display Off                |
 *                         | 1 | 0 | - | - | 1 | - | - | - | Display On                 |
 */

//コマンドデータを定数化。必要なものでORを取る:
#define dataWrite  0b01000000  //①//データ送信モード:
#define dataRead   0b01000010  //②//データ受信モード:
#define autoIncre  0b01000000  //③//書き込むアドレスを自動的にインクリメントする:
#define dontIncre  0b01000100  //④//書き込むアドレスを自動的にインクリメントしない:
#define normalMode 0b01000000  //⑤//ノーマルモードに設定, 多分これデフォでいい:
#define   testMode 0b01001000  //⑥//テストモードに設定, どう違うかわからんので多分要らん:
#define setReg     0b11000000  //⑦//書き込むレジスタアドレスを指定したい時に使用, autoIncreを有効にするとここの値が自動的に加算される？:
#define Blightness 0b10000100  //⑧//輝度を設定する時に使用, とりあえず中間値の4で:
#define displayOff 0b10000000  //⑨//消灯させる時に使用:
#define displayOn  0b10001000  //⑩//点灯させる時に使用:

/*
 * 使用の際、組み合わせに注意してください。
 * 具体的に使用可能な組み合わせは、
 *  - 「①または②」と「③または④」と「⑤または⑥」のOR
 *  - ⑦のみ
 *  - ⑧と⑩
 *  - ⑨のみ
 *  のいずれかです
 */

//基板上のLEDを制御するアドレスを指定:
#define LED1 0x01  //MSB:
#define LED2 0x03
#define LED3 0x05
#define LED4 0x07
#define LED5 0x09
#define LED6 0x0B
#define LED7 0x0D
#define LED8 0x0F  //LSB:

//7セグLEDを制御するアドレスを指定:
#define SEG1 0x00  //MSB:
#define SEG2 0x02
#define SEG3 0x04
#define SEG4 0x06
#define SEG5 0x08
#define SEG6 0x0A
#define SEG7 0x0C
#define SEG8 0x0E  //LSB:

/*
 * すべてのLEDをまとめて制御する場合は以下のようにします
  pinMode(TM1638_STB,  LOW);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, setReg);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0bxxxxxxxx);  //7SEG1の制御, .gfedcbaの順:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0b0000000x);  //LSBがLED1の状態になる:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0bxxxxxxxx);  //7SEG2:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0b0000000x);  //LED2:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0bxxxxxxxx);  //7SEG3:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0b0000000x);  //LED3:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0bxxxxxxxx);  //7SEG4:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0b0000000x);  //LED4:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0bxxxxxxxx);  //7SEG5:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0b0000000x);  //LED5:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0bxxxxxxxx);  //7SEG6:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0b0000000x);  //LED6:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0bxxxxxxxx);  //7SEG7:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0b0000000x);  //LED7:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0bxxxxxxxx);  //7SEG8:
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0b0000000x);  //LED8:
  pinMode(TM1638_STB, HIGH);
 */

//GPIOの接続先の設定:
#define TM1638_STB 5
#define TM1638_CLK 6
#define TM1638_DIO 7

void setup() {
  //各デジタルピンの設定:
  pinMode(TM1638_STB, OUTPUT);
  pinMode(TM1638_CLK, OUTPUT);
  pinMode(TM1638_DIO, OUTPUT);

  //初期化:
  digitalWrite(TM1638_STB, HIGH);
  digitalWrite(TM1638_CLK, HIGH);
  digitalWrite(TM1638_DIO,  LOW);

  //受信モードに設定:
  digitalWrite(TM1638_STB,  LOW);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, dataWrite | dontIncre | normalMode);
  digitalWrite(TM1638_STB, HIGH);

  //輝度を設定:
  digitalWrite(TM1638_STB,  LOW);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, displayOn | Blightness);
  digitalWrite(TM1638_STB, HIGH);

  //表示テスト:
  Clear();
  delay(1000);
  ctrlAllLED(0b10010110, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111);
}

void loop() {
}

void ctrlAllLED(uint8_t leds, uint8_t Digit1, uint8_t Digit2, uint8_t Digit3, uint8_t Digit4, uint8_t Digit5, uint8_t Digit6, uint8_t Digit7, uint8_t Digit8){
  pinMode(TM1638_STB,  LOW);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, setReg);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, Digit1);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, (leds | 0b10000000) >> 7);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, Digit2);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, (leds | 0b01000000) >> 6);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, Digit3);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, (leds | 0b00100000) >> 5);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, Digit4);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, (leds | 0b00010000) >> 4);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, Digit5);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, (leds | 0b00001000) >> 3);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, Digit6);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, (leds | 0b00000100) >> 2);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, Digit7);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, (leds | 0b00000010) >> 1);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, Digit8);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, (leds | 0b00000001) >> 0);
  pinMode(TM1638_STB, HIGH);
}

void Clear(){
  pinMode(TM1638_STB,  LOW);

  for(uint8_t i = 0; i < 16; i++){
    shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, 0x00);
  }
  pinMode(TM1638_STB, HIGH);
}
