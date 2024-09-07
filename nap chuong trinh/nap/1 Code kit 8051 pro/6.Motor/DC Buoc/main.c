
#include "reg52.h"


#define GPIO_MOTOR P1
//sbit F1 = P1^0;
//sbit F2 = P1^1;
//sbit F3 = P1^2;
//sbit F4 = P1^3;

sbit K1=P3^0;
sbit K2=P3^1;
sbit K3=P3^2;
sbit K4=P3^3;

unsigned char code FFW[8]={0xf1,0xf3,0xf2,0xf6,0xf4,0xfc,0xf8,0xf9}; 
unsigned char code FFZ[8]={0xf9,0xf8,0xfc,0xf4,0xf6,0xf2,0xf3,0xf1}; 

unsigned char Direction,Speed;
void Delay(unsigned int t);
void  Motor(); 

void main(void) 
{ 
	unsigned char i;
	Speed=30;
  while(1)
	{
		if(K1==0)		
		{
			Delay(1);	
			if(K1==0)
			{
				Direction=1;
			}
			while((i<200)&&(K1==0))	
			{
				Delay(1);
				i++;
			}
			i=0;
		}
		if(K2==0)		
		{
			Delay(1);	
			if(K2==0)
			{
				Direction=2;
			}
			while((i<200)&&(K2==0))	 
			{
				Delay(1);
				i++;
			}
			i=0;
		}			
		if(K3==0)		
		{
			Delay(1);	
			if(K3==0)
			{
				Speed=13;
			}
			while((i<200)&&(K3==0))
			{
				Delay(1);
				i++;
			}
			i=0;
		}
		if(K4==0)		
		{
			Delay(1);	
			if(K4==0)
			{
				Speed=40;
			}
			while((i<200)&&(K4==0))	
			{
				Delay(1);
				i++;
			}
			i=0;
		}		
		Motor();
	}
}


void  Motor()
{ 
	unsigned char i;
	for(i=0;i<8;i++)
	{
		if(Direction==1) 
			GPIO_MOTOR = FFW[i]&0x1f; 
		if(Direction==2) 
			GPIO_MOTOR = FFZ[i]&0x1f;
		Delay(Speed);		
	}	                  
}

void Delay(unsigned int t)
{                           
	unsigned int k;
	while(t--)
	{
		for(k=0; k<80; k++)
		{ }
	}
}



