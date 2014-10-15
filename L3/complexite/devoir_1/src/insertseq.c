#include "insertseq.h"
#include "utils.h"

void IS_insertionSequentielle( int * tab, int taille )
{
    int x, p;
    for(int i = 0; i < taille; ++i )
    {
        p = IS_cherchePetit( tab, i, taille );
        x = tab[p];

        decalerTableau( tab, i, p );
        tab[i] = x;
    }
}

int IS_cherchePetit( const int * tab, int debut, int fin )
{
    int p = debut;

    for(int i = debut; i < fin; ++i )
    {
        if( tab[i] < tab[p] )
            p = i;
    }
    return p;
}

