#ifndef LCD_H_
#define LCD_H_

typedef unsigned char  uint8_t;
typedef unsigned int   uint32_t;

// Direct Register Definitions (SysCtl, Port A, Port B)
#define SYSCTL_RCGCGPIO_R   (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_PRGPIO_R     (*((volatile uint32_t *)0x400FEA08))

#define GPIO_PORTA_DATA_R   (*((volatile uint32_t *)0x400043FC))
#define GPIO_PORTA_DIR_R    (*((volatile uint32_t *)0x40004400))
#define GPIO_PORTA_DEN_R    (*((volatile uint32_t *)0x4000451C))

#define GPIO_PORTB_DATA_R   (*((volatile uint32_t *)0x400053FC))
#define GPIO_PORTB_DIR_R    (*((volatile uint32_t *)0x40005400))
#define GPIO_PORTB_DEN_R    (*((volatile uint32_t *)0x4000551C))

class Lcd{
public:
    // Pin masks defined without enum
    static const uint8_t RS_PIN = (1U << 2); // PA2
    static const uint8_t EN_PIN = (1U << 3); // PA3

    Lcd();
    void init();
    void command(uint8_t cmd);
    void writeChar(char ch);
    void writeString(const char* str);
    void setCursor(uint8_t row, uint8_t col);
    void clear();

private:
    void sendNibble(uint8_t nibble);
    void pulseEnable();
    static void delayMs(uint32_t ms);
};

#endif