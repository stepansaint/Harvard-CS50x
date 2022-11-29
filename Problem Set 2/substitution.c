/**
 * A program that encrypts messages using a substitution cipher
 * @author Ermakov Stepan
*/

#include <stdio.h>
#include "cs50.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Check correctness of input (exactly 26 letters)
int proper_input(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (proper_input(argv[1]))
    {
        return 1;
    }

    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        else if (isupper(plaintext[i]))
        {
            for (int j = 0; j < strlen(argv[1]); j++)
            {
                if ((plaintext[i] - 65) == j)
                {
                    printf("%c", toupper(argv[1][j]));
                }
            }
        }
        else
        {
            for (int j = 0; j < strlen(argv[1]); j++)
            {
                if ((plaintext[i] - 97) == j)
                {
                    printf("%c", tolower(argv[1][j]));
                }
            }
        }
    }
    printf("\n");

    return 0;
}

int proper_input(string key)
{
    int length_of_key = strlen(key);

    for (int i = 0; i < length_of_key; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        if (length_of_key != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    for (int i = 0; i < length_of_key; i++)
    {
        int count_from = i + 1;

        for (int j = count_from; j < length_of_key; j++)
        {
            if (key[i] == key[j] || key[i] == (key[j] + 32) || key[i] == (key[j] - 32))
            {
                printf("Key must contain each letter exactly once.\n");
                return 1;
            }
        }
    }

    return 0;
}