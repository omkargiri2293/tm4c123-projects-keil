#include "led_blink.h"

// TM4C123 Port F register pointers
static volatile uint32_t* const SYSCTL_RCGCGPIO = reinterpret_cast<volatile uint32_t*>(0x400FE608);
static volatile uint32_t* const GPIO_PORTF_DATA  = reinterpret_cast<volatile uint32_t*>(0x400253FC);
static volatile uint32_t* const GPIO_PORTF_DIR   = reinterpret_cast<volatile uint32_t*>(0x40025400);
static volatile uint32_t* const GPIO_PORTF_AFSEL = reinterpret_cast<volatile uint32_t*>(0x40025420);
static volatile uint32_t* const GPIO_PORTF_DEN   = reinterpret_cast<volatile uint32_t*>(0x4002551C);
static volatile uint32_t* const GPIO_PORTF_AMSEL = reinterpret_cast<volatile uint32_t*>(0x40025528);

// Constructor implementation
Led::Led(uint8_t pin) {
    this->pinMask = pin;
}

// Hardware initialization member function
void Led::initPort() {
    // 1. Enable Run-Mode clock gate for Port F (Bit 5)
    *SYSCTL_RCGCGPIO |= (1U << 5);

    // 2. Delay for clock stabilization
    volatile uint32_t delay = *SYSCTL_RCGCGPIO;
    (void)delay;

    // 3. Configure direction: set selected pin as output
    *GPIO_PORTF_DIR |= this->pinMask;

    // 4. Disable analog isolation
    *GPIO_PORTF_AMSEL &= ~this->pinMask;

    // 5. Clear alternate function (standard GPIO)
    *GPIO_PORTF_AFSEL &= ~this->pinMask;

    // 6. Enable digital buffer
    *GPIO_PORTF_DEN |= this->pinMask;

    // 7. Ensure pin starts low
    this->off();
}

// Turn LED ON
void Led::on() {
    *GPIO_PORTF_DATA |= this->pinMask;
}

// Turn LED OFF
void Led::off() {
    *GPIO_PORTF_DATA &= ~this->pinMask;
}

// Toggle LED state
void Led::toggle() {
    *GPIO_PORTF_DATA ^= this->pinMask;
}

// Delay member function (~1 ms per loop at default 16 MHz internal clock)
void Led::delayMs(int ms) {
    for (int i = 0; i < ms; ++i) {
        for (volatile int j = 0; j < 3180; ++j) {
            // NOP loop
        }
    }
}