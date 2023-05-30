#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //Checks vote cast is for an actual cadidate and returns true
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            int v = candidates[i].votes;
            candidates[i].votes = v + 1;
            return true;
        }
    }

    //Checks to see if vote input does not compare and returns false
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) != 0)
        {
            return false;
        }
    }
    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //sorts through struct based on candidates.votes and than sorts descending largest to smallest votes
    int i, j, max_votes;
    for (i = 0; i < candidate_count - 1; i++)
    {
        max_votes = i;

        for (j = i + 1; j < candidate_count; j++)

            if (candidates[j].votes > candidates[max_votes].votes)
            {
                max_votes = j;
            }
        if (max_votes != i)
        {
            candidate start = candidates[max_votes];
            candidates[max_votes] = candidates[i];
            candidates[i] = start;
        }
    }

    //determines possible ties through iteratively evauluating equvilancy through the sorted array
    int tie = 0;
    for (int e = 0; e < candidate_count; e++)
    {
        if (candidates[e].votes == candidates[0].votes)
        {
            tie += 1;
        }
    }

    //prints winners of vote even if tie or multipul ties
    for (int e = 0; e < tie; e++)
    {
        printf("%s\n", candidates[e].name);
    }
    return;
}