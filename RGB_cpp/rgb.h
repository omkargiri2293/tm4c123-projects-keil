#ifndef RGB_H_
#define RGB_H_

typedef unsigned char  uint8_t;
typedef unsigned int   uint32_t;

// Direct Hardware Register Mappings (Port F & System Control)
#define SYSCTL_RCGCGPIO_R   (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_PRGPIO_R     (*((volatile uint32_t *)0x400FEA08))

#define GPIO_PORTF_DATA_R   (*((volatile uint32_t *)0x400253FC))
#define GPIO_PORTF_DIR_R    (*((volatile uint32_t *)0x40025400))
#define GPIO_PORTF_DEN_R    (*((volatile uint32_t *)0x4002551C))

class RgbLed {
public:
    // Color bit masks using static const variables instead of enum
    static const uint8_t COLOR_OFF     = 0x00;
    static const uint8_t COLOR_RED     = (1U << 1);                  // PF1
    static const uint8_t COLOR_BLUE    = (1U << 2);                  // PF2
    static const uint8_t COLOR_GREEN   = (1U << 3);                  // PF3
    static const uint8_t COLOR_MAGENTA = ((1U << 1) | (1U << 2));    // Red + Blue
    static const uint8_t COLOR_YELLOW  = ((1U << 1) | (1U << 3));    // Red + Green
    static const uint8_t COLOR_CYAN    = ((1U << 2) | (1U << 3));    // Blue + Green
    static const uint8_t COLOR_WHITE   = ((1U << 1) | (1U << 2) | (1U << 3)); // All ON

    RgbLed();
    void init();
    void setColor(uint8_t colorMask);
    void turnOff();
    static void delayMs(uint32_t ms);

private:
    static const uint8_t RGB_PINS_MASK = ((1U << 1) | (1U << 2) | (1U << 3));
};

#endif