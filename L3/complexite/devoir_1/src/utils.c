#include "utils.h"

int * genererTableau( int taille, bool init )
{
    if( init )
        return (int*)calloc(taille, sizeof( int ) );
    else
        return (int*)malloc(taille * sizeof( int ) );
}

int randomMinMax( int min, int max )
{
    static bool utils_seedChange = false;
    
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

int chercherPetit( const int * tab, int debut, int fin )
{
    int p = debut;

    for(int i = debut; i < fin; ++i )
    {
        if( tab[i] < tab[p] )
            p = i;
    }
    return p;
}

