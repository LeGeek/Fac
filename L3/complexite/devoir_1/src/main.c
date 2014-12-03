#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "utils.h"

#include "abr.h"
#include "bulle.h"
#include "fusion.h"
#include "insertdicho.h"
#include "insertseq.h"
#include "quick.h"
#include "selectpermut.h"
#include "tas.h"

typedef void (*fonctionTri)(int*, int);

#define NOMBRE_TEST_PAR_ALGO    (float)(20.0)

#define WATCHDOG_MAX_TIME  (5*60)*CLOCKS_PER_SEC

#define TAB_VALUE_SIZE  15
const int TAB_VALUE[TAB_VALUE_SIZE] = {100,500,5000,10000,50000,100000,200000,300000,400000,500000,600000,700000,800000,900000,1000000};

#define TAB_FONCTION_SIZE 8
const fonctionTri TAB_FONCTION[TAB_FONCTION_SIZE] = {&IS_insertionSequentielle, &ID_insertionDichotomique,
                                                    &SP_selectionPermutation, &BL_bulle, &FU_fusion, 
                                                    &QS_quickSort,
                                                    &AR_arbreBinaire,
                                                    &TS_triParTas};

const char * TAB_FONCTION_NAME[TAB_FONCTION_SIZE] = {"Insertion sequentielle", "Insertion Dichotomique",
                                                    "Selection permutation", "Bulle", "Fusion", 
                                                    "QuickSort", "Arbre binaire", "Par tas"};

static clock_t start;
pthread_t watchdogThread;

void * watchDog( void * args )
{
    (void) args;
    
    while( ( clock() - start ) < WATCHDOG_MAX_TIME )
        system( "sleep 1" );
    
    printf( "WatchDog processus tué;;\n" );
    exit( 2 );
    pthread_exit( NULL );
}

bool testBienTrie( int * tab, int size )
{
    for( int i = 1; i < size; ++i )
        if( tab[i-1] > tab[i] )
            return false;

    return true;
}

void afficheTableau( const int * tab, int taille )
{
    for( int i = 0; i < taille; ++i )
        printf( "%d ", tab[i] );

    printf("\n\n");
}

void sort( fonctionTri f, const char * name )
{
    printf( "Démarrage du WatchDog;;\n" );
    start = clock();
    if( pthread_create( &watchdogThread, NULL, watchDog, NULL ) == -1 )
    {
        perror( "pthread_create" );
        exit( 1 );
    }

    for( int n = 0; n < TAB_VALUE_SIZE; ++n )
    {
        float moy = 0.0;
        int * t = genererTableau( TAB_VALUE[ n ], true );
    
        for( int i = 0; i < NOMBRE_TEST_PAR_ALGO; ++i )
        {
            start = clock();
            for( int j = 0; j < TAB_VALUE[ n ]; ++j )
                t[j] = randomMinMax( 0, 2147483647 );

            f( t, TAB_VALUE[ n ] );

            /*afficheTableau( t, TAB_VALUE[ n ] );
            if( testBienTrie( t, TAB_VALUE[n] ) )
            {
                printf( "\t==> Le tableau est BIEN trié\n" );
            }
            else
            {
                printf( "\t==> Le tableau est MAL trié\n" );
                exit( -1 );
            }*/
           
            moy += (float)( clock() - start ) / CLOCKS_PER_SEC;
        }

        printf( "%s; %d; %f\n", name, TAB_VALUE[ n ], (moy/NOMBRE_TEST_PAR_ALGO ) );

        free( t );
    }
}

int main( int argc, char** argv )
{
    (void) argc;
    (void) argv;
    
    printf( "TODO:\
            \n\t1. Tri par insertion séquentiel **DONE**\
            \n\t2. Tri par insertion dichotomique **DONE**\
            \n\t3. Tri par selection-permutation **DONE**\
            \n\t4. Tri à bulle **DONE**\
            \n\t5. Tri par fusion **DONE**\
            \n\t6. Tri rapide (QuickSort) **DONE**\
            \n\t7. Tri à l'aide d'arbre binaire de recherche **DONE**\
            \n\t8. Tri par tas **DONE**\n\n");
    
    printf( " TEST : \n" );

    for( int algo = 0; algo < TAB_FONCTION_SIZE; ++algo)
    {
        if( fork() == 0 )
        {
            sort( TAB_FONCTION[ algo ], TAB_FONCTION_NAME[ algo ] );
            exit( 0 );
        }
        else
        {
            wait( NULL );
        }
    }

    return 0;
}
