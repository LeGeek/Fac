#include "treeavl.h"

#include <iostream>

#ifndef NULL
#define NULL 0
#endif

/* --- PUBLIC --- */

template< typename T >
TreeAVL<T>::TreeAVL( T value, TreeAVL * parent, TreeAVL * left, TreeAVL * right ) : value( value ), 
    left( left ), right( right ), parent( parent )
{
    level = 1;
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
                cursor->left = new TreeAVL( val, cursor );
                cursor->left->updateLevel();
                break;
            }

            cursor = cursor->left;
        }
        else
        {
            if( cursor->right == NULL )
            {
                cursor->right = new TreeAVL( val, cursor );
                cursor->right->updateLevel();
                break;
            }

            cursor = cursor->right;
        }
    }

}

template< typename T>
void TreeAVL<T>::affiche()
{
    std::cout << value << "[label=\"" << value << " (" << level << ")\"]" << std::endl;
    if( left == NULL && right == NULL )
        return;

    static int nullnb = 0;
    if( left != NULL )
    {
        std::cout << value << " -> " << left->value << ";" << std::endl;
        left->affiche();
    }
    else
    {
        std::cout << "NULL" << nullnb << " [shape=none, fontsize=0];" << std::endl;
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
        std::cout << "NULL" << nullnb << " [shape=none, fontsize=0];" << std::endl;
        std::cout << value << " -> NULL" << nullnb << ";" << std::endl;
        ++nullnb;
    }
}

template< typename T >
void TreeAVL<T>::updateLevel()
{
    int lvlLeft = 0;
    int lvlRight = 0;

    if( left != NULL )
        lvlLeft = left->getLevel();

    if( right != NULL )
        lvlRight = right->getLevel();

    if( lvlRight > lvlLeft )
        level = lvlRight + 1;
    else
        level = lvlLeft + 1;

    if( parent != NULL )
        parent->updateLevel();
}

template< typename T >
void TreeAVL<T>::balance()
{
    if( left != NULL || right != NULL )
    {
        if( parent != NULL )
            parent->balance();
    }
    else
    {
        if( left->getLevel() - right->getLevel() > 1 ||
            right->getLevel() - left->getLevel() > 1 )
            std::cout << value << " unbalanced !" << std::endl;
            return;
    }
}

