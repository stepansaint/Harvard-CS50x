# A program that prints out a double half-pyramid
# of a specified height
# (more difficult)
__author__ = "Ermakov Stepan"


def main():
    height = get_int()
    start = 0
    print_double_pyramid(start, height)


def get_int():
    while True:
        try:
            n = int(input("Height: "))
            if (n > 0 and n < 9):
                break
        except:
            print("That's not an integer!")
    return n


def print_double_pyramid(n, end):
    
    # Base-case
    if n == end:
        return

    print(" " * (end - (n + 1)), end="")
    print("#" * (n + 1), end="  ")
    print("#" * (n + 1))
    print_double_pyramid(n + 1, end)


if __name__ == "__main__":
    main()