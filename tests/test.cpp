#define CATCH_CONFIG_MAIN
#include "catch.hpp"

bool isOdd(int x) {
    return !(x % 2 == 0); 
}

TEST_CASE("Sample test case to check if number is odd") {
    int num = 5; 
    REQUIRE(isOdd(num) == true); 
}