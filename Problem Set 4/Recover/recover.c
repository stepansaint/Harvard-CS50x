/**
 * A program that recovers JPEGs from a forensic image
 * @author Ermakov Stepan
*/

#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover ...\n");
        return 1;
    }

    // Open a forensic file
    FILE *in_ptr = fopen(argv[1], "r");
    if (in_ptr == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE]; 
    int counter_jpg = -1; // Start counting from 0
    char *name_jpg = malloc(sizeof(char) * 8);

    while (fread(buffer, 1, BLOCK_SIZE, in_ptr) == BLOCK_SIZE)
    {
        // Write to a new file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            counter_jpg++;
            create_new_jpg(name_jpg, in_ptr, buffer, counter_jpg);
        }
        else if (counter_jpg >= 0) // Write to an existing file
        {
            continue_writing_jpg(name_jpg, in_ptr, buffer);
        }
    }

    free(name_jpg);
    fclose(in_ptr);
}