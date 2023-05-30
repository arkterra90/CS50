#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length;
    do
    {
        length = get_int("Length of the array: ");
    }
   while (length < 0);

   int twice[length];
   for (int i = 0; i < length; i++)
   {
        twice[i] = get_int("number: ") * 2;
   }
}