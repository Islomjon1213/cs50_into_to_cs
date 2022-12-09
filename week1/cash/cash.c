#include <stdio.h>

int get_cents();
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main()
{
    int cents = get_cents();

    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    int total = quarters + dimes + nickels + pennies;
    printf("Total is %d\n", total);
    return 0;
}

int get_cents()
{
    int sum;
    do 
    {
        printf("Enter any value: ");
        scanf("%d", &sum);
    }
    while(sum <= 0);
    return sum;
}

int calculate_quarters(int cents)
{
    int coins = 0;
    while (cents >= 25)
    {
        coins = coins - 25;
        coins++;
    }
    return coins;
}

int calculate_dimes(int cents)
{
    int coins = 0;
    while(cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    return coins;
}

int calculate_nickels(int cents)
{
    int coins = 0;
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    return coins;
}

int calculate_pennies(int cents)
{
    int coins = 0;
    while(cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    return coins;
}