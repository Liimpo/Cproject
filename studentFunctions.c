#include "studentFunctions.h"

	/*
	This function is used to find prime numbers for my zoom evaluating.
	Since I want to resize my pictures to their original sizes I need
	to find the lowest prime factors. I then multiply the prime factors.
	Starting with the largest prime factors first to be able to return
	zooming pixels that I am possible to resize to the original pic size
	but also having some options. (I try to return 3 different values all
	the time.)
	*/


void findingVals(int validpos[][1], int pos, int maximumVal)
{
	int temp = maximumVal, dividing = 2, tempHeight, options = 0, prime[MAXSIZE], primeCounter = 0, validCheck = 0;

	// Running this loop until temp is 1 because thats the lowest prime factor.
	// The loop is done with the original width or size of the picture.
	while (temp != 0)
	{
		if (temp % dividing != 0) //Checking if its evenly divided. If not divided is added by 1. Until it is dividable.
			dividing = dividing + 1;
		else
		{
			temp = temp / dividing;
			prime[primeCounter] = dividing; // I want to store the prime factors in an array.
			primeCounter++; // Expanding the array with 1.
			if (temp == 1) // Since the lowest val I can get is 1 I have to hardcode this.
				temp = 0;
		}
	}

	tempHeight = maximumVal - pos; //This is to know where my chosen spot is in the picture.
	temp = 1;

	// Check valid zooms. Starting from the largest prime factor to the smallest.
	// Thats why this for loop is starting at the maximum index of my array.
	// loop is complete when all the prime factors have been evaluated.
	for (int i = primeCounter - 1; i >= 0; i--)
	{
		temp *= prime[i];
		// This if statement is here to give me a number of valid values on temp.
		// If temp is larger than what is possible to zoom in the picture I should not
		// accept that value in my further calculations.
		if (temp < tempHeight)
			validCheck++;
	}

	temp = prime[0]; // Setting temp to the smallest prime in my array.

	// Starting at the largest number again. This is to see if all the primes in my array
	// are the same. If the smallest are the same as the largest. All of the prime factors
	// are the same.
	for (int i = primeCounter - 1; i >= 0; i--)
	{
		if (temp == prime[i])
			temp = prime[i];
		else
			i = 0;
	}

	// This is my sorting algoritm to sort my prime factors in my array because I want
	// them in decreasing order. Doing it with bubblesort.
	for (int i = 0; i < primeCounter - 1; i++)
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

	/* This is the loop that is giving me the values I am going to return to my zoom func.
		 Since I got 3 options I want it to be ran 3 times. This loop is multiplying prime
		 factors to get the largest number possible. After each instance of this loop is ran
		 options is added by one which is making the loop not considering the smallest prime
		 factor thus giving me the largest available number out of my given prime factors.

		 Because the for loop is evaluating against (validcheck-options) I will never get
		 out of my bounds since I earlier is making sure the positions are inside my picture.
	*/
	while (options < 3)
	{
		temp = 1;
		for (int i = 0; i < validCheck-options; i++)
		{
			temp *= prime[i];
		}
		// Storing my 3 largest zoomOptions in validpos.
		validpos[options][0] = temp;
		options++;
	}
}

