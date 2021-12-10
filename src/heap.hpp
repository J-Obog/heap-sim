#pragma once
#include <cstdint>

struct Word {
    uint8_t H : 1; //indicates whether or not the word is the start of the allocated block
    uint8_t S: 4;  
    uint8_t D : 8; //bytes allocated for user data
};

class HeapMem {
    private:
        Word* _mem; //memory array
        int _size; //size of memory
        int _allocated = 0; //number of allocated bytes

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
