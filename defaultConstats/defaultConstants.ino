//シリアル通信用のボーレート:
#define BaudRate 115200

//String()で変換するときの基数. BIN, DEC, HEXのいづれか:
#define dataType DEC

/* DECでの実行結果
LSBFIRST     = 0
MSBFIRST     = 1
BIN          = 2
DEC          = 10
HEX          = 16
HIGH         = 1
LOW          = 0
true         = 1
false        = 0
INPUT        = 0
OUTPUT       = 1
INPUT_PULLUP = 2
LED_BUILTIN  = 13
 */

void setup() {
  Serial.begin(BaudRate);
  Serial.println("LSBFIRST     = " + String(LSBFIRST     , dataType));
  Serial.println("MSBFIRST     = " + String(MSBFIRST     , dataType));
  Serial.println("BIN          = " + String(BIN          , dataType));
  Serial.println("DEC          = " + String(DEC          , dataType));
  Serial.println("HEX          = " + String(HEX          , dataType));
  Serial.println("HIGH         = " + String(HIGH         , dataType));
  Serial.println("LOW          = " + String(LOW          , dataType));
  Serial.println("true         = " + String(true         , dataType));
  Serial.println("false        = " + String(false        , dataType));
  Serial.println("INPUT        = " + String(INPUT        , dataType));
  Serial.println("OUTPUT       = " + String(OUTPUT       , dataType));
  Serial.println("INPUT_PULLUP = " + String(INPUT_PULLUP , dataType));
  Serial.println("LED_BUILTIN  = " + String(LED_BUILTIN  , dataType));
}

void loop() {
}
