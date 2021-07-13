cmake_minimum_required(VERSION 3.10)
project(heapsim VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BuildTests "Turn on for debugging purposes")

add_library(heap_lib
    src/heap.cpp 
    src/heap.hpp
)

target_include_directories(heap_lib
  PUBLIC
  src/
)

add_executable(${PROJECT_NAME} example.cpp)
target_link_libraries(${PROJECT_NAME} heap_lib)

if(BuildTests)
    add_executable(tests 
        tests/test.cpp 
        tests/catch.hpp
    )
    target_link_libraries(tests heap_lib)
endif()