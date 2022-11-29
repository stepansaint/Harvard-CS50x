/**
 * A program that prompts the user for a credit card number 
 * and then reports whether it is a valid American Express, 
 * MasterCard, or Visa card number
 * @author Ermakov Stepan
*/

#include "cs50.h"
#include <stdio.h>

bool am_ex_check(long int number);
bool visa_six_check(long int number);
bool visa_three_check(long int number);
bool mastercard_check(long int number);
void is_it_card(bool isLegit);

int main(void)
{
    long int number = get_long("Enter the card number, please: ");
    bool isLegit = false;

    isLegit = am_ex_check(number) || visa_six_check(number) ||
              visa_three_check(number) || mastercard_check(number);

    is_it_card(isLegit);
}

/*
American Express 15-digit (starts with 34 or 37)
Visa 16- and 13-digit (starts with 4)
MasterCard 16-digit (starts with 51, 52, 53, 54, or 55)
*/

// Check whether the number is American Express 15-digit card
bool am_ex_check(long int number)
{
    if ((number > 33999999999999 && number < 35000000000000) ||
        (number > 369999999999999 && number < 380000000000000))
    {
        int firstDigit = number % 10;
        int secondDigit = (number % 100) / 10;
        int secondExclusiveDigit = 0;
        int thirdDigit = (number % 1000) / 100;
        int fourthDigit = (number % 10000) / 1000;
        int fourthExclusiveDigit = 0;
        int fifthDigit = (number % 100000) / 10000;
        int sixthDigit = (number % 1000000) / 100000;
        int sixthExclusiveDigit = 0;
        int seventhDigit = (number % 10000000) / 1000000;
        int eigthDigit = (number % 100000000) / 10000000;
        int eigthExclusiveDigit = 0;
        int ninethDigit = (number % 1000000000) / 100000000;
        int tenthDigit = (number % 10000000000) / 1000000000;
        int tenthExclusiveDigit = 0;
        int eleventhDigit = (number % 100000000000) / 10000000000;
        int twelthDigit = (number % 1000000000000) / 100000000000;
        int twelthExclusiveDigit = 0;
        int thirteenthDigit = (number % 10000000000000) / 1000000000000;
        int fourteenthDigit = (number % 100000000000000) / 10000000000000;
        int fourteenthExclusiveDigit = 0;
        int fifteenthDigit = (number % 1000000000000000) / 100000000000000;
        int multOfEven;
        int sumOfOdd;
        bool isLegit = false;

        secondDigit *= 2;
        if (secondDigit >= 10)
        {
            secondExclusiveDigit = secondDigit % 10;
            secondDigit /= 10;
        }
        fourthDigit *= 2;
        if (fourthDigit >= 10)
        {
            fourthExclusiveDigit = fourthDigit % 10;
            fourthDigit /= 10;
        }
        sixthDigit *= 2;
        if (sixthDigit >= 10)
        {
            sixthExclusiveDigit = sixthDigit % 10;
            sixthDigit /= 10;
        }
        eigthDigit *= 2;
        if (eigthDigit >= 10)
        {
            eigthExclusiveDigit = eigthDigit % 10;
            eigthDigit /= 10;
        }
        tenthDigit *= 2;
        if (tenthDigit >= 10)
        {
            tenthExclusiveDigit = tenthDigit % 10;
            tenthDigit /= 10;
        }
        twelthDigit *= 2;
        if (twelthDigit >= 10)
        {
            twelthExclusiveDigit = twelthDigit % 10;
            twelthDigit /= 10;
        }
        fourteenthDigit *= 2;
        if (fourteenthDigit >= 10)
        {
            fourteenthExclusiveDigit = fourteenthDigit % 10;
            fourteenthDigit /= 10;
        }

        multOfEven = (secondDigit + secondExclusiveDigit) +
                     (fourthDigit + fourthExclusiveDigit) +
                     (sixthDigit + sixthExclusiveDigit) +
                     (eigthDigit + eigthExclusiveDigit) +
                     (tenthDigit + tenthExclusiveDigit) +
                     (twelthDigit + twelthExclusiveDigit) +
                     (fourteenthDigit + fourteenthExclusiveDigit);

        sumOfOdd = firstDigit + thirdDigit + fifthDigit +
                   seventhDigit + ninethDigit + eleventhDigit +
                   thirteenthDigit + fifteenthDigit;

        if ((multOfEven + sumOfOdd) % 10 == 0)
        {
            printf("AMEX\n");
            return !isLegit;
        }
        else
        {
            return isLegit;
        }
    }
    return false;
}

