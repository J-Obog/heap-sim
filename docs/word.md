## Word Struct

The Word struct is a bitfield that represents the payload of each word of memory.

For reference, a word is the smallest unit of memory in the heap. A contigous chunk of allocated memory is called a block.

#### Payload

`uint8_t H` - Flag to indicate whether or not a word is the start of an allocated block (1 bit)

`uint8_t S` - How big the block is in bytes (4 bits)

`uint8_t D` - Data of the word in memory (8 bits)
