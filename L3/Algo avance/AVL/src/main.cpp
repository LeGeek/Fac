
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "treeavl.h"

using namespace std;

void unbalancedRight( TreeAVL<int> & avl )
{
    /*          |-----5-----|
     *      |---3---|       7
     * |----2       4
     * 1
     */
    avl.clear();
    avl.insert( 5 );
    avl.insert( 3 );
    avl.insert( 7 );
    avl.insert( 2 );
    avl.insert( 4 );
    avl.insert( 1 );
}

void unbalancedRightIntern( TreeAVL<int> & avl )
{
    /*          |-------10------|
     *  |-------5-------|       15       
     *  1           |---7
     *              6
     */
    avl.clear();
    avl.insert( 10 );
    avl.insert( 5 );
    avl.insert( 15 );
    avl.insert( 1 );
    avl.insert( 7 );
    avl.insert( 6 );
}

void unbalancedRight2( TreeAVL<int> & avl )
{
    /*          |---5---|
     *      |---3       9
     * |----2
     * 1
     */
    avl.clear();
    avl.insert( 5 );
    avl.insert( 3 );
    avl.insert( 9 );
    avl.insert( 2 );
    avl.insert( 1 );
}

void unbalancedLeft( TreeAVL<int> & avl )
{
    /*  |-------5-------|
     *  4           |---7---|
     *              6       8---|
     *                          9
     */
    avl.clear();
    avl.insert( 5 );
    avl.insert( 4 );
    avl.insert( 7 );
    avl.insert( 6 );
    avl.insert( 8 );
    avl.insert( 9 );
}

void unbalancedLeft2( TreeAVL<int> & avl )
{
    /*  |---5---|
     *  3       7---|
     *              8---|
     *                  9
     */
    avl.clear();
    avl.insert( 5 );
    avl.insert( 3 );
    avl.insert( 7 );
    avl.insert( 8 );
    avl.insert( 9 );
}

void unbalancedLeftIntern( TreeAVL<int> & avl )
{
    /*          |-------10------|
     *          5          |----15----|  
     *                  |--12         20
     *                 11        
     */
    avl.clear();
    avl.insert( 10 );
    avl.insert( 5 );
    avl.insert( 15 );
    avl.insert( 12 );
    avl.insert( 20 );
    avl.insert( 11 );
}

void randomFill( int nb, int min, int max, TreeAVL<int> & avl )
{
    avl.clear();
    srand( time( NULL ) );

    int a = 0;
    for( int i = 0; i < nb; ++i )
    {
        a = rand()%(max-min) + min;
        avl.insert( a );
    }
}

int main( int argc, char** argv )
{
    if( argc != 2 )
    {
        cout << "Usage : avl graph_file" << endl;
        return 1;
    }

    TreeAVL<int> avl;
    //unbalancedLeftIntern( avl );
    randomFill( 01000, 1, 1000000, avl );

    cout << "Gen graph" << endl;
    avl.drawGraph( argv[1] );
    //avl.drawGraph( cout );
    cout << "\"" << argv[1] << "\" generated" << endl;

    return 0;
}

