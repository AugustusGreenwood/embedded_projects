cmake_minimum_required(VERSION 3.28)
project(make_led_blink C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER "avr-gcc")

set(SOURCE_FILES
    make_led_blink.c
)

include_directories(
    include/
    /usr/avr/include/
)

set(MCU "atmega2560" CACHE STRING "Architechure to compile for")
set(F_CPU "16000000L" CACHE STRING "I think this is the clock speed")
set(PORT "/dev/ttyACM0" CACHE FILEPATH "Port the programmer is on")
set(PROGRAMMER "arduino_as_isp" CACHE STRING "Type of programmer being used")
set(BAUD "19200" CACHE STRING "Baud rate")


# add compile options to be passed to avr-gcc for compilatio nand linking
set(CMAKE_EXE_LINKER_FLAGS -mmcu=${MCU})
set(CMAKE_EXECUTABLE_SUFFIX .elf)
add_compile_options(-mmcu=${MCU} -DF_CPU=${F_CPU} -Wextra -Wall -Os)

# Generate ELF file
add_executable(make_led_blink ${SOURCE_FILES})

# Generate HEX file from ELF
add_custom_command(TARGET make_led_blink POST_BUILD
    COMMAND avr-objcopy -O ihex -j .data -j .text ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating HEX file"
)

# Upload HEX file using avrdude (example)
add_custom_target(upload
    COMMAND avrdude -C /etc/avrdude.conf -v -V -p ${MCU} -c ${PROGRAMMER} -P ${PORT} -b ${BAUD} -U flash:w:${PROJECT_NAME}.hex:i
    DEPENDS make_led_blink
    COMMENT "Uploading HEX file using avrdude"
)

