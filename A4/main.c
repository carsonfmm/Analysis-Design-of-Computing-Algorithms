// Name: Carson Mifsud
// Date: 2021-03-29
// Assignment: 4
// Description: This program implements two searching methods to search through optimal binary search trees (BSTs) for the words given in the data_7.txt file.

#include "A4.h"

// Table R of subtrees' roots in the optimal BST
int R[615][615];
// Average number of comparisions in successful searches in the optimal BST
float C[615][615];
// Stores all largest probabilities
float temp_float[2045];

/*
 * Quick sort function to order an array of
 * strings ( char ** ) in alphabetical order
 */
int string_sort ( const void *i, const void *j ) {
    const char **ii = ( const char ** ) i;
    const char **jj = ( const char ** ) j;
    return strcmp ( *ii, *jj );
}

/*
 * This function uses the greedy technique to
 * traverse through an optimal BST. This function
 * takes multiple parameters which are used for:
 *    - tk: control the amount of recursions
 *    - array: The array of propabilities
 *    - left_index: left most index to begin searching
 *    - right_index: right most index to end searching
 *    - largest_index: index of the largest probability
 *    - temporary3: the users search key/input
 *    - previous: the previous word searched
 *    - tracker: iterator to track "Found" and "Not found" results
 *    - string_array_unique: array of 600 unique strings from data_7.txt
 *    - store_float: stores all largest probabilities
 *    - other_tracker: the previous index
 * This function will search for the users key in an
 * Optimal BST and print to stdout at every iteration,
 * the word found, its frequency and whether to traverse
 * left or right. If no match is found, the function
 * prints "Not found." to stdout. If a match is found,
 * the function prints "found" along with the found word
 * and its frequency.
 */
