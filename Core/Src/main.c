/**
 * @file main.c
 * @brief Main file for ILI94868 Display Driver Demo
 *
 * @author Garrett Knuf
 * @date 3/29/2024
 */

/* Auto-generated includes */
#include "main.h"
#include "stm32f4xx_it.h"

/* User-defined includes */
#include "button.h"
#include "can.h"
#include "display.h"
#include "encoder.h"
#include "init.h"
#include "hvil.h"
#include "led.h"
#include "gfx.h"
#include "img.h"
#include "pot.h"
#include "segdisp.h"
#include "speaker.h"
#include "timer.h"
#include "ui.h"

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Configure the system clock */
	SystemClock_Config();

	/* Initialize all configured peripherals */
	MX_GPIO_Init();				// GPIO pins
	MX_ADC1_Init();				// potentiometers
	MX_CAN1_Init();				// CAN bus
	MX_USB_OTG_FS_USB_Init();	// USB interface
	MX_I2C1_Init();				// Segmented display
	MX_SPI4_Init();				// LCD display
	MX_TIM2_Init();				// 1s interrupt timer
	MX_TIM3_Init();				// 1ms interrupt timer
	MX_TIM8_Init();				// Speaker PWM

	/* Turn off all LEDs */
	Led_Init();

	/* Reset button controllers */
	Button_Init();

	/* Initialize rotary encoder controllers */
	Encoder_Init();

	/* Initialize potentiometer controllers */
	Pot_Init();

	/* Initialize display */
	Display_Init();

	/* Initialize graphics unit */
	Gfx_Init();

	/* Initialize UI */
	UI_Init();

	/* Turn off speaker */
	Speaker_Init();

	/* Initialize CAN bus communication */
	//CAN_Init();

	/* Initialize HVIL */
	HVIL_Init();

	/* Start interrupts from timer */
	Timer_EnableInterrupts();


	while (1)
	{

	}

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}
