
#include<reg51.h>
//#include<intrins.h>	

#define GPIO_DIG P0
#define GPIO_KEY P1

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

unsigned char code DIG_CODE[17]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

unsigned char KeyValue;

unsigned char KeyState;	
unsigned char DisplayData[8];

unsigned char Num;
void Delay50us();
void KeyDown();		 
void DigDisplay();
void TimerConfiguration();

void main(void)
{
	TimerConfiguration();
	KeyState=0;	 
	while(1)
	{
		KeyDown();
	 	if(KeyState==1)
		{
			DisplayData[7]=DisplayData[6];
			DisplayData[6]=DisplayData[5];
			DisplayData[5]=DisplayData[4];
			DisplayData[4]=DisplayData[3];
			DisplayData[3]=DisplayData[2];
			DisplayData[2]=DisplayData[1];
			DisplayData[1]=DisplayData[0];
			DisplayData[0]=DIG_CODE[KeyValue];
			KeyState=0;
		}
//		DigDisplay();
	}				
}

void TimerConfiguration()
{
	TMOD=0X02;

	TH0=0X9C;	
	TL0=0X9C;	
	ET0=1;
	EA=1;
	TR0=1;	
}

void DigDisplay()
{
	unsigned char i,j;
//	for(i=0;i<8;i++)
//	{
		GPIO_DIG=0x00;
		switch(i)	
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;
			case(1):
				LSA=1;LSB=0;LSC=0; break;
			case(2):
				LSA=0;LSB=1;LSC=0; break;
			case(3):
				LSA=1;LSB=1;LSC=0; break;
			case(4):
				LSA=0;LSB=0;LSC=1; break;
			case(5):
				LSA=1;LSB=0;LSC=1; break;
			case(6):
				LSA=0;LSB=1;LSC=1; break;
			case(7):
				LSA=1;LSB=1;LSC=1; break;	
		}
		GPIO_DIG=DisplayData[i];
		i++;
		if(i>7)
			i=0;
//		j=10;				
//		while(j--)
//			Delay50us();	
//		GPIO_DIG=0x00;
//	}
}

void KeyDown(void)
{
	unsigned int a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)
  {
		Delay50us();
		a++;	
		a=0;
		if(GPIO_KEY!=0x0f)
		{
			ET0=0;
			KeyState=1;
			
			GPIO_KEY=0X0F;
// 			Delay50us();
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
//				default:	KeyValue=17;	
			}
			
			GPIO_KEY=0XF0;
			Delay50us();
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
//				default:	KeyValue=17;
			}
			ET0=1;
			while((a<5000)&&(GPIO_KEY!=0xf0))	
			{
				Delay50us();
				a++;
			}
			a=0;
		}
	}
}

void Delay50us(void)   
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=22;a>0;a--);
}

void Timer() interrupt 1
{
	DigDisplay();	
}