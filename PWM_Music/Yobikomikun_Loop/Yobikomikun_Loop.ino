#define PIN 12

#define BPM 128

#define hachibu 30000/BPM // 0.5*60*1000
#define hutenhachibu 45000/BPM // 1.5*0.5*60*1000
#define shibu 60000/BPM // 60*1000
#define hutenshibu 90000/BPM // 1.5*60*1000
#define nibu 120000/BPM // 2*60*1000
#define hutennibu 180000/BPM // 2*1.5*60*1000
#define zen 240000/BPM // 4*60*1000

#define soushoku 5000/BPM // 数字は適当

#define doL 131
#define dosL 139
#define reL 147
#define resL 156
#define miL 165
#define faL 175
#define fasL 185
#define soL 196
#define sosL 208
#define raL 220
#define rasL 233
#define siL 247

#define doM 262
#define dosM 277
#define reM 294
#define resM 311
#define miM 330
#define faM 349
#define fasM 370
#define soM 392
#define sosM 415
#define raM 440
#define rasM 466
#define siM 494

#define doH 523
#define dosH 554
#define reH 587
#define resH 622
#define miH 659
#define faH 698
#define fasH 740
#define soH 784
#define sosH 830
#define raH 880
#define rasH 932
#define siH 988


/*
  tone(Pin, Takasa, Nagasa);
  delay(Nagasa);
 * 
  tone(PIN, , );
  delay();
 * 
 */


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, raH, shibu);
  delay(shibu);
  tone(PIN, siH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  delay(hachibu);
  //-------------------------------
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, raH, shibu);
  delay(shibu);
  tone(PIN, siH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  delay(hachibu);
  //-------------------------------
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, hutenshibu);
  delay(hutenshibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  //-------------------------------
  tone(PIN, fasH, hutenshibu);
  delay(hutenshibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, raH, nibu);
  delay(nibu);
  //-------------------------------
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, nibu);
  delay(nibu);
  //-------------------------------
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, nibu);
  delay(nibu);
  //-------------------------------
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(shibu);
  tone(PIN, fasH, hachibu);
  delay(shibu);
  //-------------------------------
  tone(PIN, raH, hachibu);
  delay(shibu);
  tone(PIN, soH, hachibu);
  delay(shibu);
  tone(PIN, fasH, hachibu);
  delay(shibu);
  tone(PIN, miH, hachibu);
  delay(shibu);
  //-------------------------------
  //-------------------------------
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, raH, shibu);
  delay(shibu);
  tone(PIN, siH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  delay(hachibu);
  //-------------------------------
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, raH, shibu);
  delay(shibu);
  tone(PIN, siH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  delay(hachibu);
  //-------------------------------
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, hutenshibu);
  delay(hutenshibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  //-------------------------------
  tone(PIN, fasH, hutenshibu);
  delay(hutenshibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, raH, nibu);
  delay(nibu);
  //-------------------------------
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, nibu);
  delay(nibu);
  //-------------------------------
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, nibu);
  delay(nibu);
  //-------------------------------
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(hachibu);
  tone(PIN, reH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(shibu);
  tone(PIN, fasH, hachibu);
  delay(shibu);
  //-------------------------------
  tone(PIN, raH, hachibu);
  delay(shibu);
  tone(PIN, soH, hachibu);
  delay(shibu);
  tone(PIN, fasH, hachibu);
  delay(shibu);
  tone(PIN, miH, hachibu);
  delay(shibu);
  //-------------------------------
  //-------------------------------
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, raH, shibu);
  delay(shibu);
  tone(PIN, siH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(shibu);
  //-------------------------------
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, raH, shibu);
  delay(shibu);
  tone(PIN, siH, hachibu);
  delay(hachibu);
  tone(PIN, raH, hachibu);
  delay(hachibu);
  tone(PIN, fasH, hachibu);
  delay(hachibu);
  tone(PIN, miH, hachibu);
  delay(shibu);
  //-------------------------------
  tone(PIN, reH, zen);
  delay(zen);
  //-------------------------------
  //-------------------------------
  delay(zen);
}
