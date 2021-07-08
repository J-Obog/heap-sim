#include "heap.hpp"

HeapMem::HeapMem() {
    const int defaultSize = 1024; 
    _mem = new uint16_t[defaultSize]{0x0}; 
    _size = defaultSize; 
}

HeapMem::HeapMem(int size) {
    _mem = new uint16_t[size]{0x0}; 
    _size = size;
}

HeapMem::~HeapMem() {
    delete _mem; 
} 

int HeapMem::alloc(int size) {
    
}

int HeapMem::memget(int ptr) {

}

void HeapMem::dealloc(int ptr) {

}

void HeapMem::memset(int ptr, int val) {

}
