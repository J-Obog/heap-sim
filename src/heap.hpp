#pragma once
#include <cstdint>

struct Word {
    uint8_t status : 2; //2 bits allocated for block status
    uint8_t data : 8; //8 bits allocated for data
}; 

class HeapMem {
    private:
        Word* _mem; 
        int _size;
        int _mem_reserve(int offset, int size); 
        bool _ptr_valid(int ptr); 

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
