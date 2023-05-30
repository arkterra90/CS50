#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO get string from user
    string input = get_string("User input: ");
    int length = strlen(input);
    int bits[BITS_IN_BYTE];

    //iterates through each integer of the user inputed string
    for (int i = 0; i < length; i++)
    {

        //stores base-2 to an array called bits
        for (int b = 0; b < BITS_IN_BYTE; b++)
        {
            bits[b] = input[i] % 2;
            input[i] = input[i] / 2;
        }

        //prints the array using print_bulb function
        for (int p = 7; p >= 0; p--)
        {
            print_bulb(bits[p]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
