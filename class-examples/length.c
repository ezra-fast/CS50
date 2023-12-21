#include <stdio.h>
#include <cs50.h>

// Holy Shit!!!!!

int string_length(string name);

int main(void)
{
    string name = get_string("Name Here: ");
    int length = string_length(name);
    printf("%i\n", length);
}


int string_length(string name)
{
    int i = 0;
    while(name[0] != '\0')
    {
        i++;
    }
    return i;
}

