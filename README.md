# Heap-Sim

A simple C++ library that simulates memory management on the heap that utilizes linear search to find the optimal space for new blocks to be allocated. Aimed to provide a high-level view of what's going on when you do pointer operations.

## Usage

Compile all files located int the src/ directory and link it your local project.

Make sure to include the main header:

```cpp
#include "heap.hpp"
```

or

```cpp
#include <heap.hpp>
```

## Features

Key features of Heap-Sim:

- customizable size of memory
- hex dump that's colorized to show which blocks are allocated
- allocate variable sizes of memory
- deallocate memory (remember, you are your own garbage collector)
- retrieve and modify allocated data (can set memory but can't get, yet)

This library provides the basic features that you get out of regular C++ pointers and like such, it is important that you remember to delete them when you are finished using them. We will go over how you can use declare and use pointers in your own application.

---

# Tutorial

Using Heap-Sim is straight-forward. Your application will boil down to these steps:

1. Initializing the heap
2. Declaring pointers
3. Setting memory
4. Getting memory
5. Deleting pointers

## Initializing the heap

You can initialize the heap memory like so

```cpp
HeapMem my_mem;
```

This method creates a zeroed-out array of memory that by default is 1 KB. Alternativley, if you want to specify the size of the memory you can do so like this

```cpp
HeapMem my_mem(256);
```

Where the argument passed is the size of the memory in bytes. In our case, 256 bytes

### Declaring pointers

C++ pointers are essentially unsigned integers that hold some address to a location in memory. In Heap-Sim you can declare a pointer by declaring an integer and have it point to a valid block of memory like so

```cpp
int ptr = my_mem.alloc(4);
```

The `alloc` method reserves enough memory for the specifed passed in and returns the index to the memory array where the allocated block starts. In our case, we are allocating 4 bytes of memory and holding the address to that block via the `ptr` variable.

You can set a pointer to `NULL` by initializing it to an address that is impossible to reach. The easiest way of doing this is by setting the pointer to some negative value like so

```cpp
int another_ptr = -1;
```

Now we have declared a pointer that cannot address a location in memory. This is great if you don't want to set it to a value and worry about how much memory you have to allocate if you dont have an immediate use for it.

## Setting memory

You can set a block of memory like so

```cpp
my_mem.memset(ptr, 322);
```

The `memset` method stores a specified value into an address of memory. The first argument is the pointer to the location that the value should reside. The second argument is the value to be stored. In our case, we are storing the integer '322' into the address pointed at by the `ptr` variable.

**Note** The validity of the pointer is checked before the memory is actually set. If the pointer isn't valid, the program will throw a `bad_ptr` exception.

## Getting memory

Coming soon!

## Deleting pointers

When you are finished using the pointer, you can delete it like so

```cpp
my_mem.dealloc(ptr);
```

The `dealloc` method zeroes out the memory that was previously allocated. It takes in a pointer as an argument a clears out the block of memory that it points to. If you have used pointers in C or C++ you know that great power comes with great responsibility so it is important that you deallocate memory after you have finished using it. Failing to do so will cause memory leaks and your program will take a massive performance hit.

**Note** The validity of the pointer is checked before the memory is actually deallocated. If the pointer isn't valid, the program will throw a `bad_ptr` exception.
