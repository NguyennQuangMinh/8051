//dieu khien 4 led bat tat theo thu tu bang ngat 
#include "main.h"
#include "port.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"

void main()
{
	IT1 = 1; //bat ngat o chan IT1
	EX1 = 1; // cho phep ngat o chan IT1
	EA =1; // cho phep ngat toan cuc
	LED_1 = LED_2 = LED_3 = LED_4 = 0;
	while(1)
	{
		PCON |= 0x01;
	}
}

void EX1_ISR(void) interrupt 2
{
	if(!BTN_1)
	{
		LED_1 = !LED_1;
		while(!BTN_1);
	}
	if(!BTN_2)
	{
		LED_2 = !LED_2;
		while(!BTN_1);
	}
	if(!BTN_3)
	{
		LED_3 = !LED_3;
		while(!BTN_3);
	}
	if(!BTN_4)
	{
		LED_4 = !LED_4;
		while(!BTN_4);
	}
}
