#include <stdint.h>
#include <stdio.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

void create_new_jpg(char *name_jpg, FILE* input, BYTE buffer[], int counter_jpg);

void continue_writing_jpg(char *name_jpg, FILE* in_ptr, BYTE buffer[]);