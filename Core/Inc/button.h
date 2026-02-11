/*
 * button.h
 *
 *  Created on: Feb 11, 2026
 *      Author: bossx918spy
 */

#ifndef BUTTON_H
#define BUTTON_H

#include "stm32l4xx_hal.h"
#include <stdbool.h>

/* Public API */
void Button_Init(void);
void Button_EXTI_Handler(uint16_t GPIO_Pin);
bool Button_WasPressed(void);

#endif /* BUTTON_H */
