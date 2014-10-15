#include "treeavl.h"

#ifndef NULL
#define NULL 0
#endif

/* --- PUBLIC --- */

template< typename T >
TreeAVL<T>::TreeAVL( T value, TreeAVL * left, TreeAVL * right ) : value( value ), 
    left( left ), right( right )
{
    level = 0;
    updateLevel();
}

template< typename T >
TreeAVL<T>::~TreeAVL()
{
}

template< typename T >
int TreeAVL<T>::getLevel()
{
    return level;
}

template< typename T >
bool TreeAVL<T>::contains( T val )
{
    if( value == val )
        return true;

    if( val < value && left != NULL )
        return left->contains( val );
    else if( val > value && right != NULL )
        return right->contains( val );

    return false;

}

template< typename T >
void TreeAVL<T>::insert( T val )
{
    TreeAVL<T> * cursor = this;

    while( true )
    {
        if( val < cursor->value )
        {
            if( cursor->left == NULL )
            {
                cursor->left = new TreeAVL( val );
                break;
            }

            cursor = cursor->left;
        }
        else
        {
            if( cursor->right == NULL )
            {
                cursor->right = new TreeAVL( val );
                break;
            }

            cursor = cursor->right;
        }
    }

    updateLevel();
}

template< typename T>
void TreeAVL<T>::affiche()
{
    std::vector<T> * tab = new std::vector<T>[ level + 1 ];
   
    affiche( tab );

    for( int i = level; i >= 0; --i )
    {
        std::cout << "[" << i << "]\t";
        for( int j = 0; j < tab[i].size(); ++j )
            std::cout << tab[i][j] << " ";
        std::cout << std::endl;
    }
}

template< typename T>
void TreeAVL<T>::affiche( std::vector<T> * tab )
{
    if( left != NULL )
        left->affiche( tab );
    
    tab[level].push_back( value );

    if( right != NULL )
        right->affiche( tab );
}

/* --- PRIVATE --- */
template< typename T >
void TreeAVL<T>::updateLevel()
{
    int levelLeft = 0;
    int levelRight = 0;

    if( left != NULL )
        levelLeft = left->getLevel();

    if( right != NULL )
        levelRight = right->getLevel();

    if( levelLeft < levelRight )
        level = levelLeft + 1;
    else
        level = levelRight + 1;
}
