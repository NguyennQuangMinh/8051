#include <REGX52.H>

void Delay_ms(unsigned int t)
{
	unsigned int x, y;
	for(x=0; x<t; x++)
	{
		for(y=0; y<123; y++);
	}
}

void main()
{
	unsigned int i;
	
	while(1)
	{
		// Moi hieu ung thuc hien 5 lan
		
		// Hieu ung 1: ca 8 chan sang ca 8 chan tat
		for(i=0; i<5; i++)
		{
			P0 = 0x00;
			Delay_ms(500);
			P0 = 0xFF;
			Delay_ms(500);
		}
		
		// Hieu ung 2: 4 led dau sang, 4 led sau tat va nguoc lai
		for(i=0; i<5; i++)
		{
			P0 = 0xF0;
			Delay_ms(500);
			P0 = 0x0F;
			Delay_ms(500);
		}
		
		
		// Hieu ung 3: chop tat xen ke cac chan chan sang thi cac chan le tat, cac chan le sang thi cac chan chan tat
		for(i=0; i<5; i++)
		{
			P0 = 0xAA; // doi he 2 -> he 16 (BIN -> HEX)
			Delay_ms(500);
			P0 = 0x55;
			Delay_ms(500); // doi he 2 -> he 16 (BIN -> HEX)
		}
		
		// sang va tat tung led tu tren xuong
		P0 = 0x01;
		Delay_ms(500);
		P0 = 0x02;
		Delay_ms(500);
		P0 = 0x04;
		Delay_ms(500);
		P0 = 0x08;
		Delay_ms(500);
		P0 = 0x10;
		Delay_ms(500);
		P0 = 0x20;
		Delay_ms(500);
		P0 = 0x40;
		Delay_ms(500);
		P0 = 0x80;
		Delay_ms(500);
		
		// sang va tat tung led tu duoi lem
		P0 = 0x80;
		Delay_ms(500);
		P0 = 0x40;
		Delay_ms(500);
		P0 = 0x20;
		Delay_ms(500);
		P0 = 0x10;
		Delay_ms(500);
		P0 = 0x08;
		Delay_ms(500);		
		P0 = 0x04;
		Delay_ms(500);		
		P0 = 0x02;
		Delay_ms(500);		
		P0 = 0x01;
		Delay_ms(500);		
	}
}