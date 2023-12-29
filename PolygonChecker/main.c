// fall 2022 group project - triangle and rectangle shapes and their properties! 
#include "menu.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

int main() {

	struct rectanglepoints points[NUMPOINT] = { 0,0 };        //array of structures, initialized to zero

	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();
		
		int shapeChoice = printShapeMenu();
		
		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			double triangleSides[3] = { 0, 0, 0 };
			double* triangleSidesPtr = getTriangleSides(triangleSides);
			char* resulttriangle = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", resulttriangle);
			anglesOfTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			break;

		case 2:  //added case 2 to the switch statement for the rectangle
			printf_s("Rectangle selected.\n"); //Users can enter their points in any order they want and the program will connect them without any crossover - this means that we completed the more points option 
			
			if (getRectanglePoints(points, NUMPOINT))  //if getRectanglePoints returns true and the points entered are valid
			{
				POINTS vector12 = vectors(points[1], points[0]); //we are comparing the first point the user entered to the other three
				POINTS vector14 = vectors(points[3], points[0]); //this is why points[0] is called in all three of the vector calculations
				POINTS vector13 = vectors(points[2], points[0]);

				double dotproduct1214 = dotproduct(vector12, vector14);
				double dotproduct1213 = dotproduct(vector12, vector13);
				double dotproduct1314 = dotproduct(vector13, vector14);

				double magnitude12 = magnitude(vector12); 
				double magnitude14 = magnitude(vector14);
				double magnitude13 = magnitude(vector13);

				double angle1 = angle(dotproduct1214, magnitude12, magnitude14);
				double angle2 = angle(dotproduct1213, magnitude12, magnitude13);
				double angle3 = angle(dotproduct1314, magnitude13, magnitude14);

				if (angle1 > angle2 && angle1 > angle3) //the program finds the largest angle between the three vectors (made up of the four points they entered) and connects the three points that make up the angle. This means that the connected points will not cross
				{
					POINTS point2 = points[0]; //these four statements order the points in the correct order based on the angles calculated
					POINTS point1 = points[1];
					POINTS point3 = points[3];
					POINTS point4 = points[2];


					doThesePointsMakeARectangle(point1, point2, point3, point4); //this function finds the distance between these points, determines if these distances make up a rectangle and prints if they are a rectangle or not. I added this function to make the program more repetitive

				}
				else if (angle2 > angle1 && angle2 > angle3)
				{
					POINTS point2 = points[0];
					POINTS point1 = points[1];
					POINTS point3 = points[2];
					POINTS point4 = points[3];

					doThesePointsMakeARectangle(point1, point2, point3, point4);

				}
				else if (angle3 > angle1 && angle3 > angle2)
				{
					POINTS point2 = points[0];
					POINTS point1 = points[2];
					POINTS point3 = points[3];
					POINTS point4 = points[1];

					doThesePointsMakeARectangle(point1, point2, point3, point4);
				}
			}

			break;

		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}



