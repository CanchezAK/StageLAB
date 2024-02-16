add_executable(i2c_scan
         main.c
         )
pico_enable_stdio_usb(i2c_scan 1)
pico_enable_stdio_uart(i2c_scan 0)
 # Import pico_stdlib which imports commonly used features
 target_link_libraries(i2c_scan pico_stdlib pico_binary_info hardware_gpio hardware_irq hardware_i2c)

 # Create map/bin/hex file etc.
 pico_add_extra_outputs(i2c_scan)

 # Add path via pico_set_program_url CMAKE
 example_auto_set_url(i2c_scan)