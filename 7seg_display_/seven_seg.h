#ifndef SEVEN_SEG_H
#define SEVEN_SEG_H

#include <stdint.h>
#include "GPIO_lib.h"
/* 7-segment display pins: PB0-PB6 */
#define SEG_A    PIN0
#define SEG_B    PIN1
#define SEG_C    PIN2
#define SEG_D    PIN3
#define SEG_E    PIN4
#define SEG_F    PIN5
#define SEG_G    PIN6

#define SEG_PINS (PIN0 | PIN1 | PIN2 | PIN3 | \
                  PIN4 | PIN5 | PIN6)

/* Push buttons: PF0 and PF4 */
#define UP_BUTTON      PIN0
#define DOWN_BUTTON    PIN4

/* Function prototypes */
void sevenseg_init(void);

#endif