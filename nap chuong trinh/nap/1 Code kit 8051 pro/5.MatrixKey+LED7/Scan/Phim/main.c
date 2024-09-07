
#include<reg51.h>

#define GPIO_DIG P0
#define GPIO_KEY P1

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

unsigned char code DIG_CODE[16]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

unsigned char KeyValue;

unsigned char KeyState;
unsigned char DisplayData[8];

void Delay10ms();  
void KeyDown();		 
void DigDisplay(); 

void main(void)
{
	KeyState=0;
	while(1)
	{
		KeyDown();
	 	if(KeyState==1)
		{
			//khi phat hien nut duoc nhan se day cac so cu sang led ben trai tu led 1->led 8
			DisplayData[7]=DisplayData[6];
			DisplayData[6]=DisplayData[5];
			DisplayData[5]=DisplayData[4];
			DisplayData[4]=DisplayData[3];
			DisplayData[3]=DisplayData[2];
			DisplayData[2]=DisplayData[1];
			DisplayData[1]=DisplayData[0];
			DisplayData[0]=DIG_CODE[KeyValue];
			
			KeyState=0; // dat nut nhan ve trang thai chua nhan phim
		}
		DigDisplay();//hien thi du lieu len man hinh
	}				
}

void DigDisplay()
{
	unsigned char i;
	unsigned int j;
	for(i=0;i<8;i++)
	{
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
		// tao 1 khoang delay
		j=10;						 
		while(j--);	
		// dat chan dieu khien sang tat ve muc 0
		GPIO_DIG=0x00;
	}
}

void KeyDown(void)
{
	unsigned int a=0;
	GPIO_KEY=0x0f; //cho 4 bit thap cua chan P1 = 0 tuong ung voi cho cot bang 0
	if(GPIO_KEY!=0x0f) //neu nhu 1 nut duoc nhan tren so hang thi se kiem tra xem nut o hang may cot may duoc nhan
  {
		Delay10ms();
		if(GPIO_KEY!=0x0f)
		{
			KeyState=1; //neu nhu phim duoc nhan thi se day bien kiem tra trang thai nhan phim len muc 1
			Delay10ms();
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			GPIO_KEY=0XF0;
			Delay10ms();
			switch(GPIO_KEY)
			{
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			
			while((a<500)&&(GPIO_KEY!=0xf0))	 
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