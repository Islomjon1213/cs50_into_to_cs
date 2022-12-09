#include <stdbool.h>
#include <stdio.h>

void printCreditBrands(long long creditNumber);
bool creditValid(long long creditNumber);
int findLengthofCard(long long n);
bool checkSum(long long n);

int main(void)
{
    long long creditNumber;
    do
    {
        printf("Numbers: ");
        scanf("%lli", &creditNumber);
    } while(creditNumber < 0);

    if(creditValid(creditNumber) == true)
    {
        printCreditBrands(creditNumber);
    }else
    {
        printf("INVALID\n");
    }
}
bool creditValid(long long creditNumber)
{
    int len = findLengthofCard(creditNumber);
    if((len == 13 || len == 15 || len == 16) && checkSum(creditNumber))
    {
        return true;
    }else
    {
        return false;
    }
}

int findLengthofCard(long long n)
{
    int len;
    for(len = 0; n != 0; n /= 10, len++);
    return len;
}
bool checkSum(long long n)
{
    int sum = 0;
    for(int i = 0; n != 0; n /= 10, i++)
    {
        if(i % 2 == 0)
        {
            sum += n % 10;
        }else
        {
            int digit = 2 * (n % 10);
            sum += digit/10 + digit % 10;
        }
    } return (sum % 10) == 0;
}
void printCreditBrands(long long creditNumber)
{
    if((creditNumber >= 34e13 && creditNumber < 35e13) || (creditNumber >= 37e13 && creditNumber < 38e13))
    {
        printf("American Express\n");
    } else if(creditNumber >= 51e14 && creditNumber < 56e14)
    {
        printf("MASTERCARD\n");
    }else if((creditNumber >= 4e12 && creditNumber < 5e12) || (creditNumber >= 4e15 && creditNumber < 5e15))
    {
        printf("VISA\n");
    }else
    {
        printf("INVALID\n");
    }
}