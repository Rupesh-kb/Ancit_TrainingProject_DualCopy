#include "eeprom.h"
void EEPROM_Write(uint8_t memAddr, const uint8_t *data, uint8_t len) {
	uint8_t buf[16]={memAddr};
	for (uint8_t i = 0; i < len; i++)
		buf[i + 1] = data[i];
	LPI2C_DRV_MasterSetSlaveAddr(0, EEPROM_ADDR, false);
	LPI2C_DRV_MasterSendDataBlocking(0, buf, len + 1, true, 100);
	OSIF_TimeDelay(10);
}
void EEPROM_Read(uint8_t memAddr, uint8_t *data, uint8_t len) {
	LPI2C_DRV_MasterSetSlaveAddr(0U, EEPROM_ADDR, false);
	LPI2C_DRV_MasterSendDataBlocking(0, &memAddr, 1, false, 100);
	LPI2C_DRV_MasterReceiveDataBlocking(0, data, len, true, 100);
}
void NvM_WriteBlock(uint8_t rom_block,uint16_t value){
	 if (rom_block == ROM_BLOCK)
	    {
	        EEPROM_Write(EEPROM_OFFSET_A,(const uint8_t *)&value,sizeof(value));
	        OSIF_TimeDelay(10U);
	        EEPROM_Write(EEPROM_OFFSET_B,(const uint8_t *)&value,sizeof(value));
	    }
}
