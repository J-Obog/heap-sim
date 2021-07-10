add_library(heap STATIC heap.cpp heap.hpp)
add_executable(demo main.cpp)
target_include_directories(heap PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
target_link_libraries(demo PUBLIC heap)