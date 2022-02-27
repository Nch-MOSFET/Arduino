#define TEMPO 350
#define Door_Sensor 5
byte Play_Status = 0;                //1=Standby, 0=Ready
  byte Aiterukana;                   //ドアの開閉状況を保存

void setup() {
  // put your setup code here, to run once:
  
  pinMode(Door_Sensor, INPUT);       //5番ピンのDoor＿Sensorをインプットに設定
  pinMode(3, OUTPUT);                //3番ピンを音声出力に設定
  Serial.begin(9600);                //デバッグしましょうね^～
  delay(500);
  Play();
}

void loop() {
  // put your main code here, to run repeatedly:
  DoorCheck();                       //ドアの状況を調べる
  if (Aiterukana = 0){               //ドア空いてるんすよ
    if (Play_Status == 0){           //Play_StatusがReadyだった場合の処理
      Play();                        //いらっしゃーせー
    }else{                           //Play_StatusがStandbyだったらどうするんよ
      delay(1);                      //なにもしない()
    }
  }else{                             //ドア閉まってるんすよ
    Play_Status = 0;                 //いつでもならせるようにしとこ
  }
  Serial.print("Play_Status:");
  Serial.println(Play_Status);
  Serial.print("Aiterukana:");
  Serial.println("Aiterukana");
  Serial.println("//-----------------");
  
}

void DoorCheck(){                    //0=open, 1=close
  byte Door_Status = digitalRead(Door_Sensor);
  if (Door_Status = 0){
    int Aiterukana = 0;              //空いてるらしいんで0ですねぇ 
  }else{
    int Aiterukana = 1;              //閉まってるっぽいので1だわ
  }
}

void Play() {                        //いらっしゃいませぇ～
  tone(12, 392, TEMPO);
  delay(TEMPO);
  tone(12, 311, TEMPO);
  delay(TEMPO);
  tone(12, 233, TEMPO);
  delay(TEMPO);
  tone(12, 311, TEMPO);
  delay(TEMPO);
  tone(12, 349, TEMPO);
  delay(TEMPO);
  tone(12, 466, 2*TEMPO);
  delay(2*TEMPO);
  tone(12, 233, TEMPO);
  delay(TEMPO);
  tone(12, 349, TEMPO);
  delay(TEMPO);
  tone(12, 392, TEMPO);
  delay(TEMPO);
  tone(12, 349, TEMPO);
  delay(TEMPO);
  tone(12, 233, TEMPO);
  delay(TEMPO);
  tone(12, 311, 3*TEMPO);
  Play_Status = 1;               //ちょっと鳴るの辞めてもらおうか
} 
