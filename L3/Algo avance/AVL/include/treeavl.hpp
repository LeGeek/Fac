#include "treeavl.h"

template< typename T >
TreeAVL<T>::TreeAVL()
{
    head = NULL;
}

template< typename T >
bool TreeAVL<T>::insert( T value )
{
    if( head == NULL )
    {
        head = new AVL<T>( value );
        return true;
    }
    else
    {
        relocateHead();
        return head->insert( value );
    }
}

template< typename T >
void TreeAVL<T>::remove( T value )
{
    if( head == NULL )
    {
        return;
    }
    else
    {
        relocateHead();
        head->remove( value );
    }
}

template< typename T >
bool TreeAVL<T>::contains( T val )
{
    if( head == NULL )
        return false;

    relocateHead();
    return head->contains( val );
}

template< typename T >
void TreeAVL<T>::drawGraph( std::ostream & fs)
{
    relocateHead();
    
    fs << "digraph G {" << std::endl;
    head->drawGraph( fs );
    fs << "}\n" << std::endl;
}

template< typename T>
void TreeAVL<T>::drawGraph( const char * file )
{
    std::ofstream f( file, std::ofstream::out | std::ofstream::trunc );
    drawGraph( f );
    f.close();
}

template< typename T >
void TreeAVL<T>::clear()
{
    relocateHead();
    delete head;
    head = NULL;
}

template< typename T >
int TreeAVL<T>::getLevel()
{
    relocateHead();
    return head->getLevel();
}

template< typename T >
void TreeAVL<T>::relocateHead()
{
    if( head == NULL || head->parent == NULL)
        return;

    while( head->parent != NULL )
    {
        head = head->parent;
    }
}


