#include "node.h"

template<class T>
Node::Node( T key, int tabSize )
{
    this.key = key;
    next = new T[ tabSize ];
}

template<class T>
Node::Node( Node & node )
{
    key = node.key;
    next = node.next;
}

