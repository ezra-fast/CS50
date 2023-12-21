#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char ans[20];
    printf("What school is CS50 taught at: ");
    scanf("%s", ans);

    if (strcmp(ans, "Harvard") == 0)
    {
        printf("Correct\n");
    }
    else
    {
        printf("Incorrect\n");
    }

}