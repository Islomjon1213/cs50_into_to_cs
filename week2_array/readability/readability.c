#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 1000000// define 10001 characters value with MAX 


// prototypes for functions
int count_letters(char text[MAX]);
int count_words(char text[MAX]);
int count_sentences(char text[MAX]);

int main(void)
{
    // variable to get text from the user
    char text[MAX];

    printf("Text: ");
    scanf("%[^\n]%*c",text); // this is one way to get string with spaces
    //fgets(text, MAX, stdin);  this is also another way to get string from the user with spaces

    // get return integers as float numbers and print them all
    float letters = count_letters(text);
    printf("Letters: %.2f\n", letters);

    float words = count_words(text);
    printf("Words: %.2f\n", words);

    float sentences = count_sentences(text);
    printf("Sentences: %.2f\n", sentences);

    // using this formula index = 0.0588 * L - 0.296 * S - 15.8  for finding L and S values as float numbers and print them
    float l_word = (letters / words) * 100;
    printf("Lwords: %.2f\n", l_word);

    float s_word = (sentences / words) * 100;
    printf("Swords: %.2f\n",s_word);

    // index = 0.0588 * L - 0.296 * S - 15.8  use this formula to get grade
    float index = (0.0588 * l_word) - (0.296 * s_word) - 15.8;
    printf("Index: %.2f\n", index);

    int sum = (int) round(index);
    printf("Int sum: %d\n", sum);

    // if condition to make use value is greater than 16 or less than 1
    if (sum >= 16)
    {
        printf("Grade 16+\n"); // if value is greater than 16 then print grade 16+
    }else if (sum <= 1)
    {
        printf("Before Grade 1\n"); // if value is less than 1 then print before grade 1
    }else
    {
        printf("Grade %d\n", sum); // else not both of them above then print just grade some number bettwen 1 and 16
    }
}

// funtcion to calculate how many letters
int count_letters(char text[MAX])
{
    int letter = 0;
    int len;
    for (int i = 0; len = strlen(text), i < len; i++)
    {
        if (isalpha(text[i]) || islower(text[i]) || isupper(text[i]))
        {
            letter++;
        }
         if (isdigit(text[i]) || isspace(text[i]) || isalnum(text[i]))
        {
            continue;
        }
    } return letter;
}

// function to calculate how many words
int count_words(char text[MAX])
{
    int words = 0;
    int len;
    for (int i = 0; len = strlen(text), i < len; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words + 1;
}

// function to calculate how many sentences
int count_sentences(char text[MAX])
{
    int sentences = 0;
    int len;
    for (int i = 0; len = strlen(text), i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}