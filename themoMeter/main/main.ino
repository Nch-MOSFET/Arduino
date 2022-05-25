#include <MsTimer2.h>
#include <Keyboard.h>
#include "MAX6675.h"

#define CSV_ENABLED

int thermoDO  = 3;
int thermoCS  = 4;
int thermoCLK = 5;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Keyboard.begin();
  pinMode(2, INPUT_PULLUP);
  
  delay(500);

  Serial.print(thermocouple.readCelsius());

  MsTimer2::set(1000, mainFunc);
  MsTimer2::start();
}

void loop() {
}

void mainFunc() {
  if(digitalRead(2) == HIGH) {
  #ifdef CSV_ENABLED
    Keyboard.print(String(thermocouple.readCelsius()) + ",");
  #else
    Keyboard.println(thermocouple.readCelsius());
  #endif
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('s');
    Keyboard.releaseAll();
  }
}
