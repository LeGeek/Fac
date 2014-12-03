#include "tas.h"
#include "utils.h"

void TS_triParTas( int * tab, int taille )
{
    TS_formerTas( tab, taille );

    int c, root;
    for( int j = taille - 1; j >= 0; --j )
    {
        root = 0;
        swapi( &tab[root], &tab[j] );

        do 
        {
            c = 2*root + 1;

            if( c < j-1 && tab[c] < tab[c + 1] )
            {
                c++;
            }

            if( c < j && tab[root] < tab[c] )
            {
                swapi( &tab[root], &tab[c] );
            }

            root = c;
        } while( c < j );
    } 
}

void TS_formerTas( int * tab, int taille )
{
    int c, root;
    for( int i = 1; i < taille; i++ )
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             

            if( tab[root] < tab[c] )
            {
                swapi( &tab[root], &tab[c] );
            }

            c = root;
        } while( c != 0 );
    }
}

