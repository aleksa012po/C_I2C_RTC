/*
 * rtc.c
 *
 * Created: 19.1.2023. 00:32:11
 *  Author: Aleksandar Bogdanovic
 */ 

#include "config.h"
#include "rtc_define.h"
#include <avr/io.h>
#include <util/delay.h>


void RTC_write (uint8_t data, uint8_t address)		// Write to RTC
{
	// Setup time and date that will be displayed
	uint8_t second, minute, hour, day, date, month, year;

	year	= 0x23;
	month	= 0x01;
	date	= 0x23;
	day		= 0x02;
	hour	= 0x00;
	minute	= 0x31;
	second	= 0x51;
	
// --------------------------------
	// Year
	TWI_Start();

	TWI_Write(DS3231_WriteMode);	// Master address is 1010 and a 0 in the 4th bit to indicate WRITING
	
	TWI_Write(DS3231_REG_Year);		// Year address
	
	TWI_Write(year);				// 2023.

	TWI_Stop();
// --------------------------------
	// Month
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Month);	// Month address
	
	TWI_Write(month);				// 01 - January

	TWI_Stop();
// --------------------------------
	// Date
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Date);		// Date address
	
	TWI_Write(date);				// 23.

	TWI_Stop();
// --------------------------------
	// Week day (01 - 07, 01 = Sunday)
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Day);		// Day of the week
	
	TWI_Write(day);					// Monday

	TWI_Stop();
// --------------------------------
	// Hours
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Hour);		// Hours
	
	TWI_Write(hour);				// 00

	TWI_Stop();
// --------------------------------
	// Minutes
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Minutes);	// Minutes
	
	TWI_Write(minute);				// 31

	TWI_Stop();
// --------------------------------
	// Seconds
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(DS3231_REG_Seconds);	// Seconds
	
	TWI_Write(second);				// 51

	TWI_Stop();
}

void RTC_read (char address, char* ptr)// The function arguments are an address in the EEPROM to read from and a pointer to a memory place in the MCU to store the read data in
{
	// Year
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(0x06);	// Year address

	TWI_Start();

	TWI_Write(DS3231_ReadMode);									// Master address is 1011 and a 1 in the 4th bit to indicate READING

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Month
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(0x05);	// Month address
	
	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Day
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(0x04);	// Date address
	
	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Week day (01 - 07, 01 = Sunday)
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(0x03);	// Day of the week
	
	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Hours
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(0x02);	// Hours
	
	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Minutes
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(0x01);	// Hours

	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
// --------------------------------
	// Seconds
	TWI_Start();

	TWI_Write(DS3231_WriteMode);
	
	TWI_Write(0x00);	// Hours
	
	TWI_Start();

	TWI_Write(DS3231_ReadMode);									

	TWI_Read_Nack(ptr);

	TWI_Stop();
}
