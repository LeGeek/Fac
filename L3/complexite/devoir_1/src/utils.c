#include "utils.h"


int * genererTableau( int size, bool init )
{
    if( init )
        return (int*)malloc(size * sizeof( int ) );
    else
        return (int*)calloc(size, sizeof( int ) );
}

int random( int min, int max )
{
    if( !utils_seedChange )
    {
        srand( time(NULL) );
        utils_seedChange = true;
    }

    return rand()%(max-min) + min;
}

void swapi( int * a, int * b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void decalerTableau( int * tab, int debut, int fin )
{
    for( int i = fin; i >= debut; --i )
    {
        tab[i] = tab[i-1];
    }
}

