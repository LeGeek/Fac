#include "avl.h"

#include <iostream>

#ifndef NULL
#define NULL 0
#endif

#define GRAPHVIZ_NULL_STYLE " [shape=circle, fixedsize=true, width=0.15, fillcolor=\"black\", style=filled, label=\"\"];"

/* --- PUBLIC --- */

template< typename T >
AVL<T>::AVL( T value, AVL * parent, AVL * left, AVL * right ) : value( value ), 
    left( left ), right( right ), parent( parent )
{
    level = 1;
    updateLevel();
}

template< typename T >
AVL<T>::~AVL()
{
    delete left;
    delete right;
}

template< typename T >
int AVL<T>::getLevel()
{
    return level;
}

template< typename T >
int AVL<T>::getLeftLevel()
{
    if( left == NULL )
        return 0;

    return left->getLevel();
}

template< typename T >
int AVL<T>::getRightLevel()
{
    if( right == NULL )
        return 0;

    return right->getLevel();
}

template< typename T >
bool AVL<T>::contains( T val )
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
bool AVL<T>::insert( T val )
{
    AVL<T> * cursor = this;

    while( true )
    {
        if( val < cursor->value )
        {
            if( cursor->left == NULL )
            {
                cursor->left = new AVL( val, cursor );
                cursor->left->updateLevel();
                cursor->left->balance();
                return true;
            }

            cursor = cursor->left;
        }
        else if( val > cursor->value )
        {
            if( cursor->right == NULL )
            {
                cursor->right = new AVL( val, cursor );
                cursor->right->updateLevel();
                cursor->right->balance();
                return true;
            }

            cursor = cursor->right;
        }
        else
        {
            std::cerr << "'" << val << "' is already in the tree !" << std::endl;
            return false;
        }
    }
}

template< typename T >
void AVL<T>::remove( T val )
{
    AVL<T> * cursor = this;

    while( cursor != NULL )
    {
        if( cursor->value > val )
        {
            cursor = cursor->left;
        }
        else if( cursor->value < val )
        {
            cursor = cursor->right;
        }
        else
        {
            if( cursor->right == NULL && cursor->left == NULL )
            {
                if( cursor->parent->right == cursor )
                    cursor->parent->right = NULL;
                else
                    cursor->parent->left = NULL;
            }
            else if( cursor->right == NULL && cursor->left != NULL )
            {
                if( cursor->parent != NULL )
                {
                    if( cursor->parent->right == cursor )
                        cursor->parent->right = cursor->left;
                    else
                        cursor->parent->left = cursor->left;
                }

                cursor->left->parent = cursor->parent;
            }
            else if( cursor->right != NULL && cursor->left == NULL )
            {
                if( cursor->parent != NULL )
                {
                    if( cursor->parent->right == cursor )
                        cursor->parent->right = cursor->right;
                    else
                        cursor->parent->left = cursor->right;
                }

                cursor->right->parent = cursor->parent;
            }
            else
            {
                AVL<T> * savePtr = cursor;

                cursor = cursor->left;
                while( cursor->right != NULL )
                    cursor = cursor->right;

                if( cursor->parent->value != val )
                    cursor->parent->right = cursor->left;

                if( cursor->left != NULL )
                {
                    cursor->left->parent = cursor->parent;
                    if( cursor->parent->right == cursor )
                        cursor->parent->right = cursor->left;
                    else
                        cursor->parent->left = cursor->left;
                }
                else
                {
                    savePtr->left = NULL;
                }

                savePtr->value = cursor->value;
            }

            cursor->parent->updateLevel();
            cursor->left = NULL;
            cursor->right = NULL;
            delete cursor;
            return;
        }
    }
}

template< typename T >
void AVL<T>::drawGraph(std::ostream & fs)
{
    fs << value << "[label=\"" << value << " (" << level << ")\"]" << std::endl;
    if( left == NULL && right == NULL )
        return;

    static int nullnb = 0;
    if( left != NULL )
    {
        fs << value << " -> " << left->value << ";" << std::endl;
        left->drawGraph( fs );
    }
    else
    {
        fs << "NULL" << nullnb << GRAPHVIZ_NULL_STYLE << std::endl;
        fs << value << " -> NULL" << nullnb << ";" << std::endl;
        ++nullnb;
    }

    if( right != NULL )
    {
        fs << value << " -> " << right->value << ";" << std::endl;
        right->drawGraph( fs );
    }
    else
    {
        fs << "NULL" << nullnb << GRAPHVIZ_NULL_STYLE << std::endl;
        fs << value << " -> NULL" << nullnb << ";" << std::endl;
        ++nullnb;
    }
}

template< typename T >
void AVL<T>::updateLevel()
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
void AVL<T>::balance()
{
    if( left == NULL && right == NULL )
    {
        if( parent != NULL )
            parent->balance();
    }
    else if( left == NULL && right->getLevel() > 1 )
    {
        if( right->getLeftLevel() > right->getRightLevel() )
            right->rotateRight();

        rotateLeft();
    }
    else if( right == NULL && left->getLevel() > 1 )
    {
        if( left->getRightLevel() > left->getLeftLevel() )
            left->rotateLeft();

        rotateRight();
    }
    else if( left != NULL && right != NULL )
    {
        if( left->getLevel() - right->getLevel() > 1 )
        {
            if( left->getRightLevel() > left->getLeftLevel() )
                left->rotateLeft();

            rotateRight();
        }
        else if( right->getLevel() - left->getLevel() > 1 )
        {
            if( right->getLeftLevel() > right->getRightLevel() )
                right->rotateRight();

            rotateLeft();
        }
        else if( parent != NULL )
            parent->balance();
    }
    else
    {
        if( parent != NULL )
            parent->balance();
    }
}

template< typename T >
void AVL<T>::rotateRight()
{
    if( parent != NULL )
    {
        if( parent->left == this )
            parent->left = left;
        else
            parent->right = left;
    }

    left->parent = parent;
    parent = left;

    AVL<T> * tmp = left;
    left = left->right;
    tmp->right = this;
    
    if( left != NULL )
        left->parent = this;

    updateLevel();
}

template< typename T >
void AVL<T>::rotateLeft()
{
    if( parent != NULL )
    {
        if( parent->left == this )
            parent->left = right;
        else
            parent->right = right;
    }

    right->parent = parent;
    parent = right;

    AVL<T> * tmp = right;
    right = right->left;
    tmp->left = this;

    if( right != NULL )
        right->parent = this;

    updateLevel();
}

