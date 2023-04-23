#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

#include "A2.h"

// Name: Carson Mifsud
// Date: 2021-02-20
// Assignment: 2

// Declaration of global variables for quick hull algorithm
float hullx[30000];
float hully[30000];
int counter = 0;

/* 
 * Solves convex hull problem via
 * quick hull algorithm
 * Input: Arrays A[0..n-1] and B[0..n-1], with x-coordinates
 * 		  sorted in ascending order and the total number of
 * 		  points. Also the left-most and right-most points
 * 		  adn the side of the line they are located on
 * Output: The number of extreme points along
 *         with coordinates
 */
void quickHull ( float float_arrayX[], float float_arrayY[], int n, float p1x, float p1y, float p2x, float p2y, int side ) {

	int lineDistance = -1;
	int max_dist = 0;
	float upperLower = 0;
	int return_val = 0;
	float temporary = 0;
	int i = 0;

	// For loop to iterate through points and find the point farthest away from the line
	for ( i = 0; i < n; i++ ) {

		// Calculate the distance of the line
		temporary = abs ((float_arrayY[i] - p1y) * (p2x - p1x) - (p2y - p1y) * (float_arrayX[i] - p1x));

		// Calculate if the point is above or below the line
		upperLower = (float_arrayY[i] - p1y) * (p2x - p1x) - (p2y - p1y) * (float_arrayX[i] - p1x);

		// Condition check for the value of upperLower
		if (upperLower > 0) {
			return_val = 1;
		} else if (upperLower < 0) {
			return_val = -1;
		} else {
			return_val = 0;
		}

		if ( return_val == side && temporary > max_dist ) {
			lineDistance = i; 
			max_dist = temporary; 
		}

	}

	// If there are no more points, add extreme point to the convex hull
	if ( lineDistance == -1 ) {

		hullx[counter] = p1x;
		hully[counter] = p1y;
		counter = counter + 1;
		hullx[counter] = p2x;
		hully[counter] = p2y;
		counter = counter + 1;
		return;

	}

	// (y2-y1) * x + (x1-x2) * y - (y2*x1 - y1*x2 )
	upperLower = ( p2y - float_arrayY[lineDistance]) * (p1x - float_arrayX[lineDistance]) - (p1y - float_arrayY[lineDistance]) * (p2x - float_arrayX[lineDistance] );

	// Condition check for the value of upperLower
	if ( upperLower > 0 ) {
		return_val = 1;
	} else if ( upperLower < 0 ) {
		return_val = -1;
	} else {
		return_val = 0;
	}

	// Recursive call for the two hulls
	quickHull ( float_arrayX, float_arrayY, n, float_arrayX[lineDistance], float_arrayY[lineDistance], p1x, p1y, -(return_val) );

	// (y2-y1) * x + (x1-x2) * y - (y2*x1 - y1*x2 )
	upperLower = ( p1y - float_arrayY[lineDistance]) * (p2x - float_arrayX[lineDistance]) - (p2y - float_arrayY[lineDistance]) * (p1x - float_arrayX[lineDistance] );

	// Condition check for the value of upperLower
	if ( upperLower > 0 ) {
		return_val = 1;
	} else if ( upperLower < 0 ) {
		return_val = -1;
	} else {
		return_val = 0;
	}

	// Recursive call for the two hulls
	quickHull ( float_arrayX, float_arrayY, n, float_arrayX[lineDistance], float_arrayY[lineDistance], p2x, p2y, -(return_val) );

}

/* 
 * Solves convex hull problem via
 * quick hull algorithm
 * Input: Arrays A[0..n-1] and B[0..n-1], with x-coordinates
 * 		  sorted in ascending order and the total number of
 * 		  points
 * Output: The number of extreme points along
 *         with coordinates
 */
int convexHullQuickHull ( float float_arrayX[], float float_arrayY[], int n ) {

	int convexPoints = 0;
	int Xmin = 0;
	int Xmax = 0;
	float temporary = 0;
	float temporary2 = 0;
	int i = 0;
	int j = 0;

	// If there are less than three points, a convex hull is not possible
	if ( n < 3 ) {
		return convexPoints;
	}

	// Find the left-most and right-most values of x-coordinates
	for ( i = 1; i < n; i++ ) { 
		if ( float_arrayX[i] < float_arrayX[Xmin] ) {
			Xmin = i;
		}
		if ( float_arrayX[i] > float_arrayX[Xmax] ) {
			Xmax = i;
		}
	}

	// Recursively find convex hull points on both sides of the line
	quickHull ( float_arrayX, float_arrayY, n, float_arrayX[Xmin], float_arrayY[Xmin], float_arrayX[Xmax], float_arrayY[Xmax], 1 );
	quickHull ( float_arrayX, float_arrayY, n, float_arrayX[Xmin], float_arrayY[Xmin], float_arrayX[Xmax], float_arrayY[Xmax], -1 );

	// Order Extreme Points by their x-coordinates
	for ( i = 0; i < counter; i++ ) {

		for ( j = 0; j < counter; j++ ) {

			if ( i != j ) {

				if ( (hullx[i] < hullx[j]) || ((hullx[i] == hullx[j]) && (hully[i] < hully[j])) ) {

					temporary = hullx[i];
					hullx[i] =  hullx[j];
					hullx[j] = temporary;
					temporary2 = hully[i];
					hully[i] =  hully[j];
					hully[j] = temporary2;

				}

			}

		}
		
	}

	// Print the number of extreme points and their coordinates
	for ( i = 0; i < counter - 1; i++ ) {

		for ( j = i + 1; j < counter; j++ ) {

			if ( (hullx[i] == hullx[j]) && (hully[i] == hully[j]) ) {

				printf ( "Extreme Point #%d: (%.1lf,%.1lf)\n", convexPoints+1, hullx[j], hully[j] );
				convexPoints = convexPoints + 1;

			}
		}
	}

	printf ("\n");

	// Return the number of extreme points
	return convexPoints;

}
