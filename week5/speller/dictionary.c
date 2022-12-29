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

// equalise N to sum of length + 1 and multiply by 'z' because we take lowercase inside the hash function
const unsigned int N = (LENGTH + 1) * 'z';

// Hash table
node *table[N];

// declare variables
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // create total variable
    int total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        // increase total by adding lowercase word[i]
        total += tolower(word[i]);
    }
    return (total % N); // after that return total module by N
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // read the file by using fopen function
    FILE *file = fopen(dictionary, "r");

    // and check if file is empty or not
    if (file == NULL)
    {
        printf("Error to open %s\n", dictionary);
        return false;
    }

    // make an array wit total length with 46
    char word[LENGTH + 1];

    // read the string from the file
    while (fscanf(file, "%s", word) != EOF)
    {
        // create new node while using malloc
        node *new_node = malloc(sizeof(node));
        // if new node is equal to NULL the just return false
        if (new_node == NULL)
        {
            return false;
        }
        // and copy everything from dictionary file to new node file
        strcpy(new_node->word, word);
        new_node->next = NULL;

        //declare index and equalise it to hash(word)
        int index = hash(word);
        // and check if table[index] equalise to NULL
        if (table[index] == NULL)
        {
            table[index] = new_node; // if condition is true then table[index] = new node which we created
        }
        else
        {
            // else new node next equailse to table[index] and table[index] = new node
            new_node->next = table[index];
            table[index] = new_node;
        }
        // after all we just increament word_count which count words
        word_count++;
    }
    // and finally we close the file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // just return word_count because it have already calculate total amount of words
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        // create new 3 nodes head cursor and temp
        node *head = table[i];
        node *cursor = head;
        node *temp = head;
        // run while loop till curser not equal to NULL
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
