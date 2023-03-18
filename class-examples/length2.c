#include <stdio.h>
#include <cs50.h>
#include <string.h>
// manual.cs50.io = 'manual pages' are publicly accessible pages of functions.
// strlen = calculates the length of a string.
int main(void)
{
    string name = get_string("What is your name: ");
    int length = strlen(name);
    printf("%i\n", length);
}



// only strings are accompanied at the end with a NUL character.

