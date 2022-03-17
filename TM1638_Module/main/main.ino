/*
 * AmazonにてHiLetgoより販売されている8ケタ7セグメントLED・8LED・8スイッチのモジュールを動作させるためのコードです
 * 必要に応じて定数等を変更して使用してください
 * 使用されているICはTM1638を想定しています
 * このモジュールはSTB, CLK, DIOを使用してデータを送受信します
 * STB, CLKのデフォルト状態はHIGH, DIOは任意です。ここではLOWとします。また, STB, CLKはOUTPUT固定, DIOはOUTPUTをデフォルトとし必要に応じて切り替えます
 */

//Moduleに繋ぐピンを指定:
#define TM1638_STB 5
#define TM1638_CLK 6
#define TM1638_DIO 7

//送信するコマンドのビットデータを指定, 未使用領域はゼロフィル:
#define Write_Display_reg 0b01000000
#define Read_Key_reg      0b01000010
#define Set_Reg_addr      0b11000000  //下位4bitはレジスタアドレスを指定する領域です。レジスタアドレスを加算するか, レジスタアドレスとのORを取って関数に渡します:
#define Display_ON        0b10001000  //下位3bitは輝度を指定する領域です。0b000~0b111の範囲で指定ができます。使い方は上記の通りです:
#define Display_OFF       0b10000000

//各LEDのアドレスを指定:
#define LED1 0x00
#define LED2 0x02
#define LED3 0x04
#define LED4 0x06
#define LED5 0x08
#define LED6 0x0A
#define LED7 0x0C
#define LED8 0x0E

uint8_t binData = 0;

void setup() {
  //各デジタルピンの設定:
  pinMode(TM1638_STB, OUTPUT);
  pinMode(TM1638_CLK, OUTPUT);
  pinMode(TM1638_DIO, OUTPUT);

  digitalWrite(TM1638_STB, HIGH);
  digitalWrite(TM1638_CLK, HIGH);
  digitalWrite(TM1638_DIO,  LOW);
}

void loop() {
  ctrlLEDs(binData);
  binData++;
  delay(1000);
}

void sendData(uint8_t com, uint8_t dat){
/*
 * データを送信するにはshiftOut関数を用います。引数は3つで, 順に(データを送るピン, クロックを送るピン, LSFIRSTまたはMSBFIRST, 送信するデータ)になります
 * 第三引数について, ここでLSBから送信するかMSBから送信するかを指定します。LSBは最下位ビット, MSBは最上位ビットを表します
 *            　MSB↓  　　↓LSB
 *               0b10010111
 * データを送信する際, STBをLOWにして送信開始し, データを送信, STBをHIGHにして送信を終了します
 * まずcomを送信し何のデータかを指定, その後にデータを送信します
 * またここではデータを一つしか送信していませんが, 複数同時に送信することもできます
 */
  digitalWrite(TM1638_STB,  LOW);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, com);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, dat);
  digitalWrite(TM1638_STB, HIGH);
}

uint8_t receiveData(uint8_t com){
/*
 * データを受信するにはshiftIn関数を用います。引数は3つで, 順に(データを受け取るピン, クロックを送るピン, LSFIRSTまたはMSBFIRST)です
 * ここでデータを受信するため, DIOにつながっているピンをINPUTに変更する必要があります
 * また, データを送信させるコマンドを送信した後に2us以上待つ必要があります
 */
  digitalWrite(TM1638_STB,  LOW);
  shiftOut(TM1638_DIO, TM1638_CLK, LSBFIRST, com);
  pinMode(TM1638_DIO,  INPUT);
  delayMicroseconds(2);
  uint8_t dat = shiftIn(TM1638_DIO, TM1638_CLK, LSBFIRST);
  digitalWrite(TM1638_STB, HIGH);
  pinMode(TM1638_DIO, OUTPUT);
  return dat;
}

void ctrlLED(uint8_t led, uint8_t stat){
/*
 * 基板上のLEDを点灯させる時, 各LEDが持つレジスタアドレスに1を加算したデータをコマンドとして送信し, 続いて点灯状態を送信します
 */
  if(stat == 0 || stat == 1){
    sendData(Set_Reg_addr + led + 1, stat);
  }else{
    //0, 1ではなかったので無視する:
  }
}

void ctrlLEDs(uint8_t dat){
/*
 * この関数は受け取った8bitのデータを2進数で表示する関数です。少し高度になりますが一応用意しておきます
 * 基板上に配置されている通りLED1にMSB, LED8にLSBを表示するようにしています
 */
  sendData(Set_Reg_addr + LED1 + 1, (dat && 0b10000000) >> 7);
  sendData(Set_Reg_addr + LED2 + 1, (dat && 0b01000000) >> 6);
  sendData(Set_Reg_addr + LED3 + 1, (dat && 0b00100000) >> 5);
  sendData(Set_Reg_addr + LED4 + 1, (dat && 0b00010000) >> 4);
  sendData(Set_Reg_addr + LED5 + 1, (dat && 0b00001000) >> 3);
  sendData(Set_Reg_addr + LED6 + 1, (dat && 0b00000100) >> 2);
  sendData(Set_Reg_addr + LED7 + 1, (dat && 0b00000010) >> 1);
  sendData(Set_Reg_addr + LED8 + 1, (dat && 0b00000001) >> 0);
}
