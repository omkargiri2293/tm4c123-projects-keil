#ifndef LED_H
#define LED_H

typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

class Led {
private:
    uint8_t pinMask;

public:
    // Pin bitmasks defined as class constants
    static const uint8_t RED   = (1U << 1); // PF1
    static const uint8_t BLUE  = (1U << 2); // PF2
    static const uint8_t GREEN = (1U << 3); // PF3

    // Constructor
    explicit Led(uint8_t pin);

    // Hardware setup member function
    void initPort();

    // LED control member functions
    void on();
    void off();
    void toggle();

    // Timing member function
    void delayMs(int ms);
};

#endif // LED_H