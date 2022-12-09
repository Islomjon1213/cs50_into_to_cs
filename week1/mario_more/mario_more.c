#include <stdio.h>

int main()
{
    int height;
    // get height from the user 
    do 
    {
        printf("Height: ");
        scanf("%d", &height);
    } while (height < 1 || height > 8); // do while loop till condiyion is true

    // if conditions for row space and column
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
        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;

}