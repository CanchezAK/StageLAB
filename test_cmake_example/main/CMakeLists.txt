add_executable(cmake_example
         main.c
         )
pico_enable_stdio_usb(cmake_example 1)
pico_enable_stdio_uart(cmake_example 0)

#pico_generate_pio_header(zoner_full ${CMAKE_CURRENT_LIST_DIR}/uart_pio.pio)

add_subdirectory(KBD)
 # Import pico_stdlib which imports commonly used features
 target_link_libraries(cmake_example pico_stdlib pico_binary_info hardware_i2c kbd)

 # Create map/bin/hex file etc.
 pico_add_extra_outputs(cmake_example)

 # Add path via pico_set_program_url CMAKE
 example_auto_set_url(cmake_example)