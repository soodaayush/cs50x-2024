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
} node;

int numberOfWords = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashValue = hash(word);
    node *cursor = table[hashValue];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    FILE *source = fopen(dictionary, "r");

    if (source == NULL)
    {
        return 1;
    }

    char wordArr[45];

    while (fscanf(source, "%s", wordArr) != EOF)
    {
        node *newWord = malloc(sizeof(node));
        int hashValue = hash(wordArr);
        strcpy(newWord->word, wordArr);
        newWord->next = table[hashValue];
        table[hashValue] = newWord;
        numberOfWords++;
    }

    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return numberOfWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *tempVar = table[i];
        node *cursor = table[i];

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tempVar);
            tempVar = cursor;
        }
    }

    return true;
}
