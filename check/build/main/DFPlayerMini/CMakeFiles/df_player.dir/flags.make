# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

# compile ASM with C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/gcc-arm-none-eabi/bin/arm-none-eabi-gcc.exe
# compile C with C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/gcc-arm-none-eabi/bin/arm-none-eabi-gcc.exe
# compile CXX with C:/Program Files/Raspberry Pi/Pico SDK v1.5.1/gcc-arm-none-eabi/bin/arm-none-eabi-g++.exe
ASM_DEFINES = -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_USE_BLOCKED_RAM=0

ASM_INCLUDES = -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA7843~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_B~1\include -IC:\Users\admin\Documents\rp2040\check\build\generated\pico_base -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\boards\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_P~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\rp2040\HARDWA~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HARDWA~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\rp2040\HARDWA~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HARDWA~3\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA2A15~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA268C~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA5FF7~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_S~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_T~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA775E~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_U~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_S~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HAE181~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA2362~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HARDWA~4\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HAA248~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA3ACB~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA33F0~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA78F3~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA23F6~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_R~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_P~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_B~3\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_D~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_D~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_F~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_M~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_B~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_B~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_S~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_S~4\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_I~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_M~3\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\BOOT_S~1\include

ASM_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -ffunction-sections -fdata-sections

C_DEFINES = -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_USE_BLOCKED_RAM=0

C_INCLUDES = -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA7843~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_B~1\include -IC:\Users\admin\Documents\rp2040\check\build\generated\pico_base -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\boards\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_P~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\rp2040\HARDWA~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HARDWA~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\rp2040\HARDWA~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HARDWA~3\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA2A15~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA268C~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA5FF7~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_S~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_T~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA775E~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_U~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_S~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HAE181~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA2362~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HARDWA~4\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HAA248~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA3ACB~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA33F0~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA78F3~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA23F6~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_R~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_P~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_B~3\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_D~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_D~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_F~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_M~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_B~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_B~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_S~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_S~4\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_I~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_M~3\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\BOOT_S~1\include

C_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -ffunction-sections -fdata-sections -std=gnu11

CXX_DEFINES = -DLIB_PICO_BIT_OPS=1 -DLIB_PICO_BIT_OPS_PICO=1 -DLIB_PICO_DIVIDER=1 -DLIB_PICO_DIVIDER_HARDWARE=1 -DLIB_PICO_DOUBLE=1 -DLIB_PICO_DOUBLE_PICO=1 -DLIB_PICO_FLOAT=1 -DLIB_PICO_FLOAT_PICO=1 -DLIB_PICO_INT64_OPS=1 -DLIB_PICO_INT64_OPS_PICO=1 -DLIB_PICO_MALLOC=1 -DLIB_PICO_MEM_OPS=1 -DLIB_PICO_MEM_OPS_PICO=1 -DLIB_PICO_PLATFORM=1 -DLIB_PICO_PRINTF=1 -DLIB_PICO_PRINTF_PICO=1 -DLIB_PICO_RUNTIME=1 -DLIB_PICO_STANDARD_LINK=1 -DLIB_PICO_STDIO=1 -DLIB_PICO_STDIO_UART=1 -DLIB_PICO_STDLIB=1 -DLIB_PICO_SYNC=1 -DLIB_PICO_SYNC_CRITICAL_SECTION=1 -DLIB_PICO_SYNC_MUTEX=1 -DLIB_PICO_SYNC_SEM=1 -DLIB_PICO_TIME=1 -DLIB_PICO_UTIL=1 -DPICO_BOARD=\"pico\" -DPICO_BUILD=1 -DPICO_CMAKE_BUILD_TYPE=\"Release\" -DPICO_COPY_TO_RAM=0 -DPICO_CXX_ENABLE_EXCEPTIONS=0 -DPICO_NO_FLASH=0 -DPICO_NO_HARDWARE=0 -DPICO_ON_DEVICE=1 -DPICO_USE_BLOCKED_RAM=0

CXX_INCLUDES = -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA7843~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_B~1\include -IC:\Users\admin\Documents\rp2040\check\build\generated\pico_base -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\boards\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_P~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\rp2040\HARDWA~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HARDWA~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\rp2040\HARDWA~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HARDWA~3\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA2A15~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA268C~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA5FF7~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_S~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_T~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA775E~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_U~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_S~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HAE181~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA2362~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HARDWA~4\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HAA248~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA3ACB~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA33F0~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA78F3~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\HA23F6~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_R~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_P~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_B~3\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_D~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_D~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_F~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_M~1\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_B~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\common\PICO_B~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_S~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_S~4\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_I~2\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\PICO_M~3\include -IC:\PROGRA~1\RASPBE~1\PICOSD~1.1\pico-sdk\src\RP2_CO~1\BOOT_S~1\include

CXX_FLAGS = -mcpu=cortex-m0plus -mthumb -O3 -DNDEBUG -ffunction-sections -fdata-sections -fno-exceptions -fno-unwind-tables -fno-rtti -fno-use-cxa-atexit -std=gnu++17

