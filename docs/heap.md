## HeapMem Class

#### Variables

`Word* _mem` - Array of memory where heap data is stored

`int _size` - Size of the heap (default is 1KB)

`int _allocated` - Total amount of allocated memory (in bytes)

#### Methods

`HeapMem()` - Default constructor that initializes a 1KB sized heap with zeroed-out memory

`HeapMem(int size)` - Parameterized constructor that initializes a heap with the specified _size_ and zeroed-out memory

`~HeapMem()` - Destructor that deallocates the memory pointed to by `_mem`

`int allocated_mem()` - Returns `_allocated`

`int alloc(int size)` - Allocates a block of memory with the specified _size_ and returns a pointer to the start of that block

`void dealloc(int ptr)` - Deallocates the block of memory pointed to by _ptr_

`int memget(int ptr)` - Returns the data in memory pointed to by _ptr_

`void memset(int ptr, int val)` - Sets the block of memory pointed to by _ptr_ to the value specified by _val_

`void dump()` - Prints a hex dump of the contents of `_mem`
