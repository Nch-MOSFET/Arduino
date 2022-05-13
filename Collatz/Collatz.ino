#define BaudRate 115200

uint32_t number; // コラッツ予想に当てはめる数:

void setup() {
  Serial.begin(BaudRate);
  Serial.println("Start")
  Serial.print(number);
  printOut();
}

void loop() {
  if((number && 0b1) == 0) {
    number = number / 2;
    printOut();
  }else {
    number = (number * 3) + 1;
    printOut();
    number = number / 2;
    printOut();
  }
  while(isEnd()){
  }
}

boolean isEnd() {
  if(number == 0) {
    return true;
  }else {
    return false;
  }
}

void printOut() {
  Serial.print(", ");
  Serial.print(number);
}
