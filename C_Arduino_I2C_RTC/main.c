/*
 * C_Arduino_I2C_RTC.c
 *
 * Created: 19.1.2023. 00:01:57
 * Author : Aleksandar Bogdanovic
 */ 

#include <avr/io.h>
#include "config/config.h"
#include <util/delay.h>
#include "rtc/rtc.h"
#include "rtc/rtc_define.h"
#include "twi/twi.h"

void RTC_setup()
{
	TWI_Init();
	
	uint8_t byte, stored;
	
	RTC_write(byte, DS3231_REG_RTC_ADDRESS);
	_delay_ms(100);
	RTC_read(DS3231_REG_RTC_ADDRESS, &stored);	
}



int main(void)
{
    RTC_setup();
	
    while (1) 
    {
		//
    }
}

