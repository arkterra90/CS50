import sys

greeting = input("greeting: ")
greeting = greeting.lower()

if "hello" in greeting:
    print("$0")
    sys.exit(0)

elif (greeting[0] == "h"):
    print("$20")
    sys.exit(0)


else:
    print("$100")
    sys.exit(0)

