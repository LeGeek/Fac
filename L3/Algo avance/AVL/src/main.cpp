
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

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

void remove1( TreeAVL<int> & avl )
{
    avl.clear();
    avl.insert( 10 );
    avl.insert( 5 );
    avl.insert( 15 );
    avl.insert( 1 );

    avl.remove( 5 );
}

void remove2( TreeAVL<int> & avl )
{
    avl.clear();
    avl.insert( 10 );
    avl.insert( 5 );
    avl.insert( 15 );
    avl.insert( 6 );

    avl.remove( 5 );
}

void remove3( TreeAVL<int> & avl )
{
    avl.clear();
    avl.insert( 3 );
    avl.insert( 1 );
    avl.insert( 5 );
    avl.insert( 4 );

    avl.remove( 5 );
}

void remove4( TreeAVL<int> & avl )
{
    avl.clear();
    avl.insert( 4 );
    avl.insert( 1 );
    avl.insert( 5 );
    avl.insert( 6 );

    avl.remove( 5 );
}

void remove5( TreeAVL<int> & avl )
{
    avl.clear();
    avl.insert( 10 );
    avl.insert( 5 );
    avl.insert( 15 );
    avl.insert( 1 );
    avl.insert( 6 );
    avl.insert( 11 );
    avl.insert( 16 );

    avl.remove( 5 );
}

void remove6( TreeAVL<int> & avl )
{
    avl.clear();
    avl.insert( 3 );
    avl.insert( 1 );
    avl.insert( 5 );
    avl.insert( 0 );
    avl.insert( 2 );
    avl.insert( 4 );
    avl.insert( 6 );

    avl.remove( 5 );
}

void remove7( TreeAVL<int> & avl )
{
    avl.clear();
    avl.insert( 5 );
    avl.insert( 4 );
    avl.insert( 6 );

    avl.remove( 5 );
}

void remove8( TreeAVL<int> & avl )
{
    avl.clear();
    avl.insert( 10 );
    avl.insert( 5 );
    avl.insert( 15 );

    avl.remove( 5 );
}

void remove9( TreeAVL<int> & avl )
{
    avl.clear();
    avl.insert( 4 );
    avl.insert( 3 );
    avl.insert( 5 );

    avl.remove( 5 );
}

void randomFill( int nb, int min, int max, TreeAVL<int> & avl )
{
    if( nb >= max )
    {
        cerr << "Le nombre d'élément est trop d'important, par rapport au nombre MAX !" << endl;
        return;
    }

    avl.clear();
    srand( time( NULL ) );

    int a = 0, i = 0;
    while( i < nb )
    {
        a = rand()%(max-min) + min;
        if( avl.insert( a ) )
            ++i;
    }
}

int main( int argc, char** argv )
{
    if( argc != 3 )
    {
        cout << "Usage : avl nb_element graph_file" << endl;
        return 1;
    }

    int n = atoi( argv[1] );

    TreeAVL<int> avl;
    randomFill( n, 1, 2147483647, avl );

    cout << "Gen graph" << endl;
    avl.drawGraph( argv[2] );
    //avl.drawGraph( cout );
    cout << "\"" << argv[2] << "\" generated" << endl;

    cout << "Rapport : \n" <<
        "\tNombre d'élément (n) : " << n << '\n' <<
        "\tHauteur : " << avl.getLevel() << '\n' <<
        "\t1.45*log2( n ) = " << 1.45*log2( n ) << '\n' <<
        "\tValeur Moyenne : " << avl.getLevel()/log2( n ) << endl;

    return 0;
}

