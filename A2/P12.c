#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

#include "A2.h"

// Name: Carson Mifsud
// Date: 2021-02-20
// Student ID: 1089936
// Assignment: 2

/* 
 * Merges two sorted arrays into one sorted array
 * and tracks the number of inversions
 * Input: An array A[0..n-1] of integers, the
 *        bottom, half and top indices of the array
 * Output: The number of inversions that occurred
 */
int merge ( int integer_array[], int bottom, int half, int top ) {
	
	// Declare and initialize all local variables
	int i = bottom;
	int j = half;
	int k = bottom;
	int p = half;
	int q = top;
	int counter;
	int temp_integer_array[50000];
	int inversions = 0;

	// while i < p and j < q do
	while ( ( i < p ) && ( j < q + 1 ) ) {

		// if B[i] <= C[j]
		if ( integer_array[i] <= integer_array[j] ) {

			// A[k] = B[i]; i = i + 1
			temp_integer_array[k] = integer_array[i];
			i = i + 1;
		
		}

		else {

			// else A[k] = C[j]; j = j + 1; inversions = inversions + 1
			temp_integer_array[k] = integer_array[j];
			j = j + 1;
			inversions = inversions + half - i;

		}

		// k = k + 1
		k = k + 1;

	}

	// if i = p
	if ( i == p ) {

		// copy C[j..q-1] to A[k..p+q-1]; k = k + 1
		for ( counter = j; counter < q + 1; counter++ ) {
			temp_integer_array[k] = integer_array[counter];
			k = k + 1;
		}

	}
	
	else {

		// copy B[i..p-1] to A[k..p+q-1]; k = k + 1
		for ( counter = i; counter < p + 1; counter++ ) {
			temp_integer_array[k] = integer_array[counter];
			k = k + 1;
		}

	}

	// copy A[k..p+q-1] to the temporary array
	for ( counter = bottom; counter < q + 1 ; counter++ ) {
		integer_array[counter] = temp_integer_array[counter];
	}

	// Return the number of inversions
	return inversions;

}

/* 
 * Sorts array A[0..⌊n/2⌋-1] by recursivly calling
 * divideAndConquerMergesort and tracks the number of inversions
 * Input: An array A[0..⌊n/2⌋-1] of integers, the
 *        bottom index and the top index of the array
 * Output: The number of inversions that occurred
 */
int divideAndConquerMergesort ( int integer_array[], int bottom, int top ) {

	int half = 0;
	int inversions = 0;

	// if n > 1
	if ( bottom < top ) {

		// Calculate the half way point of A[0..⌊n/2⌋-1]
		half = ( bottom + top ) / 2;

		// Recursively call the divideAndConquerMergesort function with B[0..⌊n/2⌋-1]. Track the number of inversions returned
		inversions = inversions + divideAndConquerMergesort ( integer_array, bottom, half );
		// Recursively call the divideAndConquerMergesort function with C[0..⌊n/2⌋-1]. Track the number of inversions returned
		inversions = inversions + divideAndConquerMergesort ( integer_array, half + 1, top );
		// Call the merge function with A[0..⌊n/2⌋-1] and the bottom, half, and top indices of the array. Track the number of inversions returned
		inversions = inversions + merge ( integer_array, bottom, half + 1 , top );

	}

	// Return the number of inversions
	return inversions;

}