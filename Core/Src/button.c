/*
 * @file button.h
 * @brief Button utility
 *
 * @author Garrett Knuf
 * @date 4/3/2024
 */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "button.h"
#include "main.h"
#include "gfx.h"
#include "led.h"

#define DEBOUNCE_TIME 20

typedef struct {
	button_id_t id;					// button ID
	uint8_t counter;				// debounce counter
	GPIO_TypeDef *port;				// GPIO port of button
	uint32_t pin;					// pin of button on the GPIO port
} button_t;

/* Statically allocate button controllers */
static button_t btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8;

/* List of button handles (order must match button_id_t enum) */
static button_t *button_list[BTN_CNT] = {&btn1, &btn2, &btn3, &btn4, &btn5, &btn6, &btn7, &btn8};

void Button_Init(void) {
	btn1 = (button_t) {.id = BTN_ID_1, .counter = 0,
					   .port = BTN1_GPIO_Port, .pin = BTN1_Pin};
	btn2 = (button_t) {.id = BTN_ID_2, .counter = 0,
					   .port = BTN2_GPIO_Port, .pin = BTN2_Pin};
	btn3 = (button_t) {.id = BTN_ID_3, .counter = 0,
					   .port = BTN3_GPIO_Port, .pin = BTN3_Pin};
	btn4 = (button_t) {.id = BTN_ID_4, .counter = 0,
					   .port = BTN4_GPIO_Port, .pin = BTN4_Pin};
	btn5 = (button_t) {.id = BTN_ID_5, .counter = 0,
					   .port = BTN5_GPIO_Port, .pin = BTN5_Pin};
	btn6 = (button_t) {.id = BTN_ID_6, .counter = 0,
				       .port = BTN6_GPIO_Port, .pin = BTN6_Pin};
	btn7 = (button_t) {.id = BTN_ID_DEBUG1, .counter = 0,
					   .port = DEBUG_BTN1_GPIO_Port, .pin = DEBUG_BTN1_Pin};
	btn8 = (button_t) {.id = BTN_ID_DEBUG2, .counter = 0,
					   .port = DEBUG_BTN2_GPIO_Port, .pin = DEBUG_BTN2_Pin};
}

/**
 * @brief Callback function when button pressed
 * @param id (button_id_t) - id of button pressed
 */
static void Button_PressedHandler(button_id_t id) {
	switch (id) {
		case BTN_ID_1:
			Led_Toggle(LED_ID_1);
			break;
		case BTN_ID_2:
			break;
		case BTN_ID_3:
			break;
		case BTN_ID_4:
			break;
		case BTN_ID_5:
			break;
		case BTN_ID_6:
			break;
		case BTN_ID_DEBUG1:
			break;
		case BTN_ID_DEBUG2:
			break;
		default:
			break;
	}
}

/**
 * @brief Callback function when button released
 * @param id (button_id_t) - id of button released
 */
static void Button_ReleasedHandler(button_id_t id) {
	switch (id) {
		case BTN_ID_1:
			break;
		case BTN_ID_2:
			break;
		case BTN_ID_3:
			break;
		case BTN_ID_4:
			break;
		case BTN_ID_5:
			break;
		case BTN_ID_6:
			break;
		case BTN_ID_DEBUG1:
			break;
		case BTN_ID_DEBUG2:
			break;
		default:
			break;
	}
}

void Button_Debounce(void) {
	for (uint8_t i = 0; i < BTN_CNT; i++) {
		// Get next button to debounce
		button_t *btn = button_list[i];

		// Read current state of button
		bool pressed = !HAL_GPIO_ReadPin(btn->port, btn->pin);

		if (!pressed) {
			// If button released then call callback function if it exists
			if (btn->counter == DEBOUNCE_TIME + 1) {
				Button_PressedHandler(btn->id);
			}

			// Button not pressed so reset counter
			btn->counter = 0;
		} else {
			// Do not allow counter to overflow
			if (btn->counter <= DEBOUNCE_TIME) {
				btn->counter++;
				// If counter reaches debounce time then register press
				if (btn->counter == DEBOUNCE_TIME) {
					Button_ReleasedHandler(btn->id);
				}
			}
		}
	}
}