void plumbus(Image *zoom)
{
	int Xenlarger = 1, Yenlarger = 1, temp = 0, counter = 0, tempX, tempY, zoomOption = -1;
	int validXY, zoomTemp = 0, optionPicker = FALSE, Xchecker = FALSE, Ychecker = FALSE;
	int zoomOptionsY[3][1], zoomOptionsX[3][1];

	printf("Please specify the pixelposition where u want to start your zoom.\n");
	printf("You will get options how you can zoom your picture.\n");
	printf("Your picture is %dx%d. Please enter a X and Y inside your pixel range.\n", zoom->width, zoom->height);

	while (!optionPicker)
	{
		validXY = FALSE;
		while (!validXY)
		{
			printf("Pixel X val: ");
			scanf("%d", &tempX);
			getchar();

			printf("Pixel Y val: ");
			scanf("%d", &tempY);
			getchar();
			// This if-statements is making sure I input valid inputs inside the picture.
			if (tempX < zoom->width && tempY < zoom->height)
				validXY = TRUE;
			else
				printf("ERROR! Inputed X or Y is outside the picture\n");
			if (validXY)
			{
				findingVals(zoomOptionsY, tempY, zoom->height);
				findingVals(zoomOptionsX, tempX, zoom->width);
			}
		}

		// Checking if width or height is the largest. If height is big the new X val 
		// should be larger than the Y val to keep the optimal zoom options. 
		for (int i = 0; i < 3; i++)
		{
			if (zoom->width > zoom->height && zoomOptionsX[i][0] < zoomOptionsY[i][0])
			{
				temp = zoomOptionsX[i][0];
				zoomOptionsX[i][0] = zoomOptionsY[i][0];
				zoomOptionsY[i][0] = temp;
			}
		}

		// Checking if the width or height is inbetween the maximum range or not.
		// If it is outside the range it should lower itself with the next val.
		for (int i = 1; i < 3; i++)
		{
			counter = i;
			if (tempX + zoomOptionsX[counter-1][0] > zoom->width)
			{
				while (tempX + zoomOptionsX[i-1][0] > zoom->width)
				{
					zoomOptionsX[i-1][0] = zoomOptionsX[counter][0];
					counter++;
				}
			}
		}
		/* This for loop is making sure I always get the right proportions. If its a picture
			 that is more wider I am giving my current options Y-value the next one since I
			 get the values in descending order. Once I've checked the width I check the height
			 there I change my X-value instead to keep my proportions.
		*/
		for (int i = 0; i < 2; i++)
		{
			if (zoom->width > zoom->height && zoomOptionsX[i][0] == zoomOptionsY[i][0])
				zoomOptionsY[i][0] = zoomOptionsY[i+1][0];

			if (zoom->height > zoom->width && zoomOptionsX[i][0] == zoomOptionsY[i][0])
				zoomOptionsX[i][0] = zoomOptionsX[i+1][0];
		}

		// This is printing the options based on where u chosed to start
		printf("If you want a proportional zooming. Your zooming options are\n");
		printf("==========================\n");

		for (int i = 0; i < 3; i++)
		{
			printf("%d. ", i+1);
			printf("%dx%d\n", zoomOptionsX[i][0], zoomOptionsY[i][0]);
			printf("========================\n");
		}

		// This while loop is ran to make sure the user doesnt input something outside 3.
		do
		{
			scanf("%d" , &zoomOption);
			getchar();
			if (zoomOption < 1 || zoomOption > 3)
				printf("Wrong value. Enter 1-3\n");
			else
			{
				optionPicker = TRUE; //This is put to TRUE to not run the while loop again.
				zoomOption--; // I lower with one because of how the indexing works.
				printf("You are now going to zoom your picture at the position: %dx%d\n", tempX, tempY);
				printf("You will zoom an area with the size of: %dx%d Pixels. Press a key to continue..", zoomOptionsX[zoomOption][0], zoomOptionsY[zoomOption][0]);
			}
		}while (zoomOption < 0 || zoomOption > 2); // I need to have the 0 and 2 here because I lower my zoomOption with 1.

		// 20 pixels is the closest to a side you can go.
		if (zoomOptionsY[zoomOption][0] < 20 || zoomOptionsX[zoomOption][0] < 20)
		{
			printf("To get a better zoom please lower your X or Y val. Press a key to continue\n");
			optionPicker = FALSE;
		}
		getchar();
	}

	/* This section of this function is creating the matrix based on my picked values
		 It then enlargens it to get back to my starting size. Therefore I need to find
		 values that I am going to multiply with my chosen zoom option.
	*/
	
	// Since I want to check both my X and Y vals I use a temp for both of them callsed 
	// zoomTemp. I start with the X enlarger.
	zoomTemp = zoomOptionsX[zoomOption][0];
	while (!Xchecker)
	{
		zoomTemp = zoomOptionsX[zoomOption][0] * Xenlarger;
		if (zoomTemp != zoom->width) //Running this until I reach my original width.
		{
			Xenlarger++;

			/* If it happens that I can't find any values to get back to the actual size
				 I need to swap my values back to their originals. There is a posibility that
				 I swapped these vals earlier in my code. I then set Xenlarger to 1 to restart
				 my finder.
			*/
			if (zoomTemp > zoom->width)
			{
				temp = zoomOptionsY[zoomOption][0];
				zoomOptionsY[zoomOption][0] = zoomOptionsX[zoomOption][0];
				zoomOptionsX[zoomOption][0] = temp;
				Xenlarger = 1;
			}
		}
		else
			Xchecker = TRUE; // True to end my loop.
	}

	// Now I do the same but to my Y instead.
	zoomTemp = zoomOptionsY[zoomOption][0];
	while (!Ychecker)
	{
		zoomTemp = zoomOptionsY[zoomOption][0] * Yenlarger;
		if (zoomTemp != zoom->height)
		{
			Yenlarger++;
		}
		else
			Ychecker = TRUE;
	}

	// Here I create my starting picture depending on the options the user picked.
	Pixel ** localMatrix = (Pixel**) malloc(sizeof(Pixel*) * zoomOptionsY[zoomOption][0]);

	for (int i = 0; i < zoomOptionsY[zoomOption][0]; i++)
	{
		localMatrix[i] = (Pixel*) malloc(sizeof(Pixel) * zoomOptionsX[zoomOption][0]);
		for (int j = 0; j < zoomOptionsX[zoomOption][0]; j++)
		{
			localMatrix[i][j].r = zoom->pixels[i+tempY][j+tempX].r;
			localMatrix[i][j].g = zoom->pixels[i+tempY][j+tempX].g;
			localMatrix[i][j].b = zoom->pixels[i+tempY][j+tempX].b;
		}
	}

	for (int i = 0; i < zoom->height; i++)
		free(zoom->pixels[i]);
	free(zoom->pixels);

	// Setting up the new vals in the Image struct.
	zoom->pixels = localMatrix;
	zoom->height = zoomOptionsY[zoomOption][0];
	zoom->width = zoomOptionsX[zoomOption][0];

	// This is resizing the matrix to get back to the starting size.
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
	// This is 60 chars long because I add .png at the end of it.
	// I want to add .png myself to make it easier for the user.
	system("clear");
	printf("Please enter the name of your file you want to save without the png extension. (max 60 char long.)\n");
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
			i = MAXSIZE;

			printf("Saving PNG. Press a key to continue.");
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
			temp = swap.pixels[i][j].g; // Storing the green value in a temp variable.
			swap.pixels[i][j].g = swap.pixels[i][j].r; // Replacing green with red.
			swap.pixels[i][j].r = swap.pixels[i][j].b; // Replacing red with blue.
			swap.pixels[i][j].b = temp; // Replacing blue with green.
		}
	}

	system("clear");
	printf("The colors of your picture have now been swapped.");
	getchar();
}

