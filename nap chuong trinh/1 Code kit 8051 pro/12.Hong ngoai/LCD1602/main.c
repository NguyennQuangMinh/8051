#include<reg51.h>
#include"lcd.h"

sbit IRIN=P3^2;

unsigned char code CDIS1[13]={" Red Control "};
unsigned char code CDIS2[13]={" IR-CODE:--H "};

unsigned char IrValue[6];
unsigned char Time;

void IrInit();
void DelayMs(unsigned int );

void main()
{
	unsigned char i;
	IrInit();	
	LcdInit();
	LcdWriteCom(0x80);
	for(i=0;i<13;i++)
	{
		LcdWriteData(CDIS1[i]);	
	}
	LcdWriteCom(0x80+0x40);
	for(i=0;i<13;i++)
	{
		LcdWriteData(CDIS2[i]);	
	}
	while(1)
	{
		IrValue[4]=IrValue[2]>>4;	 	 
		IrValue[5]=IrValue[2]&0x0f;	
		if(IrValue[4]>9)
		{
			LcdWriteCom(0xc0+0x09);		
			LcdWriteData(0x37+IrValue[4]);
		}
		else
		{
			LcdWriteCom(0xc0+0x09);
			LcdWriteData(IrValue[4]+0x30);	
		}	
		if(IrValue[5]>9)
		{
			LcdWriteCom(0xc0+0x0a);
			LcdWriteData(IrValue[5]+0x37);	
		}
		else
		{
			LcdWriteCom(0xc0+0x0a);
			LcdWriteData(IrValue[5]+0x30);	
		}	
	}
}									 

void DelayMs(unsigned int x)   
{
 unsigned char i;
 while(x--)
 {
  for (i = 0; i<13; i++);
 }
}

void IrInit()
{
	IT0=1;	//Bit dieu khien cho phep INT0 tac dong bang muc hay bang canh(0: muc; 1: canh)
	EX0=1; 	// cho phep ngat INT0
	EA=1;		//cho phep ngat toan cuc

	IRIN=1; //chân ngat INT0 P3^2 set len muc 1 (khong can set cung duoc vi luc khong nhan du lieu thi luon o muc 1 roi)
}

void ReadIr() interrupt 0
{
	unsigned char j,k;
	unsigned int err;
	
	Time=0;					 
	DelayMs(70);

	if(IRIN==0)		// khi nhan du lieu
	{	 
		err=1000;		// check loi		
		while((IRIN==0)&&(err>0)) //neu nhan du lieu dong thoi dem check loi
		{			
			DelayMs(1);
			err--;
		} 
		if(IRIN==1)			
		{
			err=500;
			while((IRIN==1)&&(err>0))		 
			{
				DelayMs(1);
				err--;
			}
			for(k=0;k<4;k++)		
			{				
				for(j=0;j<8;j++)	
				{
					err=60;		
					while((IRIN==0)&&(err>0))
//					while (!IRIN)
					{
						DelayMs(1);
						err--;
					}
					err=500;
					while((IRIN==1)&&(err>0))	 
					{
						DelayMs(1);//0.14ms
						Time++;
						err--;
						if(Time>30)
						{
							EX0=1;
							return;
						}
					}
					IrValue[k]>>=1;	 
					if(Time>=8)			
					{
						IrValue[k]|=0x80;
					}
					Time=0;							
				}
			}
		}
		if(IrValue[2]!=~IrValue[3])
		{
			return;
		}
	}			
}