#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "studentFunctions.h"

int main ()
{
	int fileIsLoaded = FALSE;
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

		/* This case will put you in the mode where you load a file into the program to manipulate
			 The maximum of letters available in the loaded file is 64 letters long. After the user
			 inputs the name of the file I remove the \n at the end of the input with my
			 removeWhitespace function.
		 */
		case 1:
			system("clear");
			printf("Please enter the complete filename (Max 64 letters long) of your picture.\n");
			fgets(fileName, MAXSIZE, stdin);
			removeWhitespace(fileName);
			readImage(fileName, &plain);
			fileIsLoaded = TRUE;
			break;

		// The second case is used to save the file on your system. To make it easier to the user I
		// make sure the file is saved as a .png by adding .png to the end of the input by the user.
		case 2:
			if (fileIsLoaded)
			{
				createExtension(fileName);
				writeImage(fileName, &plain);
			}
			else
			{
				system("clear");
				printf("ERROR! NO FILE TO SAVE.\nPlease load a picture before saving it.");
				getchar();
			}
			break;

		// The third case is used to invert the colors in your picture.
		case 3:
			if (fileIsLoaded)
				skankHunt(plain);
			else
				errorMessage();
			break;
		
		case 4:
			if (fileIsLoaded)
				dildoSwaggins(plain);
			else
				errorMessage();
			break;

		case 5:
			if (fileIsLoaded)
				trumpster(&plain);
			else
				errorMessage();
			break;

		case 6:
			if (fileIsLoaded)
				abradolfLincler(&plain);
			else
				errorMessage();
			break;

		case 7:
			if (fileIsLoaded)
				plumbus(&plain);
			else
				errorMessage();
			break;

		case 8:
			system("clear");
			printf("Now exiting...\n");
			runProgram = FALSE;
			break;

		default:
			printf("Please enter a valid option (1-8).");
			getchar();
			break;
		}
	}

	if (fileIsLoaded)
	{
		for (int i = 0; i < plain.height; i++)
			free(plain.pixels[i]);
		free(plain.pixels);
		return 0;
	}
}
