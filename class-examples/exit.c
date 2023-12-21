#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing Command-Line Argument!\n");
        return 1; // anytime something goes wrong in a program, return a non-zero value from [main].
    }
    else
    {
        printf("Hello, %s\n", argv[1]);
        return 0; // returning 0 (zero-value) signals that all went well.
    }
}
