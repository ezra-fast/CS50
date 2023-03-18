#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 3)); // This will be the sentinel value; (+ 3) is plus 3 bytes.

    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    printf("%i\n", *(numbers + 5)); // This is pointer arithmetic, meaning that we are going to the location of the beginning of the array
// plus a given number of bytes.
// an array can be treated as the first value of the array. (when dealing with pointers)
}