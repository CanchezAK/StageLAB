add_executable(zoner
         main.cpp
         )
pico_enable_stdio_usb(zoner 1)
pico_enable_stdio_uart(zoner 0)

 # Import pico_stdlib which imports commonly used features
 target_link_libraries(zoner pico_stdlib hardware_uart pico_binary_info hardware_gpio)

 # Create map/bin/hex file etc.
 pico_add_extra_outputs(zoner)

 # Add path via pico_set_program_url CMAKE
 example_auto_set_url(zoner)