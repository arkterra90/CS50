#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_jump(int h);

int main(void)
{
    //get height of mario jump from 1 to 8
    int h = get_height();

    //print height of mario jump with spaces for blanks
    print_jump(h);
}


int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: "); //takes users input
    }
    while (h < 1 || h > 8); //makes sure input is between 1 and 8
    return h;
}

void print_jump(int h)
{
    for (int row = 0; row < h; row++) //to print new line row
    {
        for (int space = h - row - 1; space > 0; space--) //declares space variable
        {
            printf(" "); //prints space
        }
        for (int hash = 0; hash < row + 1; hash++) //declares hash int in corespondance with row
        {
            printf("#");
        }
        printf("  ");
        for (int other_hash = 0; other_hash < row + 1; other_hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}