// Check whether the number is Visa 16-digit card
bool visa_six_check(long int number)
{
    if (number > 3999999999999999 && number < 5000000000000000)
    {
        int firstDigit = number % 10;
        int secondDigit = (number % 100) / 10;
        int secondExclusiveDigit = 0;
        int thirdDigit = (number % 1000) / 100;
        int fourthDigit = (number % 10000) / 1000;
        int fourthExclusiveDigit = 0;
        int fifthDigit = (number % 100000) / 10000;
        int sixthDigit = (number % 1000000) / 100000;
        int sixthExclusiveDigit = 0;
        int seventhDigit = (number % 10000000) / 1000000;
        int eigthDigit = (number % 100000000) / 10000000;
        int eigthExclusiveDigit = 0;
        int ninethDigit = (number % 1000000000) / 100000000;
        int tenthDigit = (number % 10000000000) / 1000000000;
        int tenthExclusiveDigit = 0;
        int eleventhDigit = (number % 100000000000) / 10000000000;
        int twelthDigit = (number % 1000000000000) / 100000000000;
        int twelthExclusiveDigit = 0;
        int thirteenthDigit = (number % 10000000000000) / 1000000000000;
        int fourteenthDigit = (number % 100000000000000) / 10000000000000;
        int fourteenthExclusiveDigit = 0;
        int fifteenthDigit = (number % 1000000000000000) / 100000000000000;
        int sixteenthDigit = (number % 10000000000000000) / 1000000000000000;
        int sixteenthExclusiveDigit = 0;
        int multOfEven;
        int sumOfOdd;
        bool isLegit = false;

        secondDigit *= 2;
        if (secondDigit >= 10)
        {
            secondExclusiveDigit = secondDigit % 10;
            secondDigit /= 10;
        }
        fourthDigit *= 2;
        if (fourthDigit >= 10)
        {
            fourthExclusiveDigit = fourthDigit % 10;
            fourthDigit /= 10;
        }
        sixthDigit *= 2;
        if (sixthDigit >= 10)
        {
            sixthExclusiveDigit = sixthDigit % 10;
            sixthDigit /= 10;
        }
        eigthDigit *= 2;
        if (eigthDigit >= 10)
        {
            eigthExclusiveDigit = eigthDigit % 10;
            eigthDigit /= 10;
        }
        tenthDigit *= 2;
        if (tenthDigit >= 10)
        {
            tenthExclusiveDigit = tenthDigit % 10;
            tenthDigit /= 10;
        }
        twelthDigit *= 2;
        if (twelthDigit >= 10)
        {
            twelthExclusiveDigit = twelthDigit % 10;
            twelthDigit /= 10;
        }
        fourteenthDigit *= 2;
        if (fourteenthDigit >= 10)
        {
            fourteenthExclusiveDigit = fourteenthDigit % 10;
            fourteenthDigit /= 10;
        }
        sixteenthDigit *= 2;
        if (sixteenthDigit >= 10)
        {
            sixteenthExclusiveDigit = sixteenthDigit % 10;
            sixteenthDigit /= 10;
        }

        multOfEven = (secondDigit + secondExclusiveDigit) +
                     (fourthDigit + fourthExclusiveDigit) +
                     (sixthDigit + sixthExclusiveDigit) +
                     (eigthDigit + eigthExclusiveDigit) +
                     (tenthDigit + tenthExclusiveDigit) +
                     (twelthDigit + twelthExclusiveDigit) +
                     (fourteenthDigit + fourteenthExclusiveDigit) +
                     (sixteenthDigit + sixteenthExclusiveDigit);

        sumOfOdd = firstDigit + thirdDigit + fifthDigit +
                   seventhDigit + ninethDigit + eleventhDigit +
                   thirteenthDigit + fifteenthDigit;

        if ((multOfEven + sumOfOdd) % 10 == 0)
        {
            printf("VISA\n");
            return !isLegit;
        }
        else
        {
            return isLegit;
        }
    }
    return false;
}

