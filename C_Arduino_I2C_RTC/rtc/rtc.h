/*
 * rtc.h
 *
 * Created: 19.1.2023. 00:33:52
 *  Author: Aleksandar Bogdanovic
 */ 

#ifndef RTC_H_
#define RTC_H_

void RTC_write(uint8_t data, uint8_t address);
void RTC_read(uint8_t address, uint8_t* ptr);
void EEPROM_Read(uint8_t address, uint8_t* ptr);

#endif /* RTC_H_ */