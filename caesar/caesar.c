#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
//Variables:

//Main functionality begins here:

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);


    string ptext = get_string("plaintext:  ");

//Printing "ciphertext: " before the loop:

    printf("ciphertext: ");


    for (int i = 0, len = strlen(ptext); i < len; i++)
    {
        if (isupper(ptext[i]))
        {
            printf("%c", 65 + (ptext[i] - 65 + key) % 26);
        }
        else if (islower(ptext[i]))
        {
            printf("%c", 97 + (ptext[i] - 97 + key) % 26);
        }
        else
        {
            printf("%c", ptext[i]);
        }
    }

    printf("\n");

    return 0;

} //End of main function!