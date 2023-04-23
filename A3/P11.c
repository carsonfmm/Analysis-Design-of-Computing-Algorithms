#include "A3.h"

// Name: Carson Mifsud
// Date: 2021-03-15
// Assignment: 3

/* 
 * Searches for anagrams using a sequential search method
 * Input: An array of structs containing unsorted
 *        char pointers and a struct containing the users input
 * Output: The count of anagrams found and the anagrams
 */
void BruteForceAnagram ( integer_sort *integer_array, input_sort *input ) {

	// Integer variables used throughout the funtion
	int i = 0;
	int k = 0;
	int g = 0;
	int j = 0;
	int count = 0;
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int count6 = 0;
	int count7 = 0;
	int count8 = 0;
	int count9 = 0;
	int invalid = 0;
	int count_string0 = 0;
	int count_string1 = 0;
	int count_string2 = 0;
	int count_string3 = 0;
	int count_string4 = 0;
	int count_string5 = 0;
	int count_string6 = 0;
	int count_string7 = 0;
	int count_string8 = 0;
	int count_string9 = 0;
	int matches[30000];

	// Store the count of each digit in the user input
	for ( i = 0; i < strlen ( input->not_sorted ); i++ ) {

		if ( input->not_sorted[i] == '0' ) {
			count0 = count0 + 1;
		} else if ( input->not_sorted[i] == '1' ) {
			count1 = count1 + 1;
		} else if ( input->not_sorted[i] == '2' ) {
			count2 = count2 + 1;
		} else if ( input->not_sorted[i] == '3' ) {
			count3 = count3 + 1;
		} else if ( input->not_sorted[i] == '4' ) {
			count4 = count4 + 1;
		} else if ( input->not_sorted[i] == '5' ) {
			count5 = count5 + 1;
		} else if ( input->not_sorted[i] == '6' ) {
			count6 = count6 + 1;
		} else if ( input->not_sorted[i] == '7' ) {
			count7 = count7 + 1;
		} else if ( input->not_sorted[i] == '8' ) {
			count8 = count8 + 1;
		} else if ( input->not_sorted[i] == '9' ) {
			count9 = count9 + 1;
		} else {
			invalid = invalid + 1;
		}

	}

	// Sequentially search through the entire array of integers
	for ( k = 0; k < 30000; k++ ) {

		count_string0 = 0;
		count_string1 = 0;
		count_string2 = 0;
		count_string3 = 0;
		count_string4 = 0;
		count_string5 = 0;
		count_string6 = 0;
		count_string7 = 0;
		count_string8 = 0;
		count_string9 = 0;

		// Check if the char pointers have the same length
		if ( strlen ( integer_array[k].not_sorted ) == strlen ( input->not_sorted ) && invalid == 0 ) {

			// Store the count of each digit from the char pointers in the array
			for ( i = 0; i < strlen ( integer_array[k].not_sorted ); i++ ) {

				if ( integer_array[k].not_sorted[i] == '0' ) {
					count_string0 = count_string0 + 1;
				} else if ( integer_array[k].not_sorted[i] == '1' ) {
					count_string1 = count_string1 + 1;
				} else if ( integer_array[k].not_sorted[i] == '2' ) {
					count_string2 = count_string2 + 1;
				} else if ( integer_array[k].not_sorted[i] == '3' ) {
					count_string3 = count_string3 + 1;
				} else if ( integer_array[k].not_sorted[i] == '4' ) {
					count_string4 = count_string4 + 1;
				} else if ( integer_array[k].not_sorted[i] == '5' ) {
					count_string5 = count_string5 + 1;
				} else if ( integer_array[k].not_sorted[i] == '6' ) {
					count_string6 = count_string6 + 1;
				} else if ( integer_array[k].not_sorted[i] == '7' ) {
					count_string7 = count_string7 + 1;
				} else if ( integer_array[k].not_sorted[i] == '8' ) {
					count_string8 = count_string8 + 1;
				} else if ( integer_array[k].not_sorted[i] == '9' ) {
					count_string9 = count_string9 + 1;
				}

				// If the character count in the char pointer array and the users input are equal, an anagram has been found
				if ( count_string0 == count0 && count_string1 == count1 && count_string2 == count2 && count_string3 == count3 && count_string4 == count4 && count_string5 == count5 && count_string6 == count6 && count_string7 == count7 && count_string8 == count8 && count_string9 == count9 ) {

					// Check if the anagram found is not the original user input
					if ( strcmp ( integer_array[k].not_sorted, input->not_sorted ) != 0 ) {

						// Store the found anagram into an array
						matches[g] = atoi ( integer_array[k].not_sorted );
						count = count + 1;
						g = g + 1;

					}

				}

			}

		}

	}

	// Check the anagram array for any duplicate anagrams
	for ( i = 0; i < g; i++ ) {

		for ( j = i+1; j < g; j++ ) {

			// If the array contains duplicate anagrams
			if ( matches[i] == matches[j] ) {

				// Remove the duplicate anagram
				for ( k = j; k < g; k++ ) {

					matches[k] = matches[k + 1];

				}

				// Decrement the count variables
				count = count - 1;
				g = g - 1;
				j = j - 1;

			}

		}

	}

	// If at least one anagram was found
	if ( g > 0 ) {

		printf ( "Anagrams:\n" );

		// Print the unsorted anagrams
		for ( i = 0; i < g; i++ ) {

			printf ( "%d\n", matches[i] );

		}

	}

	// Print the final Anagram count to stdout
	printf ( "counts = %d\n", count );

}
