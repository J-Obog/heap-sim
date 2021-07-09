cmake_minimum_required(VERSION 3.10)
project(Heapy VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(Heapy 
    src/main.cpp
    src/heap.cpp
    src/heap.hpp
)
