add_executable(kbd_scan
         main.c
         )
pico_enable_stdio_usb(kbd_scan 1)
pico_enable_stdio_uart(kbd_scan 0)
add_subdirectory(scan_kbd)
 # Import pico_stdlib which imports commonly used features
 target_link_libraries(kbd_scan pico_stdlib hardware_gpio hardware_irq hardware_i2c hardware_clocks scan_kbd)

 # Create map/bin/hex file etc.
 pico_add_extra_outputs(kbd_scan)

 # Add path via pico_set_program_url CMAKE
 example_auto_set_url(kbd_scan)