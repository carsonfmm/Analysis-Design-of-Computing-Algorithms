#include "A3.h"

// Name: Carson Mifsud
// Date: 2021-03-15
// Assignment: 3

/* 
 * Creates the Good Suffix Table for the Boyer-Moore Algorithm
 * Input: Good suffix shift table, Bad suffix shift table, the
 *        users input
 * Output: The updated Good suffix and Bad suffix shift tables
 */
void GoodSuffixTable ( int *ShiftTable, int *BadTable, char *input ) {

	// Integer variables used throughout the function
    int i = 0;
	int j = 0;
	int length = 0;

	// The length of the users input / pattern
	length = strlen ( input );
	
	// Initialize variables
	i = length;
	j = length + 1;

	// Initialize the index for the Bad suffix table
    BadTable[i] = j;

	// While i is greater than 0
    while ( i > 0 ) {

		// Continue searching until the characters are the same
        while ( j <= length && input[i-1] != input[j-1] ) {

			// If the character in the user input is different from the previous character, shift the pattern
            if ( ShiftTable[j] == 0 ) {
                ShiftTable[j] = j-i;
			}

            // Update the position of next border
            j = BadTable[j];

        }

		// Store the beginning position of the boarder
        i = i - 1;
		j = j - 1;
        BadTable[i] = j;

    }

}

/* 
 * Creates the Bad Suffix Table for the Boyer-Moore Algorithm
 * Input: Good suffix shift table, Bad suffix shift table, the
 *        users input
 * Output: The updated Good suffix and Bad suffix shift tables
 */
void BadSuffixTable ( int *ShiftTable, int *BadTable, char *input ) {

	// Integer variables used throughout the algorithm
    int i = 0;
	int j = 0;
	int length = 0;

	// The length of the users input / pattern
	length = strlen ( input );

	// Initialize j with the starting index for of the Bad suffix table
    j = BadTable[0];

	// For loop to iterate untill i is less than or equal to the length of the users input / pattern
    for ( i = 0; i <= length; i++ ) {

        // Set the border position of the first character of the pattern 
        if ( ShiftTable[i] == 0 ) {
            ShiftTable[i] = j;
		}
  

		// If the suffix becomes shorter than the boarder use the next position
        if ( i == j ) {
            j = BadTable[j];
		}

    }

}
  

/* 
 * Implements Boyer-Moore's algorithm for string search matching
 * Input: Pattern [P..m-1] and text T[0..n-1]
 * Output: The amount of string matches that were found
 *         and the number of shifts used throughout the search
 */
void BoyerMooreStringSearch ( char *text_file, char *input ) {

    // Integer variables used throughout the function
    int i = 0;
	int check = 0;
	int count = 0;
	int shifts = 0;

	// The length of the text file
    int n = strlen ( text_file );
	// The length of the users input / pattern
    int m = strlen ( input );

	// Create the Bad Suffix Shift Table
    int BadTable[m+1];
	// Create the Good Suffix Shift Table
	int ShiftTable[m+1];

    //initialize all occurrence of the Good Suffix Shift Table to 0 
    for ( int i = 0; i < m+1; i++ ) {
		ShiftTable[i]=0;
	}

    // Fill the Good Suffix Shift Table
    GoodSuffixTable ( ShiftTable, BadTable, input );
	// Fill the Bad Suffix Shift Table
    BadSuffixTable ( ShiftTable, BadTable, input );

	// While i is less than or equal to the length of the text file minus the length of the users input / pattern
    while ( i <= n-m ) {

		// Update variable check
        check = m - 1;

		// While characters are equal, decrement variable check
        while ( check >= 0 && input[check] == text_file[i+check] ) {
            check = check - 1;
		}

		// if variable check is less than 0, and string match has been found
        if ( check < 0 ) {

			// Increment the string match count
			count = count + 1;
			// Reset variable i to continue the search through the file
            i = i + ShiftTable[0];

        }

        else {

            // Reset variable i to continue the search through the file
            i = i + ShiftTable[check+1];

		}

		// Update the number of shifts
		shifts = shifts + 1;

    }

	// Print the total number of string matches found to stdout
	printf ( "count: %d\n", count );
	// Print the total number of shifts to stdout
	printf ( "Pattern shifts: %d\n", shifts );

}
