#include "helpers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate all image colours and uqualise them to sum
            int sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;

            // after finding sum and divide sum by 3.0 float number
            float total = sum / 3.0;
            // after result float number then round them and change float to integer
            int mean = round(total);

            // and equalise final result to all image colours
            image[i][j].rgbtBlue = mean;
            image[i][j].rgbtGreen = mean;
            image[i][j].rgbtRed = mean;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // use nested for loop to get pixcels inside image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // find sepiaRed total by using sepia formula and sum will be float
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            // after finding sum and round sum and change sum from float to integer
            int sumRed = round(sepiaRed);
            int sumGreen = round(sepiaGreen);
            int sumBlue = round(sepiaBlue);

            // check if sum is greater than 255
            // if sum greater than 255 then image[i][j].rgbtRed or Blue or Green will be equalised to 255
            if (sumRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else // else not greater than 255 then image[i][j].rgbtRed or Blue or Green will be equalised to sumRed or Blue or Green
            {
                image[i][j].rgbtRed = sumRed;
            }


            if (sumGreen > 255) //// if sum greater than 255 then image[i][j].rgbtRed or Blue or Green will be equalised to 255
            {
                image[i][j].rgbtGreen = 255;
            }
            else //// else not greater than 255 then image[i][j].rgbtRed or Blue or Green will be equalised to sumRed or Blue or Green
            {
                image[i][j].rgbtGreen = sumGreen;
            }


            if (sumBlue > 255) //// if sum greater than 255 then image[i][j].rgbtRed or Blue or Green will be equalised to 255
            {
                image[i][j].rgbtBlue = 255;
            }
            else //// else not greater than 255 then image[i][j].rgbtRed or Blue or Green will be equalised to sumRed or Blue or Green
            {
                image[i][j].rgbtBlue = sumBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // make temp variable as a 2 dimensional array with RGBTRIPLE[height][width] to
    RGBTRIPLE tempArray[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // swap pixcels from right to left and from the left to right but if column is odd then middle pixcel doesnt swap
            tempArray[i][j] = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tempArray[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // create tempArray for temporery
    RGBTRIPLE tempArray[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempArray[i][j] = image[i][j]; // copy everything inside image[i][j] to tempArray[i][j]
        }
    }

    // run nested loop again
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            // make variable for every color and equalise them to 0
            int tRed, tGreen, tBlue;
            tRed = tGreen = tBlue = 0;
            // and make float variable as equalise to 0.0
            float count = 0.0;

            // run nested loop to find neighbours
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    // equalise a and b to new currentA and currentB integer variables
                    int currentA = i + a;
                    int currentB = j + b;

                    // check if there is valid neighbours
                    if (currentA < 0 || currentA > (height - 1) || currentB < 0 || currentB > (width - 1))
                    {
                        continue;
                    }

                    // and equalise every current valuse to totalRed and totalGreen and totalBlue
                    tRed += image[currentA][currentB].rgbtRed;
                    tGreen += image[currentA][currentB].rgbtGreen;
                    tBlue += image[currentA][currentB].rgbtBlue;

                    count++;
                }
                // and get value inside tempArray[i][j] array after round the sum while totalRed divided by count
                tempArray[i][j].rgbtRed = round(tRed / count);
                tempArray[i][j].rgbtGreen = round(tGreen / count);
                tempArray[i][j].rgbtBlue = round(tBlue / count);
            }
        }
    }

    // and finally copy everything inside tempArray[i][j] to image[i][j] array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tempArray[i][j].rgbtRed;
            image[i][j].rgbtGreen = tempArray[i][j].rgbtGreen;
            image[i][j].rgbtBlue = tempArray[i][j].rgbtBlue;
        }
    }

    return;
}
