void setup() {
  Serial.begin(115200);
}

void loop() {
  uint8_t number = random(256);
  
  for(uint8_t i = 0; i < 8; i++){
    Serial.print("number = ");
    Serial.println(number, BIN);
    number = number >> 1;
    Serial.println(number >> 1);
  }
  Serial.println("Reset");
  Serial.println();

  delay(1000);
}
