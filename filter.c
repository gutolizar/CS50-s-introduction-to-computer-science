#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)

        {
            // mude as cores para a média
            int rgbGray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = rgbGray;
            image[i][j].rgbtGreen = rgbGray;
            image[i][j].rgbtRed = rgbGray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // algoritmo sepia
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // defina a cor de sepia em 255 hex(ff)
            image[i][j].rgbtRed = (sepiaRed > 0xFF) ? 0xFF : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 0xFF) ? 0xFF : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 0xFF) ? 0xFF : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // mude metade do comptrimento da imagem (+1 devido as diferenças de indexação)
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // crie imagem temporária
    // utilize os pixels originais da imagem para criar os pixels blur na imagem temporária
    double mediar = 0;
    double mediag = 0;
    double mediab = 0;
    int counter_n = 0;
    int matrixsize = 1;

    //verifique a matriz
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //zere as médias e a contagem
            mediar = 0;
            mediag = 0;
            mediab = 0;
            counter_n = 0;

            for (int l = i - matrixsize; l <= i + matrixsize; l++)
            {
                if (l < 0)
                {
                    l = 0;
                    if (l == height)
                    {
                        break;
                    }
                }
                for (int col = j - matrixsize; col <= j + matrixsize; col++)
                {
                    if (col == width) break;
                    if (col < 0)
                    {
                        col = 0;
                    }
                    counter_n++;

                    mediar += image[l][col].rgbtRed;
                    mediag += image[l][col].rgbtGreen;
                    mediab += image[l][col].rgbtBlue;
                }
            }
            // defina novo padrão para o pixel

            image[i][j].rgbtRed = (int)round(mediar /counter_n);
            image[i][j].rgbtGreen = (int)round(mediag /counter_n);
            image[i][j].rgbtBlue = (int)round(mediab /counter_n);
        }
    }
    return;
 }
