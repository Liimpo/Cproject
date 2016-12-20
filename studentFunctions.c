#include "studentFunctions.h"

//void turnAround(Image turn)
//{
//}

void removeWhitespace(char arr[])
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		if (arr[i] == '\0')
		{
			arr [i-1] = '\0';
			i = MAXSIZE;
		}
	}
}

void createExtension(char arr[])
{
	int temp = FALSE;
	while (!temp)
	{
		system("clear");
		printf("Please enter the name of your file you want to save. (max 60 char long.)\n");
		fgets(arr, MAXSIZE, stdin);

		for (int i = 0; i < (MAXSIZE-4); i++)
		{
			if (arr[i] == '\0')
			{
				arr[i-1] = '.';
				arr[i] = 'p';
				arr[i+1] = 'n';
				arr[i+2] = 'g';
				arr[i+3] = '\0';
				temp = TRUE;
				i = MAXSIZE;

				printf("\nSaving PNG");
				getchar();
			}
		}

		if (!temp)
		{
			printf("\n You entered a name that's too long. Please use less characters.\n");
			getchar();
		}
	}
}

void dildoSwaggins(Image swap)
{
	int temp;
	for (int i = 0; i < swap.height; i++)
	{
		for (int j = 0; j < swap.width; j++)
		{
			temp = swap.pixels[i][j].g;
			swap.pixels[i][j].g = swap.pixels[i][j].r;
			swap.pixels[i][j].r = swap.pixels[i][j].b;
			swap.pixels[i][j].b = temp;
		}
	}
}

void skankHunt(Image invert)
{
	for (int i = 0; i < invert.height; i++)
	{
		for (int j = 0; j < invert.width; j++)
		{
			invert.pixels[i][j].g = 255 - invert.pixels[i][j].g;
			invert.pixels[i][j].r = 255 - invert.pixels[i][j].r;
			invert.pixels[i][j].b = 255 - invert.pixels[i][j].b;
		}
	}
}

void trumpster(Image *resize)
{
/*	int tempWidth = resize->width * 2;
	int tempHeight = resize->height * 2;

Image temp;

	temp.pixels = (Pixel**)malloc(sizeof(Pixel*) * tempHeight);
	for (int i = 0; i < tempHeight; i++)
	{
		temp.pixels[i] = (Pixel*)malloc(sizeof(Pixel) * tempWidth);
	}

	for (int i = 0; i < resize->width; i++)
	{
		temp.pixels[i] = resize->pixels[i];
	}
	
	for (int i = 0; i < resize->height; i++)
		free(resize->pixels[i]);
	free(resize->pixels);
	resize->pixels = temp.pixels;
	
	resize->width = resize->width * 2;
	resize->height = resize->height * 2;
	printf("\n Value: %d", resize->width);
	printf("\n Value: %d", resize->height);
	getchar();
	*/
	Pixel ** localMatrix = (Pixel**) malloc(sizeof(Pixel*) * resize->width);
	for (int i = 0; i < resize->width; i++)
	{
		localMatrix[i] = (Pixel*) malloc(sizeof(Pixel) * resize->height);
	}
	printf("asd");
	free (resize);
	resize->pixels = localMatrix;
	for (int i = 0; i < resize->width; i++)
		free(localMatrix[i]);
	free (localMatrix);
}
