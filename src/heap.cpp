#include <heap.hpp>
#include <iostream>
#include <iomanip>
#define NOMINMAX
#include <termcolor.hpp>

HeapMem::HeapMem() {
    const int default_size = 1024; //set default memory size to 1 KB
    _mem = new Word[default_size];
    _size = default_size; 

    //zero out memory
    for(int i = 0; i < _size; i++) 
        _mem[i] = {0};
}

HeapMem::HeapMem(int size) {
    _mem = new Word[size]; 
    _size = size;

    //zero out memory
    for(int i = 0; i < _size; i++) 
        _mem[i] = {0};  
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
        if(run == size) { //found a contiguous block of memory big enough to allocate
            int ptr = i - size; 
            _mem_reserve(ptr, size);
            return ptr;
        }
        run = (!_mem[i].alloc) ? run + 1 : 0; //increment run if space is availabe, otherwise reset it
    }

    return -1;
}

void HeapMem::dealloc(int ptr) {
    if(!_mem[ptr].head) //check if pointer is valid
        return; 

    int tmp = ptr; 

    do {
        _mem[tmp] = {0}; //clear block data
        tmp++; 
    } while(_mem[tmp - 1].next != 0); //halt if reached the end of the previously allocated block
}

int HeapMem::memget(int ptr) { //will implement soon
    return 0; 
}

void HeapMem::memset(int ptr, int val) {
    if(!_mem[ptr].head) //check if pointer is valid
        return; 

    int tmp = ptr, radix = 1; //radix points to current base of val

    do {
        uint8_t nth_byte = (uint8_t)(((1 << 8) - 1) & (val >> (radix - 1))); //extract a nth byte from val and store in current word
        _mem[tmp].data = nth_byte; 
        tmp++; 
        radix += 8; //get the start position of the next byte
    } while(_mem[tmp - 1].next != 0); //halt if reached the end of the previously allocated block 
}

void HeapMem::dump() {
    for(int i = 0; i < _size; i += 16) {
        //print offset    
        std::cout << std::setfill('0') << std::setw(4) << std::hex << std::uppercase << termcolor::reset << i << "  ";
        for(int j = 0; j < 16; j++) {
            //print memory
            int mapped = i+j; 
            if(mapped < _size) {
                if(_mem[mapped].alloc) {
                    std::cout << ' ' << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << termcolor::red << (int)_mem[mapped].data;
                } else {
                    std::cout << ' ' << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << termcolor::green << (int)_mem[mapped].data;
                }

            }
        }
        std::cout << '\n'; 
     }
}