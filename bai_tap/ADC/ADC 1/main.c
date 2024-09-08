#include "main.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "Port.h"
#include "C:\hoc\8051\bai_tap\Library\LCD16x2_4bit\LCD4.h"
#include "String.h"

unsigned char ADC_READ()
{
	P2 = 255;
	while(P3_0)
	{
		P2--;
		if(P2==0) break;
	}
	return P2;
}

void main()
{
	unsigned int adc_value, voltage;
	Lcd_Init();
	while(1)
	{
		//doc gia tri adc
		adc_value = ADC_READ();
		Lcd_Out(1,1, "ADC value: ");
		Lcd_Chr_Cp(adc_value/100 + 0x30);
		Lcd_Chr_Cp(adc_value%100/10 + 0x30);
		Lcd_Chr_Cp(adc_value%10 + 0x30);
		
		//doc dien ap adc
		voltage = (unsigned int)(adc_value * (5.0 / 256.0) * 100);
		Lcd_Out(2,1, "Voltage: ");
		Lcd_Chr_Cp(voltage/100 + 0x30);
		Lcd_Out_Cp(".");
		Lcd_Chr_Cp(voltage%100/10 + 0x30);
		Lcd_Chr_Cp(voltage%10 + 0x30);
		
		Delay_ms(500); //tranh chop tat man hinh LCD lien tuc
	}
}


