#include "helpers.h"
#include <stdio.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through 2D array
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Check for hexidecimal color value corresponding to 0 for Red
            if (image[h][w].rgbtRed == 0x00)
            {
                // Change to hex value of 255
                image[h][w].rgbtRed = 0xFF;
            }
        }
    }
}
