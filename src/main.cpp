#include "heap.hpp" 

int main() {
    HeapMem heap(16); 
    int ptr = heap.alloc(4); 
    heap.dealloc(ptr); 

    heap.dump(); 

    return 0; 
}