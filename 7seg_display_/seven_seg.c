#include "seven_seg.h"

void sevenseg_init(void)
{
    uint8_t sevenseg_pins;
    uint8_t lpins;

    /* Enable GPIO clocks */
    GPIO_Init_Clock(GPIO_PORTB_BASE);
    GPIO_Init_Clock(GPIO_PORTE_BASE);
    GPIO_Init_Clock(GPIO_PORTF_BASE);

    /* PB0-PB6 -> 7 segment */
    sevenseg_pins = PIN0 | PIN1 | PIN2 |
                    PIN3 | PIN4 | PIN5 | PIN6;

    GPIO_Init_Pin(
        GPIO_PORTB_BASE,
        sevenseg_pins,
        OUTPUT,
        PULL_DISABLE
    );

    /* PE0-PE3 -> control pins */
    lpins = PIN0 | PIN1 | PIN2 | PIN3;

    GPIO_Init_Pin(
        GPIO_PORTE_BASE,
        lpins,
        OUTPUT,
        PULL_DISABLE
    );

    /* PF0 and PF4 -> buttons */
    lpins = PIN0 | PIN4;

    GPIO_Init_Pin(
        GPIO_PORTF_BASE,
        lpins,
        INPUT,
        PULL_ENABLE
    );
}