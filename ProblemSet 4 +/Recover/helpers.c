#include "helpers.h"

void create_new_jpg(char *name_jpg, FILE* input, BYTE buffer[], int counter_jpg)
{
    sprintf(name_jpg, "%03i.jpg", counter_jpg); // Increase counter by one
    FILE *img = fopen(name_jpg, "w");
    if (img == NULL)
    {
        fclose(input);
        return;
    }

    fwrite(buffer, 1, BLOCK_SIZE, img);
    fclose(img);
}

void continue_writing_jpg(char *name_jpg, FILE* in_ptr, BYTE buffer[])
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