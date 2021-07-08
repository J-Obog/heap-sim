#pragma once
#include <cstdint>

class HeapMem {
    private:
        uint16_t* _mem; 
        int _size;

    public:
        HeapMem(); 
        HeapMem(int size);
        ~HeapMem(); 
        int alloc(int size);  
        int memget(int ptr); 
        void dealloc(int ptr);
        void memset(int ptr, int val);  
}; 
