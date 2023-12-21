#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int k;
    int j;
    int n;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);
    for (n = 0; n < height; n++) // Here is where the printing loop starts
    {
        for (k = 0; k < height - n - 1; k++)
        {
            printf(" ");
        }
        for (j = 0; j <= n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
