#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE; // creating varaible type for array later.



int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover file.name\n");
        return 1;
    }
    else
    {
        char *input = argv[1];

        FILE *inputptr = fopen(input, "r");

        if (inputptr == NULL)
        {
            printf("Cannot open file\n");
            return 2;
        }

//Variables:

        BYTE buffer[512];

        int count = 0;

        FILE *output = NULL;

        char NAME[8];

        while (fread(&buffer, 512, 1, inputptr) == 1)
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                if (count != 0)
                {
                    fclose(output);
                }

                sprintf(NAME, "%03i.jpg", count);
                output = fopen(NAME, "w");
                count = count + 1;
            }

            if (count != 0)
            {
                fwrite(&buffer, 512, 1, output);
            }
        }

        fclose(inputptr);
        fclose(output);

        return 0;
    }
}
