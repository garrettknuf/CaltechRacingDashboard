///*
// * @file init.h
// * @brief Hardware initialization code
// *
// * @author Garrett Knuf
// * @date 4/1/2024
// */
//
#ifndef INC_INIT_H_
#define INC_INIT_H_

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void);

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
void MX_ADC1_Init(void);

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
void MX_CAN1_Init(void);

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
void MX_I2C1_Init(void);

/**
  * @brief SPI4 Initialization Function
  * @param None
  * @retval None
  */
void MX_SPI4_Init(void);

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
void MX_TIM2_Init(void);

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
void MX_TIM3_Init(void);

/**
  * @brief TIM8 Initialization Function
  * @param None
  * @retval None
  */
void MX_TIM8_Init(void);

/**
  * @brief USB_OTG_FS Initialization Function
  * @param None
  * @retval None
  */
void MX_USB_OTG_FS_USB_Init(void);

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void MX_GPIO_Init(void);

#endif /* INC_INIT_H_ */
