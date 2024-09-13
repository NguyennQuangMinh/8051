
#include<reg51.h>	
#include"lcd.h"

unsigned char PuZh[]=" Pechin Science ";


void main(void)
{
	unsigned char i;
	LcdInit();
	for(i=0;i<16;i++)
	{
		LcdWriteData(PuZh[i]);	
	}
	while(1)
	{
	}				
}