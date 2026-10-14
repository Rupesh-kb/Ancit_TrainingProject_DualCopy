#include"sdk_project_config.h"
#include "eeprom.h"
#include "runnable.h"
lpi2c_master_state_t lpi2c1MasterState;
int main(void){
	CLOCK_DRV_Init(&clockMan1_InitConfig0);
	PINS_DRV_Init(NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0);
	LPUART_DRV_Init(INST_LPUART_1,&lpUartState0,&lpuart_0_InitConfig0);
	ADC_Init(&adc_pal_1_instance, &adc_pal_1_config);
	LPI2C_DRV_MasterInit(0U,&lpi2c0_MasterConfig0,&lpi2c1MasterState);

	runnable_adc_convert_display();
}
