#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[3]; // when this is left uninitialized, the for loop will return 'garbage values'. (random things stored in random memory).

    for (int i = 0; i < 3; i++)
    {
        printf("%i\n", scores[i]);
    }
}
