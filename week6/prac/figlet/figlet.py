import sys
import random
from pyfiglet import Figlet
figlet = Figlet()

user_in = input("Input: ")

fonts = figlet.getFonts()
num_fonts = len(fonts)

if (len(sys.argv) == 1):
    ran_font = random.randint(0, num_fonts)

    figlet.setFont(font=fonts[ran_font])

    print("Output")
    print(figlet.renderText(user_in))
    sys.exit(0)

elif ((len(sys.argv) == 3) and (((sys.argv[1] =="-f") or (sys.argv[1] == "-font")))):

    if (sys.argv[2]) not in fonts:
        print("Invalid Usage")
        sys.exit(1)

    else:
        figlet.setFont(font=sys.argv[2])

        print("Output:")
        print(figlet.renderText(user_in))
        sys.exit(0)

else:
    print("Invalid Usage")
    sys.exit(1)