#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>
#include <limits.h>

// Name: Carson Mifsud
// Date: 2021-03-15
// Assignment: 3

int table[126];

typedef struct {

	char *not_sorted;
	char *sorted;

} integer_sort;

typedef struct {

	char *not_sorted;
	char *sorted;

} input_sort;

void PresortAnagram ( integer_sort *integer_array, input_sort *input );
void BruteForceAnagram ( integer_sort *integer_array, input_sort *input );
void ShiftTable ( char *input );
void HorspoolStringSearch ( char *text_file, char *input );
void BruteForceStringSearch ( char *text_file, char *input );
int sorted_compare ( const void *i, const void *j );
int sorted_compare_individual ( const void *i, const void *j );
void GoodSuffixTable ( int *ShiftTable, int *BadTable, char *input );
void BadSuffixTable ( int *ShiftTable, int *BadTable, char *input );
void BoyerMooreStringSearch ( char *text_file, char *input );
