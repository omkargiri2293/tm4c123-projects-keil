#include "switch.h"

int main() {
    Switch board;
    board.init();

    while (true) {
        // Pressing SW1 turns on RED LED
        if (board.isPressed(Switch::SW1)) {
            board.ledOn(Switch::LED_RED);
        } else {
            board.ledOff(Switch::LED_RED);
        }

        // Pressing SW2 turns on GREEN LED
        if (board.isPressed(Switch::SW2)) {
            board.ledOn(Switch::LED_GREEN);
        } else {
            board.ledOff(Switch::LED_GREEN);
        }
    }

    return 0;
}