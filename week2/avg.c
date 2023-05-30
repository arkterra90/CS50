#include <cs50.h>
#include <stdio.h>

int n = 3;
float average(int speed[]);

int main(void)
{
    int speed[n];
    for (int i = 0; i < n; i++)
    {
        speed[i] = get_int("Speed: ");
    }

    printf("Average: %f\n", average(speed));
}

float average(int speed[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += speed[i];
    }
    return sum / (float) n;
}