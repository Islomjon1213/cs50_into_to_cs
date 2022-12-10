#include <stdio.h>
#include <ctype.h>
#include <string.h>

// global array for numbers which represent words
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calculate_word(char word[]);

int main()
{
    char word1[100];
    char word2[100];
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    int score1 = calculate_word(word1);
    int score2 = calculate_word(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }else if (score1 < score2)
    {
        printf("Player 2 wins\n");
    }else 
    {
        printf("Tie\n");
    }
    return 0;
}

int calculate_word(char word[])
{
    int score = 0;
    int len;
    for (int i = 0; len = strlen(word), i < len; i++)
    {
        if (isupper(word[i]))
        {
            score = score + POINTS[word[i] - 'A'];
        } else if (islower(word[i]))
        {
            score = score + POINTS[word[i] - 'a'];
        }
    }
    return score;
}