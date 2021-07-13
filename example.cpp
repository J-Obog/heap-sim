#include "heap.hpp"

int main(int argc, char** argv) {
    HeapMem hp(64); 
    int p = hp.alloc(sizeof(char)); 
    hp.memset(p, 157); 
    hp.dump(); 

    return 0; 
}