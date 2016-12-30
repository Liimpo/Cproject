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
		
		case 4:
			dildoSwaggins(plain);
			break;

		case 5:
			trumpster(&plain);
			break;

		case 6:
			abradolfLincler(&plain);
			break;

		case 7:
			plumbus(&plain);
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


	//writeImage("test.png", &new);
	}
	for (int i = 0; i < plain.height; i++)
		free(plain.pixels[i]);
	free(plain.pixels);
	return 0;
}
