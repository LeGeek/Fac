#ifndef __NODE_H__
#define __NODE_H__

/**
 * \class Node node.h __NODE_H__
**/
template <class T>
class Node
{
    T key;
    Node<T> * next;

    Node( T value, int tabSize );
    Node( Node & t );
    virtual ~Node();
};

#endif
