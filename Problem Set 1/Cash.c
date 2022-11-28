/**
 * Implemented without CS50 library
 * @author Ermakov Stepan
*/

#include <stdio.h>

int calculate_dimes(int change);
int calculate_nickels(int change);
int calculate_pennies(int change);
int calculate_quarters(int change);
int get_cents();
int get_int(char *strig);

// A program that prompts the user for the number of cents 
// that a customer is owed and then prints the smallest number 
// of coins with which that change can be made
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

int get_cents()
{
    int change;
    do
    {
        change = get_int("Change owed (in cents): ");
    }
    while (change <= 0);
    return change;
}

int get_int(char *question)
{
    int n;
    printf("%s", question);
    scanf("%i", &n);
    return n;
}


