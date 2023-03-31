#include "A3.h"

// Name: Carson Mifsud
// Date: 2021-03-15
// Student ID: 1089936
// Assignment: 3

/* 
 * Implements Brute Force string search matching
 * Input: An array T[0..n−1] of n characters representing
 *        a text and an array P[0..m−1] of m characters
 *        representing a pattern
 * Output: The amount of string matches that were found
 *         and the number of shifts used throughout the search
 */
void BruteForceStringSearch ( char *text_file, char *input ) {

	// Integer variables used throughout the function
	int i = 0;
	int m = 0;
	int n = 0;
	int check = 0;
	int shifts = 0;
	int total_count = 0;

	// The length of the text file
	m = strlen ( text_file );
	// The length of the users input / pattern
	n = strlen ( input );

	// Search through the text file
	for ( i = 0; i < m-n; i++ ) {

		// Reset the check variable
		check = 0;

		// While the strings match, increment the check variable
		while ( (check < n) && (input[check] == text_file[i+check]) ) {
			check = check + 1;
		}

		// If the check variables equals the length of the users input / pattern
		if ( check == n ) {

			// Increment the string match count by 1
			total_count = total_count + 1;

		}

		// Increment the total number of shifts
		shifts = shifts + 1;

	}

	// Print the total number of string matches found to stdout
	printf ( "count: %d\n", total_count );
	// Print the total number of shifts to stdout
	printf ( "Pattern shifts: %d\n", shifts );

}