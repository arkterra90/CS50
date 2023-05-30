#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // averages each pixel to a gray value
            float avg_gray = ((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3);

            // changes avg_gray to a rounded int to replace values of RGBTRIPLE
            image[h][w].rgbtRed = (int) round(avg_gray);
            image[h][w].rgbtGreen = (int) round(avg_gray);
            image[h][w].rgbtBlue = (int) round(avg_gray);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterates through each pixel in image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // assigns RGB values to const variables
            const int red = image[h][w].rgbtRed;
            const int green = image[h][w].rgbtGreen;
            const int blue = image[h][w].rgbtBlue;

            // Applies sepia algorithm to RGB and checks to make sure no
            // values over 255
            float new_red = .393 * red + .769 * green + .189 * blue;
            if (new_red > 255)
            {
                new_red = 255;
            }
            float new_green = .349 * red + .686 * green + .168 * blue;
            if (new_green > 255)
            {
                new_green = 255;
            }
            float new_blue = .272 * red + .534 * green + .131 * blue;
            if (new_blue > 255)
            {
                new_blue = 255;
            }

            image[h][w].rgbtRed = round(new_red);
            image[h][w].rgbtGreen = round(new_green);
            image[h][w].rgbtBlue = round(new_blue);

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        int k = width - 1;
        for (int w = 0; w < width / 2; w++)
        {
            // swap sort to reflect image
            RGBTRIPLE reflect = image[h][w];
            image[h][w] = image[h][k];
            image[h][k] = reflect;
            k--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // creates temp array for pixel averaging
    RGBTRIPLE blur[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            blur[h][w] = image[h][w];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float avg_red = 0;
            float avg_green = 0;
            float avg_blue = 0;
            int counter = 0;

            // gets values for pixels around pixel and checks if on edge or corner
            for (int hb = -1; hb < 2; hb++)
            {
                for (int wb = -1; wb < 2; wb++)
                {
                    if ((hb + h < 0) || (h + hb >= height))
                    {
                        continue;
                    }
                    if ((w + wb < 0) || (w + wb >+ width))
                    {
                        continue;
                    }

                    avg_red += blur[h + hb][w + wb].rgbtRed;
                    avg_green += blur[h + hb][w + wb].rgbtGreen;
                    avg_blue += blur[h + hb][w + wb].rgbtBlue;
                    counter++;
                }
            }
            image[h][w].rgbtRed = round(avg_red / counter);
            image[h][w].rgbtGreen = round(avg_green / counter);
            image[h][w].rgbtBlue = round(avg_blue / counter);
        }
    }
    return;
}
