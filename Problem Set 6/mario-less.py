# A program that prints out a half-pyramid
# of a specified height
# (less difficult)
__author__ = "Ermakov Stepan"


def main():
    height = get_int()
    for x in range(height):
        for y in range(height - (x + 1)):
            print(end=" ")
        print("#" * (x + 1))


def get_int():
    while True:
        try:
            n = int(input("Height: "))
            if (n > 0 and n < 9):
                break
        except ValueError:
            print("That's not an integer!")
    return n


if __name__ == "__main__":
    main()