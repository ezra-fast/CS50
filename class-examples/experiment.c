#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string("What is your name: ");

    int key = 12;

    for (int i = 0; i < strlen(name); i++)
    {
        if (isupper(name[i]))
        {
            printf("%c", 65 + (name[i] + key - 65) % 26);
        }
        else if (isspace(name[i]))
        {
            printf(" ");
        }
        else
        {
            printf("%c", 97 + (name[i] + key - 97) % 26);
        }
    }
    printf("\n");
}

