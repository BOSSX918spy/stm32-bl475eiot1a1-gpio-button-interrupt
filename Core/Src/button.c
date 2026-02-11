/*
 * button.c
 *
 *  Created on: Feb 11, 2026
 *      Author: bossx918spy
 */
#include "button.h"

/* Debounce configuration */
#define DEBOUNCE_MS 50

/* Private state */
static volatile uint32_t last_press_tick = 0;
static volatile bool button_event = false;

void Button_Init(void)
{
    /* GPIO and EXTI are configured via CubeMX */
    /* No runtime initialization required */
}

void Button_EXTI_Handler(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_13)
    {
        uint32_t now = HAL_GetTick();

        if ((now - last_press_tick) > DEBOUNCE_MS)
        {
            last_press_tick = now;
            button_event = true;
        }
    }
}

bool Button_WasPressed(void)
{
    if (button_event)
    {
        button_event = false;
        return true;
    }

    return false;
}

