#define primesVol 128
#define BaudRate  9600

uint16_t primes[primesVol];
uint16_t num = 2;

void setup() {
  Serial.begin(BaudRate);
  Serial.println("Start Calculating");
  //0-fill:
  for(uint16_t i = 0; i < primesVol; i++) {
    primes[i] = 0;
  }
  Serial.println("0-fill done");
  while(primes[primesVol] != 0) {
    uint8_t working = 0;
    Serial.println("Working " + String(working));
    if(detectPrime(num)) {
      //numは素数だった場合:
      primes[working] = num;
      Serial.println(String(num) + " is a prime");
      num++;
      working++;
    }else{
      Serial.println(String(num) + "is not a prime");
      num++;
    }
  }
  Serial.println("make primes[] done");
  Serial.println("starting send-out");
  for(uint16_t i = 0; i < primesVol; i++) {
    Serial.println("primes[" + String(i) + "] = " + String(primes[i]));
  }
  Serial.println("all job has done");
}

void loop() {
  
}

bool detectPrime(uint16_t dat) {
  bool isPrime;
  for(uint16_t i = 1; i < dat; i++) {
    //datをiで割った余りを出す baseがdatとiの商、diffが余り:
    uint16_t base = floor(dat / i);
    Serial.println("base = " + String(base));
    uint16_t diff = dat - (base * i);
    Serial.println("diff = " + String(diff));
    if(diff == 0 && dat != base) {
      //この時のbaseはdatの約数、つまり約数を持っているので素数ではない:
      isPrime = false;
      Serial.println("isPrime = false");
      goto esc;
    }else if(dat == base) {
      //このときdatは素数:
      isPrime = true;
      Serial.println("isPrime = true");
      goto esc;
    }
  }
  esc:
  return isPrime;
}

/*
 * メモ
 * リーマン・ゼータ関数
 */
