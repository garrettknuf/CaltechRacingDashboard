/*
 * @file speaker.c
 * @brief Speaker utility
 *
 * @author Garrett Knuf
 * @date 4/15/2024
 */

#include "speaker.h"
#include "main.h"

extern TIM_HandleTypeDef htim8;

static TIM_OC_InitTypeDef sConfigOC = {0};

const uint16_t note_frequencies[NUM_NOTES] = {
    0,      // NOTE_OFF
    261,    // NOTE_C4
    277,    // NOTE_C4_SHARP
    294,    // NOTE_D4
    311,    // NOTE_D4_SHARP
    330,    // NOTE_E4
    349,    // NOTE_F4
    370,    // NOTE_F4_SHARP
    392,    // NOTE_G4
    415,    // NOTE_G4_SHARP
    440,    // NOTE_A4
    466,    // NOTE_A4_SHARP
    494,    // NOTE_B4
};

void Speaker_Init(void) {
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse = 0;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;

	Speaker_SetTone(NOTE_OFF);
}

void Speaker_SetTone(note_t note) {
	if (note != NOTE_OFF) {
		HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_1);

		// Update period of PWM
		uint16_t period = 40000 / note_frequencies[note];
		htim8.Init.Period = period;
		HAL_TIM_Base_Init(&htim8);

		// Update duty cycle (50%)
		sConfigOC.Pulse = period / 2;
		HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_1);

		// Start tone
		HAL_TIM_PWM_Start(&htim8, TIM_CHANNEL_1);
	} else {
		// Stop tone
		HAL_TIM_PWM_Stop(&htim8, TIM_CHANNEL_1);
	}
}

