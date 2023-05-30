#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    // Buffer is holding 7 chars because it's a 6 char plate number and a nul char
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];
    char *temp = NULL;


    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        //malloc'd heap memory to temp to store value of buffer
        temp = malloc(7 * sizeof(char));
        //Prevents seg fault by validating allocation of memory has occured
        if (temp == NULL)
        {
            printf("temp memory could not allocate\n");
            return 1;
        }

        // For loop iterates through each buffer character to copy buffer value to temp
        for (int x = 0; x < 7; x++)
        {
            temp[x] = buffer[x];
        }

        // Plate number stored in plates array
        plates[idx] = temp;
        idx++;
    }

    for (int i = 0; i < idx; i++)
    {
        printf("%s\n", plates[i]);
    }

    // fclose and free opened file and malloc'd memory to prevent memory leaks
    fclose(infile);
    free(temp);
    return 0;
}
