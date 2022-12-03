#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;
    int new_value;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = (image[i][j].rgbtBlue +
                       image[i][j].rgbtGreen +
                       image[i][j].rgbtRed) / 3.0;
            new_value = (int) round(average);

            image[i][j].rgbtBlue = new_value;
            image[i][j].rgbtGreen = new_value;
            image[i][j].rgbtRed = new_value;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    short amount_color = 3;
    int new_values[amount_color];
    int max_bpp = 255;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // New red
            new_values[0] = (int) round((.393 * image[i][j].rgbtRed
                                         + .769 * image[i][j].rgbtGreen
                                         + .189 * image[i][j].rgbtBlue));
            // New green
            new_values[1] = (int) round((.349 * image[i][j].rgbtRed
                                         + .686 * image[i][j].rgbtGreen
                                         + .168 * image[i][j].rgbtBlue));
            // New blue
            new_values[2] = (int) round((.272 * image[i][j].rgbtRed
                                         + .534 * image[i][j].rgbtGreen
                                         + .131 * image[i][j].rgbtBlue));

            for (int k = 0; k < amount_color; k++)
            {
                if (new_values[k] > max_bpp)
                {
                    new_values[k] = max_bpp;
                }
            }

            image[i][j].rgbtRed = new_values[0];
            image[i][j].rgbtGreen = new_values[1];
            image[i][j].rgbtBlue = new_values[2];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy_image[i][j] = image[i][j];
        }
    }

    int side_of_color_box = 3;
    float capacity_of_colors;
    int start_of_height;
    int start_of_width;
    int average_red;
    int average_green;
    int average_blue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            capacity_of_colors = 0.F;

            start_of_height = i - 1;
            start_of_width = j - 1;

            average_red = 0;
            average_green = 0;
            average_blue = 0;

            for (int k = start_of_height; k < start_of_height + side_of_color_box; k++)
            {
                if (k < 0)
                {
                    continue;
                }
                if (k >= height)
                {
                    break;
                }

                for (int m = start_of_width; m < start_of_width + side_of_color_box; m++)
                {
                    if (m < 0)
                    {
                        continue;
                    }
                    if (m >= width)
                    {
                        break;
                    }

                    average_red += copy_image[k][m].rgbtRed;
                    average_green += copy_image[k][m].rgbtGreen;
                    average_blue += copy_image[k][m].rgbtBlue;

                    capacity_of_colors += 1.F;
                }
            }

            image[i][j].rgbtRed = (int) round(average_red / capacity_of_colors);
            image[i][j].rgbtGreen = (int) round(average_green / capacity_of_colors);
            image[i][j].rgbtBlue = (int) round(average_blue / capacity_of_colors);
        }
    }
    return;
}