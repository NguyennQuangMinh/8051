#include "main.h"
#include "port.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\ADC0804\ADC0804.h"
#include "C:\hoc\8051\bai_tap\Library\LCD16x2_4bit\LCD4.h"
#include "String.h"

void main()
{
	unsigned char adc_value;
	unsigned int temp;
	LCD_RW = 0;	//dat LCD o che do ghi
	Lcd_Init();	//khoi tao LCD
	while(1)
	{
		adc_value = ADC0804_Read();
		temp = (unsigned int)(adc_value*(5.0/255)*100);
		Lcd_Out(1,1,"Nhiet do: ");
		Lcd_Chr_Cp(temp/100 + 0x30);
		Lcd_Chr_Cp(temp%100/10 + 0x30);
		Lcd_Chr_Cp(temp%10 + 0x30);

		Delay_ms(500);
	}
}
