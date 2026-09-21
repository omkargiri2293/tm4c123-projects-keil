#ifndef LED_HPP
#define LED_HPP

#include <cstdint>

// Hardware register definitions using C++ reinterpret_cast
#define SYSCTL_RCGCGPIO_R   (*(reinterpret_cast<volatile uint32_t *>(0x400FE608)))
#define GPIO_PORTF_DIR_R    (*(reinterpret_cast<volatile uint32_t *>(0x40025400)))
#define GPIO_PORTF_DEN_R    (*(reinterpret_cast<volatile uint32_t *>(0x4002551C)))
#define GPIO_PORTF_DATA_R   (*(reinterpret_cast<volatile uint32_t *>(0x400253FC)))

class Led {
private:
    uint32_t pinNumber;

public:
    // Pin constant helpers
    static constexpr uint32_t RED   = 0x02U; // PF1
    static constexpr uint32_t BLUE  = 0x04U; // PF2
    static constexpr uint32_t GREEN = 0x08U; // PF3

    // Constructor declaration
    explicit Led(uint32_t pin);

    // Member function declarations
    void init();
    void turnOn();
    void turnOff();
    void toggle();
};

#endif // LED_HPP