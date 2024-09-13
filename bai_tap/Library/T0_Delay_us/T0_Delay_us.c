//trong ham main.c cua code chinh
//thiet lap timer 0 mode 1 (Mode timer 16 bit)
//TMOD &= 0xF0; //xoa bo nho timer 0
//TMOD |= 0x01; //set cai dat timer 0 chay mode 1


#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\T0_Delay_us\T0_Delay_us.h"

void T0_Delay_us(unsigned int t)  // tao delay us bang Timer 0 voi moi lan dem 1 bit la 1us
{
	unsigned int load_value;
	load_value = 65536 - t;
	TH0 = load_value >> 8;
	TL0 = load_value & 0x00FF;
	TR0 = 1; // bat dau dem
	while(!TF0); // cho den khi dem xong bao tran
	TR0 = 0; // ngung dem
	TF0 = 0; // tat co bao tran
}