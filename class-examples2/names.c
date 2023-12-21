#include <cs50.h>
#include <string.h>
#include <stdio.h>

//IF A FUNCTION RETURNS AN INT, 0 IS FALSE, AND ANY INTEGER (POSITIVE OR NEGATIVE) IS CONSIDERED TRUE. (important for line 13).

int main(void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

    for (int i = 0; i < 7; i++)
    {
        if (strcmp(names[i], "Ron") == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
