/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define HVIL_CURRENT_Pin GPIO_PIN_0
#define HVIL_CURRENT_GPIO_Port GPIOC
#define POT1_Pin GPIO_PIN_0
#define POT1_GPIO_Port GPIOA
#define POT2_Pin GPIO_PIN_1
#define POT2_GPIO_Port GPIOA
#define POT3_Pin GPIO_PIN_2
#define POT3_GPIO_Port GPIOA
#define POT4_Pin GPIO_PIN_3
#define POT4_GPIO_Port GPIOA
#define DISP_CS_Pin GPIO_PIN_11
#define DISP_CS_GPIO_Port GPIOE
#define DISP_SCK_Pin GPIO_PIN_12
#define DISP_SCK_GPIO_Port GPIOE
#define DISP_MISO_Pin GPIO_PIN_13
#define DISP_MISO_GPIO_Port GPIOE
#define DISP_MOSI_Pin GPIO_PIN_14
#define DISP_MOSI_GPIO_Port GPIOE
#define DISP_DCRS_Pin GPIO_PIN_15
#define DISP_DCRS_GPIO_Port GPIOE
#define DISP_RESET_Pin GPIO_PIN_10
#define DISP_RESET_GPIO_Port GPIOB
#define DISP_ST_LED1_Pin GPIO_PIN_12
#define DISP_ST_LED1_GPIO_Port GPIOB
#define DISP_ST_LED2_Pin GPIO_PIN_13
#define DISP_ST_LED2_GPIO_Port GPIOB
#define BTN6_Pin GPIO_PIN_14
#define BTN6_GPIO_Port GPIOB
#define BTN5_Pin GPIO_PIN_15
#define BTN5_GPIO_Port GPIOB
#define BTN4_Pin GPIO_PIN_8
#define BTN4_GPIO_Port GPIOD
#define BTN3_Pin GPIO_PIN_9
#define BTN3_GPIO_Port GPIOD
#define BTN2_Pin GPIO_PIN_10
#define BTN2_GPIO_Port GPIOD
#define BTN1_Pin GPIO_PIN_11
#define BTN1_GPIO_Port GPIOD
#define ROT_ENC_A_Pin GPIO_PIN_12
#define ROT_ENC_A_GPIO_Port GPIOD
#define ROT_ENC_B_Pin GPIO_PIN_13
#define ROT_ENC_B_GPIO_Port GPIOD
#define SPKR_PWM_Pin GPIO_PIN_6
#define SPKR_PWM_GPIO_Port GPIOC
#define DEBUG_LED1_Pin GPIO_PIN_8
#define DEBUG_LED1_GPIO_Port GPIOC
#define DEBUG_BTN1_Pin GPIO_PIN_9
#define DEBUG_BTN1_GPIO_Port GPIOC
#define DEBUG_BTN2_Pin GPIO_PIN_8
#define DEBUG_BTN2_GPIO_Port GPIOA
#define DEBUG_LED2_Pin GPIO_PIN_9
#define DEBUG_LED2_GPIO_Port GPIOA
#define LED4_Pin GPIO_PIN_3
#define LED4_GPIO_Port GPIOD
#define LED5_Pin GPIO_PIN_4
#define LED5_GPIO_Port GPIOD
#define LED3_Pin GPIO_PIN_5
#define LED3_GPIO_Port GPIOD
#define LED2_Pin GPIO_PIN_6
#define LED2_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_7
#define LED1_GPIO_Port GPIOD
#define SEGDISP_SCL_Pin GPIO_PIN_6
#define SEGDISP_SCL_GPIO_Port GPIOB
#define SEGDISP_SDA_Pin GPIO_PIN_7
#define SEGDISP_SDA_GPIO_Port GPIOB
#define CAN_STBY_Pin GPIO_PIN_0
#define CAN_STBY_GPIO_Port GPIOE
#define HVIL_FAULT_Pin GPIO_PIN_1
#define HVIL_FAULT_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
