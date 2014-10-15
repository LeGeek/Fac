
#include <iostream>

#include "treeavl.h"

int main( int argc, char** argv )
{
    (void) argc;
    (void) argv;

    TreeAVL<int> avl( 10,
            new TreeAVL<int>(5,
                new TreeAVL<int>( 2, NULL, NULL ),
                new TreeAVL<int>( 7, NULL, NULL )),
            new TreeAVL<int>( 15,
                new TreeAVL<int>( 12, NULL ),
                new TreeAVL<int>( 20, NULL ))
            );

    avl.affiche();
    std::cout << std::endl;

    avl.insert( 50 );

    avl.affiche();
    std::cout << std::endl;

    return 0;
}
