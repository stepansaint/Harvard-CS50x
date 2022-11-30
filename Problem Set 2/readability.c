/**
 * A program that calculates the approximate grade level
 * needed to comprehend some text
 * @author Ermakov Stepan
*/

#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    const int PER_100_WORDS = 100;
    float average_letters = ((float) letters / words) * PER_100_WORDS;
    float average_sentences = ((float) sentences / words) * PER_100_WORDS;

    /*
    The Coleman-Liau index of a text is designed to output that
    (U.S.) grade level that is needed to understand some text
    */
    int index = round(0.0588 * average_letters - 0.296 *
                      average_sentences - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return 0;
}

// Returns the number of letters in the text
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Returns the number of sentences in the text
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }
    return sentences;
}

// Returns the number of words in the text
int count_words(string text)
{
    int words = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words + 1; // Add a last word from the text
}