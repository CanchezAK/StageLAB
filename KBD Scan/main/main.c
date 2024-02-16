#include "scan_kbd/scan_kbd.h"
#include "hardware/clocks.h"
#define NDEBUG
extern struct KBD_Config read;

int main(void)
{
    stdio_init_all();
    struct KBD_Config config;
    i2c_init(i2c1, 100 * 1000);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);
    config.CFG |= GPI_IEN | KE_IEN;
    config.KP_GPIO1 |= ROW0 | ROW1 | ROW2 | ROW3 | ROW4;
    config.KP_GPIO2 |= COL0 | COL1 | COL2 | COL3;
    config.KP_GPIO3 = 0;
    uint8_t answer = KBD_Init(config);
    //read.is_pressed_time_start = 0;
    //read.is_pressed_time_stop = 0;
    while(1)
    {
        printf("Is pressed scene 0 %01x", read.is_pressed_scene0);
        printf("Is pressed scene 1 %01x", read.is_pressed_scene1);
        printf("Is pressed scene 2 %01x", read.is_pressed_scene2);
        printf("Is pressed scene 3 %01x", read.is_pressed_scene3);
        sleep_ms(500);
    }
    return 0;
}