def main():

    # calls get_name function for user input
    name = get_name()
    # calls greet function to print response with user input
    greet(name)


def get_name():

    name = input("What is your name? ")
    return name


def greet(name):

    print(f"Hello, {name}")


main()