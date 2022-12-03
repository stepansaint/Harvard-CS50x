/**
 * A program that prints out a half-pyramid 
 * of a specified height 
 * (less difficult)
 * @author Ermakov Stepan
*/

#include "cs50.h"
#include <stdio.h>

int main(void)
{
    // Height from 1 to 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int row = 1; row <= height; row++)
    {
        for (int number_of_spaces = 0; number_of_spaces < (height - row); number_of_spaces++)
        {
            printf(" ");
        }

        for (int number_of_hashes = 0; number_of_hashes < row; number_of_hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}