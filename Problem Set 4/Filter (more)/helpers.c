#include "helpers.h"
#include <math.h>

int calculate_average(int all_g_x, int all_g_y);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = (int) round((image[i][j].rgbtBlue +
                            image[i][j].rgbtGreen +
                            image[i][j].rgbtRed) / 3.);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    int middle_of_width;

    for (int i = 0; i < height; i++)
    {
        middle_of_width = width / 2;

        for (int j = 0; j < middle_of_width; j++)
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
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int side_of_color_box = 3;
    int average_blue;
    int average_green;
    int average_red;
    int number_of_neighbors;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average_blue = 0;
            average_green = 0;
            average_red = 0;
            number_of_neighbors = 0;

            for (int row = i - 1, max_row = (row + side_of_color_box);
                 row < max_row; row++)
            {
                if (row < 0)
                {
                    continue;
                }
                if (row >= height)
                {
                    break;
                }

                for (int column = j - 1, max_column = (column + side_of_color_box);
                     column < max_column; column++)
                {
                    if (column < 0)
                    {
                        continue;
                    }
                    if (column >= width)
                    {
                        break;
                    }

                    average_blue += copy[row][column].rgbtBlue;
                    average_green += copy[row][column].rgbtGreen;
                    average_red += copy[row][column].rgbtRed;

                    number_of_neighbors++;
                }
            }

            image[i][j].rgbtBlue = (int) round(average_blue * 1. / number_of_neighbors);
            image[i][j].rgbtGreen = (int) round(average_green * 1. / number_of_neighbors);
            image[i][j].rgbtRed = (int) round(average_red * 1. / number_of_neighbors);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int side_of_color_box = 3;

    int sobel_operand;
    int g_x[] = {-1, 0, 1,
                 -2, 0, 2,
                 -1, 0, 1};
    int g_y[] = {-1, -2, -1,
                 0, 0, 0,
                 1, 2, 1};

    int average_blue_g_x;
    int average_green_g_x;
    int average_red_g_x;
    int average_blue_g_y;
    int average_green_g_y;
    int average_red_g_y;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sobel_operand = 0;

            average_blue_g_x = 0;
            average_green_g_x = 0;
            average_red_g_x = 0;
            average_blue_g_y = 0;
            average_green_g_y = 0;
            average_red_g_y = 0;

            for (int row = i - 1, max_row = (row + side_of_color_box);
                row < max_row; row++)
            {
                for (int column = j - 1, max_column = (column + side_of_color_box);
                        column < max_column; column++)
                {
                    if (row < 0 || row >= height ||
                        column < 0 || column >= width)
                    {
                        sobel_operand++; // Increase by 1
                    }
                    else
                    {
                        average_blue_g_x += copy[row][column].rgbtBlue * g_x[sobel_operand];
                        average_blue_g_y += copy[row][column].rgbtBlue * g_y[sobel_operand];
                        average_green_g_x += copy[row][column].rgbtGreen * g_x[sobel_operand];
                        average_green_g_y += copy[row][column].rgbtGreen * g_y[sobel_operand];
                        average_red_g_x += copy[row][column].rgbtRed * g_x[sobel_operand];
                        // Increase by 1
                        average_red_g_y += copy[row][column].rgbtRed * g_y[sobel_operand++];
                    }
                }
            }

            image[i][j].rgbtBlue = calculate_average(average_blue_g_x, average_blue_g_y);
            image[i][j].rgbtGreen = calculate_average(average_green_g_x, average_green_g_y);
            image[i][j].rgbtRed = calculate_average(average_red_g_x, average_red_g_y);
        }
    }
    return;
}

// Calculate average of color for new pixel using Sobel operator
int calculate_average(int all_g_x, int all_g_y)
{
    double temp_g_x = all_g_x * all_g_x;
    double temp_g_y = all_g_y * all_g_y;

    int res_both = (int) round(sqrt(1. * (temp_g_x + temp_g_y)));

    if (res_both > 255)
    {
        res_both = 255;
    }

    return res_both;
}