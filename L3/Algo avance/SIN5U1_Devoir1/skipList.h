#include <vector>
#include <string>

#include "node.h"
#include "random.h"


template <class T>
class SkipList
{

  public:
    SkipList();
    virtual ~SkipList();

    bool contains( T key );
    void add( T key );
    void remove( T key );
    std::vector<T> toList();
    std::string toString();

  private:
    Node<T> head;
    int level;
    Random alea;
    long size;
    double proba;
    Node<T> * insertPoint;
};