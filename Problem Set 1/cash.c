/**
 * A program that prompts the user for the number of cents
 * that a customer is owed and then prints the smallest number
 * of coins with which that change can be made
 * @author Ermakov Stepan
*/

#include "cs50.h"
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int change;
    do
    {
        change = get_int("Change owed (in cents): ");
    }
    while (change <= 0);
    return change;
}

int calculate_quarters(int cents)
{
    int number_coins = 0;
    int quarter = 25;
    while (cents >= quarter)
    {
        number_coins++;
        cents -= quarter;
    }
    return number_coins;
}

int calculate_dimes(int cents)
{
    int number_coins = 0;
    int dime = 10;
    while (cents >= dime)
    {
        number_coins++;
        cents -= dime;
    }
    return number_coins;
}

int calculate_nickels(int cents)
{
    int number_coins = 0;
    int nickel = 5;
    while (cents >= nickel)
    {
        number_coins++;
        cents -= nickel;
    }
    return number_coins;
}

int calculate_pennies(int cents)
{
    int number_coins = 0;
    int penny = 1;
    while (cents >= penny)
    {
        number_coins++;
        cents -= penny;
    }
    return number_coins;
}