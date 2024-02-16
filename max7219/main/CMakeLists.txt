add_executable(max7219
         main.c
         )
pico_enable_stdio_usb(max7219 1)
pico_enable_stdio_uart(max7219 0)

 # Import pico_stdlib which imports commonly used features
 add_subdirectory(led_lib)
 target_link_libraries(max7219 pico_stdlib hardware_spi pico_binary_info led_lib)

 # Create map/bin/hex file etc.
 pico_add_extra_outputs(max7219)

 # Add path via pico_set_program_url CMAKE
 example_auto_set_url(max7219)