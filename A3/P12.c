#include "A3.h"

// Name: Carson Mifsud
// Date: 2021-03-15
// Student ID: 1089936
// Assignment: 3

/* 
 * Searches for anagrams using a binary search method
 * Input: An array of structs containing double presorted
 *        and unsorted char pointers, and a struct containing
 *        the users sorted and unsorted input
 * Output: The count of anagrams found and the unsorted anagrams
 */
void PresortAnagram ( integer_sort *integer_array, input_sort *input ) {

	// Integer variables used throughout the function
	int g = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int cond = 0;
	int bottom = 0;
	int count = 0;
	int top = 29999;
	int position = 0;
	int temp_pos = 0;
	int matches[30000];

	// While the bottom is less than or euqal to the top
	while ( bottom <= top ) {
		
		// Position represents the half way point for the binary search
		position = ( bottom + top ) / 2;

		// Checking if an anagram is found
		if ( ( cond = strcmp ( integer_array[position].sorted, input->sorted ) ) == 0 ) {

			// Check the indexes below the found index for other anagrams
			while ( ( strcmp ( integer_array[position].sorted, input->sorted ) ) == 0 ) {

				// Check if the anagram found is not the original user input
				if ( strcmp ( integer_array[position].not_sorted, input->not_sorted ) != 0 ) {

					// Store the found anagram into an array
					matches[g] = atoi ( integer_array[position].not_sorted );
					count = count + 1;
					g = g + 1;

				}

				temp_pos = temp_pos + 1;
				position = position - 1;

			}

			// Reset the position
			position = position + temp_pos;

			// Check the indexes abive the found index for other anagrams
			while ( ( strcmp ( integer_array[position].sorted, input->sorted ) ) == 0 ) {

				// Check if the anagram found is not the original user input
				if ( strcmp ( integer_array[position].not_sorted, input->not_sorted ) != 0 ) {

					// Store the found anagram into an array
					matches[g] = atoi ( integer_array[position].not_sorted );
					count = count + 1;
					g = g + 1;

				}

				position = position + 1;

			}

			// Break out of loop as the binary search is complete
			break;

  		}
	
		// Set the top and bottom variables to continue the binary search
  		else if ( cond < 0 ) {
   			top = position - 1;
		} else {
   			bottom = position + 1;
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