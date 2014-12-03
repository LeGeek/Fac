#include "quick.h"
#include "utils.h"


void QS_quickSort( int * tab, int taille )
{
    QS_sort( tab, 0, taille );
}

void QS_sort( int * tab, int debut, int fin )
{
    if( debut >= fin)
        return;

    int pivot = QS_placerPivot( tab, debut, fin );

    QS_sort( tab, debut, pivot );
    QS_sort( tab, pivot+1, fin );
}

int QS_placerPivot( int * tab, int debut, int fin )
{
    int p = debut;

    for( int i = p+1; i < fin; ++i )
    {
        if( tab[i] < tab[p] )
        {
            swapi( &tab[i], &tab[p] );
            swapi( &tab[i], &tab[p+1] );
            ++p;
        }
    }
    
    return p;
}
