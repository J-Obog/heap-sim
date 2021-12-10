#pragma once
#include <cstdint>

struct Word {
    uint8_t H : 1;
    uint8_t S: 4;  
    uint8_t D : 8;
};

class HeapMem {
    private:
        Word* _mem;
        int _size;
        int _allocated = 0;

    public:
        HeapMem(); 
        HeapMem(int size); 
        ~HeapMem(); 
        int allocated_mem(); 
        int alloc(int size);  
        void dealloc(int ptr);
        int memget(int ptr); 
        void memset(int ptr, int val); 
        void dump();
}; 
