#pragma once
#include <cstdint>

struct Word {
    //flags
    uint8_t head : 1; //indicates whether or not the word is the start of the allocated block
    uint8_t alloc : 1; //indicates whether or not the word has been allocated 
    uint8_t next : 1; //indicates whether or not the adjecent word is apart of the same allocated block
    //payload
    uint8_t data : 8; //bytes allocated for user data
};

class HeapMem {
    private:
        Word* _mem; //memory array
        int _size; //size of memory
        void _mem_reserve(int offset, int size); //helper function that sets the approriate flags

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
