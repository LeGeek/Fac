#include "insertseq.h"
#include "utils.h"

void IS_insertionSequentielle( int * tab, int taille )
{
    int x, p;
    for(int i = 0; i < taille; ++i )
    {
        p = chercherPetit( tab, i, taille );
        x = tab[p];

        decalerTableau( tab, i, p );
        tab[i] = x;
    }
}