// Check whether the number is Visa 13-digit card
bool visa_three_check(long int number)
{
    if (number > 3999999999999 && number < 5000000000000)
    {
        int firstDigit = number % 10;
        int secondDigit = (number % 100) / 10;
        int secondExclusiveDigit = 0;
        int thirdDigit = (number % 1000) / 100;
        int fourthDigit = (number % 10000) / 1000;
        int fourthExclusiveDigit = 0;
        int fifthDigit = (number % 100000) / 10000;
        int sixthDigit = (number % 1000000) / 100000;
        int sixthExclusiveDigit = 0;
        int seventhDigit = (number % 10000000) / 1000000;
        int eigthDigit = (number % 100000000) / 10000000;
        int eigthExclusiveDigit = 0;
        int ninethDigit = (number % 1000000000) / 100000000;
        int tenthDigit = (number % 10000000000) / 1000000000;
        int tenthExclusiveDigit = 0;
        int eleventhDigit = (number % 100000000000) / 10000000000;
        int twelthDigit = (number % 1000000000000) / 100000000000;
        int twelthExclusiveDigit = 0;
        int thirteenthDigit = (number % 10000000000000) / 1000000000000;
        int multOfEven;
        int sumOfOdd;
        bool isLegit = false;

        secondDigit *= 2;
        if (secondDigit >= 10)
        {
            secondExclusiveDigit = secondDigit % 10;
            secondDigit /= 10;
        }
        fourthDigit *= 2;
        if (fourthDigit >= 10)
        {
            fourthExclusiveDigit = fourthDigit % 10;
            fourthDigit /= 10;
        }
        sixthDigit *= 2;
        if (sixthDigit >= 10)
        {
            sixthExclusiveDigit = sixthDigit % 10;
            sixthDigit /= 10;
        }
        eigthDigit *= 2;
        if (eigthDigit >= 10)
        {
            eigthExclusiveDigit = eigthDigit % 10;
            eigthDigit /= 10;
        }
        tenthDigit *= 2;
        if (tenthDigit >= 10)
        {
            tenthExclusiveDigit = tenthDigit % 10;
            tenthDigit /= 10;
        }
        twelthDigit *= 2;
        if (twelthDigit >= 10)
        {
            twelthExclusiveDigit = twelthDigit % 10;
            twelthDigit /= 10;
        }

        multOfEven = (secondDigit + secondExclusiveDigit) +
                     (fourthDigit + fourthExclusiveDigit) +
                     (sixthDigit + sixthExclusiveDigit) +
                     (eigthDigit + eigthExclusiveDigit) +
                     (tenthDigit + tenthExclusiveDigit) +
                     (twelthDigit + twelthExclusiveDigit);

        sumOfOdd = firstDigit + thirdDigit + fifthDigit +
                   seventhDigit + ninethDigit + eleventhDigit +
                   thirteenthDigit;

        if ((multOfEven + sumOfOdd) % 10 == 0)
        {
            printf("VISA\n");
            return !isLegit;
        }
        else
        {
            return isLegit;
        }
    }
    return false;
}

