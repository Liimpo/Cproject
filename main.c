#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "studentFunctions.h"

int main ()
{
	int runProgram = TRUE;
	int menuOption = 0;
	char fileName[MAXSIZE];
	Image plain;
	//Image new;
	/*new.height = 512;
	/new.width = 1024;
	plain.height = 512;
	plain.width = 1024;
	new.pixels = (Pixel**) malloc(sizeof(Pixel*) * new.height);
	for(int i = 0; i < new.height; i++)
	{
	new.pixels[i] = (Pixel*) malloc(sizeof(Pixel) * new.width);
	}

	int counter1 = 0, counter2 = 0, counter3 = 0;
	plain.pixels = (Pixel**) malloc(sizeof(Pixel*) * plain.height);
	for(int i = 0; i < plain.height; i++)
	{
		plain.pixels[i] = (Pixel*) malloc(sizeof(Pixel) * plain.width);
		for(int j = 0; j < plain.width; j++)
		{
			plain.pixels[i][j].r = 255-(i/2);
			plain.pixels[i][j].g = j/4;
			plain.pixels[i][j].b = 0;
			counter1++;
		}
		counter2++;
	}
	counter1 = (plain.height - 1);
	for(int i = 0; i < plain.height; i++)
	{
		counter2 = (plain.width - 1);
		for(int j = 0; j < plain.width; j++)
		{
			new.pixels[i][j].r = plain.pixels[counter1][counter2].r;
			new.pixels[i][j].g = plain.pixels[counter1][counter2].g;
			new.pixels[i][j].b = plain.pixels[counter1][counter2].b;
			counter2--;
			counter3++;
		}
		counter1--;
	}
	printf("%d\n", counter1);
	printf("%d\n", counter2);
	printf("%d", counter3);
	getchar();*/
	readImage("test.png", &plain);
	printf("%d-%d", plain.height, plain.width);


	Pixel ** localMatrix = (Pixel**) malloc(sizeof(Pixel*) * 1024);
	for(int i = 0; i < 1024; i++)
	{
	localMatrix[i] = (Pixel*) malloc(sizeof(Pixel) * 512);
	for (int j = 0; j < 512; j++)
	{
		localMatrix[i][j].r = 255;
		localMatrix[i][j].g = 0;
		localMatrix[i][j].b = 0;
	}
	}
	for (int i = 0; i < plain.height; i++)
	{
		free (plain.pixels[i]);
	}
	free(plain.pixels);
	plain.height = 1024;
	plain.width = 512;
	plain.pixels = localMatrix;

	writeImage("hueheu.png", &plain);

	getchar();
	while (runProgram)
	{
		system("clear");

		printf("*********************************************");
		printf("\n*  Welcome to the Hi-res picture fugup      *");
		printf("\n*********************************************");
		printf("\n\n1. Load a picture to manipulate.");
		printf("\n2. Save your picture!");
		printf("\n3. This option is used if you want to invert the colors in your picture.");
		printf("\n4. Use this option to swap colors in you picture.");
		printf("\n5. Turn your picture 90 degrees.");
		printf("\n6. Enlarge your picture.");
		printf("\n7. Zoom picture.");
		printf("\n8. Exit program.\n");

		scanf("%d", &menuOption);
		getchar();
		switch (menuOption)
		{
		case 1:
			system("clear");
			printf("Please enter the filename (Max 64 letters long) of your picture\n");
			fgets(fileName, MAXSIZE, stdin);
			removeWhitespace(fileName);
			readImage(fileName, &plain);
			break;

		case 2:
			createExtension(fileName);
			writeImage(fileName, &plain);
			break;

		case 3:
			skankHunt(plain);
			break;

		case 5:
			trumpster(&plain);
			break;

		case 8:
			system("clear");
			printf("Now exiting...");
			getchar();
			runProgram = FALSE;
			break;

		default:
			printf("Please enter a valid option (1-8).");
			getchar();
			break;
		}


	printf("Saving PNG\n");
	//writeImage("test.png", &new);
	printf("hue\n");
	}

	for (int i = 0; i < plain.height; i++)
		free(plain.pixels[i]);
	free(plain.pixels);
	return 0;
}
