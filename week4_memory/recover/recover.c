#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check if argv is equal to 2
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // make a file to open file which is given by cs50
    FILE *given_file = fopen(argv[1], "r");

    // check if file is not equal to NULL
    if (given_file == NULL)
    {
        printf("There is no found such file\n");
        return 2;
    }

    // make an array with unsigned char variable
    unsigned char buffer[512];

    // make a variable to count for increasing inside the loop to count images inside the card.raw
    int count_image = 0;

    // create new file to put images into that file
    FILE *new_file = NULL;

    // create filename variable to put files inside that file
    char filename[8];

    // make loop to read given file to search valid GPEG image file
    while (fread(buffer, sizeof(char), 512, given_file))
    {
        // check first 4 bytes to find out if this is image or not
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // this code will close previous .jpg file before findng new file
            if (count_image > 0)
            {
                fclose(new_file);
            }
            sprintf(filename, "%03i.jpg", count_image);

            // open new file as writing type do copy everything from filename to this new file
            new_file = fopen(filename, "w");

            // increase count_image in every iteration to find ot how many images there are inside given file
            count_image++;
        }

        // check if new_file is valid
        if (new_file != NULL)
        {
            // if file is valid then write everything from buffer to new_file
            fwrite(buffer, sizeof(char), 512, new_file);
        }
    }

    // and finally close every file which was opened for a while ago
    fclose(given_file);
    fclose(new_file);

    return 0;
}