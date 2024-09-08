#include "Main.h"
#include "Port.h"
#include "C:\hoc\8051\bai_tap\Library\LCD16x2_4bit\LCD4.h"
#include "C:\hoc\8051\bai_tap\Library\Delay\Delay.h"
#include "C:\hoc\8051\bai_tap\Library\ADC0804\ADC0804.h"
#include "String.h"

void main()
{
	unsigned char adc_value;
	unsigned int voltage;
	Lcd_Init();
	while(1)
	{
		// hien thi gia tri ADC
		adc_value = ADC0804_Read();
		Lcd_Out(1,1,"ADC value: ");
		Lcd_Chr_Cp(adc_value/100 + 0x30);
		Lcd_Chr_Cp(adc_value%100/10 + 0x30);
		Lcd_Chr_Cp(adc_value%10 + 0x30);
		
		// hien thi gia tri voltage
		voltage = (unsigned int)(adc_value * (5.0/255.0) *100);
		Lcd_Out(2,1,"voltage: ");
		Lcd_Chr_Cp(voltage/100 + 0x30);
		Lcd_Chr_Cp('.');
		Lcd_Chr_Cp(voltage%100/10 + 0x30);
		Lcd_Chr_Cp(voltage%10 + 0x30);
		
		Delay_ms(500); //tranh nhap nhay man hinh Lcd tren mach that
	}
}
