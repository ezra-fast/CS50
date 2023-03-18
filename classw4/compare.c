#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *i = get_string("i: ");
    char *j = get_string("j ");

    if (strcmp(i, j) == 0)
    {
        printf("same\n");
    }
    else
    {
        printf("Different\n");
    }
}