void Greedy_Tree ( int tk, float *array, int left_index, int right_index, int largest_index, char *temporary3, char *previous, int tracker, char **string_array_unique, float *store_float, int other_tracker ) {

    // Integer variables used throughout the function
    int i;
    int total_word = 0;
    int total_word2 = 0;
    int k = 0;
    int my_length = 0;

    // Float variable to store the index of the largest probability
    float largest_prob = 0.0;

    // Initialize previous with the current word at the largest index
    strcpy ( previous, string_array_unique[largest_index] );

    // Calculate the length of the users key
    for ( k = 0; k < strlen(temporary3); k++ ) {
        total_word = total_word + temporary3[k];
    }

    // Calculate the length of the current word at the largest probability index
    for ( k = 0; k < strlen(string_array_unique[largest_index]); k++ ) {
        total_word2 = total_word2 + string_array_unique[largest_index][k];
    }

    // Check which of the two above calculated lengths are smaller, and initialize my_length with the smallest word length
    if ( strlen(temporary3) > strlen(string_array_unique[largest_index]) ) {

        // Initialize my_length with the length of the current word at the largest probability index
        my_length = strlen(string_array_unique[largest_index]);

    } else {

        // Initialize my_length with the length of the users key
        my_length = strlen(temporary3);

    }

    // Reset the k variable to 0
    k = 0;

    // while k is less than the length of the smallest word
    while ( k < my_length ) {

        // If the current letter at index k in string_array_unique is greater then the current letter at index k in the users key, traverse left
        if ( string_array_unique[largest_index][k] > temporary3[k] ) {

            // Update the right index to be the largest probability index minus 1
            right_index = largest_index-1;

            // Loop through the array for the largest probability, within the largest and left index
            for ( i = largest_index-1; i > left_index; i-- ) {
                if ( array[i] > largest_prob ) {
                    largest_prob = array[i];
                    largest_index = i;
                }
            }

            // Check if the current word with the largest probability, is equal to the users key
            if ( strcmp ( string_array_unique[largest_index], temporary3 ) == 0 ) {

                // Print to stdout that a match was found
                printf ( "Compared with %s (%.3f), go left subtree.\n", previous, store_float[other_tracker-1] );
                printf ( "Compared with %s (%.3f) found.\n", temporary3, largest_prob );
                tk = 600;
                return;
            }

            // Add the current largest probability to the store_float array
            store_float[other_tracker] = largest_prob;

            // If the search should continue, print the current word and its frequency to the user
            if ( other_tracker > 0 ) {
                printf ( "Compared with %s (%.3f), go left subtree.\n", previous, store_float[other_tracker-1] );
            }

            // If no matches were found, print the last word and its frequency to stdout
            if ( tracker > 0 ) {
                if ( strcmp ( previous, string_array_unique[largest_index-1] ) == 0 || strcmp ( previous, string_array_unique[largest_index+1] ) == 0 ) {
                    printf ( "Compared with %s (%.3f), go left subtree.\n", string_array_unique[largest_index], largest_prob );
                    printf ( "Not found.\n" );
                    return;
                }
            }

            // Initialize k to my_length to exit the while loop
            k = my_length;

        }
        
        // If the current letter at index k in string_array_unique is greater then the current letter at index k in the users key, traverse right
        else if ( string_array_unique[largest_index][k] < temporary3[k] ) {

            // Update the left index to be the largest probability index plus 1
            left_index = largest_index+1;

            // Loop through the array for the largest probability, within the largest and right index
            for ( i = largest_index+1; i < right_index; i++ ) {
                if ( array[i] > largest_prob ) {
                    largest_prob = array[i];
                    largest_index = i;
                }
            }

            // Check if the current word with the largest probability, is equal to the users key
            if ( strcmp ( string_array_unique[largest_index], temporary3 ) == 0 ) {

                // Print to stdout that a match was found
                printf ( "Compared with %s (%.3f), go right subtree.\n", previous, store_float[other_tracker-1] );
                printf ( "Compared with %s (%.3f) found.\n", temporary3, largest_prob );
                tk = 600;
                return;
            }

            // Add the current largest probability to the store_float array
            store_float[other_tracker] = largest_prob;

            // If the search should continue, print the current word and its frequency to the user
            if ( other_tracker > 0 ) {
                printf ( "Compared with %s (%.3f), go right subtree.\n", previous, store_float[other_tracker-1] );
            }

            // If no matches were found, print the last word and its frequency to stdout
            if ( tracker > 0 ) {
                if ( strcmp ( previous, string_array_unique[largest_index-1] ) == 0 || strcmp ( previous, string_array_unique[largest_index+1] ) == 0 ) {
                    printf ( "Compared with %s (%.3f), go right subtree.\n", string_array_unique[largest_index], largest_prob );
                    printf ( "Not found.\n" );
                    return;
                }
            }

            // Initialize k to my_length to exit the while loop
            k = my_length;

        }
        
        // Update the current letter by implementing k, and continue searching
        else {
            k++;
        }

    }

    // Increment the tracker variable
    tracker = tracker + 1;
    // Increment the other_tracker variable
    other_tracker = other_tracker + 1;

    // If the variable tk is less then 600, continue searching for the users key and recursivley call the Greedy_Tree function
    if ( tk < 600 ) {
        Greedy_Tree ( tk, array, left_index, right_index, largest_index, temporary3, previous, tracker, string_array_unique, store_float, other_tracker );
    }

    // Else, the users input was not found
    else {
        printf ( "Not found.\n" );
        return;
    }

}


/* 
 * Finds an optimal binary search tree by dynamic programming
 * Input: An array P[1..n] of search probabilities for a 
 *        sorted list of n keys
 * Output: Average number of comparisions in successful
 *         searches in the optimal BST and table R of
 *         subtrees' roots in the optimal BST
 */
