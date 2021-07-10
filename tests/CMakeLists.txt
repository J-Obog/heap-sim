add_executable(tests test.cpp catch.hpp)
target_link_libraries(tests PUBLIC heap)
add_test(tester tests)