#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *rawFile = fopen(argv[1], "r");
    uint8_t buffer[512];
    bool foundJpeg = false;
    int counter = 0;
    char filename[8];
    FILE *img = NULL;

    while (fread(buffer, 1, 512, rawFile))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            foundJpeg = true;
        }

        if (foundJpeg == true)
        {
            if (counter != 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
            foundJpeg = false;
            counter++;
        }
        else if (counter != 0)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    fclose(img);
    fclose(rawFile);

    return 0;
}
