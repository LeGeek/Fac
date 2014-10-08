import std.stdio, std.container, std.conv, std.string;

import src.structure.skiplist;
import src.utils.randomgenerator;


int main()
{
	writeln("Création SkipList");

    tester_add();
    //tester_final();

    writeln("Fin du programme !");
    return 0;
}

void tester_add()
{
    SkipList!(int) skiplist = new SkipList!(int)();
    for(int i =0; i < 1600000; ++i )
    {
        skiplist.add( i );
    }   
}

void tester_final()
{
    /*SkipList!(int*) skiplist = new SkipList!(int*)();
    long X = 1;
    
    for( int i = 0; i < 1600000; ++i )
    {
        X = X*16807 % 2147483647;
        skiplist.add( cast(int*)(X) );
    }

    //Le dernier élément est présent
    if ( !skiplist.contains( cast(int*)(X) ) )
        writeln( "\t===> Erreur : Le dernier élément, au moins, n'est pas présent !" );
    else
        writeln( "\t===> OK : Le dernier élément est présenté");
    
    writeln( "Nombre d'éléments de la SkipList : ", skiplist.size() );
    
    Array!(int*) liste = skiplist.toList();
    writeln( "Verifie le tri de la liste");
    foreach( i; 1 .. liste.length() )
    {
        if( liste[i-1] > liste[i] )
        {
            writeln( "\t===> Erreur : Tri incorrect entre '", liste[i-1], 
                    "' et '", liste[i], "'" );
            return;
        }
    }
    writeln( "\t===> OK : Le tri semble correct" );


    writeln( "Suppression de TOUS les éléments" );
    foreach( i; 0 .. liste.length() )
    {
        skiplist.remove( liste[i] );
    }

    writeln( "Nombre d'éléments final de la SkipList : ", skiplist.size() );
    writeln( skiplist.toString() );*/
}
