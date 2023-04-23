// Name: Carson Mifsud
// Date: 2021-03-15
// Assignment: 3

#include "A3.h"

// Quicksort function used for sorting the signatures the struct used for anagrams
int sorted_compare ( const void *i, const void *j )  { 

    integer_sort *i1 = ( integer_sort * ) i;
    integer_sort *j1 = ( integer_sort * ) j;
    return strcmp ( j1->sorted, i1->sorted );

} 

// Quicksort function used for sorting the char pointers into signatures the struct used for anagrams
int sorted_compare_individual ( const void *i, const void *j ) {

  	return * ( char * ) j - * ( char * ) i;

}

int main ( int argc, char const *argv[] ) {

	// File pointers
	FILE *fp1;
	FILE *fp2;

	// Integer variables used throughout the program
	int i = 0;
	int j = 0;
	int k = 0;
	int ch = 0;
	int exit_check = 1;

	// Malloc memory for the char pointers used throughout the program
	char *temporary = malloc ( sizeof ( char * ) + 100 );
	char *temporary2 = malloc ( sizeof ( char * ) + 100 );
	char *temporary3 = malloc ( sizeof ( char * ) + 100 );
	char *temporary4 = malloc ( sizeof ( char * ) * 1000000 );
	char *algorithm_input = malloc ( sizeof ( char * ) + 100 );

	// Malloc memory for the structs used throughout the program
	integer_sort *integer_array = ( integer_sort * ) malloc ( sizeof ( integer_sort ) * 30000 );
	input_sort *input = ( input_sort * ) malloc ( sizeof ( input_sort ) + 1 );
	input->not_sorted = ( char * ) malloc ( sizeof ( char * ) + 10 );
	input->sorted = ( char * ) malloc ( sizeof ( char * ) + 10 );

	// Variables to track execution time throughout the program
	struct timeb startTimeBruteForce;
	struct timeb endTimeBruteForce;
	struct timeb startTimePresort;
	struct timeb endTimePresort;
	struct timeb startTimePresortSort;
	struct timeb endTimePresortSort;
	struct timeb startTimeBruteSearch;
	struct timeb endTimeBruteSearch;
	struct timeb startTimeHorspool;
	struct timeb endTimeHorspool;
	struct timeb startTimeBoyerMoore;
	struct timeb endTimeBoyerMoore;

	// Floats used throughout the program
	float totalTimeBruteForce;
	float totalTimePresort;
	float totalTimePresortSort;
	float totalTimeBruteSearch;
	float totalTimeHorspool;
	float totalTimeBoyerMoore;

	// Open the files which have been hard coded into the program
	fp1 = fopen ( "data_4.txt", "r" );
	fp2 = fopen ( "data_52.txt", "r" );

	// Print welcome message to stdout
	printf ( "\nWelcome to Assignment 3 by Carson Mifsud!\nPlease enter the number corresponding to an algorithm or 'exit' to exit the program:\n\n" );

	// While the user has nto exited the program
	while ( exit_check == 1 ) {

		// Print the options to stdout
		printf ( "(1) Brute Force Anagram Algorithm\n" );
		printf ( "(2) Presort Anagram Algorithm\n" );
		printf ( "(3) Brute Force String Search Algorithm\n" );
		printf ( "(4) Horspool String Search Algorithm\n" );
		printf ( "(5) Boyer-Moore String Search Algorithm\n" );
		printf ( "Enter 'exit' to end the program\n\n" );

		// Get the users input
		if ( ( fgets ( algorithm_input, 100, stdin ) == NULL ) && ferror ( stdin ) ) {
			perror ( "Error: fgets()" );
		}

		printf ( "\n" );

		// Remove the '\n' character from the users input
		for ( i = 0; algorithm_input[i] != '\0'; i++ ) {}

		algorithm_input[i-1] = '\0';

		// The program will run the Brute Force Anagram Algorithm
		if ( strcmp ( algorithm_input, "1" ) == 0 ) {

			printf ( "Enter a string: " );

			// Get the users input
			if ( ( fgets ( temporary2, 100, stdin ) == NULL ) && ferror ( stdin ) ) {
				perror ( "Error: fgets()" );
			}

			strcpy ( input->not_sorted, temporary2 );
			strcpy ( input->sorted, temporary2 );

			// Remove the '\n' character from the users input, and store it in seach struct pointer
			for ( i = 0; input->not_sorted[i] != '\0'; i++ ) {}
			for ( j = 0; input->sorted[j] != '\0'; j++ ) {}

			input->not_sorted[i-1] = '\0';
			input->sorted[j-1] = '\0';

			// Read in the 'data_4.txt" file
			while ( fscanf ( fp1, "%s", temporary ) != EOF ) {

				integer_array[k].sorted = ( char * ) malloc ( strlen ( temporary ) * sizeof ( char * ) + 10 );
				strcpy ( integer_array[k].sorted, temporary );
				integer_array[k].not_sorted = ( char * ) malloc ( strlen ( temporary ) * sizeof ( char * ) + 10 );
				strcpy ( integer_array[k].not_sorted, temporary );

				k = k + 1;

			}

			// Track the execution time and call the corresponding function
			ftime ( &startTimeBruteForce );
			BruteForceAnagram ( integer_array, input );
			ftime ( &endTimeBruteForce );

			// Calculate the total execution time in milliseconds
			totalTimeBruteForce = ( endTimeBruteForce.time - startTimeBruteForce.time) * 1000 + ( endTimeBruteForce.millitm - startTimeBruteForce.millitm );

			// Print the execution time to stdout
			printf ( "The Brute Force Algorithm had an execution time of %f milliseconds.\n\n", totalTimeBruteForce );

		}

		// The program will run the Presort Anagram Algorithm
		else if ( strcmp ( algorithm_input, "2" ) == 0 ) {

			printf ( "Enter a string: " );

			// Get the users input
			if ( ( fgets ( temporary2, 100, stdin ) == NULL ) && ferror ( stdin ) ) {
				perror ( "Error: fgets()" );
			}

			strcpy ( input->not_sorted, temporary2 );
			strcpy ( input->sorted, temporary2 );

			// Remove the '\n' character from the users input, and store it in seach struct pointer
			for ( i = 0; input->not_sorted[i] != '\0'; i++ ) {}
			for ( j = 0; input->sorted[j] != '\0'; j++ ) {}

			input->not_sorted[i-1] = '\0';
			input->sorted[j-1] = '\0';

			// Read in the 'data_4.txt" file
			while ( fscanf ( fp1, "%s", temporary ) != EOF ) {

				integer_array[k].sorted = ( char * ) malloc ( strlen ( temporary ) * sizeof ( char * ) + 10 );
				strcpy ( integer_array[k].sorted, temporary );
				integer_array[k].not_sorted = ( char * ) malloc ( strlen ( temporary ) * sizeof ( char * ) + 10 );
				strcpy ( integer_array[k].not_sorted, temporary );

				k = k + 1;

			}

			// Double presort the array of char pointers using a quicksort method
			ftime ( &startTimePresortSort );
			for ( k = 0; k < 30000; k++ ) {

				qsort ( ( char * ) integer_array[k].sorted, (size_t) strlen ( integer_array[k].sorted ), ( size_t ) sizeof ( char ), sorted_compare_individual );

			}

			qsort ( ( char * ) input->sorted, (size_t) strlen ( input->sorted ), ( size_t ) sizeof ( char ), sorted_compare_individual );

			qsort ( integer_array, 30000, sizeof ( integer_sort ), sorted_compare );
			ftime ( &endTimePresortSort );

			// Track the execution time and call the corresponding function
			ftime ( &startTimePresort );
			PresortAnagram ( integer_array, input );
			ftime ( &endTimePresort );

			// Calculate the total execution time in milliseconds
			totalTimePresortSort = ( endTimePresortSort.time - startTimePresortSort.time) * 1000 + ( endTimePresortSort.millitm - startTimePresortSort.millitm );

			// Print the execution time to stdout
			printf ( "The Quicksort Algorithm had an execution time of %f milliseconds.\n", totalTimePresortSort );

			// Calculate the total execution time in milliseconds
			totalTimePresort = ( endTimePresort.time - startTimePresort.time) * 1000 + ( endTimePresort.millitm - startTimePresort.millitm );

			// Print the execution time to stdout
			printf ( "The Presort Anagram Algorithm had an execution time of %f milliseconds.\n\n", totalTimePresort );

		}

		// The program will run the Brute Force String Search Algorithm
		else if ( strcmp ( algorithm_input, "3" ) == 0 ) {

			printf ( "Enter a pattern: " );

			// Get the users input
			if ( ( fgets ( temporary3, 100, stdin ) == NULL ) && ferror ( stdin ) ) {
				perror ( "Error: fgets()" );
			}

			// Remove the '\n' character from the users input
			for ( i = 0; temporary3[i] != '\0'; i++ ) {}

			temporary3[i-1] = '\0';

			i = 0;

			// Store each character from the text file into an array
			while ( ( ch = getc ( fp2 ) ) != EOF ) {

				temporary4[i] = ch;

				i = i + 1;

			}

			// Track the execution time and call the corresponding function
			ftime ( &startTimeBruteSearch );
			BruteForceStringSearch ( temporary4, temporary3 );
			ftime ( &endTimeBruteSearch );

			// Calculate the total execution time in milliseconds
			totalTimeBruteSearch = ( endTimeBruteSearch.time - startTimeBruteSearch.time) * 1000 + ( endTimeBruteSearch.millitm - startTimeBruteSearch.millitm );

			// Print the execution time to stdout
			printf ( "The Brute Force String Search Algorithm had an execution time of %f milliseconds.\n\n", totalTimeBruteSearch );

		}

		// The program will run the Horspool String Search Algorithm
		else if ( strcmp ( algorithm_input, "4" ) == 0 ) {

			printf ( "Enter a pattern: " );

			// Get the users input
			if ( ( fgets ( temporary3, 100, stdin ) == NULL ) && ferror ( stdin ) ) {
				perror ( "Error: fgets()" );
			}

			// Remove the '\n' character from the users input
			for ( i = 0; temporary3[i] != '\0'; i++ ) {}

			temporary3[i-1] = '\0';

			i = 0;

			// Store each character from the text file into an array
			while ( ( ch = getc ( fp2 ) ) != EOF ) {

				temporary4[i] = ch;

				i = i + 1;

			}

			// Track the execution time and call the corresponding function
			ftime ( &startTimeHorspool );
			HorspoolStringSearch ( temporary4, temporary3 );
			ftime ( &endTimeHorspool );

			// Calculate the total execution time in milliseconds
			totalTimeHorspool = ( endTimeHorspool.time - startTimeHorspool.time) * 1000 + ( endTimeHorspool.millitm - startTimeHorspool.millitm );

			// Print the execution time to stdout
			printf ( "The Horspool String Search Algorithm had an execution time of %f milliseconds.\n\n", totalTimeHorspool );

		}

		// The program will run the Boyer-Moore String Search Algorithm
		else if ( strcmp ( algorithm_input, "5" ) == 0 ) {

			printf ( "Enter a pattern: " );

			// Get the users input
			if ( ( fgets ( temporary3, 100, stdin ) == NULL ) && ferror ( stdin ) ) {
				perror ( "Error: fgets()" );
			}

			// Remove the '\n' character from the users input
			for ( i = 0; temporary3[i] != '\0'; i++ ) {}

			temporary3[i-1] = '\0';

			i = 0;

			// Store each character from the text file into an array
			while ( ( ch = getc ( fp2 ) ) != EOF ) {

				temporary4[i] = ch;

				i = i + 1;

			}

			// Track the execution time and call the corresponding function
			ftime ( &startTimeBoyerMoore );
			BoyerMooreStringSearch ( temporary4, temporary3 );
			ftime ( &endTimeBoyerMoore );

			// Calculate the total execution time in milliseconds
			totalTimeBoyerMoore = ( endTimeBoyerMoore.time - startTimeBoyerMoore.time) * 1000 + ( endTimeBoyerMoore.millitm - startTimeBoyerMoore.millitm );

			// Print the execution time to stdout
			printf ( "The Boyer-Moore String Search Algorithm had an execution time of %f milliseconds.\n\n", totalTimeBoyerMoore );

		}

		// If the user has entered 'exit', print a termination messge to stdout and end the program
		else if ( strcmp ( algorithm_input, "exit" ) == 0 || strcmp ( algorithm_input, "EXIT" ) == 0 || strcmp ( algorithm_input, "Exit" ) == 0) {

			printf ( "Thank you for using the Assignment 3 program! Have a good day!\n\n" );

			// Set the exit_check variable to 0, indicating the user has exited the program
			exit_check = 0;

		}
		
		// If any other input was entered, notify the user the input was invalid and prompt the user for input again
		else {

			printf ( "That is not a valid input\nPlease enter the number corresponding to an algorithm or 'exit' to exit the program:\n\n" );

		}

	}

	// Close the file pointers
	fclose ( fp1 );
	fclose ( fp2 );

	// Free the sorted struct array of char pointers
	for ( i = 0; i < 30000; i++ ) {
		free ( integer_array[i].sorted );
	}

	// Free the non-sorted struct array of char pointers
	for ( i = 0; i < 30000; i++ ) {
		free ( integer_array[i].not_sorted );
	}

	// Free all other variables that were malloced
	free ( algorithm_input );
	free ( integer_array );
	free ( input->not_sorted );
	free ( input->sorted );
	free ( input );
	free ( temporary );
	free ( temporary2 );

	return ( 0 );

}
