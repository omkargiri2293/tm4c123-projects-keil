#include "rgb.h"

RgbLed::RgbLed() {}

void RgbLed::delayMs(uint32_t ms) {
    volatile uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 3180; j++) {
            // Software loop burning cycles (~1 ms at 16 MHz default PIOSC)
        }
    }
}

void RgbLed::init() {
    // 1. Enable Clock for Port F (bit 5)
    SYSCTL_RCGCGPIO_R |= (1U << 5);

    // 2. Wait until Port F clock is stable
    while ((SYSCTL_PRGPIO_R & (1U << 5)) == 0) {}

    // 3. Set PF1, PF2, PF3 as digital outputs
    GPIO_PORTF_DIR_R |= RGB_PINS_MASK;

    // 4. Enable digital functionality
    GPIO_PORTF_DEN_R |= RGB_PINS_MASK;

    // 5. Turn off all LEDs initially
    turnOff();
}

void RgbLed::setColor(uint8_t colorMask) {
    // Clear only PF1-PF3 and apply the new color bits
    GPIO_PORTF_DATA_R = (GPIO_PORTF_DATA_R & ~RGB_PINS_MASK) | (colorMask & RGB_PINS_MASK);
}

void RgbLed::turnOff() {
    GPIO_PORTF_DATA_R &= ~RGB_PINS_MASK;
}