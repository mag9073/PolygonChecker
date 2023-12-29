#include "menu.h"



void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {

	int shapeChoice;

	do
	{
		printf_s("1. Triangle\n");
		printf_s("2. Rectangle\n");  //added the rectangle option to the menu
		printf_s("0. Exit\n");
		printf_s("Enter number: ");
		scanf_s("%1o", &shapeChoice);
		if (shapeChoice == 0 || shapeChoice == 1 || shapeChoice == 2)	// return 'shapeChoice' when shapeChoice is 1 or 0
			return shapeChoice;						// and leave the loop

		else			//else display error msg and get input agian.
		{
			puts("The input is not valid, please try again.\n");
			rewind(stdin);		// reset the input buffer 
		}

	} while (true);

}