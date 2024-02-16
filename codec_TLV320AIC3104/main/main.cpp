#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/i2c.h"

#define TLV320AI_ADDR 0x30

struct TLV320AI
{
    void i2c_initialize()
    {
        i2c_init(i2c1, 100 * 1000);
        gpio_set_function(2, GPIO_FUNC_I2C);
        gpio_set_function(3, GPIO_FUNC_I2C);
        gpio_pull_up(2);
        gpio_pull_up(3);
    }

    void TLV_init()
    {
        gpio_init(12);
        gpio_set_dir(12, GPIO_OUT);
        gpio_put(12, 0);
        sleep_ms(1000);
        gpio_put(12, 1);
        sleep_ms(10);
        gpio_put(12, 0);
        sleep_us(10);
        gpio_put(12, 1);
        i2c_initialize();
        set_reg(TLV320AI_ADDR, 0, 0, 0);
        set_reg(TLV320AI_ADDR, 0, 15, 0x30);
        set_reg(TLV320AI_ADDR, 0, 16, 0x30);
        set_reg(TLV320AI_ADDR, 0, 17, 0x08);
        set_reg(TLV320AI_ADDR, 0, 18, 0x88);
        set_reg(TLV320AI_ADDR, 0, 19, 0x04);
        set_reg(TLV320AI_ADDR, 0, 22, 0x04);
        set_reg(TLV320AI_ADDR, 0, 24, 0x80);
        set_reg(TLV320AI_ADDR, 0, 37, 0xC0);
        set_reg(TLV320AI_ADDR, 0, 81, 0x80);
        set_reg(TLV320AI_ADDR, 0, 86, 0x01);
        set_reg(TLV320AI_ADDR, 0, 91, 0x80);
        set_reg(TLV320AI_ADDR, 0, 93, 0x09);
        set_reg(TLV320AI_ADDR, 0, 101, 0x01);
    }

    void set_reg(uint8_t address, uint8_t page, uint8_t reg, uint8_t value)
    {
        uint8_t transmit_mass[2] = {reg, value};
        if (page == 0)
        {
            while (i2c_write_blocking(i2c1, address, transmit_mass, 0x02, false) != PICO_OK);
        }

        else
        {
            uint8_t page_mass[2] = {0x00, 0x01};
            while (i2c_write_blocking(i2c1, address, page_mass, 0x02, false) != PICO_OK);
            while (i2c_write_blocking(i2c1, address, transmit_mass, 0x02, false) != PICO_OK);
        }
    }
} TLV320;



int main()
{
    stdio_init_all();
    TLV320.TLV_init();
    TLV320.set_reg(TLV320AI_ADDR, 0, 1, 0x80);
    while(1)
    {

    }
    return 0;
}