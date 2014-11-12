#include <stdio.h>

#include "utils.h"
#include "insertdicho.h"

#define TAB_TEST_SIZE   20

int main( int argc, char** argv )
{
    (void) argc;
    (void) argv;
    printf( "TODO:\
            \n\t1. Tri par insertion séquentieli **DONE**\
            \n\t2. Tri par insertion dichotomique **TEST**\
            \n\t3. Tri par selection-permutation\
            \n\t4. Tri à bulle\
            \n\t5. Tri par fusion\
            \n\t6. Tri rapide (QuickSort)\
            \n\t7. Tri à l'aide d'arbre binaire de recherche\
            \n\t8. Tri par tas\
            \n\n\nAu BOULOT !!!!!\n\n" );
    
    printf( " TEST : \n" );

    int t[TAB_TEST_SIZE];
    for( int i = 0; i < TAB_TEST_SIZE; ++i )
        t[i] = random( 0, 65536 );

    for( int i = 0; i < TAB_TEST_SIZE; ++i)
        printf( "%d ", t[i] );
    printf( "\n" );

    //printf (" TRI ICI\n" );
    ID_insertionDichotomique( t, TAB_TEST_SIZE );

    for( int i = 0; i < TAB_TEST_SIZE; ++i)
        printf( "%d ", t[i] );
    printf( "\n" );

    return 0;
}
