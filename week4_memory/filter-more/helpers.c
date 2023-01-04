#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // make a nested loop to get every pixcel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate every pixcel by adding them each other
            int sum = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            // after that result will be divided by 3
            float total = sum / 3.0;
            // and round the result and turn into integer
            int result = round(total);

            // and equailise the result to every image pixcel like image[i][j].rgbtRed or rgbtGreen or rgbtBlue
            image[i][j].rgbtRed = result;
            image[i][j].rgbtGreen = result;
            image[i][j].rgbtBlue = result;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // create a temporary temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // make a swap by using temp array
            temp[i][j] = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create temp Array for temporary
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j]; // copy everything inside image[i][j] to tempArray[i][j]
        }
    }

    // run nested loop again
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // make variable for every color and equalise them to 0
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            // and make float variable as equalise to 0.0
            float count = 0.0;

            // run nested loop to find neighbours
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // equalise x and y to new currentA and currentB integer variables
                    int currentX = i + x;
                    int currentY = j + y;

                    // check if there is valid neighbours
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // and equalise every current valuse to totalRed and totalGreen and totalBlue
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    count++;
                }
                // and get value inside temp[i][j] array after round the sum while totalRed divided by count
                temp[i][j].rgbtRed = round(totalRed / count);
                temp[i][j].rgbtGreen = round(totalGreen / count);
                temp[i][j].rgbtBlue = round(totalBlue / count);
            }
        }
    }
    // and finally copy everything inside temp[i][j] to image[i][j] array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width]; // create temp array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // create two dimensional array for representing Gx[][]
    int gX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    // create two dimensional array for representing Gy[][]
    int gY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // make variable for every color and equalise them to 0
            int redX = 0;
            int greenX = 0;
            int blueX = 0;
            int redY = 0;
            int greenY = 0;
            int blueY = 0;

            // run loop 3 times because of 3x3 box
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    // make a variable and equalise this i - 1 + x to currentX variable
                    int currentX = i - 1 + x;
                    int currentY = j - 1 + y;

                    // and check if there is valid value
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // reequalise variables to get after multiplying Gx array with image[][].rgbtRed or green or blue
                    redX += (image[currentX][currentY].rgbtRed * gX[x][y]);
                    greenX += (image[currentX][currentY].rgbtGreen * gX[x][y]);
                    blueX += (image[currentX][currentY].rgbtBlue * gX[x][y]);

                    // reequalise variables to get after multiplying Gy array with image[][].rgbtRed or green or blue
                    redY += (image[currentX][currentY].rgbtRed * gY[x][y]);
                    greenY += (image[currentX][currentY].rgbtGreen * gY[x][y]);
                    blueY += (image[currentX][currentY].rgbtBlue * gY[x][y]);
                }
            }

            // round after finishing square result of after Gx^2 + Gy^2
            int red = round(sqrt((redX * redX) + (redY * redY)));
            int green = round(sqrt((greenX * greenX) + (greenY * greenY)));
            int blue = round(sqrt((blueX * blueX) + (blueY * blueY)));

            // and check if red or green or blue greater than 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            // and equalise these colour names to temp array
            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;
        }
    }

    // finally copy everything from temp array to image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
