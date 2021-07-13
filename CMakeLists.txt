cmake_minimum_required(VERSION 3.10)
project(heapsim VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TARGET_NAME heap_lib) 
option(BuildTests "Turn on for debugging purposes")

add_library(${TARGET_NAME}
    src/heap.cpp 
    src/heap.hpp
    src/termcolor.hpp
)
target_include_directories(${TARGET_NAME} PUBLIC src/)

add_executable(demo demo.cpp)
target_link_libraries(demo ${TARGET_NAME})

if(BuildTests)
    add_executable(tests 
        tests/test.cpp 
        tests/catch.hpp
    )
    target_link_libraries(tests ${TARGET_NAME})
endif()