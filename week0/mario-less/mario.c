#include <cs50.h>
#include <stdio.h>

int get_height(void);

int main(void)
{
    //get height of mario jump from 1 to 8
    int h = get_height();

    //print height of mario jump with spaces for blanks
    for (int row = 0; row < h; row++) //to print new line row
    {
        for (int space = h - row -1; space > 0; space--) //prints space
        {
            printf(" ");
        }
        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}


int get_height(void)
{
     int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);
    return h;
}