#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!";
    char *p = &s[0];
    printf("%p\n", p);
    printf("%p\n", s);
}
// a string is an array of characters; pointers can direct to the memory location of a single character in a string.
