#pragma once
#include <cstdint>

struct Word {
    uint8_t f : 2; //2 bits allocated for flags
    uint8_t d : 8; //8 bits allocated for data
}; 

class HeapMem {
    private:
        Word* _mem; 
        int _size;
        int find(int size); 

    public:
        HeapMem(); 
        HeapMem(int size);
        ~HeapMem(); 
        int alloc(int size);  
        int memget(int ptr); 
        void dealloc(int ptr);
        void memset(int ptr, int val);  
}; 
