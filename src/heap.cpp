#include "heap.hpp"
#include <iostream>
#include <iomanip>

HeapMem::HeapMem() {
    const int default_size = 1024; 
    _mem = new Word[default_size]{{0,0,0,0}}; 
    _size = default_size; 
}

HeapMem::HeapMem(int size) {
    _mem = new Word[size]{{0,0,0,0}}; 
    _size = size;
}

HeapMem::~HeapMem() {
    delete _mem; 
} 

void HeapMem::_mem_reserve(int offset, int size) {
    for(int i = offset; i < offset + size; i++) {
        _mem[i].alloc = 1; 
        _mem[i].head = (i == offset) ? 1 : 0; 
        _mem[i].next = (i != offset + (size - 1)) ? 1 : 0; 
    }
}

int HeapMem::alloc(int size) {
    int run = 0;

    for(int i = 0; i < _size; i++) {
        if(run == size) {
            int ptr = i - size; 
            _mem_reserve(ptr, size);
            return ptr;
        }
        run = (!_mem[i].alloc) ? run + 1 : 0; 
    }

    return -1;
}

void HeapMem::dealloc(int ptr) {
    if(!_mem[ptr].head)
        return; 

    int tmp = ptr; 

    do {
        _mem[tmp] = {0}; 
    } while(_mem[tmp - 1].next != 0); 
}

int HeapMem::memget(int ptr) {
    return 0; 
}

void HeapMem::memset(int ptr, int val) {
    
}

void HeapMem::dump() {
    for(int i = 0; i < _size; i += 16) {    
        std::cout << std::setfill('0') << std::setw(4) << std::hex << std::uppercase << i << "  ";
        for(int j = 0; j < 16; j++) {
            std::cout << ' ' << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << (int)_mem[i+j].data;
        }
        std::cout << '\n'; 
     }
}