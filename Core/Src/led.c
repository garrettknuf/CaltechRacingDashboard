/*
 * @file led.c
 * @brief LED utility
 *
 * @author Garrett Knuf
 * @date 4/3/2024
 */

#include "led.h"
#include "main.h"

void Led_Init(void) {
	Led_Off(LED_ID_1);
	Led_Off(LED_ID_2);
	Led_Off(LED_ID_3);
	Led_Off(LED_ID_4);
	Led_Off(LED_ID_5);
	Led_Off(LED_ID_DEBUG1);
	Led_Off(LED_ID_DEBUG2);
}

void Led_On(led_id_t led_id) {
	switch (led_id) {
		case LED_ID_1:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
			break;
		case LED_ID_2:
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
			break;
		case LED_ID_3:
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
			break;
		case LED_ID_4:
			HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_SET);
			break;
		case LED_ID_5:
			HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_SET);
			break;
		case LED_ID_DEBUG1:
			HAL_GPIO_WritePin(DEBUG_LED1_GPIO_Port, DEBUG_LED1_Pin, GPIO_PIN_SET);
			break;
		case LED_ID_DEBUG2:
			HAL_GPIO_WritePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}

void Led_Off(led_id_t led_id) {
	switch (led_id) {
			case LED_ID_1:
				HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
				break;
			case LED_ID_2:
				HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
				break;
			case LED_ID_3:
				HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
				break;
			case LED_ID_4:
				HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
				break;
			case LED_ID_5:
				HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, GPIO_PIN_RESET);
				break;
			case LED_ID_DEBUG1:
				HAL_GPIO_WritePin(DEBUG_LED1_GPIO_Port, DEBUG_LED1_Pin, GPIO_PIN_RESET);
				break;
			case LED_ID_DEBUG2:
				HAL_GPIO_WritePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin, GPIO_PIN_RESET);
				break;
			default:
				break;
		}
}

void Led_Toggle(led_id_t led_id) {
	switch (led_id) {
		case LED_ID_1:
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			break;
		case LED_ID_2:
			HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			break;
		case LED_ID_3:
			HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
			break;
		case LED_ID_4:
			HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
			break;
		case LED_ID_5:
			HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
			break;
		case LED_ID_DEBUG1:
			HAL_GPIO_TogglePin(DEBUG_LED1_GPIO_Port, DEBUG_LED1_Pin);
			break;
		case LED_ID_DEBUG2:
			HAL_GPIO_TogglePin(DEBUG_LED2_GPIO_Port, DEBUG_LED2_Pin);
			break;
		default:
			break;
	}
}
