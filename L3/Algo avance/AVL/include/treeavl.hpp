#include "treeavl.h"

#include <iostream>

#ifndef NULL
#define NULL 0
#endif

/* --- PUBLIC --- */

template< typename T >
TreeAVL<T>::TreeAVL( T value, TreeAVL * parent, TreeAVL * left, TreeAVL * right ) : value( value ), 
    parent( parent ), left( left ), right( right )
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
    static int nullnb = 0;
    if( left != NULL )
    {
        std::cout << value << " -> " << left->value << ";" << std::endl;
        left->affiche();
    }
    else
    {
        std::cout << "NULL" << nullnb << " [shape=point];" << std::endl;
        std::cout << value << " -> NULL" << nullnb << ";" << std::endl;
        ++nullnb;
    }

    if( right != NULL )
    {
        std::cout << value << " -> " << right->value << ";" << std::endl;
        right->affiche();
    }
    else
    {
        std::cout << "NULL" << nullnb << " [shape=point];" << std::endl;
        std::cout << value << " -> NULL" << nullnb << ";" << std::endl;
        ++nullnb;
    }
}

/* --- PRIVATE --- */
template< typename T >
int TreeAVL<T>::updateLevel()
{
    int levelLeft = 0;
    int levelRight = 0;

    if( left != NULL )
        levelLeft = left->updateLevel();

    if( right != NULL )
        levelRight = right->updateLevel();

    if( levelLeft > levelRight )
        level = levelLeft + 1;
    else
        level = levelRight + 1;
    
    return level;
}
