#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: \n");
    int age = get_int("Age: \n");
    string phone = get_int("Phone number: \n");
    {
        printf("Name: %s\n", name);
        printf("Age: %i\n", age);
        printf("Phone number: %s\n", phone);
    }
}