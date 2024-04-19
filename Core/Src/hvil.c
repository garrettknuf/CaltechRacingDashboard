/*
 * @file hvil.c
 * @brief HVIL (High voltage inter-lock)
 *
 * @author Garrett Knuf
 * @date 4/19/2024
 */

#include "hvil.h"
#include "main.h"

void HVIL_Init(void) {

}

bool HVIL_GetCurrent(void) {
	// TODO this should probably be an interrupt driven event instead

	return HAL_GPIO_ReadPin(HVIL_CURRENT_GPIO_Port, HVIL_CURRENT_Pin);
}

bool HVIL_GetFault(void) {
	// TODO this should probably be an interrupt driven event instead

	return HAL_GPIO_ReadPin(HVIL_FAULT_GPIO_Port, HVIL_FAULT_Pin);
}
