#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int num = get_int("number: ");
    collatz(num);

    printf("%i steps\n", collatz(num));
}

int collatz(int n)
{
    int steps = 0;

    if (n == 1)
    {
        return 0;
    }
    else if ((n % 2) == 0)
    {
        return 1 + collatz(n/2);
    }
    else
    {
        return 1 + collatz(3*n + 1);
    }
}