// Check whether the number is Mastercard 13-digit card
bool mastercard_check(long int number)
{
    if (number > 5099999999999999 && number < 5600000000000000)
    {
        int firstDigit = number % 10;
        int secondDigit = (number % 100) / 10;
        int secondExclusiveDigit = 0;
        int thirdDigit = (number % 1000) / 100;
        int fourthDigit = (number % 10000) / 1000;
        int fourthExclusiveDigit = 0;
        int fifthDigit = (number % 100000) / 10000;
        int sixthDigit = (number % 1000000) / 100000;
        int sixthExclusiveDigit = 0;
        int seventhDigit = (number % 10000000) / 1000000;
        int eigthDigit = (number % 100000000) / 10000000;
        int eigthExclusiveDigit = 0;
        int ninethDigit = (number % 1000000000) / 100000000;
        int tenthDigit = (number % 10000000000) / 1000000000;
        int tenthExclusiveDigit = 0;
        int eleventhDigit = (number % 100000000000) / 10000000000;
        int twelthDigit = (number % 1000000000000) / 100000000000;
        int twelthExclusiveDigit = 0;
        int thirteenthDigit = (number % 10000000000000) / 1000000000000;
        int fourteenthDigit = (number % 100000000000000) / 10000000000000;
        int fourteenthExclusiveDigit = 0;
        int fifteenthDigit = (number % 1000000000000000) / 100000000000000;
        int sixteenthDigit = (number % 10000000000000000) / 1000000000000000;
        int sixteenthExclusiveDigit = 0;
        int multOfEven;
        int sumOfOdd;
        bool isLegit = false;

        secondDigit *= 2;
        if (secondDigit >= 10)
        {
            secondExclusiveDigit = secondDigit % 10;
            secondDigit /= 10;
        }
        fourthDigit *= 2;
        if (fourthDigit >= 10)
        {
            fourthExclusiveDigit = fourthDigit % 10;
            fourthDigit /= 10;
        }
        sixthDigit *= 2;
        if (sixthDigit >= 10)
        {
            sixthExclusiveDigit = sixthDigit % 10;
            sixthDigit /= 10;
        }
        eigthDigit *= 2;
        if (eigthDigit >= 10)
        {
            eigthExclusiveDigit = eigthDigit % 10;
            eigthDigit /= 10;
        }
        tenthDigit *= 2;
        if (tenthDigit >= 10)
        {
            tenthExclusiveDigit = tenthDigit % 10;
            tenthDigit /= 10;
        }
        twelthDigit *= 2;
        if (twelthDigit >= 10)
        {
            twelthExclusiveDigit = twelthDigit % 10;
            twelthDigit /= 10;
        }
        fourteenthDigit *= 2;
        if (fourteenthDigit >= 10)
        {
            fourteenthExclusiveDigit = fourteenthDigit % 10;
            fourteenthDigit /= 10;
        }
        sixteenthDigit *= 2;
        if (sixteenthDigit >= 10)
        {
            sixteenthExclusiveDigit = sixteenthDigit % 10;
            sixteenthDigit /= 10;
        }

        multOfEven = (secondDigit + secondExclusiveDigit) +
                     (fourthDigit + fourthExclusiveDigit) +
                     (sixthDigit + sixthExclusiveDigit) +
                     (eigthDigit + eigthExclusiveDigit) +
                     (tenthDigit + tenthExclusiveDigit) +
                     (twelthDigit + twelthExclusiveDigit) +
                     (fourteenthDigit + fourteenthExclusiveDigit) +
                     (sixteenthDigit + sixteenthExclusiveDigit);

        sumOfOdd = firstDigit + thirdDigit + fifthDigit +
                   seventhDigit + ninethDigit + eleventhDigit +
                   thirteenthDigit + fifteenthDigit;

        if ((multOfEven + sumOfOdd) % 10 == 0)
        {
            printf("MASTERCARD\n");
            return !isLegit;
        }
        else
        {
            return isLegit;
        }
    }
    return false;
}

// Check weather the number is a card of one of the listed banks
void is_it_card(bool isLegit)
{
    if (!isLegit)
    {
        printf("INVALID\n");
    }
}