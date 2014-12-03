#include "selectpermut.h"
#include "utils.h"

void SP_selectionPermutation( int * tab, int taille )
{
    int pos;
    for( int i = 0; i < taille; ++i )
    {
        pos = chercherPetit( tab, i, taille );
        swapi( &tab[i], &tab[ pos ] );
    }
}

