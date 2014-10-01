#include "insertseq.h"

void insertionSequentielle( int * tab, int taille )
{
    int x, p;
    for(int i = 0; i < taille; ++i )
    {
        p = cherchePetit( tab, i, taille );
        x = tab[p];

        decaler( tab, i, p );
        tab[i] = x;
    }
}

int cherchePetit( const int * tab, int debut, int fin )
{
    int p = debut;

    for(int i = debut; i < fin; ++i )
    {
        if( tab[i] < tab[p] )
            p = i;
    }
    return p;
}

void decaler( int * tab, int debut, int fin )
{
    for( int i = fin; i >= debut; --i )
    {
        tab[i] = tab[i-1];
    }
}
