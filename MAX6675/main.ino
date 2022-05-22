#include "max6675.h"


int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;


MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(115200);

  delay(500);
}

void loop() {
   Serial.println(thermocouple.readCelsius());

   delay(1000);
}
