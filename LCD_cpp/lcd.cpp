#include "lcd.h"

Lcd::Lcd() {}

void Lcd::delayMs(uint32_t ms) {
    volatile uint32_t i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 3180; j++) {
            // Software busy-wait delay (~1 ms at 16 MHz PIOSC)
        }
    }
}

void Lcd::pulseEnable() {
    GPIO_PORTA_DATA_R |= EN_PIN;   // Set EN HIGH
    delayMs(1);
    GPIO_PORTA_DATA_R &= ~EN_PIN;  // Falling edge: latches the nibble
    delayMs(2);
}

void Lcd::sendNibble(uint8_t nibble) {
    // Preserve PB0-PB3, clear PB4-PB7, place high nibble on data pins
    GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0x0F) | (nibble & 0xF0);
    pulseEnable();
}

void Lcd::command(uint8_t cmd) {
    GPIO_PORTA_DATA_R &= ~RS_PIN;  // RS = 0 (Instruction)
    sendNibble(cmd & 0xF0);         // Send upper 4 bits
    sendNibble((cmd << 4) & 0xF0);  // Send lower 4 bits
}

void Lcd::writeChar(char ch) {
    GPIO_PORTA_DATA_R |= RS_PIN;   // RS = 1 (Display Data)
    sendNibble(ch & 0xF0);          // Send upper 4 bits
    sendNibble((ch << 4) & 0xF0);   // Send lower 4 bits
}

void Lcd::writeString(const char* str) {
    while (*str) {
        writeChar(*str++);
    }
}

void Lcd::setCursor(uint8_t row, uint8_t col) {
    // Row 0 DDRAM starts at 0x80; Row 1 DDRAM starts at 0xC0
    uint8_t address = (row == 0) ? (0x80 + col) : (0xC0 + col);
    command(address);
}

void Lcd::clear() {
    command(0x01); // 0x01: Clear Display
    delayMs(2);    // Clear instruction takes ~1.52 ms
}

void Lcd::init() {
    // 1. Enable Clocks for Port A (Control) and Port B (Data)
    SYSCTL_RCGCGPIO_R |= (1U << 0) | (1U << 1);
    while ((SYSCTL_PRGPIO_R & ((1U << 0) | (1U << 1))) == 0) {}

    // 2. Configure PA2 (RS), PA3 (EN) as digital outputs
    GPIO_PORTA_DIR_R |= (RS_PIN | EN_PIN);
    GPIO_PORTA_DEN_R |= (RS_PIN | EN_PIN);

    // 3. Configure PB4-PB7 (D4-D7) as digital outputs
    GPIO_PORTB_DIR_R |= 0xF0;
    GPIO_PORTB_DEN_R |= 0xF0;

    delayMs(50); // Wait >40 ms for LCD internal reset circuitry

    // 4. Force HD44780 4-bit initialization sequence
    sendNibble(0x30);
    delayMs(5);
    sendNibble(0x30);
    delayMs(1);
    sendNibble(0x30);
    sendNibble(0x20); // Switch interface to 4-bit mode

    // 5. Initial setup commands
    command(0x28); // 4-bit, 2-line, 5x8 character dots
    command(0x0C); // Display ON, Cursor OFF
    command(0x06); // Auto-increment cursor position
    clear();
}