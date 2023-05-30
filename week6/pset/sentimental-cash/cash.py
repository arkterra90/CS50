import cs50


def main():

    # calls get_cents function for user input
    cents = get_cents()

    # calls coin_call function to calculate min coins needed
    coin_cal(cents)


def get_cents():
    while True:
        try:
            cents = cs50.get_float("How much change is owed? ")
            if (cents > 0):
                return cents
        except ValueError:
            print("enter amount of change owed")


def coin_cal(cents):

    # create a list of coin values
    money = [25, 10, 5, 1]
    size = len(money)
    count = 0
    cents = round(cents * 100)

    # iterate through money list and increment count
    for c in range(0, size, 1):
        while cents >= money[c]:
            cents = cents - money[c]
            count += 1

    # prints min count of coins needed
    print(f"{count}")


main()