#include "A3.h"

// Name: Carson Mifsud
// Date: 2021-03-15
// Student ID: 1089936
// Assignment: 3

/* 
 * Fills the shift table by Horspool's algorithm
 * Input: Pattern [P..m-1] and an alphabet of possible
 *        characters
 * Output: Table[0..size-1] indexed by the alphabet's characters
 *         and filled with shift sizes
 */
void ShiftTable ( char *input ) {

	// Integer variables used throughout the function
	int i = 0;
	int j = 0;
	int m = 0;
	int temp = 0;

	// Length of the users input / pattern
	m = strlen ( input );

	// Fill each index of the table with the length of the users input / pattern
	for ( i = 0; i < 126; i++ ) {
		
		table[i] = m;
	}

	// Construct shifts for characters in the users input / pattern
	for ( j = 0; j < m - 1; j++ ) {
		
		temp = input[j];
		table[temp] = m - 1 - j;

	}

}

/* 
 * Implements Horspool's algorithm for string search matching
 * Input: Pattern [P..m-1] and text T[0..n-1]
 * Output: The amount of string matches that were found
 *         and the number of shifts used throughout the search
 */
void HorspoolStringSearch ( char *text_file, char *input ) {

	// Integer variables used throughout the function
	int i = 0;
	int k = 0;
	int m = 0;
	int n = 0;
	int count = 0;
	int shifts = 0;
	int temp = 0;

	// Create the shift table
	ShiftTable ( input );

	// Length of the text file
	n = strlen ( text_file );
	// Length of the users input / pattern
	m = strlen ( input );

	i = m - 1;

	// While i is less than the length of the text file
	while ( i <= n-1 ) {

		// Reset variable k
		k = 0;

		// While text file and users input are equal
		while ( ( k <= m-1 ) && ( input[m-1-k] == text_file[i-k] ) ) {

			// Increment variable k
			k = k + 1;

		}

		// If k is equal the the length of the users input / pattern
		if ( k == m ) {

			// Increment the string match count
			count = count + 1;
			// Reset variable i to continue the search through the file
			i = i + m;

		} else {

			// Reset variable i to continue the search through the file
			temp = text_file[i];
			i = i + table[temp];

		}

		// Update the number of shifts
		shifts = shifts + 1;

	}

	// Print the total number of string matches found to stdout
	printf ( "count: %d\n", count );
	// Print the total number of shifts to stdout
	printf ( "Pattern shifts: %d\n", shifts );

}