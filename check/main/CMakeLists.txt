add_executable(check
         main.c
         )
pico_enable_stdio_usb(check 1)
pico_enable_stdio_uart(check 0)

pico_generate_pio_header(check ${CMAKE_CURRENT_LIST_DIR}/uart_pio.pio)

add_subdirectory(DFPlayerMini)
 # Import pico_stdlib which imports commonly used features
 target_link_libraries(check pico_stdlib hardware_uart pico_binary_info hardware_gpio hardware_irq hardware_pio hardware_clocks hardware_dma df_player hardware_timer)

 # Create map/bin/hex file etc.
 pico_add_extra_outputs(check)

 # Add path via pico_set_program_url CMAKE
 example_auto_set_url(check)