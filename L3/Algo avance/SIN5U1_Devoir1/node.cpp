#include "node.h"

template <class T>
void Node::Node( T * value, unsigned nodeTabSize )
{
    key = value;
    next = new Node[nodeTabSize];
}

void Node::~Node()
{
}