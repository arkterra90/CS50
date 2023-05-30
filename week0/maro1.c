#include <cs50.h>
#include <stdio.h>

//put functions at the top of your code with a ; to make c aware they exist below
int get_size(void);
void print_grid(int size);

int main(void)
{
    // get variable
    int n = get_size();

    // print grid of blocks
    print_grid(n);
}



























int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}