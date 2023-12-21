#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;



int main(void)
{
    //List of size 0
    node *list = NULL; // variable that will point to a node in the future; variable is called list.

    //Add a number to list
    node *n = malloc(sizeof(node)); // n points to a node that has empty space of size node.

    if (n == NULL) // if n is pointing at nothing, exit the program.
    {
        return 1;
    }

    n->number = 1; // the node (and space) that n is pointing to now contains '1' and 'NULL', respectively.
    n->next = NULL;

    //Update list to point to new node:
    list = n; // the originally NULL pointer to a node now points to (node) n, which has a '1' and a 'NULL'.

    //Add number to list:
    n = malloc(sizeof(node)); // now we are changing n to open memory once again of size (node).
    if (n == NULL)
    {
        free(list); // if n is pointing at nothing, free the list memory and return 1 to exit the program.
        return 1;
    }
    n->number = 2; // if the program is still running, n now has 2 and 'NULL', respectively.
    n->next = NULL;
    list->next = n; // now list's 'next' contains n, which essentially points at 2 and a 'NULL' following it.

    //Add a number to list:
    n = malloc(sizeof(node)); // now we're changing n again to point to allocated memory of size 'node'
    if (n == NULL)
    {
        free(list->next); // Safety precaution before potentially exiting the program.
        free(list);
        return 1;
    }
    n->number = 3; // n now points to a node that contains a 3 and NULL, respectively.
    n->next = NULL;
    list->next->next = n; // Now list's original node pointer is pointing at another node pointer which points at n, which is now 3.
    //take your time!

    //Print numbers:
    for (node *tmp = list; tmp != NULL; tmp = tmp->next) // There is an example of this somewhere on paper in your notes.
    {
        printf("%i\n", tmp->number);
    }

    //Free the linked list:
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
    return 0;
}
