#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(string prompt);

int main(void)
{
    candidate candidates_array[3];
    for (int i = 0; i < 3; i++)
    {
        candidates_array[i] = get_candidate("Enter Candidate: ");
    }
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    candidate c; //this is a way of giving a shorter name to the longer struct
    c.name = get_string("Enter a name: ");
    c.votes = get_int("Enter a number of votes: ");
    return c;
}