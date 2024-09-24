//doc gia tri ADC tu quang dien tro dieu khien bat tat LED
#include "Main.h"
#include "Port.h"
#include "C:\hoc\8051\bai_tap\Library\XPT2046\XPT2046.h"
#include "C:\hoc\8051\bai_tap\Library\LCD16x2_4bit\LCD4.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "String.h"

void main()
{
	unsigned int adc_value;
	LCD_RW = 0;
	Lcd_Init();
	while(1)
	{
//		adc_value = Read_AD_Data(0x94);			//AIN0 doc gia tri tu triet ap AD1 tren bo kit8051 pro
//		adc_value = Read_AD_Data(0xD4);		//   AIN1 doc gia tri tu dien tro nhiet NTC1
		adc_value = Read_AD_Data(0xA4);		//   AIN2 doc gia tri tu quang dien tro
//		adc_value = Read_AD_Data(0xE4);		//   AIN3 doc gia tri tu bo DAC 
		Lcd_Out(1,1,"ADC_value: ");
		Lcd_Chr_Cp(adc_value/1000 + 0x30);
		Lcd_Chr_Cp(adc_value%1000/100 + 0x30);
		Lcd_Chr_Cp(adc_value%100/10 + 0x30);
		Lcd_Chr_Cp(adc_value%10 + 0x30);
		
		Lcd_Out(2,1, "Led: ");
		if(adc_value<100)
		{
			P2_0 = 1;
			Lcd_Out(2, 6,"OFF");
		}else{
			P2_0 = 0;
			Lcd_Out(2, 6, "ON ");
		}
		Delay_ms(500); // chong man hinh LCD bi nhap nhay
	}
}