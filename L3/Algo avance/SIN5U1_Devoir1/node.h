
template <class T>
class Node
{
  public:
    Node( T * value, unsigned nodeTabSize );
    virtual ~Node();

    T * key;
    Node * next;
};