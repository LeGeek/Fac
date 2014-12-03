#include "abr.h"
#include "utils.h"

void AR_arbreBinaire( int * tab, int taille )
{
    if( taille == 0 )
        return;

    TreeAbr * root = (TreeAbr*) malloc( sizeof( TreeAbr ) );
    AR_initTreeAbr( root, tab[0] );

    for ( int i = 1; i < taille; ++i )
    {
        //printf ("Pos : %d - %p\n", i, root);
        AR_placerElement( root, tab[i] );
    }

    int p = 0;
    AR_rangerTableau( tab, &p, root );

    while( p < taille )
        tab[p++] = 2147483647;

    AR_detruireArbre( root );
    root = NULL;
}

void AR_placerElement( TreeAbr * head, int element )
{
    if( element == head->value )
    {
        //printf( "Attention : élément %d existant, non ajouté\n", element );
        return;
    }

    if( element < head->value )
    {
        if( head->left != NULL )
        {
            AR_placerElement( head->left, element );
        }
        else
        {
            TreeAbr * tmp = (TreeAbr*) malloc( sizeof( TreeAbr ) );
            AR_initTreeAbr( tmp, element );

            head->left = tmp;
        }
    }
    else
    {
        if( head->right != NULL )
        {
            AR_placerElement( head->right, element );
        }
        else
        {
            TreeAbr * tmp = (TreeAbr*) malloc( sizeof( TreeAbr ) );
            AR_initTreeAbr( tmp, element );

            head->right = tmp;
        }
    }
}

void AR_rangerTableau( int * tab, int * pos, const TreeAbr * head )
{
    if( !head )
        return;
        
    AR_rangerTableau( tab, pos, head->left );
    tab[(*pos)++] = head->value;
    AR_rangerTableau( tab, pos, head->right );
}

void AR_detruireArbre( TreeAbr * head )
{
    if( head == NULL ){ return ; }

    AR_detruireArbre( head->left );
    AR_detruireArbre( head->right );

    free( head );
    head = NULL;
}

void AR_initTreeAbr( TreeAbr * s, int value )
{
    s->value = value;
    s->left = NULL;
    s->right = NULL;
}

