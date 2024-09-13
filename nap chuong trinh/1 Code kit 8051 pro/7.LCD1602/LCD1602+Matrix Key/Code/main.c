
#include<reg51.h>	
#include"lcd.h"

#define GPIO_KEY P1

unsigned char KeyValue;

unsigned char KeyState;

unsigned char PuZh[]=" Pechin Science ";
void Delay10ms();   
void KeyDown();		 
 

void main(void)
{
	unsigned char i;
	LcdInit();
	KeyState=0;
	for(i=0;i<16;i++)
	{
		LcdWriteData(PuZh[i]);	
	}
	while(1)
	{
		KeyDown();
		if(KeyState)
		{
			KeyState=0;
			LcdWriteCom(0x80+0x40);
			LcdWriteData('0'+KeyValue);
		}
	}				
}

void KeyDown(void)
{
	char a;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)
	{
		Delay10ms();
		if(GPIO_KEY!=0x0f)
		{
			KeyState=1;
			GPIO_KEY=0X0F;
// 			Delay10ms();
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
//				default:	KeyValue=17;	
			}
			GPIO_KEY=0XF0;
			Delay10ms();
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
//				default:	KeyValue=17;
			}
			while((a<50)&&(GPIO_KEY!=0xf0))	 
			{
				Delay10ms();
				a++;
			}
			a=0;
		}
	}
}

void Delay10ms(void)   
{
    unsigned char a,b,c;
    for(c=1;c>0;c--)
        for(b=38;b>0;b--)
            for(a=130;a>0;a--);
}
