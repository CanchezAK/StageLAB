#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/i2c.h"
#include "pico/binary_info.h"

bool reserved_addr(uint8_t addr) {
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}
uint8_t flag = 0;
int main(void)
{
    stdio_init_all();
    
    i2c_init(i2c1, 100 * 1000);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);   
    while (flag == 0)
    {
        for (uint8_t i = 0; i < 8; i++)
        {
            printf("I'm alive!\r\n");
            sleep_ms(500);
        }
        flag = 1;
    }
    //bi_decl(bi_2pins_with_func(4, 9, GPIO_FUNC_I2C));
    printf("\nI2C Bus Scan\n");
    printf("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
    while(1)
    {
        for (int addr = 0; addr < (1 << 7); ++addr) {
            if (addr % 16 == 0) {
                printf("%02x ", addr);
            }
            int ret;
            uint8_t rxdata;
            if (reserved_addr(addr))
                ret = PICO_ERROR_GENERIC;
            else
                ret = i2c_read_blocking(i2c1, addr, &rxdata, 1, false);
                printf(ret < 0 ? "." : "%02x", addr);
                printf(addr % 16 == 15 ? "\n" : "  ");
        }
        printf("Done.\n");
    }
    return 0;
}