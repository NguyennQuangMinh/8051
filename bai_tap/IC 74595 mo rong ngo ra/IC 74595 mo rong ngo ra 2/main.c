#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

sbit IE74595_SHCP = P2^0; //SRCLK
sbit IE74595_DS = P2^1;		//SER
sbit IE74595_STCP = P2^2;	//RCK



void IE74595_Out(unsigned char *p, unsigned char n)
{
	unsigned int i, j, b;
	for(j = 0; j<n; j++)
	{
		b = *(p + n - j - 1); //Lay tu byte cao nhat den byte thap nhat
		for(i=0; i<8; i++)
		{
			IE74595_DS = b & (0x80>>i); // lay tung bit cua byte b gui ra DS, lay tu bit cao xuong bit thap
			
			// tao xung nhan du lieu
			IE74595_SHCP = 0;
			IE74595_SHCP = 1;
		}
	}

	// tao xung xuat du lieu
	IE74595_STCP = 0;
	IE74595_STCP = 1;
}

void main()
{
	unsigned char buffer[2], i;
	while(1)
	{
		//tat toan bo led 
		for(i =0; i<2; i++)
		{
			buffer[i] = 0x00;
		}
		IE74595_Out(buffer, 2);
		
		Delay_ms(500);
		
		// bat toan bo led
		for(i=0; i<2; i++)
		{
			buffer[i] = 0xFF;
		}
		IE74595_Out(buffer, 2);
		Delay_ms(500);
	}
}