void skankHunt(Image invert)
{
	for (int i = 0; i < invert.height; i++)
	{
		for (int j = 0; j < invert.width; j++)
		{
			// To invert a color I just take the maximum RGB value and remove the current
			// value from it.
			invert.pixels[i][j].g = 255 - invert.pixels[i][j].g;
			invert.pixels[i][j].r = 255 - invert.pixels[i][j].r;
			invert.pixels[i][j].b = 255 - invert.pixels[i][j].b;
		}
	}

	system("clear");
	printf("The colors in your picture has now been inverted!");
	getchar();
}

void trumpster(Image *resize)
{
	int temp;

	/*
	 * I am creating a local matrix here where I want my rows to be the original width
	 * and the columns my original height. By doing so I rotate my picture 90-degrees.
	 * To get every color in its right spot I take the maximum value of each rgb value
	 * and lower them with my current j and i.
	*/
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

	// Swapping the height with width.
	temp = resize->height;
	resize->height = resize->width;
	resize->width = temp;
	resize->pixels = localMatrix;

	system("clear");
	printf("Your picture has now rotated!");
	getchar();
}

void abradolfLincler(Image *resize)
{
	int tempEnlarger, checkEnlarger = FALSE;
	while (!checkEnlarger) // I set the limit to enlarge a picture every instance to 15.
	{
		printf("Enter a multiplier to enlarge your picture. (Valid numbers integers between 1-15): ");
		scanf("%d", &tempEnlarger);
		getchar();

		if (tempEnlarger >= 1 && tempEnlarger <= 15)
			checkEnlarger = TRUE;
	}

	/*
		I am once again creating a local matrix. Although this time It should keep it
		original columns/rows but instead get bigger with a multiplier that the user
		inputted. To be able to keep the correct color in the correct pixel I divide
		in every position the current position with the value of my enlarger. Since the
		mathematical operand division works as it does I get the same value depending on
		my tempEnlarger variabel.
	*/
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

	system("clear");
	printf("Your picture has now been enlarged!");
	getchar();
}

// If the user tries to manipulate a picture without loading anything. This gets printed
void errorMessage()
{
	system("clear");
	printf("ERROR! Nothing to manipulate.\nPlease load a picture before manipulating.");
	getchar();
}
