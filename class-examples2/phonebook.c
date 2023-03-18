#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Encapsulate means to contain related pieces of information in a single accessible way.
//In this code, we have a datatype: person, that contains a name and number.
//Then we have an array of "persons", each with a name and number.

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{

person people[2];

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "David") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

