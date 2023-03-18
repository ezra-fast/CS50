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
        candidates[i].votes = 0;        //Here the program sets the inital votes per candidate to zero.
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)         //Here the program gets votes until it surpasses the number of voters.
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

// Update vote totals given a new vote                  This is where your work begins!!!!!!
bool vote(string name)
{
    // TODO
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcmp(name, candidates[k].name) == 0)
        {
            candidates[k].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    int highest = candidates[0].votes;

    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes > highest)
        {
            highest = candidates[j].votes;
        }
    }

//Checking if any other candidate has equally high number of votes and printing winner(s) accordingly:

    for (int y = 0; y < candidate_count; y++)
    {
        if (candidates[y].votes == highest)
        {
            printf("%s\n", candidates[y].name);
        }
    }
    return;
}