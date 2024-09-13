//khai bao ket noi voi ADC0808
//#define ADC0808_DATA P3
//sbit ADC0808_ADDA = P2^0;
//sbit ADC0808_ADDB = P2^1;
//sbit ADC0808_ADDC = P2^2;
//sbit ADC0808_ALE = P2^3;
//sbit ADC0808_START = P2^4;
//sbit ADC0808_EOC = P2^5;
//sbit ADC0808_OE = P2^6;

#include "main.h"
#include "Port.h"
#include "C:\hoc\8051\bai_tap\Library\ADC0808\ADC0808.h"

// khoi tao ADC0808
void ADC0808_Init()
{
	ADC0808_START = 0;
	ADC0808_ALE = 0;
	ADC0808_OE = 0;
}

// doc gia tri dau vao ADC
unsigned char ADC0808_Read(unsigned char channel)
{
	unsigned kq;
	
	// chon kenh doc gia tri dau vao ADC
	ADC0808_ADDA = channel & 0x01;
	ADC0808_ADDB = channel & 0x02;
	ADC0808_ADDC = channel & 0x04;
	
	//bat dau chuyen doi 
	ADC0808_ALE = 1;
	ADC0808_START = 1;
	ADC0808_ALE = 0;
	ADC0808_START = 0;
	
	//cho cho den khi qua trinh chuyen doi xong
	while(ADC0808_EOC); //cho het muc 1
	while(ADC0808_EOC); //cho het muc 0 len lai muc 1 thi la hoan tat qua trinh chuyen doi
	
	// doc gia tri ADC ra chan OUT
	ADC0808_OE = 1;    // cho phep chan OUT xuat du lieu
	kq = ADC0808_DATA; // xuat du lieu ADC gan vao bien kq
	ADC0808_OE = 0;			// ket thuc qua trinh xuat du lieu 
	
	return kq; // tra ve gia tri cho ADC0808_Read()
}
