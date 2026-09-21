#include "led_blink.h"

int main() {
    // Instantiate red LED using class scope resolution
    Led redLed(Led::RED);
    redLed.initPort();

    // Instantiate blue LED
    Led blueLed(Led::BLUE);
    blueLed.initPort();

    while (1) {
        redLed.on();
        blueLed.off();
        redLed.delayMs(500);

        redLed.off();
        blueLed.on();
        blueLed.delayMs(500);
    }

    return 0;
}