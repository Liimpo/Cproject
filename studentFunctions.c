#include "studentFunctions.h"

void findingVals(int validpos[][2], int pos, int maximumVal)
{
	int temp = maximumVal;
	int diving = 2;
	int tempHeight;
	int options = 0;
	int prime[MAXSIZE];
	int primeCounter = 0;
	int counter = 0;
	int checker = FALSE;
	int validCheck = 0;

	while (temp!=0)
	{
		if (temp % diving != 0)
			diving = diving + 1;
		else
		{
			temp = temp / diving;
			prime[primeCounter] = diving;
			primeCounter++;
			if (temp == 1)
				temp = 0;
		}
	}
	tempHeight = maximumVal - pos;
	temp = 1;
	// Check valid zooms.
	while (!checker)
	{
		for ( int i = primeCounter-1; i >= 0; i--)
		{
			temp *= prime[i];
			if (temp < tempHeight)
				validCheck++;
			else if (temp >= tempHeight)
				checker = TRUE;
		}
	}

	getchar();
		temp = prime[0];
	if (validCheck >= 3)
		options = 0;

	for ( int i = primeCounter-1; i >= 0; i--)
	{
		if (temp == prime[i])
		{
			temp = prime[i];
			counter++;
		}
		else
			i = 0;
	}

	for ( int i = 0; i < primeCounter-1; i++)
	{
		for (int j = 0; j < primeCounter - i - 1; j++)
		{
			if (prime[j] < prime[j+1])
			{
				temp = prime[j];
				prime[j] = prime[j+1];
				prime[j+1] = temp;
			}
		}
	}
	for (int i = 0; i < primeCounter; i++)
	{
		printf("%d\n", prime[i]);
	}
	while (options < 3) //(counter!= primeCounter))
	{
		temp = 1;
		for (int i = 0; i < validCheck-options; i++)
		{
			temp *= prime[i];
			printf("%d-", temp);
		}
		printf("%d\n", temp);
		validpos[options][1] = temp;
		options++;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", validpos[i][1]);
	}
	getchar();
}



void plumbus(Image *zoom)
{
	int temp = 0;
	int counter = 0;
	int tempX, tempY;
	int zoomOption = 0;
  int optionPicker = FALSE;
	//int zoomHeight, zoomWidth;
	int Xchecker = FALSE;
	int Ychecker = FALSE;
	int zoomOptionsY[3][2], zoomOptionsX[3][2];

	printf("Please specify the pixelposition where u want to start your zoom .\n");
	printf("You will get options how you can zoom your picture.\n");
	printf("Your picture is %dx%d. Please enter a X and Y inside your pixel range.\n", zoom->width, zoom->height);

	while (!optionPicker)
	{
	printf("Pixel X val: ");
	scanf("%d", &tempX);
	getchar();
	printf("Pixel Y val: ");
	scanf("%d", &tempY);
	getchar();
	findingVals( zoomOptionsY, tempY, zoom->height);
	findingVals( zoomOptionsX, tempX, zoom->width);

	// Checking if width or height is the largest. If height is big the new X val 
	// should be larger than the Y val to keep the optimal zoom options. 
	for (int i = 0; i < 3; i++)
	{
		if (zoom->width > zoom->height && zoomOptionsX[i][1] < zoomOptionsY[i][1])
		{
			temp = zoomOptionsX[i][1];
			zoomOptionsX[i][1] = zoomOptionsY[i][1];
			zoomOptionsY[i][1] = temp;
		}
	}

	// Checking if the width or height is inbetween the maximum range or not.
	// If it is outside the range it should lower itself with the next val.
	for (int i = 1; i < 3; i++)
	{
		if (tempX + zoomOptionsX[i-1][1] > zoom->width)
		{
			zoomOptionsX[i-1][1] = zoomOptionsX[i][1];
		}
	}
	printf("\n%d\n", counter);
	printf("%d -- %d -- %d\n", zoomOptionsX[0][1], zoomOptionsX[0][1], zoomOptionsX[0][1]);

	for (int i = 0; i < 2; i++)
	{
		if (zoom->width > zoom->height && zoomOptionsX[i][1] == zoomOptionsY[i][1])
		{
			zoomOptionsY[i][1] = zoomOptionsY[i+1][1];
			counter++;
		}
		if (zoom->height > zoom->width && zoomOptionsX[i][1] == zoomOptionsY[i][1])
		{
			zoomOptionsX[i][1] = zoomOptionsX[i+1][1];
			counter++;
		}
	}
	printf("\n%d\n", counter);
	// This is printing the options based on where u chosed to start
	printf("If you want a proportional zooming. Your zooming options are\n");
	printf("==========================\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d. ", i+1);
		printf("%dx%d\n", zoomOptionsX[i][1], zoomOptionsY[i][1]);
		printf("========================\n");
	}
	scanf("%d" , &zoomOption);
	zoomOption--;
	optionPicker = TRUE;

	if (zoomOptionsY[zoomOption][1] < 10 || zoomOptionsX[zoomOption][1] < 10)
	{
		printf("To get a better zoom please lower your X or Y val.\n");
		optionPicker = FALSE;
	}
	printf("%d\n", zoomOptionsX[zoomOption][1]);
	getchar();
	}

	int zoomTemp = 0;
	int Xenlarger = 1, Yenlarger = 1;
	zoomTemp = zoomOptionsX[zoomOption][1];
	while (!Xchecker)
	{
		zoomTemp = zoomOptionsX[zoomOption][1] * Xenlarger;
		if (zoomTemp != zoom->width)
		{
			Xenlarger++;
			printf("%d\n", zoomTemp);
			getchar();
			if (zoomTemp > zoom->width)
			{
				printf("Yo");
				temp = zoomOptionsY[0][1];
				zoomOptionsY[0][1] = zoomOptionsX[0][1];
				zoomOptionsX[0][1] = temp;
				Xenlarger = 1;
			}
		}
		else
			Xchecker = TRUE;
	}

	zoomTemp = zoomOptionsY[0][1];
	while (!Ychecker)
	{
		zoomTemp = zoomOptionsY[0][1] * Yenlarger;
		if (zoomTemp != zoom->height)
		{
			Yenlarger++;
		}
		else
			Ychecker = TRUE;
	}
