#include "fusion.h"
#include "utils.h"

void FU_fusion( int * tab, int taille )
{
    FU_trierTableau( tab, 0, taille-1 );    
}

void FU_trierTableau( int * tab, int debut, int fin )
{
    if( debut >= fin )
        return;

    FU_trierTableau( tab, debut, (debut + fin)/2 );
    FU_trierTableau( tab, (debut + fin)/2 + 1, fin );
    FU_fusionTableau( tab, debut, fin );   
}

void FU_fusionTableau( int * tab, int debut, int fin )
{
    int m = (debut + fin) / 2;
    int  * tmp = genererTableau(fin-debut+1, true );
    int i = debut;
    int j = m+1;
    int k = 0;

    while( i <= m && j <= fin )
    {
        if( tab[i] <= tab[j] )
            tmp[k++] = tab[i++];
        else
            tmp[k++] = tab[j++];
    }

    while( i <= m )
        tmp[k++] = tab[i++];

    while( j <= fin )
        tmp[k++] = tab[j++];


    for( --k; k >= 0; --k )
        tab[debut+k] = tmp[k];

    free( tmp );
}
