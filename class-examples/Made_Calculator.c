#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int number1;
    printf("1st Number: ");
    scanf("%d", &number1);

    int number2;
    printf("2nd Number: ");
    scanf("%d", &number2);

    char * operator= NULL;
    operator = malloc(sizeof(char));
    printf("Operator: ");
    scanf("%s", operator);

    int calc = 0;

    if (strcmp(operator, "+") == 0)
    {
        calc = (number1 + number2);
    }
    else if (strcmp(operator, "-") == 0)
    {
        calc = (number1 - number2);
    }
    else if (strcmp(operator, "*") == 0)
    {
        calc = (number1 * number2);
    }
    else if (strcmp(operator, "/") == 0)
    {
        calc = (number1 / number2);
    }

    printf("%d\n", calc);

    free(operator);

    return 0;

}