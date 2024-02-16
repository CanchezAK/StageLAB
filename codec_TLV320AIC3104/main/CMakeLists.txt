add_executable(codec
         main.cpp
         )
pico_enable_stdio_usb(codec 1)
pico_enable_stdio_uart(codec 0)

#pico_generate_pio_header(zoner_full ${CMAKE_CURRENT_LIST_DIR}/uart_pio.pio)

#add_subdirectory(KBD)
 # Import pico_stdlib which imports commonly used features
 target_link_libraries(codec pico_stdlib pico_binary_info hardware_i2c)

 # Create map/bin/hex file etc.
 pico_add_extra_outputs(codec)

 # Add path via pico_set_program_url CMAKE
 example_auto_set_url(codec)