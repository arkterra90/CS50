#include <cs50.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;

int jpeg_check(int size, uint8_t buffer[]);

int main(int argc, char *argv[])
{
    // check for only 1 command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // open input file raw_file to recover jpegs
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("no such file found\n");
        return 1;
    }

    // allocate pointer for new file
    FILE *jpg_file = NULL;


    // creates buffer array for iterating through blocks of 512 bytes
    uint8_t buffer[BLOCK_SIZE];

    // malloc for sprintf for filenaming of new jpegs
    char *new_filename = malloc(sizeof(char) * 8);
    if (new_filename == NULL)
    {
        printf("not enough memory for filename array\n");
        fclose(file);
        free(jpg_file);
        return 0;
    }

    int is_jpg = 0;
    int jpg_count = 0;
    int jpg_start = 0;
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // call jpeg check function
        is_jpg = jpeg_check(BLOCK_SIZE, buffer);
        if (is_jpg == 1)
        {
            if (jpg_count == 0)
            {
                // fwrite to first file
                jpg_start = 1;
                sprintf(new_filename, "%03i.jpg", jpg_count);
                jpg_file = fopen(new_filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, jpg_file);
                jpg_count++;
                continue;
            }

            if (jpg_count > 0)
            {
                // if first file written fclose previous file and start new file
                fclose(jpg_file);
                sprintf(new_filename, "%03i.jpg", jpg_count);
                jpg_file = fopen(new_filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, jpg_file);
                jpg_count++;
            }
        }

        else
        {
            //conntinue to write buffer to file
            if (jpg_start == 1)
            {
                fwrite(buffer, 1, BLOCK_SIZE, jpg_file);
            }

            if (is_jpg == 0)
            {
                continue;
            }
        }

    }
    // Close all open files and free malloc memory
    free(new_filename);
    fclose(file);
    fclose(jpg_file);

}

int jpeg_check(int size, uint8_t buffer[])
{
    // Checks for jpg file signature in first four blocks of each buffer
    if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}