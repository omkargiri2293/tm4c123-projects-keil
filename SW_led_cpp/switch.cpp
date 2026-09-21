#include "switch.h"
#include "tm4c123gh6pm.h"

Switch::Switch() {}

void Switch::delayMs(uint32_t ms) {
    volatile uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 3180; j++) {
            // Software busy-wait loop (~1 ms at 16 MHz)
        }
    }
}

void Switch::init() {
    // 1. Enable clock for Port F (bit 5)
    SYSCTL_RCGCGPIO_R |= (1U << 5);

    // 2. Wait until Port F clock is ready
    while ((SYSCTL_PRGPIO_R & (1U << 5)) == 0) {}

    // 3. Unlock PF0 (required because PF0 is locked by default as NMI)
    GPIO_PORTF_LOCK_R = 0x4C4F434B; // Passcode to unlock
    GPIO_PORTF_CR_R  |= (SW1 | SW2); // Commit register: allow changes to PF0, PF4

    // 4. Set Pin Directions:
    // LEDs (PF1, PF2, PF3) = Outputs (1)
    // Switches (PF0, PF4)   = Inputs (0)
    GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIO_PORTF_DIR_R &= ~(SW1 | SW2);

    // 5. Enable internal Pull-Up resistors for switches (Active-LOW buttons)
    GPIO_PORTF_PUR_R |= (SW1 | SW2);

    // 6. Enable Digital functionality for LEDs and Switches
    GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN | SW1 | SW2);

    // 7. Turn off LEDs initially
    GPIO_PORTF_DATA_R &= ~(LED_RED | LED_BLUE | LED_GREEN);
}

bool Switch::isPressed(Button btn) {
    // Active-Low: Pressed connects pin to GND (reads 0)
    if ((GPIO_PORTF_DATA_R & btn) == 0) {
        delayMs(20); // 20 ms software debounce
        if ((GPIO_PORTF_DATA_R & btn) == 0) {
            return true;
        }
    }
    return false;
}

void Switch::ledOn(LedColor color) {
    GPIO_PORTF_DATA_R |= color;
}

void Switch::ledOff(LedColor color) {
    GPIO_PORTF_DATA_R &= ~color;
}

void Switch::ledToggle(LedColor color) {
    GPIO_PORTF_DATA_R ^= color;
}