#include "helpers.h"
#include <math.h>

// Convert image to grayscale / converta para grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)

        {
            // change colors to average / mude as cores para a média
            int rgbGray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = rgbGray;
            image[i][j].rgbtGreen = rgbGray;
            image[i][j].rgbtRed = rgbGray;
        }
    }
    return;
}

// Convert image to sepia / converta a imagem para sépia
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
    RGBTRIPLE temp[height][width];
    // make the temp image / crie imagem temporária
    // utilize os pixels originais da imagem para criar os pixels blur na imagem temporária
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    //set a counter and variables to each color / defina um contador e as variaveis para cada cor
    int counter_n = 0;
    float red, green, blue;
    red = green = blue = 0;

    /* start the loop on each pixel and the neighbours to insert into a temp imagem /
    inicie o padrão de loop sobre cada pixel e também os vizinhos para inserir numa imagem temporária*/
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (l >= 0 && k >= 0 && l < width && k < height)
                    {
                        // get the image value inside the variables for the colors/ pegue o valor da imagem e coloque nas variáveis das cores
                        red += temp[k][l].rgbtRed;
                        green += temp[k][l].rgbtGreen;
                        blue += temp[k][l].rgbtBlue;
                        counter_n++;
                    }
                }
            }
            /*the value on the color variables is divide by the counter which is the matrixsize and goes into the image /
            o valor das variáveis de cor é dividido pelo contador que é a tamanho da matriz e vai dentro da imagem*/
            image[i][j].rgbtRed = round(red / counter_n);
            image[i][j].rgbtGreen = round(green / counter_n);
            image[i][j].rgbtBlue = round(blue / counter_n);
            counter_n = 0;
            red = green = blue = 0;
        }
    }
    return;
}
