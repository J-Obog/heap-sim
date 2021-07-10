cmake_minimum_required(VERSION 3.10)
project(Heapy VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_TEST_TARGETS "Set to true for debugging purposes")

add_subdirectory(src)

if(BUILD_TEST_TARGETS)
    enable_testing()
    add_subdirectory(tests)
endif()