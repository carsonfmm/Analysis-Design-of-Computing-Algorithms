#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

#include "A2.h"

// Name: Carson Mifsud
// Date: 2021-02-20
// Assignment: 2

int main ( int argc, char **argv ) {

	// Variables used in the main function
	int inversions = 0;
	int inversions2 = 0;
	int i = 0;
	int k = 0;
	int extremePoints1 = 0;
	int extremePoints2 = 0;
	int integer_array[50000];
	float float_array[60000];
	float float_arrayX[30000];
	float float_arrayY[30000];
	int seperateX = 0;
	int seperateY = 0;
	float temporary = 0;
	float temporary2 = 0;

	// Variables to track the execution time of the functions
	struct timeb startTimeBrute;
	struct timeb endTimeBrute;
	struct timeb startTimeMerge;
	struct timeb endTimeMerge;
	struct timeb startBruteConvexHull;
	struct timeb endTimeBruteConvexHull;
	struct timeb startQuickHull;
	struct timeb endQuickHull;
	float totalTimeBrute;
	float totalTimeMerge;
	float totalTimeBruteConvexHull;
	float totalTimeQuickConvexHull;

    // Conditions for incorrect argument count
	if ( ( argc > 3 ) || ( argc < 3 ) ) {

		printf ( "Error\nFile format: ./A2 '(first_file).txt' '(second_file).txt'\n" );
		return ( -1 );
        
	}

	// File pointer
	FILE *fp;
	// Open given data_1.txt file for reading
	fp = fopen ( argv[1], "r" );

	// Loop through fp file and store all integers into the array
	while ( fscanf ( fp, "%d", &integer_array[i] ) != EOF ) {
		i = i + 1;
	}

	// Time is tracked once the function bruteForceAlgorithm is called. Time is ended once the function has finished executing and returned the number of inversions
	ftime ( &startTimeBrute );
	inversions = bruteForceAlgorithm ( integer_array, i );
	ftime ( &endTimeBrute );

	// Calculating total time and converting to milliseconds
	totalTimeBrute = ( endTimeBrute.time - startTimeBrute.time) * 1000 + ( endTimeBrute.millitm - startTimeBrute.millitm );

	// Print statement for number of inversions and execution time
	printf ( "\nThe Brute Force Algorithm has computed %d inversions.\nThe Brute Force Algorithm had an execution time of %f milliseconds.\n\n", inversions, totalTimeBrute );

	// Time is tracked once the function divideAndConquerMergesort is called. Time is ended once the function has finished executing and returned the number of inversions
	ftime ( &startTimeMerge );
	inversions2 = divideAndConquerMergesort ( integer_array, 0, i-1 );
	ftime ( &endTimeMerge );

	// Calculating total time and converting to milliseconds
	totalTimeMerge = ( endTimeMerge.time - startTimeMerge.time ) * 1000 + ( endTimeMerge.millitm - startTimeMerge.millitm );

	// Print statement for number of inversions and execution time
	printf ( "\nThe Merge Sort Algorithm has computed %d inversions.\nThe Merge Sort Algorithm had an execution time of %f milliseconds.\n\n\n", inversions2, totalTimeMerge );


	// File pointer
	FILE *fp2;
	// Open given data_1.txt file for reading
	fp2 = fopen ( argv[2], "r" );

	// Loop through fp file and store all x-coordinates into the first array and all y-coordinates into the second array
	while ( fscanf ( fp2, "%f", &float_array[k] ) != EOF ) {

		k = k + 1;

	}

	// Loop through fp file and store all x-coordinates into the first array and all y-coordinates into the second array
	for ( int f = 0; f < 60000; f++ ) {

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

	// Time is tracked once the function convexHullBruteForce is called. Time is ended once the function has finished executing and returned the number of extreme points
	ftime ( &startBruteConvexHull );
	extremePoints1 = convexHullBruteForce ( k/2, float_array );
	ftime ( &endTimeBruteConvexHull );

	// Calculating total time and converting to milliseconds
	totalTimeBruteConvexHull = ( endTimeBruteConvexHull.time - startBruteConvexHull.time ) * 1000 + ( endTimeBruteConvexHull.millitm - startBruteConvexHull.millitm );

	// Print statement for number of extreme points and execution time
	printf ( "\nThe Brute Force Convex Hull Algorithm has computed %d extreme points.\nThe Brute Force Convex Hull Algorithm had an execution time of %f milliseconds.\n\n\n", extremePoints1, totalTimeBruteConvexHull );

	// Sort the points in ascending order according to the x-coordinate
	for ( int i = 0; i < seperateY; i++ ) {

		for ( int j = 0; j < seperateY; j++ ) {

			if( i != j ) {

				if ( ( float_arrayX[i] < float_arrayX[j] ) || ( ( float_arrayX[i] == float_arrayX[j] ) && ( float_arrayY[i] < float_arrayY[j] ) ) ) {

					// Swap positions of coordinates
					temporary = float_arrayX[i];
					float_arrayX[i] =  float_arrayX[j];
					float_arrayX[j] = temporary;
					temporary2 = float_arrayY[i];
					float_arrayY[i] =  float_arrayY[j];
					float_arrayY[j] = temporary2;

				}

			}

		}
		
	}

	// Time is tracked once the function convexHullQuickHull is called. Time is ended once the function has finished executing and returned the number of extreme points
	ftime(&startQuickHull);
	extremePoints2 = convexHullQuickHull(float_arrayX, float_arrayY, seperateY);
	ftime(&endQuickHull);

	// Calculating total time and converting to milliseconds
	totalTimeQuickConvexHull = (endQuickHull.time - startQuickHull.time)/1000 + (endQuickHull.millitm - startQuickHull.millitm);

	// Print statement for number of extreme points and execution time
	printf ( "\nThe Quick Hull Convex Hull Algorithm has computed %d extreme points.\nThe Quick Hull Convex Hull Algorithm had an execution time of %f milliseconds.\n\n", extremePoints2, totalTimeQuickConvexHull );

	// Close files
	fclose ( fp );
	fclose ( fp2 );

	return ( 0 );

}
