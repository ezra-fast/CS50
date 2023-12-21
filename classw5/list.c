#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Dynamically allocate memory of size 3:
    int *list = malloc(3 * sizeof(int)); // This is putting the memory on the heap instead of the stack.

    if (list == NULL)
    {
        return 1;
    }

    //Assign 3 numbers to that array:
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //Time passes

    //Resize old array to be of size 4:
    int *tmp = realloc(list, 4 * sizeof(int)); // Realloc EXAMPLE!

    if (tmp == NULL)
    {
        free(list);
        return 2;
    }

    //Add 4th number to new array with increased memory allotment:
    tmp[3] = 4;

    //Remember new array:
    list = tmp;

    //Print new array:
    for (int y = 0; y < 4; y++)
    {
        printf("%i", list[y]);
    }
    printf("\n");

    free(tmp); // Always remember to free EVERYTHING to avoid memory leaks. (Because tmp and list are
    // technically pointing at the same thing here, they can be freed one and the same).

    return 0;
}
