#define UART_ID uart0
#define BAUD_RATE 115200
#define UART_TX_PIN 0
#define UART_RX_PIN 1

#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/gpio.h"
#include "hardware/uart.h"
#include "pico/binary_info.h"

uint32_t zoner_command[3] = {0xB3217B00, 0xA6000100, 0x00000000};
uint8_t transmit_buffer[12];

void channel_config(uint8_t out, uint8_t in, uint8_t en)
{
    zoner_command[0] |= ((0x7B + out + in + en) << 8);
    zoner_command[2] |= (in << 24) | (out << 16) | (en << 8);
}

void zoner_tx(uint32_t* data)
{
    for (uint8_t i = 0; i < 3; i++)
    {
        transmit_buffer[(i * 4)] = (data[i] >> 24 & 0xFF);
        transmit_buffer[(i * 4) + 1] = (data[i] >> 16 & 0xFF);
        transmit_buffer[(i * 4) + 2] = (data[i] >> 8 & 0xFF);
        transmit_buffer[(i * 4) + 3] = (data[i] & 0xFF);
    }
    uart_write_blocking(UART_ID, transmit_buffer, 12);
}

int main()
 {
    stdio_init_all();
    printf("Power ON");
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    while (1)
    {
        
        channel_config(0x01, 0x02, 0x01);
        zoner_tx(zoner_command);
        sleep_ms(1000);
        printf("RP2040");
    }
    return 0;
 }