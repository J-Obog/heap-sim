#include "heap.hpp"
#include <iostream>
#include <iomanip>

HeapMem::HeapMem() {
    const int defaultSize = 1024; 
    _mem = new Word[defaultSize]; 
    _size = defaultSize; 

    for(int i = 0; i < _size; i++) {
        _mem[i] = {0}; 
    }
}

HeapMem::HeapMem(int size) {
    _mem = new Word[size]; 
    _size = size;
    
    for(int i = 0; i < _size; i++) {
        _mem[i] = {0}; 
    }
}

HeapMem::~HeapMem() {
    delete _mem; 
} 

bool HeapMem::_ptr_valid(int ptr) {
    return (ptr >= 0 || ptr <= _size) && (_mem[ptr].status == 1); 
}

int HeapMem::_mem_reserve(int offset, int size) {
    int head = offset - (size - 1); 

    _mem[head].status = 1; 
    
    for(int i = (head + 1); i < offset; i++) {
        _mem[i].status = 2; 
    }

    _mem[offset].status = 3; 

    return head; 
}

int HeapMem::alloc(int size) {
    int run = 0;
    
    for(int i = 0; i < _size; i++) {
        run = (_mem[i].status == 0) ? run + 1 : 0;

        if(run == size) {
            return _mem_reserve(i, size);  
        } 
    }

    return -1; 
}

void HeapMem::dealloc(int ptr) {
    int tmp = ptr; 

    if(!_ptr_valid(tmp)) {
        return; 
    } 
    
    while(_mem[tmp].status != 3) {
        _mem[tmp] = {0};
        tmp++; 
    }

    _mem[tmp] = {0}; 

}

int HeapMem::memget(int ptr) {
    return 0; 
}

void HeapMem::memset(int ptr, int val) {
    int tmp = ptr; 
    int radix = 1; 

    if(!_ptr_valid(tmp)) {
        return; 
    } 

    while(_mem[tmp].status != 3) {
        int bf = (((1 << 8) - 1) & (val >> (radix - 1))); 
        _mem[tmp].data = (uint8_t)bf;  
        tmp++; 
        radix += 8; 
    }

    int bf = (((1 << 8) - 1) & (val >> (radix - 1))); 
    _mem[tmp].data = (uint8_t)bf; 

}

void HeapMem::dump() {
    for(int i = 0; i < _size; i += 16) {    
        std::cout << std::setfill('0') << std::setw(4) << std::hex << std::uppercase << i;
        for(int j = 0; j < 16; j++) {
            std::cout << '\t' << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << (int)_mem[i+j].data;
        }
        std::cout << '\n'; 
     }
}