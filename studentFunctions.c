#include "studentFunctions.h"

void plumbus(Image *zoom)
{

}

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
	int temp;
	Pixel ** localMatrix = (Pixel**) malloc(sizeof(Pixel*) * resize->width);
	for (int i = 0; i < resize->width; i++)
	{
		localMatrix[i] = (Pixel*) malloc(sizeof(Pixel) * resize->height);
		for (int j = 0; j < resize->height; j++)
		{
			localMatrix[i][j].r = resize->pixels[j][i].r;
			localMatrix[i][j].g = resize->pixels[j][i].g;
			localMatrix[i][j].b = resize->pixels[j][i].b;
		}
	}

	for (int i = 0; i < resize->height; i++)
		free(resize->pixels[i]);
	free(resize->pixels);


	temp = resize->height;
	resize->height = resize->width;
	resize->width = temp;
	resize->pixels = localMatrix;

	printf("Your picture has now rotated!\n");
	getchar();
}

void abradolfLincler(Image *resize)
{
	int tempEnlarger;
	printf("Enter larger: ");
	scanf("%d", &tempEnlarger);

	Pixel ** localMatrix = (Pixel**) malloc(sizeof(Pixel*) * (resize->height * tempEnlarger));
	for (int i = 0; i < (resize->height * tempEnlarger); i++)
	{
		localMatrix[i] = (Pixel*) malloc(sizeof(Pixel) * (resize->width * tempEnlarger));
		for (int j = 0; j < (resize->width * tempEnlarger); j++)
		{
			localMatrix[i][j].r = resize->pixels[i/tempEnlarger][j/tempEnlarger].r;
			localMatrix[i][j].g = resize->pixels[i/tempEnlarger][j/tempEnlarger].g;
			localMatrix[i][j].b = resize->pixels[i/tempEnlarger][j/tempEnlarger].b;
		}
	}
	
	for (int i = 0; i < resize->height; i++)
		free(resize->pixels[i]);
	free(resize->pixels);

	resize->height *= tempEnlarger;
	resize->width *= tempEnlarger;

	resize->pixels = localMatrix;

	printf("Your picture has now been enlarged!\n");
	getchar();

}
