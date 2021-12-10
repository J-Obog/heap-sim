#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <heap.hpp>

TEST_CASE("Set and get memory blocks") {
    HeapMem H(255);
    int p = H.alloc(sizeof(int));
    
    H.memset(p, 1346174);
    H.dealloc(p);

    REQUIRE(H.memget(p) == 1346174); 
}