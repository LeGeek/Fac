import std.stdio, std.container, std.conv, std.string;

import src.structure.skiplist;
import src.utils.randomgenerator;

int main()
{
	writeln("Création SkipList");
    SkipList!(int*) sl = new SkipList!(int*)();

    //tester_contains();
    tester_final();

    writeln("Fin du programme !");
    return 0;
}

void tester_contains()
{

    SkipList!(long*) skiplist = new SkipList!(long*)();
    RandomGenerator random = new RandomGenerator();

    writeln( "Remplissage de la skiplist (de manière ordonnée )" );
    for( long i = 100; i > 0; i-- )
    {
        skiplist.add( cast(long*)( random.next( 0, 51 ) ) );  //La liste est forcement triée
    }

    writeln( "Contenu de la liste : " );
    writeln( skiplist.toString() );

    int val = 0;
    string str = "";
    while( val != -1 )
    {
        write( "Nombre à rechercher : " );
        
        str = stdin.readln();
        val = to!(int)(str.removechars( "\n" ));
        writeln( "Recherche de l'élément ", val );

        if( skiplist.contains( cast(long*)(val) ) )
        {
            writeln( val, " a été trouvé !" );
        }
        else
        {
            writeln( val, " n'a pas été trouvé !" );
        }
    }
}

void tester_final()
{
    SkipList!(int*) skiplist = new SkipList!(int*)();
    long X = 1;
    foreach( i; 0 .. 10000 )
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
}
