#include "heap.hpp" 

int main() {
    HeapMem heap(512); 
    int ptr = heap.alloc(2); 

    heap.memset(ptr, 25644); 
    heap.dump(); 
    
    return 0; 
}