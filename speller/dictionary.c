// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
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

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int no; // Global variable for the count in LOAD, and later in SIZE;

// Returns true if word is in dictionary, else false ---------------------------- (Compiles) May be faulty!
bool check(const char *word)
{
    // TODO ---------- Needs to be case-insensitive!
    int value;
    node *cursor = NULL;

    value = hash(word);

    cursor = table[value];

    while (cursor != NULL)
    {
        if (strcasecmp(word, table[value]->word) == 0) // Consult documentation for the use of zero here.
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number -------------------------- (compiles) Algorithm from Dan Bernstein;
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long hashfunct = 5381;
    int u;
    while ((u = toupper(*word++)))
    {
        hashfunct = ((hashfunct << 5) + hashfunct) + u;
    }
    return hashfunct % N;
}

// Loads dictionary into memory, returning true if successful, else false ---------------- Potentially Complete (Compiles);
bool load(const char *dictionary)
{
    // TODO
    int hashindex;

    char words[46];

    node *nd = NULL;

    FILE *file = NULL;

    file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    else
    {
        while (fscanf(file, "%s", words) != EOF)
        {
            nd = malloc(sizeof(node));
            if (nd == NULL)
            {
                return false;
            }
            else
            {
                strcpy(nd->word, words);
                hashindex = hash(nd->word);
                table[hashindex] = nd;
                nd->next = table[hashindex];
                no = no + 1;
            }
        }
        fclose(file);
        return true;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded ----------------- Compiles!
unsigned int size(void)
{
    // TODO
    int size_value = no;
    if (size_value > 0)
    {
        return size_value;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO ----------------------------------- Not sure if correct, but it does compile!
    node *cursor;
    node *tmp;

    for (int y = 0; y < N; y++)
    {
        cursor = table[y];

        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        return true;
    }
    return false;
}
