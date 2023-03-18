#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);
    printf("s: ");
    scanf("%s", s); // Not necessary to do the & here because a char * points to the beginning of an array of chars.
    printf("s: %s\n", s);
}