printf("%d\n%d\n", tempY, tempX);
getchar();
	Pixel ** localMatrix = (Pixel**) malloc(sizeof(Pixel*) * zoomOptionsY[0][1]);

	for (int i = 0; i < zoomOptionsY[0][1]; i++)
	{
		localMatrix[i] = (Pixel*) malloc(sizeof(Pixel) * zoomOptionsX[0][1]);
		for (int j = 0; j < zoomOptionsX[0][1]; j++)
		{
			localMatrix[i][j].r = zoom->pixels[i+tempY][j+tempX].r;
			localMatrix[i][j].g = zoom->pixels[i+tempY][j+tempX].g;
			localMatrix[i][j].b = zoom->pixels[i+tempY][j+tempX].b;
		}
	}

	for (int i = 0; i < zoom->height; i++)
		free(zoom->pixels[i]);
	free(zoom->pixels);

	zoom->pixels = localMatrix;
	zoom->height = zoomOptionsY[0][1];
	zoom->width = zoomOptionsX[0][1];


	localMatrix = (Pixel**) malloc(sizeof(Pixel*) * zoom->height * Yenlarger);

	for (int i = 0; i < zoom->height * Yenlarger; i++)
	{
		localMatrix[i] = (Pixel*) malloc(sizeof(Pixel) * zoom->width * Xenlarger);
		for (int j = 0; j < zoom->width * Xenlarger; j++)
		{
			localMatrix[i][j].r = zoom->pixels[i/Yenlarger][j/Xenlarger].r;
			localMatrix[i][j].g = zoom->pixels[i/Yenlarger][j/Xenlarger].g;
			localMatrix[i][j].b = zoom->pixels[i/Yenlarger][j/Xenlarger].b;
		}
	}
	for (int i = 0; i < zoom->height; i++)
		free(zoom->pixels[i]);
	free(zoom->pixels);

	zoom->pixels = localMatrix;
	zoom->height = zoom->height * Yenlarger;
	zoom->width = zoom->width * Xenlarger;
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
			localMatrix[i][j].r = resize->pixels[(resize->height-1)-j][(resize->width-1)-i].r;
			localMatrix[i][j].g = resize->pixels[(resize->height-1)-j][(resize->width-1)-i].g;
			localMatrix[i][j].b = resize->pixels[(resize->height-1)-j][(resize->width-1)-i].b;
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
	int tempEnlarger, checkEnlarger = FALSE;
	while (!checkEnlarger)
	{
		printf("Enter a multiplier to enlarge your picture. (Valid numbers integers between 1-15): ");
		scanf("%d", &tempEnlarger);
		if (tempEnlarger >= 1 && tempEnlarger <= 15)
			checkEnlarger = TRUE;
	}

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
