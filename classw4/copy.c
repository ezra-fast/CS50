#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1); // malloc and free should always be used in concert.
    if (t == NULL)
    {
        return 1;
    }

    strcpy(t, s); // first arg is destination, second arg is origin. strcpy automatically copies \0 (NUL) at the end.

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t); // This frees the memory that was used for t.
    return 0;
}


// string t = s; // at this point you are merging s and t in memory.