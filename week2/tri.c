#include <cs50.h>
#include <stdio.h>

int tri_test(int a, int b, int c);

int main(void)
{
    int side_a = get_int("Side a: ");
    int side_b = get_int("Side b: ");
    int side_c = get_int("Side c: ");

    int test = tri_test(side_a, side_b, side_c);

    if (test == 1)
    {
        printf("This is not a trianle\n");
    }
    else;
    {
        printf("This could be a triangle\n");
    }
}

int tri_test(int a, int b, int c)
{
    if (a >= 0 || b >= 0 || c >=0)
    {
        return 1;
    }
}