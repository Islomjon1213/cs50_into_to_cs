#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool check_digit(char * keys);
void print_ciphertext(char * words, int key);

int main(int argc, char * argv[])
{
    // check if argc is equal to 2
    if (argc == 2)
    {
        char * keys;
        // check if value from the user is digit or not
        if (check_digit(argv[1]) == true)
        {
            // convert argv string value to integer value
            int key = atoi(argv[1]);
            char words[1000];
            printf("Plaintext: ");
            fgets(words, 1000, stdin);
            // recall print_ciphertext function to print outputs
            print_ciphertext(words, key);
            // return 0 to represent program runs correctly
            return 0;
        }
    }

    // print and return 1 to represent program runs incorrectly
    printf("Usage: ./caesar key\n");
    return 1;
}

// boolen funcion to return value from the user is digit or not
bool check_digit(char * keys)
{
    int len = strlen(keys);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(keys[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

// void function to print outputs
void print_ciphertext(char words[1000], int key)
{
    int len = strlen(words);
    printf("ciphertext: ");
    for (int i = 0; i < len; i++)
    {
        // check if char value is alphabetical
        if (isalpha(words[i]))
        {
            int num;
            // check if char value is uppercase
            if (isupper(words[i]))
            {
                num = 65;
            }
            else
            {
                num = 97;
            }
            // calculate to shift numbers by key value
            int index = words[i] - num;
            int index_number = (index + key) % 26;
            int index_asci = index_number + num;
            printf("%c", index_asci);
        }
        else
        {
            printf("%c", words[i]);
        }
    }
    printf("\n");
}