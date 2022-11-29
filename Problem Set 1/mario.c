/**
 * A program that prints out a double half-pyramid 
 * of a specified height
 * @author Ermakov Stepan
*/

#include <cs50.h>
#include <stdio.h>

void print_row(int row, int height);

int main(void)
{
    // Height from 1 to 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int current_row = 1; current_row <= height; current_row++)
    {
        print_row(current_row, height);
    }
}

// Print one row of hashes and spaces
void print_row(int row, int height)
{
    for (int space = 0; space < (height - row); space++)
    {
        printf(" ");
    }

    for (int hash = 0; hash < row; hash++)
    {
        printf("#");
    }
    printf("  ");
    for (int hash = 0; hash < row; hash++)
    {
        printf("#");
    }

    printf("\n");
}