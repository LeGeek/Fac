#include "insertdicho.h"
#include "utils.h"

void ID_insertionDichotomique( int * tab, int taille )
{
    int val, pos;
    for( int i = 1; i < taille; ++i )
    {
        val = tab[i];
        pos = ID_chercherPosition( val, tab, 0, i );

        printf( "Position de %d en %d\n", val, pos );

        decalerTableau( tab, i, pos );
        tab[pos] = val;
    }
}

int ID_chercherPosition( int value, const int * tab, int debut, int fin )
{
    if( value > tab[fin] )
        return fin;

    int pos;
    while( debut != fin )
    {
        pos = (debut+fin) / 2;

        if( value < tab[pos] )
        {
            fin = pos;
        }
        else
        {
            debut = pos+1;
        }
    }

    return debut;
}
