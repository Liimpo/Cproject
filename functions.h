#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//#define PNG_SETJMP_NOT_SUPPORTED

#include <png.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct pixel
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

typedef struct image
{
    Pixel **pixels;
    unsigned int height;
    unsigned int width;
} Image;

// This function actually writes out the PNG image file. The string 'title' is
// also written into the image file
void writeImage(char* filename, Image *img);

// This function reads an image from the filename source. Will store
// the image in the Pixel 2dim array and allocate the needed space.
void readImage(char *filename, Image *img);

// Takes in a pixel struct and converts it to a png_byte format
void pixelToRGB(png_bytep ptr, Pixel *pixel);
// same thing as pixelToRGB, only doing the opposite.
void RGBToPixel(png_bytep ptr, Pixel *pixel);
#endif
