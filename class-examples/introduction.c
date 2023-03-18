#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    char name[55];

    printf("What is your name: ");
    fgets(&name[0], 55, stdin);                               // Note here the usefulness of the fgets() function, used with the appropriate arguments.

    printf("Hello %s", name);
}
