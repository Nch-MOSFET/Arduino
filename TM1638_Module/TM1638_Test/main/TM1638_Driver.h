#ifndef TM1638_STB
 #define TM1638_STB 12
#endif
#ifndef TM1638_CLK
 #define TM1638_CLK 11
#endif
#ifndef TM1638_DIO
 #define TM1638_DIO 10
#endif

#define Write_Display_Register 0b01000000
#define Read_Key_Register      0b01000010
#define Set_Register_Addr_00H  0b11000000  //LSB 4bitはレジスタアドレス:
#define Display_ON             0b10001000  //LSB 3bitで輝度を指定:
#define Display_Intensity               2  //0-7:
#define Display_OFF            0b10000000

const uint8_t segments[16] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 
                              0b01100110, 0b01101101, 0b01111101, 0b00100111, 
                              0b01111111, 0b01101111, 0b01110111, 0b01111100, 
                              0b01011000, 0b01011110, 0b01111001, 0b01110001};  //.gfedcba:
