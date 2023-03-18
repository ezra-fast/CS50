
//recursion is a programming technique whereby a function calls itself.

//In C you can have a function call itself.

#include <cs50.h>
#include <stdio.h>

int main(void)
{

void draw(int n);

    int height = get_int("Height: ");

    draw(height);
}


void draw(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
