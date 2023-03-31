#include <stdio.h>

main ( int argc, char **argv ) {

    int temp;
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {3, 7, 4, 13, 5};

    for ( int i = 0; i < 5; i++ ) {
        for ( int j = (i+1); i < 5; j++ ) {
            if ( arr1[j] > arr2[i] ) {
                temp = arr1[j];
                arr1[j] = arr2[i];
                arr2[i] = temp;
            }
        }
    }

    for ( int i = 0; i < 5; i++ ) {
        printf ( "%d %d\n", arr1[i], arr2[i] );
    }

    return ( 0 );

}