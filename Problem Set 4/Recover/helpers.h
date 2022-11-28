#include <stdint.h>
#include <stdio.h>

// Digital cameras often initialize cards with a FAT 
// file system whose “block size” is 512 bytes
#define BLOCK_SIZE 512
typedef uint8_t BYTE;

// Create a new JPEG file when find it and write to it
void create_new_jpg(char *name_jpg, FILE* input, BYTE buffer[], int counter_jpg);

// Continue to write to an existing JPEG file
void continue_writing_jpg(char *name_jpg, FILE* in_ptr, BYTE buffer[]);