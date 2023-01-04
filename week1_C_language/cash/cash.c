#include <stdio.h>

// protypes for functions
int get_cents();
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main()
{
    // get value from the user
    int cents = get_cents();

    // calculate quarter coins
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // calculate dimes coins
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // calculate nickles coins
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // calculate pennies coins
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // calculate and print total coins
    int total = quarters + dimes + nickels + pennies;
    printf("Total is %d\n", total);
    return 0;
}

// function for get input from the user
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

// function for calculate quarters
int calculate_quarters(int cents)
{
    int coins = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }
    return coins;
}

// function for calculate dimes
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

// function for calculate nickles
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

// function for calculate pennies
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