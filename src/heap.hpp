#pragma once
#include <cstdint>

struct Word {
    uint8_t head : 1; 
    uint8_t alloc : 1; 
    uint8_t next : 1; 
    uint8_t data : 8;  
}; 

class HeapMem {
    private:
        Word* _mem; 
        int _size;
        void _mem_reserve(int offset, int size); 

    public:
        HeapMem(); 
        HeapMem(int size);
        ~HeapMem(); 
        int alloc(int size);  
        int memget(int ptr); 
        void dealloc(int ptr);
        void memset(int ptr, int val);  
        void dump(); 
}; 
