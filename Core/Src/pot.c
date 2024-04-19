/*
 * @file pot.c
 * @brief Potentiometer utility
 *
 * @author Garrett Knuf
 * @date 4/8/2024
 */

#include <stdint.h>
#include "pot.h"
#include "gfx.h"
#include "main.h"

#define ADC_NOISE_DELTA 100

typedef struct {
	pot_id_t id;
	int16_t last_reading;
	int adc_channel;
} pot_t;

static pot_t pot1, pot2, pot3, pot4;
static pot_t *pot_list[] = {&pot1, &pot2, &pot3, &pot4};

static pot_id_t current_pot = 0;

extern ADC_HandleTypeDef hadc1;
ADC_ChannelConfTypeDef sConfig = {0};

void Pot_Init(void) {

	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;


	pot1 = (pot_t) {.id = POT_ID_1, .last_reading = 0, .adc_channel = ADC_CHANNEL_0};
	pot2 = (pot_t) {.id = POT_ID_2, .last_reading = 0, .adc_channel = ADC_CHANNEL_1};
	pot3 = (pot_t) {.id = POT_ID_3, .last_reading = 0, .adc_channel = ADC_CHANNEL_2};
	pot4 = (pot_t) {.id = POT_ID_4, .last_reading = 0, .adc_channel = ADC_CHANNEL_3};
}

/**
 * @brief Event handler for changes in pot values
 * @param id (pot_id_t) - id of pot that changed
 * @param sample (int16_t) - new value of pot
 */
static void Pot_EventHandler(pot_id_t id, int16_t sample) {
	switch (id) {
		case POT_ID_1:
			break;
		case POT_ID_2:
			break;
		case POT_ID_3:
			break;
		case POT_ID_4:
			break;
		default:
			break;
	}
}

void Pot_Sample(void) {
	// Get next pot to sample
	pot_t *pot = pot_list[current_pot];

	// Configure ADC channel for pot
	sConfig.Channel = pot->adc_channel;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);

	// Start blocking ADC conversion
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 100);
	int16_t sample = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	// Only call event handler if pot changed value greater than noise threshold
	if (sample - pot->last_reading > ADC_NOISE_DELTA ||
		sample - pot->last_reading < -ADC_NOISE_DELTA) {
		pot->last_reading = sample;
		Pot_EventHandler(pot->id, sample);
	}

	// Trigger sampling for next pot
	current_pot = (current_pot + 1) % POT_CNT;
	pot = pot_list[current_pot];
}
