#include <cs50.h>
#include <stdio.h>
#include <string.h>

int command_line(int argc);

int main(int argc, string argv[])
{

    while (command_line = 0)
    do
    {
        string input;
    do
    {
        input = get_string("plaintext: ");
    }
    while ( input[0] < 64);

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 65 && input[i] <= 95)
        {
            input[i] = input[i] + (argc - 1);
        }

        else if (input[i] >= 97 && input[i] <= 122)
        {
            input[i] = input[i] + (argc - 1);
        }

        else
        {
            input[i] = input[i];
        }
    }
    printf("ciphertext: %s", input);
    printf("\n");
    }
}

int command_line(int bit)
{
    while (argc < 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
        bit = 1;
    }
    else (argc > 0)
    {
        return 0;
        bit = 0;
    }
    return bit;
}