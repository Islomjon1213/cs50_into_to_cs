#include <stdio.h>

int main()
{
    // get height from the user
    int height;
    do
    {
        printf("Height: ");
        scanf("%d", &height);
    }while (height < 1 || height > 8);

    // for loop for making row space and column
    for (int i = 0; i < height; i++)
    {
        for (int space = 0; space < height - i - 1; space++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}