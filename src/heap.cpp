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
        if(run == size) {
            return _mem_reserve(i, size);  
        }
        run = (_mem[i].status == 0) ? run + 1 : 0; 
    }

    return -1; 
}

void HeapMem::dealloc(int ptr) {
    int tmp = ptr; 

    if(!_ptr_valid(tmp)) {
        return; 
    } 

    do {
        _mem[tmp] = {0}; 
        tmp++; 
    } while(_mem[tmp].status != 3); 
    
}

int HeapMem::memget(int ptr) {

}

void HeapMem::memset(int ptr, int val) {

}
