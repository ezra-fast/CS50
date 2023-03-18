#include <cs50.h>
#include <stdio.h>

//BELOW IS A RECURSION EXAMPLE!!!!

//Merge sort: (Requires additional computer memory to execute)
    //Merge sort running time: O(n log n); It is actually theta(n log n) --------- It is very efficient.

//Pseudocode (merge sort):
    //If only one number:
        //Quit
    //Else:
        //Sort left half
        //Sort right half
        //Merge sorted halves



void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}


void draw(int n)
{
if (n <= 0)
{
    return;
}

    draw(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }

    printf("\n");
}
