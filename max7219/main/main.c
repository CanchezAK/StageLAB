#include "led_lib/led.h"
#include "pico/binary_info.h"

extern uint8_t coordxy[2];

int main() {
    stdio_init_all();
    LED_Init();

        coord(4, 5);
        put_pixel(coordxy);
        sleep_ms(500);
        coord(6,7);
        put_pixel(coordxy);
        sleep_ms(500);
        coord(6,5);
        put_pixel(coordxy);
        sleep_ms(1000);
        clear_display();

    int bright = 1;
    while (true) {
        for (uint8_t i = 1; i < 11; i++)
        {
            for (uint8_t j = 1; j < 11; j++)
            {
                coord(i, j);
                put_pixel(coordxy);
                sleep_ms(250);
            }
        }
        clear_display();
    }
}
