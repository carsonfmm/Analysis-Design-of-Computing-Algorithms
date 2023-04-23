#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

// Name: Carson Mifsud
// Date: 2021-02-20
// Assignment: 2

int bruteForceAlgorithm ( int integer_array[], int top );
int merge ( int integer_array[], int bottom, int half, int top );
int divideAndConquerMergesort ( int integer_array[], int bottom, int top );
int convexHullBruteForce ( int count, float float_array[] );
void quickHull ( float float_arrayX[], float float_arrayY[], int n, float p1x, float p1y, float p2x, float p2y, int side );
int convexHullQuickHull ( float float_arrayX[], float float_arrayY[], int n );
