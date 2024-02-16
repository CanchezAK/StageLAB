#include "scan_kbd.h"
struct KBD_Config read;

uint8_t current_reg[1] = {INT_STAT_REG};

void keypad_interrupt()
{
    X:
    read.available = 1;
    
    uint8_t key = KBD_ReadKeypad();
            uint8_t intstat = 0;
            uint8_t intstat_write[2] = {INT_STAT_REG, 0x01};
            i2c_write_blocking(i2c1, KBD_ADDR, intstat_write, 2, false);
            i2c_read_blocking(i2c1, KBD_ADDR, &intstat, 1, false);
            printf("KEA: %x\t", read.KEY_EVENT_A);
            printf("INTSTAT: %x", intstat);
            if ((intstat & 0x01) == 0)
            {
                read.available = 0;
            }
            read.KEY_EVENT_A &= 0x7F;
            read.KEY_EVENT_A--;
            if (key)
            {
                printf("press\t R: ");
                if (SCENE_QUESTION)
                {
                    read.is_pressed_time_start = get_absolute_time();
                    read.is_pressed = 1;
                    asm("nop");
                }
                asm("nop");
            }
            else
            {
                printf("release\t R: ");
                if (SCENE_QUESTION)
                {
                    read.is_pressed_time_stop = get_absolute_time();
                    read.is_pressed_time_stop._private_us_since_boot = to_us_since_boot(read.is_pressed_time_stop) - to_us_since_boot(read.is_pressed_time_start);
                    //read.is_pressed_time_stop = read.is_pressed_time_stop - read.is_pressed_time_start;
                    //uint64_t is_pressed_time_stop = to_us_since_boot(read.is_pressed_time_stop) - to_us_since_boot(read.is_pressed_time_start);
                    //read.is_pressed_time_stop._private_us_since_boot = is_pressed_time_stop;
                    read.is_pressed = 0;
                    if (read.is_pressed_time_stop._private_us_since_boot / MILLION >= 3)
                    {
                        if (read.KEY_EVENT_A % 10 == 5)
                        {
                            read.is_pressed_scene0 = 1;
                        }
                        else if (read.KEY_EVENT_A % 10 == 1)
                        {
                            if (read.is_pressed_scene1 == 1)
                            {
                                read.is_pressed_scene1 = 0;
                            }
                            else read.is_pressed_scene1 = 1;
                        }
                        else if (read.KEY_EVENT_A % 10 == 2)
                        {
                            read.is_pressed_scene2 = 1;
                        }
                        else if (read.KEY_EVENT_A % 10 == 3)
                        {
                            read.is_pressed_scene3 = 1;
                        }
                    }
                    asm("nop");
                }
                asm("nop");
            }
            printf("%d\tC: ", read.KEY_EVENT_A / 10);
            printf("%d", read.KEY_EVENT_A % 10);
            printf("Pressed time: %d\r\n\r\n\r\n", (uint32_t)read.is_pressed_time_stop._private_us_since_boot);
            KBD_ReadKeypad();
            i2c_write_blocking(i2c1, KBD_ADDR, intstat_write, 2, false);
            i2c_read_blocking(i2c1, KBD_ADDR, &intstat, 1, false);
            if (read.KEY_EVENT_A != 0 || intstat != 0)
            {
                goto X;
            }
}

unsigned char KBD_flush()
{
    current_reg[0] = KEY_EVENT_A_REG;
    if (i2c_write_blocking(i2c1, KBD_ADDR, current_reg, 1, false) == PICO_ERROR_GENERIC) return KEY_EVENT_A_REG;
    i2c_read_blocking(i2c1, KBD_ADDR, &read.KEY_EVENT_A, 1, false);
    uint8_t count = 0;
    while(read.KEY_EVENT_A != 0)
    {
        if (i2c_write_blocking(i2c1, KBD_ADDR, current_reg, 1, false) == PICO_ERROR_GENERIC) return KEY_EVENT_A_REG;
        i2c_read_blocking(i2c1, KBD_ADDR, &read.KEY_EVENT_A, 1, false);
        uint8_t buff[2] = {0};
        count++;
        current_reg[0] = GPIO_INT_STAT1_REG;
        i2c_write_blocking(i2c1, KBD_ADDR, current_reg, 1, false);
        i2c_read_blocking(i2c1, KBD_ADDR, &buff[0], 1, false);
        current_reg[0] = GPIO_INT_STAT2_REG;
        i2c_write_blocking(i2c1, KBD_ADDR, current_reg, 1, false);
        i2c_read_blocking(i2c1, KBD_ADDR, &buff[0], 1, false);
        current_reg[0] = GPIO_INT_STAT3_REG;
        i2c_write_blocking(i2c1, KBD_ADDR, current_reg, 1, false);
        i2c_read_blocking(i2c1, KBD_ADDR, &buff[0], 1, false);
        buff[0] = INT_STAT_REG;
        buff[1] = 3;
        i2c_write_blocking(i2c1, KBD_ADDR, buff, 2, false);
    }
    return count;
}

