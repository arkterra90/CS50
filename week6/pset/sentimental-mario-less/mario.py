def main():

    # calls height function for user input
    height = get_height()
    # calls print function to print pyramid
    p_print(height)


def get_height():
    # gets user input for height of pyramid. Input must be between 1 and 8
    while True:
        try:
            n = int(input("Height: "))
            if (1 <= n <= 8):
                return n
        except ValueError:
            print("enter a number between 1 and 8")


def p_print(height):

    # prints left justifyed pyramid incrementing through spaces and hash symbol printing.
    for row in range(height):
        for space in range(height - row - 1, 0, -1):
            print(" ", end="")
        for hash in range(row + 1):
            print("#", end="")
        print()


main()