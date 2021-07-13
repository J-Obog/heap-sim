#include <heap.hpp>

int main(int argc, char** argv) {
    HeapMem hp(394);
    int p1 = hp.alloc(sizeof(int));
    int p2 = hp.alloc(sizeof(int));
    int p3 = hp.alloc(sizeof(int));
    int p4 = hp.alloc(sizeof(bool));
    
    hp.memset(p1, 295190);
    hp.memset(p2, 162089);
    hp.memset(p3, 623303);
    hp.memset(p4, 1);

    hp.dump();  

    return 0; 
}