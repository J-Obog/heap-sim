#pragma once
#include <cstdint>

//pointer class
class h_ptr; 


//heap memory class
class heap {
private:
    uint8_t* _mem; 
    int _size; 

public:
    heap(); 
    heap(int size); 
    ~heap(); 
    h_ptr allocate(); 
    void deallocate(h_ptr heapPtr); 
};