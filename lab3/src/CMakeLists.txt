cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED ON)

project(utils VERSION 1.0.0)

add_library(utils_lib STATIC ${SOURCE_LIB} utils.c)
add_executable(utils_exe main.c ${SOURCE_EXE})

target_link_libraries(utils_exe utils_lib)
