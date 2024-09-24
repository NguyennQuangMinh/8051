// bat led voi gia tri adc tuong ung
#include "Main.h"
#include "Port.h"
#include "C:\hoc\8051\bai_tap\Library\XPT2046\XPT2046.h"
#include "C:\hoc\8051\bai_tap\Library\LCD16x2_4bit\LCD4.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "String.h"

void main()
{
	unsigned int adc_value, voltage;
	LCD_RW = 0;
	Lcd_Init();
	while(1)
	{
		// doc gia tri adc
		adc_value = Read_AD_Data(0x94);			//AIN0 doc gia tri tu triet ap AD1 tren bo kit8051 pro
//		adc_value = Read_AD_Data(0xD4);		//   AIN1 doc gia tri tu dien tro nhiet NTC1
//		adc_value = Read_AD_Data(0xA4);		//   AIN2 doc gia tri tu quang dien tro
//		adc_value = Read_AD_Data(0xE4);		//   AIN3 doc gia tri tu bo DAC 
		Lcd_Out(1, 1, "ADC value: ");
		Lcd_Chr_Cp(adc_value/1000 + 0x30);
		Lcd_Chr_Cp(adc_value%1000/100 + 0x30);
		Lcd_Chr_Cp(adc_value%100/10 + 0x30);
		Lcd_Chr_Cp(adc_value%10 + 0x30);
		
		// doc gia tri voltage tu gia tri ADC
		voltage = (unsigned int)adc_value*(5.0/4095.0)*1000 ;
		Lcd_Out(2, 1, "voltage: ");
		Lcd_Chr_Cp(voltage/1000 + 0x30);
		Lcd_Chr_Cp('.');
		Lcd_Chr_Cp(voltage%1000/100 + 0x30);
		Lcd_Chr_Cp(voltage%100/10 + 0x30);
		Lcd_Chr_Cp(voltage%10 + 0x30);
		
		Delay_ms(500); // chong chop man hinh LCD
		
		// bat led 1
		if(adc_value>682 && adc_value<=1364)
		{
			P2_0 = 0;
			P2_1 = 1;
			P2_2 = 1;
			P2_3 = 1;
			P2_4 = 1;
		}
		// bat led 1,2
		if(adc_value>1364 && adc_value<=2046)
		{
			P2_0 = 0;
			P2_1 = 0;
			P2_2 = 1;
			P2_3 = 1;
			P2_4 = 1;
		}
		// bat led 1,2,3
		else if(adc_value>2046 && adc_value<=2728)
		{
			P2_0 = 0;
			P2_1 = 0;
			P2_2 = 0;
			P2_3 = 1;
			P2_4 = 1;
		}
		//bat led 1,2,3,4
		else if(adc_value>2728 && adc_value<=3410)
		{
			P2_0 = 0;
			P2_1 = 0;
			P2_2 = 0;
			P2_3 = 0;
			P2_4 = 1;
		}
		//bat led 1,2,3,4,5
		else if(adc_value>3410 && adc_value<=4095)
		{
			P2_0 = 0;
			P2_1 = 0;
			P2_2 = 0;
			P2_3 = 0;
			P2_4 = 0;
		}
		//tat toan bo led
		else
		{
			P2_0 = 1;
			P2_1 = 1;
			P2_2 = 1;
			P2_3 = 1;
			P2_4 = 1;
		}
	}
}