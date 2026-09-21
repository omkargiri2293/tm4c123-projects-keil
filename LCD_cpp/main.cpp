#include "lcd.h"

int main() {
    Lcd lcd;
    lcd.init();

    lcd.setCursor(0, 0);
    lcd.writeString("712639005");

    lcd.setCursor(1, 0);
    lcd.writeString("MIS_NO");

    while (true) {
        // Halt in loop
    }
}