// NOTE: The functionality of this function was recieved from 'Introduction to the Design and Analysis of Algorithms' on page 302
void OptimalBST ( float *P, int n ) {

    // Initial initialization of tables for outer diagonal
    for ( int i = 1; i <= n; i++ ) {
        C[i][i-1] = 0;
        C[i][i] = P[i-1];
        R[i][i] = i;
    }

    C[n+1][n] = 0;

    // Diagonal Count, to initialize all indexes of the virtual tree ( Tables C and R )
    for ( int d = 1; d <= n-1; d++ ) {
        for ( int i = 1; i <= n-d; i++ ) {

            int j = i + d;
            float minval = 214748364.0;
            int kmin = 0;

            for ( int k = i; k <= j; k++ ) {

                if ( C[i][k-1] + C[k+1][j] < minval ) {
                    minval = C[i][k-1] + C[k+1][j];
                    kmin = k;
                }

            }

            R[i][j] = kmin;
            float sum = P[i-1];

            for ( int s = i+1; s <= j; s++ ) {
                sum = sum + P[s-1];
            }

            C[i][j] = minval + sum;

        }
    }
}

int main ( int argc, char const *argv[] ) {

    // File pointer for data_7.txt
    FILE *fp1;

    // Integer variables used throughout the program
    int k = 0;
    int i = 0;
    int j = 0;
    int exit_check = 1;

    // Float variables used throughout the program
    float probability_array[2045];

    // String ( char * ) and String arrays ( charr ** ) used throughout the function
	char *temporary = malloc ( sizeof ( char * ) + 256 );
    char *temporary2 = malloc ( sizeof ( char * ) + 256 );
    char **string_array = malloc ( sizeof ( char * ) * 2045 );
    char **string_array_unique = malloc ( sizeof ( char * ) * 600 );

    // Open the data_7.txt file for reading
    fp1 = fopen ( "data_7.txt", "r" );

    // Read in all words in the file
    while ( fscanf ( fp1, "%s", temporary ) != EOF ) {
        string_array[k] = ( char * ) malloc ( strlen ( temporary ) * sizeof ( char * ) + 256 );
        strcpy ( string_array[k], temporary );
        k = k + 1;
    }

    // Order the words in alphabetical order
    qsort ( string_array, 2045, sizeof ( char * ), string_sort );

    // Reset variables k, i and j
    k = 0;
    i = 0;
    j = 0;

    // While i is less than the number of strings in the file, used to store all unique strings
    while ( i < 2045 ) {

        // Initialize temporary2 with the current string
        strcpy ( temporary2, string_array[i] );

        // While the string is equal the the previous string, increment variables j and i
        while ( strcmp ( temporary2, string_array[i] ) == 0 ) {
            if ( i == 2044 ) {
                j = j + 1;
                i = i + 1;
                break;
            }
            i = i + 1;
            j = j + 1;
        }

        // Calculate and initialize the probability array for the current words node
        probability_array[k] = ( j / 2045.0 );

        // Malloc space for the current words node
        string_array_unique[k] = ( char * ) malloc ( strlen ( string_array[i-1] ) * sizeof ( char * ) + 256 );
        // Initialize the string_array_unique array with the current words node
        strcpy ( string_array_unique[k], string_array[i-1] );

        // Increment variable k
        k = k + 1;

        // Reset variable j
        j = 0;

    }

    // Call the OptimalBST function to create an Optimal BST
    OptimalBST ( probability_array, k );

    printf ( "\n\nWelcome to Assignment 4 by Carson Mifsud!\nPlease enter the number corresponding to a search method or 'exit' to exit the program:\n\n" );

	// While the user has nto exited the program
	while ( exit_check == 1 ) {

        // Integer variables used throughout the program
        int k = 0;
        int found_check = 0;
        int total_word = 0;
        int total_word2 = 0;
        int the_1 = 1;
        int the_n = 600;
        int a_k = 0;
        int my_length = 0;
        int right = 0;
        int left = 0;

        // Float variables used throughout the program
        float store_float = 0.0;

        // String ( char * ) and String arrays ( charr ** ) used throughout the function
        char *temporary3 = malloc ( sizeof ( char * ) + 256 );
        char *temporary4 = malloc ( sizeof ( char * ) + 256 );
        char *temporary5 = malloc ( sizeof ( char * ) + 256 );
        char *store_str = malloc ( sizeof ( char * ) + 256 );
        char *algorithm_input = malloc ( sizeof ( char * ) + 256 );

		// Print the options to stdout
		printf ( "\n\n(1) Optimal BST Search using Dynamic Programming\n" );
		printf ( "(2) Optimal BST Search using the Greedy Technique\n" );
		printf ( "Enter 'exit' to end the program\n\n" );

		// Get the users input
		if ( ( fgets ( algorithm_input, 100, stdin ) == NULL ) && ferror ( stdin ) ) {
			perror ( "Error: fgets()" );
		}

		printf ( "\n" );

		// Remove the '\n' character from the users input
		for ( i = 0; algorithm_input[i] != '\0'; i++ ) {}

		algorithm_input[i-1] = '\0';

        if ( strcmp ( algorithm_input, "1" ) == 0 ) {

            // Prompt the user for input
            printf ( "Enter a string: " );

            // Read the users input from stdin
            if ( ( fgets ( temporary3, 256, stdin ) == NULL ) && ferror ( stdin ) ) {
                perror ( "Error: fgets()" );
            }

            // Remove the '\n' character from the users input
            for ( i = 0; temporary3[i] != '\0'; i++ ) {}
            temporary3[i-1] = '\0';

            // Initialize a_k as the root of the entire tree
            a_k = R[1][600];

            // Initialize left as the index of the key for the root of the left subtree
            left = R[the_1][a_k-1];
            // Initialize right as the index of the key for the root of the right subtree
            right = R[a_k+1][the_n];

            // Search through the optimal BST for the users key
            for ( int tk = 0; tk < 600; tk++ ) {

                // Reset variables
                total_word = 0;
                total_word2 = 0;
                my_length = 0;
                k = 0;

                // Calculate the length of the users key
                for ( k = 0; k < strlen(temporary3); k++ ) {
                    total_word = total_word + temporary3[k];
                }

                // Calculate the length of the current word at the largest probability index
                for ( k = 0; k < strlen(string_array_unique[a_k-1]); k++ ) {
                    total_word2 = total_word2 + string_array_unique[a_k-1][k];
                }

                // Check which of the two above calculated lengths are smaller, and initialize my_length with the smallest word length
                if ( strlen(temporary3) > strlen(string_array_unique[a_k-1]) ) {

                    // Initialize my_length with the length of the current word at the largest probability index
                    my_length = strlen(string_array_unique[a_k-1]);
                } else {

                    // Initialize my_length with the length of the users key
                    my_length = strlen(temporary3);
                }

                // Reset variable k
                k = 0;

                // while k is less than the length of the smallest word
                while ( k < my_length ) {

                    // If the current letter at index k in string_array_unique is greater then the current letter at index k in the users key, traverse left
                    if ( string_array_unique[a_k-1][k] > temporary3[k] ) {

                        // If left or right equals 0 or 600, then no match was found
                        if ( left == 0 || right == 0 || left == 600 || right == 600 ) {
                            tk = 600;
                            break;
                        }

                        // Initialize store_str with the current word at the largest probability index
                        strcpy ( store_str, string_array_unique[a_k-1] );
                        // Initialize store_float as the current frequency
                        store_float = C[the_1][the_n];

                        // Update variables
                        the_n = a_k-1;
                        a_k = left;

                        // Check if the current word with the largest probability, is equal to the users key
                        if ( strcmp ( string_array_unique[a_k-1], temporary3 ) == 0 ) {

                            // Print to stdout that a match was found
                            printf ( "Compared with %s (%.3f), go left subtree.\n", store_str, store_float );
                            printf ( "Compared with %s (%.3f) found.\n", string_array_unique[a_k-1], C[the_1][the_n] );

                            // Update variables that a match has been found
                            found_check = 1;
                            tk = 600;
                            break;
                        }

                        // Continue to search through the optimal BST and print the current word and its frequency to the user
                        printf ( "Compared with %s (%.3f), go left subtree.\n", store_str, store_float );

                        // Update the left and right variables forthe next search
                        left = R[the_1][a_k-1];
                        right = R[a_k+1][the_n];

                    }
                    
                    // If the current letter at index k in string_array_unique is less then the current letter at index k in the users key, traverse right
                    else if ( string_array_unique[a_k-1][k] < temporary3[k] ) {

                        // If left or right equals 0 or 600, then no match was found
                        if ( left == 0 || right == 0 || left == 600 || right == 600 ) {
                            tk = 600;
                            break;
                        }

                        // Initialize store_str with the current word at the largest probability index
                        strcpy ( store_str, string_array_unique[a_k-1] );
                        // Initialize store_float as the current frequency
                        store_float = C[the_1][the_n];

                        // Update variables
                        the_1 = a_k+1;
                        a_k = right;

                        // Check if the current word with the largest probability, is equal to the users key
                        if ( strcmp ( string_array_unique[a_k-1], temporary3 ) == 0 ) {

                            // Print to stdout that a match was found
                            printf ( "Compared with %s (%.3f), go right subtree.\n", store_str, store_float );
                            printf ( "Compared with %s (%.3f) found.\n", string_array_unique[a_k-1], C[the_1][the_n]);

                            // Update variables that a match has been found
                            found_check = 1;
                            tk = 600;
                            break;
                        }

                        // Continue to search through the optimal BST and print the current word and its frequency to the user
                        printf ( "Compared with %s (%.3f), go right subtree.\n", store_str, store_float );

                        // Update the left and right variables forthe next search
                        left = R[the_1][a_k-1];
                        right = R[a_k+1][the_n];

                    }

                    // Update the current letter by implementing k, and continue searching
                    else {
                        k++;
                    }

                }

            }

            // If the found_check variable is 0, no matches were found in the Optimal BST, print "Not found." to stdout
            if ( found_check == 0 ) {
                printf ( "Not found.\n");
            }

            free ( temporary3 );
            free ( temporary4 );
            free ( temporary5 );
            free ( store_str );
            free ( algorithm_input );

        }

        else if ( strcmp ( algorithm_input, "2" ) == 0 ) {

            // Integer variables used throughout the program
            int temp_track = 0;
            int other_tracker = 0;
            int tk = 0;

            // String ( char * ) and String arrays ( charr ** ) used throughout the function
            char *temporary4 = malloc ( sizeof ( char * ) + 256 );
            char *temporary5 = malloc ( sizeof ( char * ) + 256 );

            // Prompt the user for input
            printf ( "Enter a string: " );

            // Read the users input from stdin 
            if ( ( fgets ( temporary4, 256, stdin ) == NULL ) && ferror ( stdin ) ) {
                perror ( "Error: fgets()" );
            }

            // Remove the '\n' character from the users input
            for ( i = 0; temporary4[i] != '\0'; i++ ) {}
            temporary4[i-1] = '\0';

            // Call the Greedy_tree function to search through the Optimal BST with the users key using the greedy technique
            Greedy_Tree ( tk, probability_array, 0, 600, 0, temporary4, temporary5, temp_track, string_array_unique, temp_float, other_tracker );

        }

		else if ( strcmp ( algorithm_input, "exit" ) == 0 || strcmp ( algorithm_input, "EXIT" ) == 0 || strcmp ( algorithm_input, "Exit" ) == 0) {

			printf ( "Thank you for using the Assignment 4 program! Have a good day!\n\n" );

			// Set the exit_check variable to 0, indicating the user has exited the program
			exit_check = 0;

		}
		
		// If any other input was entered, notify the user the input was invalid and prompt the user for input again
		else {

			printf ( "That is not a valid input\nPlease enter the number corresponding to an algorithm or 'exit' to exit the program:\n\n" );

		}

    }

    // Free all strings in the string_array
    for ( i = 0; i < k; i++ ) {
        free ( string_array[i] );
    }

    for ( i = 0; i < 600; i++ ) {
        free ( string_array_unique[i] );
    }

    // Free other string ( char * ) variables used throughout the function
	free ( temporary );
    free ( temporary2 ); 
    free ( string_array );
    free ( string_array_unique );

    // End of program
    return ( 0 );

}
