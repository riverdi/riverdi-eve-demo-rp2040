cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)
project(test_project C CXX ASM)

# do not edit!
add_definitions(-DLINUX_PLATFORM -DBUFFER_OPTIMIZATION)

# edit: choose eve platform
#add_definitions(-DEVE_1)
#add_definitions(-DEVE_2)
#add_definitions(-DEVE_3)
add_definitions(-DEVE_4)

# edit: choose clock source for eve4 platform
add_definitions(-DEVE_4_INTERNAL_OSC)
#add_definitions(-DEVE_4_EXTERNAL_OSC)

# edit: choose display type
#add_definitions(-DNTP_35)
#add_definitions(-DRTP_35)
#add_definitions(-DCTP_35)
#add_definitions(-DNTP_43)
#add_definitions(-DRTP_43)
#add_definitions(-DCTP_43)
#add_definitions(-DNTP_50)
#add_definitions(-DRTP_50)
#add_definitions(-DCTP_50)
#add_definitions(-DNTP_70)
#add_definitions(-DRTP_70)
#add_definitions(-DCTP_70)
#add_definitions(-DIPS_35)
#add_definitions(-DIPS_43)
#add_definitions(-DIPS_50)
#add_definitions(-DIPS_70)
add_definitions(-DIPS_101)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

set(sources
  riverdi-eve-lib/eve_layer/Gpu_Hal.c
  riverdi-eve-lib/eve_layer/CoPro_Cmds.c
  riverdi-eve-lib/eve_layer/Hal_Utils.c
  riverdi-eve-lib/app_layer/App_Common.c
  main/platform.c
  main/riverdi-demo.c
)

add_executable(riverdi-eve-demo-rp2040 ${sources})

pico_enable_stdio_usb(riverdi-eve-demo-rp2040 1)
pico_enable_stdio_uart(riverdi-eve-demo-rp2040 1)

pico_add_extra_outputs(riverdi-eve-demo-rp2040)

target_link_libraries(riverdi-eve-demo-rp2040 pico_stdlib hardware_spi)

include_directories(
  main/
  riverdi-eve-lib/riverdi_modules/
  riverdi-eve-lib/eve_layer/
  riverdi-eve-lib/app_layer/
)
