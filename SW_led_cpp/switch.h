#ifndef SWITCH_H_
#define SWITCH_H_

typedef unsigned char  uint8_t;
typedef unsigned int   uint32_t;

// Direct Hardware Register Definitions for TM4C123GH6PM (Port F & SysCtl)
#define SYSCTL_RCGCGPIO_R   (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_PRGPIO_R     (*((volatile uint32_t *)0x400FEA08))

#define GPIO_PORTF_DATA_R   (*((volatile uint32_t *)0x400253FC))
#define GPIO_PORTF_DIR_R    (*((volatile uint32_t *)0x40025400))
#define GPIO_PORTF_PUR_R    (*((volatile uint32_t *)0x40025510))
#define GPIO_PORTF_DEN_R    (*((volatile uint32_t *)0x4002551C))
#define GPIO_PORTF_LOCK_R   (*((volatile uint32_t *)0x40025520))
#define GPIO_PORTF_CR_R     (*((volatile uint32_t *)0x40025524))

class Switch {
public:
    enum Button {
        SW1 = (1U << 4), // PF4
        SW2 = (1U << 0)  // PF0
    };

    enum LedColor {
        LED_RED   = (1U << 1), // PF1
        LED_BLUE  = (1U << 2), // PF2
        LED_GREEN = (1U << 3)  // PF3
    };

    Switch();
    void init();
    bool isPressed(Button btn);
    void ledOn(LedColor color);
    void ledOff(LedColor color);
    void ledToggle(LedColor color);

private:
    static void delayMs(uint32_t ms);
};

#endif