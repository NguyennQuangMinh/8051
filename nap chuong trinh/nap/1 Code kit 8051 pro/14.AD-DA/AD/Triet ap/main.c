#include"reg51.h"
#include"XPT2046.h"


#define GPIO_DIG P0

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;


unsigned char code DIG_CODE[17]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};


uchar DisplayData[8];		
void DigDisplay(void);
void main(void)
{
	uint temp,count;
	while(1)
	{
	  if(count==50)
	  {
	  	count=0; 
			temp = Read_AD_Data(0x94);		//   AIN0 
	//	temp = Read_AD_Data(0xD4);		//   AIN1
	//	temp = Read_AD_Data(0xA4);		//   AIN2 
	//	temp = Read_AD_Data(0xE4);		//   AIN3
	  }
	  count++;
	  
	  DisplayData[7]=DIG_CODE[0];
	  DisplayData[6]=DIG_CODE[0];
	  DisplayData[5]=DIG_CODE[0];
	  DisplayData[4]=DIG_CODE[0];

	  DisplayData[3]=DIG_CODE[temp%10000/1000];
	  DisplayData[2]=DIG_CODE[temp%1000/100];
	  DisplayData[1]=DIG_CODE[temp%100/10];
	  DisplayData[0]=DIG_CODE[temp%10/1];

	  DigDisplay();
	}
}
void DigDisplay(void)
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
		j=50;						 
		while(j--);	
		GPIO_DIG=0x00;
	}
}
	
