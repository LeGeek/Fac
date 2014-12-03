#include "bulle.h"
#include "utils.h"

void BL_bulle( int * tab, int taille )
{
    bool elementEchange = true;
    while( elementEchange )
    {
        elementEchange = false;
        for( int i = 1; i < taille; ++i )
        {
            if( tab[i-1] > tab[i] )
            {
                elementEchange = true;
                swapi( &tab[i-1], &tab[i] );
            }
        }
    }
}
