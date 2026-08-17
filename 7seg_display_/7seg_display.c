//

#include "seven_seg.h"

int main(void)
{
    uint8_t count = 0;

    sevenseg_init();

    while(1)
    {
        sevenseg_display(count);

        if(GPIO_Read_Pin(GPIO_PORTF_BASE, UP_BUTTON) == 0)
        {
            delay(20);

            if(GPIO_Read_Pin(GPIO_PORTF_BASE, UP_BUTTON) == 0)
            {
                count++;

                if(count > 9)
                {
                    count = 0;
                }

                while(GPIO_Read_Pin(GPIO_PORTF_BASE, UP_BUTTON) == 0);
            }
        }

        if(GPIO_Read_Pin(GPIO_PORTF_BASE, DOWN_BUTTON) == 0)
        {
            delay(20);

            if(GPIO_Read_Pin(GPIO_PORTF_BASE, DOWN_BUTTON) == 0)
            {
                if(count == 0)
                {
                    count = 9;
                }
                else
                {
                    count--;
                }

                while(GPIO_Read_Pin(GPIO_PORTF_BASE, DOWN_BUTTON) == 0);
            }
        }
    }
}