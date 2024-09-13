//trong ham main.c cua code chinh
//thiet lap timer 0 mode 1 (Mode timer 16 bit)
//TMOD &= 0xF0; //xoa bo nho timer 0
//TMOD |= 0x01; //set cai dat timer 0 chay mode 1
#ifndef _T0_DELAY_US_H_
#define _T0_DELAY_US_H_

void T0_Delay_us(unsigned int t);

#endif