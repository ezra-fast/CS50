#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float grayfilter; // unanimous grayscale value to be applied to all three 8-bit values.

    for (int z = 0; z < height; z++)
    {
        for (int u = 0; u < width; u++)
        {
            grayfilter = (round((image[z][u].rgbtBlue + image[z][u].rgbtGreen + image[z][u].rgbtRed) / 3.0));

            image[z][u].rgbtBlue = grayfilter;
            image[z][u].rgbtGreen = grayfilter;
            image[z][u].rgbtRed = grayfilter;
        }
    }
    return;
}


//function to limit the height of sepia values to <=255.

int under255(int value)
{
    if (value > 255)
    {
        value = 255;
    }
    return value;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int valuered;
    int valuegreen;
    int valueblue;

    for (int g = 0; g < height; g++)
    {
        for (int f = 0; f < width; f++)
        {
            valuered = under255(round(.393 * image[g][f].rgbtRed + .769 * image[g][f].rgbtGreen + .189 * image[g][f].rgbtBlue));
            valuegreen = under255(round(.349 * image[g][f].rgbtRed + .686 * image[g][f].rgbtGreen + .168 * image[g][f].rgbtBlue));
            valueblue = under255(round(.272 * image[g][f].rgbtRed + .534 * image[g][f].rgbtGreen + .131 * image[g][f].rgbtBlue));

            image[g][f].rgbtRed = valuered;
            image[g][f].rgbtGreen = valuegreen;
            image[g][f].rgbtBlue = valueblue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int holder[3];

    for (int h = 0; h < height; h++)
    {
        for (int d = 0; d < (width / 2); d++)
        {
            holder[0] = image[h][d].rgbtRed;
            holder[1] = image[h][d].rgbtGreen;
            holder[2] = image[h][d].rgbtBlue;

            image[h][d].rgbtRed = (image[h][width - d - 1].rgbtRed);
            image[h][d].rgbtGreen = (image[h][width - d - 1].rgbtGreen);
            image[h][d].rgbtBlue = (image[h][width - d - 1].rgbtBlue);

            image[h][width - d - 1].rgbtRed = holder[0];
            image[h][width - d - 1].rgbtGreen = holder[1];
            image[h][width - d - 1].rgbtBlue = holder[2];
        }
    }
    return;
}

//Function that performs the task of actually blurring pixels, to be called later: DONE?

int AppBlur(int n, int m, int height, int width, RGBTRIPLE image[height][width], int pos)
{
    int res = 0;
    float count = 0;

    for (int q = n - 1; q < (n + 2); q++)
    {
        for (int w = m - 1; w < (m + 2); w++)
        {
            if (q < 0 || w < 0 || q > height || w >= width)
            {
                continue;
            }
            if (pos == 0)
            {
                res = res + image[q][w].rgbtRed;
            }
            else if (pos == 1)
            {
                res = res + image[q][w].rgbtGreen;
            }
            else
            {
                res = res + image[q][w].rgbtBlue;
            }
            count += 1;
        }
    }
    return round(res / count);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; // Array as a copy of the original image.

    for (int t = 0; t < height; t++) // Beginning of copying loop.
    {
        for (int r = 0; r < width; r++) // Copying the colors per pixel into a copy array for program reference later.
        {
            copy[t][r].rgbtRed = image[t][r].rgbtRed;
            copy[t][r].rgbtGreen = image[t][r].rgbtGreen;
            copy[t][r].rgbtBlue = image[t][r].rgbtBlue;
        }
    }

    for (int n = 0; n < height; n++) // Looping through pixels in image and applying the AppBlur function to the copy (unaltered) pixels for Blur effect on image.
    {
        for (int m = 0; m < width; m++)
        {
            image[n][m].rgbtBlue = AppBlur(n, m, height, width, copy, 2);
            image[n][m].rgbtGreen = AppBlur(n, m, height, width, copy, 1);
            image[n][m].rgbtRed = AppBlur(n, m, height, width, copy, 0);
        }
    }

    return;
}
