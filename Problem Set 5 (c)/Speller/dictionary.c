// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// A whole alphabet for each length of a word (up to 25 letters)
const unsigned int N = 16328;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_in_table = hash(word);

    if (table[hash_in_table] == NULL)
    {
        return false;
    }

    node *temp = table[hash_in_table];
    while (temp != NULL)
    {
        if (strcasecmp(word, temp->word) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    short length = (short) strlen(word);
    short primary_factor_of_hash = tolower(word[0]) - 'a';
    if (length == 1)
    {
        return primary_factor_of_hash;
    }

    short secondary_factor_of_hash = tolower(word[1]) - 'a';
    if (secondary_factor_of_hash < 0)
    {
        return N - 1;
    }
    short average_length_of_word = 20;
    short capacity_of_alphabet = 26;
    if (length > average_length_of_word)
    {
        return ((average_length_of_word - 1) * (capacity_of_alphabet - 1) *
                capacity_of_alphabet + capacity_of_alphabet *
                (primary_factor_of_hash + 1) + secondary_factor_of_hash);
    }
    else if (length == 2)
    {
        return capacity_of_alphabet * (primary_factor_of_hash + 1) +
               secondary_factor_of_hash;
    }
    else
    {
        return ((length - 2) * (capacity_of_alphabet - 1) *
                capacity_of_alphabet + capacity_of_alphabet *
                (primary_factor_of_hash + 1) + secondary_factor_of_hash);
    }
}

// Loads dictionary into memory, returning true if successful, else false
int word_count = 0;
bool load(const char *dictionary)
{
    FILE *text = fopen(dictionary, "r");
    if (!text)
    {
        return false;
    }

    char word[LENGTH + 1];
    node *temp = NULL;
    int number_hash;
    while (fscanf(text, "%s", word) != EOF)
    {
        temp = malloc(sizeof(node));
        if (!temp)
        {
            fclose(text);
            return false;
        }

        number_hash = hash(word);

        strcpy(temp->word, word);
        if (table[number_hash] != NULL)
        {
            temp->next = table[number_hash];
            table[number_hash] = temp;
        }
        else
        {
            temp->next = NULL;
            table[number_hash] = temp;
        }

        word_count++;
    }

    fclose(text);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    bool is_unloaded = false;
    node *temp = NULL;

    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            temp = table[i]->next;
            free(table[i]);
            table[i] = temp;
        }
        is_unloaded = true;
    }

    return is_unloaded;
}
