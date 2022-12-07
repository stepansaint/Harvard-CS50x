# A program that prompts the user for a credit card number
# and then reports whether it is a valid American Express,
# MasterCard, or Visa card number
__author__ = "Ermakov Stepan"


import re

# American Express 15-digit (starts with 34 or 37)
# Visa 16- and 13-digit (starts with 4)
# MasterCard 16-digit (starts with 51, 52, 53, 54, or 55)


def main():

    # Get user input
    card = get_number_card("Number: ")

    # Check the input
    if is_valid_card(card):
        print(get_card_company(card))
    else:
        print("INVALID")


def is_valid_card(number):
    """Check the potentially correct card number. Return True if number
       is syntactically valid according to Luhn's algorithm, False otherwise."""

    # Check the length of number
    pattern = '^\d{13}$|^\d{15}$|^\d{16}$'
    if not re.match(pattern, number):
        return False

    reversed_copy_of_even_nums = []
    for i in number[-2::-2]:
        reversed_copy_of_even_nums.append(int(i) * 2)

    sum_of_even = 0
    for i in reversed_copy_of_even_nums:
        if int(i) > 9:
            temp = str(i)
            sum_of_even += int(temp[0]) + int(temp[1])
        else:
            sum_of_even += i

    sum_of_odd = 0
    for i in number[-1::-2]:
        sum_of_odd += int(i)

    res = sum_of_odd + sum_of_even

    # Check if the last digit is zero
    if res % 10 == 0:
        return True
    else:
        return False


def get_card_company(number):
    """Check whether number is AMEX or VISA or MASTERCARD card. Return
       card company if number is valid, `INVALID` otherwise."""
    if re.search("^3[4]|3[7]", number):
        return "AMEX"
    elif re.search("^4", number):
        return "VISA"
    elif re.search("^5[1-5]", number):
        return "MASTERCARD"
    else:
        return "INVALID"


def get_number_card(question):
    """Ask the user for number in a loop. Return the number typed by user."""
    
    # Only numbers
    pattern = '^\d{1,}$'
    while True:
        num = input(question)
        if (re.match(pattern, num)):
            break
    return num


if __name__ == "__main__":
    main()

