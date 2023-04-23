#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

#include "A2.h"

// Name: Carson Mifsud
// Date: 2021-02-20
// Assignment: 2

/* 
 * Solves convex hull problem via
 * brute force
 * Input: A set of points S in a 2-dimensional plane
 *        and the total amount of pairs of coordinates
 * Output: The number of extreme points along
 *         with coordinates
 */
int convexHullBruteForce ( int count, float float_array[] ) {

	int total;
	int counterX;
	int counterY;
	int i;
	int j;
	int k;
	int final = 0;
	float temporary1;
	float temporary2;
	int point = 1;
	float temp_float_arrayX[100] = {0};
	float temp_float_arrayY[100] = {0};
	int extremePoints = 0;
	// Float arrays to store 30000 integers
	float float_arrayX[30000];
	float float_arrayY[30000];
	int seperateX = 0;
	int seperateY = 0;

	// Loop through fp file and store all x-coordinates into the first array and all y-coordinates into the second array
	for ( int f = 0; f < count*2; f++ ) {

		// x-coordinate
		if ( (f == 0) || (f % 2 == 0) ) {
			float_arrayX[seperateX] = float_array[f];
			seperateX = seperateX + 1;
		}

		// y-coordinate
		else {
			float_arrayY[seperateY] = float_array[f];
			seperateY = seperateY + 1;
		}

	}


	// First for loop for comparision of elements
	for ( i = 0; i < count; i++ ) {

		// Nested for loop for comparision of elements
		for ( j = 0; j < count; j++ ) {
			
			// Condition to avoid checking the same points
			if ( i != j ) {

				total = 0;
				counterX = 0;
				counterY = 0;

				// n < count
				for ( k = 0; k < count; k++ ) {

					// Condition to avoid checking the same points
					if ( !( k == i ) && !( k == j ) ) {

						total = total + 1;

						// (y2-y1) * x + (x1-x2) * y - (y2*x1 - y1*x2 ) < 0
						if ( ( ( (float_arrayY[j] - float_arrayY[i]) * float_arrayX[k] ) + ( (float_arrayX[i] - float_arrayX[j]) * float_arrayY[k] ) - ( ( float_arrayX[i]*float_arrayY[j] ) - ( float_arrayX[j]*float_arrayY[i] ) ) ) < 0 ) {

							counterY++;

						}

						// (y2-y1) * x + (x1-x2) * y - (y2*x1 - y1*x2 ) > 0
						if ( ( ( (float_arrayY[j] - float_arrayY[i]) * float_arrayX[k] ) + ( (float_arrayX[i] - float_arrayX[j]) * float_arrayY[k] ) - ( ( float_arrayX[i]*float_arrayY[j] ) - ( float_arrayX[j]*float_arrayY[i] ) ) ) > 0 ) {

							counterX++;

						}

						// If a distinct point was found, break out of the loop
						if ( ( counterX > 1 ) && ( counterY > 1 ) ) {
							break;
						}

					}

				}

				// If either counters equal the total, a convex hull is possible
				if ( ( counterX == total ) || ( counterY == total ) ) {

					int m = 0;

					// Iterate through all array values using the outer loop index 'i'
					while ( m <= 100 ) {

						// If there is a pair of points, break out of the loop
						if ( ( temp_float_arrayY[m] == float_arrayY[i] ) && ( temp_float_arrayX[m] == float_arrayX[i] ) ) {
							break;
						}

						// If the pair of points results in an extreme point, store the coordinate of the extreme point in a temporary array
						else if ( ( ( temp_float_arrayY[m] != float_arrayY[i] ) && ( temp_float_arrayX[m] != float_arrayX[i] ) ) && ( temp_float_arrayY[m] == 0 ) ) {

							temp_float_arrayX[m] = float_arrayX[i];
							temp_float_arrayY[m] = float_arrayY[i];
							break;

						}

						m = m + 1;

					}

					m = 0;

					// Iterate through all array values using the inner loop index 'j'
					while ( m <= 100 ) {

						// If there is a pair of points, break out of the loop
						if ( ( temp_float_arrayY[m] == float_arrayY[j] ) && ( temp_float_arrayX[m] == float_arrayX[j] ) ) {
							break;
						}

						// If the pair of points results in an extreme point, store the coordinate of the extreme point in a temporary array
						else if ( ( ( temp_float_arrayY[m] != float_arrayY[j] ) && ( temp_float_arrayX[m] != float_arrayX[j] ) ) && ( temp_float_arrayY[m] == 0 ) ) {

							temp_float_arrayX[m] = float_arrayX[j];
							temp_float_arrayY[m] = float_arrayY[j];
							break;

						}

						m = m + 1;

					}

				}

			}

		}

	}

	// Order Extreme Points by their x-coordinates
	for ( i = 0; i < 100; i++ ) {

		for ( j = 0; j < 100; j++ ) {

			if ( i != j ) {

				if ( ( temp_float_arrayX[i] < temp_float_arrayX[j] ) || ( ( temp_float_arrayX[i] == temp_float_arrayX[j] ) && ( temp_float_arrayY[i] < temp_float_arrayY[j] ) ) ) {

					temporary1 = temp_float_arrayX[i];
					temp_float_arrayX[i] =  temp_float_arrayX[j];
					temp_float_arrayX[j] = temporary1;
					temporary2 = temp_float_arrayY[i];
					temp_float_arrayY[i] =  temp_float_arrayY[j];
					temp_float_arrayY[j] = temporary2;

				}

			}

		}
		
	}

	// Loop printing the coordinates of the extreme points
	for ( final = 0; final < 100; final++ ) {

		if ( !(temp_float_arrayX[final] == 0) ) {

			printf ( "Extreme Point #%d: (%.1lf,%.1lf)\n", point, temp_float_arrayX[final],temp_float_arrayY[final] );
			extremePoints = extremePoints + 1;
			point = point + 1;

		}

	}

	return extremePoints;

}
