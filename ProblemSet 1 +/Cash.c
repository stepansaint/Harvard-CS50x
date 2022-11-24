#include <stdio.h>
#include <cs50.h>

int get_cents()
{
    int change;
    do
    {
        change = get_int("How much change is owed?\n");
    }
    while (change < 0);
    return change;
}

int calculate_quarters(int change)
{
    int numberOfCoins = 0;
    int quarter = 25;
    while (change >= quarter)
    {
        numberOfCoins++;
        change -= quarter;
    }
    return numberOfCoins;
}

int calculate_dimes(int change)
{
    int numberOfCoins = 0;
    int dime = 10;
    while (change >= dime)
    {
        numberOfCoins++;
        change -= dime;
    }
    return numberOfCoins;
}

int calculate_nickels(int change)
{
    int numberOfCoins = 0;
    int nickel = 5;
    while (change >= nickel)
    {
        numberOfCoins++;
        change -= nickel;
    }
    return numberOfCoins;
}

int calculate_pennies(int change)
{
    int numberOfCoins = 0;
    int penny = 1;
    while (change >= penny)
    {
        numberOfCoins++;
        change -= penny;
    }
    return numberOfCoins;
}

int main(void)
{
    int change = get_cents();
    int numberOfQuarters = calculate_quarters(change);
    change -= numberOfQuarters * 25;
    int numberOfDimes = calculate_dimes(change);
    change -= numberOfDimes * 10;
    int numberOfNickels = calculate_nickels(change);
    change -= numberOfNickels * 5;
    int numberOfPennies = calculate_pennies(change);
    int numberOfCoins = numberOfQuarters + numberOfDimes +
                        numberOfNickels + numberOfPennies;

    printf("%i\n", numberOfCoins);
}