void KBD_Debug()
{
    uint8_t key = KBD_ReadKeypad();
    uint8_t intstat = 0;
    uint8_t intstat_write[2] = {INT_STAT_REG, 0x01};
    i2c_write_blocking(i2c1, KBD_ADDR, intstat_write, 2, false);
    i2c_read_blocking(i2c1, KBD_ADDR, &intstat, 1, false);
}

unsigned char KBD_Init(struct KBD_Config config)
{
    uint8_t cfg[2] = {GPIO_DIR1_REG, 0x00};
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPIO_DIR1_REG;
    cfg[0] = GPIO_DIR2_REG;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPIO_DIR2_REG;
    cfg[0] = GPIO_DIR3_REG;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPIO_DIR3_REG;
    cfg[0] = GPI_EM1_REG;
    cfg[1] = 0xFF;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPI_EM1_REG;
    cfg[0] = GPI_EM2_REG;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPI_EM2_REG;
    cfg[0] = GPI_EM3_REG;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPI_EM3_REG;
    cfg[0] = GPIO_INT_LVL1_REG;
    cfg[1] = 0x00;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPIO_INT_LVL1_REG;
    cfg[0] = GPIO_INT_LVL2_REG;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPIO_INT_LVL2_REG;
    cfg[0] = GPIO_INT_LVL3_REG;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPIO_INT_LVL3_REG;
    cfg[0] = GPIO_INT_EN1_REG;
    cfg[1] = 0xFF;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPIO_INT_EN1_REG;
    cfg[0] = GPIO_INT_EN2_REG;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPIO_INT_EN2_REG;
    cfg[0] = GPIO_INT_EN3_REG;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return GPIO_INT_EN3_REG;
    

    cfg[0] = KP_GPIO1_REG;
    cfg[1] = config.KP_GPIO1;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return KP_GPIO1_REG;
    cfg[0] = KP_GPIO2_REG;
    cfg[1] = config.KP_GPIO2;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return KP_GPIO2_REG;
    cfg[0] = KP_GPIO3_REG;
    cfg[1] = config.KP_GPIO3;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return KP_GPIO3_REG;
    gpio_init(INT_PIN);
    gpio_set_dir(INT_PIN, GPIO_IN);
    gpio_set_irq_enabled_with_callback(INT_PIN, GPIO_IRQ_EDGE_FALL, true, &keypad_interrupt);
    cfg[0] = CFG_REG;
    cfg[1] = config.CFG;
    read = config;
    if (i2c_write_blocking(i2c1, KBD_ADDR, cfg, 2, false) == PICO_ERROR_GENERIC) return CFG_REG;
    KBD_flush();
    return 0;
}

void KBD_ClearISRflags()
{
    uint8_t buff[2] = {INT_STAT_REG, 0x0F};
    i2c_write_blocking(i2c1, KBD_ADDR, buff, 2, false);
}

unsigned char KBD_ReadKeypad()
{
    current_reg[0] = KEY_EVENT_A_REG;
    i2c_write_blocking(i2c1, KBD_ADDR, current_reg, 1, false);
    i2c_read_blocking(i2c1, KBD_ADDR, &read.KEY_EVENT_A, 1, false);
    //read.KEY_EVENT_A = buff;
    /*printf("K_E_A: %x, %x\r\n", read.KEY_EVENT_A, buff);
    printf("Config.CFG: %x\r\n", read.CFG);
    printf("Config.KP_GPIO1: %x\r\n", read.KP_GPIO1);
    printf("Config.KP_GPIO2: %x\r\n", read.KP_GPIO2);
    printf("Config.KP_GPIO3: %x\r\n", read.KP_GPIO3);*/
    return read.KEY_EVENT_A & 0x80;
}