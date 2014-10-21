
#include <iostream>

#include "treeavl.h"

using namespace std;

int main( int argc, char** argv )
{
    (void) argc;
    (void) argv;

    TreeAVL<int> avl( 10 );
   
    cout << "digraph G {" << endl;
    avl.affiche();
    cout << "}\n" << endl;
    
    avl.insert( 5 );
    avl.insert( 2 );
    avl.insert( 7 );
    avl.insert( 15 );
    avl.insert( 12 );
    avl.insert( 20 );
    avl.insert( 50 );
    avl.insert( 43 );
    avl.insert( 135 );
    avl.insert( 798 );
    avl.insert( 13 );
    avl.insert( 79 );

    cout << "digraph G {" << endl;
    avl.affiche();
    cout << "}\n" << endl;

    return 0;
}
