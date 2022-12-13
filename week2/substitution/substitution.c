#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// function prototype
bool valid_key(char* key);
void print_ciphertext(char* words, char* gaps);


int main(int argc, char* argv[])
{

    if (argc == 2) // check if argc is equal to 2
    {
        if (valid_key(argv[1]) == true) // check function key is valid or not
        {
            char* words = argv[1]; // creating a new array and equalise to new variable

            char gaps[1000]; // get some input from the user
            printf("plaintext: ");
            fgets(gaps, 1000, stdin);

            print_ciphertext(words, gaps); // recall print_ciphertext function
            return 0;
        }


    }
    printf("Usage: ./substitution key\n"); // print error and exit the code with output 1
    return 1;
}

// boolean function to return true or false after checking valid key
bool valid_key(char* key)
{
    int len = strlen(key);
    if (len == 26) // key must include 26 characters
    {
        for (int i = 0; i < len; i++)
        {
            if (!(isalpha(key[i]))) // if character is not alphabrtical then return false
            {
                return false;
            }
        }
        for (int m = 0; m < len - 1; m++) // nested for loop to check there is no duplicate characters inside key variable
        {
            for (int n = m + 1; n < len; n++)
            {
                if (tolower(key[m]) == tolower(key[n])) // make both loop to lowercase
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

// void print ciphertext function
void print_ciphertext(char words[1000], char* gaps)
{
    printf("ciphertext: ");
    for (int i = 0; i < 26; i++)
    {
        words[i] = tolower(words[i]); // equalise every character from the key to lowercase
    }

    int length = strlen(gaps); // find the length of input from the user
    for (int i = 0; i < length; i++)
    {
        if (isalpha(gaps[i])) // check if every character from the user is alphabetical
        {
            int index = toupper(gaps[i]) - 65; // and find the index of word inside the array
            char out;
            if (islower(gaps[i])) // equalise lower and upper character to new out variable
            {
                out = words[index];
            }
            else
            {
                out = toupper(words[index]);
            }
            printf("%c", out);
        }
        else
        {
            printf("%c",
                   gaps[i]); // if it is not alphabetical then just print as like as character what it is like number just print like a number
        }
    }
    //printf("\n");
}