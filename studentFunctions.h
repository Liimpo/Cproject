#ifndef STUDENTFUNCTIONS_H
#define STUDENTFUNCTIONS_H

#include "functions.h"

#define FALSE 0
#define TRUE 1
#define MAXSIZE 64

/*	
		Swaps the colours in every pixel.
		Red -> Green.
		Green -> Blue
		Blue -> Red
*/
void dildoSwaggins(Image swap);

void skankHunt(Image invert); // Inverts the colours in every pixel.

void removeWhitespace(char arr[]); // Removing the whitespace after taking an input with fgets.

void createExtension(char arr[]); // Adding ".png" to every file that is saved.

void trumpster(Image *resize); // This function is turning the picture 90-degrees.

void plumbus(Image *zoom); // This function is used when zooming.

/*
		This function is used inside of my zoom function. I use it to find viable X and Y zoom options
		based on how large the picture is and where the user wants to zoom in.
*/
void findingVals(int validpos[][1], int pos, int maximumVal);

void abradolfLincler(Image *resize); // This is my function to enlarge pictures.

void errorMessage(); //When a file isn't loaded and you try to manipulate a picture you get an error.

#endif
