#define NOMINMAX
#define DEF_MEM_SIZE 1024
#include <heap.hpp>
#include <iostream>
#include <iomanip>
#include <termcolor.hpp>

HeapMem::HeapMem() {
    _mem = new Word[DEF_MEM_SIZE];
    _size = DEF_MEM_SIZE; 

    for(int i = 0; i < _size; i++)
        _mem[i] = {0}; 
}

HeapMem::HeapMem(int size) {
    _mem = new Word[size]; 
    _size = size;

    for(int i = 0; i < _size; i++) 
        _mem[i] = {0};  
}

HeapMem::~HeapMem() {
    delete _mem; 
} 

int HeapMem::alloc(int size) {
    int run = 0;
    int ptr = 0;  

    while(ptr < _size) {
        if(run == (size + 1)) {
            int hp = ptr - size; 
            _mem[hp].S = size;
            _mem[hp].H = 1; 
            _allocated += size; 
            return hp; 
        } 
        int block = _mem[ptr].H; 
        ptr += (block) ? _mem[ptr].S : 1; 
        run = (block) ? 1 : run + 1;  
    }

    return -1;
}

void HeapMem::dealloc(int ptr) {
    if(!_mem[ptr].H)
        return; 

    int bsz = _mem[ptr].S;  
    for(int i = 0; i < bsz + 1; i++) {
        _mem[ptr + i] = {0}; 
    }

    _allocated -= bsz; 
}

int HeapMem::allocated_mem() {
    return _allocated; 
}

int HeapMem::memget(int ptr) {
    if(!_mem[ptr].H)
        return 0x0; 

    int bsz = _mem[ptr].S;
    int val = 0;
    int rad = 0;

    for(int i = 1; i < bsz; i++) 
        val |= (_mem[ptr + i].D << (8 * rad++)); 

    return val; 
}

void HeapMem::memset(int ptr, int val) {
    if(!_mem[ptr].H)
        return; 

    int bsz = _mem[ptr].S;
    int rad = 0; 

    for(int i = 1; i < bsz; i++) {
        int sf = 8 * (rad++);
        int mask = (255 << sf); 
        uint8_t b = (uint8_t)((val & mask) >> sf); 
        _mem[ptr + i].D = b;  
    }
}

void HeapMem::dump() {
    for(int i = 0; i < _size; i += 16) {
        std::cout << std::setfill('0') << std::setw(4) << std::hex << std::uppercase << termcolor::reset << i << "  ";
        int ahp = -1, bsz = 0; 

        for(int j = 0; j < 16; j++) {
            int mapped = i+j; 
            if (_mem[mapped].H) {
                ahp = mapped; 
                bsz = _mem[mapped].S; 
            }

            if(mapped < _size) {
                int d = (int)_mem[mapped].D; 
                if(_mem[mapped].H) {
                    std::cout << ' ' << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << termcolor::bright_magenta << d;
                } else if(mapped <= (ahp + bsz)) {
                    std::cout << ' ' << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << termcolor::red << d;
                } else {
                    std::cout << ' ' << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << termcolor::green << d;
                }
            }
        }
        std::cout << '\n'; 
     }
}