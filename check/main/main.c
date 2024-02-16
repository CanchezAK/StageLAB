#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pio.h"
#include "uart_pio.pio.h"
#include "DFPlayerMini/df.h"

#define BAUD_RATE 9600
#define BUSY_PIN 10
#define UART_TX_PIN 0

extern uint8_t data[10];
extern char flag;
unsigned char once_play = 0;

void flag_callback(uint gpio, uint32_t events)
{
    if (events == 4)
    {
        flag = 1;
    }
    else if (events == 8)
    {
        flag = 0;
        stop();
    }
}

int main()
{
    stdio_init_all();
    printf("Das arbeit und cuplungen!");
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_init(BUSY_PIN);
    gpio_set_dir(BUSY_PIN, GPIO_IN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_pull_up(BUSY_PIN);
    gpio_set_irq_enabled_with_callback(BUSY_PIN, GPIO_IRQ_EDGE_FALL | GPIO_IRQ_EDGE_RISE, true, &flag_callback);
    PIO pio = pio0;
    uint sm = 0;
    uint offset = pio_add_program(pio, &uart_pio_program);
    uart_pio_program_init(pio, sm, offset, UART_TX_PIN, BAUD_RATE);
    sleep_ms(1000);
    set_volume(1);
    play_sound_immediatly(1);
    sleep_ms(500);
    while(1)
    {
        gpio_put(PICO_DEFAULT_LED_PIN, true);
        sleep_ms(250);
        gpio_put(PICO_DEFAULT_LED_PIN, false);
        sleep_ms(250);
    }
    return 0;
}

