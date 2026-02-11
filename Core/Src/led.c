/*
 * led.c
 *
 *  Created on: Feb 11, 2026
 *      Author: bossx918spy
 */

#include "stm32l4xx_hal.h"
#include "led.h"

void LED_Init(void)
{
    // GPIO configured via CubeMX
}

void LED_Toggle(void)
{
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
}

