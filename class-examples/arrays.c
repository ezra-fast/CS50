#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int k = get_int("How many scores? ");

    int scores[k];
    int i;

    for(i = 0; i < k; i++)
    {
        scores[i] = get_int("Score: ");
    }


    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}




