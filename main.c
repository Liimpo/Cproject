#include <stdio.h>
#include <stdlib.h>
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

		/* 
			This case will put you in the mode where you load a file into the program to manipulate
			The maximum of letters available in the loaded file is 64 letters long. After the user
			inputs the name of the file I remove the \n at the end of the input with my
			removeWhitespace function.
			You can only execute manipulations on pictures one picture at a time. So you need to save
			before you can load a new one.
		 */
		case 1:
			if (!fileIsLoaded)
			{
				system("clear");
				printf("Please enter the complete filename (Max 64 letters long) of your picture.\n");
				fgets(fileName, MAXSIZE, stdin);
				removeWhitespace(fileName);
				readImage(fileName, &plain);
				fileIsLoaded = TRUE;
			}
			else
			{
				system("clear");
				printf("Please save your current picture before loading another one..\nPress a key to continue..");
				getchar();
			}
			break;

		/*
			The second case is used to save the file on your system. To make it easier to the user I
			make sure the file is saved as a .png by adding .png to the end of the input by the user.
			If a file is saved fileIsLoaded is set to FALSE making sure I cant manipulate my now free'd
			picture.
		*/
		case 2:
			if (fileIsLoaded)
			{
				createExtension(fileName);
				writeImage(fileName, &plain);
				for (unsigned int i = 0; i < plain.height; i++)
					free(plain.pixels[i]);
				free(plain.pixels);
				fileIsLoaded = FALSE;
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
				picInverter(plain);
			else
				errorMessage();
			break;

		// The fourth case is used to swap the colors
		case 4:
			if (fileIsLoaded)
				picSwapper(plain);
			else
				errorMessage();
			break;

		// The fifth case is used to turn the picture 90-degrees
		case 5:
			if (fileIsLoaded)
				picRotation(&plain);
			else
				errorMessage();
			break;

		// The sixth case is used to enlarge
		case 6:
			if (fileIsLoaded)
				picEnlarger(&plain);
			else
				errorMessage();
			break;

		// Seventh case is used to zoom the picture
		case 7:
			if (fileIsLoaded)
				picZoom(&plain);
			else
				errorMessage();
			break;

		// The last case is used to exit the program.
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

	// I need to run a if-statement here because if I dont load a file and exit the program from the
	// menu I would free memory that is not allocated.
		return 0;
}
