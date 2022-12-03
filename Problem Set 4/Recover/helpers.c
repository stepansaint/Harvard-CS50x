#include "helpers.h"

// Create a new JPEG file when find it and write to it
void create_new_jpg(char *name_jpg, FILE *input, BYTE buffer[], int counter_jpg)
{
    sprintf(name_jpg, "%03i.jpg", counter_jpg); 
    FILE *img = fopen(name_jpg, "w");
    if (img == NULL)
    {
        fclose(input);
        return;
    }

    fwrite(buffer, 1, BLOCK_SIZE, img);
    fclose(img);
}

// Continue to write to an existing JPEG file
void continue_writing_jpg(char *name_jpg, FILE *in_ptr, BYTE buffer[])
{
    FILE *img = fopen(name_jpg, "a");
    if (img == NULL)
    {
        fclose(in_ptr);
        return;
    }

    fwrite(buffer, 1, BLOCK_SIZE, img);
    fclose(img);
}