#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

// dem tang tu 0-999
void main()
{
	unsigned char tram, chuc, donvi;
	unsigned int count = 0;
	unsigned char tam;
	while(1)
	{
		tram = count / 100;
		chuc = (count % 100)/10;
		donvi = count % 10;
		
		tam = chuc << 4;   // dich 4 bit cao tai port P2 vao bien tam sau do or voi bien don vi roi truyen vao port P2
		tam = tam | donvi;
		P2 = tam;
		P3 = tram;
		
		Delay_ms(100);
		
		count++;
		count %= 1000;
	}
}

// dem giam tu 999 ve 0
/*
void main()
{
	unsigned char tram, chuc, donvi;
	unsigned int count = 999;
	unsigned char tam;
	while(1)
	{
		tram = count / 100;
		chuc = (count % 100)/10;
		donvi = count % 10;
		
		tam = chuc << 4;   // dich 4 bit cao tai port P2 vao bien tam sau do or voi bien don vi roi truyen vao port P2
		tam = tam | donvi;
		P2 = tam;
		P3 = tram;
		
		Delay_ms(100);
		
		count--;
		if(count == 0) break;
	
	}
}
*/
