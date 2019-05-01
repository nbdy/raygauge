cmake_minimum_required(VERSION 3.10)
project(raygauge)

set(CMAKE_CXX_STANDARD 11)

if(EXISTS "/sys/firmware/devicetree/base/model")
    option(rpi "build for raspberry pi" ON)
    include_directories(
            /opt/vc/lib
            /opt/vc/include
            /opt/vc/include/interface/vmcs_host/linux
            /opt/vc/include/interface/vcos/pthreads
    )
    link_directories(
            /usr/local/lib
            /opt/vc/lib
    )
else()
    option(rpi "build for raspberry pi" OFF)
endif()

add_executable(raygauge
        main.cpp
        libs/Circle/Circle.cpp
        libs/Circle/Circle.h
        libs/Rectangle/Rectangle.cpp libs/Rectangle/Rectangle.h)

if(rpi)
    target_link_libraries(raygauge raylib dl pthread brclEGL rt bcm_host brcmGLESv2)
else()
    target_link_libraries(raygauge raylib pthread X11 dl)
endif()