Name: Carson Mifsud
Date: 2021-03-29
Student ID: 1089936
Assignment: 4

To run the program main.c:
Enter: 'make all'

To execute the programs listed above:
Enter: './A4'

The above command will run the main program and allow the user to
choose which searching method to run, by entering the algorithms
corresponding number

Limitations:
Assume 'data_7.txt' will be used when testing the program, as it has been hard coded into the program
Assume a limit of 256 characters for user input
Assume a maximum of 256 characters for every word in the data_7.txt file
Assume an both recursive and iterative methods are acceptable
Assume the search is case sensitive

NOTES:
The functionality of the OptimalBST function was recieved from 'Introduction to the Design and Analysis of Algorithms' on page 302
The program functionality was implemented using a "virtual tree"
The program uses an infinite while loop that continuously prompts the user for input until they have entered 'exit'
See program comments for further explanation about the program and search method functionality
Program provides exact output for the extamples provided by Professor Wang

TEST CASE:
    - The user is prompted to enter a number which corresponds to a search method
    - The user enters either '1' or '2'
    - The program will then prompt the user to enter a key
    - The specified search algorithm will run and print out the desired output to stdout
    - The user may continue to run the program with a different search method and various inputs
    - To end the program the user must type 'exit'