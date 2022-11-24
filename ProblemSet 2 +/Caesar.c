#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isAllDigits(string secondArgument);

int main(int argc, string argv[])
{
    if (argc != 2 || isAllDigits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string plaintext = get_string("Type the sentence, please: ");
    int key = atoi(argv[1]);

    printf("plaintext:  %s\nciphertext: ", plaintext);

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        else
        {
            if (isupper(plaintext[i]))
            {
                int charForUpper = ((plaintext[i] - 65 + key) % 26) + 65;
                printf("%c", charForUpper);
            }
            else
            {
                int charForLower = ((plaintext[i] - 97 + key) % 26) + 97;
                printf("%c", charForLower);
            }
        }
    }

    printf("\n");
}

int isAllDigits(string secondArgument)
{
    for (int i = 0; i < strlen(secondArgument); i++)
    {
        if (isdigit(secondArgument[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}
