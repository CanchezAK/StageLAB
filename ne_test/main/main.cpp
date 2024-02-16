#define CE 6
#define MCLK_SEL 7
#define INT 10

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "hardware/gpio.h"

bool reserved_addr(uint8_t addr)
{
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

int main()
{
    stdio_init_all();
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, true);
    gpio_put(PICO_DEFAULT_LED_PIN, false);

    gpio_init(CE);
    gpio_init(MCLK_SEL);
    gpio_set_dir(CE, GPIO_OUT);
    gpio_set_dir(MCLK_SEL, GPIO_OUT);
    sleep_ms(250);
    i2c_init(i2c0, 100 * 1000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);   
    bi_decl(bi_2pins_with_func(4, 5, GPIO_FUNC_I2C));
    gpio_put(CE, true);
    printf("\nI2C Bus Scan\n");
    printf("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
    uint8_t soft_reset[2] = {0xC1, 0x01};
    i2c_write_blocking(i2c0, 0x4E, soft_reset, 2, false);
    soft_reset[0] = 0xC2;
    soft_reset[1] = 0x00;
    i2c_write_blocking(i2c0, 0x4E, soft_reset, 2, false);
    soft_reset[0] = 0x00;
    soft_reset[1] = 0x40;
    i2c_write_blocking(i2c0, 0x46, soft_reset, 2, false);
    while (1)
    {
        for (int addr = 0; addr < (1 << 7); ++addr) {
        if (addr % 16 == 0) {
            printf("%02x ", addr);
        }

        // Perform a 1-byte dummy read from the probe address. If a slave
        // acknowledges this address, the function returns the number of bytes
        // transferred. If the address byte is ignored, the function returns
        // -1.

        // Skip over any reserved addresses.
        int ret;
        uint8_t rxdata;
        if (reserved_addr(addr))
            ret = PICO_ERROR_GENERIC;
        else
            ret = i2c_read_blocking(i2c_default, addr, &rxdata, 1, false);

        printf(ret < 0 ? "." : "0x%02x", addr);
        printf(addr % 16 == 15 ? "\n" : "  ");
        }
        printf("Done.\n");

    }
    return 0;
}


/*
#include <stdio.h>
#include "pico/stdlib.h"
//#include "hardware/i2c.h"
//#include "pico/binary_info.h"
//#include "hardware/gpio.h"

bool reserved_addr(uint8_t addr)
{
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

int main() 
{
    stdio_init_all();
    printf("piroerg");*/
    /*gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, true);
    gpio_put(PICO_DEFAULT_LED_PIN, false);

    gpio_init(CE);
    gpio_init(MCLK_SEL);
    gpio_set_dir(CE, true);
    gpio_set_dir(MCLK_SEL, GPIO_OUT);
    gpio_put(6, false);
    i2c_init(i2c0, 100 * 1000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_pull_up(5);   
    bi_decl(bi_2pins_with_func(4, 5, GPIO_FUNC_I2C));

    printf("\nI2C Bus Scan\n");
    printf("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");

    for (int addr = 0; addr < (1 << 7); ++addr) {
        if (addr % 16 == 0) {
            printf("%02x ", addr);
        }

        // Perform a 1-byte dummy read from the probe address. If a slave
        // acknowledges this address, the function returns the number of bytes
        // transferred. If the address byte is ignored, the function returns
        // -1.

        // Skip over any reserved addresses.
        int ret;
        uint8_t rxdata;
        if (reserved_addr(addr))
            ret = PICO_ERROR_GENERIC;
        else
            ret = i2c_read_blocking(i2c_default, addr, &rxdata, 1, false);

        printf(ret < 0 ? "." : "@");
        printf(addr % 16 == 15 ? "\n" : "  ");
    }
    printf("Done.\n");*/
    /*

    static uint8_t status = 0;
    uint8_t reset_status = DeviceInit(DEV_ADDR_ADC0, adc_data_mass, 2);
    status |= (reset_status << 0);
    reset_status = DeviceInit(DEV_ADDR_ADC1, adc_data_mass, 2);
    status |= (reset_status << 1);
    reset_status = DeviceInit(DEV_ADDR_ADC2, adc_data_mass, 2);
    status |= (reset_status << 2);
    reset_status = DeviceInit(DEV_ADDR_ADC3, adc_data_mass, 2);
    status |= (reset_status << 3);
    reset_status = DeviceInit(DEV_ADDR_DAC, dac_data_mass, 2);
    status |= (reset_status << 4);
    dac_data_mass[0] = 0x03;
    reset_status = DeviceInit(DEV_ADDR_DAC, dac_data_mass, 2);
    status |= (reset_status << 5);
    printf("%02x", status);
            printf("\r\n");
        while(1)
        {
            switch (status)
            {
            case 0b00000001:
                printf("Error %02x, ADC0 started, but any other device not", status);
                gpio_put(PICO_DEFAULT_LED_PIN, true);
                sleep_ms(75);
                gpio_put(PICO_DEFAULT_LED_PIN, false);
                sleep_ms(75);
                break;
            case 0b00000011:
                printf("Error %02x, ADC0 & ADC1 started, but any other device not", status);
                gpio_put(PICO_DEFAULT_LED_PIN, true);
                sleep_ms(125);
                gpio_put(PICO_DEFAULT_LED_PIN, false);
                sleep_ms(125);
                break;
            case 0b00000111:
                printf("Error %02x, ADC0 & ADC1 & ADC2 started, but any other device not", status);
                gpio_put(PICO_DEFAULT_LED_PIN, true);
                sleep_ms(250);
                gpio_put(PICO_DEFAULT_LED_PIN, false);
                sleep_ms(250);
                break;
            case 0b00001111:
                printf("Error %02x, ADC0 & ADC1 & ADC2 & ADC3 started, but any other device not", status);
                gpio_put(PICO_DEFAULT_LED_PIN, true);
                sleep_ms(500);
                gpio_put(PICO_DEFAULT_LED_PIN, false);
                sleep_ms(500);
                break;
            case 0b00011111:
                printf("Error %02x, ADC0 & ADC1 & ADC2 & ADC3 started, but DAC answer only reg 0x02", status);
                gpio_put(PICO_DEFAULT_LED_PIN, true);
                sleep_ms(1000);
                gpio_put(PICO_DEFAULT_LED_PIN, false);
                sleep_ms(1000);
                break;
            case 0b00111111:
                printf("Starting complete!");
                gpio_put(PICO_DEFAULT_LED_PIN, true);
                sleep_ms (1000);
                break;
            case 0b00110011:
                printf("ADC0 & ADC1 & DAC0 started, ADC2 & ADC3 not");
                gpio_put(PICO_DEFAULT_LED_PIN, true);
                sleep_ms (2500);
                gpio_put(PICO_DEFAULT_LED_PIN, false);
                sleep_ms (2500);
                break;
            
            default:
                printf("Error %02x, didn't init 0x3F - error device(s) in binary translation", status);
                sleep_ms (1000);
                break;
            }
        }
        return 0;
}*/