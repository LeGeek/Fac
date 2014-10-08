#ifndef __SKIPLIST_H__
#define __SKIPLIST_H__

#include "random.h"

/**
 * \class SkipList skiplist.h __SKIPLIST_H__
 **/

template <class T>
class SkipList
{
    public:
        SkipList();
        virtual ~SkipList();

        long size();
        bool contains( T key );
        void add( T key );
        void remove( T key );
        T[] toList();
        char * toString();

    private:
        Node<T> head;
        int level;
        Random alea;
        long sizeList;
        double proba;
        Node<T> * insertPoint;

#endif
