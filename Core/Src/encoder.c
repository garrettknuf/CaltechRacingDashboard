/*
 * @file encoder.c
 * @brief Encoder utility
 *
 * @author Garrett Knuf
 * @date 4/8/2024
 */

#include <stdint.h>
#include "main.h"
#include "encoder.h"

typedef struct {
	encoder_id_t id;
	uint8_t last_code;
	GPIO_TypeDef *port;				// GPIO port of button
	uint32_t pinA;					// pin of A connector
	uint32_t pinB;					// pin of B connector
} encoder_t;

static encoder_t enc1;
static encoder_t *encoder_list[ENC_CNT] = {&enc1};

static int8_t Encoder_ReadBinary(encoder_t *enc) {
	/* Get gray code */
	GPIO_PinState pinA = HAL_GPIO_ReadPin(enc->port, enc->pinA);
	GPIO_PinState pinB = HAL_GPIO_ReadPin(enc->port, enc->pinB);

	/* Convert gray code to binary */
	int8_t binary = 0;
	binary |= (pinA << 1);
	binary |= (pinB << 0);
	return binary;
}

void Encoder_Init(void) {
	enc1 = (encoder_t) {.id = ENC_ID_1, .last_code = 0, .port = ROT_ENC_A_GPIO_Port,
						.pinA = ROT_ENC_A_Pin, .pinB = ROT_ENC_B_Pin};
	enc1.last_code = Encoder_ReadBinary(&enc1);
}

/**
 * @brief Callback function when encoder turned clockwise
 * @param id (encoder_id_t) - id of encoder rotated
 */
static void Encoder_CWHandler(encoder_id_t id) {
	switch (id) {
		case ENC_ID_1:
			break;
		default:
			break;
	}
}

/**
 * @brief Callback function when encoder turned counter-clockwise
 * @param id (encoder_id_t) - id of encoder rotated
 */
static void Encoder_CCWHandler(encoder_id_t id) {
	switch (id) {
		case ENC_ID_1:
			break;
		default:
			break;
	}
}

void Encoder_Debounce(void) {
	/* Iterate through all encoders */
	for (uint8_t i = 0; i < ENC_CNT; i++) {
		encoder_t *enc = encoder_list[i];

		// Get binary reading of encoder
		int8_t binary = Encoder_ReadBinary(enc);

		/* Check if encoder state has changed */
		if (binary != enc->last_code) {
			uint8_t diff = enc->last_code - binary;
			if (diff == -1 || diff == 3) {
				Encoder_CWHandler(enc->id);
			} else if (diff == 1 || diff == -3) {
				Encoder_CCWHandler(enc->id);
			}
		}

		/* Update state */
		enc->last_code = binary;
	}
}


