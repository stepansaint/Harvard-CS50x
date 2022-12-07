# A program that prompts the user for the number of cents
# that a customer is owed and then prints the smallest number
# of coins with which that change can be made
__author__ = "Ermakov Stepan"


# Present [quarter, dime, nickel, penny]
coins = [25, 10, 5, 1]


def main():
    change = int(100 * get_float("Change owed: "))
    start = 0
    print(calculate_change(change, coins[start], start))


def calculate_change(change, coin, current):
    # Base-case
    if change == 0:
        return 0

    if change >= coin:
        return 1 + calculate_change(change - coin, coins[current], current)
    current += 1
    return 0 + calculate_change(change, coins[current], current)


def get_float(str):
    while True:
        try:
            value = float(input(str))
            if value > 0:
                break
        except ValueError:
            print("That's not a float!")
    return value


if __name__ == "__main__":
    main()

