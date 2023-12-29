#pragma once
#define NUMPOINT 4  // for the 4 points of rectangle 

#include <stdio.h>
#include <math.h>
#include <stdbool.h>



typedef struct rectanglepoints   //created a data structure for the 4 points of rectangle 
{
	double point_x;
	double point_y;
}POINTS;

//function prototypes
bool getRectanglePoints(POINTS pointarr[], int n);
char* isRectangle(double distA, double distB, double distC, double distD, double distE, double distF);
double rectangleDist(POINTS p, POINTS q);
double perimeterRectangle(double, double, double, double);
double CalculateArea(double dista, double distb);
POINTS vectors(POINTS a, POINTS b);
double dotproduct(POINTS a, POINTS b);
double magnitude(POINTS a);
double angle(double dotprod, double magA, double magB);
void doThesePointsMakeARectangle(POINTS a, POINTS b, POINTS c, POINTS d);

