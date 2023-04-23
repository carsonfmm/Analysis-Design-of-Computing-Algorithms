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
 * Sorts array A[0..n-1] by brute force
 * and tracks the number of inversions
 * Input: An array A[0..n-1] of integers
 *        and the top index of the array
 * Output: The number of inversions that occurred
 */
int bruteForceAlgorithm ( int integer_array[], int top ) {

	int inversions = 0;

	// First for loop for comparision of elements
	for ( int i = 0; i < top; i++ ) {

		// Nested for loop for comparision of elements
		for ( int j = i + 1; j < top; j++ ) {

			// Check if element at index 'i' is greater then the element at index 'j'
			if ( integer_array[i] > integer_array[j] ) {

				// Increase the number of inversions by 1
				inversions = inversions + 1;

			}

		}

	}

	// Return the number of inversions
	return inversions;

}
