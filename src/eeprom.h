
#ifndef EEPROM_H_
#define EEPROM_H_
#include"sdk_project_config.h"
#include <stdio.h>
#define EEPROM_ADDR (0xA0U >> 1)
#define ROM_BLOCK 1U
#define EEPROM_OFFSET_A 0x10U
#define EEPROM_OFFSET_B 0x20U
void EEPROM_Write(uint8_t memAddr, const uint8_t *data, uint8_t len);
void EEPROM_Read(uint8_t memAddr, uint8_t *data, uint8_t len);
void NvM_WriteBlock(uint8_t rom_block,uint16_t value);

#endif /* EEPROM_H_ */
