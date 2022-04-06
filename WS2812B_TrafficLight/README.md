# WS2812B_TrafficLight

WS2812B内蔵LEDテープを用いた信号機のデモです

## Circuit (Pin Assignment)

| Arduinoのピン | LEDテープのピン |
|----|----|
| 5V | 5V |
| GND | GND |
| D5 | DI |

## Description

`#define GreenTime` で青灯火時間を指定、`#define ChangingDelay` で青→黃→赤と変化する時間を指定します

7連のLEDテープを使用し、中央を除いた6球を用いて信号機を表現しています
制御には`Adafluit_NeoPixel` のライブラリを使用することで用意に扱えるようになっています
