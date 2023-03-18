#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//ASCIIchart.com: the difference between capital and lowercase letters is +32. (upper - lower is plus).

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
        {
            printf("%c", s[i] - 32); // toupper(s[i]) could replace s[i] - 32.
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}
// in this code, islower(s[i]) is a boolean expression.

