// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// increased number of buckets to reduce run time
const unsigned int N = 1028;

// Hash table
node *table[N];

//New variable declerations from load functions
int word_count;
int hash_value;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_value = hash(word);

    //point cursor to head of linked list
    node *cursor = table[hash_value];

    //traverse linked list and look for match
    while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    //if no match is found return false to signify no matching word
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary
    FILE *infile = fopen(dictionary, "r");
    //check for opening of dictionary file
    if (infile == NULL)
    {
        printf("Could not open dictionary\n");
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(infile, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        //copy word to node
        strcpy(n->word, word);
        hash_value = hash(word);
        //insert word into table and reasign pointers
        n->next = table[hash_value];
        table[hash_value] = n;
        //counts words loaded into table for size function
        word_count++;
    }
    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count > 0)
    {
        // returns word count from load function
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        //free memory through linked list until NULL
        while (cursor != NULL)
        {
            node *tmp =  cursor;
            cursor = cursor->next;
            free(tmp);
        }
        //once at end of table return true to signal all memory is free
        if (i == (N - 1))
        {
            return true;
        }
    }
    return false;
}
