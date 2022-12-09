#include <stdio.h>
#include<stdbool.h>

bool cardValid( long long creditNumber);
int findLength( long long creditNumber);
bool checkSum( long long creditNumber);
void printf_card_brands( long long creditNumber);

int main()
{
    // get credit number from the user
    long long creditNumber;
    do 
    {
        printf("Numbers: ");
        scanf("%lli", &creditNumber);
    } while (creditNumber < 0);

    if(cardValid(creditNumber) == true)
    {
        printf_card_brands(creditNumber);
    }else
    {
        printf("INVALID\n");
    }
}

bool cardValid(long long creditNumber)
{
    int len = findLength(creditNumber);
    return ((len == 13 || len == 15 || len == 16) && checkSum(creditNumber));
    
}

int findLength(long long creditNumber)
{
    int len;
    for (len = 0; creditNumber != 0; creditNumber /= 10, len++);
    return len;
}

bool checkSum(long long creditNumber)
{
    int sum = 0;
    for (int i = 0; creditNumber != 0; creditNumber /= 10, i++)
    {
        if (i % 2 == 0)
        {
            sum += creditNumber % 10;
        } else
        {
            int digit = 2 * (creditNumber % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 0;
}

void printf_card_brands(long long creditNumber)
{
    if ((creditNumber >= 34e13 && creditNumber < 35e13) || (creditNumber >= 37e13 && creditNumber < 38e13))
    {
        printf("American Express\n");
    }
    else if (creditNumber >= 51e14 && creditNumber < 56e14)
    {
        printf("Master Card\n");
    }
    else if ((creditNumber >= 4e12 && creditNumber < 5e12) || (creditNumber >= 4e15 && creditNumber < 5e15))
    {
        printf("Visa card\n");
    } else
    {
        printf("Invalid");
    }
}


// #include <stdio.h>

// int main()
// {
//     int height;
//     do
//     {
//         printf("Height: ");
//         scanf("%d", &height);
//     }while (height < 1 || height > 8);

//     for (int i = 0; i < height; i++)
//     {
//         for (int space = 0; space < height - i - 1; space++)
//         {
//             printf(" ");
//         }
//         for (int j = 0; j <= i; j++)
//         {
//             printf("#");
//         }
//         printf("\n");
//     }
//     return 0;
// }