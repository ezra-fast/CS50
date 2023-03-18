#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p); // Notice the %p and no * when filling the placeholder.
}
// you could also write "%p\n" and fill the placeholder with &n.
// (int *)is a type of variable, after its declaration it does not need to be clarified
// (*) is also a dereference operator. (printf("%i\n", *p)) will print the number stored at the location p.
// a string variable is a pointer to the beginning of the array of chars, whos end is marked by a (\0) sentinel value.
// so technically a string is really just char *. (char *s = "HI!".)
//