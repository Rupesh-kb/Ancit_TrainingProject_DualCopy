#include "runnable.h"
int len;
char txBuff[64];
uint16_t adc_val,adc_val_prev=0;
uint16_t readA = 0;
uint16_t readB = 0;
void runnable_adc_convert_display(void){
	ADC_StartGroupConversion(&adc_pal_1_instance, 0U);
		while(1){
			adc_val=adc_pal_1_results0[0];
			if(adc_val_prev!=adc_val){
			NvM_WriteBlock(ROM_BLOCK,adc_val);
			EEPROM_Read(EEPROM_OFFSET_A,(uint8_t *)&readA,sizeof(readA));
			EEPROM_Read(EEPROM_OFFSET_B,(uint8_t *)&readB,sizeof(readB));
			len = snprintf(txBuff,sizeof(txBuff),"ADC=%u CopyA=%u CopyB=%u\r\n",(unsigned int)adc_val,(unsigned int)readA,(unsigned int)readB);
			if(len>0)
			{
				LPUART_DRV_SendData(INST_LPUART_1,(uint8_t *)txBuff,len);
			}
			adc_val_prev=adc_val;
			}
			OSIF_TimeDelay(500);
		}
}


