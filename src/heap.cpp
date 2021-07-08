#include "heap.hpp"

HeapMem::HeapMem() {
    const int defaultSize = 1024; 
    _mem = new Word[defaultSize]{0}; 
    _size = defaultSize; 
}

HeapMem::HeapMem(int size) {
    _mem = new Word[size]{0}; 
    _size = size;
}

HeapMem::~HeapMem() {
    delete _mem; 
} 

int HeapMem::find(int size) {
    int run = 0;

    for(int i = 0; i < _size; i++) {
        if(run == size) {
            return i - (size - 1); 
        }
        run = (_mem[i].f == 0) ? run + 1 : 0; 
    }

    return -1;  
}

int HeapMem::alloc(int size) {
    int ptr = find(size); 
    if(ptr == -1) {
        return -12345; //bad memory allocation
    } else {
        return 1; 
    }
}

int HeapMem::memget(int ptr) {

}

void HeapMem::dealloc(int ptr) {

}

void HeapMem::memset(int ptr, int val) {

}
