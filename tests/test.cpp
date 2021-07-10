#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "heap.hpp"

bool isOdd(int x) {
    return !(x % 2 == 0); 
}

//should pass
TEST_CASE("Sample test case to check if number is odd") {
    int num = 5; 
    REQUIRE(isOdd(num) == true); 
}

//should fail
TEST_CASE("Another Test case") {
    REQUIRE(1 == 3);
}