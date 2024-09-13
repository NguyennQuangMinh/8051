//su dung cam bien nhiet do LM335 hien thi nhiet do len LCD

#include "Main.h"
#include "Port.h"
#include "C:\hoc\8051\bai_tap\Library\LCD16x2_4bit\LCD4.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\ADC0804\ADC0804.h"
#include "String.h"
#include "stdio.h"

void main()
{
	unsigned char adc_value;
	unsigned int temp;
	char buff[16];
	
	LCD_RW = 0;
	Lcd_Init();

	while(1)
	{
		adc_value = ADC0804_Read(); //doc gia tri ADC tu ic ADC0804 gan vao bien adc_value
		
		temp = (unsigned int)(adc_value*(100.0/255.0));
		sprintf(buff, "Nhiet do:%3d",temp);
		Lcd_Out(1,1,buff);
		
		Delay_ms(200); // tranh man hinh LCD nhap nhay
			
	}
}
