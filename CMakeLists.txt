cmake_minimum_required(VERSION 4.2)
project(winfetch C)

set(CMAKE_C_STANDARD 23)

add_executable(winfetch main.c
        src/winfetch.c
        src/winfetch.h
        src/moduls/cpu.c
        src/moduls/cpu.h
        src/lib.h
        src/moduls/ram.c
        src/moduls/ram.h
        src/moduls/gpu.c
        src/moduls/gpu.h
        src/ascii_icon.h
        src/moduls/PcInfo.h
        src/moduls/PcInfo.c
)
target_link_libraries(winfetch PRIVATE dxgi)