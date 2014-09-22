import std.stdio, std.container, std.conv, std.string;

import src.structure.skiplist;

int main()
{
	writeln("Création SkipList");
    SkipList!(int*) sl = new SkipList!(int*)();

    tester_contains();

    writeln("Fin du programme !");
    return 0;
}

void tester_contains()
{
    SkipList!(int*) skiplist = new SkipList!(int*)();
    
    writeln( "Remplissage de la skiplist (de manière ordonnée )" );
    for( int i = 128; i > 0; i-- )
    {
        skiplist.add( cast(int*)(i) );  //La liste est forcement triée
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

        if( skiplist.contains( cast(int*)(val) ) )
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

    writeln( "Nombre d'éléments de la SkipList : ", skiplist.size() );
    
    Array!(int*) liste = skiplist.toArray();
    writeln( "Verifie le tri de la liste");
    foreach( i; 1 .. liste.length() )
    {
        if( liste[i-1] > liste[i] )
            writeln( "\t===> Erreur : Tri incorrect entre '", liste[i-1], "' et '", liste[i], "'" );
    }

    writeln( "Suppression de TOUS les éléments" );
    foreach( i; 0 .. liste.length() )
    {
        skiplist.remove( liste[i] );
    }

    writeln( "Nombre d'éléments final de la SkipList : ", skiplist.size() );
}
