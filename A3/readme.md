Name: Carson Mifsud
Date: 2021-03-15
Assignment: 2

To run the programs P11.c, P12.c, P21.c, P22.c, P23.c and main.c:
Enter: 'make all'

To execute the programs listed above:
Enter: './A3'

The above commands will run all 6 programs and allow the user to
choose which algorithm to run, by entering the algorithms
corresponding number

Limitations:
Assume 'data_4.txt' and the updated 'data_52.txt' files will be used when testing the program, as they have been hard coded into the program
Assume a limit of 100 characters for user input
Assume to only print unique anagrams
Assume to double presort before sending numbers to the function

NOTES:
The 1.1 functionality was implemented using a sequential search which has an average efficiency of size n
The 1.2 double presorting method uses quicksort to sort the strings by signatures then sort the signatures
The 1.2 functionality was implemented using a binary search which has an average efficiency of size 2ln n
The 1.1 and 1.2 functions use a struct array, where each index stores the signature sorted and non-sorted string
The program uses an infinite while loop that continuously prompts the user for input until they have entered 'exit'
See program comments for further explanation about the program and algorithm functionality

TEST CASE:
    - The user is prompted to enter a number which corresponds to an algorithm
    - The user enters either '1', '2', '3', '4', or '5'
    - The program will then prompt the user to enter a string or a pattern
    - The specified program will ru nand print out the desired output to stdout
    - The user may continue to run the program with different algorithms and various inputs
    - To end the program the user must type 'exit'



Question 2.4 Analysis Table:

| Search Number | Search Pattern | Brute Force Execution Time (ms) | Horspool Execution Time (ms) | Brute Force Pattern Shift Count | Horspool Pattern Shift Count |
|~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|       1       |   i            |             22.000000           |           44.000000          |              3296589            |             3296590          |
|---------------|----------------|---------------------------------|------------------------------|---------------------------------|------------------------------|
|       2       |   an           |             21.000000           |           30.000000          |              3296588            |             1697552          |
|---------------|----------------|---------------------------------|------------------------------|---------------------------------|------------------------------|
|       3       |   the          |             21.000000           |           17.000000          |              3296587            |             1142016          |
|---------------|----------------|---------------------------------|------------------------------|---------------------------------|------------------------------|
|       4       |   copy         |             22.000000           |           12.000000          |              3296586            |             864486           |
|---------------|----------------|---------------------------------|------------------------------|---------------------------------|------------------------------|
|       5       |   which        |             22.000000           |           18.000000          |              3296585            |             710193           |
|---------------|----------------|---------------------------------|------------------------------|---------------------------------|------------------------------|
|       6       |   program      |             13.000000           |           15.000000          |              3296583            |             537378           |
|---------------|----------------|---------------------------------|------------------------------|---------------------------------|------------------------------|
|       7       |   academic     |             20.000000           |           15.000000          |              3296582            |             495782           |
|---------------|----------------|---------------------------------|------------------------------|---------------------------------|------------------------------|
|       8       |   automatic    |             24.000000           |           14.000000          |              3296581            |             450080           |
|---------------|----------------|---------------------------------|------------------------------|---------------------------------|------------------------------|
|       9       |   commitment   |             24.000000           |           14.000000          |              3296580            |             429661           |
|---------------|----------------|---------------------------------|------------------------------|---------------------------------|------------------------------|
|       10      |   requirements |             26.000000           |            9.000000          |              3296578            |             366248           |
|---------------|----------------|---------------------------------|------------------------------|---------------------------------|------------------------------|


| Search Number | Ratio of Horspool's shift count / Brute Force shift count  | Ratio of Horspool's execution time / Brute Force execution time |
|~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|       1       |                           1                                |                              2 ( ms )                           |
|---------------|------------------------------------------------------------|-----------------------------------------------------------------|
|       2       |                           0.5149                           |                              1.428 ( ms )                       |
|---------------|------------------------------------------------------------|-----------------------------------------------------------------|
|       3       |                           0.4374                           |                              0.809 ( ms )                       |
|---------------|------------------------------------------------------------|-----------------------------------------------------------------|
|       4       |                           0.2622                           |                              0.54 ( ms )                        |
|---------------|------------------------------------------------------------|-----------------------------------------------------------------|
|       5       |                           0.2154                           |                              0.81 ( ms )                        |
|---------------|------------------------------------------------------------|-----------------------------------------------------------------|
|       6       |                           0.1630                           |                              1.15 ( ms )                        |
|---------------|------------------------------------------------------------|-----------------------------------------------------------------|
|       7       |                           0.1503                           |                              0.75 ( ms )                        |
|---------------|------------------------------------------------------------|-----------------------------------------------------------------|
|       8       |                           0.1365                           |                              0.583 ( ms )                       |
|---------------|------------------------------------------------------------|-----------------------------------------------------------------|
|       9       |                           0.1303                           |                              0.583 ( ms )                       |
|---------------|------------------------------------------------------------|-----------------------------------------------------------------|
|       10      |                           0.1110                           |                              0.3461 ( ms )                      |
|---------------|------------------------------------------------------------|-----------------------------------------------------------------|

Average of shift count ratios: 0.31127
Average of execution times: 0.90511 ( ms )

The average shift count for the 10 input patterns of different lengths is 0.31127. This result proves that the Horspool Algorithm is more efficient as it uses less pattern shifts as the length of the inpute pattern increases. The average execution time for the 10 input patterns of different lengths is 0.90511 ( ms ).  This result proves that the Horspool Algorithm is more efficient as it has a lower execution time as the length of the inpute pattern increases. In conclusion, these results prove that the Horspool algorithm is a more efficient algorithm when used on longer string patterns, and the Brute Force algorithm is more efficient when using small input patterns.
