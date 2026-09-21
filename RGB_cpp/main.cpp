#include "rgb.h"

int main() {
    RgbLed rgb;
    rgb.init();

    while (true) {
        rgb.setColor(RgbLed::COLOR_RED);
        RgbLed::delayMs(1000);

        rgb.setColor(RgbLed::COLOR_GREEN);
        RgbLed::delayMs(1000);

        rgb.setColor(RgbLed::COLOR_BLUE);
        RgbLed::delayMs(1000);

        rgb.setColor(RgbLed::COLOR_YELLOW);
        RgbLed::delayMs(1000);

        rgb.setColor(RgbLed::COLOR_CYAN);
        RgbLed::delayMs(1000);

        rgb.setColor(RgbLed::COLOR_MAGENTA);
        RgbLed::delayMs(1000);

        rgb.setColor(RgbLed::COLOR_WHITE);
        RgbLed::delayMs(1000);

        rgb.turnOff();
        RgbLed::delayMs(1000);
    }
}