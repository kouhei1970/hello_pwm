cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(hello_pwm C CXX ASM)
set(CMAKE_C_STNDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()


add_executable(hello_pwm
        hello_pwm.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(hello_pwm pico_stdlib hardware_pwm)

# create map/bin/hex file etc.
pico_add_extra_outputs(hello_pwm)
