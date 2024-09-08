// khai bao chan ket noi cua IC adc0804
//#define ADC0804_DATA P2
//sbit ADC0804_CS = P3^0;
//sbit ADC0804_RD = P3^1;
//sbit ADC0804_WR = P3^2;
//sbit ADC0804_INTR = P3^3;

#include "Main.h"
#include "Port.h"
#include "C:\hoc\8051\bai_tap\Library\ADC0804\ADC0804.h"

unsigned char ADC0804_Read()
{
	unsigned char kq;
	
	//chon chip
	ADC0804_CS = 0;
	
	// tao xung bat dau chuyen doi
	ADC0804_WR = 0;
	ADC0804_WR = 1;
	
	// Doi cho den khi chuyen doi xong
	while(ADC0804_INTR);
	
	// doc gia tri sau khi chuyen doi
	ADC0804_RD = 0;
	kq = ADC0804_DATA;
	ADC0804_RD = 1;
	
	return kq;
}